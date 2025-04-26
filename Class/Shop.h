#pragma once
#include "Product.h"
#include "Order.h"
#include "PaymentStrategies.h"
#include "Function.h"
#include "ProductCatalog.h"
#include "ShoppingCart.h"

class Shop {
private:
    Order*orders[10] = {};
    ShoppingCart& cart = ShoppingCart::getInstance();
    int orderCount = 0;

public:
    void viewCart() {
        printTitle ("Shopping Cart");
        cart.printCart();
        bool checkout = askYesOrNo("Do you want to checkout all the products? (y/n): ");
        if (checkout) {
            printTitle("Checkout");
            cart.printCart();
            cout << "Total: " << fixed << setprecision(2) << cart.getTotal() << endl << endl;

            int paymentMethod;
            cout << "Select payment method: " << endl;
            cout << "\t[1] Cash" << endl;
            cout << "\t[2] Credit / Debit Card" << endl;
            cout << "\t[3] Gcash" << endl;
            paymentMethod = getInputInt("Enter payment method: ", 1, 3);

            PaymentContext payment;
            switch (paymentMethod) {
                case 1:
                    payment.setPaymentMethod(new Cash());
                    break;
                case 2:
                    payment.setPaymentMethod(new CreditDebitCard());
                    break;
                case 3:
                    payment.setPaymentMethod(new Gcash());
                    break;
                default:
                    break;
            }

            orders[orderCount] = new Order(orderCount + 1, cart.getShoppingCartItems(), cart.getItemCount(),cart.getTotal(), payment.getPaymentMethod());

            payment.payOrder(orderCount + 1);
            orderCount++;
        }
    }

    void viewProducts () {
        bool addAnotherProduct;
        do {
            addAnotherProduct = false;
            printTitle("Products");
            cout << left << setw(12) << "Product ID"
             << setw(20) << "Name"
             << setw(10) << "Price"
             << endl;
            for (int i = 0; i < 10; i++) {
                catalog.products[i].printProduct();
            }
            cout << endl;

            bool isValid = false;
            do {
                try {
                    int productIndex = catalog.getIndex(getInput("Enter product ID: "));
                    int quantity = getInputInt("Enter quantity: ");

                    cart.addToCart(productIndex, quantity);
                    isValid = true;
                }catch (runtime_error &e) {
                    cout << "Error: " << e.what() << endl;
                }
            }while (!isValid);
            addAnotherProduct = askYesOrNo("Do you want to add another product? (y/n): ");

        }while (addAnotherProduct);


    }

    void printMenu() {
        printTitle("Welcome to Balion & Co.");
        cout << "\t [1] View Products" << endl;
        cout << "\t [2] View Shopping Cart" << endl;
        cout << "\t [3] View Orders" << endl;
        cout << "\t [4] Exit" << endl;
    }

    void viewOrders() {
        printTitle("Orders");

        try {
            if (orderCount <= 0) {
                throw std::runtime_error("No orders found.");
            }
            for (int i = 0; i < orderCount; i++) {
                orders[i]->printOrder();
                cout << endl;
            }
        }catch (runtime_error& e) {
            cout << "Error: " << e.what() << endl << endl;
        }
    }
};