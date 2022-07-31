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
    void BuildStats(int tX, int tHP, int tAP);

    CSlime()
    {
    }
    CSlime(int tX, int tHP, int tAP)
    {
        mX = tX;
        mHP = tHP;
        mAP = tAP;
    }
};

class CBrave
{
private:
    int mX = 0;

public:
    void SetX(const int tX);
    int GetX() const;
};

int main(){
    CSlime tSlime;
    CSlime tSilme2(2, 100, 40);

    tSlime.BuildStats(1, 100, 33);
    tSlime.DisplayInfo();
    tSilme2.DisplayInfo();

    CBrave tBrave;
    tBrave.SetX(5);
    cout << tBrave.GetX() << endl;

}

void CSlime::DisplayInfo() 
{
    cout << mX << endl;
    cout << mHP << endl;
    cout << mAP << endl;
}

void CSlime::BuildStats(int tX, int tHP, int tAP) 
{
    mX = tX;
    mHP = tHP;
    mAP = tAP;
}

void CBrave::SetX(const int tX)
{
    mX = tX;
}
int CBrave::GetX() const
{
    return mX;
}

;