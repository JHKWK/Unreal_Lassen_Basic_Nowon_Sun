#include <iostream>
using namespace std;

struct SSlime
{
	int mX = 0;
	int mHP = 100;
	int mAP = 30;

	void DisplaySlimeInfo(SSlime& a);
};

class CSlime
{
private :
	int mX = 0;
	int mHP = 100;
	int mAP = 30;
public: 
	void DisplaySlimeInfo();
};

int main()
{
	SSlime tSlime;
	tSlime.DisplaySlimeInfo(tSlime);

	CSlime tSlime_0;
	tSlime_0.DisplaySlimeInfo();

}

void SSlime :: DisplaySlimeInfo(SSlime& a)
{
	cout << a.mX << endl;
	cout << a.mHP << endl;
	cout << a.mAP << endl;
}

void CSlime :: DisplaySlimeInfo()
{
	cout << this->mAP << endl;
	cout << this->mHP << endl;
	cout << this->mX << endl;
}