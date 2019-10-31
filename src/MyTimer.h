#include <string>
using namespace std;

class MyTimer {
    public:
        long timer;
        long timerSinceStart;
        long frame;
        MyTimer(long seconds); 
        bool loop();
    private:
};