#include "Header.h"
#include <vector>
#include <cmath>
AbstractCar::AbstractCar() : mileage(0), fuel_drain(0), max_fuel(0), fuel(0) {} // ������������
RoutePoint::RoutePoint() : xKm(0), yKm(0), name() {}
bool AbstractCar::drive(int kilometres) // �������� ������� �� �������� � +������
{
    if (fuel >= fuel_drain * kilometres) {
        mileage += kilometres;
        fuel -= fuel_drain * kilometres;
        return true;
    }
    else {
        std::cout << std::endl;
        std::cout << "Not enough fuel to drive " << kilometres << "km" << std::endl;
        return false;
    }
}

void AbstractCar::refuel() // ������ ������ ���
{
    std::cout << std::endl;
    fuel = max_fuel; // max_fuel ����� ������������ � ������� ������ (����� �� ���������)
    std::cout << "fuel refilled" << std::endl;
}

void AbstractCar::printStatus() // ������� ������ � ���������� �������
{
    std::cout << std::endl;
    std::cout << "mileage = " << mileage << " km" << std::endl; // ���� ������� ������ �� ������� drive
    std::cout << "fuel = " << fuel << " L" << std::endl;
}

// ������� ���, ����� ����� ����������� �� ���������� ����� � ��������� � �������
void Route::addpoint(const RoutePoint& point)
{

    Pointslist_vector.push_back(point);
}

void Route::run(IVehicle* vehicle)
{
    int RouteDistance; // ���������� ���������� ��������
    std::cout << "run started" << std::endl;
    if (Pointslist_vector.size() < 2) // �������� �� ������� ���� ����� ��������
    {
        std::cout << "Route does not have 2 points!" << std::endl;
        return;
    }
    for (int point = 1; point < Pointslist_vector.size(); point++) // ���������� ����� ����� �������
    {
        RouteDistance = 0;
        RouteDistance = sqrt((pow(Pointslist_vector[point - 1].xKm - Pointslist_vector[point].xKm, 2)) + (pow(Pointslist_vector[point - 1].yKm - Pointslist_vector[point].yKm, 2)));
        // �������������� ���������� ����� ����� �������, ����� ����� ���������, ������� �� �� ����� ���������� �� ������ drive


        if (vehicle->drive(RouteDistance) == false)
        {
            vehicle->refuel();
            if (vehicle->drive(RouteDistance) == false)
                std::cout << "Vehicle cannot make it through this route!" << std::endl;
        }
    }
    vehicle->printStatus();
    std::cout << "run complete" << std::endl;

}
