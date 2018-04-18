#pragma once
#include "ShapeCreator.h"

class CTriangleCreator final : public CShapeCreator
{
public:
	static CTriangleCreator & GetInstance();
	std::unique_ptr<CShape> Create(const std::vector<int> & params) override;

protected:
	CTriangleCreator();
	~CTriangleCreator() = default;

private:
	CTriangleCreator(const CTriangleCreator &) = delete;
	CTriangleCreator & operator=(const CTriangleCreator &) = delete;
};

