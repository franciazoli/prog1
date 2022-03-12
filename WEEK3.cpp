#include "std_lib_facilities.h"

class B1
{
	
	public: virtual void vf() 
	{
			cout << "B1::vf()\n";
	}
	public: void f()
	{
		cout << "B1::f()\n";
	}		
	//public: virtual void pvf()=0;
	// 5. feladat
	// igy a program nem fut le, ezért kommentelem
};

class D1 : public B1
{
	public:virtual void vf() override
	{
		cout << "D1::vf()\n";
	}
	public: void f()
	{
		cout << "D1::f()\n";
	}
	public: virtual void pvf()
	{
		cout << "D1::pvf()\n";
	}
};

class D2 : public D1
{
	public: virtual void pvf() override
	{
		cout << "D2::pvf()\n";
	}	
};

class B2
{
	public: virtual void pvf()
	{
		cout << "B2::pvf()\n";
	}
};

class D21 : public B2
{	
	string str="Hello this is the terminal speaking\n";
	public: virtual void pvf() override
	{
		cout << str;
	}
};

class D22 : public B2
{
	int num = 333;
	public: virtual void pvf() override
	{
		cout << num << endl;
	}
	public: void f(B2& b_two)
	{
		b_two.pvf();
	}
};

int main()
{
	cout << "-----------------\n";
	
	/*
	B1 first;
	first.vf();
	first.f();
	*/
	
	cout << "\n-----------------\n";
	
	D1 second;
	second.vf();
	second.f();
	second.pvf();
	
	
	cout << "\n-----------------\n";
	
	B1& third {second};
	third.vf();
	third.f();
	// 4. feladat:
	// A D1 felulirasa ervenyes, mert a B1 referenciat itt is a D1-re inicializaltuk.
	
	cout << "\n-----------------\n";
	
	D2 fourth;
	fourth.vf();
	fourth.f();
	fourth.pvf();
	
	cout << "\n-----------------\n";
	
	D21 fifth;
	fifth.pvf();

	cout << "\n-----------------\n";
	
	D22 sixth;
	sixth.pvf();
	sixth.f(fifth);
	sixth.f(sixth);
	
	return 0;
}

