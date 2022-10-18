#include <GL/glew.h>
#include <GL/freeglut.h>
#include <GL/glut.h>
//#include <iostream>

static float X = 0.0;
static float Y = 0.0;
static float Z = -15.0;

static float rotX = 0, rotY = 0, rotZ = 0, rotAngle = 0;

// Drawing routine.
void drawScene(void)
{
	glClear(GL_COLOR_BUFFER_BIT);
	glEnable(GL_COLOR_MATERIAL);
	glColor3f(0.0, 0.0, 0.0);
	glLoadIdentity();

	// Modeling transformations.
	//Kamera
	glTranslatef(X, Y, Z);
	//glRotatef(0, rotX, rotY, rotZ);

	// Saklar
	//Belakang
	glPushMatrix();
	glScalef(1, 1, 0.1);
	glColor3f(0.5, 0.5, 0.5);
	glutSolidCube(4);
	glPopMatrix();

	//depan
	glPushMatrix();
	glTranslatef(0, 0, 0.2);
	glRotatef(-15, 1, 0, 0);
	glScalef(0.7, 0.7, 0.1);
	glColor3f(0.3, 0.3, 0.3);
	glutWireCube(4);
	glPopMatrix();

	//LCD
	//Belakang
	glPushMatrix();
	glTranslatef(20, 0, 0);
	glScalef(2, 1.2, 0.2);
	glColor3f(0.5, 0.5, 0.5);
	glutSolidCube(4);
	glPopMatrix();

	//Layar
	glPushMatrix();
	glTranslatef(20, 0, 0.1);
	glScalef(1.7, 0.9, 0.1);
	glColor3f(0, 0, 0.8);
	glutSolidCube(4);
	glPopMatrix();

	//Bawah
	glPushMatrix();
	glTranslatef(20, -3, -1);
	glScalef(0.2, 0.5, 0.1);
	glColor3f(0.5, 0.5, 0.5);
	glutSolidCube(4);
	glPopMatrix();

	//kaki
	glPushMatrix();
	glTranslatef(20, -4, -1);
	glScalef(0.5, 0.1, 0.5);
	glColor3f(0.5, 0.5, 0.5);
	glutSolidCube(4);
	glPopMatrix();

	//keyboard
	glPushMatrix();
	glTranslatef(20, -5.5, 1);
	glScalef(1.8, 0.1, 1);
	glColor3f(0.3, 0.3, 0.3);
	glutSolidCube(4);
	glPopMatrix();

	glFlush();
}

// Initialization routine.
void setup(void)
{
	glClearColor(0.0, 0.0, 0.0, 0.0);
}

// OpenGL window reshape routine.
void resize(int w, int h)
{
	glViewport(0, 0, w, h);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	glFrustum(-5.0, 5.0, -5.0, 5.0, 5.0, 100.0);
	//glOrtho(-5.0, 5.0, -5.0, 5.0, 5.0, 100.0);

	glMatrixMode(GL_MODELVIEW);
}

// Keyboard input processing routine.
void keyInput(unsigned char key, int x, int y)
{
	switch (key)
	{
	case 27:
		exit(0);
		break;
	case 'a':
		X += 0.5;
		glutPostRedisplay();
		break;
	case 'd':
		X -= 0.5;
		glutPostRedisplay();
		break;
	case 's':
		Y -= 0.5;
		glutPostRedisplay();
		break;
	case 'w':
		Y += 0.5;
		glutPostRedisplay();
		break;
	case 'q':
		Z -= 0.5;
		glutPostRedisplay();
		break;
	case 'e':
		Z += 0.5;
		glutPostRedisplay();
		break;
	default:
		break;
	}
}

void RotKeyInput(unsigned char key, int x, int y) {
	switch (key)
	{
	case 27:
		exit(0);
		break;
	case 'j':
		rotX = 1;
		glutPostRedisplay();
		break;
	case 'l':
		rotX = 1;
		glutPostRedisplay();
		break;
	case 'k':
		rotY = 1;
		glutPostRedisplay();
		break;
	case 'i':
		rotY = 1;
		glutPostRedisplay();
		break;
	case 'o':
		rotZ = 1;
		glutPostRedisplay();
		break;
	case 'u':
		rotZ = 1;
		glutPostRedisplay();
		break;
	default:
		break;
	}
}

// Main routine.
int main(int argc, char** argv)
{
	glutInit(&argc, argv);

	glutInitContextVersion(4, 3);
	glutInitContextProfile(GLUT_COMPATIBILITY_PROFILE);

	glutInitDisplayMode(GLUT_SINGLE | GLUT_RGBA);
	glutInitWindowSize(500, 500);
	glutInitWindowPosition(100, 100);
	glutCreateWindow("Tugas Kelompok Open GL");
	glutDisplayFunc(drawScene);
	glutReshapeFunc(resize);
	glutKeyboardFunc(keyInput);

	glewExperimental = GL_TRUE;
	glewInit();

	setup();

	glutMainLoop();
}