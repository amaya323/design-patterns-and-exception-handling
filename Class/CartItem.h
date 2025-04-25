#pragma once
#include "ProductCatalog.h"

class CartItem {
private:
    int productId;
    int quantity;

public:

    void setId(int id) {
        this->productId = id;
    }

    void setQuantity(const int& newQuantity) {
        this->quantity = newQuantity;
    }

    int getId() const{
        return productId;
    }

    int getQuantity() const{
        return quantity;
    }

    void printItem(){
        cout << left << setw(12) << catalog.products[productId].getId()
             << setw(20) << catalog.products[productId].getName()
             << setw(10) << fixed << setprecision(2) << catalog.products[productId].getPrice()
             << setw(10) << getQuantity();
    }
};

