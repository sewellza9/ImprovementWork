#include "FBullCowGame.h"
#include <map>
#define TMap std::map


FBullCowGame::FBullCowGame()
{
	Reset();
}

void FBullCowGame::Reset()
{
	MyCurrentTry = 1;
	const FString HIDDEN_WORD = "Plane";
	MyHiddenWord = HIDDEN_WORD;

	bIsGameWon = false;
}

int32 FBullCowGame::GetMaxTries() const
{
	TMap<int32, int32> WordLenToMaxTries{ {3,3},{4,4},{5,5},{6,6},{7,7} };
	return WordLenToMaxTries[MyHiddenWord.length()];
}

int FBullCowGame::GetCurrentTry() const
{
	return MyCurrentTry;
}

int FBullCowGame::GetHiddenWordLen() const
{
	return MyHiddenWord.length();
}

bool FBullCowGame::isGameWon() const
{
	return bIsGameWon;
}

EWordStatus FBullCowGame::CheckGuessValidity(FString guess) const
{
	if (!IsIsogram(guess))
	{
		return EWordStatus::NOT_ISOGRAM;
	}
	if (guess.length() != GetHiddenWordLen())
	{
		return EWordStatus::WRONGLEN;
	}
	return EWordStatus::OK;
}

FBullCowCount FBullCowGame::SubmitValidGuess(FString _guess)
{
	MyCurrentTry++;
	FBullCowCount bullCowCount;
	int32 Len = MyHiddenWord.length();
	for (int32 GuessIndex = 0; GuessIndex < Len; GuessIndex++)
	{
		for (int32 HiddenIndex = 0; HiddenIndex <Len; HiddenIndex++)
		{
			if (tolower( _guess[GuessIndex]) == tolower(MyHiddenWord[HiddenIndex]) && GuessIndex == HiddenIndex)
			{
				bullCowCount.Bulls++;
			}
			else if (tolower(_guess[GuessIndex]) == tolower(MyHiddenWord[HiddenIndex]))
			{
				bullCowCount.Cows++;
			}
			else
			{

			}
		}
	}
	if (bullCowCount.Bulls == Len)
	{
		bIsGameWon = true;
	}
	return bullCowCount;
}

bool FBullCowGame::IsIsogram(FString guess) const
{
	if (guess.length() <= 1)
		return true;

	TMap<char, bool> LettersSeen;
	for (auto Letter : guess)
	{
		Letter = tolower(Letter);
		if (LettersSeen[Letter])
			return false;
		else
			LettersSeen[Letter] = true;

	}
	return true;
}
