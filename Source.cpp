int findPath(Grid* current, Grid* parent, int x, int y)
{
	drawGrid();
	//glutPostRedisplay();
	if (!pathFound)
	{
		if (current->isObstacle() || current->isTraversed() /*|| current->isStartPoint()*/)
		{
			//do nothing
			//std::cout << "obstacle, traversed or start found:(" << current->getX() << ", " << current->getY() << ")\n";
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

				findPath(grid[x + 1][y], current, x + 1, y);	//right
				findPath(grid[x][y - 1], current, x, y - 1);	//down
				findPath(grid[x - 1][y], current, x - 1, y);	//left
				findPath(grid[x][y + 1], current, x, y + 1);	//up
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