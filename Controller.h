#pragma once
#include "Repository.h"
#include "Cart.h"

class Controller
{
private:
	Repository repository;
	Cart cart;

public:
	// default constructor for the controller
	Controller(const Repository& r) : repository(r) {}
	// return the repository and shopping cart of the controller
	Repository get_repository() const { return repository; }
	Cart get_cart() const { return cart; }
	/// ---------- Repository ---------- ///
	//	Adds an new coat to the repository
	void add_coat_to_repository(const std::string& id, const int& size, const std::string& color, const double& price, const int& quantity, const std::string& link);
	//	Removes a coat from the repository
	void remove_coat_from_repository(const std::string& id);
	//	Updates a coat's information
	void update_coat_to_repository(const std::string& id, const double& new_price, const int& new_quantity, const std::string& new_link);
	DynamicArray<Trench_Coat> get_all_coats() const { return repository.get_coats(); }
	/// ---------- Shopping Cart ---------- ///
	//	Clears the products dynamic vector from cart
	void clear_products_from_cart();
	//	Adds all coats to the available products in cart
	void add_available_coats_to_cart();
	//	Add all coats having a given size to the available product cart
	void add_coats_given_size(const int& size);
	//	Add a given coat to the shopping cart
	void add_coat_to_cart(const Trench_Coat& c);
	//	Starts iterating through the available products
	void start_shopping();
	//	Jumps to the next product in list
	void next_coat_shopping();
	//	Buy a product. For each item in the shopping cart removes one item from the repository
	//	Clears shopping cart and available products
	void buy_products();
	//	Clears shopping cart
	void erase_cart();
};

