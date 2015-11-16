/*
Класс ? множество Set. 
Дополнительно перегрузить следующие операции: 
() ? конструктор множества ; 
+ ? объединение множеств; 
<= ? сравнение множеств; 
int()? мощность множества; 
[] - доступ к элементу в заданной позиции.


*/
#include<iostream>
#include<cstring>
#include <conio.h>

using namespace std;

class Set
{
	int *data;
	int size;
public:
	Set(int);
	Set(const Set &);
	//~Set();
	void get();
	void show();
	operator int() const;
	int Set::operator+(const Set &r);
	bool operator<=(const Set &r);
	int Set::operator[](int n);
};
Set::Set(int x)
{
	this->size = x;
	this->data = new int[x];
}
Set::Set(const Set &x)
{
	this->size = x.size;
	this->data = new int[x.size];
	for (int i = 0; i < this->size; i++)
	{
		this->data[i] = x.data[i];
	}
}
/*Set::~Set()
{
	delete [] data;
}*/
void Set::get()
{
	cout << "Enter a Set: " << endl;
	int k;
	for (int i = 0; i <= size ; i++)
	{
		cout << "Please enter * " << i << " element" << endl;
		cin >> k;
		this->data[i] = k; 
	}
}
void Set::show()
{
	for (int i = 0; i <= size; i++)
	{
		cout << "Your Set : " << this->data[i] << " ";
	}
}
							
						/*				Перегрузки				*/	

Set::operator int() const
{
	return size;
}
int Set :: operator+ (const Set &r)
{
	for (int i = 0; i <= size; i++)
	{
		data[i] = data[i] + r.data[i];
		//cout << data[i];
	}
	return *this;
}
bool Set::operator<=(const Set &r)
{
	for (int i = 0; i <= size; i++)
	{
		bool was = false;
		for (int j = 0; j <= r.size && !was; j++)
		{
			was = r.data[j] <= data[i];
		}
		if (!was)
		{
			return true;
		}
		else
		{
			return false;
		}
		
	}
}
int Set::operator[](int n)
{
	if (n < 0 || n >= size)
	{
		cout << "Net indeksa" << endl;
		exit(1);
	}
	return data[n];
}

int main()
{
	Set a(3);
	a.get();
	Set s(3);
	s.get();
	cout << "Set : "; 
	a.show();
	cout << endl;
	cout << "Power 1:" << (int)a << endl;
	cout << "Power 2:" << (int)s << endl;
	a + s;
	a.show();
	cout << endl;
	char *r;
	r = (s <= a) ? "S men'she chem A" : "S ne men'she A";
	cout << r << endl;
	cout << endl;
	if (a[4])cout << "cool(est' indeks)" << endl;
	//system("pause");
	return 0;
}
