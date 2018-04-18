#pragma once
#include "Shape.h"

class CShapeCreator
{
public:
	CShapeCreator();
	virtual ~CShapeCreator() = default;
	virtual std::unique_ptr<CShape> Create(const std::vector<std::string> & params) = 0;
};

