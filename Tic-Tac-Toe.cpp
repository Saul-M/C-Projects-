#include<iostream>
#include<string>

using namespace std;

string board[9] = { " " , " ", " " , " ", " " , " ", " " , " ", " " };
int player = 1;


void introToGame();
bool checkForWinner();
bool checkifFilled();
void playmove();
void updateBoard(int);
void changePlayer();
void takeTurn();


int main(void) {



	introToGame();
	takeTurn();



	return 0;
}

void introToGame()
{
	cout << "------------------------"<<endl;
	cout << "Welcome to tic tac toe! "<<endl;
	cout << "------------------------"<<endl;
	cout << "\n\n Press Enter " << endl;
	cin.ignore();

	cout << "The game is based on a 3x3 board " << endl;
	cout << " 1  | 2  | 3  " << endl;
	cout << "____|____|____" << endl;
	cout << " 4  | 5  | 6  " << endl;
	cout << "____|____|____" << endl;
	cout << "    |    |    " << endl;
	cout << " 7  | 8  | 9  " << endl;


}

bool checkForWinner()
{
	
	//Row winner 
	if (board[0] == board[1] && board[0] == board[2] && board[0] != " ")
		return true;
	if (board[3] == board[4] && board[3] == board[5] && board[3] != " ")
		return true;
	if (board[6] == board[7] && board[6] == board[8] && board[6] != " ")
		return true;
	//down 
	if (board[0] == board[3] && board[0] == board[6] && board[0] != " ")
		return true;
	if (board[1] == board[4] && board[1] == board[7] && board[1] != " ")
		return true;
	if (board[2] == board[5] && board[2] == board[8] && board[2] != " ")
		return true;
	//diagnal
	if (board[0] == board[4] && board[0] == board[8] && board[0] != " ")
		return true;
	if (board[2] == board[4] && board[2] == board[6] && board[2] != " ")
		return true;
	
	return false;
}

bool checkifFilled()
{
	for (int i = 0; i < 9; i++) {
		if (board[i] == " ")
			return false;
	}

	return true;
}

void playmove()
{
	int postion;

	cout << "It Players: " << player << "'s turn." << endl;
	cout << "Enter a number between 1-9: ";
	cin >> postion;
	
	while (!(postion <= 9 && postion >= 1)){
		cout << "\nTry again please: ";
		cin >> postion;
	}

	while (board[postion - 1] != " ") {
		cout << "\nSorry theres already something there. " << endl;
		cout << "Try again: ";
		cin >> postion;
	}

	updateBoard(postion);


}

void updateBoard(int argPosition)
{
	if (player == 1)
		board[argPosition -1] = "x";
	else
		board[argPosition -1] = "o";
	system("CLS");
	cout << " "<<board[0]  <<"  | "<< board[1] <<"  | "<< board[2] <<"  " << endl;
	cout << "____|____|____" << endl;
	cout << " " << board[3] << "  | " << board[4] << "  | " << board[5] << "  " << endl;
	cout << "____|____|____" << endl;
	cout << "    |    |    " << endl;
	cout << " " << board[6] << "  | " << board[7] << "  | " << board[8] << "  " << endl;
}

void changePlayer()
{
	if (player == 1)
		player++;
	else
		player--;
}

void takeTurn()
{
	while (!checkForWinner() && !checkifFilled()) {
		playmove();
		changePlayer();
	}

	if (checkForWinner())
		cout << "\n\nNice theres a winner! ";
	else
		cout << "\n\nGame is a tie! ";
}
