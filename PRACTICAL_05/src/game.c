#include "raylib.h"
#include "stdio.h"
#include "../include/game.h"

Texture2D sprite;
Vector2 spritePosition = { 0,438 };

//customColor
Color myColor = (Color){ 255, 220, 130, 255 };

void InitGame() {
    printf("Game Initialized!\n");
    sprite = LoadTexture("resorce/player.png");
}

void UpdateGame() {
    DrawText("Game Updating...", 190, 260, 20, DARKBLUE);
   
   //Move
    if (IsKeyDown(KEY_RIGHT)) spritePosition.x += 5;
    if (IsKeyDown(KEY_LEFT))  spritePosition.x -= 5;
    if (IsKeyDown(KEY_UP))    spritePosition.y -= 5;
    if (IsKeyDown(KEY_DOWN))  spritePosition.y += 5;	
    
}

void DrawGame() {
    DrawText("Hello, Raylib Starter Kit!", 190, 180, 20, DARKBLUE);

    //Background
    DrawRectangle(0, 0, 800, 600, BLUE);

    //Draw circle
    DrawCircle(600, 100, 50, myColor);

    //draw sprite
    DrawTexture(sprite, spritePosition.x, spritePosition.y, WHITE);


    //ground rectangle
    DrawRectangle(0, 500, 800, 100, BLACK);

    //drawline
    DrawLine(0, 0, 400, 300, RED);

    //tree
    //DrawRectangle(300, 400, 20, 100, BROWN);

    DrawRectangle(270, 380, 80, 60, GREEN);

    //tree
    DrawRectangle(300, 420, 20, 100, BROWN);

    //House	
    DrawRectangle(500, 400, 100, 100, BROWN);
    Vector2 v1 = { 550, 300 };  // Top vertex
    Vector2 v2 = { 500, 400 };  // Bottom-left vertex
    Vector2 v3 = { 600, 400 };  // Bottom-right vertex

    //House
    DrawTriangle(v1, v2, v3, BROWN);

    //Door
    DrawRectangle(530, 430, 40, 60, WHITE);

    //WHITE line
    DrawRectangle(700, 540, 80, 20, WHITE);

    //WHITE line
    DrawRectangle(550, 540, 80, 20, WHITE);

    //WHITE line
    DrawRectangle(400, 540, 80, 20, WHITE);

    //WHITE line
    DrawRectangle(250, 540, 80, 20, WHITE);

    //WHITE line
    DrawRectangle(100, 540, 80, 20, WHITE);

    //WHITE line
    DrawRectangle(-50, 540, 80, 20, WHITE);



}

void CloseGame() {
    printf("Game Closed!\n");
}
