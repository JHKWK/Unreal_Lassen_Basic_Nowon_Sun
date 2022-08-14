#include "CBrave.h"
void CBrave::DoBraveMove(CBrave* tBrave, int tDir)
{
    (*tBrave).mX = (*tBrave).mX + tDir;
}

void CBrave::DoDamage(float tSlimeAP)
{
    this->mHP - tSlimeAP;
}