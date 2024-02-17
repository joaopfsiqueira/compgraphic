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
	glBegin(GL_LINES); //coordenadas linha
		glVertex2f(30.0, 30.0); //ponto inicial
		glVertex2f(220.0, 30.0); //ponto final
	glEnd();
	
	
	glLineStipple(1, 0x00FF); //dashed
	glBegin(GL_LINES);
		glVertex2f(30.0, 80.0);
		glVertex2f(220.0, 80.0);
	glEnd();
	
	glLineStipple(1, 0x1C47);	//dash/dot/dash	
	glBegin(GL_LINES);
		glVertex2f(30.0, 120.0);
		glVertex2f(220.0, 120.0);
	glEnd();
	
	glLineStipple(1, 0xAAAA);
	glBegin(GL_LINES);
		glVertex2f(30.0, 150.0);
		glVertex2f(220.0, 150.0);
	glEnd();
	
	glLineStipple(1, 0x0C0F);
	glBegin(GL_LINES);
		glVertex2f(30.0, 180.0);
		glVertex2f(220.0, 180.0);
	glEnd();	
	
	glLineStipple(2, 0xAAAA);
	glBegin(GL_LINES);
		glVertex2f(30.0, 210.0);
		glVertex2f(220.0, .0);
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
