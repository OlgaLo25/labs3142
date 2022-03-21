#ifndef CONTROLLER_H
#define CONTROLLER_H

#include <fstream>
#include "Process.h"
using namespace std;

class Controller
{

private:
    vector<Data> data;
    void printData(vector<Data> &data)
    {
        cout << "SKU"
             << "\t"
             << "Brand"
             << "\t"
             << "Category"
             << "\t"
             << "Year"
             << "\t"
             << "Price"
             << endl;

        for (int i = 0; i < data.size(); i++)
        {
            cout << data[i].sku << "\t" << data[i].brand << "\t" << data[i].category << "\t\t" << data[i].year << "\t" << data[i].price << endl;
        }
    }

    void createData(
        ifstream &textToRead,
        vector<Data> &data)
    {
        string line;
        bool skipFirstLine = true;
        while (getline(textToRead, line))
        {
            if (skipFirstLine)
            {
                skipFirstLine = false;
                continue;
            }
            vector<string> lineSplit = split(line, ',');
            int sku;
            stringToSomething(lineSplit.at(0), sku);

            string brand = lineSplit.at(1);

            char category;
            stringToSomething(lineSplit.at(2), category);
            int year;
            stringToSomething(lineSplit.at(3), year);
            float price;
            stringToSomething(lineSplit.at(4), price);

            Data line(sku, brand, category, year, price);
            data.push_back(line);
        }
        printData(data);
        
    }

    void readFile()
    {
        cout << fixed;
        cout.precision(1); // for floating numbers (Example: 1.0)
        

        ifstream textToRead;
        textToRead.open("data.csv");
        if (!textToRead.fail())
        {
            createData(
                textToRead,
                data);
        }
        textToRead.close();
        
    }

    void processFile(){
        Process pr;
        pr.averagePriceBrand(data);
        pr.averagePriceCategory(data);
        pr.skuForYears(data);
    }

public:
    Controller()
    {
        readFile();
        processFile();
    }
};
#endif