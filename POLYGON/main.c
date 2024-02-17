#include <stdio.h>
#include <stdlib.h>
#include <GL/glut.h>

/* run this program using the console pauser or add your own getch, system("pause") or input loop */

void Desenha2(void){
	glClear(GL_COLOR_BUFFER_BIT); /*limpa a janela de visualização com a cor de fundo especificada*/

	glColor3f (1.0, 0.0, 0.0);
	
	glBegin(GL_POLYGON); //coordenadas linha
		glVertex2f(100, 170); //ponto1 
		glVertex2f(150, 200); //ponto 2 
		glVertex2f(130, 80); //ponto 3 
		glVertex2f(120, 150); //ponto 4
		glVertex2f(80, 30);
		glVertex2f(30, 70);
	glEnd();
	

	
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
