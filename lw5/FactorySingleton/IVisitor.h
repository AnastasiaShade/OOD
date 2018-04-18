#pragma once
class CCircle;
class CRectangle;
class CTriangle;

class IVisitor
{
public:
	IVisitor();
	virtual ~IVisitor() = default;

	virtual void Print(CCircle & circle) = 0;
	virtual void Print(CRectangle & rectangle) = 0;
	virtual void Print(CTriangle & triangle) = 0;
};
