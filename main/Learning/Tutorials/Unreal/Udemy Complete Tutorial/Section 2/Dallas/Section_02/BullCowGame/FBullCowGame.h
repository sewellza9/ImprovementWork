#pragma once
#include <string>
#include <map>

//To make syntax more Unreal friendly
#define TMap std::map
using FString = std::string;
using int32 = int;


enum class EGuessStatus
{
	INVALID,
	OK,
	NOT_ISOGRAM,
	WRONG_LENGTH,
	NOT_LOWERCASE,
	REPEAT_GUESS,
};


struct FBullCowCount
{
	int32 bulls = 0;
	int32 cows = 0;
};

/*
This is the class for controlling the game state
*/
class FBullCowGame
{
public:
	FBullCowGame();
	~FBullCowGame();

	int32 GetMaxTries() const;
	int32 GetCurrentTry() const;
	int32 GetHiddenWordLength() const;
	bool IsGameWon() const;
	EGuessStatus CheckGuessValidity(FString) const;

	void Reset();
	FBullCowCount SubmitValidGuess(FString);

private:
	bool IsLowercase(FString) const;
	bool IsIsogram(FString) const;
	bool IsRepeatGuess(FString) const;

	TMap<FString, bool> guesses;
	int32 myCurrentTry;
	int32 myMaxTries;
	FString myHiddenWord;
	bool isGameWon;
};
