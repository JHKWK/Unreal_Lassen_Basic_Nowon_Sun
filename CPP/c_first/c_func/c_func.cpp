#include <iostream>
using namespace std;

/*
    추상화 : 임의의 항목들을 묶어놓고 이름을 붙인 것
    일반화 : 같은 성질을 가진 여러 값들에 대해 대표하는 하나의 항목을 만들어 다루는 것

    함수 function
        제어 구조들을 묶어놓고 이름을 붙인것
        코드의 추상화

    함수 사용의 3단계
        선언
        정의
        호출 
*/

//함수의 선언 : 함수를 사용하는 곳에 이 함수의 형태를 알려 주는 것;
int DoAddictive(int tA, int tB);
int DoSubstract(int tA, int tB);
int DoMultiply(int tA, int tB);
int DoDivide(int tA, int tB);

int main()
{
    int tA = 10;
    int tB = 2;
    int tResult;
    float tResult_0;

    //+
    tResult = DoAddictive( tA,tB );
    cout << tResult << endl;

    //-
    tResult = DoSubstract( tA,tB);
    cout << tResult << endl;

    // *
    tResult = DoMultiply(tA, tB);
    cout << tResult << endl;

    // / 

    tResult_0 = DoDivide(tA, tB);
    cout << tResult_0 << endl;
}


int DoAddictive(int tA, int tB)
{
    return tA + tB;
}
int DoSubstract(int tA, int tB)
{
    return tA - tB;
}
int DoMultiply(int tA, int tB)
{
    return tA * tB;
}
int DoDivide(int tA, int tB)
{
    return (float)tA / (float)tB;
}
