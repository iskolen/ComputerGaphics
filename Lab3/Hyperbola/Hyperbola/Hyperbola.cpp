#include "Hyperbola.h"

void Hyperbola::DrawHyperbola()
{
	glClearColor(1.0f, 1.0f, 1.0f, 1.0f);
	glClear(GL_COLOR_BUFFER_BIT);

	DrawCoordinateAxes();
	DrawGraph();

	glutSwapBuffers();
}

void Hyperbola::DrawCoordinateAxes()
{
	glColor3f(0.5f, 0.5f, 0.5f);

	glBegin(GL_LINES);
	glVertex2f(-4.0, 0.0);
	glVertex2f(4.0, 0.0);
	glVertex2f(0.0, -4.0);
	glVertex2f(0.0, 4.0);
	glEnd();

	DrawDivisions();
	DrawArrows();
}

void Hyperbola::DrawDivisions()
{
	glColor3f(0.5f, 0.5f, 0.5f);

	glBegin(GL_LINES);
	for (float i = -4.0; i < 4.0; i += 0.5)
	{
		glVertex2f(i, -0.1);
		glVertex2f(i, 0.1);
		glVertex2f(-0.1, i);
		glVertex2f(0.1, i);
	}
	glEnd();
}

void Hyperbola::DrawArrows()
{
	glColor3f(0, 0, 0);

	glBegin(GL_TRIANGLES);
	glVertex2f(3.9, 0.1);
	glVertex2f(4.0, 0.0);
	glVertex2f(3.9, -0.1);

	glVertex2f(-0.1, 3.9);
	glVertex2f(0.0, 4.0);
	glVertex2f(0.1, 3.9);
	glEnd();
}

void Hyperbola::DrawGraph()
{
	glColor3f(0, 0, 1);

	glBegin(GL_LINE_STRIP);
	for (float x = -4.0; x <= -0.01; x += 0.01)
	{
		float y = 1.0 / x;
		glVertex2f(x, y);
	}
	glEnd();

	glBegin(GL_LINE_STRIP);
	for (float x = 0.01; x <= 4.0; x += 0.01)
	{
		float y = 1.0 / x;
		glVertex2f(x, y);
	}
	glEnd();
}
