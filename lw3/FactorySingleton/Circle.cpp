#include "stdafx.h"
#include "Circle.h"

CCircle::CCircle(const Point & center, int radius)
	: CShape(CIRCLE_TYPE)
	, m_center(center)
	, m_radius(radius)
{
}

double CCircle::CalculateArea()
{
	return M_PI * pow(m_radius, 2);
}

double CCircle::CalculatePerimeter()
{
	return 2 * M_PI * m_radius;
}
