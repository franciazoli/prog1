#include <iostream>
#include <memory>
#include <string>
#include <vector>

using namespace std;

template<typename T>
struct S 
{ 
		S(T a): val{a} {}
		T& get();
		const T& get() const ;
		S& operator=(const T& a);
	private:
		T val;
};

template<typename T>
S<T>& S<T>::operator=(const T& a){
	val = a;
	return *this;
	 	
}

template<typename T>
istream& operator>>(istream& is, vector<T>& v)
{
	v.clear();
	char ch = 0;
	for(T val; is >> val;)
	{
		v.push_back(val);
		is >> ch;	
		if(ch == ';')
		{
			break;
		}	
	}
    
	return is;
}

template<typename T> 
void read_val(T& v)
{
	cin >> v;
}

template<typename T>
const T& S<T>::get() const 
{
	return val;
}

template<typename T>
T& S<T>::get() 
{
	return val;
}

template<typename T>
ostream& operator<<(ostream& os, vector<T>& a)
{
	for (int i = 0; i < a.size(); ++i)
	{
		os << a[i] << (i < a.size()-1 ? ", " : " ");
	}
	return os;; 
}


int main()
{
	S<int> a {4};
	S<char> b {'z'};
	S<double> c {4.4};
	S<string> d {"sdd"};
	S<vector<int>> e {vector<int> {74,75,76}};

	cout << a.get() << endl;
	cout << b.get() << endl;
	cout << c.get() << endl;
	cout << d.get() << endl;
	cout << e.get() << endl;
	a = 15;
	cout << a.get() << endl;

	cout << "Enter integer value: " << endl; int aa;
	read_val(aa); S<int> aaa {aa};
	cout << "Enter char value: " << endl; char bb;
	read_val(bb); S<char> bbb {bb};
	cout << "Enter double value: " << endl; double cc;
	read_val(cc); S<double> ccc {cc};
	cout << "Enter string value: " << endl; string dd;
	read_val(dd); S<string> ddd {dd};
	cout << aaa.get() << endl;
	cout << bbb.get() << endl;
	cout << ccc.get() << endl;
	cout << ddd.get() << endl;

	cout << "vector<int>: end it with \";\"" << endl; vector<int> ee;
    read_val(ee); S<vector<int>> eee {ee};
    //S<vector<int>> svi2 {e};
    cout << eee.get() << endl;
}	
