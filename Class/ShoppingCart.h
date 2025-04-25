#pragma once

#include "CartItem.h"


class ShoppingCart {
private:
    static ShoppingCart instance;
    CartItem cartItems[10];
    double total;
    int itemCount;
    ShoppingCart(): itemCount(0){}

public:
    static ShoppingCart& getInstance() {
        return instance;
    }

    void addToCart(int productId, int quantity) {
        for (int i = 0; i < itemCount; i++) {
            if (cartItems[i].getId() == productId) {
                cartItems[i].setQuantity(cartItems[i].getQuantity() + quantity);
            }
        }

        cartItems[itemCount-1].setId(productId);
        cartItems[itemCount-1].setQuantity(quantity);
        itemCount++;
    }

    void calculateTotal() {
        for (int i = 0; i < itemCount; i++) {
            total += catalog.products[cartItems[i].getId()].getPrice() * cartItems[i].getQuantity();
        }
    }

    double getTotal() {
        return total;
    }

    void printCart() {
        cout << left << setw(12) << "Product ID"
             << setw(20) << "Name"
             << setw(10) << "Price"
             << setw(10) << "Quantity"
             << endl;

        for (int i = 0; i < itemCount; i++) {
            cartItems[i].setQuantity(cartItems[i].getQuantity() + quantity);

        }

        calculateTotal();
    }
};

ShoppingCart ShoppingCart::instance;