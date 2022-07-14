#include <iostream>


using std::cout;
using std::cin;

int Game(int ac, int bc)
{
start:
	int a = { ac };
	int b = { bc };
	srand(time(NULL));
	int numberToGuess = rand() % b + a;
	system("cls");
	cout << "The number has been set. \nNow try to guess!\n";
	bool correctAnswer = { false };
	int playerGuess = { 0 };
	int numbOfTryies = { 0 };
	while (!correctAnswer)
	{
		cout << "It's bigger than: " << a << ". But Smaller than: " << b<<"\nYour guess: ";
		cin >> playerGuess;
		numbOfTryies++;
		if (playerGuess == numberToGuess)
		{
			cout << "Congratulations! You guessed by " << numbOfTryies << " time!";
			correctAnswer = { true };
			break;
		}
		else if (playerGuess > numberToGuess)
		{
			cout << "Wrong\n";
			b = playerGuess;
		}
		else if (playerGuess < numberToGuess)
		{
			cout << "Wrong\n";
			a = playerGuess;
		}
	}

	cout << "\nWanna play again? y/n ";
	char gameDec;
	cin >> gameDec;
	if (gameDec == 'y' || gameDec == 'Y')
	{
		goto start;
	}

	return 0;
}

int main()
{
	/*
	Easy - Number betwen 1 and 100.
	Medium - Number between 1 and 1000. 
	Hard - number between 1 and 10000.
	Custom - Player gives two numbers which represent Min and Max of random number
	*/
beginning:
	system("cls");
	cout << "Welcome in number guesser! Chose your difficulty and have fun! \n1.Easy \n2.Medium \n3.Hard \n4.How to play?\n";
	int dec{ 0 };
	cin >> dec;
	int a{ 0 }, b{ 100 };
	char enterWait;
	switch (dec)
	{
	case 1:
		Game(1, 100);
		break;
	case 2:
		Game(1, 1000);
		break;
	case 3:
		Game(1, 10000);
		break;
	case 4:
		system("cls");
		cout << "Computer will generate randomly chosen number betwen max and min. Your goal is to guess that number, with the smallest number of tries! \nEverytime you miss, computer will give you a hint did number is bigger or smaller\n";
		cout << "Write 'b' to go back to Main Menu: ";
		cin >> enterWait;
		goto beginning;
		break;
	}


	return 0;
}
