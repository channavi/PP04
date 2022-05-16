#pragma once
#include <GLFW/glfw3.h>
#include <stdlib.h>
#include <stdio.h>
#include <Windows.h>

#pragma comment(lib,"OpenGL32")

using namespace std;

static void error_callback(int error, const char* description)
{
    fputs(description, stderr);
}
static void key_callback(GLFWwindow* window, int key, int scancode, int action, int mods)
{   
    if (key == GLFW_KEY_ESCAPE && action == GLFW_PRESS)
        glfwSetWindowShouldClose(window, GL_TRUE);
}
int main(void)
{
    GLFWwindow* window;
    float yPoint = 0.0f;
    float yPoint2 = 0.1f;
    float xPoint = 0.5f;
    float xPoint2 = 0.6f;
    float xPoint3 = 0.55f;
    glfwSetErrorCallback(error_callback);
    if (!glfwInit())
        exit(EXIT_FAILURE);
    window = glfwCreateWindow(640, 480, "Simple example", NULL, NULL);
    if (!window)
    {
        glfwTerminate();
        exit(EXIT_FAILURE);
    }
    glfwMakeContextCurrent(window);
    glfwSetKeyCallback(window, key_callback);

    float ratio;
    int width, height;
    glfwGetFramebufferSize(window, &width, &height);
    ratio = width / (float)height;
    
    while (!glfwWindowShouldClose(window))
    {
        glClearColor(1.0f,1.0f,1.0f,1);
        glClear(GL_COLOR_BUFFER_BIT);
        
        if (GetAsyncKeyState(VK_SPACE) & 0x8000 || GetAsyncKeyState(VK_SPACE) & 0x8001)
        {
            yPoint = 0.2f;
            yPoint2 = 0.3f;
        }
        else
        {
            yPoint = 0.0f;
            yPoint2 = 0.1f;
        }
        glPointSize(10);
        glBegin(GL_TRIANGLES);

        glColor3f(0.0f, 1.0f, 0.0f);
        glVertex2f(-0.5f, yPoint);
        glColor3f(0.0f, 1.0f, 0.0f);
        glVertex2f(-0.5f, yPoint2);
        glColor3f(0.0f, 1.0f, 0.0f);
        glVertex2f(-0.6f, yPoint);

        glEnd();

        glPointSize(5);
        glBegin(GL_TRIANGLES);

        glColor3f(0.0f, 1.0f, 0.0f);
        glVertex2f(-0.6f, yPoint2);
        glColor3f(0.0f, 1.0f, 0.0f);
        glVertex2f(-0.6f, yPoint);
        glColor3f(0.0f, 1.0f, 0.0f);
        glVertex2f(-0.5f, yPoint2);

        glEnd();

        glPointSize(5);
        glBegin(GL_TRIANGLES);

        glColor3f(1.0f, 0.0f, 0.0f);
        glVertex2f(xPoint, 0.0f);
        glColor3f(1.0f, 0.0f, 0.0f);
        glVertex2f(xPoint2, 0.0f);
        glColor3f(1.0f, 0.0f, 0.0f);
        glVertex2f(xPoint3, 0.1f);

        glEnd();

        if (xPoint < -0.8f)
            xPoint = 0.5f;
        else
            xPoint = xPoint - 0.0003f;
        if (xPoint2 < -0.7f)
            xPoint2 = 0.6f;
        else
            xPoint2 = xPoint2 - 0.0003f;
        if (xPoint3 < -0.75f)
            xPoint3 = 0.55f;
        else
            xPoint3 = xPoint3 - 0.0003f;
        glfwSwapBuffers(window);
        glfwPollEvents();
    }
    glfwDestroyWindow(window);
    glfwTerminate();
    exit(EXIT_SUCCESS);
}