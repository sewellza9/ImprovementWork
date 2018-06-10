#pragma once
#include "FBullCowGame.h"
#include <map>

//To make syntax more Unreal friendly
#define TMap std::map
using int32 = int;

int32 FBullCowGame::GetCurrentTry() const { return myCurrentTry; }
bool FBullCowGame::IsGameWon() const { return isGameWon; }
int32 FBullCowGame::GetHiddenWordLength() const { return myHiddenWord.length(); }

FBullCowGame::FBullCowGame()
{
	Reset();
}

FBullCowGame::~FBullCowGame()
{
}

void FBullCowGame::Reset()
{
	myMaxTries = 50;
	myCurrentTry = 1;
	isGameWon = false;
	guesses.clear();

	const FString HIDDEN_WORD = "zelda";
	myHiddenWord = HIDDEN_WORD;

	return;
}

int32 FBullCowGame::GetMaxTries() const
{
	TMap<int32, int32> MaxTriesTable
	{
		{ 3, 5 },
		{ 4, 10 },
		{ 5, 25 },
		{ 6, 45 },
		{ 7, 95 },
	};

	return MaxTriesTable[GetHiddenWordLength()];
}

EGuessStatus FBullCowGame::CheckGuessValidity(FString guess) const
{
	EGuessStatus status = EGuessStatus::OK;

	if (guess.length() != GetHiddenWordLength())
	{
		return EGuessStatus::WRONG_LENGTH;
	}
	else if (!IsLowercase(guess))
	{
		return EGuessStatus::NOT_LOWERCASE;
	}
	else if (IsRepeatGuess(guess))
	{
		return EGuessStatus::REPEAT_GUESS;
	}
	else if (!IsIsogram(guess))
	{
		return EGuessStatus::NOT_ISOGRAM;
	}
	else
	{
		return EGuessStatus::OK;
	}
}

//Receives a VALID guess, increments number of tries, and returns bull/cow count
FBullCowCount FBullCowGame::SubmitValidGuess(FString guess)
{
	myCurrentTry++;

	guesses[guess] = true;

	FBullCowCount bull_cow_count;

	//Assumes guess and m_myHiddenWord are the same length
	int32 word_length = myHiddenWord.length();

	for (int32 i = 0; i < word_length; ++i)
	{
		for (int32 j = 0; j < word_length; ++j)
		{
			if (myHiddenWord[i] == guess[j])
			{
				if (i == j)
				{
					bull_cow_count.bulls++;
					break;
				}
				else
				{
					bull_cow_count.cows++;
					break;
				}
			}
		}
	}

	if (bull_cow_count.bulls == word_length)
	{
		isGameWon = true;
	}
	return bull_cow_count;
}

bool FBullCowGame::IsLowercase(FString word) const
{
	for (auto letter : word)
	{
		if (!islower(letter))
		{
			return false;
		}
	}

	return true;
}

bool FBullCowGame::IsIsogram(FString word) const
{
	int32 word_length = word.length();

	if (word_length <= 1)
	{
		return true;
	}

	TMap<char, bool> letters;

	for (auto letter : word)
	{
		letter = tolower(letter);

		if (letters.find(letter) == letters.end())
		{
			letters[letter] = true;
		}
		else
		{
			return false;
		}
	}

	return true;
}

bool FBullCowGame::IsRepeatGuess(FString guess) const
{
	return guesses.find(guess) != guesses.end();
}
