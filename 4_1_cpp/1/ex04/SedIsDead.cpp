#include "SedIsDead.hpp"

SedIsDead::SedIsDead(std::string infileName, std::string strToFind, std::string substituteStr)
{
	if (errorHandling(infileName, strToFind, substituteStr))
		return ;
	findAndReplace(infileName, strToFind, substituteStr);
}

bool SedIsDead::errorHandling(std::string infileName, std::string strToFind, std::string substituteStr)
{
	if (infileName.empty() || strToFind.empty() || substituteStr.empty())
	{
		std::cout << "ERROR: Empty string provided as argument" << std::endl;
		return (true);
	}
	return (false);
}

void SedIsDead::findAndReplace(std::string infileName, std::string strToFind, std::string substituteStr)
{		
	int num_occurrences = 0;
	std::string::size_type pos = 0;
	std::string infileString = readFromFile(infileName);
	std::string outfileString = infileString;
	std::string outfileName = makeOutfileName(infileName);

	if (infileString.empty())
		return;
	while ((pos = infileString.find(strToFind, pos)) != std::string::npos) {
		++num_occurrences;
		pos += strToFind.length();
	}
	for (int i = 0; i < num_occurrences; i++)
		outfileString = replaceString(outfileString, strToFind, substituteStr);
	writeToFile(outfileName, outfileString);
}

std::string SedIsDead::makeOutfileName(std::string infileName)
{
	size_t pos;

	pos = infileName.find(".txt");
	infileName.erase(pos, 4);
	infileName.insert(pos, ".replace");
	return (infileName);
}

std::string SedIsDead::readFromFile(std::string infileName)
{
	std::ifstream t(infileName.c_str());
	std::stringstream buffer;

    if (!t.is_open()) {
        std::cerr << "ERROR: File \"" << infileName << "\" could not be opened" << std::endl;
        return "";
    }
	buffer << t.rdbuf();
	return(buffer.str());
}

void SedIsDead::writeToFile(std::string outfileName, std::string strToWrite)
{
	std::ofstream outputFile;

	outputFile.open(outfileName.c_str());
	outputFile << strToWrite;
	outputFile.close();
}

std::string SedIsDead::replaceString(std::string infileString, std::string strToFind, std::string substituteStr)
{
	size_t pos;

	pos = infileString.find(strToFind);
	infileString.erase(pos, strToFind.length());
	infileString.insert(pos, substituteStr);
	return(infileString);
}