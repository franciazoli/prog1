//g++ WEEK4_1.cpp Graph.cpp Window.cpp GUI.cpp Simple_window.cpp -o week4_1 `fltk-config --ldflags --use-images`


#include "Simple_window.h"
#include "Graph.h"
#include "std_lib_facilities.h"




double one   (double x){return 1  ;}
double slope (double x){return x/2;}
double square(double x){return x*x;}
double sloping_cos(double x){return cos(x)+slope(x);}


int main()
{
	try
	{

		using namespace Graph_lib;
		int constexpr xmax = 600;
		int constexpr ymax = 600;
		Simple_window win{ Point{100,100}, xmax, ymax, "Function Graphs"};

		
		constexpr int Ox = 300;
		constexpr int Oy = 300;
		Point Origo{Ox,Oy};
		constexpr int xlen = 400;
		constexpr int ylen = 400;


		Axis x {Axis::x,Point{100,Oy}, xlen, 20, "1==20 pixels"};
		x.set_color(Color::blue);
		Axis y {Axis::y,Point{Ox,ylen+100}, ylen, 20, "1==20 pixels"};
		y.set_color(Color::blue);
		win.attach(x);
		win.attach(y);


		constexpr int r_min = -10;
		constexpr int r_max = 11;
		constexpr int xscale = 20;
		constexpr int yscale = 20;
		constexpr int pts = 400;


		Function constant{one, r_min, r_max, Origo, pts, xscale, yscale};
		Function linear{slope, r_min, r_max, Origo, pts, xscale, yscale};
		Text label{Point{100,Oy+85}, "x/2"};
		Function parabolic{square, r_min, r_max, Origo, pts, xscale, yscale};
		Function cosine{cos, r_min, r_max, Origo, pts, xscale, yscale};
		cosine.set_color(Color::red);
		Function sloping_cosine{sloping_cos,r_min, r_max, Origo, pts, xscale, yscale};
		sloping_cosine.set_color(Color::yellow);
		
		
		win.attach(constant);
		win.attach(linear);
		win.attach(label);
		win.attach(parabolic);
		win.attach(cosine);
		win.attach(sloping_cosine);


		win.wait_for_button();
	}
	
	
	catch(exception& e)
	{
		cerr<<"Error: " << e.what() << endl;
		keep_window_open();
		return 1;
	}
	
	
	catch(...)
	{
		cerr << "Unknown Exception\n";
		keep_window_open();
		return 2;
	}
	
	
	return 0;
}
