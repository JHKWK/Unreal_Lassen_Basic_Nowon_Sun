#include "CUnit.h"
void CUnit::BuildInfo()
{
}

void CUnit::DoMove( int tDir)
{
    mX = mX + tDir;
}

void CUnit::DoDamage(CUnit* tAttacker)
{
    this->mHP = this->mHP - tAttacker->GetAP();
}

const int CUnit:: GetX()
{
    return mX;
}
const int CUnit::GetHP()
{
    return mHP;
}
const int CUnit::GetAP()
{
    return mAP;
}