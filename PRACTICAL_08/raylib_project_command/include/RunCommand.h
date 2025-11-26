#ifndef RUN_COMMAND_H
#define RUN_COMMAND_H

#include "Command.h"
#include "player.h"

class RunCommand : public Command {
public: 
RunCommand(Player* p) : player(p) {} 

void execute() override { 
Run(player); 
} 

void undo() override { 
// undo will use message later 
}

private: 
Player* player;
};

#endif
