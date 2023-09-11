#ifndef ATARGET_HPP
# define ATARGET_HPP
# include <iostream>

class ASpell;

class ATarget
{
	protected:
		std::string type;
	public:
		ATarget(std::string in_type);
		ATarget(const ATarget &a);
		ATarget &operator=(const ATarget &a);
		virtual ~ATarget();
		const std::string getType() const;
		virtual ATarget* clone() = 0;
		void getHitBySpell(const ASpell &a) const;
};

#endif