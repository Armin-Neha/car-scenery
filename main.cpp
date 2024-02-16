#include <GL/gl.h>
#include<stdio.h>
#include<math.h>
#include <GL/glut.h>
#include <stdlib.h>
#include <time.h>

void circle(GLfloat rx, GLfloat ry, GLfloat cx, GLfloat cy)
{
    glBegin(GL_POLYGON);
    glVertex2f(cx, cy);
    for (int i = 0; i <= 360; i++)
    {
        float angle = i * 3.1416 / 180;
        float x = rx * cos(angle);
        float y = ry * sin(angle);
        glVertex2f((x + cx), (y + cy));
    }
    glEnd();
}

void moon(GLfloat rx, GLfloat ry, GLfloat cx, GLfloat cy)
{
    glBegin(GL_POLYGON);
    glVertex2f(cx, cy);
    for (int i = 0; i <= 360; i++)
    {
        float angle = i * 3.1416 / 180;
        float x = rx * cos(angle);
        float y = ry * sin(angle);
        glVertex2f((x + cx), (y + cy));
    }
    glEnd();
}

void init(void)
{
    glClearColor(0.0, 0.0, 0.2, 0.0);
    glMatrixMode(GL_PROJECTION);
    gluOrtho2D(0.0, 500, 0.0, 500);
}

void hills()
{
    // Hills 1
    glColor3ub(184, 134, 11);
    glBegin(GL_POLYGON);
    glVertex2d(-40, 300);
    glVertex2d(200, 300);
    glVertex2d(100, 450);
    glEnd();

    // Hills 2
    glColor3ub(218, 165, 32);
    glBegin(GL_POLYGON);
    glVertex2d(150, 300);
    glVertex2d(350, 300);
    glVertex2d(250, 450);
    glEnd();

    // Hills 3
    glColor3ub(184, 134, 11);
    glBegin(GL_POLYGON);
    glVertex2d(300, 300);
    glVertex2d(520, 300);
    glVertex2d(400, 450);
    glEnd();

    // Hills 4
    glColor3ub(218, 165, 32);
    glBegin(GL_POLYGON);
    glVertex2d(450, 300);
    glVertex2d(650, 300);
    glVertex2d(550, 450);
    glEnd();

}

void river()
 {
    glColor3ub(159,207,251);
    glBegin(GL_POLYGON);
    glVertex2d(0, 299);
    glVertex2d(500, 299);
    glVertex2d(500, 0);
    glVertex2d(0, 0);
    glEnd();
}

void boat()
{
    // Body of the boat
    glColor3ub(73,47,47);
    glBegin(GL_POLYGON);
    glVertex2d(70, 140);
    glVertex2d(170, 140);
    glVertex2d(190, 180);
    glVertex2d(50, 180);
    glEnd();

    // Mast of the boat
    glColor3ub(86,85,73);
    glBegin(GL_POLYGON);
    glVertex2d(130, 180);
    glVertex2d(130, 260);
    glVertex2d(135, 260);
    glVertex2d(135, 180);
    glEnd();

    // Sail 1
    glColor3ub(214,214,195);
    glBegin(GL_TRIANGLES);
    glVertex2d(135, 250);
    glVertex2d(170, 280);
    glVertex2d(135, 280);
    glEnd();

    // Sail 2
    glColor3ub(171,182,160);
    glBegin(GL_POLYGON);
    glVertex2d(135, 220);
    glVertex2d(170, 250);
    glVertex2d(135, 250);
    glEnd();
}

void display(void)
{
    glClear(GL_COLOR_BUFFER_BIT);

    srand(time(NULL));
    glColor3ub(255, 255, 255);
    glPointSize(2.0);
    glBegin(GL_POINTS);
    for (int i = 0; i < 70; i++)
    {
        int x = rand() % 500;
        int y = rand() % 150 + 350;
        glVertex2d(x, y);
    }
    glEnd();

    river();

    boat();

    //Ground Color
    glColor3ub(34,59,5);
    glBegin(GL_POLYGON);
    glVertex2d(0, 0);
    glVertex2d(500, 0);
    glVertex2d(500, 150);
    glVertex2d(0, 150);
    glEnd();

    // road
    glColor3ub(255, 255, 255);
    glBegin(GL_POLYGON);
    glVertex2d(0, 55);
    glVertex2d(500, 55);
    glVertex2d(500, 115);
    glVertex2d(0, 115);
    glEnd();

    glColor3ub(96,98,107);
    glBegin(GL_POLYGON);
    glVertex2d(0, 60);
    glVertex2d(500, 60);
    glVertex2d(500, 110);
    glVertex2d(0, 110);
    glEnd();

    // hills
    hills();

    //moon design
    glColor3ub(169,169,169);
    moon(25, 35, 175, 415);

    // car body
    glColor3ub(79,2,5);
    glBegin(GL_POLYGON);
    glVertex2d(260, 130);
    glVertex2d(315, 130);
    glVertex2d(305, 160);
    glVertex2d(270, 160);
    glEnd();

    glColor3ub(79,2,5);
    glBegin(GL_POLYGON);
    glVertex2d(250, 100);
    glVertex2d(330, 100);
    glVertex2d(325, 130);
    glVertex2d(250, 130);
    glEnd();

    // Design
    glColor3ub(164,110,81);
    glBegin(GL_POLYGON);
    glVertex2d(250, 110);
    glVertex2d(328.5, 110);
    glVertex2d(327, 115);
    glVertex2d(250, 115);
    glEnd();

    glColor3ub(233,226,199);
    glBegin(GL_POLYGON);
    glVertex2d(250, 115);
    glVertex2d(327.5, 115);
    glVertex2d(326.5, 120);
    glVertex2d(250, 120);
    glEnd();

    glColor3ub(110,100,86);
    glBegin(GL_POLYGON);
    glVertex2d(250, 120);
    glVertex2d(326.8, 120);
    glVertex2d(325.8, 125);
    glVertex2d(250, 125);
    glEnd();

    // car window
    glColor3ub(220, 220, 220);
    glBegin(GL_POLYGON);
    glVertex2d(265, 130);
    glVertex2d(285, 130);
    glVertex2d(285, 150);
    glVertex2d(270, 150);
    glEnd();

    // car window
    glColor3ub(220, 220, 220);
    glBegin(GL_POLYGON);
    glVertex2d(290, 130);
    glVertex2d(310, 130);
    glVertex2d(305, 150);
    glVertex2d(290, 150);
    glEnd();

    // car wheels
    glColor3ub(0, 0, 0);
    circle(10, 14, 275, 100);
    circle(10, 14, 305, 100);

    glColor3ub(243,240,231);
    circle(6, 10, 275, 100);
    circle(6, 10, 305, 100);

    glFlush();
}


int main(int argc, char** argv)
{
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
    glutInitWindowSize(1000, 600);
    glutInitWindowPosition(300, 50);
    glutCreateWindow("A Car Scenario");
    init();
    glutDisplayFunc(display);
    glutMainLoop();
    return 0;
}
