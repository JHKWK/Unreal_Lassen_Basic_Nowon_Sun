#include <iostream>
using namespace std;

//template function
template<typename T>
T DoAdd(T a, T b);
//T가 실제로 어떤 타입일 지는 컴파일 타임에 결정된다.(정적으로 결정된다)

int main()
{
	int tResult;

	tResult = DoAdd(3,2);

	float tResultFloat;

	tResultFloat = DoAdd(3.141592f, 2.1111f);

	cout << "tResult : " << tResult << endl << "tResultFloat : " << tResultFloat << endl;

	char tResultChar;
	tResultChar = DoAdd(1,1);
	cout << "Char : " << tResultChar << endl;

	return 0;
}

template<typename T>
T DoAdd(T a, T b)
{
	return a + b;
}
