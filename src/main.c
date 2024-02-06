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

    Foe *goblin = createFoe("Goblin", characters, party_size);
    Foe *orc = createFoe("Orc", characters, party_size);
    Foe *dragon = createFoe("Dragon", characters, party_size);

    Foe *foes[] = {goblin, orc, dragon};

    printFoe(goblin);
    printFoe(orc);
    printFoe(dragon);

    size_t foes_size = sizeof(foes) / sizeof(foes[0]);
    adventureLoop(characters, party_size, foes, foes_size);

    free(warrior);
    free(mage);
    free(rogue);
    free(goblin);
    free(orc);
    free(dragon);

    return 0;
}
