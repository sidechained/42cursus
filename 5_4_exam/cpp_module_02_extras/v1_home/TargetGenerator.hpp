#ifndef TARGETGENERATOR_HPP
# define TARGETGENERATOR_HPP

# include <string>
# include <map>
# include "ATarget.hpp"

class TargetGenerator
{
	private:
		TargetGenerator(TargetGenerator &);
		TargetGenerator& operator=(TargetGenerator &);
		std::map < std::string, ATarget * > tbook;
	public:
		TargetGenerator();
		~TargetGenerator();
		void learnTargetType(ATarget*);
		void forgetTargetType(std::string const &);
		ATarget* createTarget(std::string const &);	
};

#endif
