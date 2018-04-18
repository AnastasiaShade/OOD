#include "stdafx.h"
#include "Rectangle.h"


CRectangle::CRectangle(const Point & leftTop, const Point & rightBottom)
	: CShape(RECTANGLE_TYPE)
	, m_leftTop(leftTop)
	, m_rightBottom(rightBottom)
{
}

double CRectangle::CalculateArea()
{
	return abs((m_rightBottom.x - m_leftTop.x) * (m_rightBottom.y - m_leftTop.y));
}

double CRectangle::CalculatePerimeter()
{
	return abs(2 * ((m_rightBottom.x - m_leftTop.x) + (m_rightBottom.y - m_leftTop.y)));
}
