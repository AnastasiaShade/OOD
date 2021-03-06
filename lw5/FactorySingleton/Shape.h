#pragma once
#include "BigNumber.h"
#include "IVisitor.h"

struct Point
{
	Point(CBigNumber & _x, CBigNumber & _y)
	{
		x = _x;
		y = _y;
	};

	CBigNumber x;
	CBigNumber y;
};

class CShape
{
public:
	CShape(const std::string & type);
	virtual ~CShape() = default;
	std::string GetArea();
	std::string GetPerimeter();
	std::string GetType();
	virtual void Accept(IVisitor & visitor) = 0;

protected:
	virtual std::string CalculateArea() = 0;
	virtual std::string CalculatePerimeter() = 0;

private:
	std::string m_type;
};

