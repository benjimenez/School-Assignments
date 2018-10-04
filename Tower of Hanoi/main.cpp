//Benjamin Jimenez

#include <iostream>
#include <fstream>
using namespace std;

void tower(ofstream &o_file, int n, int source, int work, int dest);

int main()
{
	ofstream o_file; //create file
	o_file.open("output.txt");
	int disks; //Number of disks

	cout << "Enter number of disks: "; //prompt for disks
	cin >> disks; // disk input

	tower(o_file, disks, 0, 1, 2); // call for recursion //
	o_file.close(); //close file

	return 0;
}
//void tower function
void tower(ofstream &o_file, int n, int source, int work, int dest)
{
	if (n != 0)
	{
		if (work == 0){ //work peg = 0
			tower(o_file, n-1, source, work, dest); //src->dest using work
                        o_file << source << " -> " << work << endl;
			tower(o_file, n-1, dest, work, source); //dest->src using work
                        o_file << work << " -> " << dest << endl;
			tower(o_file, n-1, source, work, dest); //src->dest using work
		} //if work == 0

		else{
			tower(o_file, n-1, source, dest, work); //src->work using dest
			o_file << source << " -> " << dest << endl;
			tower(o_file, n-1, work, source, dest); //work->dest using src
		} //else
	} // if (n!=0)
}
