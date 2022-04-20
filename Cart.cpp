#include "Cart.h"

Cart::Cart()
{
	this->current = 0;
}

void Cart::clear_products()
{
	int i = 0;
	for(i=0;i<=products.getSize();i++)
		this->products.remove(i);

}

void Cart::clear_cart()
{
	int i = 0;
	for (i = 0; i < cart.getSize(); i++)
		this->cart.remove(i);
}

void Cart::add_coat_product(const Product& coat)
{
	this->products.add(coat);
}

void Cart::add_to_cart(const Product& coat)
{
	this->cart.add(coat);
}

void Cart::start()
{
	//if (this->products.getSize()==0)
		//return;
	this->current = 0;
	Trench_Coat current = this->get_current_coat();
	current.show();
}

void Cart::next()
{
	//if (this->products.getSize() == 0)
		//return;
	this->current++;
	Trench_Coat current = this->get_current_coat();
	current.show();
}

Trench_Coat Cart::get_current_coat()
{
	if (this->current == this->products.getSize())
		this->current = 0;
	return this->products[this->current];
}

double Cart::total_price()
{
	double cost = 0;
	for (int i = 0; i < this->cart.getSize(); i++)
		cost += cart[i].get_price();
	return cost;
}

bool Cart::isEmpty()
{
	return (this->cart.getSize() == 0);
}

bool Cart::no_available_products()
{
	return (this->products.getSize()==0);
}