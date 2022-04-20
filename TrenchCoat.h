#pragma once
#include <iostream>
#include <Windows.h>
using namespace std;
class Trench_Coat
{
private:
	std::string id; // unique id for identification - 5 characters
	int size;
	std::string color;
	double price;
	int quantity;
	std::string picture_link;

public:
	// default contructor
	Trench_Coat();

	// constructor with parameters
	Trench_Coat( std::string id,  int size,  std::string color,  double price,  int quantity,  std::string picture_link);

	// getter for the id
	std::string get_id() const { return id; }
	// getter for the size
	int get_size() const { return size; }
	// getter for the color
	std::string get_color() const { return color; }
	// getter for the price
	double get_price() const { return price; }
	// getter for the quantity
	int get_quantity() const { return quantity; }
	// getter for the link
	std::string get_link() const { return picture_link; }

	// shows the current coat: link is opened in browser
	void show();

	// oveload of the == operator
	bool operator==(const Trench_Coat& other) const;
};
