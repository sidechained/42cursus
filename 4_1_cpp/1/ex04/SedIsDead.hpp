#ifndef SedIsDead_HPP
# define SedIsDead_HPP

# include <iostream>
# include <fstream>
# include <sstream>

class SedIsDead
{
	private:
		std::string _infileString;
		std::string _strToFind;
	public:
		SedIsDead(std::string infileName, std::string strToFind, std::string substituteStr);
		bool errorHandling(std::string infileName, std::string strToFind, std::string substituteStr);
		void findAndReplace(std::string infileName, std::string strToFind, std::string substituteStr);
		std::string makeOutfileName(std::string infileName);
		std::string readFromFile(std::string infileName);
		void writeToFile(std::string infileName, std::string strToWrite);
		std::string replaceString(std::string infileString, std::string strToFind, std::string substituteStr);
};

#endif