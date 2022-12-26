
#include "Brain.hpp"

Brain::Brain(void)
{
	std::cout << "Brain construct" << std::endl;
}

Brain::~Brain(void)
{
	std::cout << "Brain destroy" << std::endl;
}

Brain::Brain(const Brain &brain)
{
	*this = brain;
}

Brain &Brain::operator=(const Brain &brain)
{
	for (size_t i = 0; i < numberIdeas; i++)
	{
		_ideas[i] = brain._ideas[i];
	}

	return *this;
}
