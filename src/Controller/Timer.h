class Timer {
    public:
        Timer(long milliseconds);
        long getTime();
        boolean check();
    private:
        long waitingTime;
        long timeSinceStart;
        long frame;
        long iteratorTime;
};
