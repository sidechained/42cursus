#include <iostream> // cout, string
#include <fstream> // ifstream, ofstream
#include <sstream> // stringstream

std::string readFromFile(std::string filename)
{
	std::ifstream t(filename);
	std::stringstream buffer;
	buffer << t.rdbuf();
	return(buffer.str());
}

void writeToFile(std::string filename, std::string contentsToWrite)
{
	std::ofstream outputFile;
	outputFile.open (filename);
	outputFile << contentsToWrite;
	outputFile.close();
}

int countOccurences(std::string fileString, std::string stringToFind)
{
	int occurrences;
	occurrences = 0;
	std::string::size_type pos = 0;
	while ((pos = fileString.find(stringToFind, pos )) != std::string::npos)
	{
		++occurrences;
		pos += stringToFind.length();
	}
	return(occurrences);
}

// only replaces first instance
std::string replaceString(std::string fileString, std::string stringToFind, std::string replacementString)
{
	size_t pos;
	pos = fileString.find(stringToFind);
	fileString.erase(pos, stringToFind.length());	\
	fileString.insert(pos, replacementString);
	return(fileString);
}

int main(int argc, char** argv)
{
	std::string filename;
	std::string fileString;
	std::string s1;
	std::string s2;
	size_t pos;
	int occurrences;
	int i;

	if (argc != 4)
	{
		std::cout << "ERROR: wrong number of arguments" << std::endl;
		return(0);
	}
	filename = argv[1];
	s1 = argv[2];
	s2 = argv[3];
	if ((s1 == "") || (s2 == ""))
	{
		std::cout << "ERROR: string empty" << std::endl;
		return(0);
	}	
	fileString = readFromFile(filename);
	occurrences = countOccurences(fileString, s1);
	i = 0;
	while(i < occurrences)
	{
		fileString = replaceString(fileString, s1, s2);
		i++;
	}
	pos = filename.find(".txt");
	filename.erase(pos, 4);
	filename.insert(pos, ".replace"); // replace use of replace!
	writeToFile(filename, fileString);
	return (0);
}