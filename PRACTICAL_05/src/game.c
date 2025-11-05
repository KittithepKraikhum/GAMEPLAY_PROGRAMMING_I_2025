#include "raylib.h"
#include "stdio.h"
#include "../include/game.h"

Texture2D sprite;

void InitGame() {
    printf("Game Initialized!\n");
    sprite = LoadTexture("resorce/player.png");
}

void UpdateGame() {
    DrawText("Game Updating...", 190, 260, 20, DARKBLUE);
    
}

void DrawGame() {
    DrawText("Hello, Raylib Starter Kit!", 190, 180, 20, DARKBLUE);
//    DrawCircle(50,50,50,RED);
    //load sprite
    DrawTexture(sprite, 0, 0, WHITE);
}

void CloseGame() {
    printf("Game Closed!\n");
}
