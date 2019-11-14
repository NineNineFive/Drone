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
        const int xPin = 34;
        const int yPin = 35;
        const int swPin = 15;
        int xVal;
        int yVal;
        int deadZone = 200;
        boolean swVal;
        String joystickValue;
};