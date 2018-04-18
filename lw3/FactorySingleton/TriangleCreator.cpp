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

std::unique_ptr<CShape> CTriangleCreator::Create(const std::vector<int> & params)
{
	Point point1(params[0], params[1]);
	Point point2(params[2], params[3]);
	Point point3(params[4], params[5]);
	std::unique_ptr<CShape> shape = std::make_unique<CTriangle>(CTriangle(point1, point2, point3));

	return move(shape);
}
