//Benjamin Jimenez

#include <iostream>
#include <strstream>   // for string streams
#include <string>
#include <stack>
using namespace std;


static const int MAX_INPUT = 256;


int main()
{
    char buf[MAX_INPUT];
    string line = "";
    string word;
	string entry;
	char letter;
	
    cout << "enter a line: ";

    cin.getline( buf, MAX_INPUT );
    line = buf;
    
    // open a stream bound to the line
    istrstream input( line.c_str() ); 

	input>>letter;
 	input>>entry;
	switch(letter)
	{
		case 'a':
		case 'e':
		case 'i':
		case 'o':
		case 'u':
		cout << letter << entry <<"yay\n";
		break;

		default:
		cout << entry << letter << "ay\n";
		break;
	}

    return 0;
}
