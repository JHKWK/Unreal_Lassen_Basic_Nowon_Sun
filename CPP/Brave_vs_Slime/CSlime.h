#pragma once
class CSlime
{
private:
    float mHP = 200.0f;
    float mAP = 500.0f;

public:

    void DoDamge(float tBraveAP)
    {
        mHP = mHP - tBraveAP;
    }

    const int GetHP() const
    {
        return mHP;
    }

    const int GetAP() const
    {
        return mAP;
    }
};

