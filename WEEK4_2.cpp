//g++ WEEK4_2.cpp Graph.cpp Window.cpp GUI.cpp Simple_window.cpp -o week4_2 `fltk-config --ldflags --use-images`

#include "std_lib_facilities.h"

const vector<char> invchar = 	{';','?',':','[',']','*','&','^','%','$','#','@','!','.','"','\''};

struct  Person
{
	private:
		string first_name;
		string last_name;
		int age;
	public:
		Person(){};
		Person(string fname, string lname, int a)
		{
			
			if (a<=0 or a>=150)
			{
				error("Invalid Age");
			}
			if (fname=="" || lname=="")
			{
				error("Specify a name");
			}
			for(int i=0; i < invchar.size(); i++)
			{
				if (fname.find(invchar[i]) != string::npos 
					or lname.find(invchar[i]) != string::npos)
					{
						error("Invalid character(s) in name");
					}
				constructinit(fname, lname, a);
			}
			
		};
		void constructinit(string fname, string lname, int a)
		{

			first_name = fname;
			last_name = lname;
			age = a;
		
		}
			string get_first() 	const{return first_name;}
			string get_last() 	const{return last_name;}
			int get_age() 		const{return age;}
};


ostream& operator<< (ostream& os, Person& p)
{
	return os << p.get_first() << ' ' << p.get_last() << ' ' << p.get_age() << endl; 
}


istream& operator>> (istream& is, Person& p)
{
	string fname, lname; int age;
	cout << "First name: ";
	is >> fname;
	cout << "Last name: ";
	is >> lname;
	cout << "Age: ";
	is >> age;
	p = Person(fname,lname,age);
	return is;
} 
	


int main()
{
	try
	{
		vector<Person> people;
		Person Goofy{"Goofy", "Person", 63};
		cout << Goofy;
		Person p1; 
		cin >> p1;
		cout << p1;

		cout << "Continue entering data, exit using \"stop\", \"stop\", \"1\"." << endl;
			for (Person p2; cin >> p2;)
			{
				if (p2.get_first()=="stop") break;
				people.push_back(p2);
			}
			for (Person p:people)
			{
				cout << p << endl;
			}
		return 0;
		}	

	catch(exception& e){
		cerr << "error: "<< e.what() << endl;
		keep_window_open();
		return 1;
	}
	catch(...){
		cerr << "Unknown exception\n";
		keep_window_open();
		return 2;
	}
}
