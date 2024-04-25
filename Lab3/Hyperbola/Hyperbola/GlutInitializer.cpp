#include "GlutInitializer.h"

GlutInitializer::GlutInitializer(int* argc, char** argv)
{
    glutInit(argc, argv);
}

void GlutInitializer::InitDisplayMode(unsigned int mode)
{
    glutInitDisplayMode(mode);
}

void GlutInitializer::InitWindowSize(int width, int height)
{
    glutInitWindowSize(width, height);
}

void GlutInitializer::CreateWindow(const char* title)
{
    glutCreateWindow(title);
}

void GlutInitializer::RegisterDisplayFunc(void (*func)())
{
    glutDisplayFunc(func);
}

void GlutInitializer::RegisterReshapeFunc(void (*func)(int, int))
{
    glutReshapeFunc(func);
}

void GlutInitializer::EnterMainLoop()
{
    glutMainLoop();
}