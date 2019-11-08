#include <string.h>

class Button{
    public:
        Button();
        void setup();
        void loop();
        void print();
        String getButtonValue();

    private:
        const int buttonPin = 23;
        String buttonValue;
};