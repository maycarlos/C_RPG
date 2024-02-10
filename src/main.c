#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#include "character.h"
#include "utils.h"
#include "foes.h"
#include "adventure.h"
#include "dynamic_array.h"

int main()
{
    puts("Welcome to my new project!");

    Character *warrior = createCharacter("Red Lizard", WARRIOR);
    Character *mage = createCharacter("Elmah", MAGE);
    Character *rogue = createCharacter("Mayah", ROGUE);

    DynamicArray *characters = createDynamicArray(NULL, 0);

    characters = appendElement(characters, warrior);
    characters = appendElement(characters, mage);
    characters = appendElement(characters, rogue);

    printCharacter(getElement(characters, 0));
    printCharacter(getElement(characters, 1));
    printCharacter(getElement(characters, 2));

    Monster *goblin = createMonster("Goblin", GOBLIN, (Character **)characters->array, characters->size);
    Monster *orc = createMonster("Orc", ORC, (Character **)characters->array, characters->size);
    Monster *dragon = createMonster("Dragon", DRAGON, (Character **)characters->array, characters->size);

    printf("Size of the characters dynamic array: %ld\n", characters->size);

    DynamicArray *monsters = createDynamicArray(NULL, 0);

    monsters = appendElement(monsters, goblin);
    monsters = appendElement(monsters, orc);
    monsters = appendElement(monsters, dragon);

    printMonster(getElement(monsters, 0));
    printMonster(getElement(monsters, 1));
    printMonster(getElement(monsters, 2));

    printf("Size of the monsters dynamic array: %ld\n", monsters->size);

    freeDynamicArray(characters);
    freeDynamicArray(monsters);

    // Character *characters[] = {warrior, mage, rogue};
    // size_t party_size = sizeof(characters) / sizeof(characters[0]);

    // Monster *goblin = createMonster("Goblin", GOBLIN, characters, party_size);
    // Monster *orc = createMonster("Orc", ORC, characters, party_size);
    // Monster *dragon = createMonster("Dragon", DRAGON, characters, party_size);

    // Monster *monsters[] = {goblin, orc, dragon};
    // size_t monsters_n = sizeof(monsters) / sizeof(monsters[0]);

    // adventureLoop(characters, party_size, monsters, monsters_n);

    // free(warrior);
    // free(mage);
    // free(rogue);
    // free(goblin);
    // free(orc);
    // free(dragon);

    // return 0;
}
