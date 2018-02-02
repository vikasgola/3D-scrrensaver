#include <GL/glut.h>
#include<math.h>
#include<stdlib.h>
#include<iostream>

using namespace std;

float rotation_angle=0.003;
float vx=0.001;
float vy=0.001;
float cx=-0.85;
float cy=0.0;

// random float generator
float randf(float lo, float hi) {
    float random = ((float) rand()) / (float) RAND_MAX;
    float diff = hi - lo;
    float r = random * diff;
    return lo + r;
}


// circle function
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
    glClear(GL_COLOR_BUFFER_BIT);

    // set every time new matrix
    // glLoadIdentity();

    // set rotation to some angle with axis 
    // glRotatef(rotation_angle,0.0,0.0,1.0);
    // rotation_angle+=0.003;

    // make triangle with vertices
    // glBegin(GL_TRIANGLES);
        // glColor3f(1.0,1.0,0.0);
    //     glVertex3f(1.0,0.0,0.0);
    //     glVertex3f(0.0,-1.0,0);
    //     glVertex3f(1.0,-1.0,0.0);
    // glEnd();

    glLoadIdentity();
    // glColor3f(randf(0.0,1.0),randf(0.0,1.0),randf(0.0,1.0));
    // if(translate_by<1.0){
    //     glTranslatef(translate_by,0.0,0.0);
    //     translate_by+=0.001;
    // }else if(translate_by>=1.0-0.15){
    //     glTranslatef(translate_by,0.0,0.0);
    //     translate_by-=0.001;
    // }

    if(cx<0.85 && vx>0.0){
        vx=0.001;
    }else if(cx>-0.85){
        vx=-0.001;
    }else{
        vx=-vx;
    }

    cx+=vx;

    DrawCircle(cx,cy,0.15,360);

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