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

    GLFWwindow* window = glfwCreateWindow(512, 512, "Mainwindow", NULL, NULL);

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
        
        glColor3f(1.0f, 1.0f, 0.7f);   // цвет для вершин 1 и 2
        glVertex2f(-0.5f, -0.5f);      // левый нижний угол

        glColor3f(1.0f, 1.0f, 0.7f);
        glVertex2f(0.5f, -0.5f);      // правый нижний угол

        glColor3f(1.0f, 1.0f, 0.7f);
        glVertex2f(0.5f, 0.5f);      // правый верхний угол

        // Второй треугольник (верхний левый – нижний правый)
        glColor3f(1.0f, 1.0f, 0.7f);
        glVertex2f(0.5f, 0.5f);      // правый верхний угол

        glColor3f(1.0f, 1.0f, 0.7f);
        glVertex2f(-0.5f, -0.5f);      // левый нижний угол

        glColor3f(1.0f, 1.0f, 0.7f);
        glVertex2f(-0.5f, 0.5f);      // левый верхний угол

        glEnd();
        glfwSwapBuffers(window);

        glfwPollEvents();
    }
    glfwTerminate();

    return 0;
}
