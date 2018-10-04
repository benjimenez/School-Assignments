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
  Employee* EmployeeList[NUM_EMPLOYEES];

  EmployeeList[0] = new Manager("Carla Garcia", 35000, "Economist");
  EmployeeList[1] = new Manager("Juan Perez", 38000, "Engineer");
  EmployeeList[2] = new Officer("Pedro Egia", 18000, "Officer 1");
  EmployeeList[3] = new Officer("Luisa Penia", 15000, "Officer 2");
  EmployeeList[4] = new Technician("Javier Ramos", 19500, "Welder");
  EmployeeList[5] = new Technician("Amaia Bilbao", 12000, "Electricist");

  for (int i = 0; i<NUM_EMPLOYEES; i++)
  {
	EmployeeList[i]->show_info();
  }

  return 0;
}