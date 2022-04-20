#include "Validator.h"
#include <string>

void coat_validator(const Trench_Coat& coat)
{
	if (coat.get_id().length() != 5)
		throw "Coat ID must have 5 characters.!";
	if (coat.get_size() > 60 || coat.get_size() < 30)
		throw "Size must be between 30 and 60!";
	if (coat.get_color().length() == 0)
		throw "The colour field cannot be empty!";
	if (coat.get_price() == 0)
		throw "Price must be greater than 0!";
	if (coat.get_quantity() == 0)
		throw "The quantity must be at least 1!";
	if (coat.get_link().length() == 0)
		throw "A link to the coat image must be given!";
}