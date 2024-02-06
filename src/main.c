#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#include "character.h"
#include "utils.h"
#include "foes.h"

int main()
{
    puts("Welcome to my new project!");

    Character *warrior = createCharacter("Red Lizard", WARRIOR);
    Character *mage = createCharacter("Elmah", MAGE);
    Character *rogue = createCharacter("Mayah", ROGUE);

    Character *characters[] = {warrior, mage, rogue};
    size_t party_size = sizeof(characters) / sizeof(characters[0]);

    printCharacter(warrior);
    puts("\n");
    printCharacter(mage);
    puts("\n");
    printCharacter(rogue);
    puts("\n");

    levelUpParty(characters, party_size);

    puts("\n");

    printCharacter(warrior);
    puts("\n");
    printCharacter(mage);
    puts("\n");
    printCharacter(rogue);
    puts("\n");

    levelUpParty(characters, party_size);
    levelUpParty(characters, party_size);

    printCharacter(warrior);
    puts("\n");
    printCharacter(mage);
    puts("\n");
    printCharacter(rogue);
    puts("\n");

    Foe *blackDragon = createFoe("Black Dragon", characters, party_size);
    printFoe(blackDragon);

    puts("\n");

    free(warrior);
    free(mage);
    free(rogue);
    free(blackDragon);

    return 0;
}
