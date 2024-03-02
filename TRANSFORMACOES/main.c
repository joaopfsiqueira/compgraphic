#include <stdio.h>
#include <stdlib.h>
#include <GL/glut.h>

/* lembre-se que os comandos são executados em PILHA, ou seja, DE BAIXO PARA CIMA. 
TODA ESCALA E ROTAÇÃO precisa da TRANSLAÇÃO para mover o objeto para o lugar que estava antes de executar algo dentro de uma matriz
*/

void DesenhaObjeto(void){
	
		//DESENHA OBJETO
	glBegin(GL_LINE_LOOP); //começa o desenho
		glVertex2f(4,5); //desenha a linha
		glVertex2f(7,5); //desenha a linha
		glVertex2f(5.5, 9); //desenha a linha
	glEnd();
}

void DesenhaTransalacao(void) {
	//limpa a janela de visualização com a cor
	glClear(GL_COLOR_BUFFER_BIT);
	
	glColor3f(1,0,0); //colocando uma cor
	DesenhaObjeto();
	
	// toda transformação precisa do pushmatrix e pop matrix. Tudo que estiver dentro disso está dentro da matriz de transformação.
	glPushMatrix();
	// vc passa os valores conforme o teu ortho. se for ortho2d, vc só passa x e y. se for ortho normal vc passa para x y e z
		glColor3f(0,0,1); //colocando uma cor
		glTranslatef(4, -3, 0); //efetua a transformação. Lembrando que a transformação tem que estar antes do desenho do OBJETO.
		DesenhaObjeto();
	glPopMatrix();
	
	//Executa os comandos OPENGL
	glFlush();
}


void DesenhaEscala(void) {
	//limpa a janela de visualização com a cor
	glClear(GL_COLOR_BUFFER_BIT);
	
	glColor3f(1,0,0); //colocando uma cor
	DesenhaObjeto();
	
	//abaixo temos exemplo da execução de PILHA, dentro da matrix, entre a linha 47 e 55, é executado em pilha. executa a linha 54 para cima.
	
	// toda transformação precisa do pushmatrix e pop matrix. Tudo que estiver dentro disso está dentro da matriz de transformação.
	glPushMatrix();
	// vc passa os valores conforme o teu ortho. se for ortho2d, vc só passa x e y. se for ortho normal vc passa para x y e z
		glColor3f(0,0,1); //colocando uma cor
		glTranslatef(4, 5, 0); //depois de voltar para o inicio, devemos então colocar ele onde queremos.
		glScalef(0.5, 0.25, 0); //apenas com esse código o scale vai mudar a escala do objeto.
		glTranslatef(-4, -5, 0); //se n usarmos o glTranslate o proprio scale vai mover o objeto, mas vai mover para o lugar errado. Então primeiro devemos
		//levar o objeto até a origin, basicamente olhando o primeiro vertex2f e colocando os valores dele negativo. como feito acima.
		DesenhaObjeto();
	glPopMatrix();
	
	//Executa os comandos OPENGL
	glFlush();
}


void DesenhaRotacao(void) {
	//como o proprio nome sugere, agora vamos rotacionar o objeto.
	
	//limpa a janela de visualização com a cor
	glClear(GL_COLOR_BUFFER_BIT);
	
	glColor3f(1,0,0); //colocando uma cor
	DesenhaObjeto();
	
	//abaixo temos exemplo da execução de PILHA, dentro da matrix, entre a linha 47 e 55, é executado em pilha. executa a linha 54 para cima.
	
	// toda transformação precisa do pushmatrix e pop matrix. Tudo que estiver dentro disso está dentro da matriz de transformação.
	glPushMatrix();
	// vc passa os valores conforme o teu ortho. se for ortho2d, vc só passa x e y. se for ortho normal vc passa para x y e z
		glColor3f(0,0,1); //colocando uma cor
		glTranslatef(4, 5, 0); //depois de voltar para o inicio, devemos então colocar ele onde queremos.
		
		glScalef(0.5, 0.25, 0); //apenas com esse código o scale vai mudar a escala do objeto.

		// (grau, x, y, z);
		//então abaixo falamos que vai mover em um 45 graus.
		glRotatef(45, 0, 0, 1);
		

		glTranslatef(-4, -5, 0); //se n usarmos o glTranslate o proprio rotate vai mover o objeto, mas vai mover para o lugar errado. Então primeiro devemos
		//levar o objeto até a origin, basicamente olhando o primeiro vertex2f e colocando os valores dele negativo. como feito acima.
		

		DesenhaObjeto();
	glPopMatrix();
	
	//Executa os comandos OPENGL
	glFlush();
}


void Inicializa(void){
	//define a cor de fundo da janela
	glClearColor(1.0, 1.0, 1.0, 1.0);
	
	//forma de projeção ortogonal
	//glOrtho(xMin, xMax, yMin, yMax, zMin, zMax)
	gluOrtho2D(0,12,0, 12); //como é 2d, só utilizamos x e y. se fosse o outro tirariamos o 2d do nome pra usar o z e ai viraria 3d.
	//aqui definimos que x (cima) é 12, entãovamos passar um numero entre 0 e 12 nas vertex. o mesmo para o y (lado).
}

//programa principal
void main(int argc, char *argv[]) {
	
	
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
	glutInitWindowSize(640,480);
	glutInitWindowPosition(10,10);
	
	glutCreateWindow("Transformacoes");
	//glutDisplayFunc(DesenhaTransalacao);
	//glutDisplayFunc(DesenhaEscala);
	glutDisplayFunc(DesenhaRotacao);
	
	Inicializa();
	
	// toda manipulação que a gente fizer na tela o comando abaixo atualiza.
	glutMainLoop();
}
