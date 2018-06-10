/*
	This is the console executable that makes use of the BullCow Class
	This acts as the view in the MVC pattern, and is responsible for all
	user interaction. For game logic see the FBullCowGame class.
*/
#pragma once

#include <iostream>
#include <string>
#include "FBullCowGame.h"


//To make syntax more Unreal friendly
using FText = std::string;
using int32 = int;


void PrintIntro();
void PlayGame();
FText GetValidGuess();
bool AskToPlayAgain();
void PrintGamesSummary();

FBullCowGame BC_Game;

// the entry point for our game
int main()
{

	bool play_game = true;
	while (play_game)
	{
		system("cls");
		PrintIntro();
		PlayGame();
		play_game = AskToPlayAgain();
	}

	return 0;
}


void PrintIntro()
{
	std::cout << "Welcome to Bulls and Cows. It's a word game." << std::endl;
	std::cout << "Can you guess the " << BC_Game.GetHiddenWordLength() << " letter isogram I'm thinking of?" << std::endl << std::endl;
	return;
}


void PlayGame()
{
	BC_Game.Reset();

	//Loop until the player wins or the number of tries has been exhausted
	while(!BC_Game.IsGameWon() && BC_Game.GetCurrentTry() <= BC_Game.GetMaxTries())
	{
		FText player_guess = GetValidGuess();
		std::cout << "Your guess: " << player_guess << std::endl;

		FBullCowCount bull_cow_count = BC_Game.SubmitValidGuess(player_guess);
		std::cout << "Bulls: " << bull_cow_count.bulls << ". ";
		std::cout << "Cows : " << bull_cow_count.cows << "\n\n";
	}

	PrintGamesSummary();
	return;
}


void PrintGamesSummary()
{
	if (BC_Game.IsGameWon())
	{
		std::cout << "Congratulations! You won!" << std::endl;
	}
	else
	{
		std::cout << "Oh darn. You lost the game." << std::endl;
	}
}


FText GetValidGuess()
{
	FText guess = "";
	EGuessStatus guess_status = EGuessStatus::INVALID;

	do
	{
		std::cout << "Try " << BC_Game.GetCurrentTry() << " of " << BC_Game.GetMaxTries() << ": Enter a Guess: ";
		std::getline(std::cin, guess);

		guess_status = BC_Game.CheckGuessValidity(guess);
		switch (guess_status)
		{
		case EGuessStatus::WRONG_LENGTH:
		{
			std::cout << "Please enter a word with " << BC_Game.GetHiddenWordLength() << " letters.\n\n";
			break;
		}
		case EGuessStatus::NOT_ISOGRAM:
		{
			std::cout << "Please enter a word without repeating letters.\n\n";
			break;
		}
		case EGuessStatus::NOT_LOWERCASE:
		{
			std::cout << "Please enter all lowercase letters.\n\n";
			break;
		}
		case EGuessStatus::REPEAT_GUESS:
		{
			std::cout << "Please enter a word that you have not already guessed.\n\n";
			break;
		}
		case EGuessStatus::OK:
		{
			break;
		}
		default:
			break;
		}
	} while (guess_status != EGuessStatus::OK);

	return guess;
}


bool AskToPlayAgain()
{
	FText answer = "";
	std::cout << "Do you want to play again with the same hidden word? ";
	std::getline(std::cin, answer);

	return answer[0] == 'y' || answer[0] == 'Y';
}
