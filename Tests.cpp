#include "Tests.h"
#include "Repository.h"
#include "Validator.h"
#include "Cart.h"
#include "Controller.h"
#include "DynamicArray.h"
void Tests::testCoat()
{
	// Test default constructor
	Trench_Coat c1;
	assert(c1.get_id() == "");
	assert(c1.get_size() == 0);
	assert(c1.get_color() == "");
	assert(c1.get_price() == 0);
	assert(c1.get_quantity() == 0);
	assert(c1.get_link() == "");

	// Test constructor with parameters
	Trench_Coat c2{ "BEI52", 52, "Beige", 399.98, 3, "http://lp2.hm.com/hmprod?set=source[/environment/2016/8FZ_0205_037R.jpg],width[3811],height[4456],y[-11],type[FASHION_FRONT]&hmver=0&call=url[file:/product/main]" };
	assert(c2.get_id() == "BEI52");
	assert(c2.get_size() == 52);
	assert(c2.get_color() == "Beige");
	assert(c2.get_price() == 399.98);
	assert(c2.get_quantity() == 3);
	assert(c2.get_link() == "http://lp2.hm.com/hmprod?set=source[/environment/2016/8FZ_0205_037R.jpg],width[3811],height[4456],y[-11],type[FASHION_FRONT]&hmver=0&call=url[file:/product/main]");

	// Test == operator
	Trench_Coat c3 = c2;
	assert(c3 == c2);
	//!!!!!!!!!!
	Trench_Coat c4{ "GRN45", 45, "Green", 200.00, 2, "http://google.com" };
	assert(!(c4 == c2));

	Trench_Coat c5{ "BEI52", 45, "Green", 200.00, 2, "http://google.com" };
	assert(!(c5 == c2));

	Trench_Coat c6{ "BEI52", 52, "Green", 200.00, 2, "http://google.com" };
	assert(!(c6 == c2));

	Trench_Coat c7{ "BEI52", 52, "Beige", 200.00, 2, "http://google.com" };
	assert(!(c7 == c2));

	Trench_Coat c8{ "BEI52", 52, "Beige", 399.98, 2, "http://google.com" };
	assert(!(c8 == c2));

	Trench_Coat c9{ "BEI52", 52, "Beige", 399.98, 3, "http://google.com" };
	assert(!(c9 == c2));
}

void Tests::testRepository()
{
	// Test default constructor
	Repository repo{};

	// Test add to repo
	Trench_Coat c1{ "BEI52", 52, "Beige", 399.98, 3, "http://lp2.hm.com/hmprod?set=source[/environment/2016/8FZ_0205_037R.jpg],width[3811],height[4456],y[-11],type[FASHION_FRONT]&hmver=0&call=url[file:/product/main]" };
	Trench_Coat c2{ "PNK32", 32, "Pink", 159.95, 4, "http://lp2.hm.com/hmprod?set=source[/environment/2016/8EZ_0149_013R.jpg],width[4000],height[4677],x[643],y[118],type[FASHION_FRONT]&hmver=0&call=url[file:/product/main]" };
	repo.add_repository(c1);
	repo.add_repository(c2);
	assert(repo.get_coats().getSize() == 2);

	Trench_Coat c3{ "BRN44", 44, "Brown", 159.95, 0, "http://lp2.hm.com/hmprod?set=source[/environment/2016/8EZ_0149_013R.jpg],width[4000],height[4677],x[643],y[118],type[FASHION_FRONT]&hmver=0&call=url[file:/product/main]" };
	repo.add_entities(c3);
	assert(repo.get_coats().getSize() == 3);

	// Test remove from repo
	repo.remove_repository("BRN44");
	assert(repo.get_coats().getSize() == 2);
	// Test remove exception 1
	bool exceptionThrown = false;
	try {
		repo.remove_repository("BRN44");
	}
	catch (const char* msg) {
		exceptionThrown = true;
	}
	assert(exceptionThrown);
	// Test remove exception 2
	exceptionThrown = false;
	try {
		repo.remove_repository("PNK32");
	}
	catch (const char* msg) {
		exceptionThrown = true;
	}
	assert(exceptionThrown);

	// Test sell coat
	//repo.sell_coat_repository("PNK32");
	//cout << repo.find_repository("PNK32").get_quantity() << endl;
	//assert(repo.find_repository("PNK32").get_quantity() == 3);
	

	// Test update coat
	Trench_Coat c4{ "BEI52",52,"Beige",399.98,6,"http://google.com" };
	repo.update_repository("BEI52", c4);
	assert(repo.find_repository("BEI52").get_quantity() == 6);
	// Test update coat exception
	exceptionThrown = false;
	try {
		repo.update_repository("GRN50", c4);
	}
	catch (const char* msg) {
		exceptionThrown = true;
	}
	assert(exceptionThrown);

	// Test get coats by given size
	DynamicArray<Trench_Coat> check_vector = repo.get_coat_by_size(52);
	assert(check_vector.getSize() == 1);
}

void Tests::testValidators()
{
	// Test ID
	Trench_Coat c1{ "BGR234",0,"",0,0,"" };
	bool exceptionThrown = false;
	try {
		coat_validator(c1);
	}
	catch (const char* msg) {
		exceptionThrown = true;
	}
	assert(exceptionThrown);

	// Test size
	Trench_Coat c2{ "BGR23",0,"",0,0,"" };
	exceptionThrown = false;
	try {
		coat_validator(c2);
	}
	catch (const char* msg) {
		exceptionThrown = true;
	}
	assert(exceptionThrown);

	// Test colour
	Trench_Coat c3{ "BGR23",44,"",0,0,"" };
	exceptionThrown = false;
	try {
		coat_validator(c3);
	}
	catch (const char* msg) {
		exceptionThrown = true;
	}
	assert(exceptionThrown);

	// Test price
	Trench_Coat c4{ "BGR23",44,"Brown",0,0,"" };
	exceptionThrown = false;
	try {
		coat_validator(c4);
	}
	catch (const char* msg) {
		exceptionThrown = true;
	}
	assert(exceptionThrown);

	// Test quantity
	Trench_Coat c5{ "BGR23",44,"Brown",20,0,"" };
	exceptionThrown = false;
	try {
		coat_validator(c5);
	}
	catch (const char* msg) {
		exceptionThrown = true;
	}
	assert(exceptionThrown);

	// Test link
	Trench_Coat c6{ "BGR23",44,"Brown",20,1,"" };
	exceptionThrown = false;
	try {
		coat_validator(c6);
	}
	catch (const char* msg) {
		exceptionThrown = true;
	}
	assert(exceptionThrown);
}

void Tests::testShoppingCart()
{
	// Test constructor
	Cart cart{};

	// Test add available products
	Trench_Coat c1{ "BLU42", 42, "Blue",195.00,2,"http://google.com" };
	Trench_Coat c2{ "ORG46", 46, "Orange",195.00,2,"http://google.com" };
	cart.add_coat_product(c1);
	cart.add_coat_product(c2);
	assert(cart.get_available_items().getSize() == 2);

	// Test add coats to cart
	cart.add_to_cart(c1);
	cart.add_to_cart(c2);
	assert(cart.get_cart_items().getSize() == 2);

   // Test start iteration
	cart.start();
	assert(cart.get_current_coat() == c1);
	//
	//// Test next iteration
	cart.next();
	assert(cart.get_current_coat() == c2);
	cart.next();

	// Test total cost
	assert(cart.total_price() == 390.00);

	// Test clear available products and no products
	cart.clear_products();

	assert(cart.no_available_products());

	// Test clear cart and empty cart
	cart.clear_cart();


	// Test start and next for empty cart
	cart.start();
	cart.next();
}

void Tests::testController()
{
	// Test constructor
	Repository repo{};
	Cart cart{};
	Trench_Coat c{ "ORG50", 50, "Orange", 250.00, 0, "http://google.com" };
	repo.add_entities(c);
	Controller ctrl{ repo };

	// Test add to repo
	ctrl.add_coat_to_repository("BLU42", 42, "Blue", 195.00, 2, "http://google.com");
	ctrl.add_coat_to_repository("ORG46", 46, "Orange", 195.00, 2, "http://google.com");
	assert(ctrl.get_repository().get_coats().getSize() == 3);

	// Test remove from repo
	ctrl.remove_coat_from_repository("ORG50");
	assert(ctrl.get_repository().get_coats().getSize() == 2);

	// Test update to repo
	Trench_Coat c1{ "ORG46", 46, "Orange", 245.00, 5, "http://youtube.com" };
	ctrl.update_coat_to_repository("ORG46", 245.00, 5, "http://youtube.com");
	assert(ctrl.get_repository().get_coats()[1] == c1);

	// Test add all coats
	ctrl.add_available_coats_to_cart();
	assert(ctrl.get_cart().get_available_items().getSize() == 2);

	// Test clear available products
	ctrl.clear_products_from_cart();
	assert(ctrl.get_cart().isEmpty());

	// Test add size coats
	ctrl.add_coats_given_size(46);
	
	assert(ctrl.get_cart().get_available_items().getSize() == 3);

	// Test add to cart
	Trench_Coat c2{ "ORG46", 46, "Orange", 195.00, 2, "http://google.com" };
	ctrl.add_coat_to_cart(c2);
	assert(ctrl.get_cart().get_cart_items().getSize() == 1);

	// Test start/next shopping
	ctrl.start_shopping();
	ctrl.next_coat_shopping();

	// Test buy Products
	ctrl.buy_products();
	assert(ctrl.get_cart().isEmpty());
}

void Tests::testAll()
{
	testCoat();
	testRepository();
	testValidators();
	testShoppingCart();
	testController();
}