
#ifndef TERRAIN
#define TERRAIN

#include<GL/glut.h>
#include<math.h>
#include <unistd.h>
#include<iostream>
using namespace std;

float randi(float a, float b) {
    float random = (float) rand() / (float) RAND_MAX;
    float diff = b - a;
    float r = random * diff;
    return a + r;
}

class hemiSphere{
    public:
        float r , x , y ,z;
        
        hemiSphere(){
            static bool seeded = false;
            if(!seeded) {
            srand(time(NULL));
            seeded = true;
        }
            y=-3.0;
            r=randi(0.3,0.5);
            x= randi(-5.0,30.0);
            z= randi(-10.0,-16.0);
        }

        void hemiDraw(){

            glLoadIdentity();
            glColor3f(0.1,1.0,0.0);
            glTranslatef(x,y,z);
            glutSolidSphere(r,20,360);
        }

        void motion(float vx){
            x=x+vx;
        }
};

#endif
