#include <iostream>
#include <fstream>

static bool	initialChecks(int argc, char **argv)
{
	if (argc != 4) {
		std::cerr << "USAGE: " << argv[0] << " <filename> <s1> <s2>" << std::endl;
		return 0;
	}
	if (std::string(argv[2]).empty()) {
		std::cerr << "Word to replace can't be empty !" << std::endl;
		return 0;
	}
	return 1;
}

static std::string	readContent(std::ifstream& input)
{
	std::string str;
	std::string fileContent;
	bool newLine = true;

	while (std::getline(input, str))
	{
		if (!newLine)
			fileContent += "\n";
		fileContent += str;
		newLine = false;
	}
	return fileContent;
}

int main(int argc, char **argv)
{
	if (!initialChecks(argc, argv))
		return 1;

	std::ifstream input(argv[1]);
	if (!input) {
		std::cerr << "File not found" << std::endl;
		return 1;
	}

	std::ofstream output(std::string(argv[1]) + ".replace");
	if (!output) {
		std::cerr << "Could not create output file" << std::endl;
		return 1;
	}

	std::string fileContent = readContent(input);
	
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
