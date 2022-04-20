#pragma once
#include "Controller.h"

class UI
{
private:
	Controller controller;

public:
	UI(const Controller& c) : controller(c) {}

	void run();

private:
	static void printMenu();
	static void printRepositoryMenu();
	static void printShoppingCartMenu();

	//bool is_number(const std::string& s);

	void add_coat_ui();
	void print_all_coats_ui();
	void remove_coat_ui();
	void update_coat_ui();
	void add_size_coat_ui();
	void show_cart_ui();
};

