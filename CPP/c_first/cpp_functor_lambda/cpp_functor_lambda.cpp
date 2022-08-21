#include <iostream>
using namespace std;

/*
    함수객체

    람다(익명함수)

*/

class CisOdd
{
public :
    // 함수 호출 연산자를 연산자 오버로트
    bool operator()(int tE)
    {
        return tE % 2 == 1;
    }
};

int main()
{
    // step_0
    
    // 함수객체 functor
    CisOdd tisOdd;
    tisOdd(3); // 함수객체 functor를 이용하여 호출

    cout << tisOdd(3) << endl << tisOdd(2) << endl;

    // step_1
    // []:capture절
    // ():매개변수리스트
    // {}:함수몸체(정의)

    []() {};      // 람다함수 선언과 정의
    []() {}();    // 람다함수 선언과 정의와 호출

    []() {cout << "Lambda" << endl; };
    []() {cout << "Lambda()" << endl; }();

    auto tLambda = []() {cout << "Lambda" << endl; }; 
    tLambda();

    int tA = 3;
    int tB = 2;
    int tR = 0;

    // = 값으로 외부변수 캡쳐
    // & 참조 reference로 외부변수 캡쳐
    // [=]() 모든 외부변수를 값으로 캡쳐
    // [&]() 모든 외부변수를 참조형으로 캡쳐 

    auto t = [=, &tR]() {tR = tA + tB;}; // 모든 외부변수를 값으로 캡쳐 하고 tR은 참조형으로 캡쳐
    t(); // 람다 함수 실행
    cout << tR << endl;

    tA = 5;
    tB = 7;

    auto t2 = [&tR](int tA, int tB) {tR = tA + tB; };
    t2(tA,tB);
    cout << tR << endl;

    return 0;
}