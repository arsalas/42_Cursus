
#include "Brain.hpp"

Brain::Brain(void) : _qIdeas(0)
{
	std::cout << "Brain construct" << std::endl;
}

Brain::~Brain(void)
{
	std::cout << "Brain destroy" << std::endl;
}

Brain::Brain(const Brain &brain) : _qIdeas(brain._qIdeas)
{
	for (size_t i = 0; i < numberIdeas; i++)
	{
		_ideas[i] = brain._ideas[i];
	}
	std::cout << "Brain copy constructor" << std::endl;
}

Brain &Brain::operator=(const Brain &brain)
{
	_qIdeas = brain._qIdeas;
	for (size_t i = 0; i < numberIdeas; i++)
	{
		_ideas[i] = brain._ideas[i];
	}

	return *this;
}

void Brain::setIdea(std::string str)
{
	if (_qIdeas == 100)
		return;
	_ideas[_qIdeas] = str;
	_qIdeas++;
}

std::string Brain::getIdea(unsigned int position) const
{
	if (position > 99)
		return NULL;
	return _ideas[position];
}
