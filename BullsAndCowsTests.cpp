#include "BullsAndCowsTests.h"
#include "BullsAndCowsGame.h"

#include <iostream>

/**
 * @brief Prints a single self-check result and returns 0 on pass or 1 on failure.
 *
 * @param passed Result of the check condition. Passed by value: the function does not modify it.
 * @param name Human-readable test case description. Passed by value (pointer): does not modify the string.
 * @return @c 0 if @p passed is @c true, @c 1 otherwise.
 */
int reportCheck(bool passed, const char* name);

/**
 * @brief Tests isFourDigit() on valid 4-digit numbers and boundary invalid values.
 *
 * @return Number of failed checks.
 */
int testIsFourDigit();

/**
 * @brief Tests hasRepeatedDigits() on digit tuples with and without duplicates.
 *
 * @return Number of failed checks.
 */
int testHasRepeatedDigits();

/**
 * @brief Tests composeNumber() on standard and zero-containing 4-digit combinations.
 *
 * @return Number of failed checks.
 */
int testComposeNumber();

/**
 * @brief Tests extractDigits() and verifies that the input number passed by value is unchanged.
 *
 * @return Number of failed checks.
 */
int testExtractDigits();

/**
 * @brief Tests generateUniqueDigits() over 50 runs for digit ranges and uniqueness.
 *
 * @return Number of failed checks.
 */
int testGenerateUniqueDigits();

/**
 * @brief Tests countBullsAndCows() across bull/cow combinations and counter reset behavior.
 *
 * @return Number of failed checks.
 */
int testCountBullsAndCows();

void runSelfChecks()
{
    std::cout << "=== Self-checks (handwritten) ===" << std::endl;

    const int failed = testIsFourDigit()
                     + testHasRepeatedDigits()
                     + testComposeNumber()
                     + testExtractDigits()
                     + testGenerateUniqueDigits()
                     + testCountBullsAndCows();

    if (failed == 0)
    {
        std::cout << "All self-checks passed." << std::endl;
    }
    else
    {
        std::cout << "Self-checks failed: " << failed << std::endl;
    }

    std::cout << std::endl;
}

int reportCheck(bool passed, const char* name)
{
    if (passed)
    {
        std::cout << "[OK] " << name << std::endl;
        return 0;
    }

    std::cout << "[FAIL] " << name << std::endl;
    return 1;
}

int testIsFourDigit()
{
    int failed = 0;

    {
        // Arrange
        const int input = 1000;
        const bool expected = true;
        // Act
        const bool actual = isFourDigit(input);
        // Assert
        failed += reportCheck(actual == expected, "isFourDigit(1000) == true");
    }
    {
        // Arrange
        const int input = 1234;
        const bool expected = true;
        // Act
        const bool actual = isFourDigit(input);
        // Assert
        failed += reportCheck(actual == expected, "isFourDigit(1234) == true");
    }
    {
        // Arrange
        const int input = 5067;
        const bool expected = true;
        // Act
        const bool actual = isFourDigit(input);
        // Assert
        failed += reportCheck(actual == expected, "isFourDigit(5067) == true");
    }
    {
        // Arrange
        const int input = 9999;
        const bool expected = true;
        // Act
        const bool actual = isFourDigit(input);
        // Assert
        failed += reportCheck(actual == expected, "isFourDigit(9999) == true");
    }
    {
        // Arrange
        const int input = 0;
        const bool expected = false;
        // Act
        const bool actual = isFourDigit(input);
        // Assert
        failed += reportCheck(actual == expected, "isFourDigit(0) == false");
    }
    {
        // Arrange
        const int input = 99;
        const bool expected = false;
        // Act
        const bool actual = isFourDigit(input);
        // Assert
        failed += reportCheck(actual == expected, "isFourDigit(99) == false");
    }
    {
        // Arrange
        const int input = 999;
        const bool expected = false;
        // Act
        const bool actual = isFourDigit(input);
        // Assert
        failed += reportCheck(actual == expected, "isFourDigit(999) == false");
    }
    {
        // Arrange
        const int input = 10000;
        const bool expected = false;
        // Act
        const bool actual = isFourDigit(input);
        // Assert
        failed += reportCheck(actual == expected, "isFourDigit(10000) == false");
    }
    {
        // Arrange
        const int input = -1234;
        const bool expected = false;
        // Act
        const bool actual = isFourDigit(input);
        // Assert
        failed += reportCheck(actual == expected, "isFourDigit(-1234) == false");
    }

    return failed;
}

int testHasRepeatedDigits()
{
    int failed = 0;

    {
        // Arrange
        const int d1 = 1, d2 = 1, d3 = 2, d4 = 3;
        const bool expected = true;
        // Act
        const bool actual = hasRepeatedDigits(d1, d2, d3, d4);
        // Assert
        failed += reportCheck(actual == expected, "hasRepeatedDigits(1, 1, 2, 3) == true");
    }
    {
        // Arrange
        const int d1 = 1, d2 = 2, d3 = 3, d4 = 3;
        const bool expected = true;
        // Act
        const bool actual = hasRepeatedDigits(d1, d2, d3, d4);
        // Assert
        failed += reportCheck(actual == expected, "hasRepeatedDigits(1, 2, 3, 3) == true");
    }
    {
        // Arrange
        const int d1 = 5, d2 = 6, d3 = 7, d4 = 5;
        const bool expected = true;
        // Act
        const bool actual = hasRepeatedDigits(d1, d2, d3, d4);
        // Assert
        failed += reportCheck(actual == expected, "hasRepeatedDigits(5, 6, 7, 5) == true");
    }
    {
        // Arrange
        const int d1 = 1, d2 = 2, d3 = 2, d4 = 4;
        const bool expected = true;
        // Act
        const bool actual = hasRepeatedDigits(d1, d2, d3, d4);
        // Assert
        failed += reportCheck(actual == expected, "hasRepeatedDigits(1, 2, 2, 4) == true");
    }
    {
        // Arrange
        const int d1 = 8, d2 = 8, d3 = 8, d4 = 8;
        const bool expected = true;
        // Act
        const bool actual = hasRepeatedDigits(d1, d2, d3, d4);
        // Assert
        failed += reportCheck(actual == expected, "hasRepeatedDigits(8, 8, 8, 8) == true");
    }
    {
        // Arrange
        const int d1 = 1, d2 = 0, d3 = 2, d4 = 0;
        const bool expected = true;
        // Act
        const bool actual = hasRepeatedDigits(d1, d2, d3, d4);
        // Assert
        failed += reportCheck(actual == expected, "hasRepeatedDigits(1, 0, 2, 0) == true");
    }
    {
        // Arrange
        const int d1 = 1, d2 = 2, d3 = 3, d4 = 4;
        const bool expected = false;
        // Act
        const bool actual = hasRepeatedDigits(d1, d2, d3, d4);
        // Assert
        failed += reportCheck(actual == expected, "hasRepeatedDigits(1, 2, 3, 4) == false");
    }

    return failed;
}

int testComposeNumber()
{
    int failed = 0;

    {
        // Arrange
        const int d1 = 1, d2 = 2, d3 = 3, d4 = 4;
        const int expected = 1234;
        // Act
        const int actual = composeNumber(d1, d2, d3, d4);
        // Assert
        failed += reportCheck(actual == expected, "composeNumber(1, 2, 3, 4) == 1234");
    }
    {
        // Arrange
        const int d1 = 1, d2 = 0, d3 = 2, d4 = 3;
        const int expected = 1023;
        // Act
        const int actual = composeNumber(d1, d2, d3, d4);
        // Assert
        failed += reportCheck(actual == expected, "composeNumber(1, 0, 2, 3) == 1023");
    }
    {
        // Arrange
        const int d1 = 9, d2 = 0, d3 = 8, d4 = 7;
        const int expected = 9087;
        // Act
        const int actual = composeNumber(d1, d2, d3, d4);
        // Assert
        failed += reportCheck(actual == expected, "composeNumber(9, 0, 8, 7) == 9087");
    }
    {
        // Arrange
        const int d1 = 1, d2 = 0, d3 = 0, d4 = 0;
        const int expected = 1000;
        // Act
        const int actual = composeNumber(d1, d2, d3, d4);
        // Assert
        failed += reportCheck(actual == expected, "composeNumber(1, 0, 0, 0) == 1000");
    }
    {
        // Arrange
        const int d1 = 5, d2 = 0, d3 = 6, d4 = 7;
        const int expected = 5067;
        // Act
        const int actual = composeNumber(d1, d2, d3, d4);
        // Assert
        failed += reportCheck(actual == expected, "composeNumber(5, 0, 6, 7) == 5067");
    }

    return failed;
}

int testExtractDigits()
{
    int failed = 0;

    {
        // Arrange
        int number = 1234;
        int d1 = -1, d2 = -1, d3 = -1, d4 = -1;
        // Act
        extractDigits(number, d1, d2, d3, d4);
        // Assert
        failed += reportCheck(d1 == 1 && d2 == 2 && d3 == 3 && d4 == 4 && number == 1234,
                              "extractDigits(1234) -> 1, 2, 3, 4 (number unchanged)");
    }
    {
        // Arrange
        int number = 1023;
        int d1 = -1, d2 = -1, d3 = -1, d4 = -1;
        // Act
        extractDigits(number, d1, d2, d3, d4);
        // Assert
        failed += reportCheck(d1 == 1 && d2 == 0 && d3 == 2 && d4 == 3 && number == 1023,
                              "extractDigits(1023) -> 1, 0, 2, 3 (number unchanged)");
    }
    {
        // Arrange
        int number = 9087;
        int d1 = -1, d2 = -1, d3 = -1, d4 = -1;
        // Act
        extractDigits(number, d1, d2, d3, d4);
        // Assert
        failed += reportCheck(d1 == 9 && d2 == 0 && d3 == 8 && d4 == 7 && number == 9087,
                              "extractDigits(9087) -> 9, 0, 8, 7 (number unchanged)");
    }
    {
        // Arrange
        int number = 1000;
        int d1 = -1, d2 = -1, d3 = -1, d4 = -1;
        // Act
        extractDigits(number, d1, d2, d3, d4);
        // Assert
        failed += reportCheck(d1 == 1 && d2 == 0 && d3 == 0 && d4 == 0 && number == 1000,
                              "extractDigits(1000) -> 1, 0, 0, 0 (number unchanged)");
    }
    {
        // Arrange
        int number = 5067;
        int d1 = -1, d2 = -1, d3 = -1, d4 = -1;
        // Act
        extractDigits(number, d1, d2, d3, d4);
        // Assert
        failed += reportCheck(d1 == 5 && d2 == 0 && d3 == 6 && d4 == 7 && number == 5067,
                              "extractDigits(5067) -> 5, 0, 6, 7 (number unchanged)");
    }

    return failed;
}

int testGenerateUniqueDigits()
{
    // Arrange
    const int runs = 50;
    bool firstDigitInRange = true;
    bool otherDigitsInRange = true;
    bool allDigitsUnique = true;

    // Act
    for (int i = 0; i < runs; ++i)
    {
        int d1{};
        int d2{};
        int d3{};
        int d4{};
        generateUniqueDigits(d1, d2, d3, d4);

        if (d1 < 1 || d1 > 9)
        {
            firstDigitInRange = false;
        }
        if (d2 < 0 || d2 > 9 || d3 < 0 || d3 > 9 || d4 < 0 || d4 > 9)
        {
            otherDigitsInRange = false;
        }
        if (hasRepeatedDigits(d1, d2, d3, d4))
        {
            allDigitsUnique = false;
        }
    }

    // Assert
    return reportCheck(firstDigitInRange, "generateUniqueDigits (50 runs): d1 in 1..9")
         + reportCheck(otherDigitsInRange, "generateUniqueDigits (50 runs): d2..d4 in 0..9")
         + reportCheck(allDigitsUnique, "generateUniqueDigits (50 runs): no repeated digits");
}

int testCountBullsAndCows()
{
    int failed = 0;

    {
        // Arrange
        int bulls = 9, cows = 9;
        // Act
        countBullsAndCows(1, 2, 3, 4, 1, 2, 3, 4, bulls, cows);
        // Assert
        failed += reportCheck(bulls == 4 && cows == 0, "countBullsAndCows(1234 vs 1234) -> 4B 0C");
    }
    {
        // Arrange
        int bulls = 9, cows = 9;
        // Act
        countBullsAndCows(1, 2, 3, 4, 1, 2, 4, 3, bulls, cows);
        // Assert
        failed += reportCheck(bulls == 2 && cows == 2, "countBullsAndCows(1234 vs 1243) -> 2B 2C");
    }
    {
        // Arrange
        int bulls = 9, cows = 9;
        // Act
        countBullsAndCows(1, 2, 3, 4, 5, 6, 7, 8, bulls, cows);
        // Assert
        failed += reportCheck(bulls == 0 && cows == 0, "countBullsAndCows(1234 vs 5678) -> 0B 0C");
    }
    {
        // Arrange
        int bulls = 9, cows = 9;
        // Act
        countBullsAndCows(1, 2, 3, 4, 4, 3, 2, 1, bulls, cows);
        // Assert
        failed += reportCheck(bulls == 0 && cows == 4, "countBullsAndCows(1234 vs 4321) -> 0B 4C");
    }
    {
        // Arrange
        int bulls = 9, cows = 9;
        // Act
        countBullsAndCows(1, 2, 3, 4, 1, 5, 6, 7, bulls, cows);
        // Assert
        failed += reportCheck(bulls == 1 && cows == 0, "countBullsAndCows(1234 vs 1567) -> 1B 0C");
    }
    {
        // Arrange
        int bulls = 9, cows = 9;
        // Act
        countBullsAndCows(1, 2, 3, 4, 5, 1, 7, 8, bulls, cows);
        // Assert
        failed += reportCheck(bulls == 0 && cows == 1, "countBullsAndCows(1234 vs 5178) -> 0B 1C");
    }
    {
        // Arrange
        int bulls = 9, cows = 9;
        // Act
        countBullsAndCows(1, 2, 3, 4, 1, 2, 4, 5, bulls, cows);
        // Assert
        failed += reportCheck(bulls == 2 && cows == 1, "countBullsAndCows(1234 vs 1245) -> 2B 1C");
    }
    {
        // Arrange
        int bulls = 9, cows = 9;
        // Act
        countBullsAndCows(1, 0, 2, 3, 1, 0, 3, 2, bulls, cows);
        // Assert
        failed += reportCheck(bulls == 2 && cows == 2, "countBullsAndCows(1023 vs 1032) -> 2B 2C");
    }

    return failed;
}