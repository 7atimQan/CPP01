#include <iostream>
#include <fstream>

int main(int argc, char **argv)
{
	(void)argv;
	if (argc != 4) {
		std::cerr << "USAGE: " << argv[0] << " <filename> <s1> <s2>" << std::endl;
		return 1;
	}
	if (std::string(argv[2]).empty()) {
		std::cerr << "Empty string in arguments !" << std::endl;
		return 1;
	}
	std::string str;
	std::ifstream input(argv[1]);
	std::ofstream output(std::string(argv[1]) + ".replace");
	if (!input) {
		std::cerr << "File not found" << std::endl;
		return 1;
	}

	std::string fileContent;
	bool newLine = true;

	while (std::getline(input, str))
	{
		if (!newLine)
			fileContent += "\n";
		fileContent += str;
		newLine = false;
	}

	size_t pos = fileContent.find(argv[2]);
	while (pos != std::string::npos)
	{
		fileContent.erase(pos, std::string(argv[2]).length());
		fileContent.insert(pos, argv[3]);
		pos += std::string(argv[3]).length();
		pos = fileContent.find(argv[2], pos);
	}
	output << fileContent;
	return 0;
}