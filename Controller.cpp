#include "Controller.h"


/// ---------- Repository ---------- ///

void Controller::add_coat_to_repository(const std::string& id, const int& size, const std::string& color, const double& price, const int& quantity, const std::string& link)
{
	Trench_Coat coat{ id, size, color, price, quantity, link };
	this->repository.add_repository(coat);
}

void Controller::remove_coat_from_repository(const std::string& id)
{
	this->repository.remove_repository(id);
}

void Controller::update_coat_to_repository(const std::string& id, const double& new_price, const int& new_quantity, const std::string& new_link)
{
	Trench_Coat Coat = this->repository.find_repository(id);
	Trench_Coat new_coat{ id, Coat.get_size(), Coat.get_color(), new_price, new_quantity, new_link };
	this->repository.update_repository(id, new_coat);
}

/// ---------- Shopping Cart ---------- ///

void Controller::clear_products_from_cart()
{
	this->cart.clear_cart();
}

void Controller::add_available_coats_to_cart()
{
	
	
	DynamicArray<Trench_Coat> coats = get_all_coats();

	for (int i = 0; i < coats.getSize(); i++) {
		this->cart.add_coat_product(coats[i]);
	}
	
}

void Controller::add_coats_given_size(const int& size)
{
	
	DynamicArray<Trench_Coat> coats = get_all_coats();
	for (int i = 0; i < coats.getSize(); i++) {
		if (coats[i].get_size() == size)
			this->cart.add_coat_product(coats[i]);
	}

}

void Controller::add_coat_to_cart(const Trench_Coat& c)
{
	this->cart.add_to_cart(c);
}

void Controller::start_shopping()
{
	this->cart.start();
}

void Controller::next_coat_shopping()
{
	this->cart.next();
}

void Controller::buy_products()
{
	DynamicArray<Trench_Coat> coats_in_cart = this->cart.get_cart_items();
	for (int i = 0; i < coats_in_cart.getSize(); i++) {
		this->repository.sell_coat_repository(coats_in_cart[i].get_id());
	}
	this->erase_cart();
	this->cart.clear_products();
}

void Controller::erase_cart()
{
	this->cart.clear_cart();
}