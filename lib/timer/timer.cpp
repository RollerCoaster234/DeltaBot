#include <timer.hpp>

namespace timer
{
    /*
    TimerConfiguration class implementation
    */

    void TimerConfiguration::SetOutputPins(uint8_t *outputPinsArray)
    {
        int i = 0;
        int softPinsArr[10] = {-1};
        int hardPinsArr[10] = {-1};
        Serial.println("tried timer " + String(m_timer));
        while (outputPinsArray[i] != NULL)
        {
            if (TimerPinUtils::CheckIfPinIsHardwareTimerOutput(m_timer, outputPinsArray[i]))
            {
                Serial.println(String(outputPinsArray[i]) + " true");
            }
            else
            {
                Serial.println(String(outputPinsArray[i]) + " false");
            }

            i++;
        }
        Serial.println("fin");
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

    void TimerConfiguration::SetTimer(const TimerConfiguration::TimerCounter &timerCounter)
    {
        Serial.println("timeeer");
        m_timer = timerCounter;
    }

    TimerConfiguration::TimerCounter &TimerConfiguration::GetTimer() const
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

    Timer::Timer(const TimerConfiguration &config)
    {
    }

    // Timer::~Timer()
    // {
    // }
}