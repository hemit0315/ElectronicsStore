#ifndef WARRANTY_H
#define WARRANTY_H

#include <iostream>
#include <string>
using namespace std;

class Warranty
{
private:
    int warrantyId;
    int productId;
    int months;
    string expiry;

public:
    Warranty();
    Warranty(int wid, int pid, int m, string e);
    ~Warranty();

    void display();
    bool checkValidity();

    int getWarrantyId();
    int getProductId();
};

#endif