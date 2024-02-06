#ifndef utils_h
#define utils_h

#include "character.h"
#include "foes.h"

enum ColorOutput
{
    RED,
    GREEN,
    BLUE,
    YELLOW,
    MAGENTA,
    CYAN,
    WHITE
};

/*
Print the character info
@param character: pointer to a character
*/
void printCharacter(Character *character);

/*
Print the foe's stats
@param foe: pointer to a foe
*/
void printFoe(Foe *foe);

#endif
