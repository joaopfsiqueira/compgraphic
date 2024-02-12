#include <stdio.h>
#include <stdlib.h>
#include <GL/glut.h>
/* run this program using the console pauser or add your own getch, system("pause") or input loop */

/*
headers
*/


/*
rotinas de callback
*/
void display(void){
	
}


/* funções principais*/
int main(int argc, char *argv[]) {
	glutInit(&argc, argv)
	
	glutInitDisplayMode( modo );
	/* inicializa o display mode*/
	
	glutCreateWindow(nome_da_janela);
	/*cria a janela*/
	
	
	glutDisplayFunct(display);
	/* registro de chamada de callback*/
	
	glutMainLoop();
	/* é o que faz a imagem manter, sem isso ela aparece e some*/
	
	return 0;
}
