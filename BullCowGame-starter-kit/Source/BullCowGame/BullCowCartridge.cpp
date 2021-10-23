// Fill out your copyright notice in the Description page of Project Settings.
#include "BullCowCartridge.h"

void UBullCowCartridge::BeginPlay() // When the game starts
{
    Super::BeginPlay();
    InitGame();
}

void UBullCowCartridge::OnInput(const FString& Input) // When the player hits enter
{
    if (bGameOver) {
        ClearScreen();
        InitGame();
    }
    else 
    {
        ProcessGuess(Input);
    }
}

void UBullCowCartridge::InitGame() 
{
    HiddenWord = TEXT("sex");
    Lives = HiddenWord.Len();
    bGameOver = false;

    WelcomePlayer();
}

void UBullCowCartridge::WelcomePlayer()
{
    PrintLine(TEXT("Welcome to Bulls and Cows!"));
    PrintLine(TEXT("The Hidden word is %i characters long."), HiddenWord.Len());
    PrintLine(TEXT("You have %i lifes, good luck."), Lives);
    PrintLine(TEXT("Type a guess and press ENTER to continue."));
}

void UBullCowCartridge::ProcessGuess(FString Guess)
{
    if (Guess == HiddenWord)
    {
        PrintLine(TEXT("Congratulations, your guess is correct!"));
        EndGame();
        return;
    }
    if (Guess.Len() != HiddenWord.Len())
    {
        PrintLine(TEXT("The Hidden word is %i characters long.\nYou lost."), HiddenWord.Len());
        return;
    }
    --Lives;
    if (Lives == 0)
    {
        ClearScreen();
        PrintLine(TEXT("You have no lives left!"));
        PrintLine(TEXT("The hidden word is %s"), *HiddenWord);
        EndGame();
        return;
    }
    PrintLine(TEXT("Your guess is wrong."));
    PrintLine(TEXT("You have %i lives remaining"), Lives);
    return;
}

void UBullCowCartridge::EndGame()
{
    bGameOver = true;
    PrintLine(TEXT("Press ENTER to continue."));
}

