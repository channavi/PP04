#include <GLFW/glfw3.h>
#include <stdlib.h>
#include <stdio.h>
#include <Windows.h>
#include <iostream>

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
    float xPoint = 0.0f;
    float xPoint2 = 0.1f;
    float yPoint = 0.0f;
    float yPoint2 = 0.1f;
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

    glEnable(GL_BLEND);
    glBlendFunc(GL_SRC_ALPHA, GL_ONE);

    float ratio;
    int width, height;
    glfwGetFramebufferSize(window, &width, &height);
    ratio = width / (float)height;

    while (!glfwWindowShouldClose(window))
    {
        glClearColor(0.0f, 0.0f, 0.0f, 1);
        glClear(GL_COLOR_BUFFER_BIT);


        if (GetAsyncKeyState(VK_LEFT) & 0x8000 || GetAsyncKeyState(VK_LEFT) & 0x8001)
        {
            xPoint = xPoint - 0.01f;
            xPoint2 = xPoint2 - 0.01f;
        }

        if (GetAsyncKeyState(VK_RIGHT) & 0x8000 || GetAsyncKeyState(VK_RIGHT) & 0x8001)
        {
            xPoint = xPoint + 0.01f;
            xPoint2 = xPoint2 + 0.01f;
        }

        if (GetAsyncKeyState(VK_UP) & 0x8000 || GetAsyncKeyState(VK_UP) & 0x8001)
        {
            yPoint = yPoint + 0.01f;
            yPoint2 = yPoint2 + 0.01f;
        }

        if (GetAsyncKeyState(VK_DOWN) & 0x8000 || GetAsyncKeyState(VK_DOWN) & 0x8001)
        {
            yPoint = yPoint - 0.01f;
            yPoint2 = yPoint2 - 0.01f;
        }

        glPointSize(10);
        glBegin(GL_TRIANGLES);

        glColor4f(0.0f, 1.0f, 0.0f, 1.0f);
        glVertex2f(xPoint, yPoint);
        glColor4f(0.0f, 1.0f, 0.0f, 1.0f);;
        glVertex2f(xPoint, yPoint2);
        glColor4f(0.0f, 1.0f, 0.0f, 1.0f);
        glVertex2f(xPoint2, yPoint);
        glEnd();

        glPointSize(10);
        glBegin(GL_TRIANGLES);

        glColor4f(0.0f, 1.0f, 0.0f, 1.0f);
        glVertex2f(xPoint2, yPoint2);
        glColor4f(0.0f, 1.0f, 0.0f, 1.0f);
        glVertex2f(xPoint, yPoint2);
        glColor4f(0.0f, 1.0f, 0.0f, 1.0f);
        glVertex2f(xPoint2, yPoint);
        glEnd();

        glPointSize(10);
        glBegin(GL_TRIANGLES);

        glColor4f(0.0f, 0.0f, 1.0f, 1.0f);
        glVertex2f(-0.6f, -0.1f);
        glColor4f(0.0f, 0.0f, 1.0f, 1.0f);
        glVertex2f(-0.6f, 0.1f);
        glColor4f(0.0f, 0.0f, 1.0f, 1.0f);
        glVertex2f(-0.4f, -0.1f);
        glEnd();

        glPointSize(10);
        glBegin(GL_TRIANGLES);

        glColor4f(0.0f, 0.0f, 1.0f, 1.0f);
        glVertex2f(-0.4f, 0.1f);
        glColor4f(0.0f, 0.0f, 1.0f, 1.0f);
        glVertex2f(-0.6f, 0.1f);
        glColor4f(0.0f, 0.0f, 1.0f, 1.0f);
        glVertex2f(-0.4f, -0.1f);
        glEnd();

        if (xPoint > -0.6f && xPoint < -0.4f && yPoint < 0.1f && yPoint > -0.1f)
        {
            std::cout << "충돌1";
        }
        if (xPoint > -0.6f && xPoint < -0.4f && yPoint2 < 0.1f && yPoint2 > -0.1f)
        {
            std::cout << "충돌2";
        }
        if (xPoint2 > -0.6f && xPoint2 < -0.4f && yPoint < 0.1f && yPoint > -0.1f)
        {
            std::cout << "충돌3";
        }
        if (xPoint2 > -0.6f && xPoint2 < -0.4f && yPoint2 < 0.1f && yPoint2 > -0.1f)
        {
            std::cout << "충돌4";
        }
        
        
        
        glfwSwapBuffers(window);
        glfwPollEvents();
    }

    glfwDestroyWindow(window);
    glfwTerminate();
    exit(EXIT_SUCCESS);
}
// 다이어그램 최대한 심플하게 , 사이클이 생기지 않게