#ifndef FOES_H
#define FOES_H

#include <stdlib.h>


typedef struct Character Character;
typedef struct Foe
{
    char name[50];
    int level;
    int strengthStat;
    int dexterityStat;
    int inteligenceStat;
    int luckStat;
    int healthStat;
} Foe;

/*
Create foes based of the character level
@param name - name of the foe
@param characters - characters party stats
@param party_size - size of the party
*/
Foe *createFoe(char name[50], Character *characters[], size_t party_size);

/*
Function to attack a character
@param attacker: pointer to a foe
@param defender: pointer to a character
*/
void attackFoe(Foe *attacker, Character *defender);

#endif
