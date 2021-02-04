#include<iostream>
#include <windows.h>
#include<queue>
#include<string>

using namespace std;

class Person {
private:
	string name;
public:
	Person(string a);
	
	void setName(string a);
	string getName();
};

class Customer :public Person {
private:
	string phoneNumber;
public:
	Customer(string a= "None", string b="None");
	void setNumber(string b);
	string getNumber();
	
};
void diplayCurrentCustomer(queue<Customer*>a);
void completeOrder(queue<Customer*> &a);
void createNewOrder(queue<Customer*> &a, string& name, string& number);
void visualMenu(queue<Customer*> a);

int main() {
	int option;
	bool off = false;
	queue<Customer*> customerLine;
	string name, number;

	do {
		visualMenu(customerLine);
		
		cin >> option;
		cin.ignore();
		
		
		switch (option) {
		case(1):
			system("CLS");
			createNewOrder(customerLine, name,number);
			system("CLS");
			break;
		case(2):
			if (!customerLine.empty()) {
				system("CLS");
				completeOrder(customerLine);
				Sleep(1000);
				system("CLS");
			}
			else {
				system("CLS");
				cout << "The line is empty" << endl;
				Sleep(1000);
				system("CLS");
			}
			break;
		case(3):
			off = true;
			break;
		default:
			cout << "Invalid input" << endl;
			break;
		}
	} while (off != true);

	return 0;
}

Person::Person(string a)
{
	setName(a);
}

void Person::setName(string a)
{
	name = a;
}

string Person::getName()
{
	return name;
}

Customer::Customer(string a, string b):Person( a)
{
	setName(a);
	setNumber(b);

}

void Customer::setNumber(string b)
{
	phoneNumber = b;
}

string Customer::getNumber()
{
	return phoneNumber;
}





void diplayCurrentCustomer(queue<Customer*> a)
{
	cout << "Current customer: "<< a.front()->getName()
		<< endl;
	cout << "Phone Number: " << a.front()->getNumber()<<endl; 
	
}

void completeOrder(queue<Customer*> &a)
{
	cout << "Completed order for: "<<a.front()->getName()
		<<endl;
	cout << "Phone Number: " << a.front()->getNumber()<<endl;
	
	delete a.front();
	a.pop();

}

void createNewOrder(queue<Customer*> &a ,string& name, string& number)
{
	

	cout << "Whats the customer name? : ";
	getline(cin, name);
	
	cout << "\nWhats the the customer's phone number (###)###-####? : ";
	getline(cin, number);
	
	a.push(new Customer(name, number));


}

void visualMenu(queue<Customer*> a )
{
	cout << "--------Menu--------" << endl;
	cout << "[1] - Add new order" << endl;
	cout << "[2] - Complete an order" << endl;
	cout << "[3] - Quit" << endl;
	cout << "--------------------" << endl;
	if (!a.empty()) {
		diplayCurrentCustomer(a);
	}
	else {
		cout << "Current customer: None" <<
			"\nPhone number: None" << endl;

	}

	cout << "Pick a Number" << endl;
	
}
