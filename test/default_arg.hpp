#pragma once

class default_arg
{
public:
    static unsigned& destructor_counter()
    {
        static unsigned counter = 0;
        return counter;
    }

    int value;

    operator int() const { return value; }

    explicit default_arg() : value(1000) {}

    default_arg(default_arg&& other) : value(other.value) { other.value = 0; }

    default_arg(const default_arg& other) = delete;

    ~default_arg()
    {
        if (value)
            ++destructor_counter();
    }

    default_arg& operator=(default_arg&& other)
    {
        if (this != &other)
        {
            value = other.value;
            other.value = 0;
        }
        return *this;
    }

    default_arg& operator=(const default_arg& other) = delete;
};
