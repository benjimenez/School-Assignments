//Benjamin Jimenez

#include "bank.h"
#include "bank.cpp"

int main()
{
	Bank b;
        string input;
	int account, account2;
	int amount;

	b.zero();

        while ((input != "quit") || (input != "Quit"))
        {
                cout << "bank> ";
                cin >> input;

                if (input == "quit")
                {
                        break;
                }
                else if (input == "withdraw")
                {
                        cin >> account >> amount;
			b.withdraw(account, amount);
                }
                else if (input == "balance")
                {
			cin >> account;
			b.balance(account);
			cout << b.balance(account) << endl;
                }
                else if (input == "deposit")
                {
			cin >> account >> amount;
			b.deposit(account, amount);
                }
		else if (input == "transfer")
		{
			cin >> account >> account2 >> amount;
			b.transfer(account, account2, amount);
		}
                else
                {
                        cout << "Invalid command. Try again." << endl;
                }

        }

        return 0;
}

