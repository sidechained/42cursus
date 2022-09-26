// Make a program called replace that takes a filename and two strings, let’s call them s1 and s2, that are NOT empty
// It will open the file, and write its contents to FILENAME.replace, after replacing every occurrence of s1 with s2.
// - All the member functions of the class std::string are allowed, except replace. Use them wisely!
// - handle errors
// - do not use the C file manipulation functions
// - turn in some test files to show your program works.
// std::string filename, std::string s1, sd::string s2

#include <iostream>
#include <fstream> // ifstream (+ ofstream?)
#include <sstream> // stringstream
//#include <string>

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

// only replaces first instance
// iterate until EOF/EOS
std::string replaceString(std::string fileString, std::string stringToFind, std::string replacementString)
{
	size_t pos;
	pos = fileString.find(stringToFind);
	fileString.replace(pos, stringToFind.length(), replacementString);
	return(fileString);
}

int main(int argc, char** argv)
{
	std::string filename;
	std::string fileString;
	std::string s1;
	std::string s2;
	size_t pos;

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
	fileString = replaceString(fileString, s1, s2);
	pos = filename.find(".txt");
	filename.replace(pos, 5, ".replace");
	writeToFile(filename, fileString);
	return (0);
}