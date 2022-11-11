#include <iostream>
#include "Header.h"
#include <fstream>
#include <string>
int main( int argc, char* argv[]  )
{
    std::string path;
    if (argc < 2)
    {
        std::cout << "Error, route file is not added!" << std::endl;
        return 0;
    }
    for (int i = 0; i < argc; i++)
    {
        std::cout << argv[i] << std::endl;
        path = argv[i];
    }


    Route routes;
    RoutePoint point;

    std::ifstream file;
    file.open(path);

    if (!file.is_open())
    {
        std::cout << "Error opening file!" << std::endl;
    }

    else
    {
        std::cout << "File opened" << std::endl;

        int t_x;
        int t_y;
        std::string t_name;
        while (!file.eof())
        {
            file >> t_x;
            file >> t_y;
            file >> t_name;
            
            point.xKm = t_x;
            point.yKm = t_y;
            point.name = t_name;

            routes.addpoint(point);

        }
    }
    file.close();


    IVehicle* vehicles[4] = { new Sedan, new Suv, new Bus, new Bicycle }; // создаем объекты классов

    for (int i = 0; i < 4; ++i)
    {
        std::cout << std::endl << "---------------" << std::endl;
        IVehicle* vehicle = vehicles[i];
        for (int n = 0; n < 1; n++)
        {
            routes.run(vehicle);
            std::cout << std::endl;
        }
    }
    return 0;
}
