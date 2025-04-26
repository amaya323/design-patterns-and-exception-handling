#pragma once
#include "ProductCatalog.h"

class CartItem {
private:
    int productIndex;
    int quantity;

public:

    void setIndex(int index) {
        this->productIndex = index;
    }

    void setQuantity(const int& newQuantity) {
        this->quantity = newQuantity;
    }

    int getIndex() const{
        return productIndex;
    }

    int getQuantity() const{
        return quantity;
    }

    void printItem(){
        cout << left << setw(12) << catalog.products[productIndex].getId()
             << setw(20) << catalog.products[productIndex].getName()
             << setw(10) << fixed << setprecision(2) << catalog.products[productIndex].getPrice()
             << setw(10) << getQuantity() << endl;
    }
};

