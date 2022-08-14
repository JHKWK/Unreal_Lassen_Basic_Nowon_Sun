#include <iostream>
#include <time.h>
#include "CBrave.h"
#include "CSlime.h"

using namespace std;

int GetWorldAttrib(int tWorld[], int index);

int main()
{
    srand((unsigned int)time(nullptr));

    int tWorld[5] = { 100, 0, 1, 0, 200 };

    CBrave tBrave;
    CSlime tSlime;

    char tMoveDir = 'd';


    cout << "((용사와 슬라임))" << endl;
    cout << "==종료하려면 n을 입력하세요==" << endl;


    while (true)
    {
        //input
        cout << "move?(a/d)";
        cin >> tMoveDir;


        if ('n' == tMoveDir)
        {
            cout << "brave is sleeping." << endl;
            break;
        }

        if ('a' == tMoveDir)
        {
            if (tBrave.GetX() > 0)
            {
                tBrave.DoBraveMove(&tBrave, -1);
                cout << "<--move left" << endl;
            }
            else
            {
                cout << "용사가 더이상 움직일 수 없습니다." << endl;
            }
        }

        if ('d' == tMoveDir)
        {
            if (tBrave.GetX() < 4)
            {
                tBrave.DoBraveMove(&tBrave, 1);
                cout << "-->move right" << endl;
            }
            else
            {
                cout << "용사가 더이상 움직일 수 없습니다." << endl;
            }
        }

        int tAttrib = 0;
        tAttrib = GetWorldAttrib(tWorld, tBrave.GetX());
        //tAttrib = tWorld[tBraveX];


        switch (tAttrib)
        {
        case 0: //아무것도 없음
        {
            cout << "No one here." << "(You are on" << tBrave.GetX() << "Tile)" << endl;
        }
        break;
        case 1: //슬라임 있음
        {
            cout << "Slime is here." << "(You are on" << tBrave.GetX() << "Tile)" << endl;

            char tIsRollDice = 'r';
            while (1)
            {
                cout << "Roll a Dice of Fate!(r):";
                cin >> tIsRollDice;

                if ('r' == tIsRollDice)
                {
                    //roll dice
                    int tDiceNumber = rand() % 6 + 1;
                    cout << tDiceNumber << endl;

                    switch (tDiceNumber)
                    {
                    case 1:
                    case 2:
                    case 3:
                    {
                        tBrave.DoDamage(tSlime.GetAP());

                        cout << "Brave is damaged" << endl;
                    }
                    break;
                    case 4:
                    case 5:
                    case 6:
                    {
                        tSlime.DoDamge(tBrave.GetAP());

                        cout << "Slime is damaged." << endl;
                    }
                    break;
                    }

                    if (tSlime.GetHP() <= 0)
                    {
                        cout << "Slime is very tired." << endl;

                        break;
                    }
                    if (tBrave.GetHP() <= 0)
                    {
                        cout << "Brave is very tired." << endl;

                        break;
                    }
                }
            }
        }
        break;
        case 100:
        {
            cout << "Brave is in home." << "(You are on" << tBrave.GetX() << "Tile)" << endl;
        }
        break;
        case 200:
        {
            cout << "Brave is in End of world." << "(You are on" << tBrave.GetX() << "Tile)" << endl;
        }
        break;
        }
    }


    cout << "슬라임은 심심하다." << endl << "어서 빨리 일어나라! 용사!" << endl;


    return 0;
}

int GetWorldAttrib(int tWorld[], int index)
{
    return tWorld[index];
}