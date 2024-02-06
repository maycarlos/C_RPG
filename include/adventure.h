#ifndef ADVENTURE_H
#define ADVENTURE_H

#include <stdio.h>
#include <stdbool.h>

#include "character.h"
#include "foes.h"
#include "utils.h"

/*
Check if at least one character in the party is alive
@param party: the party of characters
@param party_size: the size of the party
*/
bool isPartyAlive(Character *party, size_t party_size);

/*
Main adventure loop

@param party: the party of characters
@param party_size: the size of the party
@param foes: the foes to fight
@param foes_size: the size of the foes
*/
void adventureLoop(Character *party, size_t party_size, Foe *foes, size_t foes_size);

#endif
