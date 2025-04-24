#pragma once
#include "Product.h"

class CartItem {
private:
    Product product;
    int quantity;

public:

    CartItem() : product(Product()), quantity(0) {}
    void setProduct(const Product& newProduct) {
        this->product = newProduct;
    }

    void setQuantity(const int& newQuantity) {
        this->quantity = newQuantity;
    }

    Product getProduct() const{
        return product;
    }

    int getQuantity() const{
        return quantity;
    }
};

