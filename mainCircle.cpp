#include <iostream>
#include <GL/glut.h>
#include <cmath>
#define _USE_MATH_DEFINES
int c=0;
int centerx, centery, radx, rady;

//function that calculates the distance between two dots
float distance(int x1, int y1, int x2, int y2){
	float d = sqrt((x2-x1)*(x2-x1))+((y2-y1)*(y2-y1));
	return d;
}

// initializer for the viewport
void init() {
	glClearColor(0.0,0.0,0.0,0.0);
	glViewport(0,0,300,300);
	gluOrtho2D(0.0,300.0,0.0,300.0);
}

//method that draws a filled circle when the center coordinate, radius and a number is given.
//Since glut does not have an self-defined method for drawing circles,
//we draw a polygon with an n number of pieces.
//The higher the n number, the rounder the circle is.
void vizatoRreth(int x0, int y0, float r, int n){
	float theta;
	glBegin(GL_POLYGON);
		glColor3f(1.0,0.0,0.0);
		for(int i=0;i<n;i++){
			theta = i*2*M_PI/n;
			glVertex2i(x0 + r*cos(theta), y0 + r*sin(theta));
		}
	glEnd();
	glFlush();
}
//function for mouse events. 
//When the number of clicks its even, we save the data as the center of the circle
//When the number of clicks its odd, we calculate the distance between the last two clicks
//use it as radius and draw a circle.
void mouse(int button, int state, int x, int y){
	if(button==GLUT_LEFT_BUTTON && state==GLUT_DOWN){
		if(c%2==0){
			centerx=x;
			centery=300-y;
			c=c+1;
		}
		else{
			radx=x;
			rady=300-y;
			c=c+1;
			float d = radx - centerx;
			vizatoRreth(centerx, centery, d, 300);
		}
	}
	glutPostRedisplay();
}
//clear the buffer
void display(){
	glClear(GL_COLOR_BUFFER_BIT);
}
int main(int argc, char*argv[]){
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_SINGLE|GLUT_RGB);
	glutInitWindowSize(300,300);
	glutCreateWindow("Circle");
	init();
	glutMouseFunc(mouse);
	glutDisplayFunc(display);
	glutMainLoop();
}
