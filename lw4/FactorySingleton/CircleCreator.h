#pragma once
#include "ShapeCreator.h"
#include "Circle.h"
#include "BigNumber.h"

class CCircleCreator final : public CShapeCreator
{
public:
	static CCircleCreator & GetInstance();
	std::unique_ptr<CShape> Create(const std::vector<std::string> & params) override;

protected:
	CCircleCreator();
	~CCircleCreator() = default;

private:
	CCircleCreator(const CCircleCreator &) = delete;
	CCircleCreator & operator=(const CCircleCreator &) = delete;
};
