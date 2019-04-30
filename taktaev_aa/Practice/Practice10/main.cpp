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
	system("pause");
	return 1;
}