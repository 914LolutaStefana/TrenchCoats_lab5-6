#include <Windows.h>
#include "UI.h"
#include "Tests.h"

using namespace std;

int main()
{
	
	Tests::testAll();

	Repository repository{};
	Trench_Coat c1{ "BEI52", 52, "Beige", 399.98, 3, "http://lp2.hm.com/hmprod?set=source[/environment/2016/8FZ_0205_037R.jpg],width[3811],height[4456],y[-11],type[FASHION_FRONT]&hmver=0&call=url[file:/product/main]" };
	Trench_Coat c2{ "PNK32", 32, "Pink", 159.95, 4, "http://lp2.hm.com/hmprod?set=source[/environment/2016/8EZ_0149_013R.jpg],width[4000],height[4677],x[643],y[118],type[FASHION_FRONT]&hmver=0&call=url[file:/product/main]" };
	Trench_Coat c3{ "BLU38", 38, "Blue", 199.99, 2, "http://lp2.hm.com/hmprod?set=source[/environment/2017/8LZ_0056_026R.jpg],width[4098],height[4792],y[-1],type[FASHION_FRONT]&hmver=0&call=url[file:/product/main]" };
	Trench_Coat c4{ "GRN40", 40, "Green", 229.95, 0, "http://lp2.hm.com/hmprod?set=source[/environment/2017/8MZ_0076_010R.jpg],width[4240],height[4958],y[-1],type[FASHION_FRONT]&hmver=0&call=url[file:/product/main]" };
	Trench_Coat c5{ "PNK32", 36, "Pink", 159.14, 0, "http://lp2.hm.com/hmprod?set=source[/environment/2016/8EZ_0149_013R.jpg],width[4000],height[4677],x[643],y[118],type[FASHION_FRONT]&hmver=0&call=url[file:/product/main]" };
	Trench_Coat c6{ "BEI48", 48, "Beige", 399.98, 1, "http://lp2.hm.com/hmprod?set=source[/environment/2016/8FZ_0205_037R.jpg],width[3811],height[4456],y[-11],type[FASHION_FRONT]&hmver=0&call=url[file:/product/main]" };
	Trench_Coat c7{ "SAT42", 42, "Satin", 248.95, 5, "http://lp2.hm.com/hmprod?set=source[/model/2017/E00%200488077%20003%2066%202177.jpg],type[STILLLIFE_FRONT]&hmver=2&call=url[file:/product/main]" };
	Trench_Coat c8{ "CAM46", 46, "Camel", 599.98, 2, "http://lp2.hm.com/hmprod?set=source[/environment/2016/7YM_0545_049R.jpg],width[4141],height[4841],x[416],y[208],type[FASHION_FRONT]&hmver=0&call=url[file:/product/main]" };
	Trench_Coat c9{ "CAM50", 50, "Camel", 579.98, 0, "http://lp2.hm.com/hmprod?set=source[/environment/2016/7YM_0545_049R.jpg],width[4141],height[4841],x[416],y[208],type[FASHION_FRONT]&hmver=0&call=url[file:/product/main]" };
	Trench_Coat c10{ "GRY38", 38, "Light-grey", 499.98, 4, "http://lp2.hm.com/hmprod?set=source[/environment/2017/8GZ_0311_003R.jpg],width[4034],height[4716],y[-1],type[FASHION_FRONT]&hmver=0&call=url[file:/product/main]" };
	repository.add_entities(c1);
	repository.add_entities(c2);
	repository.add_entities(c3);
	repository.add_entities(c4);
	repository.add_entities(c5);
	repository.add_entities(c6);
	repository.add_entities(c7);
	repository.add_entities(c8);
	repository.add_entities(c9);
	repository.add_entities(c10);
	Controller controller{ repository };
	UI ui{ controller };
	ui.run(); 
	
	

	return 0;
}