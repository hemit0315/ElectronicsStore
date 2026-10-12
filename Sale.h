#ifndef SALE_H
#define SALE_H

#include <iostream>
using namespace std;

class Sale
{
private:
    int saleId;
    int productId;
    int customerId;
    int quantity;
    double total;

public:
    Sale();
    Sale(int sid, int pid, int cid, int q, double t);
    ~Sale();

    void calculateTotal(double price);
    void display();

    int getSaleId();
    int getProductId();
    int getCustomerId();
    int getQuantity();
    double getTotal();
};

#endif