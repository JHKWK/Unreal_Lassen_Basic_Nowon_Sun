#include <iostream>
using namespace std;

template<typename T>
class CData
{
private:
    T mData;
public:
    CData(T tData) : mData(tData)
    {

    }

    void SetData(T tData)
    {
        mData = tData;
    }

    const T GetData() const
    {
        return mData;
    }        

};

// char* 일때 동작하는 규칙 (speciallized)
template<>
class CData<char*>
{
private:
    char* mData = nullptr;

public:
    CData(char* tData)
    {
        // Deep Copy
        unsigned int tLength = strlen(tData);
        mData = new char[tLength + 1];
        memset(mData, 0, tLength + 1);

        memcpy(mData, tData, tLength);
    }

    const char* GetData() const
    {
        return mData;
    }

    ~CData()
    {
        if (mData)
        {
            delete[] mData;
            mData = nullptr;
        }
    }
};

int main()
{
    CData<int> tData(777);
    cout << tData.GetData() << endl;

    CData<float> tDataF(777.777f);
    cout << tDataF.GetData() << endl;

    //char* (C style 문자열) 멤버변수를 가지는 템플릿 클래스;
    CData<char*> tprDataC((char*)"abc");
    cout << tprDataC.GetData() << endl;



    return 0;
}