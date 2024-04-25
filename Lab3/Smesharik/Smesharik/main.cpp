#include "Smesharik.h"
#include "GlutInitializer.h"

void DrawSmesharik()
{
    Smesharik smesharik;
    smesharik.DrawKarych();
}

void Reshape(int width, int height)
{
    glViewport(0, 0, width, height);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();

    float aspectRatio = (float)width / (float)height;

    if (aspectRatio >= 1.0) 
        glOrtho(-1.0 * aspectRatio, 1.0 * aspectRatio, -1.0, 1.0, -1.0, 1.0);
    else 
        glOrtho(-1.0, 1.0, -1.0 / aspectRatio, 1.0 / aspectRatio, -1.0, 1.0);

    glMatrixMode(GL_MODELVIEW);
    glutPostRedisplay();
}

int main(int argc, char** argv) 
{
    GlutInitializer glutInit(&argc, argv);
    glutInit.InitDisplayMode(GLUT_RGB | GLUT_DOUBLE);
    glutInit.InitWindowSize(WINDOW_WIDTH, WINDOW_HEIGTH);
    glutInit.CreateWindow(WINDOW_TITLE);

    glutInit.RegisterDisplayFunc(&DrawSmesharik);
    glutInit.RegisterReshapeFunc(&Reshape);

    glutInit.EnterMainLoop();

    return 0;
}