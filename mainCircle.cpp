#include <iostream>
#include <GL/glut.h>
#include <cmath>
#define _USE_MATH_DEFINES
int c=0;
int centerx, centery, radx, rady;

float distance(int x1, int y1, int x2, int y2){
	float d = sqrt((x2-x1)*(x2-x1))+((y2-y1)*(y2-y1));
	return d;
}

void init() {
	glClearColor(0.0,0.0,0.0,0.0);
	glViewport(0,0,300,300);
	gluOrtho2D(0.0,300.0,0.0,300.0);
}

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
