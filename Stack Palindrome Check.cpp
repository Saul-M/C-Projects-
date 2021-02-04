//Saul Martinez Valencia 
//Palindrome checker using stacks and the idea of LIFO

#include<iostream>
#include<stack>
#include<string>


using namespace std;

void printStack(stack<char>);
bool checkPalindrome(string word);

int main(void) {
	string word;
	char response;
	
	do {
		cout << "Enter string: ";
		getline(cin, word);
		if (checkPalindrome(word)) {
			cout << "The string is a Palindrome!" << endl;
		}
		else
			cout << "The word is not a Palindrome." << endl;

	
		
		cout << "Another string ? ";
		cin >> response;
		cin.ignore();
	} while (response == 'y' || response == 'Y');

	return 0;
}
void printStack(stack<char> arg)
{
	while (!arg.empty()) {

		cout << arg.top() << endl;
		arg.pop();
	}
}
bool checkPalindrome(string word) {
	stack<char> userString;

	string reverseWord = "";
	for (int i = 0; i < word.size(); i++) {
		userString.push(word[i]);
	}
	while (!userString.empty()) {
		reverseWord = reverseWord + userString.top();
		userString.pop();
	}

	if (word.size() == 1 || word.empty() == true) {
		return true;
	}
	else if (reverseWord == word)
		return true;
	else
		return false;
}