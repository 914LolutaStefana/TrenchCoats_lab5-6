#include "UI.h"
#include <string>
#include <iostream>

using namespace std;

void UI::printMenu()
{
	cout << "\n_____________________________________________" << endl;
	cout << "|               Choose an option             |" << endl;
	cout << "| 1 - Administrator mode                     |" << endl;
	cout << "| 2 - Client mode                            |" << endl;
	cout << "| 0 - Exit program                           |" << endl;
	cout << "|____________________________________________|" << endl;
}

void UI::printRepositoryMenu()
{
	cout << "\n_______________________________________" << endl;
	cout << "|          Administrator mode          |" << endl;
	cout << "| 1 - Add coat                         |" << endl;
	cout << "| 2 - Display all coats                |" << endl;
	cout << "| 3 - Delete coat                      |" << endl;
	cout << "| 4 - Update coat                      |" << endl;
	cout << "| 0 - Back                             |" << endl;
	cout << "|______________________________________|" << endl;
}

void UI::printShoppingCartMenu()
{
	cout << "\n___________________________________________" << endl;
	cout << "|  Welcome to my trench coats application! |" << endl;
	cout << "| 1 - See trench coats in your size        |" << endl;
	cout << "| 2 - Add coat to cart                     |" << endl;
	cout << "| 3 - Next coat                            |" << endl;
	cout << "| 4 - See shopping cart                    |" << endl;
	cout << "| 0 - Back                                 |" << endl;
	cout << "|__________________________________________|" << endl;
}


void UI::add_coat_ui()
{
	cout << "Enter the coat ID(must be 5 charanters): ";
	std::string ID;
	getline(cin, ID);
	cout << "Enter size: ";
	int size;
	cin >> size;
	cin.ignore();
	cout << "Enter colour: ";
	std::string colour;
	getline(cin, colour);
	cout << "Enter price: ";
	double price;
	cin >> price;
	cin.ignore();
	cout << "Enter quantity: ";
	int quantity;
	cin >> quantity;
	cin.ignore();
	cout << "Enter link: ";
	std::string link;
	getline(cin, link);
	this->controller.add_coat_to_repository(ID, size, colour, price, quantity, link);
}

void UI::print_all_coats_ui()
{
	DynamicArray <Trench_Coat> coats = this->controller.get_all_coats();
	for (int i = 0; i < coats.getSize(); i++) {
		cout << "Coat id: " << coats[i].get_id() << " ";
		cout << "Size: " << coats[i].get_size() << " ";
		cout << "Color: " << coats[i].get_color() << " ";
		cout << "Price: " << coats[i].get_price() << " ";
		cout << "Quantity: " << coats[i].get_quantity() << endl;
	}
}

void UI::remove_coat_ui()
{
	cout << "Enter coat id you want to remove: ";
	std::string ID;
	getline(cin, ID);
	this->controller.remove_coat_from_repository(ID);
}

void UI::update_coat_ui()
{
	cout << "Enter the ID for the coat you want to update: ";
	std::string ID;
	getline(cin, ID);
	cout << "Enter the new price for coat: ";
	double new_price;
	cin >> new_price;
	cin.ignore();
	cout << "Enter the new quantity for coat: ";
	int new_quantity;
	cin >> new_quantity;
	cin.ignore();
	cout << "Enter new link for coat image: ";
	std::string new_link;
	getline(cin, new_link);
	this->controller.update_coat_to_repository(ID, new_price, new_quantity, new_link);
}

void UI::add_size_coat_ui()
{
	cout << "Enter the size for your coat: ";
	std::string size_str;
	getline(cin, size_str);
	if (size_str.empty()) {
		this->controller.clear_products_from_cart();
		this->controller.add_available_coats_to_cart();
	}
	else {
		
		int size_i = stoi(size_str);
		this->controller.clear_products_from_cart();
		this->controller.add_coats_given_size(size_i);
		
	}
}

void UI::show_cart_ui()
{
	DynamicArray <Trench_Coat> coatsInCart = this->controller.get_cart().get_cart_items();
	cout << "\nProducts in shopping cart: " << endl;
	for (int i = 0; i < coatsInCart.getSize(); i++) {
		cout << "Color: " << coatsInCart[i].get_color() << " ";
		cout << "Size: " << coatsInCart[i].get_size() << " ";
		cout << "Price: " << coatsInCart[i].get_price() << endl;
	}
	if (this->controller.get_cart().isEmpty())
		cout << "\nThe shopping cart is empty" << endl;
	cout << "\n\tTotal Cost: " << this->controller.get_cart().total_price() << endl;
	cout << "\nWhat would you lie to do?" << endl;
	cout << "1 - Buy coats" << endl;
	cout << "2 - Remove everything from cart" << endl;
	cout << "0 - Continue shopping" << endl;
	cout << "\nInput command: ";
	int command;
	cin >> command;
	cin.ignore();

	switch (command)
	{
	case 1: {
		if (this->controller.get_cart().isEmpty())
			cout << "Cannot buy because cart is empty." << endl;
		else
			this->controller.buy_products();
		break;
	}
	case 2: {
		this->controller.erase_cart();
		break;
	}
	case 0: { break; }
	}
}

void UI::run()
{
	while (true)
	{
		try {
			UI::printMenu();
			int command{ 0 };
			cout << "Input command: ";
			cin >> command;
			cin.ignore();
			if (command == 0)
				break;

			// Administrator mode
			if (command == 1)
			{
				while (true)
				{
					UI::printRepositoryMenu();
					int commandRepo{ 0 };
					cout << "|| Input command: ";
					cin >> commandRepo;
					cin.ignore();
					if (commandRepo == 0)
						break;

					switch (commandRepo)
					{
					case 1: {
						try {
							this->add_coat_ui();
						}
						catch (const char* msg) {
							cerr << msg << endl;
						}
						break;
					}
					case 2: {
						this->print_all_coats_ui();
						break;
					}
					case 3: {
						try {
							this->remove_coat_ui();
						}
						catch (const char* msg) {
							cerr << msg << endl;
						}
						break;
					}
					case 4: {
						try {
							this->update_coat_ui();
						}
						catch (const char* msg) {
							cerr << msg << endl;
						}
						break;
					}
					} //end of switch
				} //
			}    // end of admin

				 // User Mode
			if (command == 2)
			{
				UI::add_size_coat_ui();
				while (true)
				{
					UI::printShoppingCartMenu();
					int commandUser{ 0 };
					cout << "|| Input command: ";
					cin >> commandUser;
					cin.ignore();
					if (commandUser == 0)
						break;

					switch (commandUser)
					{
					case 1: {
						try {
							if (this->controller.get_cart().no_available_products()) {
								cout << "No coats available." << endl;
								break;
							}
							this->controller.start_shopping();
							Trench_Coat c = this->controller.get_cart().get_current_coat();
							cout << "\nNow showing: " << endl;
							cout << "\tSize: " << c.get_size() << endl;
							cout << "\tColour: " << c.get_color() << endl;
							cout << "\tPrice: " << c.get_price() << endl;
							std::string availability = "";
							if (c.get_quantity() > 3)
								availability = "In Stock";
							else if (c.get_quantity() <= 3)
								availability = "Limited Stock";
							else availability = "Out of stock";
							cout << "\tAvailability: " << availability << endl;
							cout << "\n\tTotal Cost: " << this->controller.get_cart().total_price() << endl;
						}
						catch (const char* msg) {
							cerr << msg << endl;
						}
						break;
					}
					case 2: {
						try {
							if (this->controller.get_cart().get_current_coat().get_quantity() < 1) {
								cout << "This item is out of stock. It will not be added to you shopping cart." << endl;
								continue;
							}
							Trench_Coat c = this->controller.get_cart().get_current_coat();
							this->controller.add_coat_to_cart(c);
							cout << "\n\tTotal Cost: " << this->controller.get_cart().total_price() << endl;
						}
						catch (const char* msg) {
							cerr << msg << endl;
						}
						break;
					}
					case 3: {
						try {
							if (this->controller.get_cart().no_available_products()) {
								cout << "No coats available." << endl;
								break;
							}
							this->controller.next_coat_shopping();
							Trench_Coat c = this->controller.get_cart().get_current_coat();
							cout << "\nNow showing: " << endl;
							cout << "\tSize: " << c.get_size() << endl;
							cout << "\tColour: " << c.get_color() << endl;
							cout << "\tPrice: " << c.get_price() << endl;
							std::string availability = "";
							if (c.get_quantity() > 3)
								availability = "In Stock";
							else if (c.get_quantity() <= 3 && c.get_quantity() > 0)
								availability = "Limited Stock";
							else availability = "Out of stock";
							cout << "\tAvailability: " << availability << endl;
							cout << "\n\tTotal Cost: " << this->controller.get_cart().total_price() << endl;
						}
						catch (const char* msg) {
							cerr << msg << endl;
						}
						break;
					}
					case 4: {
						try {
							UI::show_cart_ui();
						}
						catch (const char* msg) {
							cerr << msg << endl;
						}
						break;
					}
					} //end of switch
				} //
			}    // end of user
		}
		catch (const char* msg) {
			cerr << msg << endl;
		}
	}
}