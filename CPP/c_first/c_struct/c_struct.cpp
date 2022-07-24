#include <iostream>
using namespace std;

// 구조체 : 데이터의 추상화;
// 함수 : 코드의 추상화

struct SWeapon
{
	int tWeaponAP;
	int tWeaponEndur;
	int tWeaponPower;
};

int main()
{
	SWeapon tWeapon;

	int* tpA = &tWeapon.tWeaponAP;

	tWeapon.tWeaponAP = 777;
	tWeapon.tWeaponEndur = 2;
	tWeapon.tWeaponPower = 33;

	int tFianlAP = tWeapon.tWeaponAP + tWeapon.tWeaponEndur + tWeapon.tWeaponPower;

	cout << tFianlAP << endl;

	cout << *tpA << endl;



}
