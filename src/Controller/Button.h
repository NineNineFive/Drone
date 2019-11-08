#include <string.h>

class Button{
    public:
        Button();
        void setup();
        void loop();
        void print();

    private:
        const int buttonPin = 7;
        String buttonValue;
};