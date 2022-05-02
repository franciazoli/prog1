#include <iostream>
#include <vector>
#include <algorithm>
#include <list>

using namespace std;

template<typename Iter1, typename Iter2>
// requires Input_iterator<Iter1>()&& Output_iterator<Iter2>()
Iter2 iter_copy(Iter1 f1, Iter1 e1, Iter2 f2)
{
	for (Iter1 p = f1; p != e1; p++)
        {
        	*f2 = *p;
        	f2++;
        }
    return f2;
}

template<typename T>
void increase(T& t,double cc)
{
	for(auto& a : t)
	{
		a += cc;
	}
}
template<typename T>
void print(T& t)
{
	for(auto& a : t)
	{
		cout << a << ' ';
	}
	cout << "" << endl;
}

int main(){


	int arrbase[10] {0,1,2,3,4,5,6,7,8,9};
	vector<int> vctbase {0,1,2,3,4,5,6,7,8,9};
	list<int> lstbase {0,1,2,3,4,5,6,7,8,9};
	
	cout << "Base numbers: " << "{0,1,2,3,4,5,6,7,8,9}" <<endl;

	int arr[10];
	for (int i = 0; i < 10; ++i)
	{
		arr[i] = arrbase[i];
	};
	vector<int> vct = vctbase;
	list<int> lst = lstbase; 
	
	for(int i = 0; i < 10; i++)
	{
		arr[i] += 2;
	}
	for(int i = 0; i < vct.size(); i++)
	{
		vct[i] += 3;
	}
	for(auto& a : lst)
	{
		a += 5;
	}
	
	cout << "Array(Values increased by 2): ";
	print(arr);
	cout << "Vector(Values increased by 3): ";
	print(vct);
	cout << "List(Values increased by 5): ";
	print(lst);

	iter_copy(arr,arr+10, vct.begin());
	iter_copy(lst.begin(),lst.end(),arr);

	cout << "" << endl;
	print(arr);
	print(vct);
	print(lst);


	vector<int>::iterator p = find(vct.begin(), vct.end(), 9);
	if(p != vct.end())
	{
		cout << "Found! Position: " << distance(vct.begin(), p) << endl;
	}
	else
	{
	cout << "Value not found." << endl;
	}
	
	
	list<int>::iterator p2 = find(lst.begin(), lst.end(), 14);
	if(p2 != lst.end())
	{
		cout << "Found! Position: " << distance(lst.begin(), p2) << endl;
	}
	else
	{
		cout << "Value not found." << endl;
	}
	return 0;
}
