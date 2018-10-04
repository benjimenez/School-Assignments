//Benjamin Jimenez

#include <iostream>
#include <cstring>
#include <algorithm>
#include <fstream>
using namespace std;
int SIZE = 256;

int main()
{
	ofstream out;
        int a, b;
       	int i, j;
	char str1[SIZE], str2[SIZE];

	out.open("output.txt");

	cout << "> ";
	cin >> str1;

	cout << "> ";
	cin >> str2;

	i = strlen(str1);
        j = strlen(str2);

	int table[i+1][j+1];

	out << "    ";
	for(a=0;a<=j;a++){ out << a << " "; }
	out << "\n      ";
	for(a=0;a<j;a++){ out << str2[a] << " "; }
	out << endl;
        for (a = 0; a <= i; a++)
        {
		if (a != 0) {out << a << " " << str1[a-1] << " "; }
		else {out << a << "   ";}
                for (b=0; b <= j; b++)
                {
                        if ((a==0) || (b==0)){
				table[a][b] = 0;
				out << table[a][b];
                        }
			else if(str1[a-1] == str2[b-1]){
				table[a][b] = table[a-1][b-1] + 1;
				out << table[a][b];
			}
			else{
				table[a][b] = max(table[a-1][b], table[a][b-1]);
				out << table[a][b];
			}
			out << " ";
                }
                out << endl;
        }
	int num = table[i][j];
	char sub[num + 1];
	sub[num] = '\0';

	a=i;
	b=j;

	while ((a>0) && (b>0)){
		if (str1[a-1] == str2[b-1]){
			sub[num-1] = str1[a-1];
			num--; a--; b--;
		}
		else if (table[a-1][b] > table[a][b-1]){
			a--;
		}
		else{
			b--;
		}
	}
	cout << "Longest common substring has length " << table[i][j];
	cout << ": \"" << sub << "\"\n";

	out.close();

	return 0;
}

