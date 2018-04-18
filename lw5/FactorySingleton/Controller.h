#pragma once
#include "Shape.h"
#include "CircleCreator.h"
#include "RectangleCreator.h"
#include "TriangleCreator.h"
#include "VisitorPrinter.h"

class CController final
{
public:
	CController(std::vector<std::unique_ptr<CShape>> & shapes);
	bool HandleCommand(std::string & line);
	void PrintShapes(std::vector<std::unique_ptr<CShape>> & shapes, std::ofstream & output);

private:
	bool CreateCircle(const std::vector<std::string> & args);
	bool CreateTriangle(const std::vector<std::string> & args);
	bool CreateRectangle(const std::vector<std::string> & args);
	
	void EraseEmpty(std::vector<std::string> & args);

	typedef std::map<std::string, std::function<bool(std::vector<std::string> & args)>> ActionMap;

	std::vector<std::unique_ptr<CShape>> &m_shapes;
	const ActionMap m_actionMap;
};

