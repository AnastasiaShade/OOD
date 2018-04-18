#pragma once
#include "Shape.h"
#include "Circle.h"
#include "Rectangle.h"
#include "Triangle.h"

class CController final
{
public:
	CController(std::vector<std::shared_ptr<CShape>> &shapes);
	bool HandleCommand(std::string & line);
	void PrintShapes(const std::vector<std::shared_ptr<CShape>> & shapes, std::ofstream & output);

private:
	bool CreateCircle(const std::vector<int> &args);
	bool CreateTriangle(const std::vector<int> &args);
	bool CreateRectangle(const std::vector<int> &args);
	std::vector<int> CController::ConverteToInteger(const std::vector<std::string> & args) const;

	typedef std::map<std::string, std::function<bool(std::vector<int> & args)>> ActionMap;

	std::vector<std::shared_ptr<CShape>> &m_shapes;
	const ActionMap m_actionMap;
};

