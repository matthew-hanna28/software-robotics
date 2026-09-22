#include <iostream>

int main()
{
    std::cout << "Robot Command Simulator\n";
    std::cout << "Robot online!\n";
    int battery = 100;
    int speed = 10;
    int position = 0;
    double temperature = 36.5;
    bool active = true;

    std::cout << "battery: " <<battery << "\n";
    std::cout << "speed: " << speed << "\n";
    std::cout << "position: " << position << "\n";
    std::cout << "temperature: " << temperature << "\n";
    std::cout << "active: " << active << "\n";

    position = speed * 5;

    std::cout << "New position: " << position << "\n";

    battery = battery - 20;

    std::cout << "Battery after movement: " << battery << "\n";


    return 0;
}