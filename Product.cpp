#include "Product.h"

Product::Product()
{
    productId = 0;
    name = "";
    brand = "";
    price = 0;
    stock = 0;
}

Product::Product(int id, string n, string b, double p, int s)
{
    productId = id;
    name = n;
    brand = b;
    price = p;
    stock = s;
}

Product::~Product()
{
    cout << "Product object destroyed." << endl;
}

void Product::display()
{
    cout << "Product ID: " << productId << endl;
    cout << "Name: " << name << endl;
    cout << "Brand: " << brand << endl;
    cout << "Price: " << price << endl;
    cout << "Stock: " << stock << endl;
}

void Product::updateStock(int quantity)
{
    stock = stock + quantity;
}

int Product::getProductId()
{
    return productId;
}

string Product::getName()
{
    return name;
}

string Product::getBrand()
{
    return brand;
}

double Product::getPrice()
{
    return price;
}

int Product::getStock()
{
    return stock;
}
void Product::setPrice(double p)
{
    price = p;
}

void Product::setStock(int s)
{
    stock = s;
}