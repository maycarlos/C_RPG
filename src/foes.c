#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "character.h"
#include "foes.h"

Monster *createMonster(char name[50], enum MonsterClass monster_cls, Character **characters, size_t party_size)
{
    Monster *newFoe = (Monster *)malloc(sizeof(Monster));
    strcpy(newFoe->name, name);

    // Initialize total stats
    int total_level = 0, total_strength = 0, total_dexterity = 0, total_intelligence = 0, total_luck = 0, total_health = 0;

    // Calculate the total stats of the party
    for (size_t i = 0; i < party_size; i++)
    {
        total_level += characters[i]->level;
        total_strength += characters[i]->strengthStat;
        total_dexterity += characters[i]->dexterityStat;
        total_intelligence += characters[i]->inteligenceStat;
        total_luck += characters[i]->luckStat;
        total_health += characters[i]->healthStat;
    }

    // Calculate the average stats of the party
    int average_level = total_level / party_size;
    int average_strength = total_strength / party_size;
    int average_dexterity = total_dexterity / party_size;
    int average_intelligence = total_intelligence / party_size;
    int average_luck = total_luck / party_size;
    int average_health = total_health / party_size;

    if (monster_cls == GOBLIN)
    {
        newFoe->level = average_level * 0.8;                  // Adjust the factor as needed
        newFoe->strengthStat = average_strength * 0.8;        // Adjust the factor as needed
        newFoe->dexterityStat = average_dexterity * 0.8;      // Adjust the factor as needed
        newFoe->inteligenceStat = average_intelligence * 0.8; // Adjust the factor as needed
        newFoe->luckStat = average_luck * 0.8;                // Adjust the factor as needed
        newFoe->healthStat = average_health * 0.8;            // Adjust the factor as needed
    }
    else if (monster_cls == ORC)
    {
        newFoe->level = average_level * 1.0;                  // Adjust the factor as needed
        newFoe->strengthStat = average_strength * 1.0;        // Adjust the factor as needed
        newFoe->dexterityStat = average_dexterity * 1.0;      // Adjust the factor as needed
        newFoe->inteligenceStat = average_intelligence * 1.0; // Adjust the factor as needed
        newFoe->luckStat = average_luck * 1.0;                // Adjust the factor as needed
        newFoe->healthStat = average_health * 1.0;            // Adjust the factor as needed
    }
    else if (monster_cls == DRAGON)
    {
        newFoe->level = average_level * 1.2;                  // Adjust the factor as needed
        newFoe->strengthStat = average_strength * 1.2;        // Adjust the factor as needed
        newFoe->dexterityStat = average_dexterity * 1.2;      // Adjust the factor as needed
        newFoe->inteligenceStat = average_intelligence * 1.2; // Adjust the factor as needed
        newFoe->luckStat = average_luck * 1.2;                // Adjust the factor as needed
        newFoe->healthStat = average_health * 1.2;            // Adjust the factor as needed
    }
    return newFoe;
}

void attackMonster(Monster *attacker, Character *defender)
{
    printf("%s attacks %s!\n", attacker->name, defender->name);
    defender->healthStat -= 1.3 * attacker->strengthStat;
    if (defender->healthStat <= 0.0)
    {
        printf("%s has been defeated!\n", defender->name);
        return;
    }
    printf("%s has %.02f health left\n", defender->name, defender->healthStat);
    puts("\n");
}
