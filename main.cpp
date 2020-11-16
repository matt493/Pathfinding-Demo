#include "Grid.h"
//#include "Headers.h"
#pragma region funcDeclarations

void display();
void init();
void reshape(int, int);
void mouseFunc(int, int, int, int);
void keyboard(unsigned char, int, int);

//returns screen coordinates
Point getMatrixCoord(int, int);

//draw the grid system
void drawGrid();

//draw the path when path is found
void drawPath(Grid*);

//init grid
void initGrid();

#pragma endregion

const int XMAX = 600;
const int YMAX = 600;
const int GRID_SIZE = 20;

Grid *grid[GRID_SIZE * 2][GRID_SIZE * 2];
Grid *startNode, *endNode;
int start_x, start_y;
bool startInit = false;
bool endInit = false;
bool pathFound = false;

int findPath(Grid* current, Grid* parent, int x, int y)
{
	drawGrid();
	if (!pathFound)
	{
		if (current->isObstacle() || current->isTraversed())
		{
			std::cout << "obstacle, traversed or start found:(" << x << ", " << y << ")\n";
		}
		else if (current->isEndPoint())
		{
			pathFound = true;
			current->setTraversed();
			current->setParent(parent);
			std::cout << "end found \n";
		}
		else
		{
			std::cout << "probable path found:(" << x << ", " << y << ")\n";

			if (x >= 1 && x < (GRID_SIZE * 2) - 2 && y >= 1 && y < (GRID_SIZE * 2) - 2)
			{
				current->setTraversed();
				current->setParent(parent);
				std::cout << "current: setTraversed():(" << x << ", " << y << ")\n";

				findPath(grid[x][y + 1], current, x, y + 1);	//up
				findPath(grid[x + 1][y], current, x + 1, y);	//right
				findPath(grid[x][y - 1], current, x, y - 1);	//down
				findPath(grid[x - 1][y], current, x - 1, y);	//left
			}
			else
			{
				return 0;
			}
		}
	}
	else
	{
		return 0;
	}

}

int main(int argc, char** argv)
{
	srand(time(0));
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_RGB);
	glutInitWindowPosition(100,100);
	glutInitWindowSize(XMAX, YMAX);
	glutCreateWindow("Pathfinder | LMB(set START/END) | RMB(set OBSTACLE) | press any key to run");
	initGrid();
	glutDisplayFunc(display);
	glutReshapeFunc(reshape);
	glutMouseFunc(mouseFunc);
	glutKeyboardFunc(keyboard);
	init();
	glutMainLoop();
}

void display()
{
	glClear(GL_COLOR_BUFFER_BIT);
	glLoadIdentity();
	glPointSize(14);			//POINT SIZE
	drawGrid();
	glFlush();

	/*
	//print coordinate system
	for (int i = 0; i < (GRID_SIZE * 2)-1; i++)
	{
		for (int j = 0; j < (GRID_SIZE * 2)-1; j++)
		{
			std::cout << "(" << grid[i][j]->getX() << "," << grid[i][j]->getY() << ") ";
		}
		std::cout << "\n";
	}
	*/
}

void init()
{
	glClearColor(0.0, 0.0, 0.0, 1.0);
}

void reshape(int w, int h)
{
	glutReshapeWindow(XMAX, YMAX);
	glViewport(0, 0, (GLsizei)w, (GLsizei)h);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	gluOrtho2D(-GRID_SIZE, GRID_SIZE, -GRID_SIZE, GRID_SIZE);
	glMatrixMode(GL_MODELVIEW);
}

void mouseFunc(int button, int state, int mouse_x, int mouse_y)
{
	//Compute the normalized device space coordinate of the mouse in range [-1, 1]:
	double ndc_x = (double)mouse_x / XMAX * 2.0 - 1.0;
	double ndc_y = 1.0 - (double)mouse_y / YMAX * 2.0;

	//Map the result to the range to the grid range:
	int x = (int)(ndc_x * GRID_SIZE + GRID_SIZE + 0.5) - GRID_SIZE;
	int y = (int)(ndc_y * GRID_SIZE + GRID_SIZE + 0.5) - GRID_SIZE;

	//if (state == 0)
	//{
	//	std::cout << "button:" << button << "\nstate:" << state << "\nON SCREEN (" << x << "," << y << ")\n";
	//	std::cout << "ON MATRIX (" << getMatrixCoord(x, y).x << ", " << getMatrixCoord(x, y).y << ")\n-----------\n";
	//}

	//setting params
	
	x = getMatrixCoord(x, y).x;
	y = getMatrixCoord(x, y).y;

	if (button == 0 && state == 0)
	{
		if (!startInit)		//draw start point
		{
			grid[x][y]->setStartPoint();
			start_x = x;
			start_y = y;
			startInit = grid[x][y]->isStartPoint();
			startNode = grid[x][y];
		}
		else if (!endInit)	//draw end point
		{
			grid[x][y]->setEndPoint();
			endInit = grid[x][y]->isEndPoint();
			endNode = grid[x][y];
		}
	}
	else if ((button == 2) && state == 0)	//drawing obstacles
	{
		//std::cout << " start:" << grid[x][y]->isStartPoint() << "\n";
		//std::cout << " end:" << grid[x][y]->isEndPoint() << "\n";

		if (grid[x][y]->isStartPoint() || grid[x][y]->isEndPoint()) 
		{
			//DO NOTHING
		}
		else if (grid[x][y]->isObstacle())
		{
			grid[x][y]->setObstacle(false);
		}
		else
		{ 
			grid[x][y]->setObstacle(true); 
		}
	}
}

Point getMatrixCoord(int x, int y)
{
	Point point;

	point.x = x + GRID_SIZE - 1;
	point.y = y - GRID_SIZE + 1;

	if (point.x < 0) point.x *= -1;
	if (point.y < 0) point.y *= -1;

	return point;
}

void keyboard(unsigned char key, int x, int y)
{
	findPath(startNode,NULL, start_x, start_y);

	if (pathFound)
	{
		drawPath(endNode);
	}
	else
	{
		//std::cout << "path not found! \n";
		MessageBox(NULL, L"NO VALID PATH FOUND", L"ERROR!", MB_OK | MB_ICONEXCLAMATION);
	}
}

void initGrid()
{
	float grid_x = GRID_SIZE - 1;
	float grid_y = GRID_SIZE - 1;
	int i, j;

	//initializing the grid
	for (float x = -grid_x, i = 0; x < GRID_SIZE; x++, i++)
	{
		for (float y = grid_y, j = 0; y > -GRID_SIZE; y--, j++)
		{
			grid[(int)i][(int)j] = new Grid(x, y);
			if (i == 0 || j == 0 || i == (GRID_SIZE * 2) - 2 || j == (GRID_SIZE * 2) - 2)
			{
				grid[(int)i][(int)j]->setObstacle(true);
			}
			/*
			if (rand() % 3 == 0)
			{
				grid[(int)i][(int)j]->setObstacle();
			}
			*/
		}
	}
}

void drawGrid()
{
	glClear(GL_COLOR_BUFFER_BIT);
	//float grid_x = GRID_SIZE - 1;
	//float grid_y = GRID_SIZE - 1;

	for (int i = 0; i < (GRID_SIZE * 2) - 1; i++)
	{
		for (int j = 0; j < (GRID_SIZE * 2) - 1; j++)
		{
			glBegin(GL_POINTS);

			glColor3f(grid[i][j]->getColor().r, grid[i][j]->getColor().g, grid[i][j]->getColor().b);
			glVertex2f(grid[i][j]->getX(), grid[i][j]->getY());

			glEnd();
		}
	}
	glFlush();
}

void drawPath(Grid* currentNode)
{
	drawGrid();
	if (currentNode->getParent() != NULL)
	{
		currentNode->setPath();
		drawPath(currentNode->getParent());
	}
}