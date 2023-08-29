#ifndef ATARGET_HPP
# define ATARGET_HPP

# include <iostream>

# include "ASpell.hpp"

class ASpell;

class ATarget
{
	protected:
		std::string type;
		
	public:
		ATarget();
		ATarget(std::string);
		ATarget(ATarget &);
		ATarget& operator=(ATarget &);
		~ATarget();
		const std::string getType() const;
		virtual ATarget* clone() const = 0;
		void getHitBySpell(const ASpell &) const;
};

#endif
