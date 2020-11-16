#include <GL/glut.h>
#include <stdio.h>

using namespace std;
#define FROM_RIGHT      1 
#define FROM_LEFT       2 
#define FROM_TOP        3 
#define FROM_BOTTOM     4 

static int WINDOW_WIDTH, WINDOW_HEIGHT;

int player_1_Result = 0;
int player_2_Result = 0;
static float Xspeed = 4, Yspeed = 4;
static float delta = 0.7;

char string[100];

struct RECTA
{
    float left, top, right, bottom, red, green, blue;
};

RECTA ball = { 100,100,120,120, 1,1,1 };
RECTA wall;
RECTA player_1 = { 0,490,40,500, 1,0,0 };
RECTA player_2 = { 750,0,790,10, 0,1,0 };

void DrawRectangle(RECTA  rect)
{
    glBegin(GL_QUADS);
    glColor3f(rect.red, rect.green, rect.blue);
    glVertex2f(rect.left, rect.bottom);      //Left - Bottom 
    glVertex2f(rect.right, rect.bottom);
    glVertex2f(rect.right, rect.top);
    glVertex2f(rect.left, rect.top);
    glEnd();
}

void Timer(int v)
{
    ball.left += Xspeed;
    ball.right += Xspeed;
    ball.top += Yspeed;
    ball.bottom += Yspeed;

    glutTimerFunc(5, Timer, 1);
}
void drawText(char* string, int x, int y)
{
    char* c;
    glPushMatrix();
    glTranslatef(x, y, 0);
    glScalef(0.1, -0.1, 1);

    for (c = string; *c != '\0'; c++)
    {
        glutStrokeCharacter(GLUT_STROKE_ROMAN, *c);
    }
    glPopMatrix();

}

void stop()
{
    printf("game over");
    printf(string);
    exit(0);
}

int Test_Ball_Wall(RECTA  ball, RECTA wall)
{
    if (ball.right >= wall.right)
        return FROM_RIGHT;
    if (ball.left <= wall.left)
        return FROM_LEFT;
    if (ball.top <= wall.top)
        stop();
    if (ball.bottom >= wall.bottom)
        stop();

    else return 0;
}

bool Test_Ball_Player_1(RECTA ball, RECTA player)
{

    if (ball.bottom >= player.top && ball.left >= player.left && ball.right <= player.right)
    {
        player_1_Result++;

        return true;
    }

    return false;
}

bool Test_Ball_Player_2(RECTA ball, RECTA player)
{

    if (ball.top <= player.bottom && ball.left >= player.left && ball.right <= player.right)
    {
        player_2_Result++;

        return true;
    }

    return false;
}

static float player_1_x = 20;
static float player_2_x = 770;

void a_d_esc_keys(unsigned char key, int x, int y)
{
    switch (key) {
    case 27:
        exit(0);
        break;
    case 'a':
    case 'A':
        player_2_x = player_2_x <= 20 ? 20 : (player_2_x - 20);
        break;
    case 'd':
    case 'D':
        player_2_x = player_2_x >= 770 ? 770 : (player_2_x + 20);;
        break;
    }
}

void special_keys(int key, int x, int y)
{
    switch (key)
    {
    case 100:
        player_1_x = player_1_x <= 20 ? 20 : (player_1_x - 20);;
        break;
    case 102:
        player_1_x = player_1_x >= 770 ? 770 : (player_1_x + 20);;
        break;
    }
}


// OpenGL Setting
void Setting(void)
{
    glClearColor(0.0, 0.0, 0.0, 0.0);
    glHint(GL_PERSPECTIVE_CORRECTION_HINT, GL_NICEST);

}


// OnWindowResize 
void reshape(int w, int h)
{
    WINDOW_WIDTH = w;
    WINDOW_HEIGHT = h;

    glViewport(0, 0, (GLsizei)w, (GLsizei)h);

    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluOrtho2D(0, w, h, 0);


    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();

}

int pcResult = 0;

void disp()
{
    glClear(GL_COLOR_BUFFER_BIT);
    glLoadIdentity();

    sprintf_s(string, "Player 1 : %d ", player_1_Result);
    drawText(string, 10, 120);
    sprintf_s(string, "Player 2 : %d ", player_2_Result);
    drawText(string, 10, 160);

    wall.left = wall.top = 0;
    wall.right = WINDOW_WIDTH;
    wall.bottom = WINDOW_HEIGHT;

    DrawRectangle(ball);

    if (Test_Ball_Wall(ball, wall) == FROM_RIGHT)
        Xspeed = -delta;

    if (Test_Ball_Wall(ball, wall) == FROM_LEFT)
        Xspeed = delta;

    if (Test_Ball_Wall(ball, wall) == FROM_BOTTOM)
    {
        Yspeed = -delta;
        pcResult += 1;
    }
    if (Test_Ball_Wall(ball, wall) == FROM_TOP)
    {
        Yspeed = delta;
        pcResult += 1;
    }

    DrawRectangle(player_1);
    player_1.left = player_1_x - 20;
    player_1.right = player_1_x + 40;

    DrawRectangle(player_2);
    player_2.left = player_2_x - 20;
    player_2.right = player_2_x + 40;

    if (Test_Ball_Player_1(ball, player_1) == true)
        Yspeed = -delta;

    if (Test_Ball_Player_2(ball, player_2) == true)
        Yspeed = +delta;

    glutSwapBuffers();
}


int main(int argc, char** argv)
{
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB);
    glutInitWindowSize(795, 500);
    glutInitWindowPosition(200, 200);
    glutCreateWindow("GAME");
    Setting();
    glutDisplayFunc(disp);
    glutIdleFunc(disp);
    glutReshapeFunc(reshape);
    glutSpecialFunc(special_keys);
    glutKeyboardFunc(a_d_esc_keys);
    glutTimerFunc(1, Timer, 1);
    //glutSpecialUpFunc(upkey);

    glutMainLoop();
    return 0;
}