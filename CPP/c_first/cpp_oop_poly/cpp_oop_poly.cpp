#include <iostream>
using namespace std;

class CUnit
{
private:
	int mX = 0;
	int mY = 0;
	int mZ = 0;
	int mW = 0;

public:
	virtual void Display();
};

class CSlime : public CUnit
{
public:
	void Display() override;
};

class CSlimeBoss : public CSlime
{
public:
	void Display() override;
};

int main()
{
	CUnit* tUnits[2] = {nullptr,nullptr};
	CSlime tSlime;
	CSlimeBoss tBoss;

	tUnits[0] = &tSlime;
	tUnits[1] = &tBoss;

	for (int i = 0; i < 2; i++)
	{
		tUnits[i]->Display();
	}

	cout << "CUnit class Size" << sizeof(CUnit) << endl;
	cout << "Slime class Size" << sizeof(CSlime) << endl;
	cout << "Boss class Size" << sizeof(CSlimeBoss) << endl;
	// (int)4+4+4+4 + (ptr)8 = 24 byte
	return 0;
}

void CUnit::Display()
{
	cout << "void CUnit::Display()" << endl;
}
void CSlime::Display()
{
	cout << "void CSlime::Display()" << endl;
}
void CSlimeBoss::Display()
{
	cout << "void CSlimeBoss::Display()" << endl;
}