//Benjamin Jimenez

#include <iostream>
#include <string>

using namespace std;

int main()
{
	string input;

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
			cout << "WITHDRAW SELECTED" << endl;
		}
		else if (input == "balance")
		{
			cout << "BALANCE SELECTED" << endl;
		}
		else if (input == "deposit")
		{
                        cout << "DEPOSIT SELECTED" << endl;
		}
		else
		{
			cout << "Command invalid. Try again." << endl;
		}

	}




	return 0;
}
