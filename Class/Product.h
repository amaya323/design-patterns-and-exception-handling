#pragma once
#include <iostream>
using namespace std;

class Product {
private:
    int id;
    string name;
    double price;

public:
    Product() : id(0), name(""), price(0.0) {}

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

    double getPrice() {
        return price;
    }
};