#include <iostream>
using namespace std;

// 포인터 변수 : '주소'를 '값'으로 가지는 '변수'

int main()
{
    int tA = 777;
    int* tpA = nullptr; // 포인터변수의 선언 및 초기화
    tpA = &tA; // & 주소 연산자 : 변수에 주소를 얻어오는 연산자

    *tpA = 888;

    int tB = 0;
    tB = *tpA; // 간접참조 연산자

    *tpA = 999;

    cout << tB << endl;

    cout << tA << endl;
}
