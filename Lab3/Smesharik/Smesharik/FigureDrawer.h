#include "stdafx.h"

class FigureDrawer
{
public:
	static void DrawEllipse(float xCenter, float yCenter, float rx, float ry);
	static void DrawRectangle(float xTopLeft, float yTopLeft, float width, float height, float angle);
	static void DrawTriangle(float x1, float y1, float x2, float y2, float x3, float y3);
	static void DrawHalfEllipse(float xCenter, float yCenter, float rx, float ry, bool isUpperHalf);
	static void DrawHalfEllipseOutline(float xCenter, float yCenter, float rx, float ry, bool isUpperHalf, float lineWidth);
};