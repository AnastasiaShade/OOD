#pragma once

struct Point
{
	Point() {};
	Point(int _x, int _y)
	{
		x = _x;
		y = _y;
	};

	int x;
	int y;
};

class CShape
{
public:
	CShape(const std::string & type);
	virtual ~CShape() = default;
	double GetArea();
	double GetPerimeter();
	std::string GetType();

protected:
	virtual double CalculateArea() = 0;
	virtual double CalculatePerimeter() = 0;

private:
	std::string m_type;
	double m_area;
	double m_perimeter;
};

