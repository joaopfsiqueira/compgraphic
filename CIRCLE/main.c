#include <stdio.h>
#include <stdlib.h>
#include <GL/glut.h>

/* run this program using the console pauser or add your own getch, system("pause") or input loop */

void Desenha2(void){
	
	int i;
	float theta;
	
	glClear(GL_COLOR_BUFFER_BIT); /*limpa a janela de visualização com a cor de fundo especificada*/

	glColor3f (1.0, 0.0, 0.0);
	
	glEnable(GL_POLYGON_SMOOTH); //habilita anti-aliasing
	glEnable(GL_BLEND);
	glBlendFunc(GL_SRC_ALPHA, 1);
	
	glBegin(GL_POLYGON); //coordenadas linha
		for (i=0;i<360;i++) {
			theta=i*3.142/180;
			glVertex2f(125+100*cos(theta), 125+100*sin(theta));
		}
	
	glEnd();
	

	glDisable(GL_POLYGON_SMOOTH);
	
	//executa os comandos OpenGl, basicamente limpa o buffer.
	glFlush();
}

void Inicializa2(void) {
	
	//define a cor de fundo da janela de visualização como preta, modelo RGBA
	glClearColor(0, 0, 0, 0.2);
	gluOrtho2D(0, 250, 0, 250); // define a materia
}


int main(int argc, char **argv) {
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
	glutInitWindowSize(400, 150);
	glutInitWindowPosition(100, 100);
	
	glutCreateWindow("Primeiro Programa 2");
	glutDisplayFunc(Desenha2);
	
	
	Inicializa2();
	glutMainLoop();
	
	return 0;
}
