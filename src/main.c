#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#include "character.h"
#include "utils.h"
#include "foes.h"
#include "adventure.h"

int main()
{
    puts("Welcome to my new project!");

    Character *warrior = createCharacter("Red Lizard", WARRIOR);
    Character *mage = createCharacter("Elmah", MAGE);
    Character *rogue = createCharacter("Mayah", ROGUE);

    Character *characters[] = {warrior, mage, rogue};
    size_t party_size = sizeof(characters) / sizeof(characters[0]);

    Monster *goblin = createMonster("Goblin", GOBLIN, characters, party_size);
    Monster *orc = createMonster("Orc", ORC, characters, party_size);
    Monster *dragon = createMonster("Dragon", DRAGON, characters, party_size);

    Monster *monsters[] = {goblin, orc, dragon};
    size_t monsters_n = sizeof(monsters) / sizeof(monsters[0]);

    adventureLoop(characters, party_size, monsters, monsters_n);

    free(warrior);
    free(mage);
    free(rogue);
    free(goblin);
    free(orc);
    free(dragon);

    return 0;
}
