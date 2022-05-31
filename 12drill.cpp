#include "std_lib_facilities.h"
#include "Simple_window.h"
#include "Graph.h"

/*
g++ WEEK1.cpp Graph.cpp Window.cpp GUI.cpp Simple_window.cpp -o week1 `fltk-config --ldflags --use-images`
*/

int main(){

	using namespace Graph_lib;
	
try{
	Simple_window win {Point{100,100},1030,480, "Canvas"};

	Axis xa {Axis::x, Point{30,350}, 300, 10, "X Axis"};
	Axis ya {Axis::y, Point{30,350}, 300, 10, "Y Axis"};
	
	ya.set_color(Color::blue);
	ya.label.set_color(Color::blue);
	
	xa.set_color(Color::yellow);
	xa.label.set_color(Color::yellow);

	Function sinfx {sin,0,2*3.14,Point{30,250},300,49,49};
	sinfx.set_color(Color::red);

	Polygon tri;
	tri.add(Point{300,75});
	tri.add(Point{350,175});
	tri.add(Point{400,75});
	tri.set_color(Color::yellow);
	tri.set_style(Line_style(Line_style::dash,3));

	Rectangle r{Point{100,120}, 150,50};
	r.set_fill_color(Color::red);

	Closed_polyline poly_rect;
	poly_rect.add(Point{400,225});
	poly_rect.add(Point{450,200});
	poly_rect.add(Point{550,200});
	poly_rect.add(Point{500,225});
	poly_rect.add(Point{550,250});
	poly_rect.add(Point{450,250});
	poly_rect.set_style(Line_style(Line_style::dash,2));
	poly_rect.set_fill_color(Color::green);

	Text t{Point{100,70}, "Hello World/Hello Graphical World"};
	t.set_font(Font::times_bold);
	t.set_font_size(23);

	Circle c{Point{400,400},50};
	Ellipse e{Point{400,400}, 100,50};
	Circle c2{Point{400,400},35};
	
	c.set_fill_color(Color::black);
	e.set_fill_color(Color::white);
	c2.set_fill_color(Color::blue);
	
	
	Mark m{Point{500,430},'.'};

	Image ip1{Point (600,40), "badge.jpg"};

	Image ip2{Point(600,60), "badge.jpg"};

	win.attach(xa);
	win.attach(ya);
	win.attach(sinfx);
	win.attach(tri);
	win.attach(r);
	win.attach(poly_rect);
	win.attach(t);
	win.attach(e);
	win.attach(c);
	win.attach(c2);
	win.attach(m);
	win.attach(ip1);
	win.attach(ip2);

	win.set_label("Window");

	win.wait_for_button();
	}
	catch (exception& e){
		cout << "Error\n";
		return 1;
	}

	catch(...){
		cout << "Other error\n";
		return 2;
	}
} 
