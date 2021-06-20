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
    int poker[53];     //���J�P�`��
    int pokerValue[53]; //���J�N���ƭ�
    string pokerName[53]; //���JA~K
    int pokerF[5];   //���a�⤤���P
    int pokerL[5];   //���a�⤤���P
    int pokerNumF;   //���a�⤤���P��
    int pokerNumL;   //���a�⤤���P��
public:
    TwentyOnePoints();
    void sortPoker();  //�~�P,�b�C���C���}�l�e�i��
    string getPokerF();  //�^�Ǫ��a���P
    string getPokerL();  //�^�ǲ��a���P
    int getPointsF();       //�^�Ǫ��a�P���I��
    int getPointsL();       //�^�ǲ��a�P���I��
    void AskF();         //���a�n�P
    void AskL();         //���a�n�P
    void landlordProcess();//�b���a���n�P�ɶi��B�z
};
#endif