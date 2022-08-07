#include <iostream>
using namespace std;

class CWeapon
{
private:
	int mAP = 0;
};

class CSlime
{
private:

public :

	int mX ;
	int mHP ;
	int mAP ;

	CSlime();						   // 기본생성자
	~CSlime();						   // 기본소멸자
	CSlime(const CSlime& t);		   // 복사생성자	
	void operator= (const CSlime& t);  // 복사대입연산자

	CWeapon* mpWeapon = nullptr;
};

class CSlimeBoss : CSlime
{
public :
	CSlimeBoss() 
	{
	}
	~CSlimeBoss()
	{
	}
	// 부모클래스의 복사 생성자를 호출하였다. 명시하지 않을 시 부모클래스의 기본 생성자가 호출된다
	CSlimeBoss(const CSlimeBoss& t):CSlime(t)
	{
	}
	void operator=(const CSlimeBoss& t)
	{
		if (&t == this) 
		{
			return;
		}
		//부모클래스의 복사대입연산자를 호출 해 준다
		CSlime::operator=(t);
	}
};

int main()
{
	CSlime tSlimeA;
	tSlimeA.mX = 1;
	tSlimeA.mHP = 100;
	tSlimeA.mAP = 30;

	CSlime tSlimeB;
	tSlimeB.mX = 2;
	tSlimeB.mHP = 120;
	tSlimeB.mAP = 20;

	//복사 생성자
	CSlime tSlimeC(tSlimeA);
	//CSlime tSlimeC = tSlimeA;

	//복사 대입 연산자
	tSlimeB = tSlimeA;

	CSlimeBoss tSlimeBossA;
	CSlimeBoss tSlimeBossB;

	CSlimeBoss tSlimeBossC = tSlimeBossA;
	tSlimeBossB = tSlimeBossA;

	return 0;
}

CSlime::CSlime() : mX(0), mHP(5), mAP(0)
{
	mpWeapon = new CWeapon();
}

CSlime ::~CSlime()
{
	if (mpWeapon != nullptr)
		delete mpWeapon;
		mpWeapon = nullptr;
}

CSlime::CSlime(const CSlime& t) 
{
	//얕은 복사 shallow copy
	//mX = t.mX;
	//mHP = t.mAP;
	//mAP = t.mAP;

	//mpWeapon = t.mpWeapon;

	//깊은 복사 deep copy
	mX = t.mX;
	mHP = t.mAP;
	mAP = t.mAP;

	mpWeapon = new CWeapon();
	*mpWeapon = *t.mpWeapon;
}

void CSlime::operator= (const CSlime& t)
{
	if (&t == this)
	{
		return;
	}
	//얕은 복사 shallow copy
	//mX = t.mX;
	//mHP = t.mAP;
	//mAP = t.mAP;

	//mpWeapon = t.mpWeapon;

	//깊은 복사 deep copy
	mX = t.mX;
	mHP = t.mAP;
	mAP = t.mAP;

	if (nullptr == mpWeapon)
	{
		mpWeapon = new CWeapon();
		*mpWeapon = *t.mpWeapon;
	}
	else
	{
		*mpWeapon = *t.mpWeapon;
	}
}
