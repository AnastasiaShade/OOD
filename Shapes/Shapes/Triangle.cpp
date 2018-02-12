#include "stdafx.h"
#include "Triangle.h"


CTriangle::CTriangle(const Point & point1, const Point & point2, const Point &point3)
	: CShape(TRIANGLE_TYPE)
	, m_point1(point1)
	, m_point2(point2)
	, m_point3(point3)
{
}

double CTriangle::CalculateArea()
{
	return abs(((m_point1.x - m_point3.x) * (m_point2.y - m_point3.y) - (m_point2.x - m_point3.x) * (m_point1.y - m_point3.y)) / 2);
}

double CTriangle::CalculatePerimeter()
{
	double vector1Length = CalculateVectorLength(m_point1, m_point2);
	double vector2Length = CalculateVectorLength(m_point2, m_point3);
	double vector3Length = CalculateVectorLength(m_point1, m_point3);
	return (vector1Length + vector2Length + vector3Length);
}

double CTriangle::CalculateVectorLength(const Point & first, const Point & second) const
{
	return sqrt(pow((second.x - first.x), 2) + pow((second.y - first.y), 2));
}

