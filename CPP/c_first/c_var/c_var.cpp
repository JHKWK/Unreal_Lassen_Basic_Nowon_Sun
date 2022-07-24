#include <iostream>
using namespace std;

/*
	변수 종류

	프로세스 주소 공간

*/

int gA = 1024;

void Doit(int tP);

int main()
{
	int tX = 777;
	Doit(gA);
}

void Doit(int tP) 
{
	cout << "tP:" << tP << endl;
}