#pragma once

#include <iostream>
#include <iomanip>
using namespace std;

class Product {
private:
    int id;
    string name;
    double price;

public:

    Product(int id, string name, double price) {
        this->id = id;
        this->name = name;
        this->price = price;
    }
    int getId() {
        return id;
    }

    string getName() {
        return name;
    }

    void printProduct(){
        cout << left << setw(12) << id
             << setw(20) << name
             << setw(10) << fixed << setprecision(2) << price
             << endl;
    }

    double getPrice() {
        return price;
    }
};

