#include <iostream>
#include <cctype>
#include <string>
#include <fstream>

int main(int ac, char **argv)
{
	if (ac != 4)
		return 1;
	std::string	filename = argv[1];
	std::string	s1 = argv[2];
	std::string	s2 = argv[3];
	std::string	line;
	std::ifstream inputFile(filename.c_str());

	if (!inputFile)
		return (std::cerr << "inputfile fail", 1);
	if (s1.empty())
		return (1);
	std::size_t		pos = 0;
	std::size_t		len = 0;
	std::size_t		s1Len = s1.length();
	std::ofstream	outputFile((filename + ".replace").c_str());
	if (!outputFile || !outputFile.is_open())
		return (std::cerr << "outputfile fail", 1);
	std::string		res;
	while (std::getline(inputFile, line))
	{
		res.clear();
		pos = line.find(s1);
		while (pos != std::string::npos)
		{
			res += line.substr(0, pos);
			res += s2;
			len = line.length();
			line = line.substr(pos + s1Len, len - (pos + s1Len));
			pos = line.find(s1);
		}
		res += line;
		outputFile << res << std::endl;
	}
	return (0);
}
