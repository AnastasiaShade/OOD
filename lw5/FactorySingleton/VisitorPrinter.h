#pragma once
#include "IVisitor.h"
#include "Circle.h"
#include "Rectangle.h"
#include "Triangle.h"

class CVisitorPrinter : public IVisitor
{
public:
	CVisitorPrinter(std::ofstream & output);
	~CVisitorPrinter() = default;

	void Print(CCircle & circle) override;
	void Print(CRectangle & rectangle) override;
	void Print(CTriangle & triangle) override;

private:
	std::ofstream & m_output;

};

