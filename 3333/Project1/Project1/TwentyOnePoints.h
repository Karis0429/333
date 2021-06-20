#ifndef TwentyOnePoints_h
#define TwentyOnePoints_h
#include <iostream>
#include <string>
#include <cstdlib>
#include <time.h>
using namespace std;
class TwentyOnePoints
{
private:
    int poker[53];     //撲克牌總數
    int pokerValue[53]; //撲克代表的數值
    string pokerName[53]; //撲克A~K
    int pokerF[5];   //玩家手中的牌
    int pokerL[5];   //莊家手中的牌
    int pokerNumF;   //玩家手中的牌數
    int pokerNumL;   //莊家手中的牌數
public:
    TwentyOnePoints();
    void sortPoker();  //洗牌,在每輪遊戲開始前進行
    string getPokerF();  //回傳玩家的牌
    string getPokerL();  //回傳莊家的牌
    int getPointsF();       //回傳玩家牌的點數
    int getPointsL();       //回傳莊家牌的點數
    void AskF();         //玩家要牌
    void AskL();         //莊家要牌
    void landlordProcess();//在玩家不要牌時進行處理
};
#endif