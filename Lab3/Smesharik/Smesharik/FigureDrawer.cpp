#include "FigureDrawer.h"

void FigureDrawer::DrawEllipse(float xCenter, float yCenter, float rx, float ry)
{
    const float step = float(2 * M_PI / ELLIPSE_POINTS);

    glBegin(GL_TRIANGLE_FAN);
    glVertex2d(xCenter, yCenter);
    for (float angle = 0; angle < 2 * M_PI + step; angle += step)
    {
        const float dx = rx * cosf(angle);
        const float dy = ry * sinf(angle);
        glVertex2f(dx + xCenter, dy + yCenter);
    }
    glEnd();
}

void FigureDrawer::DrawHalfEllipse(float xCenter, float yCenter, float rx, float ry, bool isUpperHalf)
{
    const float step = float(M_PI / ELLIPSE_POINTS);

    glBegin(GL_TRIANGLE_FAN);
    glVertex2f(xCenter, yCenter);
    for (float angle = 0; angle < M_PI + step; angle += step)
    {
        const float dx = rx * cosf(angle);
        const float dy = ry * sinf(angle);
        if (isUpperHalf)
            glVertex2f(dx + xCenter, dy + yCenter);
        else
            glVertex2f(dx + xCenter, -dy + yCenter);
    }
    glEnd();
}

void FigureDrawer::DrawHalfEllipseOutline(float xCenter, float yCenter, float rx, float ry, bool isUpperHalf, float lineWidth)
{
    const float step = float(M_PI / ELLIPSE_POINTS);

    glLineWidth(lineWidth);

    // Примитивы OpenGL
    glBegin(GL_LINES);
    for (float angle = 0; angle < M_PI; angle += step)
    {
        const float dx = rx * cosf(angle);
        const float dy = ry * sinf(angle);
        if (isUpperHalf)
        {
            glVertex2f(dx + xCenter, dy + yCenter);
            glVertex2f(rx * cosf(angle + step) + xCenter, ry * sinf(angle + step) + yCenter);
        }
        else
        {
            glVertex2f(dx + xCenter, -dy + yCenter);
            glVertex2f(rx * cosf(angle + step) + xCenter, -ry * sinf(angle + step) + yCenter);
        }
    }
    glEnd();
}

void FigureDrawer::DrawRectangle(float xTopLeft, float yTopLeft, float width, float height, float angle)
{
    glPushMatrix();

    glTranslatef(xTopLeft + width / 2.0f, yTopLeft + height / 2.0f, 0.0f);
    glRotatef(angle, 0.0f, 0.0f, 1.0f);
    glScalef(width, height, 1.0f);

    glBegin(GL_QUADS);
    glVertex2f(-0.5f, -0.5f);
    glVertex2f(0.5f, -0.5f);
    glVertex2f(0.5f, 0.5f);
    glVertex2f(-0.5f, 0.5f);
    glEnd();

    glPopMatrix();
}

void FigureDrawer::DrawTriangle(float x1, float y1, float x2, float y2, float x3, float y3)
{
    glBegin(GL_TRIANGLES);
    glVertex2f(x1, y1);
    glVertex2f(x2, y2);
    glVertex2f(x3, y3);
    glEnd();
}