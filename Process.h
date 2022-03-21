#ifndef PROCESS_H
#define PROCESS_H
#include "Common.h"
using namespace std;


class Process
{

private:

    template <typename Key, typename Value>
    void printMap(map<Key, Value> map)
    {
        typename map<Key, Value>::iterator elementOfMap;
        for (elementOfMap = map.begin(); elementOfMap != map.end(); elementOfMap++)
        {
            cout << elementOfMap->first << " average is " << elementOfMap->second << endl;
        }
    }

    void printSkuYears(map<int, vector<int>> &dataMap)
    {
        map<int, vector<int>>::iterator elementOfAverageMap;
        for (elementOfAverageMap = dataMap.begin(); elementOfAverageMap != dataMap.end(); elementOfAverageMap++)
        {
            cout << "Year " << elementOfAverageMap->first << " (" << elementOfAverageMap->second.size() << "): ";
            for (int i = 0; i < elementOfAverageMap->second.size(); i++)
            {
                cout << elementOfAverageMap->second[i] << " ";
            }
            cout << endl;
        }
    }

    template <typename Key, typename Value>
    void writeMap(map<Key, Value> &averageMap)
    {
        ofstream out("output.txt", ios::app);
        out << fixed;
        out.precision(1);
        if (out.is_open())
        {
            typename map<Key, Value>::iterator elementOfAverageMap;
            for (elementOfAverageMap = averageMap.begin(); elementOfAverageMap != averageMap.end(); elementOfAverageMap++)
            {
                out << elementOfAverageMap->first << " average is " << elementOfAverageMap->second << endl;
            }

            out.close();
        }
    }

    void writeSkuYears(map<int, vector<int>> &data)
    {
        ofstream out("output.txt", ios::app);
        if (out.is_open())
        {
            map<int, vector<int>>::iterator elementOfAverageMap;
            for (elementOfAverageMap = data.begin(); elementOfAverageMap != data.end(); elementOfAverageMap++)
            {
                out << "Year " << elementOfAverageMap->first << " (" << elementOfAverageMap->second.size() << "): ";
                for (int i = 0; i < elementOfAverageMap->second.size(); i++)
                {
                    out << elementOfAverageMap->second[i] << " ";
                }
                out << endl;
            }

            out.close();
        }
    }

    map<string, int> perRowBrand(vector<Data> &data)
    {
        map<string, int> brandMap;
        for (int i = 0; i < data.size(); i++)
        {
            if (brandMap.find(data[i].brand) != brandMap.end())
            {
                brandMap.find(data[i].brand)->second = brandMap.at(data[i].brand) + 1;
            }
            else
            {
                brandMap.insert(make_pair(data[i].brand, 1));
            }
        }
        return brandMap;
    }

    map<char, int> perRowCategory(vector<Data> &data)
    {
        map<char, int> categoryMap;
        for (int i = 0; i < data.size(); i++)
        {
            if (categoryMap.find(data[i].category) != categoryMap.end())
            {
                categoryMap.find(data[i].category)->second = categoryMap.at(data[i].category) + 1;
            }
            else
            {
                categoryMap.insert(make_pair(data[i].category, 1));
            }
        }
        return categoryMap;
    }

public:
    void skuForYears(vector<Data> &data)
    {
        map<int, vector<int>> dataMap;

        for (int i = 0; i < data.size(); i++)
        {
            vector<int> someVector;
            if (dataMap.find(data[i].year) != dataMap.end())
            {
                someVector = dataMap.find(data[i].year)->second;
                someVector.push_back(data[i].sku);
                dataMap.find(data[i].year)->second = someVector;
            }
            else
            {
                someVector.push_back(data[i].sku);
                dataMap.insert(make_pair(data[i].year, someVector));
            }
        }

        printSkuYears(dataMap);
        writeSkuYears(dataMap);
    }

    void averagePriceBrand(vector<Data> &data)
    {
        map<string, int> brandMap = perRowBrand(data);
        map<string, double> averageMap;

        map<string, int>::iterator elementOfMap;                                              // iterator points to a pair
        for (elementOfMap = brandMap.begin(); elementOfMap != brandMap.end(); elementOfMap++) // iterator searches for the same brands
        {
            double sum = 0;
            for (int i = 0; i < data.size(); i++)
            {
                if (elementOfMap->first == data[i].brand) // if the kay eaqual to "i" brand, sum the prices
                // first is the key of the pair (ABC)
                {
                    sum += data[i].price;
                }
            }
            double averageSum = sum / elementOfMap->second;
            string nameOfCategoryOrBrand = elementOfMap->first;
            averageMap.insert(make_pair(nameOfCategoryOrBrand, averageSum));
        }

        printMap(averageMap);
        writeMap(averageMap);
    }

    void averagePriceCategory(vector<Data> &data)
    {
        map<char, int> categoryMap = perRowCategory(data);
        map<char, double> averageMap;

        map<char, int>::iterator elementOfMap;                                                      // iterator points to a pair
        for (elementOfMap = categoryMap.begin(); elementOfMap != categoryMap.end(); elementOfMap++) // iterator searches for the same Categorys
        {
            double sum = 0;
            for (int i = 0; i < data.size(); i++)
            {
                if (elementOfMap->first == data[i].category) // if the kay eaqual to "i" Category, sum the prices
                // first is the key of the pair (ABC)
                {
                    sum += data[i].price;
                }
            }
            double averageSum = sum / elementOfMap->second;
            char nameOfCategoryOrCategory = elementOfMap->first;
            averageMap.insert(make_pair(nameOfCategoryOrCategory, averageSum));
        }

        printMap(averageMap);
        writeMap(averageMap);
    }
};

#endif