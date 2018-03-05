#ifndef PHYSICS_HPP
#define PHYSICS_HPP
float MAXVAL =0.05;
#include "balls.hpp"
#include "terrain.hpp"
#include<cmath>
float MINVAL =0.00001;
void collideBallToBall(balls &a,balls &b){

bool collisionhappens=false;

 float distance=(a.x+a.vx-b.x-b.vx)*(a.x+a.vx-b.x-b.vx)+(a.y+a.vy-b.y-a.vy)*(a.y+a.vy-b.y-a.vy)+(a.z+a.vz-b.z-b.vz)*(a.z+a.vz-b.z-b.vz);

 if(distance <= 4.0*a.raddi *a.raddi) {
    collisionhappens=true;
 }
     
 if(collisionhappens==true){  
    
    float radial_vectorx = b.x-a.x; 
    float radial_vectory = b.y-a.y;
    float radial_vectorz = b.z-a.z;
    float dotproductb = -b.vx*radial_vectorx-b.vy*radial_vectory-b.vz*radial_vectorz;
    float dotproducta = a.vx*radial_vectorx+a.vy*radial_vectory+a.vz*radial_vectorz;
    float resultant = radial_vectorx*radial_vectorx+radial_vectory*radial_vectory+radial_vectorz*radial_vectorz;
    
    if(b.x>a.x)
            b.x=b.raddi/1000+b.x;
            
    else
       a.x=a.raddi/1000+a.x;
    
    float FinalVelocityvxComponentOfA = a.vx -(radial_vectorx)*dotproducta/resultant+(-radial_vectorx)*dotproductb/resultant;
    float FinalVelocityvyComponentOfA = a.vy-(radial_vectory)*dotproducta/resultant+(-radial_vectory)*dotproductb/resultant;
    float FinalVelocityvZComponentOfA = a.vz-(radial_vectorz)*dotproducta/resultant+(-radial_vectorz)*dotproductb/resultant;
    float FinalVelocityvxComponentOfB = b.vx -(-radial_vectorx)*dotproductb/resultant+(radial_vectorx)*dotproducta/resultant;
    float FinalVelocityvyComponentOfB = b.vy-(-radial_vectory)*dotproductb/resultant+(radial_vectory)*dotproducta/resultant;
    float FinalVelocityvZComponentOfB = b.vz-(-radial_vectorz)*dotproductb/resultant+(radial_vectorx)*dotproducta/resultant;
    a.vx = FinalVelocityvxComponentOfA;
    a.vy = FinalVelocityvyComponentOfA;
    a.vz = FinalVelocityvZComponentOfA;
    b.vx = FinalVelocityvxComponentOfB;
    b.vy = FinalVelocityvyComponentOfB ;
    b.vz = FinalVelocityvZComponentOfB;
   
 }

}
void collideBallToWall(balls &a,float width,float height,float depth1 , float depth2){
 
if(a.x+a.vx>width-a.raddi    ||     a.x+a.vx<-width+a.raddi)
     {a.vx=-a.vx;
     if(a.x-width+a.raddi>0)
          a.x=(width-a.raddi);
    if(a.x-a.raddi<-width)   
     a.x=width+a.raddi;
     }
if(a.y+a.vy>height-a.raddi  ||    a.y+a.vy-a.raddi<-height )
    {a.vy=-a.vy;
    if(a.y+a.raddi>height)
          a.y=(height-a.raddi);
    if(a.y-a.raddi-0.003<-height)   
     a.y=-height+a.raddi+0.003;
      }
    
if(a.z+a.vz+a.raddi>-10||    a.z+a.vz-a.raddi<-16 )
    {a.vz=-a.vz;
    if(a.z+a.raddi>-10)
          a.z=(-10-a.raddi);
    if(a.z-a.raddi<-16)   
     a.z=-16+a.raddi;
    } 
    
}


void collideBallToTerrian(balls &a,hemiSphere &h){

      bool collisionhappens=false;

      float distance=(a.x+a.vx-h.x)*(a.x+a.vx-h.x)+(a.y+a.vy-h.y)*(a.y+a.vy-h.y)+(a.z+a.vz-h.z)*(a.z+a.vz-h.z);

       if(distance <= (a.raddi + h.r)*(a.raddi + h.r)) {
            collisionhappens=true;
      }

      if(collisionhappens==true){  
      
      float radial_vectorx = h.x-a.x;
      float radial_vectory = h.y-a.y;
      float radial_vectorz = h.z-a.z;
      float dotproducta = a.vx*radial_vectorx+a.vy*radial_vectory+a.vz*radial_vectorz;
      float resultant = radial_vectorx*radial_vectorx+radial_vectory*radial_vectory+radial_vectorz*radial_vectorz;
      
      if(h.x>a.x)
                  a.x=-a.raddi/50+a.x;
                  
      else
            a.x=a.raddi/50+a.x;
      
      float FinalVelocityvxComponentOfA = a.vx -2*(radial_vectorx)*dotproducta/resultant;
      float FinalVelocityvyComponentOfA = a.vy-2*(radial_vectory)*dotproducta/resultant;
      float FinalVelocityvZComponentOfA = a.vz-2*(radial_vectorz)*dotproducta/resultant;
      a.vx = FinalVelocityvxComponentOfA;
      a.vy = FinalVelocityvyComponentOfA;
      a.vz = FinalVelocityvZComponentOfA;              
 }
 }
 void ballstuck(balls &a,hemiSphere &b,float width )
 {
 
 if((a.x<=-5.5) && (b.x-a.x+0.001<=a.raddi+b.r))
   a.vy=0.001;
 }

 
#endif

