#include <iostream>
using namespace std;

int main()
{
	int a = 10;
	int c = 5;

	int& b = a;

	b = 20;

	//cout << a << endl;
		
	b = c;

	//cout << a << endl;
	//cout << c << endl;

	// 동적할당 new연산자 : 주소값을 리턴한다

	int* tpPtrA = nullptr;
	tpPtrA = new int; // 이름이 없다

	*tpPtrA = 777;
	//cout << *tpPtrA << endl;

	if (nullptr != tpPtrA)
	{
		delete tpPtrA;
		tpPtrA = nullptr;
	}

	/////////////////////////////////////////

	char* tpCharA = new char;
	*tpCharA = '3';

	//cout << *tpCharA << endl;

	////////////////////////////////////////
	int* tpPtrZ = new int[5];

	for (int i = 0; i < 5; i++)
	{
		tpPtrZ[i] = i+1;
		cout << tpPtrZ[i] << endl;
	}

	cout << "////////////////////////////////////" << endl;

	for (int i = 0; i < 5; i++)
	{
		*(tpPtrZ + i) = i+11;
		cout << *(tpPtrZ + i) << endl;
	}

	if (nullptr != tpPtrZ)
	{
		delete[] tpPtrZ; // 배열형 삭제
		tpPtrZ = nullptr;
	}

	return 0;
}





