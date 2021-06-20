#include "TwentyOnePoints.h"
int j = 2;
int randNum[1000];
TwentyOnePoints::TwentyOnePoints()
{
    poker[0] = 0;
    pokerValue[0] = 0;
    pokerName[0] = "";
    int i;
    for (i = 1; i <= 13; i++)
    {
        poker[i] = i;
        poker[i + 13] = i;
        poker[i + 26] = i;
        poker[i + 39] = i;
    }
    for (i = 1; i <= 52; i++)
    {
        if (poker[i] <= 10)
            pokerValue[i] = poker[i];
        else
            pokerValue[i] = 10;
    }
    for (i = 0; i < 4; i++)
    {
        pokerName[1 + 13 * i] = "A";
        pokerName[2 + 13 * i] = "2";
        pokerName[3 + 13 * i] = "3";
        pokerName[4 + 13 * i] = "4";
        pokerName[5 + 13 * i] = "5";
        pokerName[6 + 13 * i] = "6";
        pokerName[7 + 13 * i] = "7";
        pokerName[8 + 13 * i] = "8";
        pokerName[9 + 13 * i] = "9";
        pokerName[10 + 13 * i] = "10";
        pokerName[11 + 13 * i] = "J";
        pokerName[12 + 13 * i] = "Q";
        pokerName[13 + 13 * i] = "K";
    }
    for (i = 0; i < 5; i++)
    {
        pokerF[i] = 0;    //|對pokerOfFarmer初始化
        pokerL[i] = 0;    //|對pokerOfLandlord初始化
    }
    pokerNumF = 0;//玩家手中的牌數初始化為0
    pokerNumL = 0;//莊家手中的牌數初始化為0
    srand(time(0));
    for (i = 0; i < 1000; i++)
    {
        randNum[i] = rand() * 51 / 32767 + 1;//產生隨機數陣列
    }
}
void TwentyOnePoints::sortPoker()
{
    cout << "新一局遊戲開始，開始洗牌..." << endl;

    pokerF[0] = randNum[j++];  //產生1-52的隨機數
    pokerF[1] = randNum[j++];  //產生1-52的隨機數
    pokerL[0] = randNum[j++];  //產生1-52的隨機數
    pokerL[1] = randNum[j++];  //產生1-52的隨機數

    pokerNumF = 2;
    pokerNumL = 2;

    cout << "洗牌完成,你的牌為:" << getPokerF() << endl;
}

string TwentyOnePoints::getPokerF()//回傳玩家的牌
{
    int i;
    string result = "";

    for (i = 0; i < pokerNumF; i++)
        result = result + pokerName[pokerF[i]] + " ";

    return result;
}

string TwentyOnePoints::getPokerL()//回傳莊家的牌
{
    int i;
    string result = "";

    for (i = 0; i < pokerNumL; i++)
        result = result + pokerName[pokerL[i]] + " ";

    return result;
}

int TwentyOnePoints::getPointsF()//回傳玩家的總點數
{
    int result = 0;

    for (int i = 0; i < pokerNumF; i++)
        result = result + pokerValue[pokerF[i]];

    return result;
}

int TwentyOnePoints::getPointsL()//回傳莊家的總點數
{

    int result = 0;

    for (int i = 0; i < pokerNumL; i++)
        result = result + pokerValue[pokerL[i]];

    return result;
}

void TwentyOnePoints::AskF()
{
    if (pokerNumF >= 5)
    {
        cout << "你的牌數已有5張，不能再要牌了" << endl;
        landlordProcess();
    }
    else
    {
        pokerF[pokerNumF++] = randNum[j++];   //產生1-52的隨機數
        cout << "你的牌為:" << getPokerF() << endl;
        if (getPointsF() > 21)
        {
            cout << "你爆了,你輸了" << endl;
            cout << "遊戲結束" << endl;
            exit(0);
            sortPoker();
        }
        else if (getPointsF() == 21)
        {
            landlordProcess();
        }
    }
}

void TwentyOnePoints::AskL()
{
    if (pokerNumL >= 5)
    {
        if (getPointsF() > getPointsL())
        {
            cout << "莊家的牌為" << getPokerL() << endl;
            cout << "你贏了" << endl;
            sortPoker();
        }
        else if (getPointsF() == getPointsL())
        {
            cout << "莊家的牌為" << getPokerL() << endl;
            cout << "平手" << endl;
            sortPoker();
        }
        else
        {
            cout << "莊家的牌為" << getPokerL() << endl;
            cout << "你輸了" << endl;
            cout << "遊戲結束" << endl;
            exit(0);
            sortPoker();
        }
    }
    else
    {
        pokerL[pokerNumL++] = randNum[j++];   //產生1-52的隨機數
        if (getPointsL() > 21)
        {
            cout << "莊家的牌為" << getPokerL() << endl;
            cout << "莊家爆了,你贏了" << endl;
            sortPoker();
        }
        else
            landlordProcess();
    }
}
void TwentyOnePoints::landlordProcess()
{
    if (getPointsL() >= 17)
    {
        if (getPointsL() > getPointsF())
        {
            cout << "莊家的牌為" << getPokerL() << endl;
            cout << "莊家獲勝，你輸了" << endl;
            cout << "遊戲結束" << endl;
            exit(0);
            sortPoker();
        }
        else if (getPointsF() == getPointsL())
        {
            cout << "莊家的牌為" << getPokerL() << endl;
            cout << "本次遊戲平手" << endl;
            sortPoker();
        }
        else
        {
            cout << "莊家的牌為" << getPokerL() << endl;
            cout << "你贏了" << endl;
            sortPoker();
        }
    }
    else
        AskL();
}