#include "stdafx.h"
#include "Controller.h"

CController::CController(std::vector<std::unique_ptr<CShape>> & shapes)
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
		std::string type = elements[0];
		elements.erase(elements.begin());
		EraseEmpty(elements);
		
		return it->second(elements);
	}

	return false;
}

bool CController::CreateCircle(const std::vector<std::string> & args)
{
	auto & instance = CCircleCreator::GetInstance();
	std::unique_ptr<CShape> shape = instance.Create(args);
	m_shapes.push_back(move(shape));

	return true;
}

bool CController::CreateTriangle(const std::vector<std::string> & args)
{
	auto & instance = CTriangleCreator::GetInstance();
	std::unique_ptr<CShape> shape = instance.Create(args);
	m_shapes.push_back(move(shape));

	return true;
}

bool CController::CreateRectangle(const std::vector<std::string> & args)
{
	auto & instance = CRectangleCreator::GetInstance();
	std::unique_ptr<CShape> shape = instance.Create(args);
	m_shapes.push_back(move(shape));

	return true;
}

void CController::EraseEmpty(std::vector<std::string> & args)
{
	for (size_t i = 0; i < args.size(); )
	{
		if (args[i] == "")
		{
			args.erase(args.begin() + i);
		}
		else
		{
			++i;
		}
	}
}

void CController::PrintShapes(std::vector<std::unique_ptr<CShape>> & shapes, std::ofstream & output)
{
	if (!shapes.empty())
	{
		CVisitorPrinter printer(output);
		for (auto &shape : shapes)
		{
			try
			{
				shape->Accept(printer);
			}
			catch (std::exception & err)
			{
				output << err.what() << std::endl;
			}
		}
	}
	else
	{
		output << "You have not entered figures\n";
	}
}
