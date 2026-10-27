

#include <iostream>
#include <string>

using namespace std;

class Robot {
private:
    int x;
    int y;
    int battery;
    int direction; // 0 = North, 1 = East, 2 = South, 3 = West

    string getDirectionName() {
        if (direction == 0) return "North";
        if (direction == 1) return "East";
        if (direction == 2) return "South";
        return "West";
    }

public:
    Robot(int startingBattery) {
        x = 0;
        y = 0;
        battery = startingBattery;
        direction = 0;
    }

    void moveForward() {
        if (battery < 5) {
            cout << "Not enough battery to move!\n";
            return;
        }

        if (direction == 0) y++;
        else if (direction == 1) x++;
        else if (direction == 2) y--;
        else x--;

        battery -= 5;
        cout << "Moved forward!\n";
    }

    void moveBackward() {
        if (battery < 5) {
            cout << "Not enough battery to move!\n";
            return;
        }

        if (direction == 0) y--;
        else if (direction == 1) x--;
        else if (direction == 2) y++;
        else x++;

        battery -= 5;
        cout << "Moved backward!\n";
    }

    void turnLeft() {
        direction = (direction + 3) % 4;
        cout << "Turned left. Facing " << getDirectionName() << ".\n";
    }

    void turnRight() {
        direction = (direction + 1) % 4;
        cout << "Turned right. Facing " << getDirectionName() << ".\n";
    }

    void chargeBattery() {
        battery += 20;

        if (battery > 100) {
            battery = 100;
        }

        cout << "Battery charged to " << battery << "%.\n";
    }

    void showStatus() {
        cout << "\n--- Robot Status ---\n";
        cout << "Position: (" << x << ", " << y << ")\n";
        cout << "Direction: " << getDirectionName() << "\n";
        cout << "Battery: " << battery << "%\n";
    }
};


int main() {
    Robot robot(100);
    int choice = 0;

    while (choice != 6) {
        cout << "\n=== ROBOT COMMAND SIMULATOR ===\n";
        cout << "1. Move forward\n";
        cout << "2. Move backward\n";
        cout << "3. Turn left\n";
        cout << "4. Turn right\n";
        cout << "5. Show status / charge battery\n";
        cout << "6. Exit\n";
        cout << "Enter command: ";

        cin >> choice;

        if (choice == 1) {
            robot.moveForward();
        }
        else if (choice == 2) {
            robot.moveBackward();
        }
        else if (choice == 3) {
            robot.turnLeft();
        }
        else if (choice == 4) {
            robot.turnRight();
        }
        else if (choice == 5) {
            robot.showStatus();

            cout << "Charge battery too? (1 = Yes, 0 = No): ";
            int chargeChoice;
            cin >> chargeChoice;

            if (chargeChoice == 1) {
                robot.chargeBattery();
            }
        }
        else if (choice == 6) {
            cout << "Shutting down robot. Goodbye!\n";
        }
        else {
            cout << "Invalid command. Choose 1-6.\n";
        }
    }

    return 0;
}

