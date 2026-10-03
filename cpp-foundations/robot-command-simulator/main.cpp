#include <iostream>

int sensorReadings[4] = {20, 35, 42, 18};

int moveForward(int position, int speed)
{
    return position + speed;
}
/*
void drainBattery(int* battery)
{
    *battery = *battery - 10;
}
*/

void drainBattery(int* battery)
{
    if (battery != nullptr)
    {
        *battery = *battery - 10;
    }
}

void drainBattery(int& battery)
{
    battery = battery - 10;
}

class Robot
{
    private:
    int battery;
    int speed;
    int position;

    public:
    Robot(int startingBattery, int startingSpeed, int startingPosition)
    {
        battery = startingBattery;
        speed = startingSpeed;
        position = startingPosition;
    }
    void move()
    {
        position = position + speed;
    }

    int getPosition()
    {
        return position;
    }

    void drainBattery()
    {
        battery = battery - 10;
    }

    int getBattery()
    {
        return battery;
    }

    void charge()
    {
        std::cout << "Charging...\n";
    }

    void honk()
    {
        std::cout << "Beep beep!\n";
    }

};

class WheeledRobot : public Robot
{
    public:
    WheeledRobot(int battery, int speed, int position)
        : Robot(battery, speed, position)
    {
    }
};

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
        position = moveForward(position, speed);
        std::cout << "position = " << position << "\n";
    }

    for (int i = 0; i < 4; i++)
    {
        std::cout <<"i = " << i << " = " << "sensorReadings[" << i << "] = " << sensorReadings[i] << "\n";
    }

    for (int i = 0; i < 4; i++)
    {   
        std::cout << "Sensor " << i << ": " << sensorReadings[i] << " cm\n";
    }

    std::string command = "forward";
    std::cout << "Command: " << command << "\n";

    /*
    std::string userCommand;
    std::cout << "Enter a robot command: ";
    std::cin >> userCommand;
    std::cout << "Command received: " << userCommand << "\n";

    
    if (userCommand == "forward")
    {
        std::cout << "Robot moving forward!\n";
    }
    else if (userCommand == "backward")
    {
        std::cout << "Robot moving backward!\n";
    }
    else if (userCommand == "stop")
    {
        std::cout << "Robot is currently not moving!\n";
    }
    */

    /*
    int* batteryPtr = &battery;
    *batteryPtr = 50;
    drainBattery(&battery);

    std::cout << "Battery address: " << &battery << "\n";
    std::cout << "Battery pointer: " << batteryPtr << "\n";
    std::cout << "Battery through pointer: " << *batteryPtr << "\n";
    std::cout << "Battery: " << battery << "\n";
    battery = battery - 10;
    std::cout << "Drained battery address: " << &battery << "\n";
    std::cout << "Drained battery pointer: " << *batteryPtr << "\n";
    */

    drainBattery(&battery);
    std::cout << "Battery after draining: " << battery << "\n";

    drainBattery(battery);
    std::cout << "Battery after draining: " << battery << "\n";

    Robot myRobot1(100, 10, 0);
    myRobot1.move();
    std::cout << "Robot1 position: " << myRobot1.getPosition() << "\n";
    myRobot1.drainBattery();
    std::cout << "Robot1 Battery: " << myRobot1.getBattery() << "\n";
    
    Robot myRobot2(75, 20, 50);
    myRobot2.move();
    std::cout << "Robot2 position: " << myRobot2.getPosition() << "\n";
    myRobot2.drainBattery();
    std::cout << "Robot2 Battery: " << myRobot2.getBattery() << "\n";
    myRobot2.drainBattery();
    std::cout << "Robot2 Battery: " << myRobot2.getBattery() << "\n";
   
    WheeledRobot myWheeledRobot(100, 10, 0);
    myWheeledRobot.charge();
    myWheeledRobot.honk();

    return 0;
}
