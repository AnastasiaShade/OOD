#include "stdafx.h"
#include "BigNumber.h"

static const std::map<std::string, int> ACTION_MAP = { {"+", 0}, {"-", 1}, {"*", 2}, {"/", 3} };

std::string MakeOperation(const std::vector<std::string> & expParts)
{
	CBigNumber result;

	switch (ACTION_MAP.at(expParts[1]))
	{
	case 0: 
		result = CBigNumber(expParts[0]) + CBigNumber(expParts[2]);
		break;
	case 1: 
		result = CBigNumber(expParts[0]) - CBigNumber(expParts[2]);
		break;
	case 2: 
		result = CBigNumber(expParts[0]) * CBigNumber(expParts[2]);
		break;
	case 3: 
		result = CBigNumber(expParts[0]) / CBigNumber(expParts[2]);
		break;
	default:
		return "Unknown operator";
	}

	return expParts[0] + " " + expParts[1] + " " + expParts[2] + " = " + result.GetValue();
}

int main(int argc, char *argv[])
{
	
	if (argc != 3)
	{
		std::cout << "invalid arguents count\nusage: BigNumbers.exe <input file name> <output file name>\n";
		return 1;
	}

	std::ifstream input(argv[1]);
	std::ofstream output(argv[2]);
	std::vector<std::string> expParts;
	std::string line;

	while (getline(input, line))
	{
		try
		{
			boost::algorithm::split(expParts, line, boost::is_any_of(" "));
			output << MakeOperation(expParts) << std::endl;
		}
		catch (std::invalid_argument & err)
		{
			output << err.what() << std::endl;
		}
	}	
	
    return 0;
}

