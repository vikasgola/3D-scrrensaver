#ifndef SHADER_LOADER_H
#define SHADER_LOADER_H 

#include<GL/glew.h>
#include<GLFW/glfw3.h>

GLuint GLloadShaders(const char * vertex_file_path,const char * fragment_file_path);

#endif