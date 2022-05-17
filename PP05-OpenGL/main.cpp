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
    float PxPoint = -0.5f;
    float PxPoint2 = -0.6f;
    float yPoint = 0.0f;
    float yPoint2 = 0.1f;
    float ExPoint = 0.5f;
    float ExPoint2 = 0.6f;
    float ExPoint3 = 0.55f;
    bool End = false;
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
        glVertex2f(PxPoint, yPoint);
        glColor3f(0.0f, 1.0f, 0.0f);
        glVertex2f(PxPoint, yPoint2);
        glColor3f(0.0f, 1.0f, 0.0f);
        glVertex2f(PxPoint2, yPoint);

        glEnd();

        glPointSize(10);
        glBegin(GL_TRIANGLES);

        glColor3f(0.0f, 1.0f, 0.0f);
        glVertex2f(PxPoint2, yPoint2);
        glColor3f(0.0f, 1.0f, 0.0f);
        glVertex2f(PxPoint2, yPoint);
        glColor3f(0.0f, 1.0f, 0.0f);
        glVertex2f(PxPoint, yPoint2);

        glEnd();

        glPointSize(10);
        glBegin(GL_TRIANGLES);

        glColor3f(1.0f, 0.0f, 0.0f);
        glVertex2f(ExPoint, 0.0f);
        glColor3f(1.0f, 0.0f, 0.0f);
        glVertex2f(ExPoint2, 0.0f);
        glColor3f(1.0f, 0.0f, 0.0f);
        glVertex2f(ExPoint3, 0.1f);

        glEnd();

        if (ExPoint < -0.8f)
        {
            ExPoint = 0.5f;
        }
        else
        {
            if(End == false)
            ExPoint = ExPoint - 0.01f;
        }

        if (ExPoint2 < -0.7f)
        {
            ExPoint2 = 0.6f;
        }
        else
        {
            if (End == false)
            ExPoint2 = ExPoint2 - 0.01f;
        }
        if (ExPoint3 < -0.75f)
        {
            ExPoint3 = 0.55f;
        }
        else
        {
            if (End == false)
            ExPoint3 = ExPoint3 - 0.01f;
        }

        if (ExPoint == PxPoint)
        {
            End = true;
        }

        glfwSwapBuffers(window);
        glfwPollEvents();
    }
    glfwDestroyWindow(window);
    glfwTerminate();
    exit(EXIT_SUCCESS);
}