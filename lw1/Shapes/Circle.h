#pragma once
#include "Shape.h"

class CCircle final : public CShape
{
public:
	CCircle(const Point & center, int radius);
	~CCircle() = default;

private:
	double CalculateArea() override;
	double CalculatePerimeter() override;

	Point m_center;
	int m_radius;
};

