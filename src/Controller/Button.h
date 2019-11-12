#include <string.h>

class Button{
    public:
        Button();
        void setup();
        void loop();
        void print();
        String getValue();
        boolean getToggle();

    private:
        const int buttonPin = 23;
        String value;
        boolean toggle;
};