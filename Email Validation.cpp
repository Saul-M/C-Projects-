//Saul Martinez 
//3/25/20
#include<iostream>
#include<string>
#include<list>

using namespace std;

bool isEmailValid(string);

int main(void) {


	string userEmail;
	char response = 'y';

	do {
		cout << "Type in email to check if its valid." << endl;
		getline(cin, userEmail);
		try {
			if (isEmailValid(userEmail))
				cout << "It valid" << endl;
			else
				cout << "Not valid" << endl;
		}
		catch(exception e){
			cout << "Error: " << e.what();
		}
		
		cout << "\nWould you like to try again? " << endl;
		cin >> response;
		cin.ignore();
	} while (response == 'y' || response == 'Y');

	//ask for user email *done*


	//check for @ if not invaild so try / throw functions
	//check for the given email names if no match then invaild 
	//use the find / size / maybe substrc 

	//if vaild print out true 




	return 0;
}

bool isEmailValid(string email)
{
	
	string emailExtension;
	
	list<string> validEmailExtensions = { "@gmail.com", "@aol.com","@cos.edu", "@giant.cos.edu" };
	list<string>::iterator itr = validEmailExtensions.begin();

	if (email.find('@') == string::npos) {
		throw exception("Email has no @");
	}else 
		emailExtension = email.substr(email.find('@'), email.length());

	for (itr; itr != validEmailExtensions.end(); itr++) {
		if (emailExtension == *itr) {
			return true;
		}
		//I had no idea that you didnt ask for this and not only that but the whole function in it self was 
		//alreadying checking if the email was valid

		/*if (emailExtension != validEmailExtensions.back()) {
			throw exception("No such domain.");
		}
		*/
	}
	
	
	
	return false;

}
