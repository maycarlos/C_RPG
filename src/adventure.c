#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

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

void *selectRandom(void *array[], size_t size)
{
    size_t index = rand() % size;
    printf("Index: %ld\n", index);

    return array[index];
}

void adventureLoop(Character *party[], size_t party_size, Monster *foes[], size_t foes_size)
{
    bool IsAlive = true;

    Monster *currentFoe = selectRandom(foes, foes_size);
    Character *currentCharacter = selectRandom(party, party_size);

    printf("A wild %s appears!\n", currentFoe->name);
    printMonster(currentFoe);

    printf("%s is going to fight it!\n", currentCharacter->name);
    printCharacter(currentCharacter);

    while (IsAlive)
    {

        printf("%s, it's your turn!\n", currentCharacter->name);
        attack(currentCharacter, currentFoe);

        if (currentFoe->healthStat <= 0)
        {
            printf("You defeated the %s!\n", currentFoe->name);
            currentCharacter->experience += currentFoe->level * 1.5;

            if (currentCharacter->experience >= 100)
            {
                levelUp(currentCharacter);
                currentCharacter->experience = 0.0;
            }

            currentFoe = selectRandom(foes, foes_size);
        }
        else
        {
            printf("The %s attacks you back!\n", currentFoe->name);
            attackFoe(currentFoe, currentCharacter);
        }

        if (currentCharacter->healthStat <= 0.0)
        {
            printf("%s has been defeated!\n", currentCharacter->name);
            IsAlive = false;

            // currentCharacter = selectRandom(party, party_size);

            // if (isPartyAlive(party, party_size))
            // {
            //     currentCharacter = selectRandom(party, party_size);
            //     printf("%s, it's your turn!\n", currentCharacter->name);
            // }
            // else
            // {
            //     printf("Game over!\n");
            //     IsAlive = false;
            // }
        }

        // IsAlive = false;
    }
}
