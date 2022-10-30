#pragma once
#include <Arduino.h>
// #include <avr/pgmspace.h>
// #include <pins_arduino.h>

namespace timer
{
    template <typename T>
    class Time
    {
    public:
        enum TimeUnit
        {
            Microsecond,
            Millisecond,
            Second,
            Minute,
            Hour
        };

        void SetTimeInUnit(TimeUnit unit, T value); // Sets time in the given unit
        void AddTimeInUnit(TimeUnit unit, T value); // Adds time in the given unit

        const T GetTimeInUnit(TimeUnit unit) const; // Computes time internally in the give unit
        const TimeUnit GetTimeUnit() const;         // Gets smallest unit of change // unit of resolution

        Time() = default; // default constructor
        Time(const Time &toCopy);
        ~Time();

    private:
        T *m_timeInUnitArray; // Number of counting units // Is array to facilitate dynamic expansion in case of overflow
        TimeUnit m_timeUnit;  // Smallest unit of change // this gives the resolution
    };

    class TimerConfiguration
    {
    public:
        enum TimerCounter
        {
            Timer0,
            Timer1,
            Timer2
        };

        enum TimerMode
        {
            Nomal,
            CTC,
            FastPWM,
            PhasePWM,
            PhaseAndFreqPWM
        };

        enum CountMode
        {
            Bottom,
            Top,
            Max
        };

        enum ClockSource
        {
            NoSource,
            Source,
            DivBy8,
            DivBy64,
            DivBy256,
            DivBy1024,
            ExternalT0Falling,
            ExternalT0Rising
        };

        enum CountDirection
        {
            Up,
            Down
        };


        void SetOutputPins(uint8_t *outputPinsArray);
        const uint8_t *GetOutputPins() const;

        void SetCounterInteger(uint64_t count);
        const uint64_t &GetCounterInteger() const;

        void SetTimerMode(TimerMode type);
        const TimerMode &GetTimerMode() const;

        void SetCountMode(CountMode mode);
        const CountMode &GetCountMode() const;

        void SetClockSource(ClockSource clock);
        const ClockSource &GetClockSource() const;

        void SetCountDirection(CountDirection direction);
        const CountDirection &GetCountDirection() const;

        void SetInterruptFunction(void *func);
        const void *GetInterruptFunction() const;

        void SetTimer(const TimerCounter &timerCounter);
        TimerCounter &GetTimer() const;

        TimerConfiguration();
        TimerConfiguration(const TimerConfiguration &toCopy);
        ~TimerConfiguration();

    private:
        uint8_t *m_outputPinsArr;
        uint8_t *m_outputSoftwarePinsArr;
        uint8_t *m_outputHardwarePinsArr;

        uint64_t m_count;
        TimerCounter m_timer;

        ClockSource m_clockSrc;
        TimerMode m_TimerType;
        CountMode m_countMode;

        void *m_interruptVector;
    };

    class Timer
    {
    public:


        void SetTimerConfiguration(const TimerConfiguration &config);
        TimerConfiguration &GetTimerConfiguration();

        void StartTimer();
        void StopTimer();
        void ResetTimer();

        // Timer() = default; // default constructor
        Timer(const TimerConfiguration &config);
        Timer(const Timer &) = delete; // disallow the copy constructor due to hardware limitations
        // ~Timer();

    private:
        virtual void ArmTimer();
        virtual void DisarmTimer();

        TimerConfiguration m_timerConfig;
        uint8_t *RegisterA;
        uint8_t *RegisterB;
        uint8_t *RegisterC;
        uint8_t *InterruptMaskRegister;
        uint8_t *GeneralTimerControlRegister;
        uint8_t *CounterValueRegisterLow;
        uint8_t *CounterValueRegisterHigh;
        uint8_t *CompareRegisterALow;
        uint8_t *CompareRegisterAHigh;
        uint8_t *CompareRegisterBLow;
        uint8_t *CompareRegisterBHigh;
    };

    namespace TimerPinUtils
    {
        static const uint8_t Timer0OutputPins[2] = {TIMER0A, TIMER0B};
        static const uint8_t Timer1OutputPins[2] = {TIMER1A, TIMER1B};
        static const uint8_t Timer2OutputPins[2] = {TIMER2A, TIMER2B};

        static inline bool
        CheckIfPinIsHardwareTimerOutput(TimerConfiguration::TimerCounter timer, int pin)
        {
            uint8_t* timerPins = nullptr;
            switch (timer)
            {
            case TimerConfiguration::TimerCounter::Timer0:
                timerPins = const_cast<uint8_t*>(Timer0OutputPins);
                break;
            case TimerConfiguration::TimerCounter::Timer1:
                timerPins = const_cast<uint8_t*>(Timer1OutputPins);
                break;
            case TimerConfiguration::TimerCounter::Timer2:
                timerPins = const_cast<uint8_t*>(Timer2OutputPins);
                break;
            default:
                return false;
            }

            for (size_t i = 0; i < 2; i++)
            {
                if (timerPins[i] == digitalPinToTimer(pin))
                    return true;
            }
            return false;
        }
    };
} // namespace timer