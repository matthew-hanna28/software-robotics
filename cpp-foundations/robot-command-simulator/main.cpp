#include <iostream>

void moveForward(int& position, int speed)
{
    position = position + speed;
}

int main()
{
    std::cout << "Robot Command Simulator\n";
    std::cout << "Robot online!\n";
    int battery = 100;
    int speed = 10;
    int position = 0;
    double temperature = 36.5;
    bool active = true;
    int time;

    std::cout << "battery: " <<battery << "\n";
    std::cout << "speed: " << speed << "\n";
    std::cout << "position: " << position << "\n";
    std::cout << "temperature: " << temperature << "\n";
    std::cout << "active: " << active << "\n";

    battery = battery - 20;

     std::cout << "Battery after movement: " << battery << "\n";

   // std::cout << "How many seconds should the robot move? ";

   // std::cin >> time;

   // position = speed * time;

   // std::cout << "New position: " << position << "\n";

    for (int i = 0; i < 5; i++)
    {
        moveForward(position, speed);
        std::cout << "position = " << position << "\n";
    }

    return 0;
}