#pragma once

#include "CartItem.h"

class ShoppingCart {
private:
    CartItem cartItems[10];
    double total = 0.0;
    int itemCount = 0;

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
        total = 0;
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
