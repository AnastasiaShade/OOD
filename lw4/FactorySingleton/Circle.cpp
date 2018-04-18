#include "stdafx.h"
#include "Circle.h"

CCircle::CCircle(const Point & center, CBigNumber & radius)
	: CShape(CIRCLE_TYPE)
	, m_center(center)
	, m_radius(radius)
{
}

std::string CCircle::CalculateArea()
{
	CBigNumber n1 = CBigNumber().Pow(m_radius, 2);
	CBigNumber n2 = CBigNumber(PI_VALUE) * n1;
	CBigNumber n3 = n2 / 100;

	return n3.GetAbsValue();
}

std::string CCircle::CalculatePerimeter()
{
	CBigNumber n1 = 2 * CBigNumber(PI_VALUE);
	CBigNumber n2 = n1 * m_radius;
	CBigNumber n3 = n2 / 100;

	return n3.GetAbsValue();
}
