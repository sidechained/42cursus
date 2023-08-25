#ifndef TARGETGENERATOR_HPP
# define TARGETGENERATOR_HPP

# include <map>
# include "ATarget.hpp"

class TargetGenerator
{
	private:
		TargetGenerator(TargetGenerator &obj);
		TargetGenerator& operator=(TargetGenerator &obj);
		std::map < std::string, ATarget*> target;
	public:
		TargetGenerator();
		~TargetGenerator();
		void learnTargetType(ATarget* t);
		void forgetTargetType(std::string const &t);
		ATarget* createTarget(std::string const &t);
};

#endif