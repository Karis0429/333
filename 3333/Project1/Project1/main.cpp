#include "TwentyOnePoints.h"
int main()
{
    int choose = 1;
    TwentyOnePoints twentyOne;
    cout << "----------------------�w��C���G�Q�@�I�C�� ----------------------" << endl << endl;
    twentyOne.sortPoker();//�~�P
    while (true)
    {
        cout << "1->�n�P 2->���n�P �п�J�Ʀr��ܾާ@:";
        cin >> choose;
        if (choose == 1)
            twentyOne.AskF();
        else if (choose == 2)
            twentyOne.landlordProcess();
        else
            cout << "��J�d��1~2" << endl;
    }
}