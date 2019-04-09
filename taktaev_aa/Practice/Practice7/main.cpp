#include "VectorSTR.h"

using namespace std;

void main()
{
	int num1, num2;
    Vector sum, diff, plusmuzhik, minusmuzhik, multiplybymuzhik;
    double scal = 0, muzhik, mas0 = 0;
	cout << "//When an error occurs, the number will be written. The error number goes before a point";
	cout << "and the line number goes after the point." << endl;
    cout << "Enter the first vector's dimension:" << endl;
    cin >> num1;
	Vector x(num1);
    cout << "Please enter values of first vector's components:" << endl;
    for (int i = 0; i < x.n; i++)
    {
        cin >> x.mas[i];
    }
    cout << "Enter the second vector's dimension:" << endl;
    cin >> num2;
    Vector y(num2);
    cout << "Please enter values of second vector's components:" << endl;
    for (int i = 0; i < y.n; i++)
    {
        cin >> y.mas[i];
    }
	cout << "Enter a number:" << endl;
	cin >> muzhik;
	plusmuzhik = x + muzhik;
	minusmuzhik = y - muzhik;
	multiplybymuzhik = x * muzhik;
	Vector sum1(x.n), diff1(x.n);
	try
	{
		sum = x + y;
		cout << "x + y = " << endl;
		sum.Output();
	}
	catch (char* k)
	{
		cout << k << endl;
	}
	try
	{
		sum1 += x;
		cout << "x +=  " << endl;
		sum1.Output();
	}
	catch (char* k)
	{
		cout << k << endl;
	}
	try
	{
		diff = x - y;
		cout << "x - y = " << endl;
		diff.Output();
	}
	catch (char* k)
	{
		cout << k << endl;
	}
	try
	{
		diff1 -= y;
		cout << "y -=  " << endl;
		diff1.Output();
	}
	catch (char* k)
	{
		cout << k << endl;
	}
	try
	{
		scal = x * y;
		cout << "x * y = " << scal << endl;
	}
	catch (char* k)
	{
		cout << k << endl;
	}
	try
	{
		mas0 = x[0];
		cout << "x[0]= " << mas0 << endl;
	}
	catch (char* k)
	{
		cout << k << endl;
	}
	/*cout << "x + y = " << endl;
	sum.Output();
	cout << "x += 0 " << endl;
	sum1.Output();
	cout << "x - y = " << endl;
	diff.Output();
	cout << "y -= 0 " << endl;
	diff1.Output();
	cout << "x * y = " << scal << endl;
	cout << "x[0]= " << mas0 <<endl;
	cout << "x + muzhik = " << endl;*/
	plusmuzhik.Output();
	cout << "y - muzhik = " << endl;
	minusmuzhik.Output();
	cout << "x * muzhik = " << endl;
	multiplybymuzhik.Output();
	cout << "The length of x is " << x.Vector_Len() << endl;
	cout << "The length of y is " << y.Vector_Len() << endl;
	int k;
	cin >> k;
}