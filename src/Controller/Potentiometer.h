class Potentiometer {
    public:
        Potentiometer();
        void setup();
        void loop();
        void print();
        int getValue();

    private:
        const int potentiometerPin = 27;
        int value;
};
