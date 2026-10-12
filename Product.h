#ifndef PRODUCT_H
#define PRODUCT_H

#include <iostream>
#include <string>

using namespace std;

class Product
{
private:
    int productId;
    string name;
    string brand;
    double price;
    int stock;

public:
    Product();
    Product(int id, string n, string b, double p, int s);
    virtual ~Product();

    virtual void display();
    void updateStock(int quantity);

    int getProductId();
    string getName();
    string getBrand();
    double getPrice();
    int getStock();

    void setPrice(double p);
    void setStock(int s);
};

#endif