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
   
    //Draw circle
    DrawCircle(600,100,50,ORANGE);

    //draw sprite
    DrawTexture(sprite, 0, 438, WHITE);
    
    //ground rectangle
    DrawRectangle(0,500,800,100,BROWN);

    //drawline
    DrawLine(0,0,400,300,RED);

    //tree
    //DrawRectangle(300, 400, 20, 100, BROWN);
  
    DrawRectangle(270,380,80,60,GREEN);

      //tree
    DrawRectangle(300, 420, 20, 100, BROWN);
       
}

void CloseGame() {
    printf("Game Closed!\n");
}
