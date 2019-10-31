class Drone {
    public:
        Drone ();
        void connect();
        void myloop();
    private:
        int x;
        int y;
        int pinX;
        int pinY;
};