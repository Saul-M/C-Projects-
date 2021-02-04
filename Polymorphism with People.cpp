#include<iostream>
#include<string>
#include<vector>


using namespace std;

class Person {

private:

	string personName;

public:
	Person(string fName);
	//Using set and get methods because thats pro stuff 
	void setName(string);
	string getName(void);
	//This is a pure virtual method that can be overwritten
	//the "=0" is maling sure that is we maded any other class we 
	//have to the code ourselves 
	virtual void display(void) = 0;



};

//Derving the student class from person 
class Student :public Person {
private:
	int Id;
	double gpa;
public:
	Student(string fName, int id, double argGpa);
	void setId(int);
	int getId(void);
	void setGpa(double);
	double getGpa(void);
	void display(void);
};

class Althele :public Person {
private:
	string sport;
	int Id;

public:
	Althele(string Name, int id, string argSport);
	void setId(int);
	int getId(void);
	void setSport(string);
	string getSport(void);
	void display(void);
};

class Employee : public Person {
private:
	int Id;
	double salary;

public:
	Employee(string Name, int id, double argSalary);
	void setId(int);
	int getId(void);
	void setSalary(double);
	double getSalary(void);
	void display(void);
};

int main(void) {
	//Dynamiclly allocating it using vectors
	vector<Person*> studentList;

	//This is adding "new" objects pointers to the vector
	studentList.push_back(new Student("Saul Martinez", 33540, 3.7));
	studentList.push_back(new Althele("Brandon Valencia", 35689, "FootBall"));
	studentList.push_back(new Employee("Jorge Martin", 35689, 90000));


	for (int i = 0; i < studentList.size(); i++) {
		//This is the Polymorphism
		studentList[i]->display();
		cout << "-----------------------------------------" << endl;
	}
	for (int i = 0; i < studentList.size(); i++) {
		//This is making sure that theres no memory leaks
		studentList[i] = NULL;
	}


	system("pause");
	return 0;
}


Person::Person(string fName)
{
	setName(fName);
}

void Person::setName(string fName)
{
	personName = fName;
}

string Person::getName(void)
{
	return personName;
}


Student::Student(string fName, int id, double argGpa):Person(fName)
{
	setId(id);
	setGpa(argGpa);
}

void Student::setId(int id)
{
	Id = id;
}

int Student::getId(void)
{
	return Id;
}

void Student::setGpa(double argGpa)
{
	gpa = argGpa;
}

double Student::getGpa(void)
{
	return gpa;
}




void Student::display(void)
{
	cout << "Student: " << getName() << endl;
	cout << "Id number: " << getId() << endl;
	cout << "Has a gpa of " << getGpa() << endl;
	
	
}

Althele::Althele(string Name, int id, string argSport):Person(Name)
{
	setId(id);
	setSport(argSport);
}

void Althele::setId(int id)
{
	Id = id;
}

int Althele::getId(void)
{
	return Id;
}

void Althele::setSport(string argSport)
{
	sport = argSport;
}

string Althele::getSport(void)
{
	return sport;
}

void Althele::display(void)
{
	cout << "Althele: " << getName() << endl;
	cout << "ID number: " << getId() << endl;
	cout << "Plays the sport " << getSport() << endl;
}

Employee::Employee(string Name, int id, double argSalary):Person(Name)
{
	setId(id);
	setSalary(argSalary);
}

void Employee::setId(int id)
{
	Id = id;
}

int Employee::getId(void)
{
	return Id;
}

void Employee::setSalary(double argSalary)
{
	salary = argSalary;
}

double Employee::getSalary(void)
{
	return salary;
}

void Employee::display(void)
{
	cout << "Employee: " << getName() << endl;
	cout << "Id number: " << getId() << endl;
	cout << "Has a salary of " << getSalary() << endl;

}
