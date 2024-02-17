#include <stdio.h>
#include <stdlib.h>
#include <GL/glut.h>

/* run this program using the console pauser or add your own getch, system("pause") or input loop */

void Desenha(void){
	glClear(GL_COLOR_BUFFER_BIT); /*limpa a janela de visualização com a cor de fundo especificada*/
	
	int i;

	glColor3f (1.0, 0.0, 0.0);
	glEnable(GL_LINE_SMOOTH);
	
	glEnable(GL_LINE_STIPPLE); //ativa padrão
	
	glLineWidth(1.0); // define a largura da linha
	
	//(fator, padrão), SENDO O PADRÃO 0x+ALGUMACOISA, exemplo => 0x0101, 0xAAAA
	glLineStipple(1, 0x0101); //dotted
	glBegin(GL_TRIANGLE_FAN); //coordenadas linha
		glVertex2f(30, 30); //ponto1 T1
		glVertex2f(30, 180); //ponto 2 T1
		glVertex2f(80, 150); //ponto 3 T1
		glVertex2f(100, 100); //ponto 4 T2
		glVertex2f(100, 30); //ponto 5 T3
	glEnd();
	
	
	glDisable(GL_LINE_STIPPLE); //desativa o padrão
	
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
