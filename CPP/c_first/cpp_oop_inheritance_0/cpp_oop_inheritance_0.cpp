#include <iostream>
using namespace std;

class CSlime
{
private:
	int mHp = 100;
	int mAp = 30;
	int mPosX = 0;

public:
	CSlime();
	~CSlime();
 	void DisplayStat();
};

class CSlimeBlack : public CSlime
{
public:
	void DisplayStatBlack();
};

class CSlimeWhite : public CSlime
{
public :
	CSlimeWhite();
	~CSlimeWhite();
};


int main()
{
	CSlime tSlime;
	CSlimeBlack tSlimeBlack;
	CSlimeWhite tSlimeWhite;
	tSlime.DisplayStat();
	tSlimeBlack.DisplayStatBlack();
	tSlimeWhite.DisplayStat();

	return 0;
}

CSlime::CSlime()
{
	cout << "CSlime::CSlime()" << endl;
}
CSlime::~CSlime()
{
	cout << "CSlime::~CSlime()" << endl;
}
void CSlime::DisplayStat() 
{
	cout << "PosX =" << mPosX << endl;
	cout << "HP =" << mHp << endl;
	cout << "AP =" << mAp << endl;
}
void CSlimeBlack::DisplayStatBlack() 
{
	cout << "SlimeBlack" << endl;
	DisplayStat();
}
CSlimeWhite::CSlimeWhite()
{
	cout << "CSlimeWhite::CSlimeWhite()" << endl;
}
CSlimeWhite::~CSlimeWhite()
{
	cout << "CSlimeWhite::~CSlimeWhite()" << endl;
}


