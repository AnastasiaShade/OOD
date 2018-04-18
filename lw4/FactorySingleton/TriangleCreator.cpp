#include "stdafx.h"
#include "TriangleCreator.h"

CTriangleCreator::CTriangleCreator()
{
}

CTriangleCreator & CTriangleCreator::GetInstance()
{
	static CTriangleCreator instance;
	return instance;
}

std::unique_ptr<CShape> CTriangleCreator::Create(const std::vector<std::string> & params)
{
	Point point1(CBigNumber(params.at(0)), CBigNumber(params.at(1)));
	Point point2(CBigNumber(params.at(2)), CBigNumber(params.at(3)));
	Point point3(CBigNumber(params.at(4)), CBigNumber(params.at(5)));
	std::unique_ptr<CShape> shape = std::make_unique<CTriangle>(CTriangle(point1, point2, point3));

	return move(shape);
}
