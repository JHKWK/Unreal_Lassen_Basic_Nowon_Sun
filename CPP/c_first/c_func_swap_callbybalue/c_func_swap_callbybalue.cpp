#include <iostream>
using namespace std;

void DoSwap(int tA, int tB);

int main()
{
	int tA = 1;
	int tB = 5;

	cout << "tA : " << tA << endl;
	cout << "tB : " << tB << endl;

	DoSwap(tA, tB);
	
	cout << "tA : " << tA << endl;
	cout << "tB : " << tB << endl;

}

//call by value
//함수가 매개변수를 다루는 기본방식은 call by value 이다.
void DoSwap(int tA, int tB)
{
	int tTemp = 0;
	tTemp = tA;
		
	tA = tB;
	tB = tTemp;

}