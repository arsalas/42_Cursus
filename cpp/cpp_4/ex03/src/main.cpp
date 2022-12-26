#include "MateriaSource.hpp"
#include "Ice.hpp"
#include "Cure.hpp"
#include "Character.hpp"

int main()
{
	{
		IMateriaSource *src = new MateriaSource(); // Default MateriaSource constructor called
		src->learnMateria(new Ice());			   // Default ice from AMateria constructor called & Default Ice constructor called
		src->learnMateria(new Cure());			   // Default cure from AMateria constructor called & Default Cure constructor called
		ICharacter *me = new Character("me");	   // Default character me created
		AMateria *tmp;
		tmp = src->createMateria("ice");		// Default ice from AMateria constructor called & Copy constructor Ice ice called
		me->equip(tmp);							// Character me is equiped with ice
		tmp = src->createMateria("cure");		// Default cure from AMateria constructor called & Copy constructor cure from Cure called
		me->equip(tmp);							// Character me is equiped with cure
		ICharacter *bob = new Character("bob"); // Default character bob created
		me->use(0, *bob);						// Ice ice used on bob
		me->use(1, *bob);						// Cure cure used on bob
		delete bob;
		delete me;
		delete src;
	}

	std::cout << std::endl;
	std::cout << std::endl;

	{
		ICharacter *me = new Character("player_1");
		me->unequip(1);
		delete me;
	}

	std::cout << std::endl;
	std::cout << std::endl;

	{
		ICharacter *me = new Character("player_1");
		IMateriaSource *src = new MateriaSource();
		src->learnMateria(new Ice());
		AMateria *tmp;
		tmp = src->createMateria("ice");
		me->equip(tmp);
		me->unequip(0);
		me->unequip(1);
		delete src;
		delete me;
	}

	std::cout << std::endl;
	std::cout << std::endl;

	// Asignación (igualación)
	// Crear dos personas. Equipar a una. Igualarlas. Cerrar.
	{
		IMateriaSource *src = new MateriaSource();
		Character *p1 = new Character("Player_1");
		Character *p2 = new Character("Player_2");
		AMateria *tmp;
		src->learnMateria(new Ice());	 // Aprendemos la materia "ice"
		tmp = src->createMateria("ice"); // Creamos la materia "ice"
		p1->equip(tmp);					 // Equipamos el player_1
		p2[0] = p1[0];						 // Igualamos el player_2 al player_1
		p1->use(0, *p2);				 // Ice ice used on bob
		p2->use(0, *p1);				 // Ice ice used on bob
		delete p1;
		delete p2;
		delete src;
	}
	std::cout << std::endl;
	std::cout << std::endl;

	// Constructor copia
	{
		IMateriaSource *src = new MateriaSource();
		Character *p1 = new Character("Player_1");
		Character p2(p1[0]);
		AMateria *tmp;
		src->learnMateria(new Ice());
		tmp = src->createMateria("ice");
		p1->use(0, p2); // Ice ice used on bob
		p2.use(0, *p1); // Ice ice used on bob
		delete p1;
		delete src;
		delete tmp;
	}
	std::cout << std::endl;
	std::cout << std::endl;

	// Utilizar p1 sin haber creado una materia
	{
		ICharacter *p1 = new Character("Player_1");
		ICharacter *p2 = new Character("Player_2");
		p1->use(0, *p2); // Ice ice used on bob
		delete p1;
		delete p2;
	}
	return (0);
}