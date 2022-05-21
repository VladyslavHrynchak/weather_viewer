#ifndef CITY_H
#define CITY_H
#include <string>

class City
{
public:
    City() = default;
   City(const std::string& name_, const std::string& lat_, const std::string& lon_);




    std::string name;
    std::string lat;
    std::string lon;


};

#endif
