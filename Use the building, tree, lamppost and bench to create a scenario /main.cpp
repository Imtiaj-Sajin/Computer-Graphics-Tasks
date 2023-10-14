

/*



* GL02Primitive.cpp: Vertex, Primitive and Color



* Draw Simple 2D colored Shapes: quad, triangle and polygon.



*/



#include <windows.h> // for MS Windows



#include <GL/glut.h> // GLUT, include glu.h and gl.h
#include <cmath>
#include <math.h>
#include <cstdlib>
#include <ctime>

/* Initialize OpenGL Graphics */



void initGL() {



// Set "clearing" or background color



glClearColor(0.0f, 0.0f, 0.0f, 1.0f); // Black and opaque



}



/* Handler for window-repaint event. Call back when the window first appears and



whenever the window needs to be re-painted. */

void circle(float radius, float xc, float yc, float r, float g, float b)
{
    glBegin(GL_POLYGON);// Draw a Red 1x1 Square centered at origin
	for(int i=0;i<200;i++)
        {
            glColor3ub(r,g,b);
            float pi=3.1416;
            float A=(i*2*pi)/200;
            float r=radius;
            float x = r * cos(A);
            float y = r * sin(A);
            glVertex2f(x+xc,y+yc);
        }
	glEnd();
}

void roadDev(float x,float y){
glBegin(GL_LINES); // Each set of 4 vertices form a quad
glColor3ub(45, 53, 66); // Yellow
glVertex2f(x, -.55);
glVertex2f(y, -.55);
glEnd();

}
void sky(){
    glBegin(GL_POLYGON);
    glColor3ub(18,63,119);

    glVertex2f(-1, -.5);
    glVertex2f(1, -.5);
    glVertex2f(1, 1);
    glVertex2f(-1, 1);

glEnd();



}

void tree(float x) {
    glBegin(GL_POLYGON);
    glColor3ub(38,4,10);

    glVertex2f(x + 0.545, -0.5);
    glVertex2f(x + 0.615, -0.5);
    glVertex2f(x + 0.615, -0.245);
    glVertex2f(x + 0.545, -0.245);
    glEnd();

    circle(0.125, x + 0.58, -0.245, 66, 105, 47);
    circle(0.1, x + 0.58 + 0.06, -0.245 - 0.03, 66, 105, 47);
    circle(0.1, x + 0.58 - 0.06, -0.245 - 0.03, 66, 105, 47);
    circle(0.1, x + 0.58, -0.245 - 0.03, 66, 105, 47);
}
void bench (){
        glColor3ub(1,1,1);

    glBegin(GL_POLYGON);

    glVertex2f(-.15, -.5);
    glVertex2f(-.15, -.47);
    glVertex2f(-.18, -.47);
glEnd();

glBegin(GL_POLYGON);
        glColor3ub(1,1,1);

    glVertex2f(-.27, -.47);
    glVertex2f(-.3, -.47);
    glVertex2f(-.3, -.5);
glEnd();
glBegin(GL_POLYGON);
        glColor3ub(39,39,39);

    glVertex2f(-.173, -.475);
    glVertex2f(-.173, -.445);
    glVertex2f(-.277, -.445);
    glVertex2f(-.277, -.475);
glEnd();


}

void lampost(){
glBegin(GL_POLYGON);
        glColor3ub(1,1,1);

    glVertex2f(-.425, -.25);
    glVertex2f(-.425, -.275);
    glVertex2f(-.25, -.275);
    glVertex2f(-.25, -.25);
glEnd();

glBegin(GL_POLYGON);

glVertex2f(-.35, -.275);
    glVertex2f(-.35, -.5);
    glVertex2f(-.325, -.5);
    glVertex2f(-.325, -.275);
glEnd();
    circle(.025,-.425,-.275,245,219,55);
    circle(.025,-.25,-.275,245,219,55);


}

void drawStars(int numStars) {
    srand(time(0));

    for (int i = 0; i < numStars; ++i) {
        float x = (rand() % 200 - 100) / 100.0;
        float y = (rand() % 150) / 100.0;
        float radius = (rand() % 3 + 1) / 200.0; // Reduced size
        circle(radius, x, y, 255, 255, 255);
    }
}

void drawWind() {

            glBegin(GL_LINES);
            glColor3ub(251,239,203);
            glVertex2f(-0.249f, 0.421f);
            glVertex2f(-0.404f, 0.583f);
            glVertex2f(-0.464f, 0.476f);
            glVertex2f(-0.460f, 0.492f);
            glVertex2f(-0.582f, 0.215f);
            glVertex2f(-0.380f, -0.081f);
            glVertex2f(-0.311f, 0.144f);
            glVertex2f(-0.198f, -0.049f);
            glVertex2f(-0.089f, 0.152f);
            glVertex2f(0.029f, -0.136f);
            glVertex2f(0.209f, 0.219f);
            glVertex2f(0.087f, 0.591f);
            glVertex2f(-0.147f, 0.453f);
            glVertex2f(-0.191f, 0.543f);
            glEnd();
}
void ground(){
glBegin(GL_POLYGON);
    glColor3ub(72,98,48);

    glVertex2f(-1, -1);
    glVertex2f(1, -1);
    glVertex2f(1, -.6);
    glVertex2f(-1, -.6);

glEnd();
}

void display() {

glClearColor(1.0f, 1.0f, 1.0f, 1.0f); // Set background color to black and opaque

glClear(GL_COLOR_BUFFER_BIT); // Clear the color buffer with current clearing color

sky();
drawStars(90);
tree(0);
tree(.4);
tree(-1.5);
bench();
lampost();
ground();
glBegin(GL_POLYGON); // These vertices form a closed polygon

glColor3ub(226,82,82); // Yellow

glVertex2f(-.1, -.0);
glVertex2f(-.1, -.5);
glVertex2f(.3, -.5);
glVertex2f(.3, -.0);

glEnd();

////////

glBegin(GL_POLYGON); // These vertices form a closed polygon



glColor3ub(15, 105, 134); // Yellow



glVertex2f(-.1, -.0);

glVertex2f(-.1, -.1);

glVertex2f(.3, -.1);



glEnd();

////////

////////

glBegin(GL_POLYGON); // These vertices form a closed polygon



glColor3ub(0,155,200); // Yellow



glVertex2f(-.1, -.1);

glVertex2f(-.1, -.2);

glVertex2f(.3, -.1);



glEnd();

////////////////

glBegin(GL_POLYGON); // These vertices form a closed polygon



glColor3ub(15, 105, 134); // Yellow



glVertex2f(-.1, -.2);

glVertex2f(-.1, -.3);

glVertex2f(.3, -.3);



glEnd();

////////

////////

glBegin(GL_POLYGON); // These vertices form a closed polygon



glColor3ub(0,155,200); // Yellow



glVertex2f(-.1, -.3);

glVertex2f(-.1, -.4);

glVertex2f(.3, -.3);



glEnd();

////////

glBegin(GL_POLYGON); // These vertices form a closed polygon



glColor3ub(45, 53, 66); // Yellow



glVertex2f(-.0, -.4);

glVertex2f(-.0, -.5);

glVertex2f(.2, -.5);

glVertex2f(.2, -.4);



glEnd();

////////



glLineWidth(1.5);

glBegin(GL_LINES); // Each set of 4 vertices form a quad

glColor3ub(45, 53, 66); // Yellow



glVertex2f(-.1, -.1);

glVertex2f(.3, -.1);



glEnd();



glBegin(GL_LINES); // Each set of 4 vertices form a quad

glColor3ub(45, 53, 66); // Yellow



glVertex2f(-.1, -.2);

glVertex2f(.3, -.2);

glEnd();



glBegin(GL_LINES); // Each set of 4 vertices form a quad

glColor3ub(45, 53, 66); // Yellow



glVertex2f(-.1, -.3);

glVertex2f(.3, -.3);



glEnd();



glBegin(GL_LINES); // Each set of 4 vertices form a quad

glColor3ub(45, 53, 66); // Yellow



glVertex2f(-.1, -.4);

glVertex2f(.3, -.4);

glEnd();
////

glBegin(GL_LINES); // Each set of 4 vertices form a quad

glColor3ub(45, 53, 66); // Yellow

glVertex2f(-1, -.5);
glVertex2f(1, -.5);

glEnd();

glBegin(GL_LINES); // Each set of 4 vertices form a quad
glColor3ub(45, 53, 66); // Yellow

glVertex2f(-1, -.6);
glVertex2f(1, -.6);

glEnd();

roadDev(-.6,-.9);
roadDev(-.3,0);
roadDev(.3,.6);
roadDev(1,.9);

////

glFlush(); // Render now



}



/* Main function: GLUT runs as a console application starting at main() */



int main(int argc, char** argv) {



glutInit(&argc, argv); // Initialize GLUT

glutInitWindowSize(900, 900); // Set the window's initial width & height



glutCreateWindow("Vertex, Primitive & Color"); // Create window with the given title





glutInitWindowPosition(50, 50); // Position the window's initial top-left corner



glutDisplayFunc(display); // Register callback handler for window re-paint event



initGL(); // Our own OpenGL initialization



glutMainLoop(); // Enter the event-processing loop



return 0;



}

