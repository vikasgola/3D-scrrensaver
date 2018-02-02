#include <GL/glut.h>
#include<math.h>
#include<stdlib.h>
#include<iostream>

using namespace std;

float randf(float lo, float hi) {
    float random = ((float) rand()) / (float) RAND_MAX;
    float diff = hi - lo;
    float r = random * diff;
    return lo + r;
}

void DrawCircle(float cx, float cy, float r, int num_segments)
{
    glBegin(GL_POLYGON);
    for(int ii = 0; ii < num_segments; ii++)
    {
        float theta = 2.0f * 3.1415926f * float(ii) / float(num_segments);//get the current angle

        float x = r * cosf(theta);//calculate the x component
        float y = r * sinf(theta);//calculate the y component

        glVertex2f(x + cx, y + cy);//output vertex

    }
    glEnd();
}


void display(){
    // glClear(GL_COLOR_BUFFER_BIT);

    // set every time new matrix
    // glLoadIdentity();

    // set rotation to some angle with axis 
    // glRotatef(0.1,0.0,0.0,1.0);

    // make triangle with vertices
    // glBegin(GL_TRIANGLES);
    //     glColor3f(0.0,0.0,0.0);
    //     glVertex3f(1.0,0.0,0.0);
    //     glVertex3f(0.0,-1.0,0);
    //     glVertex3f(1.0,-1.0,0.0);
    // glEnd();

    glLoadIdentity();
    glColor3f(randf(0.0,1.0),randf(0.0,1.0),randf(0.0,1.0));
    DrawCircle(randf(-1.0,1.0),randf(-1.0,1.0),randf(0.0,0.05),360);

    glColor3f(randf(0.0,1.0),randf(0.0,1.0),randf(0.0,1.0));
    DrawCircle(randf(-1.0,1.0),randf(-1.0,1.0),randf(0.0,0.05),360);

    glColor3f(randf(0.0,1.0),randf(0.0,1.0),randf(0.0,1.0));
    DrawCircle(randf(-1.0,1.0),randf(-1.0,1.0),randf(0.0,0.05),360);

    glutSwapBuffers();
}

void reshape(int w, int h){
    glViewport(0,0,w,h);
}

void init(){
    glClearColor(0.0,0.0,0.0,1.0);
}

int main(int argc, char** argv)
{
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB | GLUT_DEPTH);
    glutInitWindowSize(500,500);
    glutInitWindowPosition(200,200);
    glutCreateWindow("Assignment 1");

    init();

    glutDisplayFunc(display);
    glutIdleFunc(display);
    glutReshapeFunc(reshape);
    glutMainLoop();
    return 0;
}