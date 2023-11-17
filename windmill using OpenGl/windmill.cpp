#include <windows.h>
#include <GL/glut.h>
#include <cmath>
#include <cstdlib>
#include <ctime>

float bladeRotation = 0.0; // Initial rotation angle for the blades
float rotationSpeed = 0.05; // Adjust the rotation speed

void initGL() {
    glClearColor(1.0f, 1.0f, 1.0f, 1.0f); // Set background color to white
}

void blade(float length) {
    glBegin(GL_TRIANGLES);
    glColor3ub(100, 149, 237); // Cornflower Blue color
    glVertex2f(0, 0);
    glVertex2f(-length / 10, length);
    glVertex2f(length / 10, length);
    glEnd();
}

void drawWindmill() {
    // Base
    glBegin(GL_QUADS);
    glColor3ub(139, 69, 19); // Saddle Brown color
    glVertex2f(-0.05, -0.6);
    glVertex2f(0.05, -0.6);
    glVertex2f(0.05, -1.0);
    glVertex2f(-0.05, -1.0);
    glEnd();

    // Pole
    glBegin(GL_QUADS);
    glColor3ub(139, 69, 19); // Saddle Brown color
    glVertex2f(-0.02, -0.6);
    glVertex2f(0.02, -0.6);
    glVertex2f(0.02, 0.3);
    glVertex2f(-0.02, 0.3);
    glEnd();

    // Blades
    glPushMatrix();
    glTranslatef(0.0, 0.3, 0.0);
    glRotatef(bladeRotation, 0.0, 0.0, 1.0);

    blade(0.4);
    glRotatef(90.0, 0.0, 0.0, 1.0);
    blade(0.4);
    glRotatef(90.0, 0.0, 0.0, 1.0);
    blade(0.4);
    glRotatef(90.0, 0.0, 0.0, 1.0);
    blade(0.4);

    glPopMatrix();
}

void drawBird(float x, float y) {
    glBegin(GL_TRIANGLES);
    glColor3ub(0, 0, 0); // Black color for birds
    glVertex2f(x, y);
    glVertex2f(x - 0.02, y + 0.02);
    glVertex2f(x + 0.02, y + 0.02);
    glEnd();
}

void drawBirds() {
    srand(time(0)); // Seed for random positions

    for (int i = 0; i < 3; i++) {
        float x = static_cast<float>(rand()) / static_cast<float>(RAND_MAX) * 2.0 - 1.0;
        float y = static_cast<float>(rand()) / static_cast<float>(RAND_MAX) * 0.2 + 0.2;

        drawBird(x, y);
    }
}

void display() {
    glClear(GL_COLOR_BUFFER_BIT);

    // Update the rotation angle for blade animation
    bladeRotation += rotationSpeed;
    if (bladeRotation > 360.0) {
        bladeRotation -= 360.0;
    }

    drawBirds(); // Draw birds before windmill to appear behind it
    drawWindmill();

    glutPostRedisplay(); // Request a redraw to keep the animation running
    glFlush();
}

int main(int argc, char** argv) {
    glutInit(&argc, argv);
    glutInitWindowSize(800, 800);
    glutCreateWindow("Windmill with Birds");
    glutInitWindowPosition(50, 50);
    glutDisplayFunc(display);
    initGL();
    glutIdleFunc(display); // Register idle function for continuous animation
    glutMainLoop();
    return 0;
}
