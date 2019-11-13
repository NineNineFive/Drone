class Potentiometer {
    public:
        Potentiometer();
        void setup();
        void loop();
        void print();
        int getValue();

    private:
        const int potentiometerPin = 34;
        int value;
};
