#include "raylib.h"
#include "stdio.h"
#include "../include/game.h"

void InitGame() {
    printf("Game Initialized!\n");
}

void UpdateGame() {
    DrawText("Game Updating...", 190, 260, 20, DARKBLUE);
    
}

void DrawGame() {
    DrawText("Hello, Raylib Starter Kit!", 190, 180, 20, DARKBLUE);
    DrawCircle(50,50,50,RED);
}

void CloseGame() {
    printf("Game Closed!\n");
}
