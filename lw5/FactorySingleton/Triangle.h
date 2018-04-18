#pragma once
#include "Shape.h"

class CTriangle final : public CShape
{
public:
	CTriangle(const Point & point1, const Point & point2, const Point & point3);
	~CTriangle() = default;
	void Accept(IVisitor & visitor) override;

private:
	std::string CalculateArea() override;
	std::string CalculatePerimeter() override;
	CBigNumber CalculateVectorLength(const Point & left, const Point & right) const;

	Point m_point1;
	Point m_point2;
	Point m_point3;
};

