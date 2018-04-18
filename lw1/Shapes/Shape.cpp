#include "stdafx.h"
#include "Shape.h"


CShape::CShape(const std::string & type)
	: m_type(type)
{
}

std::string CShape::GetType()
{
	return m_type;
}

double CShape::GetArea()
{
	return CalculateArea();
}

double CShape::GetPerimeter()
{
	return CalculatePerimeter();
}

