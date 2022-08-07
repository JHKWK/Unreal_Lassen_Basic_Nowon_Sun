#include <iostream>
using namespace std;

class CUnit
{
public:
	int mEXP=10;

private:
	int mHP=100;

protected:
	int mAP=20;
};

class CSlime : public CUnit 
{
public:
	void DisplayHP();
	void DisplayAP();
	void DisplayEXP();
};

int main()
{
	CSlime tSlime;

	tSlime.DisplayHP();
	tSlime.DisplayAP();
	tSlime.DisplayEXP();

	return 0;
}

void CSlime::DisplayHP()
{
	 //cout << mHP << endl;
}
void CSlime::DisplayAP()
{
	cout << mAP << endl;
}
void CSlime::DisplayEXP()
{
	cout << mEXP << endl;
}
