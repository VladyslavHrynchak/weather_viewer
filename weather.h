#ifndef WEATHER_H
#define WEATHER_H
#define CPPHTTPLIB_OPENSSL_SUPPORT
#include "httplib.h"
#include "nlohmann/json.hpp"
#include "city.h"
#include <vector>

class Weather
{
public:
  void start();

private:
    std::vector<City> cities;

    void addCities();

};

#endif
