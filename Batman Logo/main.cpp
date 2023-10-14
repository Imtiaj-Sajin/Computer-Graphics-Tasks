#include <windows.h> // for MS Windows
#include <GL/glut.h> // GLUT, include glu.h and gl.h

/* Handler for window-repaint event. Call back when the window first appears and
whenever the window needs to be re-painted. */
void renderBitmapString(float x, float y, float z, void *font, char *string) {
    char *c;
    glRasterPos3f(x, y,z);
    for (c=string; *c != '\0'; c++)
    {
        glutBitmapCharacter(font, *c);
    }
}

void display() {
    glClearColor(1.0f, 1.0f, 0.0f, 0.0f); // Set background color to black and opaque
    glClear(GL_COLOR_BUFFER_BIT); // Clear the color buffer (background)


glBegin(GL_POLYGON);
glColor3f(0.0f,0.0f,0.0f);                    //0 dia start na korle thik VABE ASE NA KN?
glVertex2f(0.0f,0.0f);
glVertex2f(0.04f,0.0f);
glVertex2f(0.08f,0.02f);
glVertex2f(0.12f,0.04f);
glVertex2f(0.154f,0.08f);
glVertex2f(0.16f,0.14f);
glVertex2f(0.21f,0.17f);
glVertex2f(0.26f,0.176f);
glVertex2f(0.40f,0.14f);
glVertex2f(0.32f,0.10f);
glVertex2f(0.28f,0.04f);
glVertex2f(0.276f,0.0f);
glVertex2f(0.25f,-0.02f);
glVertex2f(0.248f,-0.06f);
glVertex2f(0.20f,-0.064f);
glVertex2f(0.16f,-0.08f);
glVertex2f(0.124f,-0.12f);
glVertex2f(0.10f,-0.20f);
glVertex2f(0.04f,-0.24f);
glVertex2f(0.0f,-0.32f);
glVertex2f(-0.04f,-0.24f);
glVertex2f(-0.10f,-0.20f);
glVertex2f(-0.124f,-0.12f);
glVertex2f(-0.16f,-0.08f);
glVertex2f(-0.20f,-0.064f);
glVertex2f(-0.248f,-0.06f);
glVertex2f(-0.25f,-0.02f);
glVertex2f(-0.276f,0.0f);
glVertex2f(-0.28f,0.04f);
glVertex2f(-0.32f,0.10f);
glVertex2f(-0.40f,0.14f);
glVertex2f(-0.26f,0.176f);
glVertex2f(-0.21f,0.17f);
glVertex2f(-0.16f,0.14f);
glVertex2f(-0.154f,0.08f);
glVertex2f(-0.12f,0.04f);                    ////BAT
glVertex2f(-0.08f,0.02f);
glVertex2f(-0.04f,0.0f);
glVertex2f(0.0f,0.0f);
glEnd();

glBegin(GL_POLYGON);
glColor3f(0.0f,0.0f,0.0f);
glVertex2f(0.04f,0.0f);
glVertex2f(0.06f,0.04f);
glVertex2f(0.04f,0.08f);
glVertex2f(0.02f,0.06f);
glVertex2f(-0.02f,0.06f);
glVertex2f(-0.04f,0.08f);
glVertex2f(-0.06f,0.04f);
glVertex2f(-0.04f,0.0f);
glEnd();

/*
glBegin(GL_POLYGON);
glColor3f(0.0f, 0.0f, 0.0f); // Black
glVertex2f(0.0f,0.09f);
glVertex2f(0.01f,0.09f);
glVertex2f(0.03f,0.12f);
glVertex2f(0.03f,0.04f);
glVertex2f(0.06f,0.03f);
glVertex2f(0.09f,0.03f);
glVertex2f(0.11f,0.04f);
glVertex2f(0.12f,0.05f);
glVertex2f(0.13f,0.07);
glVertex2f(0.11f,0.11f);
glVertex2f(0.14f,0.10f);
glVertex2f(0.17f,0.08f);
glVertex2f(0.19f,0.06f);
glVertex2f(0.20f,0.04f);
glVertex2f(0.21f,0.01f);
glVertex2f(0.21f,-0.02f);
glVertex2f(0.20f,-0.05f);
glVertex2f(0.19f,-0.07f);
glVertex2f(0.17f,-0.09f);
glVertex2f(0.14f,-0.11f);
glVertex2f(0.11f,-0.12f);
glVertex2f(0.12f,-0.11f);
glVertex2f(0.13f,-0.09f);
glVertex2f(0.13f,-0.08f);
glVertex2f(0.12f,-0.06f);
glVertex2f(0.11f,-0.05f);
glVertex2f(0.10f,-0.05f);
glVertex2f(0.09f,-0.06f);
glVertex2f(0.08f,-0.08f);
glVertex2f(0.07f,-0.06f);
glVertex2f(0.06f,-0.05f);
glVertex2f(0.05f,-0.05f);
glVertex2f(0.04f,-0.06f);
glVertex2f(0.0f,-0.12f);
glVertex2f(-0.04f,-0.06f);
glVertex2f(-0.05f,-0.05f);
glVertex2f(-0.06f,-0.05f);
glVertex2f(-0.07f,-0.06f);
glVertex2f(-0.08f,-0.08f);
glVertex2f(-0.09f,-0.06f);
glVertex2f(-0.10f,-0.05f);
glVertex2f(-0.11f,-0.05f);
glVertex2f(-0.12f,-0.06f);
glVertex2f(-0.13f,-0.08f);
glVertex2f(-0.13f,-0.09f);
glVertex2f(-0.12f,-0.11f);
glVertex2f(-0.11f,-0.12f);
glVertex2f(-0.14f,-0.11f);
glVertex2f(-0.17f,-0.09f);
glVertex2f(-0.19f,-0.07f);
glVertex2f(-0.20f,-0.05f);
glVertex2f(-0.21f,-0.02f);
glVertex2f(-0.21f,0.01f);
glVertex2f(-0.20f,0.04f);                  ///INCOMPITE
glVertex2f(-0.19f,0.06f);
glVertex2f(-0.17f,0.08f);
glVertex2f(-0.14f,0.10f);
glVertex2f(-0.11f,0.11f);
glVertex2f(-0.12f,0.10f);
glVertex2f(-0.13f,0.08f);
glVertex2f(-0.13f,0.07f);
glVertex2f(-0.12f,0.05f);
glVertex2f(-0.11f,0.04f);
glVertex2f(-0.09f,0.03f);
glVertex2f(-0.06f,0.03f);
glVertex2f(-0.03f,0.04f);
glVertex2f(-0.03f,0.12f);
glVertex2f(-0.01f,0.09f);
glVertex2f(0.0f,0.09f);

*/



   // glEnd();
     glFlush(); // Render now
}

/* Main function: GLUT runs as a console application starting at main() */
int main(int argc, char** argv) {
    glutInit(&argc, argv);
    glutInitWindowSize(640, 480); // Set the window's initial width & height
    glutInitWindowPosition(80, 50);  // Set the window's initial position according to the monitor
    glutCreateWindow("OpenGL Setup Test"); // Create a window with the given title
    glutDisplayFunc(display); // Register display callback handler for window re-paint
    glutMainLoop(); // Enter the event-processing loop
    return 0;
}
