#include <iostream>
#include <string>
#include <cstdlib>
#include <ctime>
using namespace std;
int totalScore;
// This is the set list of words that will be scrambled 
namespace scramble {
	const string words[10] = {
		"programming", "static" , "namespace" , "while" , "for", "void" , "bool" , "class" , "else" , "float"
	};
	// This will store the hints that are related to the scrambled words
	const string hints[10] = {
		"What computer scientists do.",
		"Made to optimize hardware efficiency.",
		"Used to organize too many classes.",
		"A form of loop, used to execute a block of code repeatdly.",
		"A form of loop, loops with a set condition and continues to do so until the condition is met.",
		"Used to declare a function.",
		"Used to declare variables to store.",
		"Defines the kind of data and functionality their objects will have.",
		"if then...",
		"A variable type used for storing and defining numeric values."
	};
}
class codeBreaker
{
	// holds the information for scrambledWord, introduce, checkGuess, and Run.
public:
	codeBreaker();
	void scrambledWord(string& w);
	void Introduce();
	bool CheckGuess(string& g);
	void Run();

	// holds the information for tries, index, word, hint, codedWord, and guess.
private:
	int tries;
	int index;
	string word;
	string hint;
	string codedWord;
	string guess;
};
codeBreaker::codeBreaker() :
	tries(0), index(rand() % 10), word(scramble::words[index]), hint(scramble::hints[index]),
	codedWord(""), guess("")

{}
void codeBreaker::scrambledWord(string& w) {
	// This block is responsible for scrambling up the words so that the player can guess them.
	codedWord = w;
	// how many times it will run a for loop to swap characters around
	int length = codedWord.size();
	// for loop to swap characters around at random
	for (int i = 0; i < length; i++) {
		int index1 = (rand() % length);
		int index2 = (rand() % length);

		char temp = codedWord[index1];
		codedWord[index1] = codedWord[index2];
		codedWord[index2] = temp;
	}
}

void codeBreaker::Introduce() {
	// This displays a coded word
	scrambledWord(word);
	cout << "The coded word is: " << codedWord;
}

// This will check to see if the players guess is right or wrong
bool codeBreaker::CheckGuess(string& g) {
	// increments the number of tries
	++tries;
	++totalScore;
	// displays hint when player asks for a hint
	if (g == "hint") {
		cout << hint;
		return false;
	}
	// displays a message and quits the game
	else if (g == "quit") {
		cout << "You have chosen to end the game.\n";
		cout << "Thank you for playing Code Breaker!\n\n";
		system("pause");
		exit(0);
	}
	// tells the player if they got the word right and how many times it took them to guess correctly
	else if (g == word) {
		cout << "Correct! You have guessed the word in " << tries << " tries.\n";
		return true;
	}
	// tells the player if they guessed incorrectly
	else {
		cout << "Sorry! That guess is incorrect. Try again!";
		return false;
	}

}

void codeBreaker::Run() {
	// runs the game
	Introduce();

	while (true) {
		cout << "\n\nYour guess: ";
		cin >> guess;

		if (CheckGuess(guess))
			break;
	}
}

int main() {
	// Main menu
	cout << "\tWelcome to Code Breaker!\n\n";
	cout << "Unscramble the letters to guess the coded word.\n";
	cout << "Input 'hint' for a hint.\n";
	cout << "Input 'quit' to quit the game.\n\n";
	cout << "When it asks to play again, input 'y' for yes and 'n' for no.\n\n";

	// random number generator
	srand(static_cast<unsigned int>(time(0)));
	// sets up play again option
	char PlayAgain = 'y';
	while (PlayAgain != 'n') {
		// makes the game run 3 times 
		for (int i = 0; i < 3; i++) {

			codeBreaker myGame;
			myGame.Run();

			cin.ignore();
			cin.get();
		}
		do {
			// tells the player that the game is completed, shows them the total number iof attempts, and asks if they want to play again.
			cout << "Game Complete!\n";
			cout << "Total attempts: " << totalScore;
			cout << "\nPlay again? y/n: ";
			cin >> PlayAgain;
		}
		// tells the computer what y and n mean
		while (PlayAgain != 'y' && PlayAgain != 'n');
	}
	return 0;
}



