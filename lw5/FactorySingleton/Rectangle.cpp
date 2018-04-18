#include "stdafx.h"
#include "Rectangle.h"


CRectangle::CRectangle(const Point & leftTop, const Point & rightBottom)
	: CShape(RECTANGLE_TYPE)
	, m_leftTop(leftTop)
	, m_rightBottom(rightBottom)
{
}

void CRectangle::Accept(IVisitor & visitor)
{
	visitor.Print(*this);
}

std::string CRectangle::CalculateArea()
{
	CBigNumber result = (m_rightBottom.x - m_leftTop.x) * (m_rightBottom.y - m_leftTop.y);
	return result.GetAbsValue();
}

std::string CRectangle::CalculatePerimeter()
{
	CBigNumber result = 2 * ((m_rightBottom.x - m_leftTop.x) + (m_rightBottom.y - m_leftTop.y));
	return result.GetAbsValue();
}
