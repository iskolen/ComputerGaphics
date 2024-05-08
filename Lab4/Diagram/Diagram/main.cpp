#include "pch.h"
#include "GLFWInitializer.h"
#include "Window.h"

int main()
{
	GLFWInitializer initGLFW;
	Window window{ WINDOW_WIDTH, WINDOW_HEIGTH, WINDOW_TITLE };
	window.Run();
}