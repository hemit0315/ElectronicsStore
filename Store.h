#ifndef STORE_H
#define STORE_H

#include "Product.h"
#include "ElectronicProduct.h"
#include "Appliance.h"
#include "Customer.h"
#include "Warranty.h"
#include "Sale.h"

class Store
{
private:
    Product** products;
    Customer* customers;
    Warranty* warranties;
    Sale* sales;

    int productCount;
    int customerCount;
    int warrantyCount;
    int saleCount;

    int productCapacity;
    int customerCapacity;
    int warrantyCapacity;
    int saleCapacity;

public:
    Store();
    ~Store();

    void menu();
    void addProduct();
    void displayProducts();
    void searchProduct();
    void updateProduct();
    void deleteProduct();
    void addCustomer();
    void displayCustomers();
    void makeSale();
    void showReport();

    void saveData();
    void loadData();
};

#endif