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

    //House	
    DrawRectangle(500,400,100,100,BROWN);
    Vector2 v1 = { 550, 300 };  // Top vertex
    Vector2 v2 = { 500, 400 };  // Bottom-left vertex
    Vector2 v3 = { 600, 400 };  // Bottom-right vertex
    
    //House
    DrawTriangle(v1, v2, v3, BLUE);

   //Door
   DrawRectangle(530,430,40,60,WHITE);
       
}

void CloseGame() {
    printf("Game Closed!\n");
}
