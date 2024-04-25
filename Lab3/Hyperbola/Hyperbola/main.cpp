#include "GlutInitializer.h"
#include "Hyperbola.h"

void OnDrawGraph()
{
    Hyperbola hyperbola;
    hyperbola.DrawHyperbola();
}

void OnResizeWindow(int width, int height)
{
    glViewport(0, 0, width, height);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();

    float aspectRatio = (float)width / (float)height;

    if (aspectRatio >= 1.0)
        glOrtho(-4.0 * aspectRatio, 4.0 * aspectRatio, -4.0, 4.0, -4.0, 4.0);
    else
        glOrtho(-4.0, 4.0, -4.0 / aspectRatio, 4.0 / aspectRatio, -4.0, 4.0);

    glMatrixMode(GL_MODELVIEW);
    glutPostRedisplay();
}

int main(int argc, char** argv)
{
    GlutInitializer glutInit(&argc, argv);
    glutInit.InitDisplayMode(GLUT_RGBA | GLUT_DOUBLE);
    glutInit.InitWindowSize(WINDOW_WIDTH, WINDOW_HEIGTH);
    glutInit.CreateWindow(WINDOW_TITLE);

    glutInit.RegisterDisplayFunc(&OnDrawGraph);
    glutInit.RegisterReshapeFunc(&OnResizeWindow);

    glutInit.EnterMainLoop();

    return 0;
}