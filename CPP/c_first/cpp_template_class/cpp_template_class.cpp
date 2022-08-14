#include <iostream>
using namespace std;

template<typename T>
class DData
{
public:
	T mData;
};


template<typename T>
class CData
{
public:
	T mData;
};



int main()
{
	CData<int> tData;
	tData.mData = 777;

	CData<string> tData2;
	tData2.mData = "칠칠칠";

	CData < DData<int> > tData3;
	tData3.mData.mData = 3;

	cout << tData.mData << endl;
	cout << tData2.mData << endl;
	cout << tData3.mData.mData << endl;

	return 0;

}