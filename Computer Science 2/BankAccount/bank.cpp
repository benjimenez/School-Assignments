//Benjamin Jimenez

void Bank::zero()
{
	for(int i = 0; i < 10; i++)
    	{
		account[i] = 0;
	}
}

int Bank::deposit(int num, int value)
{
	/* puts funds into account */
	account[num] = account[num] + value;
}

int Bank::withdraw(int num, int value)
{
	if (account[num] < value)
	{
		cout << "Error, amount exceeds available funds.\n";
		return 0;
	}
	else
	{
		account[num] = account[num] - value;
		return 1;
	}
}

int Bank::balance(int num)
{
	int x = account[num];
	return x;
}

int Bank::transfer(int num1, int num2, int value)
{
	if (Bank::withdraw(num1, value) == 1)
	{
		Bank::deposit(num2, value);
	}
}
