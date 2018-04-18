#pragma once
#include "Shape.h"

class CRectangle final : public CShape
{
public:
	CRectangle(const Point & leftTop, const Point & rightBottom);
	~CRectangle() = default;

private:
	std::string CalculateArea() override;
	std::string CalculatePerimeter() override;

	Point m_leftTop;
	Point m_rightBottom;
};

