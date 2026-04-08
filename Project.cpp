// compgraf.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#define GLEW_DLL
#define GLFW_DLL

#include <iostream>

#include "GL/glew.h"
#include "GLFW/glfw3.h"



int main()
{
    if (!glfwInit()) {
        fprintf(stderr, "ERROR: could not start GLFW3.\n");
        return 1;
    }

    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 1);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 0);
    //glfwWindowHint(GLFW_OPENGL_FORWARD_COMPAT, GL_TRUE);
    //glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);

    GLFWwindow* window = glfwCreateWindow(1024, 1024, "Lab1-Mainwindow", NULL, NULL);

    if (!window) {
        glfwTerminate();
        return -1;
    }
    glfwMakeContextCurrent(window);
    glewExperimental = GL_TRUE;

    GLenum ret = glewInit();
    if (ret != GLEW_OK) {
        fprintf(stderr, "ERROR: %s\n", glewGetErrorString(ret));
        return 1;
    }


    while (!glfwWindowShouldClose(window)) {
        glClearColor(1.0, 0.6, 1.0, 1.0 );
        glClear(GL_COLOR_BUFFER_BIT);

        glBegin(GL_TRIANGLES);
        
        glColor3f(1.0f, 1.0f, 0.7f);   
        glVertex2f(-0.5f, -0.5f);      
        glVertex2f(0.5f, -0.5f);      
        glVertex2f(0.5f, 0.5f);      

        // Второй треугольник 
        
        glVertex2f(0.5f, 0.5f);      
        glVertex2f(-0.5f, -0.5f);      
        glVertex2f(-0.5f, 0.5f);      

        glEnd();
        glfwSwapBuffers(window);

        glfwPollEvents();
    }
    glfwTerminate();

    return 0;
}
