/*
	g++ WEEK5.cpp Graph.cpp Window.cpp GUI.cpp Lines_window.cpp -o week5 `fltk-config --ldflags --use-images`
*/

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
	catch(exception& e) {
   		cerr << "Exception: " << e.what() << '\n';
    		return 1;
	}
    	catch (...) {
    	cerr << "Unknown exception\n";
	return 2;
	}
}
