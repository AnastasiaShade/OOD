#pragma once
#include "ShapeCreator.h"
#include "Rectangle.h"
#include "BigNumber.h"

class CRectangleCreator final : public CShapeCreator
{
public:
	static CRectangleCreator & GetInstance();
	std::unique_ptr<CShape> Create(const std::vector<std::string> & params) override;

protected:
	CRectangleCreator();
	~CRectangleCreator() = default;

private:
	CRectangleCreator(const CRectangleCreator &) = delete;
	CRectangleCreator & operator=(const CRectangleCreator &) = delete;
};
