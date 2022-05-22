#include "weather.h"
#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

void Weather::addCities()
{
    City Lviv("Lviv","49.8382600","24.0232400");
    cities.push_back(Lviv);

    City Kyiv("Kyiv","50.4546600","30.5238000");
    cities.push_back(Kyiv);

    City Odesa("Odesa","46.4774700","30.7326200");
    cities.push_back(Odesa);

    City Uzgorod("Uzgorod","48.6166700","22.3000000");
    cities.push_back(Uzgorod);

    City Ivano_Frankivsk("Ivano-Frankivsk","48.9215000","24.7097200");
    cities.push_back(Ivano_Frankivsk);

    City Lutsk("Lutsk","50.7593200","25.3424400");
    cities.push_back(Lutsk);

}

void Weather::start()
{
     addCities();
     httplib::Client cli("http://api.weatherbit.io");
     string name_of_city;
     cout << "Enter city: " << endl;
     cin >> name_of_city;

     auto find_city = find_if(cities.begin(),cities.end(),[&name_of_city](const City &i)
     {

         return i.name == name_of_city;
     });

     httplib::Params params;
     params.emplace("lat", find_city->lat);
     params.emplace("lon", find_city->lon);

     auto res = cli.Get("/v2.0/current?key=61acd3060bd24ffa9d8c070d52e0f11b&lang=uk", params,{} );
     auto a = nlohmann::json::parse(res->body);

     cout << a["data"][0].dump(2) << endl;

}
