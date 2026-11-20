#include "BullsAndCowsGame.h"

#include <iostream>
#include <cstdlib>

#ifdef _WIN32
#include <windows.h>
#endif

void setupConsole()
{
#ifdef _WIN32
    SetConsoleOutputCP(CP_UTF8);
    SetConsoleCP(CP_UTF8);
#endif
}

void printWelcome()
{
    std::cout << "===============================================" << std::endl;
    std::cout << "    🐂 WELCOME TO BULLS AND COWS! 🐄" << std::endl;
    std::cout << "===============================================" << std::endl;
    std::cout << std::endl;
    std::cout << "🎯 I've thought of a 4-digit number with no repeated digits." << std::endl;
    std::cout << "🤔 Try to guess it!" << std::endl;
    std::cout << std::endl;
    std::cout << "📋 RULES:" << std::endl;
    std::cout << "🐂 Bulls = correct digits in correct positions" << std::endl;
    std::cout << "🐄 Cows = correct digits in wrong positions" << std::endl;
    std::cout << std::endl;
    std::cout << "🎮 Enter your guess (4 digits): ";
}

bool isFourDigit(int number)
{
    return number >= 1000 && number <= 9999;
}

bool hasRepeatedDigits(int d1, int d2, int d3, int d4)
{
    return d1 == d2 || d1 == d3 || d1 == d4 ||
           d2 == d3 || d2 == d4 ||
           d3 == d4;
}

int composeNumber(int d1, int d2, int d3, int d4)
{
    return d1 * 1000 + d2 * 100 + d3 * 10 + d4;
}

void extractDigits(int number, int& d1, int& d2, int& d3, int& d4)
{
    d1 = number / 1000;
    d2 = (number / 100) % 10;
    d3 = (number / 10) % 10;
    d4 = number % 10;
}

void generateUniqueDigits(int& d1, int& d2, int& d3, int& d4)
{
    d1 = rand() % 9 + 1;

    do
    {
        d2 = rand() % 10;
    }
    while (d2 == d1);

    do
    {
        d3 = rand() % 10;
    }
    while (d3 == d1 || d3 == d2);

    do
    {
        d4 = rand() % 10;
    }
    while (d4 == d1 || d4 == d2 || d4 == d3);
}

void countBullsAndCows(int s1, int s2, int s3, int s4,
                       int g1, int g2, int g3, int g4,
                       int& bulls, int& cows)
{
    bulls = 0;
    cows = 0;

    if (s1 == g1) bulls++;
    if (s2 == g2) bulls++;
    if (s3 == g3) bulls++;
    if (s4 == g4) bulls++;

    if (s1 == g2 || s1 == g3 || s1 == g4) cows++;
    if (s2 == g1 || s2 == g3 || s2 == g4) cows++;
    if (s3 == g1 || s3 == g2 || s3 == g4) cows++;
    if (s4 == g1 || s4 == g2 || s4 == g3) cows++;
}

void printRoundResult(int bulls, int cows)
{
    std::cout << "🎯 Result: 🐂 Bulls: " << bulls << ", 🐄 Cows: " << cows << std::endl;
}

void printVictory(int secretNumber, int attempts)
{
    std::cout << std::endl;
    std::cout << "🎉🎉🎉 CONGRATULATIONS! 🎉🎉🎉" << std::endl;
    std::cout << "🏆 You guessed the number " << secretNumber
              << " in " << attempts << " attempts!" << std::endl;
    std::cout << "🎊 Well done!" << std::endl;
}

bool readGuess(int& guess)
{
    std::cin >> guess;
    return static_cast<bool>(std::cin);
}

int chooseMode()
{
    int mode = 0;

    do
    {
        std::cout << "1 - test mode (check small functions)" << std::endl;
        std::cout << "2 - game" << std::endl;
        std::cout << "Choose mode: ";
        std::cin >> mode;

        if (!std::cin)
        {
            std::cin.clear();
            std::cin.ignore(1000, '\n');
            mode = 0;
        }
    }
    while (mode != 1 && mode != 2);

    std::cout << std::endl;
    return mode;
}

void playGame()
{
    int digit1{};
    int digit2{};
    int digit3{};
    int digit4{};
    generateUniqueDigits(digit1, digit2, digit3, digit4);
    const int secretNumber = composeNumber(digit1, digit2, digit3, digit4);

    printWelcome();

    int attempts = 0;
    int guess{};

    while (readGuess(guess))
    {
        if (!isFourDigit(guess))
        {
            std::cout << "❌ Please enter a 4-digit number: ";
            continue;
        }

        int g1{};
        int g2{};
        int g3{};
        int g4{};
        extractDigits(guess, g1, g2, g3, g4);

        if (hasRepeatedDigits(g1, g2, g3, g4))
        {
            std::cout << "🔄 Please enter a number with no repeated digits: ";
            continue;
        }

        attempts++;

        int bulls{};
        int cows{};
        countBullsAndCows(digit1, digit2, digit3, digit4, g1, g2, g3, g4, bulls, cows);
        printRoundResult(bulls, cows);

        if (bulls == 4)
        {
            printVictory(secretNumber, attempts);
            break;
        }

        std::cout << "🔄 Try again: ";
    }
}