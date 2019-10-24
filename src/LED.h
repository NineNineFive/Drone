#include <string>
#include <Timer.h>
using namespace std;

class LED
{
    public:
        int pin;
        string message;
        //Timer timer;
        LED(int pin); 
        void setup();
        void turnOnLED(boolean state);
        void loop();
        void print();
    private:
        
};