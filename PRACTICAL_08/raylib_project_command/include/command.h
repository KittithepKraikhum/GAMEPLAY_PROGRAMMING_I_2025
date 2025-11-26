#ifndef COMMAND_H
#define COMMAND_H

#include <stdbool.h>

#include "player.h"

// Forward declaration of the Mediator struct
typedef struct Mediator Mediator;

// Define the Command enum combining different commands into bit flags
// Movement could be defined as just MOVE with direction (for simplicity, each direction is separate)

typedef enum
{ 
NONE        	= 0, 
MOVE_UP 		= 1 << 0, 
MOVE_DOWN 		= 1 << 1, 
MOVE_LEFT 		= 1 << 2, 
MOVE_RIGHT 		= 1 << 3, 
JUMP 			= 1 << 4, 
FIRE 			= 1 << 5, 
RUN 			= 1 << 6, // add this 
CROUCH 			= 1 << 7, // add this 
SHIELD 			= 1 << 8, // add this 
COUNT 			= 9
} Command;

// Function to execute a command
void ExecuteCommand(Command command, Player *player, float deltaTime);

// Function to show active command bits (for debugging)
void GetCommandBits(Command cmd, char *buffer);

// Check if a specific command is active
bool IsCommandActive(Command command, Command filter);

#endif // COMMAND_H
