#include "stdafx.h"

class GlutInitializer 
{
public:
	GlutInitializer(int* argc, char** argv);
    void InitDisplayMode(unsigned int mode);
    void InitWindowSize(int width, int height);
    void CreateWindow(const char* title);
    void RegisterDisplayFunc(void (*func)());
    void RegisterReshapeFunc(void (*func)(int, int));
    void EnterMainLoop();
};