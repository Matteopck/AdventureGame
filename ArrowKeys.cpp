#include <iostream>
#include <cstdlib>
#include <ctime>
#include <chrono>
#include <thread>
#include <conio.h> 
using namespace std;

const int ROWS = 10;
const int COLUMNS = 20;
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
        char movement = _getch(); 

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

class LandEnemy : public Character {
public:
    LandEnemy(int r, int c, int h) : Character(r, c, h) {}

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

void display_land(const Adventurer& adv, const NPC& npc, const LandEnemy& L1, const LandEnemy& L2) {
    system("cls"); 
    
    for (int i = 0; i < ROWS; i++) {
        for (int j = 0; j < COLUMNS; j++) {
            if (i == adv.getRow() && j == adv.getColumn()) {
                cout << 'A';
            }else if (i == npc.getRow() && j == npc.getColumn()) {
                cout << 'N';
            }else if (i == L1.getRow() && j == L1.getColumn()) {
                cout << 'L';
            }else if (i == L2.getRow() && j == L2.getColumn()) {
                cout << 'l';
            }else {
                cout << '_';
            }
        }
        cout << endl;
    }
}

int land_effect(Adventurer& adventurer, LandEnemy& L1, LandEnemy& L2) {
    int Lose = 0;
    if (adventurer.getRow() == L1.getRow() && adventurer.getColumn() == L1.getColumn()) {
        adventurer.health -= MAX_HEALTH * 0.3;
        if (adventurer.health < 0) {
            cout << "Lose!" << endl;
            Lose = 1;
        }
    }
    if (adventurer.getRow() == L2.getRow() && adventurer.getColumn() == L2.getColumn()) {
        adventurer.health -= MAX_HEALTH * 0.3;
        if (adventurer.health < 0) {
            cout << "Lose!" << endl;
            Lose = 1;
        }
    }
    return Lose;
}

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
                LandEnemy L1(5,5, MAX_HEALTH);
                LandEnemy L2(9 ,10 , MAX_HEALTH);
                int Lose;
                while (Lose != 1) {
                    display_land(adventurer, npc, L1, L2);
                    cout<<"Adventurer Health is : "<<adventurer.health<<endl;
                    //cout<<"NPC Health is : "<<npc.health<<endl;

                    adventurer.move();
                    npc.move();
                    L1.move();
                    L2.move();

                    
                    Lose = land_effect(adventurer, L1, L2);
                    
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