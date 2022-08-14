#pragma once


class CBrave
{
private:
    int mX = 0;
    float mHP = 1000;
    float tBraveAP = 100;

public:
    void DoBraveMove(CBrave* tBrave, int tDir);
    void DoDamage(float tSlimeAP);

    const int GetX() const
    {
        return mX;
    }
    const int GetHP() const
    {
        return mHP;
    }
    const int GetAP() const
    {
        return tBraveAP;
    }
};
