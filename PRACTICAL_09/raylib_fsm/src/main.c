#include <stdio.h>

#include "game.h"
#include "constants.h"


typedef enum {
    STATE_ATTACK = 0,
    STATE_CROUCH,
    STATE_SHIELD,
    STATE_COUNT
} PlayerState;

typedef enum {
EVENT_NONE = 0,
EVENT_ATTACK,
EVENT_CROUCH,
EVENT_SHIELD,
EVENT_STOP
} Event;


// ATTACK STATE
void PlayerEnterAttack(GameObject *obj, float deltaTime);
void PlayerUpdateAttack(GameObject *obj, float deltaTime);
void PlayerExitAttack(GameObject *obj, float deltaTime);
void PlayerAttackHandleEvent(GameObject *obj, Event event, float deltaTime);

// CROUCH STATE
void PlayerEnterCrouch(GameObject *obj, float deltaTime);
void PlayerUpdateCrouch(GameObject *obj, float deltaTime);
void PlayerExitCrouch(GameObject *obj, float deltaTime);
void PlayerCrouchHandleEvent(GameObject *obj, Event event, float deltaTime);

// SHIELD STATE
void PlayerEnterShield(GameObject *obj, float deltaTime);
void PlayerUpdateShield(GameObject *obj, float deltaTime);
void PlayerExitShield(GameObject *obj, float deltaTime);
void PlayerShieldHandleEvent(GameObject *obj, Event event, float deltaTime);


// Function Prototypes
// Game Loop Function
void GameLoop(GameData *data);

// Main Entry Point
int main(void)
{
	// Init raylib window
	InitWindow(SCREEN_WIDTH, SCREEN_HEIGHT, "Raylib Command Pattern and FSM Starter Kit GPP I");

	// Create GameData Pointer
	GameData *data = (GameData *)(malloc(sizeof(GameData)));

	// Initialise Game
	InitGame(data);

	// Set Target FPS
	SetTargetFPS(TARGET_FPS);

	// Raylib while loop
	while (!WindowShouldClose()) // Detect window close button or ESC key
	{
		// Call GameLoop
		GameLoop(data);
	}

	// Free resources
	CloseGame(data);

	// Close Raylib Window
	CloseWindow();

	return 0;
}

void PlayerEnterAttack(GameObject *obj, float deltaTime) {
printf("%s ENTER ATTACK\n", obj->name);
}

void PlayerUpdateAttack(GameObject *obj, float deltaTime) {
printf("%s is ATTACKING...\n", obj->name);
ChangeState(obj, STATE_CROUCH); // auto leave attack
}

void PlayerExitAttack(GameObject *obj, float deltaTime) {
printf("%s EXIT ATTACK\n", obj->name);
}

void PlayerAttackHandleEvent(GameObject *obj, Event event, float deltaTime) {
switch(event) {
case EVENT_SHIELD: ChangeState(obj, STATE_SHIELD); break;
case EVENT_CROUCH: ChangeState(obj, STATE_CROUCH); break;
default: break;
}
}

//crouch
void PlayerEnterCrouch(GameObject *obj, float deltaTime) {
printf("%s ENTER CROUCH\n", obj->name);
}

void PlayerUpdateCrouch(GameObject *obj, float deltaTime) {
printf("%s is CROUCHING...\n", obj->name);
}

void PlayerExitCrouch(GameObject *obj, float deltaTime) {
printf("%s EXIT CROUCH\n", obj->name);
}

void PlayerCrouchHandleEvent(GameObject *obj, Event event, float deltaTime) {
switch(event) {
case EVENT_ATTACK: ChangeState(obj, STATE_ATTACK); break;
case EVENT_SHIELD: ChangeState(obj, STATE_SHIELD); break;
case EVENT_STOP:   ChangeState(obj, STATE_SHIELD); break;
default: break;
}
}

//shield
void PlayerEnterShield(GameObject *obj, float deltaTime) {
printf("%s ENTER SHIELD\n", obj->name);
}

void PlayerUpdateShield(GameObject *obj, float deltaTime) {
printf("%s is SHIELDING...\n", obj->name);
}

void PlayerExitShield(GameObject *obj, float deltaTime) {
printf("%s EXIT SHIELD\n", obj->name);
}

void PlayerShieldHandleEvent(GameObject *obj, Event event, float deltaTime) {
switch(event) {
case EVENT_ATTACK: ChangeState(obj, STATE_ATTACK); break;
case EVENT_CROUCH: ChangeState(obj, STATE_CROUCH); break;
case EVENT_STOP:   ChangeState(obj, STATE_CROUCH); break;
default: break;
}
}



void GameLoop(GameData *data)
{
	// Update Game Data
	// Should be outside BeginDrawing(); and EndDrawing();
	float deltaTime = GetFrameTime(); // Get delta time frame time expressed in seconds

	UpdateGame(data, deltaTime);

	// Raylib function Draw
	BeginDrawing();

	// Clear the Frame
	ClearBackground(RAYWHITE);

	// Draw the Game Objects
	DrawGame(data);

	// Raylib End drawing to Frame Buffer
	EndDrawing();
}
