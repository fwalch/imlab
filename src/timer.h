/**
 * Defines a timer implementation.
 */
class Timer {
  private:
    clock_t start_clock;

  public:
    /** Number of ticks from start to stop */
    long ticks;
    /** Number of seconds from start to stop */
    double seconds;
    /** Starts the timer */
    void start();
    /** Stops the timer and assigns ticks and seconds */
    void stop();
};
