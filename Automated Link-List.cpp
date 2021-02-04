#include <iostream> 
#include <string>
#include<vector>
using namespace std;

// Class that defines the node object
class Node {
private:
	string item;
	Node* nextPtr;

public:
	//constructors
	Node();
	Node(string);
	Node(string, Node*);

	//Accessor Methods
	void setItem(string);
	string getItem();
	void setNextPtr(Node*);
	Node* getNextPtr();

};


void printLists(Node* headPtr);


int main(void) {
	string input;
	char ans;

	Node* headPtr = new Node("");
	Node myNode;

	Node* curNodePtr = headPtr;

	do {
		cout << "Enter string :" << endl;
		getline(cin, input);
		curNodePtr->setNextPtr(new Node(input));
		curNodePtr = curNodePtr->getNextPtr();
		cout << "Would you like to keep going?(Y/N) " << endl;
		cin >> ans;
		cin.ignore();

	} while (ans == 'y'|| ans =='Y');

	printLists(headPtr);



	while (headPtr != nullptr) {
		curNodePtr = headPtr;
		headPtr = headPtr->getNextPtr();
		delete curNodePtr;

	}


	curNodePtr = headPtr; //both should be nullptr at the end

	printLists(headPtr);

	return (0);
}

void printLists(Node* beginningNodePtr) {

	Node* tempNodePtr = beginningNodePtr;

	cout << "******************" << endl;
	if (tempNodePtr == nullptr) {
		cout << "List is now Empty" << endl;
	}
	else {
		while (tempNodePtr->getNextPtr() != nullptr) {

			cout << tempNodePtr->getItem() << endl;
			tempNodePtr = tempNodePtr->getNextPtr();

		};
		cout << tempNodePtr->getItem() << endl;

	}
	cout << "******************" << endl;

}




//Node Implementation
Node::Node()
{
	setItem(""); //default to empty string
	setNextPtr(nullptr); //default to null pointer
}

Node::Node(string arg)
{
	setItem(arg);
	setNextPtr(nullptr);
}

Node::Node(string arg, Node* argPtr)
{
	setItem(arg);
	setNextPtr(argPtr);
}

void Node::setItem(string arg)
{
	item = arg;
}

string Node::getItem()
{
	return item;
}

void Node::setNextPtr(Node* argPtr)
{
	nextPtr = argPtr;
}

Node* Node::getNextPtr()
{
	return nextPtr;
}