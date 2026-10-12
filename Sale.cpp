#include "Sale.h"

Sale::Sale()
{
    saleId = 0;
    productId = 0;
    customerId = 0;
    quantity = 0;
    total = 0;
}

Sale::Sale(int sid, int pid, int cid, int q, double t)
{
    saleId = sid;
    productId = pid;
    customerId = cid;
    quantity = q;
    total = t;
}

Sale::~Sale()
{
    
}

void Sale::calculateTotal(double price)
{
    total = price * quantity;
}

void Sale::display()
{
    cout << "Sale ID: " << saleId << endl;
    cout << "Product ID: " << productId << endl;
    cout << "Customer ID: " << customerId << endl;
    cout << "Quantity: " << quantity << endl;
    cout << "Total: " << total << endl;
}

int Sale::getSaleId()
{
    return saleId;
}

int Sale::getProductId()
{
    return productId;
}

int Sale::getCustomerId()
{
    return customerId;
}

int Sale::getQuantity()
{
    return quantity;
}

double Sale::getTotal()
{
    return total;
}