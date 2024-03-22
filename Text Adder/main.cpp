#include <GL/glut.h>
#include <string>
#include "textAdder.h"
void display() {
    glClear(GL_COLOR_BUFFER_BIT);

    staticText("sssstasdtast", 300, 340, 0.2, 3, 0.3, 0.3,0.3);
    morphedText("saaasdfasdjin", 600, 540, 0.2, 2, 0.3, 0.3,0.3);
    glColor3f(1.0f, 0.0f, 1.0f);
    typedText(0,300,"saajin sajijnsaajin sajijnsaajin sajijnsaajin sajijnsaajin sajijnsaajin sajijnsaajin sajijnsaajin sajijn");
    glFlush();
}



void init() {
    glClearColor(1.0, 1.0, 1.0, 1.0);
    gluOrtho2D(0, 1920, 0, 1080);
}

int main(int argc, char** argv) {
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
    glutInitWindowSize(1920, 1080);
    glutCreateWindow("Text Morphing Animation");
    init();
    glutDisplayFunc(display);
    glutTimerFunc(0, mT_update, 0);
    glutTimerFunc(_tDelay,_keyboard_timer,0);
    glutMainLoop();
    return 0;
}
