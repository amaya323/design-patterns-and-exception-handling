#include "Class/Shop.h"

int main() {
    ShoppingCart &cart = cart.getInstance();
    Shop shop;
    int choice;

    do {
        shop.printMenu();
        choice = getInputInt("Enter your choice: ", 1, 4);

        switch (choice) {
            case 1:
                shop.viewProducts();
            break;
            case 2:
                shop.viewCart();
            break;
            case 3:
                shop.viewOrders();
            break;
            case 4:
                return 0;
            default:
                break;
        }
        cout << endl;
        system("pause");

    }while (choice != 4);


}
