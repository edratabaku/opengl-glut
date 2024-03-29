#include <iostream>
#include <GL/glut.h>
//counter
int i=0;
//structure that will hold the x and y coordinates of a point
struct point {
	int xp;
	int yp;
};
//an array of type point
struct point points[300];
//init function
void init()
	glClearColor(0.0,0.0,0.0,0.0);
	glViewport(0,0,300,300);
	gluOrtho2D(0.0,300.0,0.0,300.0);
}
//clearing buffers for every display
void display(){
	glClear(GL_COLOR_BUFFER_BIT);
}
//function that draws a filled triangle
void drawFull(point pt1, point pt2, point pt3){
	glBegin(GL_TRIANGLES);
		glColor3f(1.0,1.0,0.0);
		glVertex2i(pt1.xp,pt1.yp);
		glVertex2i(pt2.xp,pt2.yp);
		glVertex2i(pt3.xp,pt3.yp);
	glEnd();
	glFlush();
}
//function that draws a not filled triangle
void drawEmpty(point pt1, point pt2, point pt3){
	glBegin(GL_LINE_LOOP);
		glColor3f(1.0,1.0,0.0);
		glVertex2i(pt1.xp,pt1.yp);
		glVertex2i(pt2.xp,pt2.yp);
		glVertex2i(pt3.xp,pt3.yp);
	glEnd();
	glFlush();
}
/*mouse function that reads input from user and when the third click happens 
it draws a filled triangle with the coordinates of user's last three clicks*/
void mouse(int button, int state, int x, int y){
	if (button == GLUT_LEFT_BUTTON && state==GLUT_DOWN){
		if(i%3!=2){
			pikat[i].xp = x;
			pikat[i].yp = 300-y;
			i=i+1;
		}
		else{
			pikat[i].xp=x;
			pikat[i].yp=300-y;
			drawFull(pikat[i-2], pikat[i-1],pikat[i]);
			i=i+1;
		}
	}
	glutPostRedisplay();
}
/*mouse function that reads input from user and when the third click happens 
it draws a not filled triangle with the coordinates of user's last three clicks*/
void mouse2(int button, int state, int x, int y){
		if (button == GLUT_LEFT_BUTTON && state==GLUT_DOWN){
		if(i%3!=2){
			pikat[i].xp = x;
			pikat[i].yp = 300-y;
			i=i+1;
		}
		else{
			pikat[i].xp=x;
			pikat[i].yp=300-y;
			drawEmpty(pikat[i-2], pikat[i-1],pikat[i]);
			i=i+1;
		}
	}
	glutPostRedisplay();
}
/*keyboard function that allows the user to decide if they want the triangles to be filled or not.
If the user gives an input of z, the triangles will be unfilled.
If the user gives an input of m, the triangles will be filled.
If the user presses the esc key the program will close.*/
void keyboard(unsigned char key, int x, int y){
	switch (key){
		case 'Z':
		case 'z':
			glutMouseFunc(mouse2);
			break;
		case 'M':
		case 'm':
			glutMouseFunc(mouse);
			break;
		case 27:
			exit(0);
	}
}
//main function
int main (int argc, char*argv[]){
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_SINGLE|GLUT_RGB);
	glutCreateWindow("Trekendesha");
	init();
	glutMouseFunc(mouse);
	glutDisplayFunc(display);
	glutKeyboardFunc(keyboard);
	glutMainLoop();
}
