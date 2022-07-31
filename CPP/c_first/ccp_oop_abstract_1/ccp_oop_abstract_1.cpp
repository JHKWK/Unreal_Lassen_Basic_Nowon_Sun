#include <iostream>
using namespace std;

class CSlime 
{
private:
	int mX = 0;
	int mHP = 100;
	int mAP = 30;

public :
	void DisplayInfo();

	// 생성자,소멸자
	// 생성자 constructor : 객체가 생성될 때 자동으로 호출되는 함수
	// 소멸자 destructor : 객체가 소멸될 때 자동으로 호출되는 함수
	
	// 리턴타입 표기가 없음
	CSlime();  // 기본생성자
	~CSlime(); // 소멸자
};

int main()
{
	//CSlime tSlime;
	//tSlime.DisplayInfo();

	CSlime* tpSlime = new CSlime;
	tpSlime->DisplayInfo();

	if (nullptr != tpSlime)
	{
		delete tpSlime;
		tpSlime = nullptr;
	}

	return 0;
}

void CSlime::DisplayInfo() 
{
	cout << "--- Slime Info ---" << endl;
	cout <<"POS X : "<<mX << endl;
	cout <<"HP    : "<<mHP << endl;
	cout <<"AP    : "<<mAP << endl;
}

CSlime::CSlime() 
{
	cout << "CSlime::CSlime()" << endl;

}

CSlime::~CSlime() 
{
	cout << "CSlime::~CSlime()" << endl;

}
