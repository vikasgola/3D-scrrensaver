
#define GLEW_STATIC

#include<pthread.h>
#include<GL/glew.h>
#include<GL/glut.h>
#include<math.h>
#include<stdlib.h>
#include "sphere.h"
#include<iostream>

#define NUM_THREADS 5

using namespace std;


// random float generator
float randf(float lo, float hi) {
    float random = ((float) rand()) / (float) RAND_MAX;
    float diff = hi - lo;
    float r = random * diff;
    return lo + r;
}

// global variables
float rotation_angle=0.003;
float vx=0.001;
float vy=0.001;
float cx=randf(-0.85,0.85);
float cy=0.0;
GLuint vboid;
GLuint window=0;
SolidSphere sphere(0.1, 24, 360);
GLfloat vertices[]={
        // vertices
        0.0,0.0,-2.0,
        -1.0,-1.0,0.0,
        1.0,-1.0,0.0,
        0.0,0.0,-2.0,
        1.0,1.0,0.0,
        -1.0,1.0,0.0,

        // colors
        1.0,0.0,0.0,
        0.0,1.0,0.0,
        0.0,0.0,1.0,
        1.0,0.0,0.0,
        0.0,1.0,0.0,
        0.0,0.0,1.0
};


// circle function
void DrawCircle(float cx, float cy, float r, int num_segments)
{
    glBegin(GL_POLYGON);
    for(int ii = 0; ii < num_segments; ii++)
    {
        float theta = 2.0f * 3.1415926f * float(ii) / float(num_segments);//get the current angle

        float x = r * cosf(theta);//calculate the x component
        float y = r * sinf(theta);//calculate the y component

        glVertex3f(x + cx, y + cy,-1.5);//output vertex

    }
    glEnd();
}

// function for multi-threading 
void *createBalls(void *threadid){


}

// shader
void createShader(void){

}


void display(){
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

    // pthread_t threads[NUM_THREADS];
    // int rc;
    // int i;
   
    // for( i = 0; i < NUM_THREADS; i++ ) {
    //   cout << "main() : creating thread, " << i << endl;
    //   rc = pthread_create(&threads[i], NULL, createBalls, (void *)i);
      
    //   if (rc) {
    //      cout << "Error:unable to create thread," << rc << endl;
    //      exit(-1);
    //   }
    // }
    // pthread_exit(NULL);

    // set every time new matrix
    glLoadIdentity();


    // enabling data entry form arrays
    // glEnableClientState(GL_VERTEX_ARRAY);

    //enablong data entry of colors from array
    // glEnableClientState(GL_COLOR_ARRAY);

    // glBindBuffer(GL_ARRAY_BUFFER,vboid);

    // glColor3f(0.0,0.0,0.0);

    // take input from array with some details
    // glVertexPointer(3,GL_FLOAT,3*sizeof(GL_FLOAT),0);
    // glColorPointer(3,GL_FLOAT,3*sizeof(GL_FLOAT),(GLvoid *)(18*sizeof(GLfloat)));
    // glDrawArrays(GL_TRIANGLES,0,6);

    // glBindBuffer(GL_ARRAY_BUFFER,vboid);

    // disable client state
    // glDisableClientState(GL_COLOR_ARRAY);
    // glDisableClientState(GL_VERTEX_ARRAY);

    // set rotation to some angle with axis 
    // glRotatef(rotation_angle,1.0,0.0,0.0);
    // rotation_angle+=0.01;
    // rotation_angle+=0.003;

    // make triangle with vertices
    // glBegin(GL_TRIANGLES);
        // glColor3f(1.0,1.0,0.0);
    //     glVertex3f(1.0,0.0,0.0);
    //     glVertex3f(0.0,-1.0,0);
    //     glVertex3f(1.0,-1.0,0.0);
    // glEnd();

    // glLoadIdentity();
    // glColor3f(randf(0.0,1.0),randf(0.0,1.0),randf(0.0,1.0));
    // DrawCircle(randf(-1.0,1.0),randf(-1.0,1.0),randf(0.01,0.1),360);
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
    glColor3f(0.1,0.1,0.1);

    sphere.draw(cx,cy,-1.2);

    glColor3f(1.0,1.0,1.0);
    // glEnable(GL_POLYGON_SMOOTH);

    // DrawCircle(cx,cy,0.1,360);

    glutSwapBuffers();
    glFlush();
}

void reshape(int w, int h){

    glViewport(0,0,w,h);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();

    gluPerspective(60,(float)w/h,1.0,10.0);
    glMatrixMode(GL_MODELVIEW);

}

void keyboard_input(unsigned char key, int x, int y){
    switch(key){
        case 27:
            exit(0);
            // pthread_exit(NULL);
    }
}

void init(){
    glClearColor(0.1,0.1,0.2,1.0);
    glutFullScreen();

    // glOrtho(-3.0,3.0,-2.0,2.0,-2.0,2.0);   

    // gluLookAt(1.0, 2.0, 3.0, 0.0, 0.0, 0.0, 0.0, 1.0, 0.0); 

    GLfloat mat_specular[] = { 0.0, 1.0, 1.0, 1.0 };
    GLfloat mat_shininess[] = { 50.0 };
    GLfloat light_position[] = { 1.0, 1.0, 1.0, 0.0 };
    // glClearColor (0.0, 0.0, 0.0, 0.0);
    glShadeModel (GL_SMOOTH);

    glMaterialfv(GL_FRONT, GL_SPECULAR, mat_specular);
    glMaterialfv(GL_FRONT, GL_SHININESS, mat_shininess);
    glLightfv(GL_LIGHT0, GL_POSITION, light_position);

    glEnable(GL_LIGHTING);
    glEnable(GL_LIGHT0);

    // enabling depth 
    glEnable(GL_DEPTH_TEST);
    glDepthFunc(GL_LEQUAL);

    // store data in graphic card 
    if(glewInit()){
        cout<<"error"<<endl;        
        exit(EXIT_FAILURE);
    }
    // shader creating
    createShader();

    glGenBuffers(1,&vboid);
    glBindBuffer(GL_ARRAY_BUFFER,vboid);
    glBufferData(GL_ARRAY_BUFFER,sizeof(vertices),vertices,GL_STATIC_DRAW);
    glBindBuffer(GL_ARRAY_BUFFER,0);
}


int main(int argc, char** argv)
{
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB | GLUT_DEPTH);
    glutInitWindowSize(500,500);
    glutInitWindowPosition(0,0);
    window=glutCreateWindow("Assignment 1");

    init();

    glutDisplayFunc(display);
    glutIdleFunc(display);
    glutReshapeFunc(reshape);
    glutKeyboardFunc(keyboard_input);

    glutMainLoop();
    return 0;
}