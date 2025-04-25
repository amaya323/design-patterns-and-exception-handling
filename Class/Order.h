#pragma once


#include <iostream>
#include "CartItem.h"
using namespace std;

class Order {
private:
    CartItem cartItems[10];
    double total;
    string paymentMethod;
    int orderId;
public:

    Order(int orderId, CartItem items[], double total, string paymentMethod){
        this->orderId = orderId;
        this->cartItems[orderId-1] = order;
        this->total = total;
        this->paymentMethod = paymentMethod;


    }

    void print() {
        cout << "Order ID: " << orderId << endl;
        cout << fixed << setprecision(2) << total;
        cout << "Payment Method: " << paymentMethod << endl;
        cout << "Order Details: ";

        cout << left << setw(12) << "Product ID"
             << setw(20) << "Name"
             << setw(10) << "Price"
             << setw(10) << "Quantity"
             << endl;

        for (CartItem item: cartItems) {
            item.printItem();
            cout << endl;
        }

    }
    ~Order() {

    }
};

