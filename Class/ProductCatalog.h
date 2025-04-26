#pragma once
#include "Product.h"

class ProductCatalog {
public:
    Product products [10] = {
            {"A1", "Laptop", 999.99},
            {"B2", "Mouse", 19.99},
            {"C3", "Keyboard", 49.99},
            {"D4", "Monitor", 199.99},
            {"E5", "Headphones", 79.99},
            {"F6", "Webcam", 59.99},
            {"G7", "USB Drive", 12.99},
            {"H8", "External SSD", 129.99},
            {"I9", "Wireless Router", 89.99},
            {"J10", "Bluetooth Speaker", 39.99}
    };

    int getIndex(string productId) {
        for (int i = 0; i < 10; i++) {
            if (productId == products[i].getId()) {
                return i;
            }
        }
        throw runtime_error("Product not found!");
    }

};

ProductCatalog catalog;



