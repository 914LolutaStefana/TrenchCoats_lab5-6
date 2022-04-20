#pragma once
#include "TrenchCoat.h"
#include "DynamicArray.h"
class Repository
{
private:
	DynamicArray <Trench_Coat> coats;
public:
	//default constructor
	Repository(){}
	//initial add for the 10 starting entities
	void add_entities(const Trench_Coat &coat);
	//adds a coat to the repo
	void add_repository(const Trench_Coat& coat);
	//removes a coat by id
	void remove_repository(const std::string& id);
	void sell_coat_repository(const std::string& id);
	//updates a coat by id
	void update_repository(const std::string& id, const Trench_Coat& coat);
	//finds a coat by id
	Trench_Coat find_repository(const std::string& id);
	//gets a coat having a given size
	DynamicArray <Trench_Coat> get_coat_by_size(const int &size);
	//gets all the coats
	DynamicArray <Trench_Coat> get_coats() const { return coats; }

};
