#include<iostream>
#include<list>
#include<cstdlib>
#include<ctime>

using namespace std;

list<int>::iterator searchListBinary(list<int>& arg, int target);
list<int>::iterator searchListLinear(list<int>& arg, int target);


int main(void) {

	srand((unsigned)time(0));
	int const sizeOfList = 100;
	char response = 'y';
	list<int> myList;
	list<int>::iterator itr = myList.begin();
	do {
		int randNumber = (rand() % 300 + 1);

		myList.push_back(randNumber);
		myList.sort();
		myList.unique();
	} while (myList.size() != sizeOfList);

	do {
		system("CLS");
		int numberToSearch;
		cout << "What number would you like to search ? " << endl;
		cin >> numberToSearch;
		list<int>::iterator binaryItr = searchListBinary(myList, numberToSearch);
		list<int>::iterator linearItr = searchListLinear(myList, numberToSearch);

		cout << "===========================" << endl;
		for (itr = myList.begin(); itr != myList.end(); itr++) {
			cout << *itr << endl;
		}
		cout << "===========================" << endl;
		cout << "Numbers inside the List ^" << endl;

		if (binaryItr != myList.end()) {
			cout << "Found! - Through binary" << endl;
		}
		else
			cout << "Not found !" << endl;

		if (linearItr != myList.end()) {
			cout << "Found! - Through linear" << endl;
		}
		else
			cout << "Not found !" << endl;

		cout << "Would you like to try again ?" << endl;
		cin >> response;
		cin.ignore();

	} while (response == 'y' || response == 'Y');

	return(0);
}

list<int>::iterator searchListBinary(list<int>& arg, int target) {
	if (target < arg.front() || target > arg.back()) {
		return arg.end();
	}
	list<int>::iterator start = arg.begin();
	list<int>::iterator finish = arg.end();
	finish--;
	int mid = arg.size() / 2;
	while (*start <= *finish) {
		list<int>::iterator targetItr = start;

		advance(targetItr, mid);

		if (target == *targetItr) {
			return targetItr;
		}
		if (target < *targetItr) {
			finish = --targetItr;
		}
		else {
			start = ++targetItr;
		}
		mid = (mid - 1) / 2;
	}
	return arg.end();
}
list<int>::iterator searchListLinear(list<int>& arg, int target)
{
	list<int>::iterator linearItr = arg.begin();
	for (linearItr = arg.begin(); linearItr != arg.end(); linearItr++) {
		if (*linearItr == target) {
			return linearItr;
		}
	}
	return linearItr;
}
