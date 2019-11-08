class Potentiometer {
    public:
        Potentiometer ();
        void setup();
        void loop();
        void print();
    private:
        const int potentiometerPin = 27;
        int frequency;
};
