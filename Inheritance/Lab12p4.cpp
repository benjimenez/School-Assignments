//Benjamin Jimenez


#include <iostream>
#include <string>
#define NUM_EMPLOYEES 6

using namespace std;


class Employee {
  string name;
  long salary;
public:
  Employee(string ename, long esalary)
  { name = ename; salary = esalary; }
  //virtual function
  virtual void show_info (){
  cout<<"Employee"<<endl; }
  string getName()
  { return name; }
  long GetSalary()
  { return salary; }
};

class Manager : public Employee{
protected:
  string degree;

public: 
  Manager(string mname, long msalary, string mdegree) : Employee(mname, msalary)
  { degree = mdegree; }
  void show_info()
  { cout<<getName()<<" "<<GetSalary()<<" "<<degree<<endl; }
};

class Worker : public Employee{
protected:
  string position;

public: 
  Worker(string wname, long wsalary, string wposition) : Employee(wname, wsalary)
  { position = wposition; }
  string GetPosition()
  { return position; }
  void show_info()
  { cout<<getName()<<" "<<GetSalary()<<" "<<position<<endl; }
};

class Officer : public Worker{
public:
  Officer(string oname, long osalary, string oposition) : Worker(oname, osalary, oposition) { ; }
  void show_info()
  { cout<<getName()<<" "<<GetSalary()<<" "<<GetPosition()<<endl; }
};

class Technician : public Worker{
public: 
  Technician(string tname, long tsalary, string tposition) : Worker(tname, tsalary, tposition) { ; }
  void show_info()
  { cout<<getName()<<" "<<GetSalary()<<" "<<GetPosition()<<endl; }
};

int main()
{
  int num;
  string name;
  long salary;
  string other;
  int choice;
  int choice2;


  cout<<"Enter number of employees: ";
  cin>>num;
  Employee *EmployeeList[num];
  cout << endl;

  int  next = 0;

  while(choice != 4)
  {
	cout << "1. Add employee (manager, officer, technician)"<<endl;
	cout << "2. Make a lsit of all employees introduced"<<endl;
	cout << "3. Search for a specific employee by name"<<endl;
	cout << "4. Exit the program.\n"<<endl;
	cout << "Enter number for choice: ";

	cin >> choice;

	switch(choice)
	{ case 1: if(next < num)
		  {
			cout << "1. Add manager"<<endl;
			cout << "2. add officer"<<endl;
			cout << "3. add technician"<<endl;
			cin >> choice2;
			cin.ignore();

		   switch (choice2)
                 { case 1:  cout<<"Name: ";
                            getline(cin,name);
                            cout<<endl<<"Salary: ";
                            cin>>salary;
                            cout<<endl;
                            cout<<"Degree: ";
                            cin.ignore(256, '\n');
                            getline(cin,other);
                            EmployeeList[next] = new Manager(name, salary, other);
                            break;
                   case 2:  cout<<"Name: ";
                            getline(cin,name);
                            cout<<endl<<"Salary: ";
                            cin>>salary;
                            cout<<endl;
                            cout<<"Position: ";
                            cin.ignore(256, '\n');
                            getline(cin,other);
                            EmployeeList[next] = new Officer(name, salary, other);
                            break;
                   case 3:  cout<<"Name: ";
                            cin>>name;
                            cout<<endl<<"Salary: ";
                            cin>>salary;
                            cout<<endl;
                            cout<<"Position: ";
                            cin.ignore(256, '\n');
                            getline(cin,other);
                            EmployeeList[next] = new Technician(name, salary, other);
                            break;
                 }
               next++;
               }
               else
                 cout<<"Max number of employees"<<endl;
               break;
      case 2:  for(int i = 0; i < num; i++)
               { cout<<endl;
                 EmployeeList[i]->show_info();
               }
               break;
      case 3: cout<<"Name: ";
              cin>>name;
              for(int i = 0; i < num; i++)
                if (EmployeeList[i]->getName() == name)
                { cout<<endl;
                  EmployeeList[i]->show_info();
                  cout<<endl;
                }
              break;
      case 4: break;
}
}




  return 0;
}
