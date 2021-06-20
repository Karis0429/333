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
        pokerF[i] = 0;    //|��pokerOfFarmer��l��
        pokerL[i] = 0;    //|��pokerOfLandlord��l��
    }
    pokerNumF = 0;//���a�⤤���P�ƪ�l�Ƭ�0
    pokerNumL = 0;//���a�⤤���P�ƪ�l�Ƭ�0
    srand(time(0));
    for (i = 0; i < 1000; i++)
    {
        randNum[i] = rand() * 51 / 32767 + 1;//�����H���ư}�C
    }
}
void TwentyOnePoints::sortPoker()
{
    cout << "�s�@���C���}�l�A�}�l�~�P..." << endl;

    pokerF[0] = randNum[j++];  //����1-52���H����
    pokerF[1] = randNum[j++];  //����1-52���H����
    pokerL[0] = randNum[j++];  //����1-52���H����
    pokerL[1] = randNum[j++];  //����1-52���H����

    pokerNumF = 2;
    pokerNumL = 2;

    cout << "�~�P����,�A���P��:" << getPokerF() << endl;
}

string TwentyOnePoints::getPokerF()//�^�Ǫ��a���P
{
    int i;
    string result = "";

    for (i = 0; i < pokerNumF; i++)
        result = result + pokerName[pokerF[i]] + " ";

    return result;
}

string TwentyOnePoints::getPokerL()//�^�ǲ��a���P
{
    int i;
    string result = "";

    for (i = 0; i < pokerNumL; i++)
        result = result + pokerName[pokerL[i]] + " ";

    return result;
}

int TwentyOnePoints::getPointsF()//�^�Ǫ��a���`�I��
{
    int result = 0;

    for (int i = 0; i < pokerNumF; i++)
        result = result + pokerValue[pokerF[i]];

    return result;
}

int TwentyOnePoints::getPointsL()//�^�ǲ��a���`�I��
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
        cout << "�A���P�Ƥw��5�i�A����A�n�P�F" << endl;
        landlordProcess();
    }
    else
    {
        pokerF[pokerNumF++] = randNum[j++];   //����1-52���H����
        cout << "�A���P��:" << getPokerF() << endl;
        if (getPointsF() > 21)
        {
            cout << "�A�z�F,�A��F" << endl;
            cout << "�C������" << endl;
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
            cout << "���a���P��" << getPokerL() << endl;
            cout << "�AĹ�F" << endl;
            sortPoker();
        }
        else if (getPointsF() == getPointsL())
        {
            cout << "���a���P��" << getPokerL() << endl;
            cout << "����" << endl;
            sortPoker();
        }
        else
        {
            cout << "���a���P��" << getPokerL() << endl;
            cout << "�A��F" << endl;
            cout << "�C������" << endl;
            exit(0);
            sortPoker();
        }
    }
    else
    {
        pokerL[pokerNumL++] = randNum[j++];   //����1-52���H����
        if (getPointsL() > 21)
        {
            cout << "���a���P��" << getPokerL() << endl;
            cout << "���a�z�F,�AĹ�F" << endl;
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
            cout << "���a���P��" << getPokerL() << endl;
            cout << "���a��ӡA�A��F" << endl;
            cout << "�C������" << endl;
            exit(0);
            sortPoker();
        }
        else if (getPointsF() == getPointsL())
        {
            cout << "���a���P��" << getPokerL() << endl;
            cout << "�����C������" << endl;
            sortPoker();
        }
        else
        {
            cout << "���a���P��" << getPokerL() << endl;
            cout << "�AĹ�F" << endl;
            sortPoker();
        }
    }
    else
        AskL();
}