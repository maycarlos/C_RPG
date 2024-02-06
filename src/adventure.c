
#include <stdio.h>
#include <stdbool.h>

#include "character.h"
#include "foes.h"
#include "utils.h"
#include "adventure.h"

bool isPartyAlive(Character *party, size_t party_size)
{
    for (size_t i = 0; i < party_size; i++)
    {
        if (party[i].healthStat > 0)
        {
            return true;
        }
    }
    return false;
}

void adventureLoop(Character *party, size_t party_size, Foe *foes, size_t foes_size)
{
    bool everyoneIsAlive = true;
    while (everyoneIsAlive)
    {

        everyoneIsAlive = false;
    }
    /*
    for (size_t i = 0; i < foes_size; i++)
    {
        Foe *currentFoe = &foes[i];
        printf("A wild %s appears!\n", currentFoe->name);
        printFoe(currentFoe);
        puts("\n");

        while (currentFoe->healthStat > 0)
        {
            for (size_t j = 0; j < party_size; j++)
            {
                Character *currentCharacter = &party[j];
                if (currentCharacter->healthStat > 0)
                {
                    printf("%s attacks %s!\n", currentCharacter->name, currentFoe->name);
                    currentFoe->healthStat -= currentCharacter->strengthStat;
                    printf("%s has %d health left\n", currentFoe->name, currentFoe->healthStat);
                    puts("\n");
                }
            }
        }
    }
    */
}
