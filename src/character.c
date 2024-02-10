#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#include "character.h"
#include "foes.h"

Character *createCharacter(char name[50], enum Class CharacterClass)
{
    Character *newCharacter = (Character *)malloc(sizeof(Character));

    strcpy(newCharacter->name, name);
    newCharacter->level = 1;
    newCharacter->CharacterClass = CharacterClass;
    newCharacter->strengthStat = 10;
    newCharacter->dexterityStat = 10;
    newCharacter->inteligenceStat = 10;
    newCharacter->luckStat = 10;
    newCharacter->healthStat = 100;
    newCharacter->experience = 0.0;

    return newCharacter;
}

void levelUp(Character *character)
{

    character->level += 1;

    printf("Level up! %s is now level %d\n", character->name, character->level);

    if (character->CharacterClass == WARRIOR)
    {
        character->strengthStat += 10;
        character->dexterityStat += 5;
        character->inteligenceStat += 5;
        character->luckStat += 5;
        character->healthStat += 20;
    }
    else if (character->CharacterClass == MAGE)
    {
        character->strengthStat += 5;
        character->dexterityStat += 5;
        character->inteligenceStat += 10;
        character->luckStat += 5;
        character->healthStat += 10;
    }
    else if (character->CharacterClass == ROGUE)
    {
        character->strengthStat += 5;
        character->dexterityStat += 10;
        character->inteligenceStat += 5;
        character->luckStat += 10;
        character->healthStat += 10;
    }
}

void levelUpParty(Character *characters[], size_t party_size)
{
    for (size_t i = 0; i < party_size; i++)
    {
        levelUp(characters[i]);
    }
}

void attack(Character *attacker, Monster *defender)
{
    printf("%s attacks %s!\n", attacker->name, defender->name);
    defender->healthStat -= 1.3 * attacker->strengthStat;
    if (defender->healthStat <= 0.0)
    {
        return;
    }
    else
    {
        printf("%s has %.02f health left\n", defender->name, defender->healthStat);
    }
    puts("\n");
}
