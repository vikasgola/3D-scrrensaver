#include<GL/glew.h>
#include<GL/glut.h>
#include<math.h>
#include<stdlib.h>

#include<iostream>

using namespace std;


#define NUM_THREADS 5


// global varibles



void data_entry_from_array(){
    
    // enabling data entry form arrays
    glEnableClientState(GL_VERTEX_ARRAY);

    //enablong data entry of colors from array
    glEnableClientState(GL_COLOR_ARRAY);

    // glBindBuffer(GL_ARRAY_BUFFER,vboid);


    // take input from array with some details
    glVertexPointer(3,GL_FLOAT,3*sizeof(GL_FLOAT),0);
    glColorPointer(3,GL_FLOAT,3*sizeof(GL_FLOAT),(GLvoid *)(18*sizeof(GLfloat)));
    glDrawArrays(GL_TRIANGLES,0,6);

    // disable client state
    glDisableClientState(GL_COLOR_ARRAY);
    glDisableClientState(GL_VERTEX_ARRAY);

}


void init(){

    // enable lighting
    GLfloat mat_specular[] = { 0.0, 1.0, 1.0, 1.0 };
    GLfloat mat_shininess[] = { 50.0 };
    GLfloat light_position[] = { -1.0, 1.0, 1.0, 0.0 };

    glShadeModel (GL_SMOOTH);

    glMaterialfv(GL_FRONT, GL_SPECULAR, mat_specular);
    glMaterialfv(GL_FRONT, GL_SHININESS, mat_shininess);
    glLightfv(GL_LIGHT0, GL_POSITION, light_position);

    glEnable(GL_LIGHTING);
    glEnable(GL_LIGHT0);

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

        glVertex3f(x + cx, y + cy,-1.5);//output vertex

    }
    glEnd();
}

void thread(){
    
    pthread_t threads[NUM_THREADS];
    int rc;
    int i;
   
    for( i = 0; i < NUM_THREADS; i++ ) {
      cout << "main() : creating thread, " << i << endl;
    //   rc = pthread_create(&threads[i], NULL, createBalls, (void *)i);
      
      if (rc) {
         cout << "Error:unable to create thread," << rc << endl;
         exit(-1);
      }
    }
    pthread_exit(NULL);

}

void reshape(){
        // enable lighting
    // GLfloat mat_specular[] = { 0.0, 1.0, 1.0, 1.0 };
    // GLfloat mat_shininess[] = { 50.0 };
    // GLfloat light_position[] = { 1.0, 1.0, 1.0, 0.0 };

    // glShadeModel (GL_SMOOTH);

    // glMaterialfv(GL_FRONT, GL_SPECULAR, mat_specular);
    // glMaterialfv(GL_FRONT, GL_SHININESS, mat_shininess);
    // glLightfv(GL_LIGHT0, GL_POSITION, light_position);

    // glEnable(GL_LIGHTING);
    // glEnable(GL_LIGHT0);

}

int main(int argc, char** argv){



    return 0;
}