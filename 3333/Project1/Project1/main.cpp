#include "TwentyOnePoints.h"
int main()
{
    int choose = 1;
    TwentyOnePoints twentyOne;
    cout << "----------------------歡迎遊玩二十一點遊戲 ----------------------" << endl << endl;
    twentyOne.sortPoker();//洗牌
    while (true)
    {
        cout << "1->要牌 2->不要牌 請輸入數字選擇操作:";
        cin >> choose;
        if (choose == 1)
            twentyOne.AskF();
        else if (choose == 2)
            twentyOne.landlordProcess();
        else
            cout << "輸入範圍為1~2" << endl;
    }
}