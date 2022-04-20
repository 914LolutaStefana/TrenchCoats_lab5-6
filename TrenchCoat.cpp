#include "TrenchCoat.h"
#include <shellapi.h>
#include <Windows.h>



Trench_Coat::Trench_Coat() : id(""), size(0), color(""), price(0), quantity(0), picture_link("") {}

Trench_Coat::Trench_Coat( std::string id,  int size,  std::string color,  double price,  int quantity,  std::string picture_link)
{
	this->id= id;
	this->size = size;
	this->color = color;
	this->price = price;
	this->quantity = quantity;
	this->picture_link = picture_link;
}
void Trench_Coat::show()
{
	ShellExecute(NULL, NULL, "chrome.exe", this->get_link().c_str(), NULL, SW_SHOWMAXIMIZED);
}


bool Trench_Coat::operator==(const Trench_Coat& other_coat) const
{
	if (this->id != other_coat.id)
		return false;
	if (this->size != other_coat.size)
		return false;
	if (this->color != other_coat.color)
		return false;
	if (this->price != other_coat.price)
		return false;
	if (this->quantity != other_coat.quantity)
		return false;
	if (this->picture_link != other_coat.picture_link)
		return false;
	return true;
}