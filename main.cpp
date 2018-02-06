
#define GLEW_STATIC

#include<GL/glew.h>
#include<GLFW/glfw3.h>
#include<fstream>
#include "shaderLoader.h"

#include<iostream>
using namespace std;

// global variable
GLFWwindow* window;
GLuint VAO,VBO;
GLuint programShader;
GLfloat vertices[] = {
    -0.5f,-0.5f,0.0f,
    0.5f,-0.5f,0.0f,
    0.0f,0.5f,0.0f
};

void keyHandling(GLFWwindow* win,int key,int scancode,int action,int mode){
    if(key==GLFW_KEY_ESCAPE && action == GLFW_PRESS){
        glfwSetWindowShouldClose(window,GL_TRUE);
    }
}


void gameLoop(){
    programShader= GLloadShaders("vertexShader.vs","fragmentShader.fs");
    while(!glfwWindowShouldClose(window)){
        
        glfwPollEvents();

        glClearColor(0.2,0.3,0.3,1.0);
        glClear(GL_COLOR_BUFFER_BIT);
        
        // shader
        glUseProgram(programShader);

        glBindVertexArray(VAO);
        glDrawArrays(GL_LINE_LOOP,0,3);
        glBindVertexArray(0);


        glfwSwapBuffers(window);
    }
}


void init(){
    glViewport(0,0,500,500);

    glfwSetKeyCallback(window,keyHandling);

    glGenVertexArrays(1,&VAO);
    glGenBuffers(1,&VBO);

    glBindVertexArray(VAO);

    glEnableVertexAttribArray(0);

    // vertex buffer data
    glBindBuffer(GL_ARRAY_BUFFER,VBO);
    glBufferData(GL_ARRAY_BUFFER,sizeof(vertices),vertices,GL_STATIC_DRAW);
    
    glVertexAttribPointer(0,3,GL_FLOAT,GL_FALSE,3*sizeof(GLfloat),(GLvoid*)0);

    glBindVertexArray(0);

}



int main(){

    glfwInit();
    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR,3);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR,3);
    glfwWindowHint(GLFW_OPENGL_PROFILE,GLFW_OPENGL_CORE_PROFILE);
    glfwWindowHint(GLFW_RESIZABLE,GL_FALSE);

    window = glfwCreateWindow(500,500,"Assignment 1",NULL,NULL);

    if(window==NULL){
        cerr<<"Failed to create window!"<<endl;
        glfwTerminate();
        return -1;
    }

    glfwMakeContextCurrent(window);
    glfwSetWindowPos(window,400,150);
    glewExperimental = GL_TRUE;

    if(glewInit() != GLEW_OK){
        cerr<<"Failed to load GLEW!"<<endl;
    }

    
    init();

    gameLoop();
    
    glfwTerminate();
    return 0;
}