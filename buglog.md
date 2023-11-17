Created 11/10/23

Ok, if there's a function that needs to be overriden in order to move, how do I pass in a vector to know which direction to move?
FIX: Make "Move" have a vector as a private component.

Frickin' how am I supposed to get_tile in move.cpp? Like, how? How is that supposed to call said function?
FIX: Make a tile object first, then have it figure out the answer.

A bug resulted from monsters attempting to move onto the same tile as the hero, so I made it that if you attempt to move onto a tile that is occupied you will rest instead.