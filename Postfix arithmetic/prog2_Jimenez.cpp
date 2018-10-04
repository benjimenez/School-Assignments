//Benjamin Jimenez
#include <iostream>
#include <cctype>
#include <sstream>
#include <stack>
#include <string>
using namespace std;

string inToPostfix(const string& infix);
bool realchar(char currentOp);
bool precedence(char left, char right);

int main()
{       //prompts and stores string
        cout << "Enter the Arithmetic Expression: ";
        string infix, check;
        getline(std::cin, infix);
        //call to inToPostfix
    check = inToPostfix(infix);
    if (check == "error"){
        return 0;
    }
    else{
        cout << "Postfix: '" << check << "'\n";
    }

    return 0;
}
/* checks for operations that may be used */
bool isrealchar(char currentOp)
{
    switch (currentOp) {
        case '+':
        case '-':
        case '*':
        case '/':
        case '^':
            return true;
        default:
            return false;
    }
}
/* arranges operators correctly */
bool precedence(char left, char right)
    {
        if ( left == '^' ) {
            return true;
        } else if ( right == '^' ) {
            return false;
        } else if ( left == '*' || left == '/' ) {
            return true;
        } else if ( right == '*' || right == '/' || right ) {
            return false;
        }

        return true;
    }
/* converts infix to postfix  */
string inToPostfix(const string& infix)
{
    stringstream output; // return string
    string error = "error"; //for error check
    int i = 0;
    stack<char> mystack; //declare stack
    mystack.push('(');

    /* runs through each char in string */
    for(i = 0; i < infix.length(); i++) {
        const char current = infix[i];

        if (isspace(current)) {
            // do not store spaces
        }

        else if(isdigit(current)) {
            cout << "This program does not accept digits.\n"; //error check
            cout << "Only lower case letters and operators. Good bye.\n";
            return error; //returns error string
        }

        else if(isalpha(current)) {
            if (islower(current)){
                output << current; //output to stream
            }
            else{
                cout << "You entered an upper case letter.\n"; //error check
                cout << "This program only accepts lower case letters. Good Bye.\n";
                return error; //retursn error string
            }
        }

        else if('(' == current) {
            mystack.push(current); //push ( onto stack
        }
        /* operator */
        else if(isrealchar(current)) {
            while(!mystack.empty() && isrealchar(mystack.top()) && precedence(mystack.top(), current)) {
            output << mystack.top();
            mystack.pop();
            }
            mystack.push(infix[i]);
        }

        //right parent
        else if(')' == current) {
            //top of stack is not a left parent
            while(!mystack.empty() && '(' != mystack.top()) {
            output << mystack.top();
            mystack.pop();
            }

        // get rid of left parent
        mystack.pop();
        }
        else
        {
            cout << "Invalid operation. Good bye.\n"; //error check
            return error;
        }
    }
        //closing left parent
        while(!mystack.empty() && '(' != mystack.top()) {
        output << mystack.top();
        mystack.pop(); //pop stack
        }
        //get rid of left parent
        mystack.pop();

    return output.str(); //returns final stringstream
}
