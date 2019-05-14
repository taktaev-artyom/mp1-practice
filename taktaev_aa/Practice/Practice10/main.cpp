#include "Container.h"

using namespace std;

int main()
{
	Container<int, 10> x;
	try
	{
		x.Add(1);
		x.Add(2);
		x.Add(3);
		x.Add(x.Find(2));
		x.Delete(2);
		x.print();
	}
	catch (const char* k)
	{
		cout << k << endl;
	}
	cout << "Version 2:" << endl;
	Container<int*, 10> x1;
	try
	{
		x1.Add(11);
		x1.Add(12);
		x1.Add(13);
		x1.Add(x1.Find(12));
		x1.Delete(12);
		x1.print();
	}
	catch (const char* k)
	{
		cout << k << endl;
	}

	/////////////////ERRORS//////////////////

	cout << "Error test:" << endl;
	Container<int, 10> x2;
	try
	{
		x2.Add(1);
		x2.Add(x2.Find(2));
	}
	catch (const char* k)
	{
		cout << k << endl;
	}
	try
	{
		x2.Delete(2);
	}
	catch (const char* k)
	{
		cout << k << endl;
	}
	try
	{
		x2.Delete(1);
		x2.Delete(x2.Find(1));
	}
	catch (const char* k)
	{
		cout << k << endl;
	}
	try
	{
		x2.print();
	}
	catch (const char* k)
	{
		cout << k << endl;
	}
	try
	{
		for (int i = 0; i < 10; i++)
			x2.Add(i);
		x2.Add(13);
	}
	catch (const char* k)
	{
		cout << k << endl;
	}
	/*cout << "Error test 2:" << endl;
	Container<int*, 10> x3;
	try
	{
		x1.Add(11);
		x1.Add(12);
		x1.Add(13);
		x1.Add(x1.Find(12));
		x1.Delete(12);
		x1.print();
	}
	catch (const char* k)
	{
		cout << k << endl;
	}*/
	system("pause");
	return 1;
}