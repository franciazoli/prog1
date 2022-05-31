//g++ 13drill.cpp Graph.cpp Window.cpp GUI.cpp Simple_window.cpp -o 13drill `fltk-config --ldflags --use-images`
#include "Simple_window.h"
#include "Graph.h"
#include "std_lib_facilities.h"

int main()
{
	try
	{
		using namespace Graph_lib;
		
		Simple_window win{Point{100,100}, 800, 1000, "My Window"};
		
		int sizex=800;
		int sizey=1000;
		int gridx=100;
		int gridy=100;
		
		Lines grid;
		
		for (int i = gridx; i < sizex; i += gridx)
		{
			grid.add(Point{i,0}, Point{i,800});
		}
		for (int j = gridy; j < sizey; j += gridy)
		{
			grid.add(Point{0,j}, Point{800,j});
		}
		
		
		Vector_ref<Rectangle> rect;
		for(int i = 0; i <= 8; i++)
		{
			rect.push_back(new Rectangle{Point{i*100, i*100}, 100, 100});
			rect[i].set_fill_color(Color::red);
			win.attach(rect[i]);
		}
		/*
		Vector_ref<Image> img;
		for(int i = 2; i < 5; i++)
		{
			img.push_back(new Image(Point{i*300, i*400}, "sealion.jpeg"));
			win.attach(img[i]);
		}
		*/
		win.attach(grid);
		
		Image lion1 (Point{600,200}, "sealion.jpeg");
		Image lion2 (Point{0,200}, "sealion.jpeg");
		Image lion3 (Point{400,600}, "sealion.jpeg");
		
		win.attach(lion1);
		win.attach(lion2);
		win.attach(lion3);
		
		Image finn (Point{100,0}, "finn.jpeg");
		win.attach(finn);
		for(int i = 0; i < 12; i++)
		{
			win.wait_for_button();
			if(i%2==0)
			{
				finn.move(100,0);
			}
			else
			{
				finn.move(0,100);
			}
			win.attach(finn);
			
		}	
		
		win.wait_for_button();
	}
	catch(exception& e)
	{
		cout << "Error\n";
		return 1;
	}
	catch(...)
	{
		cout << "Unknown error\n";
		return 2;
	}
}

