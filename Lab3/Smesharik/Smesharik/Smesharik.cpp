#include "Smesharik.h"

void Smesharik::DrawKarych()
{
    glClearColor(1.0, 1.0, 1.0, 1.0);
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

    DrawLegs();
    DrawBody();
    DrawHands();

    glutSwapBuffers();
}

void Smesharik::DrawBody()
{
    DrawHead();
    DrawButterfly();
    DrawEyes();
    DrawBeak();
}

void Smesharik::DrawHead()
{
    glColor3f(0.15f, 0.08f, 0.36f);
    FigureDrawer::DrawEllipse(0.0f, 0.0f, 0.52f, 0.52f);

    glColor3f(0.0f, 0.4f, 0.67f);
    FigureDrawer::DrawEllipse(0.0f, 0.0f, 0.5f, 0.5f);
}

void Smesharik::DrawLegs()
{
    glColor3f(0.64f, 0.13f, 0.39f);
    FigureDrawer::DrawRectangle(-0.11f, -0.71f, 0.09f, 0.27f, 0);
    FigureDrawer::DrawRectangle(-0.01f, -0.71f, 0.09f, 0.27f, 0);

    FigureDrawer::DrawRectangle(-0.18f, -0.71f, 0.09f, 0.22f, -45);
    FigureDrawer::DrawRectangle(0.06f, -0.71f, 0.09f, 0.22f, 45);

    glColor3f(0.90f, 0.4f, 0.61f);
    FigureDrawer::DrawRectangle(-0.10f, -0.7f, 0.07f, 0.25f, 0);
    FigureDrawer::DrawRectangle(0.0f, -0.7f, 0.07f, 0.25f, 0);

    FigureDrawer::DrawRectangle(-0.17f, -0.7f, 0.07f, 0.20f, -45);
    FigureDrawer::DrawRectangle(0.07f, -0.7f, 0.07f, 0.20f, 45);
}

void Smesharik::DrawHands()
{
    glColor3f(0.15f, 0.08f, 0.36f);
    FigureDrawer::DrawHalfEllipse(0.5f, -0.27f, 0.1f, 0.4f, true);
    FigureDrawer::DrawHalfEllipse(0.5f, -0.27f, 0.1f, 0.1f, false);

    FigureDrawer::DrawHalfEllipse(-0.5f, -0.27f, 0.1f, 0.4f, true);
    FigureDrawer::DrawHalfEllipse(-0.5f, -0.27f, 0.1f, 0.1f, false);

    glColor3f(0.0f, 0.4f, 0.67f);
    FigureDrawer::DrawHalfEllipse(0.5f, -0.27f, 0.08f, 0.38f, true);
    FigureDrawer::DrawHalfEllipse(0.5f, -0.27f, 0.08f, 0.08f, false);

    FigureDrawer::DrawHalfEllipse(-0.5f, -0.27f, 0.08f, 0.38f, true);
    FigureDrawer::DrawHalfEllipse(-0.5f, -0.27f, 0.08f, 0.08f, false);

}

void Smesharik::DrawBeak()
{
    glColor3f(0.89f, 0.42f, 0.08f);
    FigureDrawer::DrawHalfEllipse(0.0f, 0.1f, 0.41f, 0.21f, false);
    FigureDrawer::DrawHalfEllipse(0.0f, 0.1f, 0.41f, 0.14f, true);
    FigureDrawer::DrawEllipse(0.0f, 0.15f, 0.11f, 0.16f);

    glColor3f(0.95f, 0.67f, 0.0f);
    FigureDrawer::DrawHalfEllipse(0.0f, 0.1f, 0.4f, 0.2f, false);
    FigureDrawer::DrawHalfEllipse(0.0f, 0.1f, 0.4f, 0.13f, true);
    FigureDrawer::DrawEllipse(0.0f, 0.15f, 0.1f, 0.15f);

    glColor3f(0.89f, 0.42f, 0.08f);
    FigureDrawer::DrawHalfEllipseOutline(0.0f, 0.1f, 0.3f, 0.1f, false, 4.0f);
}

void Smesharik::DrawEyes()
{
    glColor3f(0.64f, 0.13f, 0.39f);
    FigureDrawer::DrawEllipse(-0.15f, 0.4f, 0.2f, 0.2f);
    FigureDrawer::DrawEllipse(0.15f, 0.4f, 0.2f, 0.2f);

    glColor3f(0.90f, 0.4f, 0.61f);
    FigureDrawer::DrawEllipse(-0.15f, 0.4f, 0.18f, 0.18f);
    FigureDrawer::DrawEllipse(0.15f, 0.4f, 0.18f, 0.18f);

    glColor3f(0.64f, 0.13f, 0.39f);
    FigureDrawer::DrawEllipse(-0.13f, 0.36f, 0.2f, 0.1f);
    FigureDrawer::DrawEllipse(0.13f, 0.36f, 0.2f, 0.1f);

    glColor3f(1, 1, 1);
    FigureDrawer::DrawHalfEllipse(-0.12f, 0.35f, 0.2f, 0.1f, true);
    FigureDrawer::DrawHalfEllipse(0.12f, 0.35f, 0.2f, 0.1f, true);

    FigureDrawer::DrawHalfEllipse(-0.12f, 0.35f, 0.2f, 0.13f, false);
    FigureDrawer::DrawHalfEllipse(0.12f, 0.35f, 0.2f, 0.13f, false);

    glColor3f(0, 0, 0);
    FigureDrawer::DrawEllipse(-0.07f, 0.37f, 0.04f, 0.05f);
    FigureDrawer::DrawEllipse(0.07f, 0.37f, 0.04f, 0.05f);

    glColor3f(1, 1, 1);
    FigureDrawer::DrawEllipse(-0.05f, 0.39f, 0.02f, 0.02f);
    FigureDrawer::DrawEllipse(0.1f, 0.39f, 0.02f, 0.02f);

    glColor3f(0.64f, 0.13f, 0.39f);
    FigureDrawer::DrawRectangle(-0.005f, 0.27f, 0.01f, 0.25f, 0);
}

void Smesharik::DrawButterfly()
{
    glColor3f(0.15f, 0.08f, 0.37f);
    FigureDrawer::DrawTriangle(-0.15f, -0.35f, 
                               -0.15f, -0.15f, 
                               0.1f, -0.25f);

    FigureDrawer::DrawTriangle(0.15f, -0.35f,
                               0.15f, -0.15f,
                               -0.1f, -0.25f);
}