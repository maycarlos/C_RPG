#ifndef character_h
#define character_h

#include <stdint.h>
#include <stddef.h>

typedef struct Monster Monster;

enum Class
{
    WARRIOR,
    MAGE,
    ROGUE
};

typedef struct Character
{
    char name[50];
    uint32_t level;
    enum Class CharacterClass;
    float healthStat;
    uint32_t strengthStat;
    uint32_t dexterityStat;
    uint32_t inteligenceStat;
    uint32_t luckStat;
    float experience;

} Character;

/*
Create a new character with the given name and class
@param name: character name
@param CharacterClass: character class
*/
Character *createCharacter(char name[50], enum Class CharacterClass);

/*
Level up the character
@param character: pointer to a character
*/
void levelUp(Character *character);

/*
Function to level up the whole party
@param characters: array of pointers to characters
@param party_size: size of the party
*/
void levelUpParty(Character *characters[], size_t party_size);

/*
Function to attack a foe
@param attacker: pointer to a character
@param defender: pointer to a foe
*/
void attack(Character *attacker, Monster *defender);

#endif
