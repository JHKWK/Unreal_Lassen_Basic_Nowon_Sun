#include <iostream>
using namespace std;

void DoAdd();
void DoAdd(int a, int b);
void DoAdd(float a, float b);

int main()
{
	DoAdd();
	DoAdd(1,1);
	DoAdd(1.1f, 1.1f);

	return 0;
}

void DoAdd()
{
	cout << 0 << endl;
}

void DoAdd(int a, int b) 
{
	cout << a + b << endl;
}

void DoAdd(float a, float b)
{
	cout << a + b << endl;
}