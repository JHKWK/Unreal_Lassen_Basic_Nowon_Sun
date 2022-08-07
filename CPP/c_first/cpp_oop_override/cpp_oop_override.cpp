#include <iostream>
using namespace std;

class CUnit 
{
protected:
	int mX = 0;
public:
	void Display();

};

class CBrave : public CUnit
{
public:
	void Display();
	//overrie 재정의
	//부모클래스에 있는 함수의 형태 (시그니쳐 : 리턴타입 함수이름(매개변수리스트))를 그대로 유지하면서, 정의가 바뀐것
	//정의가 바뀐것
};


int main()
{
	CUnit tUnit;
	tUnit.Display();

	CBrave tBrave;
	tBrave.Display();

	CUnit* tpUnit = nullptr;
	tpUnit = &tBrave; //상속계통구조로 만들어진 클래스로 선언된 객체는 부모클래스 타입의 포인터로 가리킬 수 있다.
	tpUnit->Display();

	return 0;
}

void CUnit::Display()
{
	cout << "void CUnit::Display()" << endl;
}

void CBrave::Display()
{
	cout << "void CBrave::Display()" << endl;
}
