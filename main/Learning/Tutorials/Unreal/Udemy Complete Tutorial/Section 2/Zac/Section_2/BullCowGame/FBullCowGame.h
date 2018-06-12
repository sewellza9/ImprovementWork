#pragma once
#include <string>

using FString = std::string;
using int32 = int;

struct FBullCowCount
{
	int32 Bulls = 0;
	int32 Cows = 0;
};

enum class EWordStatus
{
	INVALID,
	OK,
	NOT_ISOGRAM,
	WRONGLEN

};

class FBullCowGame
{
public:
	FBullCowGame();

	int32 GetMaxTries() const;
	int32 GetCurrentTry() const;
	int GetHiddenWordLen() const;
	bool isGameWon() const;
	EWordStatus CheckGuessValidity(FString) const;

	void Reset();
	FBullCowCount SubmitValidGuess(FString);
	

private:
	int32 MyCurrentTry;
	FString MyHiddenWord;
	bool bIsGameWon;
	bool IsIsogram(FString) const;
};

