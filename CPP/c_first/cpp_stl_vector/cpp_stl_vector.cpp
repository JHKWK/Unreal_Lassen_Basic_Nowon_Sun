#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
/*
     STL의 Vector 가변 배열

     STL Standard Template Library
         템플릿 문법으로 만들어진 클래스, 함수 모음집
         <-- C++에서 자료구조와 알고리즘을 범용적(다양한 타입에 대입)으로 제공하기 위한 라이브러리

         STL의 세가지 구성요소
         1) 컨테이너 container  :  자료구조
         2) 반복자   iterator   :  컨테이너와 알고리즘과 함께 동작 할 수 있도록 만들어 놓은 일반화된 포인터(?)
         3) 알고리즘 algorithm  :  알고리즘을 범용적으로 만들어 놓은 것

 
    원시 배열 : 동일한 타입의 원소들의 '물리적으로 연속적인'메모리 블럭
    <-- 물리적으로 연속되어있으면 캐쉬적중률이 올라간다
    <-- 속도가 빠르다
    -->컴파일 타임에 크기가 결정 된다.

    가변배열 vector 
    동일한 타입의 원소들이 '개념적으로 연속적인' 메모리 블럭
    <-- 원시배열보다 속도가 느리다
    --> 실행중에 크기를 조정 가능하다(실행중에 원소를 추가하거나 삭제하는 것이 가능하다)
  
*/


//sort에 필요한 비교함수
bool Do(int a, int b)
{
    //내림차순
    //return a > b;

    //오름차순
    return a < b;
}

int main()
{
    vector<int> tArray;

    //배열의 원소를 5개 확보
    tArray.resize(5);

    for (size_t i = 0; i < tArray.size(); i++)
    {
        cout << tArray[i]<< endl;
    }

    cout << endl;

    tArray[1] = 88;
    tArray[2] = 23;
    tArray[3] = 33;
    tArray[4] = 54;

    tArray.at(0) = 7;

    for (size_t i = 0; i < tArray.size(); i++)
    {
        cout << tArray[i] << endl;
    }

    cout << endl;


    //반복자를 이용한 순회(모둔 원소를 중복없이 한번씩 방문 하는 것) 구문
    vector<int>::iterator titor;
    for (titor = tArray.begin();titor != tArray.end();titor++)
    {
        cout << *titor << endl;
    }
    cout << endl;

    // 원소 추가
    tArray.push_back(111);
    tArray.push_back(222);


    for (titor = tArray.begin(); titor != tArray.end(); titor++)
    {
        cout << *titor << endl;
    }
    cout << endl;

    // 원소 삭제
    tArray.pop_back();
    for (titor = tArray.begin(); titor != tArray.end(); titor++)
    {
        cout << *titor << endl;
    }
    cout << endl;

    //정렬 알고리즘 사용 예
    std::sort(tArray.begin(), tArray.end(), Do);

    for (titor = tArray.begin(); titor != tArray.end(); titor++)
    {
        cout << *titor << endl;
    }
    cout << endl;


    return 0;
}
