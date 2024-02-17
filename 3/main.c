#include <stdio.h>
#include <stdlib.h>
#include <GL/glut.h>

/* run this program using the console pauser or add your own getch, system("pause") or input loop */

void Desenha(void){
	glClear(GL_COLOR_BUFFER_BIT); /*limpa a janela de visualização com a cor de fundo especificada*/
	
	
	//desenha pontos na tela, com tamanho variando entre 1 e 15
	//a variação ocorre de 0.5 em 0.5
	float distance = 1.0f/15;
	float pos = -1 + distance;
	float i;
	
	//desenha os pontos, sem suavização
//	glDisable(GL_POINT_SMOOTH);
	
	
	//desenha os pontos, com suavização
	for (i= 1; i <= 15; i += 0.5){
		glPointSize(i);
		glBegin(GL_POINTS);
			glVertex2f(pos, 0.0f);
		glEnd();
		pos +=distance;	
	}
	
	//executa os comandos OpenGl, basicamente limpa o buffer.
	glFlush();
}

void Inicializa(void) {
	
	//define a cor de fundo da janela de visualização como preta, modelo RGBA
	glClearColor(0.3, 0.5, 0.4, 0.2);
}


int main(int argc, char **argv) {
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
	glutCreateWindow("Primeiro Programa");
	glutDisplayFunc(Desenha);
	Inicializa();
	glutMainLoop();
	
	return 0;
}
