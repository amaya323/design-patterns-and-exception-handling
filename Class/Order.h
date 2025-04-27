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
    int cartItemCount;
public:

    Order(const int orderId, const CartItem* items, const int itemCount, const double total, const string &paymentMethod){
        this->orderId = orderId;
        this->total = total;
        this->paymentMethod = paymentMethod;
        this->cartItemCount = itemCount;

        for (int i = 0; i < cartItemCount; i++) {
            cartItems[i] = items[i];
        }
    }

    void printOrder() {
        cout << "Order ID: " << orderId << endl;
        cout << "Total: " << fixed << setprecision(2) << total << endl;
        cout << "Payment Method: " << paymentMethod << endl;
        cout << "Order Details: " << endl;

        cout << left << setw(12) << "Product ID"
             << setw(20) << "Name"
             << setw(10) << "Price"
             << setw(10) << "Quantity"
             << endl;

        for (int i = 0; i < cartItemCount; i++) {  // Only print actual items
            cartItems[i].printItem();
        }
    }
};

