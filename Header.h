#pragma once
#include <iostream>
#include <vector>
#include <string>

class IVehicle
{
public:
    int mileage = 0;
    virtual bool drive(int kilometres) = 0;
    virtual void refuel() = 0;
    virtual void printStatus() = 0;
};

class AbstractCar : public IVehicle
{
public:
    AbstractCar();

    int mileage;
    double fuel;
    double max_fuel;
    double fuel_drain;

    bool drive(int kilometres); // наматывает пробег и тратит топливо
    void refuel(); // заправка на полный бак
    void printStatus(); // вывод информации о пробеге и текущем топливе

};

class Sedan : public AbstractCar // наследование класса Vehicle классами Sedan, Suv и Bus, возможны ошибки в параметрах доступа
{
public:
    Sedan() { fuel = 0; max_fuel = 40; fuel_drain = 0.1; }
};

class Suv : public AbstractCar
{
public:
    Suv() { fuel = 0; max_fuel = 50; fuel_drain = 0.15; }

};

class Bus : public AbstractCar
{
public:
    Bus() { fuel = 0; max_fuel = 50; fuel_drain = 0.2; }

};

class Bicycle : public IVehicle
{
public:
    bool drive(int kilometres)
    {
        mileage += kilometres;
        return true;
    }

    void refuel()
    {
        std::cout << std::endl;
        std::cout << "no fuel tank" << std::endl;
    }

    void printStatus()
    {
        std::cout << std::endl;
        std::cout << "mileage = " << mileage << " km" << std::endl;
    }
};

struct RoutePoint
{
    RoutePoint();
    int xKm; // координата x в км
    int yKm; // координата y в км
    std::string name; // название точки маршрута
};

class Route
{
public:
    std::vector <RoutePoint>  Pointslist_vector{};
    void addpoint(const RoutePoint& point);
    void run(IVehicle* vehicle);
};
