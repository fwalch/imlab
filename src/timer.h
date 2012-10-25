class Timer {
  private:
    clock_t start_clock;

  public:
    unsigned long ticks;
    double seconds;
    void start();
    void stop();
};
