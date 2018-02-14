#include "stdafx.h"
#include "Controller.h"

CController::CController(std::vector<std::shared_ptr<CShape>> & shapes)
	: m_shapes(shapes)
	, m_actionMap({
		{ CIRCLE_TYPE, std::bind(&CController::CreateCircle, this, std::placeholders::_1) },
		{ TRIANGLE_TYPE, std::bind(&CController::CreateTriangle, this, std::placeholders::_1) },
		{ RECTANGLE_TYPE, std::bind(&CController::CreateRectangle, this, std::placeholders::_1) }
})
{
}

bool CController::HandleCommand(std::string & line)
{
	std::vector<std::string> elements;
	boost::algorithm::split_regex(elements, line, boost::regex("([A-Za-z0-9]*)( *)=( *)|:( *)|;( *)|,( *)"));
	
	auto it = m_actionMap.find(elements[0]);
	if (it != m_actionMap.end())
	{
		std::vector<int> args = ConverteToInteger(elements);
		return it->second(args);
	}
	return false;
}

std::vector<int> CController::ConverteToInteger(const std::vector<std::string> & elements) const
{
	std::vector<int> args;
	for (size_t i = 1; i < elements.size(); ++i)
	{
		if (!elements[i].empty())
		{
			args.push_back(stoi(elements[i]));
		}
	}
	return args;
}

bool CController::CreateCircle(const std::vector<int> & args)
{
	Point center(args[0], args[1]);
	int radius = args[2];

	std::shared_ptr<CShape> shape = std::make_shared<CCircle>(center, radius);
	m_shapes.push_back(shape);
	return true;
}

bool CController::CreateTriangle(const std::vector<int> & args)
{
	Point point1(args[0], args[1]);
	Point point2(args[2], args[3]);
	Point point3(args[4], args[5]);

	std::shared_ptr<CShape> shape = std::make_shared<CTriangle>(point1, point2, point3);
	m_shapes.push_back(shape);
	return true;
}

bool CController::CreateRectangle(const std::vector<int> & args)
{
	Point point1(args[0], args[1]);
	Point point2(args[2], args[3]);

	std::shared_ptr<CShape> shape = std::make_shared<CRectangle>(point1, point2);
	m_shapes.push_back(shape);
	return true;
}

void CController::PrintShapes(const std::vector<std::shared_ptr<CShape>> & shapes, std::ofstream & output)
{
	if (!shapes.empty())
	{
		for (auto &shape : shapes)
		{
			output << shape->GetType() << ": P=" << shape->GetPerimeter() << "; S=" << shape->GetArea() << std::endl;
		}
	}
	else
	{
		output << "You have not entered figures\n";
	}
}