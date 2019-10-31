#include <string>
using namespace std;

class Timer {
    public:
        long timer;
        long timerSinceStart;
        long frame;
        Timer(long seconds); 
        void loop();
    private:
        
};