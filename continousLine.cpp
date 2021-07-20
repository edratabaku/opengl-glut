#include <iostream>
#include <GL/glut.h>

float xp=0, yp=0;
void initDraw(){
	glClearColor(0.0,0.0,0.0,1.0);
	glViewport(0,0,400,400);
	gluOrtho2D(-300.0,300.0,-300.0,300.0);
}
void keyboard(unsigned char key, int x, int y){
	switch(key){
		case 27:
			exit(0);
	}
}
int clicked=0;
float vx[1000];
float vy[1000];
void mouse (int button, int state, int x, int y){
	if (button == GLUT_LEFT_BUTTON){
		if (state == GLUT_DOWN){
			vx[clicked] = x-300;
			vy[clicked] = 600-y-300;
			clicked++;
			glutPostRedisplay();
		}
	}
}
void display(){
	glClear(GL_COLOR_BUFFER_BIT);
	glBegin(GL_LINE_STRIP);
	for(int i=0;i<clicked;i++){
		glVertex2f(vx[i],vy[i]);
	}
	glEnd();
	glFlush();
}
int main(int argc, char* argv[]){
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_RGB|GLUT_SINGLE);
	glutInitWindowSize(600,600);
	glutCreateWindow("Vija e thyer");
	initDraw();
	glutKeyboardFunc(keyboard);
	glutMouseFunc(mouse);
	glutDisplayFunc(display);
	glutMainLoop();
}
