#include "Warranty.h"

Warranty::Warranty()
{
    warrantyId = 0;
    productId = 0;
    months = 0;
    expiry = "";
}

Warranty::Warranty(int wid, int pid, int m, string e)
{
    warrantyId = wid;
    productId = pid;
    months = m;
    expiry = e;
}

Warranty::~Warranty()
{
    
}

void Warranty::display()
{
    cout << "Warranty ID: " << warrantyId << endl;
    cout << "Product ID: " << productId << endl;
    cout << "Warranty Months: " << months << endl;
    cout << "Expiry Date: " << expiry << endl;
}

bool Warranty::checkValidity()
{
    return months > 0;
}

int Warranty::getWarrantyId()
{
    return warrantyId;
}

int Warranty::getProductId()
{
    return productId;
}