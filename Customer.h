#ifndef CUSTOMER_H
#define CUSTOMER_H

#include <iostream>
#include <string>
using namespace std;

class Customer
{
private:
    int customerId;
    string name;
    string phone;

public:
    Customer();
    Customer(int id, string n, string p);
    ~Customer();

    void display();

    int getCustomerId();
    string getName();
    string getPhone();
};

#endif