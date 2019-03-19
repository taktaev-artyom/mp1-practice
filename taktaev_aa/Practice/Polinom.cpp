#include "Polinom.h"
monom::monom()
{
	koeff = 0;
	degree = 0;

}

monom::monom(double k, int d)
{
	koeff = k;
	degree = d;
}

monom::~monom()
{
	delete next;
}

polynom::polynom()
{
	head = nullptr;
}

polynom::~polynom()
{
	delete head;
}

void polynom::Add(double k, int d)
{
	if (!head) head = new monom(k, d);
	else
	{
		monom* i;
		for (i = head; i->next != 0; i = i->next)
		{
		}
		i->next = new monom(k, d);
	}
}

void polynom::Delete(monom* x)
{
	monom* i = head;
	monom* del = i;
	while(i)
	{
		i = i->next;
		if (i == x) delete del;
		del = i;
	}
}

monom* polynom::Search(int degree)
{
	monom* i;
	for(i = head; i; i = i->next)
	{ 
		if (i->degree == degree) return i;
	}
	return nullptr;
}

void polynom::DeleteAll()
{
	monom* i = head;
	monom* del = i;
	while (i)
	{
		i = i->next;
		delete del;
		del = i;
	}
	head = nullptr;
}

polynom& polynom::Input()
{
	monom* head = nullptr;
	DeleteAll();
	while (1)
	{
		int degree;
		double koeff;
		std::cout << "Vvedite koefficient" << std::endl;
		std::cin >> koeff;
		std::cout <<"Vvedite stepen'"<<std::endl;
		std::cin >> degree;
		if ((degree == 0) && (koeff == 0)) break;
		Add(koeff, degree);
	}
	return *this;
}

void polynom::Output()
{
	if (!head)
	{
		std::cout << "Полином нулевой!" << std::endl;
		return;
	}
	for (monom* i = head; i; i = i->next) 
	{
		if (i==head) std::cout<< i->koeff << "x^" << i->degree;
		else
		if (i->degree == 0) std::cout << " + " << "i->koeff" << std::endl;
		else
			std::cout << " + " << i->koeff << "x^" << i->degree;
	}
}

polynom& polynom::operator+(double x)
{
	monom* i;
	if (Search(0) == nullptr) Add(x, 0);
	else Search(0)->koeff = Search(0)->koeff;
	return *this;
}

polynom& polynom::operator+(const polynom& x)
{
	monom* i;
}