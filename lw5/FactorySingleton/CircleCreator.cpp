#include "stdafx.h"
#include "CircleCreator.h"

CCircleCreator::CCircleCreator()
{
}

CCircleCreator & CCircleCreator::GetInstance()
{
	static CCircleCreator instance;
	return instance;
}

std::unique_ptr<CShape> CCircleCreator::Create(const std::vector<std::string> & params)
{
	Point center(CBigNumber(params.at(0)), CBigNumber(params.at(1)));
	CBigNumber radius = CBigNumber(params.at(2));
	std::unique_ptr<CShape> shape = std::make_unique<CCircle>(CCircle(center, radius));

	return move(shape);
}
