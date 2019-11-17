#include <string.h>

class Button{
    public:
        Button();
        void setup();
        void loop();
        void print();
        boolean getToggle();
        boolean getFlipButton();

    private:
        const int toogleButtonPin = 23;
        const int flipButtonPin = 15;
        boolean toggle;
        boolean lastToggle;
        boolean flipButton;
};