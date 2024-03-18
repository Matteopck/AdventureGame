#include <iostream>
#include <cstdlib>
#include <ctime>
#include <chrono>
#include <thread>
#include <conio.h> 
using namespace std;

const int ROWS = 20;
const int COLUMNS = 30;
const int MAX_HEALTH = 100;

class Character {
protected:
    int row, column;
   

public:
    int health;
    Character(int r, int c, int h) : row(r), column(c), health(h) {}

    int getRow() const { return row; }
    int getColumn() const { return column; }
    int getHealth() const { return health; }

    virtual void move() = 0;
};

class Adventurer : public Character {
public:
    Adventurer(int r, int c, int h) : Character(r, c, h) {}

    void move() {
        char movement = _getch(); // Get the key pressed without waiting for Enter

        switch (movement) {
            case 72: // Up arrow key
                if (row - 1 >= 0) {
                    row--;
                }
                break;
            case 80: // Down arrow key
                if (row + 1 < ROWS) {
                    row++;
                }
                break;
            case 75: // Left arrow key
                if (column - 1 >= 0) {
                    column--;
                }
                break;
            case 77: // Right arrow key
                if (column + 1 < COLUMNS) {
                    column++;
                }
                break;
            case 32: // Space key
                if (row - 2 >= 0) {
                    row -= 2;
                }
                break;
            default:
                break;
        }
    }
};

class NPC : public Character {
public:
    NPC(int r, int c, int h) : Character(r, c, h) {}

    void move() {
        int direction = rand() % 4;

        switch (direction) {
            case 0: // Move up
                if (row - 1 >= 0) {
                    row--;
                }
                break;
            case 1: // Move down
                if (row + 1 < ROWS) {
                    row++;
                }
                break;
            case 2: // Move left
                if (column - 1 >= 0) {
                    column--;
                }
                break;
            case 3: // Move right
                if (column + 1 < COLUMNS) {
                    column++;
                }
                break;
            default:
                break;
        }
    }
};

void display_land(const Adventurer& adv, const NPC& npc) {
    system("cls"); // Clear the console in a Windows environment

    for (int i = 0; i < ROWS; i++) {
        for (int j = 0; j < COLUMNS; j++) {
            if (i == adv.getRow() && j == adv.getColumn()) {
                cout << 'A';
            } else if (i == npc.getRow() && j == npc.getColumn()) {
                cout << 'N';
            } else {
                cout << '_';
            }
        }
        cout << endl;
    }
}

/*void land_effect(Character& character) {
    int effect = rand() % 3; // 0: No effect, 1: Reduce health, 2: Increase health

    switch (effect) {
        case 1: // Reduce health by 30%
            character.health -= MAX_HEALTH * 0.3;
            if (character.health < 0) {
                character.health = 0;
            }
            cout << "Health reduced by 30%!" << endl;
            break;
        case 2: // Increase health by 20%
            character.health += MAX_HEALTH * 0.2;
            if (character.health > MAX_HEALTH) {
                character.health = MAX_HEALTH;
            }
            cout << "Health increased by 20%!" << endl;
            break;
        default:
            break;
    }
}*/

int main() {
    srand(time(0)); // Seed the random number generator

    int choice;
    do {
        cout << "Welcome to the Adventure Game!" << endl;
        cout << "1. Start Game" << endl;
        cout << "2. Exit" << endl;
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1: {
                Adventurer adventurer(1, 1, MAX_HEALTH);
                NPC npc(8, 18, MAX_HEALTH);

                while (true) {
                    display_land(adventurer, npc);
                    //cout<<"Adventurer Health is : "<<adventurer.health<<endl;
                    //cout<<"NPC Health is : "<<npc.health<<endl;

                    adventurer.move();
                    npc.move();

                    //land_effect(adventurer);
                    //land_effect(npc);

                    if (adventurer.getRow() == npc.getRow() && adventurer.getColumn() == npc.getColumn()) {
                        cout << "Winner!" << endl;
                        this_thread::sleep_for(chrono::milliseconds(1000));
                        break;
                    }

                    this_thread::sleep_for(chrono::milliseconds(200));
                }
                break;
            }
            case 2:
                cout << "Exiting the game. Goodbye!" << endl;
                break;
            default:
                cout << "Invalid choice. Please try again." << endl;
        }
    } while (choice != 2);

    return 0;
}