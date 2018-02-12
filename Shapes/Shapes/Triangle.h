#pragma once
#include "Shape.h"

class CTriangle final : public CShape
{
public:
	CTriangle(const Point & point1, const Point & point2, const Point &point3);
	~CTriangle() = default;

private:
	double CalculateArea() override;
	double CalculatePerimeter() override;
	double CalculateVectorLength(const Point & first, const Point & second) const;

	Point m_point1;
	Point m_point2;
	Point m_point3;
};

