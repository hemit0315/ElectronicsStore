#ifndef ELECTRONICPRODUCT_H
#define ELECTRONICPRODUCT_H

#include "Product.h"

class ElectronicProduct : public Product
{
private:
    int warrantyMonths;

public:
    ElectronicProduct();
    ElectronicProduct(int id, string n, string b, double p, int s, int w);
    int getWarrantyMonths();

    void display() override;
};

#endif