#include <iostream>
using namespace std;

class CRyuAlgebra
{
private:
	int mVal = 0;

public:
	//
	CRyuAlgebra(int tVal) : mVal(tVal) // mVal = tVal 초기화 목록 문법
	{
	}
	~CRyuAlgebra()
	{
	}

	void operator = (const CRyuAlgebra& tRyuAlgebra)
	{
		mVal = tRyuAlgebra.mVal;
	}

	CRyuAlgebra operator +(CRyuAlgebra& tRyuAlgebra)
	{
		return mVal * 10 + tRyuAlgebra.mVal;
	}

	int GetVal() const
	{
		return mVal;
	}

};

int main()
{
	//CRyuAlgebra tA(1);
	//CRyuAlgebra tB(2);
	//CRyuAlgebra tResult(0);
	CRyuAlgebra tA=1; //선언할때 의 =은 생성자 구문
	CRyuAlgebra tB=2;
	CRyuAlgebra tResult=0;


	tResult = tA + tB;
	
	cout << tResult.GetVal() << endl;

	return 0;
}