#include <stdlib.h>
#include <GL/glut.h>
#include <math.h>
#include <stdio.h>

#define WIDTH 800
#define HEIGHT 800

// Controle das implementações
int implementacao = 1;

float vertices[][3] = {
{1, 1, 1}, {-1, 1, 1}, {-1, 1, -1}, {1, 1, -1},
{1, -1, 1}, {-1, -1, 1}, {-1, -1, -1}, {1, -1, -1}
};

int edges[][2] = {
{0, 1}, {1, 2}, {2, 3}, {3, 0},
{4, 5}, {5, 6}, {6, 7}, {7, 4},
{0, 4}, {1, 5}, {2, 6}, {3, 7},
};

void init();
void display();
void question1();
void question2();
void question3();
void question4();
void menuImplementacoes(int op);
void menuPrincipal(int op);
void criaMenu();
void textoBitmap(void *font, char *s);

int main(int argc, char **argv)
{
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
    glutInitWindowSize(WIDTH, HEIGHT);
    glutInitWindowPosition(5, 5);
    glutCreateWindow("Prova II de Computação Gráfica - Implementações");
    glutDisplayFunc(display);
    init();
    criaMenu();

    glutMainLoop();

    return(0);
}

void init()
{
    glClearColor(0.0f, 0.0f, 0.0f, 0.0f);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluPerspective(90.0f, (float)WIDTH / (float)HEIGHT, 0.0f, 100.0f);
    glClear(GL_COLOR_BUFFER_BIT);
    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();
    glTranslatef(0.0f, 0.0f, -5.0f);
}

void display()
{
    glClear(GL_COLOR_BUFFER_BIT);
    glColor3f(1.0f, 1.0f, 1.0f);

    glRasterPos2f(-2.2f, -2.0f); // Posição do texto
    textoBitmap(GLUT_BITMAP_HELVETICA_12, "Clique com o botao direito e acesse as outras implementacoes");

    if(implementacao == 1)
    {
        question1();
    }

    if(implementacao == 2)
    {
        question2();
    }

    if(implementacao == 3)
    {
        question3();
    }

    if(implementacao == 4)
    {
        question4();
    }

    glFlush();
}

// Implementação 1
void question1()
{
    int i, vertice1, vertice2;
    float x1, x2, y1, y2, z1, z2;

    glColor3f(1.0, 1.0, 1.0);

    glBegin(GL_LINES);
        for(i = 0; i < 12; i++)
        {
            vertice1 = edges[i][0];

            x1 = vertices[vertice1][0];
            y1 = vertices[vertice1][1];
            z1 = vertices[vertice1][2];

            vertice2 = edges[i][1];

            x2 = vertices[vertice2][0];
            y2 = vertices[vertice2][1];
            z2 = vertices[vertice2][2];

            glVertex3f(x1, y1, z1);
            glVertex3f(x2, y2, z2);
        }
    glEnd();
}

// Implementação 2
void question2()
{
    int i, j;
    float x, y, z;

    for(i = 0; i < 9; i++)
    {
        for(j = 0; j < 9; j++)
        {
            glBegin(GL_LINE_LOOP);

                x = (2.0 * (i + 1) / 9.0) - 1;
                y = 1 - pow(x, 2);
                z = (2.0 * j / 9.0) - 1;
                glVertex3f(x, y, z);

                x = (2.0 * (i + 1) / 9.0) - 1;
                y = 1 - pow(x, 2);
                z = (2.0 * (j + 1) / 9.0) - 1;
                glVertex3f(x, y, z);

                x = (2.0 * i / 9.0) - 1;
                y = 1 - pow(x, 2);
                z = (2.0 * (j + 1) / 9.0) - 1;
                glVertex3f(x, y, z);

                x = (2.0 * i / 9.0) - 1;
                y = 1 - pow(x, 2);
                z = (2.0 * j / 9.0) - 1;
                glVertex3f(x, y, z);

            glEnd();
        }
    }
}

// Implementação 3
void question3()
{
    int i, j;
    float x, y, z;

    for(i = 0; i < 9; i++)
    {
        for(j = 0; j < 9; j++)
        {
            glBegin(GL_LINE_LOOP);

                x = (2.0 * (i + 1) / 9.0) - 1;
                y = sqrt(1 - pow(x, 2));
                z = (2.0 * j / 9.0) - 1;
                glVertex3f(x, y, z);

                x = (2.0 * (i + 1) / 9.0) - 1;
                y = sqrt(1 - pow(x, 2));
                z = (2.0 * (j + 1) / 9.0) - 1;
                glVertex3f(x, y, z);

                x = (2.0 * i / 9.0) - 1;
                y = sqrt(1 - pow(x, 2));
                z = (2.0 * (j + 1) / 9.0) - 1;
                glVertex3f(x, y, z);

                x = (2.0 * i / 9.0) - 1;
                y = sqrt(1 - pow(x, 2));
                z = (2.0 * j / 9.0) - 1;
                glVertex3f(x, y, z);

            glEnd();
        }
    }
}

// Implementação 4
void question4()
{
    int i, j;
    float x, y, z;

    for(i = 0; i < 9; i++)
    {
        for(j = 0; j < 9; j++)
        {
            glBegin(GL_LINE_LOOP);

                x = (2.0 * (i + 1) / 9.0) - 1;
                y = 1 - fabs(x);
                z = (2.0 * j / 9.0) - 1;
                glVertex3f(x, y, z);

                x = (2.0 * (i + 1) / 9.0) - 1;
                y = 1 - fabs(x);
                z = (2.0 * (j + 1) / 9.0) - 1;
                glVertex3f(x, y, z);

                x = (2.0 * i / 9.0) - 1;
                y = 1 - fabs(x);
                z = (2.0 * (j + 1) / 9.0) - 1;
                glVertex3f(x, y, z);

                x = (2.0 * i / 9.0) - 1;
                y = 1 - fabs(x);
                z = (2.0 * j / 9.0) - 1;
                glVertex3f(x, y, z);

            glEnd();
        }
    }
}

void keyboard(unsigned char key, int x, int y)
{
    switch(key)
    {
        case 27:
            exit(0);
        break;
    }
    glutPostRedisplay();
}

// Função para gerenciamento das implementações
void menuImplementacoes(int op)
{
    printf("**** Menu de Implementacoes\n");

    switch(op)
    {
        case 1:
            printf("Implementacao 1\n\n");
            implementacao = 1;
            break;
        case 2:
            printf("Implementacao 2\n\n");
            implementacao = 2;
            break;
        case 3:
            printf("Implementacao 3\n\n");
            implementacao = 3;
            break;
        case 4:
            printf("Implementacao 4\n\n");
            implementacao = 4;
            break;
    }

    glutPostRedisplay();
}

void menuPrincipal(int op)
{

}

void criaMenu()
{
    int menu, submenuImplementacoes;

    // Cria menu para seleção da cor
    submenuImplementacoes = glutCreateMenu(menuImplementacoes);

    // Adição de itens ao menu corrente
    glutAddMenuEntry("Implementação 1", 1);
    glutAddMenuEntry("Implementação 2", 2);
    glutAddMenuEntry("Implementação 3", 3);
    glutAddMenuEntry("Implementação 4", 4);

    // Cria menu principal
    menu = glutCreateMenu(menuPrincipal);
    glutAddSubMenu("Implementações", submenuImplementacoes);

    // Associa o menu corrente ao botão direito do mouse
    glutAttachMenu(GLUT_RIGHT_BUTTON);
}

// Apresentação de texto
void textoBitmap(void *font, char *s)
{
    while(*s)
    {
        glutBitmapCharacter(font, *s++);
    }

}
