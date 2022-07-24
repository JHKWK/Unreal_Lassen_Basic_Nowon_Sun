//
//  main.cpp
//  4_tiny_brave1d
//
//  Created by ryu on 2020/02/14.
//  Copyright © 2020 ryu. All rights reserved.
//


/*
 created by pokpoongryu


 지형속성:
 100    집
 200    세상의 끝
 1      슬라임 출몰 지역

 */

#include <iostream>
#include <time.h>

using namespace std;

struct SBrave
{
    int tBraveX = 0;
    float tBraveHP = 100;
    float tBraveAP = 1000;
};
struct SSlime
{
    float tSlimeHP = 200.0f;
    float tSlimeAP = 500.0f;
};

int GetWorldAttrib(int tWorld[], int index);
void DoMove(int* ta);
void DoBraveMove(SBrave* tBrave, int tDir);

int main()
{
    srand((unsigned int)time(nullptr));

    int tWorld[5] = { 100, 0, 1, 0, 200 };

    SBrave tBrave;
    SSlime tSlime;

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
            if (tBrave.tBraveX > 0)
            {
                DoBraveMove(&tBrave, -1);
                cout << "<--move left" << endl;
            }
            else
            {
                cout << "Brave can not move any more." << endl;
            }
        }

        if ('d' == tMoveDir)
        {
            if (tBrave.tBraveX < 4)
            {
                DoBraveMove(&tBrave, 1);
                cout << "-->move right" << endl;
            }
            else
            {
                cout << "Brave can not move any more." << endl;
            }
        }

        int tAttrib = 0;
        tAttrib = GetWorldAttrib(tWorld, tBrave.tBraveX);
        //tAttrib = tWorld[tBraveX];


        switch (tAttrib)
        {
        case 0: //아무것도 없음
        {
            cout << "No one here." << "(You are on" << tBrave.tBraveX << "Tile)" << endl;
        }
        break;
        case 1: //슬라임 있음
        {
            cout << "Slime is here." << "(You are on" << tBrave.tBraveX << "Tile)" << endl;

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
                        tBrave.tBraveHP = tBrave.tBraveHP - tSlime.tSlimeAP;

                        cout << "Brave is damaged" << endl;
                    }
                    break;
                    case 4:
                    case 5:
                    case 6:
                    {
                        tSlime.tSlimeHP = tSlime.tSlimeHP - tBrave.tBraveAP;

                        cout << "Slime is damaged." << endl;
                    }
                    break;
                    }

                    if (tSlime.tSlimeHP <= 0)
                    {
                        cout << "Slime is very tired." << endl;

                        break;
                    }
                    if (tBrave.tBraveHP <= 0)
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
            cout << "Brave is in home." << "(You are on" << tBrave.tBraveX << "Tile)" << endl;
        }
        break;
        case 200:
        {
            cout << "Brave is in End of world." << "(You are on" << tBrave.tBraveX << "Tile)" << endl;
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
void DoMove(int* ta)
{
    int tb;
    tb = *ta;
    tb++;
    *ta = tb;
}
void DoBraveMove(SBrave* tBrave, int tDir) 
{
    (* tBrave).tBraveX = (* tBrave).tBraveX + tDir;
    // (*tBrave).tBraveX  간접참조 방법1
    // tBrave->tBraveX    간접참조 방법2
}
