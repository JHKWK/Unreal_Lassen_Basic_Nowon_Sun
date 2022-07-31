#include <iostream>
using namespace std;

void DoSwap(int& A, int& B);

int main()
{
	int tA = 0;
	int* tpA = nullptr;

	tpA = &tA;

	int& tBB = tA; //레퍼런스 연산자 reference

	*tpA = 10;

	tBB = 20;


	int tX = 3;
	int tY = 2;

	cout << "X : " << tX << "  "<< "Y : " << tY << endl;

	DoSwap(tX, tY);

	cout << "X : " << tX << "  " << "Y : " << tY << endl;

	return 0;
}

void DoSwap(int& A, int& B)
{
	int tTemp = B;
	B = A;
	A = tTemp;
}