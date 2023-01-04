#include "Character.hpp"

/**
 * @brief Default Construct a new Character:: Character object
 *
 * @param name
 */
Character::Character(std::string name) : _name(name), _quantityMaterias(0), _trash(NULL), _quantityTrash(0)
{
	for (int i = 0; i < maxMaterias; i++)
	{
		_inventary[i] = NULL;
	}

	std::cout << "Construct Character" << std::endl;
}

/**
 * @brief Copy Construct a new Character:: Character object
 *
 * @param other
 */
Character::Character(const Character &other) : _name(other.getName()), _quantityMaterias(other._quantityMaterias)
{
	copyMaterias(other);
	copyTrash(other);
	std::cout << "Construct copy Character" << std::endl;
}

/**
 * @brief Retorna un objeto con los mismos valores que los del parametro other
 *
 * @param other
 * @return Character&
 */
Character &Character::operator=(Character &other)
{
	if (this == &other)
		return *this;
	_name = other._name;
	deleteInventary();
	copyMaterias(other);
	deleteTrash();
	copyTrash(other);
	return *this;
}

/**
 * @brief Destroy the Character:: Character object
 *
 */
Character::~Character()
{
	deleteInventary();
	deleteTrash();
	std::cout << "Destructor Character" << std::endl;
}

/**
 * @brief Obtiene el valor de la variable de clase _name
 *
 * @return std::string const&
 */
std::string const &Character::getName() const
{
	return _name;
}

/**
 * @brief Libera la memoria del inventario
 *
 */
void Character::deleteInventary()
{
	for (int i = 0; i < maxMaterias; i++)
	{
		if (_inventary[i])
			delete _inventary[i];
	}
	_quantityMaterias = 0;
}

/**
 * @brief Hace una copia de las materias de otro Character
 *
 * @param other
 */
void Character::copyMaterias(const Character &other)
{

	for (int i = 0; i < maxMaterias; i++)
	{
		if (other._inventary[i])
			_inventary[i] = other._inventary[i]->clone();
		else
			_inventary[i] = NULL;
	}
	_quantityMaterias = other._quantityMaterias;
}

/**
 * @brief Comprueba si el indice es un indice valido de materias
 *
 * @param idx
 * @return true
 * @return false
 */
bool Character::isMateriaIndexValid(int idx) const
{
	if (idx < 0 || idx >= maxMaterias)
		return false;
	return true;
}

/**
 * @brief Equipa una materia
 *
 * @param m
 */
void Character::equip(AMateria *m)
{
	if (_quantityMaterias >= maxMaterias)
		return;
	_inventary[_quantityMaterias] = m;
	_quantityMaterias++;
}

/**
 * @brief Desequipa una materia y la guarda en trash
 *
 * @param idx
 */
void Character::unequip(int idx)
{
	if (!isMateriaIndexValid(idx) || !_inventary[idx])
		return;
	pushTrash(_inventary[idx]);
	_inventary[idx] = NULL;
	_quantityMaterias--;
}

/**
 * @brief Usa una materia
 *
 * @param idx
 * @param target
 */
void Character::use(int idx, ICharacter &target)
{
	if (!isMateriaIndexValid(idx) || !_inventary[idx])
		return;
	_inventary[idx]->use(target);
}

/**
 * @brief Agrega una nueva materia a _trash
 *
 * @param materia
 */
void Character::pushTrash(AMateria *materia)
{
	AMateria **newTrash = new AMateria *[_quantityTrash + 1];
	for (int i = 0; i < _quantityTrash; i++)
	{
		newTrash[i] = _trash[i];
	}
	newTrash[_quantityTrash] = materia;
	if (_quantityTrash > 0)
		delete _trash;
	_trash = newTrash;
	_quantityTrash++;
}

/**
 * @brief Libera la memoria almacenada en _trash
 *
 */
void Character::deleteTrash()
{
	if (_quantityTrash == 0)
		return;
	for (int i = 0; i < _quantityTrash; i++)
	{
		delete _trash[i];
	}
	delete[] _trash;
}

/**
 * @brief Hace una copia de _trash a partir del _trash de otro Character
 *
 * @param other
 */
void Character::copyTrash(const Character &other)
{
	_quantityTrash = other._quantityTrash;
	if (other._quantityTrash == 0)
		return;
	_trash = new AMateria *[other._quantityTrash];
	for (int i = 0; i < other._quantityTrash; i++)
	{
		_trash[i] = other._trash[i]->clone();
	}
}