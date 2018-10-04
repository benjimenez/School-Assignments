//Benjamin Jimenez

#include <iostream>
#include <string>

using namespace std;

class Bank{
	private:
	int account[10];

	public:
	void zero();
	int deposit(int num, int value);
	int withdraw(int num, int value);
	int balance(int num);
	int transfer(int num1, int num2, int value);
};

