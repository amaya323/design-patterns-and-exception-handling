#pragma once
#include "Product.h"

class ProductCatalog {
    private:
    // lists of products
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
    public:

    Product getProduct(int index) {
        return products[index];
    }

    int getIndex(string productId) {
        //convert to uppercase all letter
        for (char &c: productId) {
            if (isalpha(c)) {
                c = toupper(c);
            }
        }
        // iterate through the product catalog and check if the product exists
        for (int i = 0; i < 10; i++) {
            if (productId == products[i].getId()) {
                return i; // return the index of the product if found
            }
        }
        throw runtime_error("Product not found!"); // throw error if not found
    }

};

// global product
ProductCatalog catalog;



