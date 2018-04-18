#include "stdafx.h"
#include "VisitorPrinter.h"


CVisitorPrinter::CVisitorPrinter(std::ofstream & output)
	:m_output(output)
{
}

void CVisitorPrinter::Print(CCircle & circle)
{
	m_output << circle.GetType() << ": P = " << circle.GetPerimeter() << ", S = " << circle.GetArea() << std::endl;
}

void CVisitorPrinter::Print(CRectangle & rectangle)
{
	m_output << rectangle.GetType() << ": P = " << rectangle.GetPerimeter() << ", S = " << rectangle.GetArea() << std::endl;
}

void CVisitorPrinter::Print(CTriangle & triangle)
{
	m_output << triangle.GetType() << ": P = " << triangle.GetPerimeter() << ", S = " << triangle.GetArea() << std::endl;
}
