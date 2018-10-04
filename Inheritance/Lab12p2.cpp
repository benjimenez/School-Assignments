//Benjamin Jimenez


#include <iostream>
#include <string>
using namespace std;

class Employee {
  string name; 
public:
  Employee(string ename)
  { name = ename; }
  //virtual function
  virtual void show_info (){
  cout<<"Employee"<<endl; }
  string getName()
  { return name; }
};

class Manager : public Employee{
public: 
  Manager(string mname) : Employee(mname) { ; }
  void show_info()
  { cout<<getName()<<endl; }
};

class Worker : public Employee{
public: 
  Worker(string wname) : Employee(wname) { ; }
  void show_info()
  { cout<<getName()<<endl; }
};

class Officer : public Employee{
public:
  Officer(string oname) : Employee(oname) { ; }
  void show_info()
  { cout << getName()<<endl; }
};

class Technician : public Employee{
public: 
  Technician(string tname) : Employee(tname) { ; }
  void show_info()
  { cout<<getName()<<endl; }
};


int main()
{
  Employee Rafa("Rafa"); Manager Mario("Mario"); Worker Anton("Anton");
  Officer Luis("Luis"); Technician Pablo("Pablo");

  Employee *pe; cout<<"\nInheritance and Polymorphism:\n"<<endl;

  pe = &Rafa; pe-> show_info();
  pe = &Mario; pe-> show_info();
  pe = &Anton; pe-> show_info();
  pe = &Luis; pe-> show_info();
  pe = &Pablo; pe-> show_info();

  cout<<"Ya he terminado."<<endl;

  return 0;
}