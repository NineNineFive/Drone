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
        const int button1Pin = 23;
        const int button2Pin = 8;
        boolean toggle;
        boolean lastToggle;
        boolean flipButton;
};