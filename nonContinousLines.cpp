#include <iostream>
#include <GL/glut.h>

int i=0;
//structure that holds the coordinates of a points
struct pika {
	int xp;
	int yp;
};
//array of points
struct pika pikat[100];
//initializer for the viewport
void init(){
	glClearColor(0.0,0.0,0.0,0.0);
	glViewport(0,0,300,300);
	gluOrtho2D(0.0,300.0,0.0,300.0);
}
//clear the buffer
void display(){
	glClear(GL_COLOR_BUFFER_BIT);
}
//draws a line that connects two points
void drawLine(pika pt1, pika pt2){
	glBegin(GL_LINE_STRIP);
	glVertex2i(pt1.xp,pt1.yp);
	glVertex2i(pt2.xp,pt2.yp);
	glEnd();
	glFlush();
}
//function that handles mouse events
//when the number of clicks is even, it saves the coordinates of the last click.
//when the number of clicks is odd, it draws a line that connects the last two clicks.
void mouse(int button, int state, int x, int y){
	if (button==GLUT_LEFT_BUTTON && state==GLUT_DOWN){
		if(i%2==0){
			pikat[i].xp=x;
			pikat[i].yp=300-y;
			i=i+1;
		}
		else{
			pikat[i].xp = x;
			pikat[i].yp = 300-y;
			drawLine(pikat[i-1],pikat[i]);
			i=i+1;
		}
	}
	glutPostRedisplay();
}
//main function
int main(int argc, char*argv[]){
	glutInit(&argc,argv);
	glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
	glutInitWindowSize(300,300);
	glutCreateWindow("Dritare");
	init();
	glutDisplayFunc(display);
	glutMouseFunc(mouse);
	glutMainLoop();
}
