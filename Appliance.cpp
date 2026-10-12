#include "Appliance.h"

Appliance::Appliance()
{
    type = "";
}

Appliance::Appliance(int id, string n, string b,
                     double p, int s, string t)
    : Product(id, n, b, p, s)
{
    type = t;
}

void Appliance::display()
{
    Product::display();
    cout << "Type: " << type << endl;
}
string Appliance::getType()
{
    return type;
}