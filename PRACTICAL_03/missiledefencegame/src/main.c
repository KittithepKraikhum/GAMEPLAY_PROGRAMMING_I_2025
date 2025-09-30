#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

// Define Position xy struct
typedef struct Position
{
  int x;
  int y;
} Coordinates;

// Define WarHead enum type
typedef enum
{
  EXPLOSIVE,
  NUCLEAR
} WarHead;

// Define Enemy struct type with Coordinates
typedef struct Enemy
{
  Coordinates coordinates;
} Target;

// Define Missile struct type with WarHead, Coordinates, Target, and armed status
typedef struct Missile
{
  WarHead payload;
  Coordinates coordinates;
  Target target;

  bool armed;

  // ADVANCED: Function pointers (direct function calls can be used instead)
  // Function pointer to update missile position

  void (*update)(struct Missile *missile);

  // Function pointer to arm or disarm missile
  void (*arm)(struct Missile *missile);

} Missile;

// Function to arm or disarm a missile
void armMissile(struct Missile *missile)
{
  if (missile->armed)
    missile->armed = false;
  else
    missile->armed = true;
}

// Function to update missile position
void updateMissile(struct Missile *missile)
{
  missile->coordinates.x += 1;
  missile->coordinates.y += 2;
}

// Function to print coordinates
void printCoordinates(Coordinates c)
{
  printf("X: %d, Y: %d\n", c.x, c.y);
}

// Main entry point for the game
int main()
{
  // Create a new Target
  Target *target = (Target *)malloc(sizeof(Target));

  // Set Enemy Position / Target coordinates
  target->coordinates.x = 2;
  target->coordinates.y = 2;

//Simple text menu to launch missiles or quit

  //user input
  int userPlay = 0;
  printf("Welcome to Missile Defence Game\n");
  printf("Press 0 to exit the game\n");
  printf("Press 1 to Launch Missile\n");
  scanf("%d",&userPlay);

   if(userPlay == 0)
        {
          printf("Goodbye!\n");
          return 0;
        }	

  // Print Target Coordinates
  printf("Print Target Coordinates\n");
  printCoordinates(target->coordinates);

  // Create a new Missile
  Missile *missile = (Missile *)malloc(sizeof(Missile));

  // Set Missile Payload
  missile->payload = EXPLOSIVE;
  missile->arm = armMissile;
  missile->update = updateMissile;

  // Set Missile Armed Status
  missile->arm(missile);

  // Print Missile Armed Status
  if (missile->armed)
    printf("Missile is Armed\n");
  else
    printf("Missile is NOT Armed\n");

  // Set Missile Target by dereferencing Target pointer
  missile->target = *target;

  // Set Initial Position
  missile->coordinates.x = 0;
  missile->coordinates.y = 0;

  // Print Position
  printf("Print Missile Position\n");
  printCoordinates(missile->coordinates);

  // Update Position
  missile->update(missile);

  // Print Missile Position
  printf("Print Missile Position after an Update\n");
  printCoordinates(missile->coordinates);

  // Print Missile target
  printf("Print Missile Target Position\n");
  printCoordinates(missile->target.coordinates);

  // Free Memory
  free(target);
  free(missile);

  // Pause
  printf("Press Enter to end game.\n");
  getchar();

  return 0;
}
