// Fill out your copyright notice in the Description page of Project Settings.
#include "BullCowCartridge.h"

void UBullCowCartridge::BeginPlay() // When the game starts
{
    Super::BeginPlay();
    HiddenWord = TEXT("planet");
    PrintLine(TEXT("Welcome to Bulls and Cows!"));
    PrintLine(TEXT("Type a word and press ENTER to continue..."));
}

void UBullCowCartridge::OnInput(const FString& Input) // When the player hits enter
{
    ClearScreen();
    if (Input == HiddenWord)
    {
        PrintLine(TEXT("Congratulations, your guess is correct!"));
    } 
    else
    {
        PrintLine(TEXT("Hmm... you miss."));
    }
}