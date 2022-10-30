#include <timer.hpp>

namespace timer
{
    /*
    TimerConfiguration class implementation
    */

    void TimerConfiguration::SetOutputPins(uint8_t *outputPinsArray)
    {
        
    }
    const uint8_t *TimerConfiguration::GetOutputPins() const
    {
    }

    void SetCounterInteger(uint64_t count)
    {
    }
    const uint64_t &TimerConfiguration::GetCounterInteger() const
    {
    }

    void TimerConfiguration::SetTimerMode(TimerConfiguration::TimerMode type)
    {
    }
    const TimerConfiguration::TimerMode &TimerConfiguration::GetTimerMode() const
    {
    }

    void TimerConfiguration::SetCountMode(TimerConfiguration::CountMode mode)
    {
    }
    const TimerConfiguration::CountMode &TimerConfiguration::GetCountMode() const
    {
    }

    void TimerConfiguration::SetClockSource(TimerConfiguration::ClockSource clock)
    {
    }
    const TimerConfiguration::ClockSource &TimerConfiguration::GetClockSource() const
    {
    }

    void TimerConfiguration::SetCountDirection(TimerConfiguration::CountDirection direction)
    {
    }

    const TimerConfiguration::CountDirection &TimerConfiguration::GetCountDirection() const
    {
    }

    void TimerConfiguration::SetInterruptFunction(void *func)
    {
    }
    const void *TimerConfiguration::GetInterruptFunction() const
    {
    }

    TimerConfiguration::TimerConfiguration()
    {
    }

    TimerConfiguration::TimerConfiguration(const TimerConfiguration &toCopy)
    {
    }

    TimerConfiguration::~TimerConfiguration()
    {
    }

    /*
        Timer class implementation
    */

    void Timer::SetTimerConfiguration(const TimerConfiguration &config)
    {
    }

    TimerConfiguration &Timer::GetTimerConfiguration()
    {
    }

    void Timer::SetTimer(const Timer::TimerCounter &timerCounter)
    {
    }

    Timer::TimerCounter &Timer::GetTimer() const
    {
    }

    void Timer::StartTimer()
    {
    }
    void Timer::StopTimer()
    {
    }
    void Timer::ResetTimer()
    {
    }

    Timer::Timer(const Timer::TimerCounter &timerCounter, const TimerConfiguration &config)
    {
    }

    Timer::~Timer()
    {
    }
}