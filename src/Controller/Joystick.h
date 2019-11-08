#include <string.h>

class Joystick{
    public:
        Joystick();
        void setup();
        void loop();
        void print();
        int getX();
        int getY();
        int getSW();
        
    private:
        const int xPin = 15;
        const int yPin = 4;
        const int swPin = 5;
        int xVal;
        int yVal;
        int swVal;
        String joystickValue;
};