#include "VectorSTR.h"

using namespace std;

void main()
{
	int num1, num2;
	double errmas[] = { 1.26, 2.35, 3.44, 4.79, 5.88, 6.97, 7.116 };
    Vector sum, sum1, diff, diff1, plusmuzhik, minusmuzhik, multiplybymuzhik, umn;
    double scal, muzhik, mas0;
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
	try
	{
		sum = x + y;
		sum1 += x;
		diff = x - y;
		diff1 -= y;
		scal = x * y;
		umn = x;
		umn *= y;
		mas0 = x[0];
	}
	catch (int k)
	{
		cout << "!!!ERROR number" << errmas[k-1] << endl;
		//return;
	}
	cout << "x + y = " << endl;
	sum.Output();
	cout << "0 += x " << endl;
	sum1.Output();
	cout << "x - y = " << endl;
	diff.Output();
	cout << "0 -= y " << endl;
	diff1.Output();
	cout << "x * y = " << scal << endl;
	cout << "x *= y " << endl;
	umn.Output();
	cout << "x[0]= " << mas0 <<endl;
	cout << "x + muzhik = " << endl;
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