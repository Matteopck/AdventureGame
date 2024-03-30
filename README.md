README

-- Description :
This code is a simple text-based adventure game implemented in C++. The game features an adventurer character that the player can control using the arrow keys and the space bar.
The game world consists of a grid of cells, where the adventurer can move around and encounter non-player characters (NPCs) and land enemies.
The game's objective is for the adventurer to reach the NPC while avoiding the land enemies. If the adventurer collides with a land enemy, their health decreases by 30%.
If the adventurer's health drops to zero or below, the game is lost. If the adventurer reaches the NPC, the game is won.


-- Classes
The code defines the following classes:
Character: This is an abstract base class that represents a character in the game world. It has properties for the character's row, column, and health. It also has a pure virtual function move() that must be implemented by derived classes.
Adventurer: This class is derived from Character and represents the player-controlled character. It overrides the move() function to handle user input from the arrow keys and the space bar.
NPC: This class is derived from Character and represents a non-player character. It overrides the move() function to make the NPC move randomly within the game world.
LandEnemy: This class is derived from Character and represents a land-based enemy. It overrides the move() function to make the land enemy move randomly within the game world.


-- Functions
The code includes the following functions:
display_land(): This function is responsible for rendering the game world by printing the characters' symbols on the console.
land_effect(): This function handles the collision detection between the adventurer and the land enemies. If a collision occurs, the adventurer's health is decreased by 30%.
main(): This is the entry point of the program. It presents a menu to the user, allowing them to start the game or exit. If the user chooses to start the game, it creates instances of the Adventurer, NPC, and LandEnemy classes and enters the game loop.


-- How to Run
To run the game, compile the code using a C++ compiler and execute the resulting binary file. The game will display a menu, prompting the user to start the game or exit.
Once the game starts, use the arrow keys to move the adventurer and the space bar to perform a double jump. The objective is to reach the NPC while avoiding the land enemies.
Note: This code requires the conio.h header file, which is a non-standard header file specific to certain compilers and operating systems. 
If your compiler does not support conio.h, you may need to replace the _getch() function with an alternative method for reading user input.
