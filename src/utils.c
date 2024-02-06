#include <stdio.h>
#include "character.h"
#include "foes.h"

#define ANSI_COLOR_RED "\x1b[31m"
#define ANSI_COLOR_GREEN "\x1b[32m"
#define ANSI_COLOR_BLUE "\x1b[34m"
#define ANSI_COLOR_YELLOW "\x1b[33m"
#define ANSI_COLOR_MAGENTA "\x1b[35m"
#define ANSI_COLOR_CYAN "\x1b[36m"
#define ANSI_COLOR_WHITE "\x1b[37m"
#define ANSI_COLOR_RESET "\x1b[0m"

void printCharacter(Character *character)
{
    printf("Name: %s\n", character->name);

    if (character->CharacterClass == WARRIOR)
    {
        printf("Class: %sWarrior%s\n", ANSI_COLOR_RED, ANSI_COLOR_RESET);
    }
    else if (character->CharacterClass == MAGE)
    {
        printf("Class: %sMage%s\n", ANSI_COLOR_BLUE, ANSI_COLOR_RESET);
    }
    else if (character->CharacterClass == ROGUE)
    {
        printf("Class: %sRogue%s\n", ANSI_COLOR_GREEN, ANSI_COLOR_RESET);
    }

    printf("Level: %d\n", character->level);
    printf("Health: %d\n", character->healthStat);
    printf("Strength: %d\n", character->strengthStat);
    printf("Dexterity: %d\n", character->dexterityStat);
    printf("Inteligence: %d\n", character->inteligenceStat);
    printf("Luck: %d\n", character->luckStat);
    printf("Experience: %.02f\n", character->experience);
}

void printFoe(Foe *foe)
{
    printf("Name: %s\n", foe->name);
    printf("Level: %d\n", foe->level);
    printf("Health: %d\n", foe->healthStat);
    printf("Strength: %d\n", foe->strengthStat);
    printf("Dexterity: %d\n", foe->dexterityStat);
    printf("Inteligence: %d\n", foe->inteligenceStat);
    printf("Luck: %d\n", foe->luckStat);
}
