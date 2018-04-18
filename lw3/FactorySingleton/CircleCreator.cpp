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

std::unique_ptr<CShape> CCircleCreator::Create(const std::vector<int> & params)
{
	Point center(params[0], params[1]);
	int radius = params[2];
	std::unique_ptr<CShape> shape = std::make_unique<CCircle>(CCircle(center, radius));

	return move(shape);
}
