# AMateria class

Complete the definition and implement the necessary member functions.

Create the concrete Materias Ice and Cure.
Their type will be their name in lowercase ("ice" for Ice, etc...).
Their clone() method will, of course, return a new instance of the real Materia’s type.

Regarding the use(ICharacter&) method, it’ll display:
• Ice: "* shoots an ice bolt at NAME *"
• Cure: "* heals NAME’s wounds *"
(Of course, replace NAME by the name of the Character given as parameter.)


# Character class

The Character possesses an inventory of 4 Materia at most, empty at the start. He’ll equip the Materia in slots 0 to 3, in this order.
In case we try to equip a Materia in a full inventory, or use/unequip a nonexistent Materia, don’t do a thing.
The unequip method must NOT delete Materia!
The use(int, ICharacter&) method will have to use the Materia at the idx slot,
and pass target as parameter to the AMateria::use method.

Of course, you’ll have to be able to support ANY AMateria in a Character’s inventory.

Your Character must have a constructor taking its name as a parameter. Copy or assignation of a Character must be deep, of course. The old Materia of a Character must be deleted. Same upon the destruction of a Character .

Create the MateriaSource class, which will have to implement the following inter- face:

learnMateria must copy the Materia passed as a parameter, and store it in memory to be cloned later. Much in the same way as for Character , the Source can know at most 4 Materia, which are not necessarily unique.
createMateria(std::string const &) will return a new Materia, which will be a copy of the Materia (previously learned by the Source) which type equals the parameter. Returns 0 if the type is unknown.
In a nutshell, your Source must be able to learn "templates" of Materia and re-create them on demand. You’ll then be able to create a Materia without knowing its "real" type, just a string identifying it.

