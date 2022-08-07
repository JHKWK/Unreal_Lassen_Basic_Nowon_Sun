#include <iostream>
using namespace std;

class CUnit 
{
public:
	CUnit();
	virtual ~CUnit(); // 가상함수가 적용된 클래스는 반드시 가상소멸자를 적용해 주어야 제대로 소멸자가 작동한다

	virtual void Display() {};
};

class CActor : public CUnit
{
public:
	CActor();
	~CActor() override;

	void Display() override {};
};

int main()
{
	CUnit* tpUnit = new CActor();

	if (tpUnit != nullptr)
	{
		delete tpUnit;
		tpUnit = nullptr;
	}
}

CUnit::CUnit()
{

}
CUnit::~CUnit()
{

}
CActor::CActor()
{

}
CActor::~CActor()
{

}
