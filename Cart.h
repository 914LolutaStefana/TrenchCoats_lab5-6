#pragma once
#include "DynamicArray.h"
#include "TrenchCoat.h"
typedef Trench_Coat Product;
class Cart
{
private:
	DynamicArray <Product> products;
	DynamicArray <Product> cart;
	int current;
public:
	//constructor for cart
	Cart();
	//clears the vector of products
	void clear_products();
	//clears the shopping cart vector
	void clear_cart();
	//adds a coat to the product vector
	void add_coat_product(const Product& coat);
	//adds a coat to the cart vector
	void add_to_cart(const Product& coat);
	// starts iterating through the available products
	void start();
	// jumps to the next available product
	void next();
	// returns the current coat for the iterator
	Trench_Coat get_current_coat();
	// computes the total cost of the Coats in the shopping cart
	double total_price();
	// returns a vector containing all items from the shopping cart
	DynamicArray <Product> get_cart_items() const { return cart; }
	// returns a vector containing all available products
	DynamicArray <Product> get_available_items() const { return products; }
    // checks if the cart is empty
	bool isEmpty();
	// checks if there are no available products
	bool no_available_products();


};
