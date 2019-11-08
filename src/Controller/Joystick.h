#include <string.h>

class Joystick{
    public:
        Joystick();
        void setup();
        void loop();
        void print();
        
    private:
        const int xPin = 5;
        const int yPin = 33;
        const int swPin = 14;
        int xVal;
        int yVal;
        int swVal;
        String joystickValue;
};