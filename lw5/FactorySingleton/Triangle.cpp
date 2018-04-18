#include "stdafx.h"
#include "Triangle.h"

CTriangle::CTriangle(const Point & point1, const Point & point2, const Point & point3)
	: CShape(TRIANGLE_TYPE)
	, m_point1(point1)
	, m_point2(point2)
	, m_point3(point3)
{
}

void CTriangle::Accept(IVisitor & visitor)
{
	visitor.Print(*this);
}

std::string CTriangle::CalculateArea()
{
	CBigNumber result = ((m_point1.x - m_point3.x) * (m_point2.y - m_point3.y) - (m_point2.x - m_point3.x) * (m_point1.y - m_point3.y)) / 2;
	return result.GetAbsValue();
}

std::string CTriangle::CalculatePerimeter()
{
	CBigNumber vector1Length = CalculateVectorLength(m_point1, m_point2);
	CBigNumber vector2Length = CalculateVectorLength(m_point2, m_point3);
	CBigNumber vector3Length = CalculateVectorLength(m_point1, m_point3);

	return (vector1Length + vector2Length + vector3Length).GetAbsValue();
}

CBigNumber CTriangle::CalculateVectorLength(const Point & left, const Point & right) const
{
	CBigNumber firstPow = CBigNumber().Pow(right.x - left.x, 2);
	CBigNumber secondPow = CBigNumber().Pow(right.y - left.y, 2);
	return  CBigNumber().Sqrt(firstPow + secondPow);
}
