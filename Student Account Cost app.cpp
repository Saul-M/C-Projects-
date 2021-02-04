#include<iostream>
#include<string>
#include<vector>


using namespace std;

class Person {

private:

	string personName;

public:
	
	void setName(string);
	string getName(void);
	virtual double calculateNewBalance(void)=0;
	virtual void Getinfo(void)=0;

	

};

class Student :public Person {
private:
	int Id, totalUnit;
	double totalBalance ;
public:
	Student(string Name, int id, int addedunits, double balance, double withdraw = 0 , double deposit = 0);
	
	
	void setId(int);
	int getId(void);
	void setUnits(int);
	int getUnits(void);
	void setBalance(double);
	double getBalance(void);
	double calculateUnitCharge(void);
	void depositBalance(double);
	void withdrawBalance(double);
	double calculateNewBalance(void);
	void Getinfo(void);

	
};


int main(void) {

	vector<Student*> studentList;

	studentList.push_back(new Student("Saul Martinez", 33540, 12, 0, 0, 400));
	studentList.push_back(new Student("Brandon Valencia", 35689, 12, 150, 50,0));

	for (int i = 0; i < studentList.size(); i++) {
		//studentList[i]->Getinfo();
		cout << "Student " << i << " Statement " << endl;
		cout << "Total balance after withdraw/deposits:"<<studentList[i]->getBalance() << endl;
		cout << "Total amount owed with Units:  "<<studentList[i]->calculateUnitCharge()<< endl;
		cout << "What is owed after units charged :" << studentList[i]->calculateNewBalance() << endl;
		cout << "------------------------------------" << endl;
	}

	for (int i = 0; i < studentList.size(); i++) {
		studentList[i] = NULL;
	}


	system("pause");
	return 0;
}


void Person::setName(string fName)
{
	personName = fName;
}

string Person::getName(void)
{
	return personName;
}



Student::Student(string Name, int id, int addedunits, double balance, double withdraw, double deposit)
{
	setName(Name);
	setId(id);
	setUnits(addedunits);
	setBalance(balance);
	withdrawBalance(withdraw);
	depositBalance(deposit);
	
	
}

void Student::setId(int id)
{
	Id = id;
}

int Student::getId(void)
{
	return Id;
}

void Student::setUnits(int units)
{
	totalUnit = units;
}

int Student::getUnits(void)
{
	return totalUnit;
}

void Student::setBalance(double balance)
{
	totalBalance = balance;
}

double Student::getBalance(void)
{
	return totalBalance;
}

double Student::calculateUnitCharge(void)
{
	double charge = getUnits() * 46.0;
	return charge;
}

void Student::depositBalance(double deposit)
{
	totalBalance = totalBalance + deposit;
}

void Student::withdrawBalance(double withdraw)
{
	totalBalance = totalBalance - withdraw;
}

double Student::calculateNewBalance(void)
{
	double costPerUnit = 46;
	double endBalance = (getBalance() - calculateUnitCharge())* -1;
	return endBalance;
}

void Student::Getinfo(void)
{
	cout << "Student: " << getName()<< endl;
	cout << "Id#: " << getId() << endl;
	cout << "Number of units " << getUnits() << endl;
	cout << "The starting the balance was " << getBalance() <<endl;
	cout << "The final balance after units is " << calculateNewBalance() << endl;
}
