class Potentiometer {
    public:
        Potentiometer();
        void setup();
        void loop();
        String print();
        int getHeightValue();

    private:
        const int potentiometerPin = 32;
        int potValue;
};