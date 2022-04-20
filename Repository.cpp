#include "Repository.h"
#include "Validator.h"
#include <string>
#include <iostream>
using namespace std;
void Repository::add_entities(const Trench_Coat& coat) {
	this->coats = this->coats + coat;
}
void Repository::add_repository(const Trench_Coat& coat) {
	coat_validator(coat);
	this->coats = this->coats + coat;
}
void Repository::remove_repository(const std::string& id) {
	Trench_Coat coat = find_repository(id);
	if (coat.get_id().length() == 0)
		throw "This coat does not exists! Nothing was removed..";
	if (coat.get_quantity() > 0)
		throw "Can't remove this coat because there is at least one left in stock";
	int i = 0;
	bool removed = false;
	while (i < this->coats.getSize() && removed == false)
	{
		if (this->coats[i] == coat)
		{
			coats.remove(i);
			removed = true;
		}
		i++;
	}

}
void Repository::sell_coat_repository(const std::string& id) {
	Trench_Coat coat = find_repository(id);
	Trench_Coat new_coat{ coat.get_id(),coat.get_size(), coat.get_color(),coat.get_price(), coat.get_quantity() - 1,coat.get_link() };
	int i = 0;
	bool ok = false;
	while (i < this->coats.getSize() && ok== false)
	{
		if (this->coats[i] == coat)
		{
			coats.remove(i);
			ok = true;
		}
		i++;
	}
	coats.update(i, new_coat);
}
void Repository::update_repository(const std::string& id, const Trench_Coat& coat) {

	Trench_Coat c = find_repository(id);
	if (c.get_id().length() == 0)
		throw "This coat does not exists!";
	coat_validator(coat);
	int i = 0;
	bool updated = false;
	while (i < this->coats.getSize() && updated== false)
	{
		if (this->coats[i].get_id() == c.get_id())
		{
			coats.update(i, coat);
			updated = true;
		}
		i++;
	}
}
Trench_Coat  Repository::find_repository(const std::string& id) {
	for (int i = 0; i < this->coats.getSize(); i++) {
		Trench_Coat coat = coats[i];
		if (coat.get_id() == id)
			return coat;
	}
	return Trench_Coat{};//returns an empty list if the coat with the given id was not found
}
DynamicArray <Trench_Coat>  Repository::get_coat_by_size(const int& size)
{
	DynamicArray <Trench_Coat> coats;
	int i = 0;
	for (i = 0; i < this->coats.getSize(); i++)
	{
		Trench_Coat new_coat = this->coats[i];
		if (new_coat.get_size() == size)
			coats.add(new_coat);
	}
	return coats;
}