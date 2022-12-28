#include <fstream>
#include "ShrubberyCreationForm.hpp"
#include "AForm.hpp"
#include "Bureaucrat.hpp"

// Constructors
ShrubberyCreationForm::ShrubberyCreationForm(std::string target) : AForm("SCF_" + target, 145, 137), _target(target)
{
	std::cout << "\e[0;33mFields Constructor called of ShrubberyCreationForm\e[0m" << std::endl;
}

ShrubberyCreationForm::ShrubberyCreationForm(const ShrubberyCreationForm &copy) : AForm(copy.getName(), copy.getGradeSign(), copy.getGradeExecute()), _target(copy._target)
{
	std::cout << "\e[0;33mCopy Constructor called of ShrubberyCreationForm\e[0m" << std::endl;
}

// Destructor
ShrubberyCreationForm::~ShrubberyCreationForm() {}

// Operators
ShrubberyCreationForm &ShrubberyCreationForm::operator=(const ShrubberyCreationForm &assign)
{
	_target = assign._target;
	return *this;
}

// Getters / Setters
const std::string ShrubberyCreationForm::getTarget() const
{
	return _target;
}


// Methods
void ShrubberyCreationForm::execute(const Bureaucrat &executor) const
{
	checkExecute(executor.getGrade());
	std::ofstream file;
	file.open((_target + "_shrubbery").c_str());
	file << " \n\
	oxoxoo    ooxoo\n\
  ooxoxo oo  oxoxooo\n\
 oooo xxoxoo ooo ooox\n\
 oxo o oxoxo  xoxxoxo\n\
  oxo xooxoooo o ooo\n\
    ooo\\oo\\  /o/o\n\
        \\  \\/ /\n\
         |   /\n\
         |  |\n\
         | D|\n\
         |  |\n\
         |  |\n\
  ______/____\\____\n";
	file.flush();
	file.close();
}

std::ostream &operator<<(std::ostream &out, const ShrubberyCreationForm &form)
{
	out << form.getName();
	out << ": [GradeSign: " << form.getGradeSign();
	out << ", GradeExec: " << form.getGradeExecute();
	out << ", Target: " << form.getTarget();
	out << ", Signed: " << (form.getIsSigned() ? "Yes]" : "No]");
	return out;
}