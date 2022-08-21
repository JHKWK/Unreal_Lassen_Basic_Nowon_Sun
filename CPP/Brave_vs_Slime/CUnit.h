#pragma once
class CUnit
{
protected:
    int mX ;
    float mHP ;
    float mAP ;

public:
    virtual void BuildInfo();
    void DoMove(int tDir);
    void DoDamage(CUnit* tAttacker);
    const int GetX(); 
    const int GetHP();
    const int GetAP();
};