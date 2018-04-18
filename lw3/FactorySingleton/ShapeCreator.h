#pragma once
#include "Shape.h"
#include "Triangle.h"

class CShapeCreator
{
public:
	CShapeCreator();
	virtual ~CShapeCreator() = default;
	virtual std::unique_ptr<CShape> Create(const std::vector<int> & params) = 0;
};

