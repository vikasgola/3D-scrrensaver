#include <GL/glut.h>
#include <GL/freeglut.h>
#include<pthread.h>
#include "balls.hpp"
#include <unistd.h>
#include"physics.hpp"
#include"terrain.hpp"
#include"cube.hpp"
#include<ctime>

#define T 20
int tt=0;
GLuint window;
pthread_t thread[N], thread_main;
hemiSphere HS[T];

balls ball[50];
int selectedBall = -1;
GLfloat eyeX;
pthread_mutex_t lock;
int t=N;

void setSelectedBall(int l){
    selectedBall=l;
}

void increaseN(){
    t++;
    #undef N
    #define N t
}

void decreaseN(){
    t--;
    #undef N
    #define N t
}

GLfloat getEye(){
    return eyeX;
}

void setMotionT(float ki){
    if(getEye()>2.5 && getEye()<=24.35){
    for(int i=0;i<T;i++){
            HS[i].motion(-ki);
        }
    }
}

void setEye(float eye,float k){
    
    setMotionT(k);
    
    if(eye>=24.6){
        eyeX=24.5;
    }else if(eye>=2.4){
        eyeX=eye+k;
    }else{
        eyeX=2.40;
    }
}

void * function(void * id){

    int i= (long int) id;
    
    pthread_mutex_lock(&lock);  
    collideBallToWall(ball[i],5.5,3.0,-8,-13.0);
   
    for(int k=0;k<N;k++)
        for(int j=0;j<T;j++){
            collideBallToTerrian(ball[k],HS[j]);
            
    }
    for(int k=0;k<N;k++)
    for(int j=k+1;j<N;j++){
        if(j!=k)
            {
            collideBallToBall(ball[k],ball[j]);
            
            
            }
    }
     for(int k=0;k<N;k++)
    for(int j=0;j<T;j++){
            {
       ballstuck(ball[i],HS[j],5.5 );
            
            
            }
    }

     
    pthread_mutex_unlock(&lock);  

    ball[i].move();
    pthread_exit(NULL);     
 }


void start(){
   glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

    glLoadIdentity();

    gluLookAt(getEye(),0.0,0.0,getEye(),0.0,-5.0,0.0,1.0,0.0);
    
    glTranslatef(0.0,0.0,-13.0); 
    DrawCube();

    for(int i=0;i<T;i++){
        HS[i].hemiDraw();
    }

    for(long int i=0;i<N;i++){
        ball[i].balldrawing();
        pthread_create(&thread[i] , NULL , function , (void *)i);
        pthread_join(thread[i],NULL);
       }
  
    glutSwapBuffers();
}


void reshape(int x, int y){
    if (y == 0 || x == 0)
     return; 
    glMatrixMode(GL_PROJECTION);    
    glLoadIdentity();
    gluPerspective(33.5,(GLdouble)x/(GLdouble)y,6.0,16.0);
  
    glMatrixMode(GL_MODELVIEW);
    
    glViewport(0,0,x,y);
}

void idle(){
    glutPostRedisplay();
}

void windowKeys(GLint key,int x,int y){
    switch(key){
    case GLUT_KEY_RIGHT:
            setEye(eyeX,0.01);
            setTrans(getTrans(),0.01);
            setTras(getTras(),0.01);
            break;
            
    case GLUT_KEY_LEFT:
            setEye(eyeX,-0.01);
            setTrans(getTrans(),-0.01);
            setTras(getTras(),-0.01);
            break;
    }
}
void gamepause()
{ 
if(tt==0)
 {for(int k=0;k<N;k++)
      {
           ball[k].tempvx=ball[k].vx;
           ball[k].vx=0;
           ball[k].tempvy=ball[k].vy;
           ball[k].vy=0;
           ball[k].tempvz=ball[k].vz;
           ball[k].vz=0;
          ball[k].tempgravity= ball[k].gravity;
          ball[k].gravity=0; 
    }
    tt=1;}
else 
{

 for(int k=0;k<N;k++)
      {
          ball[k].vx=ball[k].tempvx;
           
                     ball[k].vy=ball[k].tempvy;
           
                     ball[k].vz=ball[k].tempvz;
           
                     ball[k].gravity=ball[k].tempgravity;
            
    
        }
        tt=0;
   }
}

void keyboard(unsigned char key, int x, int y){    
    switch(key){
    case 27:
            glutDestroyWindow(window);
            break;
    case 103:
            for(int i=0;i<N;i++){
            if(ball[1].gravity>0.001)
            {
            }
    else  
            ball[i].gravity+=0.0001;
                
            }
            break;
     case 32:
                gamepause();
                break;
    case 104:
            for(int i=0;i<N;i++){
                ball[i].gravity-=0.0001;
            }
            break;
     case 113:
            if(selectedBall==-1){
                for(int i=0;i<N;i++){
                    ball[i].vx+=0.0001;
                }
            }else{
                ball[selectedBall].vx+=0.1;
            }
            
            break;
    case 97:
            if(selectedBall==-1){
                for(int i=0;i<N;i++){
                    ball[i].vx-=0.0001;
                }
            }else{
                ball[selectedBall].vx-=0.1;
            }
            break;
    case 119:
            if(selectedBall==-1){
                for(int i=0;i<N;i++){
                    ball[i].vy+=0.0001;
                }
            }else{
                ball[selectedBall].vy+=0.1;
            }
            break;
    case 115:
            if(selectedBall==-1){
                for(int i=0;i<N;i++){
                    ball[i].vy-=0.0001;
                }
            }else{
                ball[selectedBall].vy-=0.001;
            }
            break;
    case 101:
            if(selectedBall==-1){
                for(int i=0;i<N;i++){
                    ball[i].vz+=0.0001;
                }
            }else{
                ball[selectedBall].vz+=0.1;
            }
            break;
    case 100:
            if(selectedBall==-1){
                for(int i=0;i<N;i++){
                    ball[i].vz-=0.0001;
                }
            }else{
                ball[selectedBall].vz-=0.1;
            }
            break;
    case 43:
        increaseN();
        break;
    case 45:
        decreaseN();
        break;
    default:
        setSelectedBall(key-49);
    }

}

void *init(void *id){
    glutInitDisplayMode(GLUT_DOUBLE|GLUT_RGB |GLUT_DEPTH);
    glutInitWindowSize(600,600);
    glutInitWindowPosition(0, 0);
    window = glutCreateWindow((char *)id);
    glutFullScreen();
    glClearColor(0.0,0.0,0, 0);
    glEnable(GL_DEPTH_TEST);
    glDepthFunc(GL_LEQUAL);
 glEnable(GL_LIGHTING);
	glEnable(GL_LIGHT0);
	// Create light components
	GLfloat ambientLight[] = { 1.0f, 1.0f, 1.0f, 0.0f };
	GLfloat diffuseLight[] = { 0.8f, 0.8f, 0.8, 1.0f };
	GLfloat specularLight[] = { 0.5f, 0.5f, 0.5f, 1.0f };
	GLfloat position[] = { -3.0f, -3.0f, 0.0f,0.0f};
 glEnable(GL_COLOR_MATERIAL);
     
	// Assign created components to GL_LIGHT0
	glLightfv(GL_LIGHT0, GL_AMBIENT, ambientLight);
	glLightfv(GL_LIGHT0, GL_DIFFUSE, diffuseLight);
	glLightfv(GL_LIGHT0, GL_SPECULAR, specularLight);
	glLightfv(GL_LIGHT0, GL_POSITION, position);
	glTranslatef(0.5,0,0);

    setEye(2.4,0.1);

    glutDisplayFunc(start);
    glutIdleFunc(idle);   

    glutReshapeFunc(reshape);
    glutKeyboardFunc( keyboard );
    glutSpecialFunc(windowKeys);
    glutMainLoop();

}

int main(int argc, char** argv){
     
    glutInit(&argc, argv); 
        if (pthread_mutex_init(&lock, NULL) != 0)
    {
        cout<<"\ns mutex init has failed\n";
        return 1;
    }
   
    pthread_create(&thread_main , NULL , init , (void *)argv[0]);

    pthread_exit(EXIT_SUCCESS);
    return 0;
}
