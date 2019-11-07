class Potentiometer {
    public:
        Potentiometer ();
        void setup();
        void loop();
        void print();
    private:
        int potentiometerPin = 27;
        int frequency;
};
