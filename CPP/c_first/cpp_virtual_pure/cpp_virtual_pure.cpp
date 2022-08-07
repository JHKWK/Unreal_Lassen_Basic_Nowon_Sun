#include <iostream>
using namespace std;

/*
    순수 가상함수 pure virtual funtion은 추상 클래스 abstract class를 만들고 이것은 '형태'를 강제한다
*/

//추상 클래스
class CUnit
{
public:
    CUnit() {};
    virtual ~CUnit() {};

    virtual void DSP() = 0 ; //순수 가상 함수를 선언( 형태만 제공하는 함수 )
};

class CSlime : public CUnit
{
public:
    CSlime() {};
    virtual ~CSlime() {};

    void DSP()
    {
        cout << "CSlime::DSP" << endl;
    };
};

int main()
{
    // 순수가상함수는 정의가 없기 때문에
    //추상 클래스로는 객체를 만들 수 없다

    // CUnit tUnit;

    CSlime tSlime;
    tSlime.DSP();
}
