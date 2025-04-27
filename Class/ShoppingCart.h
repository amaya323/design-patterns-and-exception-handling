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
    CartItem* getShoppingCartItems() {
        return cartItems;
    }

    int getItemCount() const {
        return itemCount;
    }

    void clearCart () {
        for (int i = 0; i < itemCount; i++) {
            cartItems[i] = CartItem();
        }
        total = 0.0;
        itemCount = 0;
    }

    static ShoppingCart& getInstance() {
        return instance;
    }

    void addToCart(int productIndex, int quantity) {
        bool isFound = false;
        for (int i = 0; i < itemCount; i++) {
            if (cartItems[i].getIndex() == productIndex) {
                cartItems[i].setQuantity(cartItems[i].getQuantity() + quantity);
                isFound = true;
            }
        }

        if (!isFound) {
            cartItems[itemCount].setIndex(productIndex);
            cartItems[itemCount].setQuantity(quantity);
            itemCount++;
        }
    }

    void calculateTotal() {
        for (int i = 0; i < itemCount; i++) {
            total += catalog.getProduct(cartItems[i].getIndex()).getPrice() * cartItems[i].getQuantity();
        }
    }

    double getTotal() {
        calculateTotal();
        return total;
    }

    void printCart() {
        cout << left << setw(12) << "Product ID"
             << setw(20) << "Name"
             << setw(10) << "Price"
             << setw(10) << "Quantity"
             << endl;

        for (int i = 0; i < itemCount; i++) {
            cartItems[i].printItem();
        }
    }
};

ShoppingCart ShoppingCart::instance;