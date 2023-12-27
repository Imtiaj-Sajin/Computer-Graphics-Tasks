#include <windows.h>
#include <GL/glut.h>
#include<cmath>

void drawCircle(float x, float y, float radius, float red, float green, float blue) {
    int numSegments = 100;  // Adjust the number of segments for smoother circle

    glColor3f(red, green, blue);
    glBegin(GL_TRIANGLE_FAN);
    glVertex2f(x, y);  // Center of the circle

    for (int i = 0; i <= numSegments; i++) {
        float theta = 2.0f * 3.1415926f * float(i) / float(numSegments);

        float dx = radius * cosf(theta);
        float dy = radius * sinf(theta);

        glVertex2f(x + dx, y + dy);
    }

    glEnd();
}
void drawStars(int numStars) {
    glColor3f(1.0, 1.0, 1.0); // Set star color to white

    glBegin(GL_POINTS);

    for (int i = 0; i < numStars; ++i) {
        float x = (rand() % 3200 - 1600) / 100.0; // Random x-coordinate in the visible window
        float y = (rand() % 1800 - 900) / 100.0;  // Random y-coordinate in the visible window
        float size = (rand() % 10 + 1) / 100.0;    // Random size between 0.01 and 0.1

        glPointSize(size);
        glVertex2f(x, y);
    }

    glEnd();
}
void drawGradientCircle(float x, float y, float radius,
                         float startRed, float startGreen, float startBlue,
                         float endRed, float endGreen, float endBlue) {
    int numSegments = 100;

    glBegin(GL_TRIANGLE_FAN);
    for (int i = 0; i <= numSegments; i++) {
        float theta = 2.0f * 3.1415926f * float(i) / float(numSegments);

        float dx = radius * cosf(theta);
        float dy = radius * sinf(theta);

        // Calculate the color based on the gradient
        float t = float(i) / float(numSegments);
        float currentRed = startRed + t * (endRed - startRed);
        float currentGreen = startGreen + t * (endGreen - startGreen);
        float currentBlue = startBlue + t * (endBlue - startBlue);

        glColor3f(currentRed, currentGreen, currentBlue);
        glVertex2f(x + dx, y + dy);
    }
    glEnd();
}

void backgroundLanding(){
    glClearColor(1.0f, 1.0f, 1.0f, 1.0f);

    glBegin(GL_POLYGON);

    glColor3ub(231,209,173); // Light Blue
    glVertex2d(-16, 9.0);

    glColor3ub(246,249,241);// Light Blue
    glVertex2d(-16.0, -0.0);

    glColor3ub(37,24,19);// Light Blue
    glVertex2d(-16.0, -9.0);


    glColor3ub(14,5,14); // Light PINK
    glVertex2d(16.0, -9.0);

    glColor3ub(28,28,49);  // Light PINK
    glVertex2d(16.0, 0.0);

     glColor3ub(11,0,0);  // Light PINK
    glVertex2d(16.0, 9.0);
    glEnd();



}
void drawEarth() {
    glBegin(GL_POLYGON);





    glColor3ub(7,110,96);
    glVertex2d(16.0089037269473, 3.35); // z

    glColor3ub(41,44,56);
    glVertex2d(15.5122233009138, 3.4237139438823); // W

    glColor3ub(168, 215, 185);
    glVertex2d(14.4285378938879, 3.5341532210315); // V

    glColor3ub(58,72,78);
    glVertex2d(13.0273395650583, 3.6652998626461); // U

    glColor3ub(68,86,91);
    glVertex2d(10.9850087657944, 3.765662970606); // T
    glVertex2d(9.9827045618432, 3.7559318618298); // S

    glColor3ub(89,124,125);
    glVertex2d(8.114331676808, 3.7464696442774);  // R
    glVertex2d(5.9929499635908, 3.7464696442774); // Q
    glVertex2d(2.5, 3.6);                           // P

    glColor3ub(198,223,213);
    glVertex2d(-0.0171433212294, 3.2746748117356); // O
    glVertex2d(-3.0069964832908, 2.8002370345223); // N
    glVertex2d(-5.9550766738109, 2.1530044718343); // M
    glVertex2d(-8.8906669384693, 1.4094248797308); // K

    glColor3ub(236,243,235);
    glVertex2d(-10.1686943623971, 1.0376350836791); // J
    glVertex2d(-13.029207707811, 0.0912020031964); // G

    glColor3ub(216,227,211);
    glVertex2d(-15, -0.6);                          // D

    glColor3ub(246,249,241);
    glVertex2d(-16.0089037269473, -1.0929610779818); // C

    glColor3ub(93,91,79);
    glVertex2d(-16,-9); //A

     glColor3ub(81,76,65);
    glVertex2d(-11,-9);

    glColor3ub(60,50,50);
    glVertex2d(-6,-9);

    glColor3ub(40,40,40);
    glVertex2d(0,-9);

    glColor3ub(30,30,30);
    glVertex2d(6,-9);

    glColor3ub(12,12,12);
    glVertex2d(10,-9);

    glColor3ub(1,1,1);
    glVertex2d(14,-9);

    glColor3ub(0,0,0);
    glVertex2d(16,-9);
    glEnd();
}

void display() {
    glClearColor(1.0f, 1.0f, 1.0f, 1.0f);
    glClear(GL_COLOR_BUFFER_BIT);

    backgroundLanding();
    drawStars(500);
    //drawEarth();

    glFlush();
}

int main(int argc, char** argv) {
    glutInit(&argc, argv);
    glutInitWindowSize(1920, 1080);
    glutCreateWindow("Vertex, Primitive & Color");
    gluOrtho2D(-16.0, 16, -9, 9);
    glutInitWindowPosition(50, 50);
    glutDisplayFunc(display);
    glutMainLoop();
    return 0;
}
