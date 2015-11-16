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
			(T)array[i] = ((T)(RAND_MAX)) / 100 + ((T)(rand() % 31 - 25));
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
	void print()
	{
		cout << "Size = " << this->size << endl;
		for (int i = 0; i < size; i++)
		{
			cout << array[i] << " ";
		}
		cout << endl;
	}
};

int main()
{
	srand(time(NULL));
	Set<int> firstSet(3);
	firstSet.input();
	Set<int > secondSet(3);
	secondSet.input();
	Set<int > sum;
	sum = firstSet + secondSet;
	firstSet.print();
	secondSet.print();
	sum.print();
	system("pause");
}
