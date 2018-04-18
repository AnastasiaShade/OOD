#include "stdafx.h"
#include "Controller.h"

int main(int argc, char *argv[])
{
	if (argc != 3)
	{
		std::cout << "invalid arguents count\n" << "usage: FactorySingleton.exe <input file name> <output file name>\n";
		return 1;
	}

	std::vector<std::unique_ptr<CShape>> shapes;
	std::ifstream input(argv[1]);
	std::ofstream output(argv[2]);
	CController controller(shapes);
	std::string line;

	while (getline(input, line))
	{
		if (!controller.HandleCommand(line))
		{
			output << "Unknown command!\n";
		}
	}
	controller.PrintShapes(shapes, output);

	return 0;
}
