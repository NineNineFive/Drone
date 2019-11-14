class Potentiometer {
    public:
        Potentiometer();
        void setup();
        void loop();
        void print();
        int getHeightValue();

    private:
        const int potentiometerPin = 6;
        int potValue;
};