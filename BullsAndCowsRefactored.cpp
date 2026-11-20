#include "BullsAndCowsGame.h"
#include "BullsAndCowsTests.h"

#include <cstdlib>
#include <ctime>

/**
 * @brief Program entry point: initializes console and RNG, then runs the selected mode.
 *
 * @return Exit status code (0 on normal completion).
 */
int main()
{
    srand(time(nullptr));
    setupConsole();

    const int mode = chooseMode();
    if (mode == 1)
    {
        runSelfChecks();
    }
    else
    {
        playGame();
    }

    return 0;
}