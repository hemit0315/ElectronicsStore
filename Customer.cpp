#include "Customer.h"

Customer::Customer()
{
    customerId = 0;
    name = "";
    phone = "";
}

Customer::Customer(int id, string n, string p)
{
    customerId = id;
    name = n;
    phone = p;
}

Customer::~Customer()
{
    
}

void Customer::display()
{
    cout << "Customer ID: " << customerId << endl;
    cout << "Name: " << name << endl;
    cout << "Phone: " << phone << endl;
}

int Customer::getCustomerId()
{
    return customerId;
}

string Customer::getName()
{
    return name;
}

string Customer::getPhone()
{
    return phone;
}