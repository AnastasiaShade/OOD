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

std::string CShape::GetArea()
{
	return CalculateArea();
}

std::string CShape::GetPerimeter()
{
	return CalculatePerimeter();
}

