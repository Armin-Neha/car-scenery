#include <GL/gl.h>
#include<stdio.h>
#include<math.h>
#include <GL/glut.h>
#include <stdlib.h>
#include <time.h>

// --- Animation state ---
GLfloat carOffset = 0.0f;      // horizontal offset applied to the car & wheels
const GLfloat CAR_SPEED = 2.0f;  // pixels moved per timer tick
const GLfloat CAR_MIN_X = -120.0f; // offscreen left
const GLfloat CAR_MAX_X = 260.0f;  // offscreen right (500-wide viewport)

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
    srand(time(NULL));
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

// Car is now a self-contained function that offsets every vertex by carOffset,
// so animating it is just a matter of changing one float each frame.
void car(GLfloat dx)
{
    // car body
    glColor3ub(79,2,5);
    glBegin(GL_POLYGON);
    glVertex2d(260 + dx, 130);
    glVertex2d(315 + dx, 130);
    glVertex2d(305 + dx, 160);
    glVertex2d(270 + dx, 160);
    glEnd();

    glColor3ub(79,2,5);
    glBegin(GL_POLYGON);
    glVertex2d(250 + dx, 100);
    glVertex2d(330 + dx, 100);
    glVertex2d(325 + dx, 130);
    glVertex2d(250 + dx, 130);
    glEnd();

    // Design stripes
    glColor3ub(164,110,81);
    glBegin(GL_POLYGON);
    glVertex2d(250 + dx, 110);
    glVertex2d(328.5 + dx, 110);
    glVertex2d(327 + dx, 115);
    glVertex2d(250 + dx, 115);
    glEnd();

    glColor3ub(233,226,199);
    glBegin(GL_POLYGON);
    glVertex2d(250 + dx, 115);
    glVertex2d(327.5 + dx, 115);
    glVertex2d(326.5 + dx, 120);
    glVertex2d(250 + dx, 120);
    glEnd();

    glColor3ub(110,100,86);
    glBegin(GL_POLYGON);
    glVertex2d(250 + dx, 120);
    glVertex2d(326.8 + dx, 120);
    glVertex2d(325.8 + dx, 125);
    glVertex2d(250 + dx, 125);
    glEnd();

    // car windows
    glColor3ub(220, 220, 220);
    glBegin(GL_POLYGON);
    glVertex2d(265 + dx, 130);
    glVertex2d(285 + dx, 130);
    glVertex2d(285 + dx, 150);
    glVertex2d(270 + dx, 150);
    glEnd();

    glColor3ub(220, 220, 220);
    glBegin(GL_POLYGON);
    glVertex2d(290 + dx, 130);
    glVertex2d(310 + dx, 130);
    glVertex2d(305 + dx, 150);
    glVertex2d(290 + dx, 150);
    glEnd();

    // car wheels
    glColor3ub(0, 0, 0);
    circle(10, 14, 275 + dx, 100);
    circle(10, 14, 305 + dx, 100);

    glColor3ub(243,240,231);
    circle(6, 10, 275 + dx, 100);
    circle(6, 10, 305 + dx, 100);
}

void display(void)
{
    glClear(GL_COLOR_BUFFER_BIT);

    // Starfield
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

    // Ground
    glColor3ub(34,59,5);
    glBegin(GL_POLYGON);
    glVertex2d(0, 0);
    glVertex2d(500, 0);
    glVertex2d(500, 150);
    glVertex2d(0, 150);
    glEnd();

    // Road
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

    hills();

    // Moon
    glColor3ub(169,169,169);
    moon(25, 35, 175, 415);

    // Animated car
    car(carOffset);

    glutSwapBuffers();  // double-buffered: swap instead of glFlush()
}

// Called on a timer to advance the animation and request a redraw.
void update(int value)
{
    carOffset += CAR_SPEED;
    if (carOffset > CAR_MAX_X)
    {
        carOffset = CAR_MIN_X;  // wrap the car back to the left, offscreen
    }

    glutPostRedisplay();
    glutTimerFunc(16, update, 0);  // ~60 FPS (1000ms / 60 ≈ 16ms)
}

int main(int argc, char** argv)
{
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB);  // double buffering avoids flicker
    glutInitWindowSize(1000, 600);
    glutInitWindowPosition(300, 50);
    glutCreateWindow("A Car Scenario - Animated");
    init();
    glutDisplayFunc(display);
    glutTimerFunc(0, update, 0);  // kick off the animation loop
    glutMainLoop();
    return 0;
}
