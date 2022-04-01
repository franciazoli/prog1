#include "GUI.h"
#include "Lines_window.h"

int main()
{
	try
	{
	    using namespace Graph_lib;
	    Lines_window win(Point(100,100), 1200, 800,"Lines");
	    return gui_main();
	}
	catch(exception& e)
	{
	    cerr << "Error: " << e.what() << '\n';
	    return 1;
	}
	    catch (...)
	{
	    cerr << "Unknown Error.\n";
		return 2;
	}
}
