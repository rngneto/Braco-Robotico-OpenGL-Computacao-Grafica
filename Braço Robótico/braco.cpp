/*
 * Computacao Grafica
 * Codigo Exemplo: Braco Robotico usando GLUT/OpenGL
 * Autor: Prof. Laurindo de Sousa Britto Neto
 * Alterado pelo aluno: Raimundo Nonato Gomes Neto
 */

// Bibliotecas utilizadas pelo OpenGL
#ifdef __APPLE__
#define GL_SILENCE_DEPRECATION
#include <GLUT/glut.h>
#include <OpenGL/gl.h>
#include <OpenGL/glu.h>
#else
#include <GL/glut.h>
#include <GL/gl.h>
#include <GL/glu.h>
#endif

#include <stdio.h>
#include <stdlib.h>

#define ESC 27

/*
 * Declaracao de constantes e variaveis
 */
static int ombro = 0, cotovelo = 0, mao = 0, indicador = 0, polegar = 0, anelar = 0, rotaEixoY = 0, rotaEixoX = 0, rotaEixoZ = 0;

/*
 * Declaracoes antecipadas (forward) das funcoes (assinaturas)
 */
void init(void);
void keyboard (unsigned char key, int x, int y);
void display(void);
void reshape (int w, int h);

//Fucao principal
int main(int argc, char** argv)
{

	// inicia o GLUT
	glutInit(&argc, argv);

	// inicia o display usando RGB, double-buffering e z-buffering
	glutInitDisplayMode(GLUT_RGB | GLUT_DOUBLE | GLUT_DEPTH);
	glutInitWindowSize(800, 800);
	glutInitWindowPosition(100, 100);
	glutCreateWindow("Computacao Grafica: Braco Robotico - Raimundo Neto");

	// Funcao com alguns comandos para a inicializacao do OpenGL
	init ();

	// define as funcoes de callback
	glutDisplayFunc(display);
	glutReshapeFunc(reshape);
	glutKeyboardFunc(keyboard);
	glutMainLoop();

	return EXIT_SUCCESS;
}

// Funcao com alguns comandos para a inicializacao do OpenGL
void init(void)
{
	glClearColor (1.0, 1.0, 1.0, 1.0); //Limpa a tela com a cor branca;
	glEnable(GL_DEPTH_TEST); // Habilita o algoritmo Z-Buffer
}

//Funcal callback para o reshape da janela
void reshape (int w, int h)
{

	// muda para o modo GL_PROJECTION e reinicia a matriz de projecao
	glMatrixMode (GL_PROJECTION);
	glLoadIdentity();

	// define o tamanho da area de desenho da janela
	glViewport (0, 0, (GLsizei) w, (GLsizei) h);

	// Define a forma do volume de visualizacao para termos
	// uma projecao perspectiva (3D).
	gluPerspective(60, (float)w / (float)h , 1.0, 9.0); //(angulo, aspecto, ponto_proximo, ponto distante)
	gluLookAt(0.0, 0.0, 7.0, // posicao da camera (olho)
			  0.0, 1.0, 0.0, // direcao da camera (geralmente para centro da cena)
			  0.0, 1.0, 0.0); // sentido ou orientacao da camera (de cabeca para cima)
	// muda para o modo GL_MODELVIEW para desenhar na tela
	glMatrixMode (GL_MODELVIEW);

}

// Fucao callback para controle das teclas comuns
void keyboard (unsigned char key, int x, int y)
{
	switch (key)
	{

	case 'o':
		ombro = (ombro - 5) % 360;
		break; // sentido horario
	case 'O':
		ombro = (ombro + 5) % 360;
		break; // sentido anti-horario
	case 'c':
		cotovelo = (cotovelo - 5) % 360;
		break; // sentido horario
	case 'C':
		cotovelo = (cotovelo + 5) % 360;
		break; // sentido anti-horario
	case 'm':
		mao = (mao - 5) % 360;
		break; // sentido horario
	case 'M':
		mao = (mao + 5) % 360;
		break; // sentido anti-horario
	case 'i':
		indicador = (indicador - 5) % 360;
		break; // sentido horario
	case 'I':
		indicador = (indicador + 5) % 360;
		break; // sentido anti-horario
	case 'p':
		polegar = (polegar - 5) % 360;
		break; // sentido horario
	case 'P':
		polegar = (polegar + 5) % 360;
		break; // sentido anti-horario
	case 'a':
		anelar = (anelar - 5) % 360;
		break; // sentido horario
	case 'A':
		anelar = (anelar + 5) % 360;
		break; // sentido anti-horario
	case 'y':
		rotaEixoY = (rotaEixoY - 5) % 360;
		break; // sentido horario
	case 'Y':
		rotaEixoY = (rotaEixoY + 5) % 360;
		break; // sentido anti-horario
	case 'x':
		rotaEixoX = (rotaEixoX - 5) % 360;
		break; // sentido horario
	case 'X':
		rotaEixoX = (rotaEixoX + 5) % 360;
		break; // sentido anti-horario
	case 'z':
		rotaEixoZ = (rotaEixoZ - 5) % 360;
		break; // sentido horario
	case 'Z':
		rotaEixoZ = (rotaEixoZ + 5) % 360;
		break; // sentido anti-horario

	case 'r':
	case 'R':
		ombro = 0;
		cotovelo = 0;
		mao = 0;
		indicador = 0;
		polegar = 0;
		anelar = 0;
		rotaEixoX = 0;
		rotaEixoY = 0;
		rotaEixoZ = 0;
		break; //Volta TODO o Bra�o para a posi��o original

	case ESC:
		exit(EXIT_SUCCESS);
		break; // sai do programa
	}
	glutPostRedisplay();
}

// Funcao callback para desenhar na janela
void display(void)
{

	glClear (GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT); //Limpa o Buffer de Cores
	glLoadIdentity();

	glRotatef ((GLfloat) rotaEixoX, 1.0, 0.0, 0.0);//rota��o de todo o bra�o em torno do eixo X
	glRotatef ((GLfloat) rotaEixoZ, 0.0, 0.0, 1.0);//rota��o de todo o bra�o em torno do eixo Z

	//Base
	glPushMatrix();
	glTranslatef(0.0, -2.0, 0.0);
	glRotatef(-90, 1, 0, 0);
	glColor3f(0.0, 0.0, 0.4);//Azul Escuro
	glutSolidCone(1.0, 1.0, 30, 30); // base, altura, fatias, pilhas
	glPopMatrix();

	//Define a largura das linhas para 2 pixels - Desenho das linhas da base
	glLineWidth(2.0);

	//Base com contorno branco
	glPushMatrix();
	glTranslatef(0.0, -2.0, 0.0);
	glRotatef(-90, 1, 0, 0);
	glColor3f(1.0, 1.0, 1.0); //Contorno branco
	glutWireCone(1.0, 1.0, 30, 30); // base, altura, fatias, pilhas
	glPopMatrix();

	// Restaura a largura das linhas para o valor padr�o (1.0)
	glLineWidth(1.0);

	//Ombro
	glPushMatrix();
	glTranslatef(0.0, -1.0, 0.0);
	glColor3f(0.0, 0.28, 0.67);//Azul cobalto
	glutSolidSphere(0.5, 30, 30); // raio, fatias, pilhas
	glPopMatrix();
	glRotatef ((GLfloat) rotaEixoY, 0.0, 1.0, 0.0);//rota��o de todo o bra�o em torno do eixo Y
	//Movimento do ombro
	glPushMatrix();
	//Origem posicionada no ombro
	glTranslatef (0.0, -1.0, 0.0);
	glRotatef ((GLfloat) ombro, 0.0, 0.0, 1.0);
	//Origem posicionada no centro do braco
	glTranslatef (0.0, 1.0, 0.0);

	//Braco
	glPushMatrix();
	glRotatef(90, 0, 0, 1);
	glScalef (2.0, 0.5, 0.5);
	glColor3f(0.4, 0.4, 0.4);//Tom de cinza
	glutSolidCube (1.0); // Tamanho
	glPopMatrix();

	//Cotovelo
	glPushMatrix();
	glTranslatef(0.0, 1.0, 0.0);
	glColor3f(0.0, 0.7, 0.7); //Turquesa
	glutSolidSphere(0.4, 30, 30); // raio, fatias, pilhas
	glPopMatrix();

	//Movimento do antebraco
	glPushMatrix();
	//Origem posicionada no cotovelo
	glTranslatef (0.0, 1.0, 0.0);
	glRotatef ((GLfloat) cotovelo, 0.0, 0.0, 1.0);
	glTranslatef (0.0, 1.0, 0.0);

	//Antebraco
	glPushMatrix();
	glRotatef(90, 0, 0, 1);
	glScalef (2.0, 0.4, 0.4);
	glColor3f(0.6, 0.6, 0.6);//Tom de cinza
	glutSolidCube (1.0); // Tamanho
	glPopMatrix();

	//Punho
	glPushMatrix();
	glTranslatef(0.0, 1.0, 0.0);
	glColor3f(0.0, 1.0, 1.0);// Ciano
	glutSolidSphere(0.3, 30, 30); // raio, fatias, pilhas
	glPopMatrix();

	//Movimento da m�o
	glPushMatrix();
	//Origem posicionada no punho
	glTranslatef (0.0, 1.0, 0.0); // eleva o cubo
	glRotatef ((GLfloat) mao, 0.0, 0.0, 1.0);
	glTranslatef (0.0, 0.75, 0.0);

	//M�o
	glPushMatrix();
	glRotatef(90, 0, 0, 1);
	glScalef (1.0, 0.3, 0.3);
	glColor3f(0.8, 0.8, 0.8);//Tom de cinza
	glutSolidCube (1.0); // Tamanho
	glPopMatrix();

	//Palma da m�o
	glPushMatrix();
	glTranslatef(0.0, 0.5, 0.0);
	glColor3f(0.0, 0.0, 0.0);//Preto
	glutSolidSphere(0.2, 30, 30); // raio, fatias, pilhas
	glPopMatrix();

	//Posi��o do Polegar
	glPushMatrix();
	//Origem posicionada na palma da m�o
	glTranslatef (0.1, 0.6, 0.0);
	glRotatef ((GLfloat) polegar, 0.0, 0.0, 1.0);
	glTranslatef (0.0, 0.25, 0.0);

	//Defini��o do Polegar
	glPushMatrix();
	glRotatef(90, 0, 0, 1);
	glScalef (0.5, 0.1, 0.1);
	glColor3f(1.0, 0.0, 0.0);//Vermelho
	glutSolidCube (0.9); // Tamanho
	glPopMatrix();

	glPopMatrix();

	//Posi��o do Anelar
	glPushMatrix();
	//Origem posicionada na palma da m�o
	glTranslatef (-0.1, 0.6, 0.1); // eleva o cubo
	glRotatef ((GLfloat) anelar, 0.0, 0.0, 1.0);
	glTranslatef (0.0, 0.25, 0.0);

	//Defini��o do Anelar
	glPushMatrix();
	glRotatef(90, 0, 0, 1);
	glScalef (0.5, 0.1, 0.1);
	glColor3f(0.0, 1.0, 0.0);//Verde
	glutSolidCube (0.9); // Tamanho
	glPopMatrix();

	glPopMatrix();

	//Defini��o do Indicador
	glPushMatrix();
	//Origem posicionada no braco
	glTranslatef (-0.1, 0.6, -0.1); // eleva o cubo
	glRotatef ((GLfloat) indicador, 0.0, 0.0, 1.0);
	glTranslatef (0.0, 0.25, 0.0);

	//Defini��o do Indicador
	glPushMatrix();
	glRotatef(90, 0, 0, 1);
	glScalef (0.5, 0.1, 0.1);
	glColor3f(0.0, 0.0, 1.0);//Azul
	glutSolidCube (1.0); // Tamanho
	glPopMatrix();

	glPopMatrix();
	glPopMatrix();
	glPopMatrix();

	//Origem volta para o sistema de coordenadas original
	glPopMatrix();

	//Troca os buffers, mostrando o que acabou de ser desenhado
	glutSwapBuffers();
}

