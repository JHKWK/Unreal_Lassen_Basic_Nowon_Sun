#include <iostream>
using namespace std;

// 윈도우 콘솔 응용프로그램의 시작점(진입점)
// main 함수의 정의
int main()
{
    //영역 scope

    //두 정수의 사칙연산

    int tA = 10;
    int tB = 2;
    int tResult = 0;

    //+
    tResult = tA + tB;
    cout << tResult << endl;
    
    //-
    tResult = tA - tB;
    cout << tResult << endl;
    
    // *
    tResult = tA * tB;
    cout << tResult << endl;

    // / 
    float tResult_0 = 0.0f;
    tResult_0 = (float) tA / (float) tB;
    cout << tResult_0 << endl;

}
