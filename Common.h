#ifndef COMMON_H
#define COMMON_H

#include <vector>
#include <sstream>

using namespace std;
//struct Data
struct Data
{
    int sku;
    string brand;
    char category;
    int year;
    float price;
    Data(int sku, string brand, char category, int year, float price)
    {
        this->sku = sku;
        this->brand = brand;
        this->category = category;
        this->year = year;
        this->price = price;
    }
};

//Common functions
vector<string> split(string s, char delim)
{
    vector<string> result;
    stringstream streamName(s);
    string item;

    while (getline(streamName, item, delim))
    {
        result.push_back(item);
    }

    return result;
}

template <typename Text, typename TypeToConvert>
void stringToSomething(Text stringText, TypeToConvert &typeConvert)
{
    stringstream syear(stringText);
    syear >> typeConvert;
}

#endif
