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

void adventureLoop(Character *party[], size_t party_size, Monster *monsters[], size_t monsters_size)
{

    Monster *currentMonster = selectRandom(monsters, monsters_size);
    Character *currentCharacter = selectRandom(party, party_size);

    printf("A wild %s appears!\n", currentMonster->name);
    printMonster(currentMonster);

    printf("%s is going to fight it!\n", currentCharacter->name);
    printCharacter(currentCharacter);

    while (1)
    {

        printf("You have %ld monsters left to defeat!\n", monsters_size);
        printf("You have %ld characters left to fight!\n", party_size);

        printf("%s, it's your turn!\n", currentCharacter->name);
        attack(currentCharacter, currentMonster);

        if (currentMonster->healthStat <= 0)
        {
            printf("You defeated the %s!\n", currentMonster->name);
            currentCharacter->experience += currentMonster->level * 1.5;

            if (currentCharacter->experience >= 100)
            {
                levelUp(currentCharacter);
                currentCharacter->experience = 0.0;
            }

            if (monsters_size == 0)
            {
                printf("You have defeated all the monsters!\n");
                break;
            }

            // TODO Make this a function probably called update_foes
            size_t old_monsters_size = monsters_size;
            monsters_size--;

            Monster *updated_foes[monsters_size];

            for (size_t i = 0, j = 0; i < old_monsters_size; i++)
            {
                if (monsters[i]->healthStat > 0)
                {
                    updated_foes[j] = monsters[i];
                    j++;
                }
            }

            monsters = updated_foes;

            currentMonster = selectRandom(monsters, monsters_size);
        }
        else
        {
            printf("The %s attacks you back!\n", currentMonster->name);
            attackMonster(currentMonster, currentCharacter);
        }

        if (currentCharacter->healthStat <= 0.0)
        {
            // printf("%s has been defeated!\n", currentCharacter->name);

            // TODO Also make this a function called update_party

            size_t old_party_size = party_size;
            party_size--;

            if (party_size == 0)
            {
                printf("Game Over!\n");
                break;
            }

            Character *updated_party[party_size];

            for (size_t i = 0, j = 0; i < old_party_size; i++)
            {
                if (party[i]->healthStat > 0)
                {
                    updated_party[j] = party[i];
                    j++;
                }
            }

            party = updated_party;

            currentCharacter = selectRandom(party, party_size);
        }
    }
}