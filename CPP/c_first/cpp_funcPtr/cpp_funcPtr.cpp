#include <iostream>
#include <functional>
using namespace std;
/*
	함수포인터
*/

int DoAdd(int tA, int tB);
int DoSub(int tA, int tB);

class CUnit
{
private:
	//함수 포인터는 멤버함수를 가리키므로 함수 포인터의 소속을 밝혀야 한다.
	typedef void(CUnit::*CFuncPtr)();
	CFuncPtr mFuncPtr;

public :
	void Create();
	void Excute();
	void Doit();
};

int main()
{ 	 
	cout << "직접호출 : " << DoAdd(2, 3) << endl;	//직접호출

	//간접호출 : 실행중에 호출할 함수를 결정할 수 있다.
	//함수포인터 : 간접호출할 함수와 형태를 맞춘다.
	int (*tpPtr)(int, int) = nullptr;
	tpPtr = DoAdd;
	cout << "간접호출 : " << tpPtr(3, 5) << endl;    //간접호출


	//step_1
	// 타입 재정의 구문
	typedef unsigned int KWK_INT; // typedef A B  A라는 타입을 B라는 타입으로 재정의해서 쓰겠다
	KWK_INT tz = 777;

	typedef int (*FuncPtrKWK)(int, int);
	FuncPtrKWK tKwk = nullptr;

	tKwk = DoAdd;
	cout << "간접호출 - 함수포인터 DoAdd : "  << tKwk(10, 9) << endl;

	tKwk = DoSub;
	cout << "간접호출 - 함수포인터 DoSub : " << tKwk(10, 9) << endl;

	//step_2


	CUnit tUnit;
	tUnit.Create();
	tUnit.Excute();

	//std 
	/*std::function<void ()> tCF;
	tCF = &CUnit::Excute;*/

	typedef void (CUnit::*FuncCUnit)();
	FuncCUnit tCF;
	tCF = &CUnit::Doit;//tUnit.Excute();*/

	//tCF();

	return 0;


}

int DoAdd(int tA, int tB)
{
	return tA + tB;
}

int DoSub(int tA, int tB)
{
	return tA - tB;
}

void CUnit:: Create()
{
	// 클래스의 멤버함수는 전역함수와는 달리 한번더 참조하여 접근하여야만 한다.
	mFuncPtr = &CUnit::Doit;
}

void CUnit::Excute()
{
	// 멤버함수에 대해 간접 호출을 해야 하므로 한번더 참조하여 접근 하였다.
	(this->*mFuncPtr)();
}

void CUnit:: Doit()
{
	cout << "CUnit::Doit" << endl;
}
