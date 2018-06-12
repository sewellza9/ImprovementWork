//This is our console exec
#pragma once
#include <iostream>
#include <string>
#include "FBullCowGame.h"

using FText = std::string;

void PrintIntro();
void PlayGame();
FText GetGuess();
bool AskToPlayAgain();
FBullCowGame BCGame;
void PrintGameSummary();

int main()
{
	do
	{
		PrintIntro();
		PlayGame();
	} while (AskToPlayAgain());


	return 0; //Exit app
}
void PlayGame()
{
	BCGame.Reset();
	while (!BCGame.isGameWon() && BCGame.GetCurrentTry() <= BCGame.GetMaxTries())
	{
		FText Guess = GetGuess();

		FBullCowCount BullCowCount = BCGame.SubmitValidGuess(Guess);
		std::cout << "Bulls= " << BullCowCount.Bulls << ". Cows = " << BullCowCount.Cows << std::endl;
	
	}

	PrintGameSummary();
		
}
void PrintIntro()
{
	std::cout << "Welcome to Bulls and Cows, a fun word game." << std::endl;
	std::cout << "Can you guess the " << BCGame.GetHiddenWordLen() << " letter isogram I's thinking of?\n";

}
FText GetGuess()
{
	EWordStatus Status = EWordStatus::INVALID;
	FText guess = "";
	do
	{
		int32 currentTry = BCGame.GetCurrentTry();
		std::cout << "TRY " << currentTry << " of " << BCGame.GetMaxTries()<< "- Enter your guess: ";
		std::getline(std::cin, guess);

		Status = BCGame.CheckGuessValidity(guess);

		switch (Status)
		{
		case EWordStatus::NOT_ISOGRAM:
			std::cout << "Please enter a Isogram.\n";
			break;
		case EWordStatus::WRONGLEN:
		{
			std::cout << "Please enter a " << BCGame.GetHiddenWordLen() << " letter word.\n";
			break;
		}
		default:
			break;
		}
	} while (Status != EWordStatus::OK);
	return guess;
}
bool AskToPlayAgain()
{
	std::cout << "Do you want to play again with the same hidden word (y/n)? ";
	FText response = "";
	std::getline(std::cin, response);

	return(tolower(response[0]) == 'y');

}
void PrintGameSummary()
{
	if (BCGame.isGameWon())
	{
		std::cout << "CONGRATS YOU WIN!\n";
	}
	else
	{
		std::cout << "BETTER LUCK NEXT TIME.\n";
	}
}
void PrintBack(FText guess)
{
	std::cout << "Your guess was: " << guess << std::endl;
}