#include "Blockchain.h"

int main()
{
    Blockchain BlockChain;

    while (true)
    {
        cout << "Transfering Money:  1" << endl;
        cout << "See a block data:   2" << endl;
        cout << "See The Blockchain: 3" << endl;
        cout << "Close the program:  4" << endl;
        cout << "Choose a number:" << endl;
        char Ans;
        cin >> Ans;
        if (Ans == '1')
        {
            string SenderKey, ReceiverKey;
            double Amount;
            int Diff;
            cout <<  "Enter Your SenderKey:" << endl;
            cin >> SenderKey;
            cout <<  "Enter Your ReceiverKey:" << endl;
            cin >> ReceiverKey;
            cout <<  "Enter The Amount:" << endl;
            cin >> Amount;
            cout <<  "Enter Your Difficulty or zero to ignore:" << endl;
            cin >> Diff;

            Transaction T1(SenderKey, ReceiverKey, Amount);
            
            if (Diff == 0)
            {
                Block block(T1, BlockChain.get_BlockChain()[BlockChain.get_BlockChain().size() - 1].get_CurrentHash(), BlockChain.get_BlockChain().size());

                BlockChain.AddBlock(block);

                BlockChain.CheckHash(block.get_index() - 1, block.get_PrevHash());
            }
            else
            {
                Block block(T1, BlockChain.get_BlockChain()[BlockChain.get_BlockChain().size() - 1].get_CurrentHash(), BlockChain.get_BlockChain().size(), Diff);

                BlockChain.AddBlock(block);

                BlockChain.CheckHash(block.get_index() - 1, block.get_PrevHash());
            }
        }
        else
        {
            switch (Ans)
            {
            case '2':
                cout << "Enter your index:" << endl;
                int index;
                cin >> index;
                if (index > BlockChain.get_BlockChain().size() || index < 1)
                {
                    cout << "\n====== There Is No Block With This Index! ======\n" << endl;
                }
                else
                {
                    BlockChain.ShowBlock(index - 1);
                }                
                break;
            case '3':
                cout << "Sakhtan" << endl;
                break;
            case '4':
                    BlockChain.ShowBlockchain();
                break;
            default:
                cout << "Wrong Choice!" << endl;
                break;
            }
        }
    }
}