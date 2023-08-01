#include "ShrubberyCreationForm.hpp"

ShrubberyCreationAForm::ShrubberyCreationAForm(std::string target):
	AForm("ShrubberyCreationAForm", 145, 137), _target(target)
{
}

ShrubberyCreationAForm::~ShrubberyCreationAForm()
{
}

void ShrubberyCreationAForm::execute(Bureaucrat const &executor) const
{
	checkIfExecutable(executor);
	std::cout << _target << "_shrubbery file created in current directory." << std::endl;
	std::string filename = _target;
	filename.append("_shrubbery");
	std::ofstream myfile;
	myfile.open(filename.c_str());
	myfile << "                                              ." << std::endl;
	myfile << "                                   .         ;" << std::endl;
	myfile << "      .              .              ;%     ;;" << std::endl;
	myfile << "        ,           ,                :;%  %;" << std::endl;
	myfile << "         :         ;                   :;%;'     .," << std::endl;
	myfile << ",.        %;     %;            ;        %;'    ,;" << std::endl;
	myfile << "  ;       ;%;  %%;        ,     %;    ;%;    ,%'" << std::endl;
	myfile << "   %;       %;%;      ,  ;       %;  ;%;   ,%;'" << std::endl;
	myfile << "    ;%;      %;        ;%;        % ;%;  ,%;'" << std::endl;
	myfile << "     `%;.     ;%;     %;'         `;%%;.%;'" << std::endl;
	myfile << "      `:;%.    ;%%. %@;        %; ;@%;%'" << std::endl;
	myfile << "         `:%;.  :;bd%;          %;@%;'" << std::endl;
	myfile << "           `@%:.  :;%.         ;@@%;'" << std::endl;
	myfile << "             `@%.  `;@%.      ;@@%;" << std::endl;
	myfile << "               `@%%. `@%%    ;@@%;" << std::endl;
	myfile << "                 ;@%. :@%%  %@@%;" << std::endl;
	myfile << "                   %@bd%%%bd%%:;" << std::endl;
	myfile << "                     #@%%%%%:;;" << std::endl;
	myfile << "                     %@@%%%::;" << std::endl;
	myfile << "                     %@@@%(o);  . '" << std::endl;
	myfile << "                     %@@@o%;:(.,'" << std::endl;
	myfile << "                 `.. %@@@o%::;" << std::endl;
	myfile << "                    `)@@@o%::;" << std::endl;
	myfile << "                     %@@(o)::;" << std::endl;
	myfile << "                    .%@@@@%::;" << std::endl;
	myfile << "                    ;%@@@@%::;." << std::endl;
	myfile << "                   ;%@@@@%%:;;;." << std::endl;
	myfile << "               ...;%@@@@@%%:;;;;,..    Gilo97" << std::endl;
	myfile.close();
}