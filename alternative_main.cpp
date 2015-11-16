#include<iostream>
#include<ctime>

using namespace std;

template<class T> class Set
{
public:
	T *array;
	int size;
	Set()
	{
		array = 0;
		size = 0;
	}
	Set(T *pp, int sz)
	{
		array = new T[sz];
		for (int i = 0; i < sz; i++)
		{
			array[i] = pp[i];
		}
		size = sz;
	}
	Set(int x)
	{
		array = new T[x];
		size = x;
	}
	void input()
	{
		for (int i = 0; i < size; i++)
		{
			(T)array[i] = ((T)(RAND_MAX)) / 1000 + ((T)(rand() % 30));
		}
	}
	friend Set operator +(Set& a1, Set& a2)
	{
		Set min, max;
		if (a1.size > a2.size)
		{
			max = a1;
			min = a2;
		}
		else
		{
			max = a2;
			min = a1;
		}
		T *p = new T[max.size];
		Set newSet(max.size);
		for (int i = 0; i < min.size; i++)
		{
			newSet.array[i] = min.array[i] + max.array[i];
		}
		for (int i = min.size; i < max.size; i++)
		{
			newSet.array[i] = max.array[i];
		}
		return newSet;

	}
	operator int() const
	{
		return this->size;
	}
	T operator[](int x)
	{
		return array[x];
	}
	friend bool operator <=(const Set &r, const Set &l)
	{
		if (r.size < l.size)
		{
			cout << " < " << endl;
			return true;
		}
		if (r.size == l.size)
		{
			for (int i = 0; i < r.size; i++)
			{
				if (r.array[i] != l.array[i])
				{
					return false;
				}
				else
				{
					return true;
				}
			}
		}
		return false;
	}
	void print()
	{
		cout << "Size = " << this->size << endl;
		for (int i = 0; i < size; i++)
		{
			cout << "Result:" << "  ";
			cout << array[i] << " ";
		}
		cout << endl;
	}
};

int main()
{
	srand(time(NULL));
	Set<int> firstSet(2);
	firstSet.input();
	Set<int > secondSet(3);
	secondSet.input();
	Set<int > sum;
	sum = firstSet + secondSet;
	firstSet.print();
	secondSet.print();
	sum.print();
	cout << "-------" << endl;
	cout << "----First Set----" << endl;
	cout << "First : " << firstSet[0] << endl;
	cout << "Second : " << firstSet[1] << endl;
	cout << "Third : " << firstSet[2] << endl;
	cout << "-------" << endl;
	cout << "----Second Set----" << endl;
	cout << "First : " << secondSet[0] << endl;
	cout << "Second : " << secondSet[1] << endl;
	cout << "Third : " << secondSet[2] << endl;
	cout << "-------" << endl;
	cout << "Amount of Element : " << (int)firstSet << endl;
	cout << "-------" << endl;
	if (firstSet <= secondSet)
	{
		cout << "First Set <= Second Set" << endl;
		cout << "-----" << endl;
	}
	else
	{
		cout << "First Set >= Second Set" << endl;
		cout << "-----" << endl;
	}
	
	system("pause");
}
