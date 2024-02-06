#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#include "character.h"
#include "foes.h"

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

void adventureLoop(Character *party[], size_t party_size, Foe *foes[], size_t foes_size)
{
    bool everyoneIsAlive = true;
    while (everyoneIsAlive)
    {
        int random_party_member = rand() % party_size;
        int random_opp = rand() % foes_size;

        Foe *currentFoe = foes[random_opp];
        Character *currentCharacter = party[random_party_member];

        printf("A wild %s appears!\n", currentFoe->name);
        printFoe(currentFoe);

        puts("Select a character to fight the foe:");
        for (size_t i = 0; i < party_size; i++)
        {
            printf("%lu. %s\n", i + 1, party[i]->name);
        }

        everyoneIsAlive = false;
    }
}
