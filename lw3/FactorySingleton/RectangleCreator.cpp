#include "stdafx.h"
#include "RectangleCreator.h"

CRectangleCreator::CRectangleCreator()
{
}

CRectangleCreator & CRectangleCreator::GetInstance()
{
	static CRectangleCreator instance;
	return instance;
}

std::unique_ptr<CShape> CRectangleCreator::Create(const std::vector<int> & params)
{
	Point point1(params[0], params[1]);
	Point point2(params[2], params[3]);
	std::unique_ptr<CShape> shape = std::make_unique<CRectangle>(CRectangle(point1, point2));
	
	return move(shape);
}
