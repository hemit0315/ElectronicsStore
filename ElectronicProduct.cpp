#include "ElectronicProduct.h"

ElectronicProduct::ElectronicProduct()
{
    warrantyMonths = 0;
}

ElectronicProduct::ElectronicProduct(int id, string n, string b,
                                     double p, int s, int w)
    : Product(id, n, b, p, s)
{
    warrantyMonths = w;
}

void ElectronicProduct::display()
{
    Product::display();
    cout << "Warranty: " << warrantyMonths << " months" << endl;
}
int ElectronicProduct::getWarrantyMonths()
{
    return warrantyMonths;
}