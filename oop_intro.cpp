#include <iostream>

class Counter
{
private:
    int _value;

public:
    Counter(void) : _value(0) {}
    Counter(const Counter& other) : _value(other._value) {}
    Counter& operator=(const Counter& other)
    {
        if (this != &other)
            _value = other._value;
        return *this;
    }
    ~Counter(void) {}

    void increment(void)
    {
        ++_value;
    }

    int getValue(void) const
    {
        return _value;
    }
};

template <typename T>
class Pair
{
private:
    T _first;
    T _second;

public:
    Pair(const T& first, const T& second)
        : _first(first), _second(second) {}

    const T& getFirst(void) const
    {
        return _first;
    }

    const T& getSecond(void) const
    {
        return _second;
    }
};

class Shape
{
public:
    virtual ~Shape(void) {}
    virtual double area(void) const = 0;
};

class Rectangle : public Shape
{
private:
    double _width;
    double _height;

public:
    Rectangle(double width, double height)
        : _width(width), _height(height) {}

    virtual double area(void) const
    {
        return _width * _height;
    }
};

class Circle : public Shape
{
private:
    double _radius;

public:
    explicit Circle(double radius) : _radius(radius) {}

    virtual double area(void) const
    {
        return 3.14159265358979323846 * _radius * _radius;
    }
};

static void printArea(const Shape& shape)
{
    std::cout << shape.area() << std::endl;
}

int main(void)
{
    Counter counter;
    counter.increment();
    std::cout << counter.getValue() << std::endl;

    Counter copy(counter);
    copy.increment();
    std::cout << copy.getValue() << std::endl;

    Pair<int> numbers(4, 7);
    std::cout << numbers.getFirst() << " " << numbers.getSecond() << std::endl;

    Rectangle rectangle(3.0, 4.0);
    Circle circle(2.0);
    printArea(rectangle);
    printArea(circle);

    return 0;
}
