#include <GL/glut.h>

GLfloat trans = 8.0,tra=-3.0;

GLfloat getTrans(){
  return trans;
}

GLfloat getTras(){
  return tra;
}

void setTrans(float tran,float k){
  if(tran>=30.2)
    trans=30.00001;
  else if(trans>=8.0)
  trans = trans + k;
  else
      trans = 8.0;
}

void setTras(float tran,float k){
  if(tran>=18.6)
    tra=18.5;
  else if(tra>=-3.0)
  tra = tran + k;
  else 
      tra = -3.0;
}
void DrawCube(void)
{
    glMatrixMode(GL_MODELVIEW);
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    glBegin(GL_QUADS);        
   
      glColor3f(0.9f,0.9f,0.9f);  
    glVertex3f( 30.0f,-3.0f, 3.0f);  // Top Right Of The Quad (Bottom)
    glVertex3f(-3.0f,-3.0f, 3.0f);      // Top Left Of The Quad (Bottom)
    glVertex3f(-3.0f,-3.0f,-3.0f); // Bottom Left Of The Quad (Bottom)
    glVertex3f( 30.0f,-3.0f,-3.0f);    // Bottom Right Of The Quad (Bottom)    
 

    glColor3f(0.9,0.9,0.9 );
    glVertex3f( 30.0f, 3.0f,-3.0f);    // Top Right Of The Quad (Top)
    glVertex3f(-3.0f, 3.0f,-3.0f);    // Top Left Of The Quad (Top)
    glVertex3f(-3.0f, 3.0f, 3.0f);    // Bottom Left Of The Quad (Top)
    glVertex3f( 30.0f, 3.0f, 3.0f);    // Bottom Right Of The Quad (Top)
     
   glColor3f(0.8f,0.8f,0.8f);       
    glVertex3f( 30.0f,-3.0f,-3.0f);    // Top Right Of The Quad (Back)
    glVertex3f(-3.0f,-3.0f,-3.0f);    // Top Left Of The Quad (Back)
    glVertex3f(-3.0f, 3.0f,-3.0f);    // Bottom Left Of The Quad (Back)
    glVertex3f( 30.0f, 3.0f,-3.0f);    // Bottom Right Of The Quad (Back)
   
   glColor3f(0.7f,0.7f,0.7f);        
    glVertex3f(-3.0f, 3.0f, 3.0f);    // Top Right Of The Quad (Left)
    glVertex3f(-3.0f, 3.0f,-3.0f);    // Top Left Of The Quad (Left)
    glVertex3f(-3.0f,-3.0f,-3.0f);    // Bottom Left Of The Quad (Left)
    glVertex3f(-3.0f,-3.0f, 3.0f);    // Bottom Right Of The Quad (Left)
   
   glColor3f(0.7f,0.7f,0.7f);        
    glVertex3f( 30.0f, 3.0f,-3.0f);    // Top Right Of The Quad (Right)
    glVertex3f( 30.0f, 3.0f, 3.0f);    // Top Left Of The Quad (Right)
    glVertex3f( 30.0f,-3.0f, 3.0f);    // Bottom Left Of The Quad (Right)
    glVertex3f( 30.0f,-3.0f,-3.0f);

   glColor3f(0.6f,0.6f,0.6f);        
    glVertex3f( trans, 3.0f,-3.0f);    // Top Right Of The Quad (Right)
     glVertex3f( trans, 3.0f, 3.0f);    // Top Left Of The Quad (Right)
     glVertex3f( trans,-3.0f, 3.0f);    // Bottom Left Of The Quad (Right)
     glVertex3f( trans,-3.0f,-3.0f);  

     glColor3f(0.6f,0.6f,0.6f);        
     glVertex3f(tra, 3.0f, 3.0f);    // Top Right Of The Quad (Left)
     glVertex3f(tra, 3.0f,-3.0f);    // Top Left Of The Quad (Left)
     glVertex3f(tra,-3.0f,-3.0f);    // Bottom Left Of The Quad (Left)
     glVertex3f(tra,-3.0f, 3.0f);  

glEnd();

}
