#include <iostream>
#include <GL/glut.h>
#include <cmath>

float qr;
int height = 100;

void initDraw(){
	glClearColor(0.0,0.0,0.0,1.0);
	glViewport(0,0,400,400);
	glOrtho(-300.0,300.0,-300.0,300-0,-300.0,300.0);
}
int fx=0, fy=300, sx=fx, sy=fy;

void drawCircle(int x, int y, int r){
	glBegin(GL_POLYGON);
	glTranslatef(0.0,0.0,0.0);
	for(int i=0;i<360;i++){
		float theta= i*2*M_PI/360;
		glColor3f(0.0,0.0,1.0);
		glVertex3f(x+r*cos(theta),qr+r*sin(theta),100);
		glColor3f(1.0,0.0,0.0);
		glVertex3f(x+r*cos(theta),qr+r*sin(theta),50);
	}
	glEnd();
}

void display(){
	glClear(GL_COLOR_BUFFER_BIT);
	glBegin(GL_LINE_STRIP);
	glVertex2i(fx,fy);
	glVertex2i(sx,sy);
	glEnd();
	glPushMatrix();
	glTranslatef(0.0,sy,0.0);
	glRotatef(sy,1.0,0.0,0.0);
	drawCircle(0,sy,50);
	glPopMatrix();
	glColor3f(1.0,1.0,1.0);
	glPushMatrix();
	glPopMatrix();
	glFlush();
}
bool poshte=1;

void update(int value){
	if(poshte){
		sy = sy-10;
		if(sy<=0){
			poshte= false;
		}
	}
	if(!poshte){
		sy+=10;
		if(sy>=300)
		poshte=true;
	}
	glutPostRedisplay();
	glutTimerFunc(90,update,0);
}
int main(int argc, char*argv[]){
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_SINGLE|GLUT_RGB);
	glutInitWindowSize(600,600);
	glutCreateWindow("yoyo");
	initDraw();
	update(0);
	glutTimerFunc(90,update,0);
	glutDisplayFunc(display);
	glutMainLoop();
}