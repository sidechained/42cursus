// "DEBUG" level:
// Messages in this level contain extensive contextual information. They are mostly used for problem diagnosis.
// Example: 

// "INFO" level:
// These messages contain some contextual information to help trace execution in a production environment.
// Example: 

// "WARNING" level:
// A warning message indicates a potential problem in the system. The system is able to handle the problem by itself or to proceed with this problem anyway.
// Example:

// "ERROR" level:
// An error message indicates a serious problem in the system. The problem is usually non-recoverable and requires manual intervention.
// Example: 

#include "Karen.hpp"

int	main()
{
	Karen karen;
	karen.complain("DEBUG");
	karen.complain("INFO");
	karen.complain("WARNING");
	karen.complain("ERROR");
	karen.complain("NOIDEA");
}