#include <iostream>
using namespace std;

void DoChangeElemnet(int tArray[], int tIndex, int tValue);

//배열 : 동일한 타입의 원소들의 연속적인 메모리 블럭
// 연속적으로 되어 있으면 cpu의 캐쉬 적중률이 높아진다

int main()
{
	//원시배열
	int tArray[5] = {0,0,0,0,0};

	tArray[0] = 4;
	tArray[1] = 0;
	tArray[2] = 1;
	tArray[3] = 2;
	tArray[4] = 3;

	DoChangeElemnet(tArray, 4, 3);

	for (int i = 0; i < 5 ; i++)
	{
		cout << tArray[i] << endl;
	}

	return 0;
}

// 배열과 포인터는 '주소값'을 다룬다는 공통점이 있다
// 주소값을 넘긴다
// 배열의 이름은 배열의 시작 주소값이다.
void DoChangeElemnet(int tArray[], int tIndex, int tValue)
{
	tArray[tIndex] = tValue;
}