
// movingvehicle.cpp : Defines the entry point for the console application.
//

//#include "stdafx.h"
#include <GL\glut.h>
#include <stdio.h>

float tx = 0.0f; // for translation
float ty = 0.0f;
float angle = 0.0f; // for rotation

bool playAnim = false;
 
void init()
{
	glClearColor(1.000, 0.548, 0.000, 1.0f);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	glOrtho(-1.0, 1.0, -1.0, 1.0, -1.0, 1.0);
	glMatrixMode(GL_MODELVIEW);
}

void display()
{
	if (playAnim)
	{
		glClear(GL_COLOR_BUFFER_BIT);
		glLoadIdentity();
		glColor3f(0.827, 0.827, 0.827);//Road
		glBegin(GL_POLYGON);
		glVertex2f(-1.0, -0.4);
		glColor3f(0.0, 0.0, 0.0);
		glVertex2f(-1.0, -0.1);
		glVertex2f(1.0, -0.1);
		glColor3f(0.827, 0.827, 0.827);
		glVertex2f(1.0, -0.4);
		glEnd();

		glLoadIdentity();
		glColor3f(0.663, 0.663, 0.663);//far side 
		glBegin(GL_POLYGON);
		glVertex2f(-1.0, -0.1);
		glColor3f(0.412, 0.412, 0.412);
		glVertex2f(-1.0, -0.05);
		glVertex2f(1.0, -0.05);
		glColor3f(0.663, 0.663, 0.663);
		glVertex2f(1.0, -0.1);
		glEnd();

		glLoadIdentity();
		glColor3f(0.412, 0.412, 0.412);//far side walkway
		glBegin(GL_POLYGON);
		glVertex2f(-1.0, -0.05);
		glColor3f(0.663, 0.663, 0.663);
		glVertex2f(-1.0, 0.02);
		glVertex2f(1.0, 0.02);
		glColor3f(0.412, 0.412, 0.412);
		glVertex2f(1.0, -0.05);
		glEnd();

		float l = -1.0;
		while (l <= 2.0)
		{
			glLoadIdentity();
			glColor3f(0.600, 1.000, 0.300);//MOUNTAIN
			glBegin(GL_POLYGON);
			glVertex2f(l, 0.02);
			//glVertex2f(l,0.8);
			l = l + 0.4;
			glVertex2f(l, 0.8);
			glColor3f(0.000, 0.000, 0.000);
			glVertex2f(l, 0.06);
			glEnd();
			l = l + 0.3;
		}
		l = -0.10;
		while (l <= 1.0)
		{
			glLoadIdentity();
			glColor3f(0.600, 1.000, 0.300);//MOUTAIN
			glBegin(GL_POLYGON);
			glVertex2f(l, 0.02);
			//glVertex2f(l,0.8);
			l = l + 0.4;
			glVertex2f(l, 0.8);
			glColor3f(0.000, 0.000, 0.000);
			glVertex2f(l, 0.06);
			glEnd();
			l = l + 0.3;
		}

		float v = -0.9;
		while (v <= 1.0)
		{
			glLoadIdentity();
			glColor3f(0.000, 1.000, 0.804);//MOUNTAIN
			glBegin(GL_POLYGON);
			glVertex2f(v, 0.02);
			//glVertex2f(v,0.6);
			v = v + 0.3;
			glVertex2f(v, 0.6);
			glColor3f(0.000, 0.000, 0.000);
			glVertex2f(v, 0.02);
			glEnd();
			v = v + 0.2;
		}

		v = 0.10;
		while (v <= 1.0)
		{
			glLoadIdentity();
			glColor3f(0.000, 1.000, 0.804);//MOUNTAIN
			glBegin(GL_POLYGON);
			glVertex2f(v, 0.02);
			//glVertex2f(v,0.6);
			v = v + 0.3;
			glVertex2f(v, 0.6);
			glColor3f(0.000, 0.000, 0.000);
			glVertex2f(v, 0.02);
			glEnd();
			v = v + 0.2;

		}

		float i = -1.0;
		while (i <= 1.0)
		{
			glLoadIdentity();
			glColor3f(0.275, 1.510, 0.000);//MOUTAIN
			glBegin(GL_POLYGON);
			glVertex2f(i, 0.02);
			//glVertex2f(i,0.4);
			i = i + 0.2;
			glVertex2f(i, 0.4);
			glColor3f(0.000, 0.000, 0.000);
			glVertex2f(i, 0.02);
			glEnd();
			i = i + 0.1;
		}

		glLoadIdentity();
		glColor3f(1.698, 1.133, 1.133);// car 
		glTranslatef(tx, ty, 0.0f);
		glBegin(GL_POLYGON);
		glVertex2f(0.53, -0.3);
		glVertex2f(0.53, -0.2);

		glVertex2f(1.0, -0.2);
		glVertex2f(1.0, -0.3);
		glEnd();
		glLoadIdentity();
		glTranslatef(tx, ty, 0.0f);
		glBegin(GL_TRIANGLES);
		glVertex2f(0.6, -0.2);
		glVertex2f(0.7, -0.1);

		glVertex2f(0.7, -0.2);
		glEnd();
		glLoadIdentity();
		glTranslatef(tx, ty, 0.0f);
		glBegin(GL_POLYGON);
		glVertex2f(0.7, -0.2);
		glVertex2f(0.7, -0.1);

		glVertex2f(0.9, -0.1);
		glVertex2f(0.9, -0.2);
		glEnd();
		glLoadIdentity();
		glTranslatef(tx, ty, 0.0f);
		glBegin(GL_TRIANGLES);
		glVertex2f(0.9, -0.2);
		glVertex2f(0.9, -0.1);

		glVertex2f(0.97, -0.2);
		glEnd();

		glLoadIdentity();//glass
		glTranslatef(tx, ty, 0.0f);
		glColor3f(0.902, 0.902, 0.980);
		glBegin(GL_TRIANGLES);
		glVertex2f(0.61, -0.2);
		glVertex2f(0.7, -0.11);
		glVertex2f(0.7, -0.2);
		glEnd();
		glLoadIdentity();
		glTranslatef(tx, ty, 0.0f);
		glBegin(GL_POLYGON);
		glVertex2f(0.71, -0.2);
		glVertex2f(0.71, -0.11);

		glVertex2f(0.79, -0.11);
		glVertex2f(0.79, -0.2);
		glEnd();
		glLoadIdentity();
		glTranslatef(tx, ty, 0.0f);
		glBegin(GL_POLYGON);
		glVertex2f(0.8, -0.2);
		glVertex2f(0.8, -0.11);

		glVertex2f(0.89, -0.11);
		glVertex2f(0.89, -0.2);
		glEnd();
		glLoadIdentity();
		glTranslatef(tx, ty, 0.0f);
		glBegin(GL_TRIANGLES);
		glVertex2f(0.9, -0.2);
		glVertex2f(0.9, -0.11);

		glVertex2f(0.96, -0.2);
		glEnd();
		glLoadIdentity();
		glColor3f(0.000, 1.863, 0.000);//nearside walkway
		glBegin(GL_POLYGON);
		glVertex2f(-1.0, -1.0);
		glColor3f(0.412, 0.412, 0.412);
		glVertex2f(-1.0, -0.4);
		glVertex2f(1.0, -0.4);
		glColor3f(0.063, 1.863, 0.412);
		glVertex2f(1.0, -1.0);
		glEnd();

		glLoadIdentity();//tyre1
		glTranslatef(tx + 0.6, ty - 0.3, 0.0f);
		glRotatef(angle, 0.0, 0.0, 1.0);
		glColor3f(0.0, 0.0, 0.0);
		glutWireCone(0.05, 0.05, 10, 10);

		glLoadIdentity();//tyre2
		glTranslatef(tx + 0.9, ty - 0.3, 0.0f);
		glRotatef(angle, 0.0, 0.0, 1.0);
		glColor3f(0.0, 0.0, 0.0);
		glutWireCone(0.05, 0.05, 10, 10);
		glutSwapBuffers();
	}
}

void update(int value)
{
	if(tx>=-2.0)
		tx = tx - 0.1;
	else
	{
		tx=0.0f;
		ty=0.0f;
	}
	angle = angle + 25;
	glutTimerFunc(100, update, 0);

}

void keyboard(unsigned char key, int x, int y)
{
	switch (key)
	{
	case 'p':
	case 'P':
		playAnim = true;
		break;
	case 's':
	case 'S':
		playAnim = false;
		break;
	}
}

int main(int argc,char *argv[])
{
	glutInit(&argc,argv);
	glutInitDisplayMode(GLUT_DOUBLE  | GLUT_RGB);
	glutInitWindowSize(1000,1000);
	glutInitWindowPosition(50,50);
	glEnable(GL_DEPTH_TEST);
	glutCreateWindow("Moving Vehicle");
	init();
	glutDisplayFunc(display);
	glutIdleFunc(display);
	glutTimerFunc(100,update,0);
	glutKeyboardFunc(keyboard);
	glutMainLoop();
	return 0;
}
