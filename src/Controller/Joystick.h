#include <string.h>

class Joystick{
    public:
        Joystick();
        void setup();
        void loop();
        String print();
        int getXPosition();
        int getYPosition();
        boolean getStopButton();
        
    private:
        const int xPin = 35;
        const int yPin = 34;
        const int swPin = 32;
        int xVal;
        int yVal;
        int deadZone = 200;
        boolean swVal;
        String joystickValue;
};