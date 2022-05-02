#include "Lines_window.h"
#include "Graph.h"

int main()
{
	try
	{
		Lines_window MyWindow {Point{100,100},1000,800,"Lines"};
		return gui_main();
	}
	catch(exception& e)
	{
		cerr << "error: " << e.what() << endl;
		return 1;
	}
	catch(...)
	{
		cerr << "Unknown error" << endl;
		return 2;
	}
}
