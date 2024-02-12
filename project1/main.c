#include <stdio.h>
#include <stdlib.h>
#include <GL/glut.h>

/* run this program using the console pauser or add your own getch, system("pause") or input loop */

void Desenha(void){
	glClear(GL_COLOR_BUFFER_BIT); /*limpa a janela de visualização com a cor de fundo especificada*/
	
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
