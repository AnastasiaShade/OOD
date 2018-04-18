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

std::unique_ptr<CShape> CRectangleCreator::Create(const std::vector<std::string> & params)
{
	Point point1(CBigNumber(params.at(0)), CBigNumber(params.at(1)));
	Point point2(CBigNumber(params.at(2)), CBigNumber(params.at(3)));
	std::unique_ptr<CShape> shape = std::make_unique<CRectangle>(CRectangle(point1, point2));
	
	return move(shape);
}
