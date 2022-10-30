#pragma once
#include <avr/pgmspace.h>

template<typename T>
class vector
{
    public:
    T& operator [](size_t position) const
    {
        return &m_dataArr[position];
    }

    T& at(size_t position) const
    {
        return &m_dataArr[position];
    }

    void reserve(size_t size)
    {
        if (size < m_currentSize)
        {
#ifdef DEBUG
            Serial.println("Vector reserve value under current element size! Current size: " + String(m_currentSize) + " New size: " + String(m_reservedSize));
#endif
            return;
        }
        T* newArr = new T[size];
        for (size_t i = 0; i < m_currentSize; i++)
        {
            newArr + i * m_elementSize 
        }
        
    }

    T* begin()
    {
        return m_dataArr;
    }

    T* end()
    {
        return m_dataArr + m_currentSize * m_elementSize;
    }

    vector()
    {

    }

    ~vector()
    {

    }

    private:
    T* m_dataArr;
    size_t m_currentSize;
    size_t m_reservedSize;
    size_t m_elementSize;
};