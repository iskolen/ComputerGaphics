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
    float angleRad = angle * (M_PI / 180.0f);

    float centerX = xTopLeft + width / 2.0f;
    float centerY = yTopLeft + height / 2.0f;

    float x1 = (xTopLeft - centerX) * cos(angleRad) - (yTopLeft - centerY) * sin(angleRad) + centerX;
    float y1 = (xTopLeft - centerX) * sin(angleRad) + (yTopLeft - centerY) * cos(angleRad) + centerY;

    float x2 = (xTopLeft + width - centerX) * cos(angleRad) - (yTopLeft - centerY) * sin(angleRad) + centerX;
    float y2 = (xTopLeft + width - centerX) * sin(angleRad) + (yTopLeft - centerY) * cos(angleRad) + centerY;

    float x3 = (xTopLeft + width - centerX) * cos(angleRad) - (yTopLeft + height - centerY) * sin(angleRad) + centerX;
    float y3 = (xTopLeft + width - centerX) * sin(angleRad) + (yTopLeft + height - centerY) * cos(angleRad) + centerY;

    float x4 = (xTopLeft - centerX) * cos(angleRad) - (yTopLeft + height - centerY) * sin(angleRad) + centerX;
    float y4 = (xTopLeft - centerX) * sin(angleRad) + (yTopLeft + height - centerY) * cos(angleRad) + centerY;

    glBegin(GL_QUADS);
    glVertex2f(x1, y1);
    glVertex2f(x2, y2);
    glVertex2f(x3, y3);
    glVertex2f(x4, y4);
    glEnd();
}

void FigureDrawer::DrawTriangle(float x1, float y1, float x2, float y2, float x3, float y3)
{
    glBegin(GL_TRIANGLES);
    glVertex2f(x1, y1);
    glVertex2f(x2, y2);
    glVertex2f(x3, y3);
    glEnd();
}