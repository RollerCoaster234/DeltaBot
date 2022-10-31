#pragma once
#include <avr/pgmspace.h>

template<typename T>
class vector
{
    public:
    T& operator [](size_t position) const
    {
        if (m_currentSize < position)
        {
            m_currentSize = position;
        }

        return at(position);
    }

    T& at(size_t position) const
    {
        if (position > m_reservedSize || position < 0)
        {
#ifdef DEBUG
            Serial.println("Out of bounds access! Vector size: " + String(m_currentSize) + "; accesed position: " + String(position) + "!");
#endif
            return &m_dataArr[0];
        }
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
            *(newArr + i * m_elementSize) = *(m_dataArr + i * m_elementSize); 
        }

        delete[] m_dataArr;
        m_dataArr = newArr;

        m_reservedSize = size;
    }

    void reserve(size_t size, T fillElement)
    {
        reserve(size);
        for (size_t i = m_currentSize; i < m_reservedSize; i++)
        {
            // copy fill element into reserved space using copy constructor
            *(m_dataArr + i * m_elementSize) = T(fillElement);
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
        setup();
        reserve(m_reservedSize);
    }

    vector(T fillElement)
    {
        setup();
        reserve(m_reservedSize, fillElement);
    }

    ~vector()
    {
        delete[] m_dataArr;
    }

    private:

    void setup(size_t currentSize=0, size_t elementSize=sizeof(T), size_t reservedSize=static_cast<int>(sizeof(T)/16))
    {
        if (m_reservedSize  == 0)
        {
            m_reservedSize = 4;
        }
    }

    T* m_dataArr;
    size_t m_currentSize;
    size_t m_reservedSize;
    size_t m_elementSize;
};