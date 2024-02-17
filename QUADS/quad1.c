#include <stdio.h>
#include <stdlib.h>
#include <GL/glut.h>

/* run this program using the console pauser or add your own getch, system("pause") or input loop */

void Desenha(void){
	glClear(GL_COLOR_BUFFER_BIT); /*limpa a janela de visualização com a cor de fundo especificada*/

	glColor3f (1.0, 0.0, 0.0);
	
	glBegin(GL_QUADS); //coordenadas linha
		glVertex2f(50, 70); //ponto1 
		glVertex2f(70, 140); //ponto 2 
		glVertex2f(120, 150); //ponto 3 
		glVertex2f(130, 30); //ponto 4
	glEnd();
	

	
	//executa os comandos OpenGl, basicamente limpa o buffer.
	glFlush();
}

void Inicializa(void) {
	
	//define a cor de fundo da janela de visualização como preta, modelo RGBA
	glClearColor(0, 0, 0, 0.2);
	gluOrtho2D(0, 250, 0, 250); // define a materia
}


int main(int argc, char **argv) {
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
	glutInitWindowSize(400, 150);
	glutInitWindowPosition(100, 100);
	
	glutCreateWindow("Primeiro Programa");
	glutDisplayFunc(Desenha);
	
	
	Inicializa();
	glutMainLoop();
	
	return 0;
}
