#include <iostream>

#include "Bureaucrat.hpp"
#include "AForm.hpp"
#include "Intern.hpp"
#include "PresidentialPardonForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "ShrubberyCreationForm.hpp"

void testForm(AForm& f)
{
	Bureaucrat b1("John_5", 5);
	Bureaucrat b2("John_6", 6);
	Bureaucrat b3("John_25", 25);
	Bureaucrat b4("John_26", 26);
	Bureaucrat b5("John_45", 45);
	Bureaucrat b6("John_46", 46);
	Bureaucrat b7("John_72", 72);
	Bureaucrat b8("John_73", 73);
	Bureaucrat b9("John_137", 137);
	Bureaucrat b10("John_138", 138);
	Bureaucrat b11("John_145", 145);
	Bureaucrat b12("John_146", 146);

	std::cout << f << std::endl;
	std::cout << b1 << std::endl;
	std::cout << b2 << std::endl;
	std::cout << b3 << std::endl;
	std::cout << b4 << std::endl;
	std::cout << b5 << std::endl;
	std::cout << b6 << std::endl;
	std::cout << b7 << std::endl;
	std::cout << b8 << std::endl;
	std::cout << b9 << std::endl;
	std::cout << b10 << std::endl;
	std::cout << b11 << std::endl;
	std::cout << b12 << std::endl;

	std::cout << std::endl;

	// EXEC NOT SIGNED
	b12.executeForm(f);
	b11.executeForm(f);
	b10.executeForm(f);
	b9.executeForm(f);
	b8.executeForm(f);
	b7.executeForm(f);
	b6.executeForm(f);
	b5.executeForm(f);
	b4.executeForm(f);
	b3.executeForm(f);
	b2.executeForm(f);
	b1.executeForm(f);

	std::cout << std::endl;

	// SIGN
	b12.signForm(f);
	b11.signForm(f);
	b10.signForm(f);
	b9.signForm(f);
	b8.signForm(f);
	b7.signForm(f);
	b6.signForm(f);
	b5.signForm(f);
	b4.signForm(f);
	b3.signForm(f);
	b2.signForm(f);
	b1.signForm(f);

	std::cout << std::endl;

	// EXEC SIGNED
	b12.executeForm(f);
	b11.executeForm(f);
	b10.executeForm(f);
	b9.executeForm(f);
	b8.executeForm(f);
	b7.executeForm(f);
	b6.executeForm(f);
	b5.executeForm(f);
	b4.executeForm(f);
	b3.executeForm(f);
	b2.executeForm(f);
	b1.executeForm(f);

}

void testMake(std::string form, std::string target)
{
	std::cout << std::endl;
	AForm* f = Intern().makeForm(form, target);
	if (f)
	{
		testForm(dynamic_cast<AForm&>(*f));
		delete f;
	}
}

int main()
{
	testMake("shruberry creation", "42");
	testMake("robotomy request", "Drop");
	testMake("presidential pardon", "Drop");
	testMake("Unknown", "Drop");

	return 0;
}