#ifndef BALLS 
#define BALLS

#include<GL/glut.h>
#include<math.h>
#include <unistd.h>
#include<iostream>
using namespace std;

class balls {
public:
float x,y,z,vx,vy,vz,t,raddi,rc,gc,bc,gravity,tempvx,tempvy,tempvz,tempgravity;

float randi(float a, float b) {
    float random = (float) rand() / (float) RAND_MAX;
    float diff = b - a;
    float r = random * diff;
    return a + r;
}

 
    balls(){
        static bool seeded = false;
        if(!seeded) {
            srand(time(NULL));
            seeded = true;
        }
        
        t = 0.0;

        rc=randi(0.0,1.0);
        
        gc=randi(0.0,1.0);

        bc=randi(0.0,1.0);
        
        gravity=0.0001;
        
        raddi = randi(0.40,0.40);
        x = randi(-5.0+raddi,5.0-raddi);
        y = randi(-3.0+raddi,3.0-raddi);
        z = randi(-10.0-raddi,-16+raddi);

        vx = randi(0.001,0.002);
        vy = randi(0.003,0.005);
        vz =randi(0.0001,0.0003);
        
    }

    void balldrawing(){
        glLoadIdentity();
        glColor3f(rc,gc,bc);
        glTranslatef(x,y,z);
        glutSolidSphere(raddi,20,360);
      
    }


    void move()
    { 
        x = x + vx;
        vy=vy-gravity;
        y = y + vy;
        z = z + vz;
    }

};


#endif
