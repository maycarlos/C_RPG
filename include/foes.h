#ifndef FOES_H
#define FOES_H

#include <stdlib.h>
#include <inttypes.h>

typedef struct Character Character;

/*
Enum to represent the class of the monsters
*/
enum MonsterClass
{
    GOBLIN,
    ORC,
    DRAGON
};

typedef struct Monster
{
    char name[50];
    uint32_t level;
    uint32_t strengthStat;
    uint32_t dexterityStat;
    uint32_t inteligenceStat;
    uint32_t luckStat;
    float healthStat;
} Monster;

/*
Create foes based of the character level
@param name - name of the foe
@param characters - characters party stats
@param party_size - size of the party
*/
Monster *createMonster(char name[50], enum MonsterClass monster_cls, Character *characters[], size_t party_size);

/*
Function to attack a character
@param attacker: pointer to a foe
@param defender: pointer to a character
*/
void attackMonster(Monster *attacker, Character *defender);

#endif
