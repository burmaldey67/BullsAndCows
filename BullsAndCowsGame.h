#pragma once

/**
 * @brief Configures console input and output encoding to UTF-8 on Windows.
 */
void setupConsole();

/**
 * @brief Prints the game title, rules, and initial prompt to the console.
 */
void printWelcome();

/**
 * @brief Checks that a number has exactly four digits.
 *
 * @param number Number to check. Passed by value: the function does not modify it.
 * @return @c true if @p number is in the inclusive range 1000..9999, @c false otherwise.
 */
bool isFourDigit(int number);

/**
 * @brief Checks whether any two of the four digits are equal.
 *
 * @param d1 First digit. Passed by value: the function does not modify it.
 * @param d2 Second digit. Passed by value: the function does not modify it.
 * @param d3 Third digit. Passed by value: the function does not modify it.
 * @param d4 Fourth digit. Passed by value: the function does not modify it.
 * @return @c true if at least two digits are equal, @c false otherwise.
 */
bool hasRepeatedDigits(int d1, int d2, int d3, int d4);

/**
 * @brief Composes a 4-digit integer from four separate digits.
 *
 * @param d1 Thousands digit. Passed by value: the function does not modify it.
 * @param d2 Hundreds digit. Passed by value: the function does not modify it.
 * @param d3 Tens digit. Passed by value: the function does not modify it.
 * @param d4 Units digit. Passed by value: the function does not modify it.
 * @return Composed 4-digit integer.
 */
int composeNumber(int d1, int d2, int d3, int d4);

/**
 * @brief Splits a 4-digit integer into four individual digits.
 *
 * @param number 4-digit integer to split. Passed by value: the function does not modify it.
 * @param d1 Thousands digit. Passed by reference: writes the extracted digit into this variable.
 * @param d2 Hundreds digit. Passed by reference: writes the extracted digit into this variable.
 * @param d3 Tens digit. Passed by reference: writes the extracted digit into this variable.
 * @param d4 Units digit. Passed by reference: writes the extracted digit into this variable.
 */
void extractDigits(int number, int& d1, int& d2, int& d3, int& d4);

/**
 * @brief Generates four unique digits for the secret number (first digit 1..9, others 0..9).
 *
 * @param d1 First digit (1..9). Passed by reference: writes the generated digit into this variable.
 * @param d2 Second digit (0..9). Passed by reference: writes the generated digit into this variable.
 * @param d3 Third digit (0..9). Passed by reference: writes the generated digit into this variable.
 * @param d4 Fourth digit (0..9). Passed by reference: writes the generated digit into this variable.
 */
void generateUniqueDigits(int& d1, int& d2, int& d3, int& d4);

/**
 * @brief Counts bulls (exact digit and position matches) and cows (matching digits in wrong positions).
 *
 * @param s1 First secret digit. Passed by value: the function does not modify it.
 * @param s2 Second secret digit. Passed by value: the function does not modify it.
 * @param s3 Third secret digit. Passed by value: the function does not modify it.
 * @param s4 Fourth secret digit. Passed by value: the function does not modify it.
 * @param g1 First guess digit. Passed by value: the function does not modify it.
 * @param g2 Second guess digit. Passed by value: the function does not modify it.
 * @param g3 Third guess digit. Passed by value: the function does not modify it.
 * @param g4 Fourth guess digit. Passed by value: the function does not modify it.
 * @param bulls Number of bulls. Passed by reference: writes the calculated count into this variable.
 * @param cows Number of cows. Passed by reference: writes the calculated count into this variable.
 */
void countBullsAndCows(int s1, int s2, int s3, int s4,
                       int g1, int g2, int g3, int g4,
                       int& bulls, int& cows);

/**
 * @brief Prints the number of bulls and cows for the current round.
 *
 * @param bulls Number of bulls. Passed by value: the function does not modify it.
 * @param cows Number of cows. Passed by value: the function does not modify it.
 */
void printRoundResult(int bulls, int cows);

/**
 * @brief Prints the victory message with the secret number and total attempts.
 *
 * @param secretNumber Guessed 4-digit secret number. Passed by value: the function does not modify it.
 * @param attempts Total number of valid attempts taken. Passed by value: the function does not modify it.
 */
void printVictory(int secretNumber, int attempts);

/**
 * @brief Reads a player's guess from standard input.
 *
 * @param guess Variable to store the entered number. Passed by reference: writes the read integer into this variable.
 * @return @c true if an integer was successfully read, @c false on stream failure or EOF.
 */
bool readGuess(int& guess);

/**
 * @brief Prompts the user to select between test mode (1) and game mode (2).
 *
 * @return Selected mode number (1 or 2).
 */
int chooseMode();

/**
 * @brief Plays one full match of Bulls and Cows.
 *
 * Only a guess that is a 4-digit number with no repeated digits counts as an attempt:
 * the counter grows after both checks have passed.
 */
void playGame();