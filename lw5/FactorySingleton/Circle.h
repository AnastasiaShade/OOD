#pragma once
#include "Shape.h"
#include "BigNumber.h"

class CCircle final : public CShape
{
public:
	CCircle(const Point & center, CBigNumber & radius);
	~CCircle() = default;
	void Accept(IVisitor & visitor) override;

private:
	std::string CalculateArea() override;
	std::string CalculatePerimeter() override;

	Point m_center;
	CBigNumber m_radius;
};

