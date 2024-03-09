#include <stdio.h>
#include <stdlib.h>
#include <GL/glut.h>

/* run this program using the console pauser or add your own getch, system("pause") or input loop */

void Inicializa();
void desenha(void);
void teclado(unsigned char tecla, int x, int y);
void reshape(int w, int h);


// o trinta representa a quantidade de pontos que eu passei ao longo das vertices
static GLfloat vertices[30]={
	
	// o nosso cubo tera apenas 9 vertices na forma que vamos deixa-lo
	
	0.0, 30.0, 30.0,//0
	20.0, 30.0, 30.0,//1
	30.0, 20.0, 30.0,//2
	30.0, 0.0, 30.0,//3
	0.0, 0.0, 30.0,//4
	0.0, 30.0, 0.0,//5
	30.0, 30.0, 0.0,//6
	30.0, 0.0, 0.0,//7
	0.0, 0.0, 0.0,//8
	30.0, 30.0, 20.0//9	
};


//defini��o das faces, os n�meros que passamos dentro dos {} s�o as vertices acima, ent�o ele pega os 3 n�mero de cada um dos valores
static GLubyte frente[] = {0, 4, 3, 2, 1};
static GLubyte tras[] = {5,6,7,8};
static GLubyte esquerda[] = {0,5,8,4};
static GLubyte direita[] = {2, 3, 7, 6, 9};
static GLubyte topo[] = {0, 1, 9, 6, 5};
static GLubyte fundo[] = {3, 4, 8, 7};
static GLubyte triangulo[] = {1, 2, 9};


static int eixox, eixoy;
int largura, altura;


void main(int argc, char** argv) {

	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
	glutInitWindowSize(256,256);
	glutInitWindowPosition(10,10);
	glutCreateWindow("Cubo");
	
	Inicializa();	
	
	glutDisplayFunc(desenha);
	glutKeyboardFunc(teclado);
	glutReshapeFunc(reshape);
		
	glutMainLoop();
};

void Inicializa(){
	glClearColor(0.0, 0.0, 0.0, 0.0);
	
	//cada par � x y e z
	glOrtho(-50,50,-50,50,-50,50);
	
	
	//esse c�digo vai calcular os pontos. se eu tenho 2, ele vai calcular qual est� na frente e qual est� atr�s. Calcula pontos(profundidade)
	glEnable(GL_DEPTH_TEST);
	
	//ESSE AQUI VAI REMOVER O PONTO DE TR�S
	glEnable(GL_CULL_FACE);
};

void desenha(){
	glPushMatrix();
	
	
	//rota��es
	//vamos fazer duas vezes, j� que a rota��o que queremos nesse exemplo � para x e y.
	glRotatef((GLfloat) eixoy, 0.0, 1.0, 0.0);
	glRotatef((GLfloat) eixox, 1.0, 0.0, 0.0);
	
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	
	
	// desenhar usando os vertices
	glEnableClientState(GL_VERTEX_ARRAY);
	
	
	// 3 � numero de elementos para formar o vertice, aquela variavel que cadastrou l� em cima chamada vertice,
	//GL_FLOAT � o tipo do dado no vetor, os pontos.
	// 0 � um STRIDER - um deslocamento inicial, um offset
	// vertices � o nome do vetor / variavel que armazena os pontos. 
	glVertexPointer(3, GL_FLOAT, 0, vertices);

	glColor3f(1.0, 0.0,0.0);
	//desenha os elementos
	// PASSAMOS PRIMEIRO O TIPO DO ELEMENTO, � UM DRAW ELEMENTS PARA CADA UMA DAS FACES.
	// Formato, polygon ou linha ou triangle, tanto faz. Depois colocamos a quantidade de vertices naquele lado que est� desenhando, depois o TIPO e depois
	// O �ltimo � o GLubyte referente ao lado que est� sendo criado.
	glDrawElements(GL_POLYGON, 5, GL_UNSIGNED_BYTE, frente);
	glColor3f(0.0, 1.0,0.0);
	glDrawElements(GL_QUADS, 4, GL_UNSIGNED_BYTE, esquerda);
	glColor3f(0.0, 0.0,1.0);
	glDrawElements(GL_QUADS, 4, GL_UNSIGNED_BYTE, tras);
	glColor3f(1.0, 1.0,0.0);
	glDrawElements(GL_POLYGON, 5 , GL_UNSIGNED_BYTE, direita);
	glColor3f(1.0, 0.0,1.0);
	glDrawElements(GL_POLYGON, 5, GL_UNSIGNED_BYTE, topo);
	glColor3f(0.0, 1.0,1.0);
	glDrawElements(GL_QUADS, 4, GL_UNSIGNED_BYTE, fundo);
	glColor3f(0.5, 0.5, 0.3);
	glDrawElements(GL_TRIANGLES, 3, GL_UNSIGNED_BYTE, triangulo);
	
	glDisableClientState(GL_VERTEX_ARRAY);
	
	glPopMatrix();
	glFlush();
	
};


//precisamos de 3 valores, a tecla pressionada e x e y em rela��o ao mouse.
void teclado(unsigned char tecla, int x, int y) {
	switch(tecla) {
		//se apertar a tecla ESC, fecha o sistema.
		case 27:
			exit(0);
			break;
		case 'y':
			eixoy = (eixoy + 5) % 360; //dividir por 360 � s� para ajustar a rota��o nos eixos.	
			glutPostRedisplay(); //for�a o redesenho da imagem
			break;
		case 'x':
			eixox = (eixox + 5) % 360; //dividir por 360 � s� para ajustar a rota��o nos eixos.	
			glutPostRedisplay(); //for�a o redesenho da imagem
			break;	
		case 'p':
			glLoadIdentity(); //limpa o buffer e faz � partir daqui, ou seja, da um reset nas coordenadas
			gluPerspective(65.0, (GLfloat) largura/(GLfloat) altura, 20.0, 120.0);
			gluLookAt(0, 0, -90, 0, 0, 0, 0, 1, 0);
			glutPostRedisplay(); //for�a o desenho para o lookat
			break;
		case 'o':
			glLoadIdentity(); //limpa o buffer e faz � partir daqui, reseta as coorde
			glOrtho(-50, 50, -50, 50, -50, 50);
			glutPostRedisplay();//for�a o desenho para o lookat
			break;	
	}
}

void reshape(int w, int h) {
	
	//estou indicando que a minha janela vai de 0 0 at� o tamanho que definiu rodando o app.
	glViewport(0, 0, (GLsizei) w, (GLsizei) h);
	
	largura = w;
	altura = h;
	
}
