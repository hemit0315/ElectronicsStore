#ifndef APPLIANCE_H
#define APPLIANCE_H

#include "Product.h"

class Appliance : public Product
{
private:
    string type;

public:
    Appliance();
    Appliance(int id, string n, string b, double p, int s, string t);

    void display() override;
    string getType();
};

#endif