#include <windows.h>
#include <GL/glut.h>
#include <cmath>
#include <cstdlib>
#include <ctime>

float wheelRotation = 0.0;
float carX = -0.3;  // Initial x-coordinate of the car
float carSpeed = 0.0005;

void initGL() {
    glClearColor(1.0f, 1.0f, 1.0f, 1.0f);
}

void circle(float radius, float xc, float yc, float r, float g, float b) {
    glBegin(GL_POLYGON);
    for (int i = 0; i < 200; i++) {
        glColor3ub(r, g, b);
        float pi = 3.1416;
        float A = (i * 2 * pi) / 200;
        float x = radius * cos(A);
        float y = radius * sin(A);
        glVertex2f(x + xc, y + yc);
    }
    glEnd();
}

void drawCar(float size, int r, int g, int b) {
    // Car body
    glBegin(GL_QUADS);
    glColor3ub(r, g, b);
    glVertex2f(carX, -0.25);
    glVertex2f(carX + size, -0.25);
    glVertex2f(carX + size, -0.25 + size * 0.3);
    glVertex2f(carX, -0.25 + size * 0.3);
    glEnd();

    // Car roof
    glBegin(GL_QUADS);
    glColor3ub(r + 30, g + 30, b + 30);
    glVertex2f(carX + size * 0.1, -0.25 + size * 0.3);
    glVertex2f(carX + size * 0.9, -0.25 + size * 0.3);
    glVertex2f(carX + size * 0.8, -0.25 + size * 0.7);
    glVertex2f(carX + size * 0.2, -0.25 + size * 0.7);
    glEnd();

    // Left window
    glBegin(GL_QUADS);
    glColor3ub(173, 216, 230);
    glVertex2f(carX + size * 0.25, -0.25 + size * 0.4);
    glVertex2f(carX + size * 0.45, -0.25 + size * 0.4);
    glVertex2f(carX + size * 0.45, -0.25 + size * 0.6);
    glVertex2f(carX + size * 0.25, -0.25 + size * 0.6);
    glEnd();

    // Right window
    glBegin(GL_QUADS);
    glColor3ub(173, 216, 230);
    glVertex2f(carX + size * 0.55, -0.25 + size * 0.4);
    glVertex2f(carX + size * 0.75, -0.25 + size * 0.4);
    glVertex2f(carX + size * 0.75, -0.25 + size * 0.6);
    glVertex2f(carX + size * 0.55, -0.25 + size * 0.6);
    glEnd();

    // Left wheel with spokes
    glPushMatrix();
    glTranslatef(carX + size * 0.2, -0.25, 0.0);
    glRotatef(-wheelRotation, 0.0, 0.0, 1.0);
    circle(size * 0.1, 0, 0, 0, 0, 0);

    // Draw spokes
    glColor3ub(255, 255, 255); // White color for spokes
    for (int i = 0; i < 8; i++) {
        float angle = i * 45.0;
        float x1 = size * 0.05 * cos(angle * 3.14159265359 / 180);
        float y1 = size * 0.05 * sin(angle * 3.14159265359 / 180);
        float x2 = size * 0.1 * cos(angle * 3.14159265359 / 180);
        float y2 = size * 0.1 * sin(angle * 3.14159265359 / 180);
        glBegin(GL_LINES);
        glVertex2f(0, 0);
        glVertex2f(x1, y1);
        glEnd();
        glBegin(GL_LINES);
        glVertex2f(x2, y2);
        glVertex2f(x1, y1);
        glEnd();
    }
    glPopMatrix();

    // Right wheel with spokes
    glPushMatrix();
    glTranslatef(carX + size * 0.8, -0.25, 0.0);
    glRotatef(-wheelRotation, 0.0, 0.0, 1.0);
    circle(size * 0.1, 0, 0, 0, 0, 0);

    // Draw spokes
    glColor3ub(255, 255, 255); // White color for spokes
    for (int i = 0; i < 8; i++) {
        float angle = i * 45.0;
        float x1 = size * 0.05 * cos(angle * 3.14159265359 / 180);
        float y1 = size * 0.05 * sin(angle * 3.14159265359 / 180);
        float x2 = size * 0.1 * cos(angle * 3.14159265359 / 180);
        float y2 = size * 0.1 * sin(angle * 3.14159265359 / 180);
        glBegin(GL_LINES);
        glVertex2f(0, 0);
        glVertex2f(x1, y1);
        glEnd();
        glBegin(GL_LINES);
        glVertex2f(x2, y2);
        glVertex2f(x1, y1);
        glEnd();
    }
    glPopMatrix();
}

void display() {
    glClear(GL_COLOR_BUFFER_BIT);

    // Update the rotation angle for wheel animation
    wheelRotation += 1.0;
    if (wheelRotation > 360.0) {
        wheelRotation -= 360.0;
    }

    // Update the x-coordinate for car animation
    carX += carSpeed;

    if (carX > 1.1) {
        carX = -1.0;  // Reset to the left side when it goes beyond the screen
    }

    drawCar(0.6, 250,10,00);

    glutPostRedisplay(); // Request a redraw to keep the animation running
    glFlush();
}

int main(int argc, char** argv) {
    glutInit(&argc, argv);
    glutInitWindowSize(900, 900);
    glutCreateWindow("Moving Car");
    glutInitWindowPosition(50, 50);
    glutDisplayFunc(display);
    initGL();
    glutIdleFunc(display); // Register idle function for continuous animation
    glutMainLoop();
    return 0;
}
