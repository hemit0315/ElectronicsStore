#include <iostream>
#include <fstream>
#include "Store.h"
#include <stdexcept>
using namespace std;

Store::Store()
{
    productCapacity = 100;
    customerCapacity = 100;
    warrantyCapacity = 100;
    saleCapacity = 100;

    productCount = 0;
    customerCount = 0;
    warrantyCount = 0;
    saleCount = 0;

    products = new Product*[productCapacity];
    customers = new Customer[customerCapacity];
    warranties = new Warranty[warrantyCapacity];
    sales = new Sale[saleCapacity];

    for (int i = 0; i < productCapacity; i++)
        products[i] = nullptr;

    cout << "Electronics Store System Started." << endl;
}

Store::~Store()
{
    for (int i = 0; i < productCount; i++)
        delete products[i];

    delete[] products;
    delete[] customers;
    delete[] warranties;
    delete[] sales;

    cout << "Store closed successfully." << endl;
}

void Store::menu()
{
    int choice;

    do
    {
        cout << "\n===== ELECTRONICS STORE MANAGEMENT =====" << endl;
        cout << "1. Add Product" << endl;
        cout << "2. Display Products" << endl;
        cout << "3. Search Product" << endl;
        cout << "4. Update Product" << endl;
        cout << "5. Delete Product" << endl;
        cout << "6. Add Customer" << endl;
        cout << "7. Display Customers" << endl;
        cout << "8. Make Sale" << endl;
        cout << "9. Show Report" << endl;
        cout << "10. Save Data" << endl;
        cout << "11. Load Data" << endl;
        cout << "12. Exit" << endl;
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice)
        {
        case 1:
            addProduct();
            break;
        case 2:
            displayProducts();
            break;
        case 3:
            searchProduct();
            break;
        case 4:
            updateProduct();
            break;
        case 5:
            deleteProduct();
            break;
        case 6:
            addCustomer();
            break;
        case 7:
            displayCustomers();
            break;
        case 8:
            makeSale();
            break;
        case 9:
            showReport();
            break;
        case 10:
            saveData();
            break;
        case 11:
            loadData();
            break;
        case 12:
            cout << "Exiting system..." << endl;
            break;
        default:
            cout << "Invalid choice. Try again." << endl;
        }

    } while (choice != 12);
}

void Store::addProduct()
{
    try
    {
        if (productCount >= productCapacity)
        {
            throw runtime_error("Product storage is full!");
        }

        int id, stock, type, warrantyMonths;
        string name, brand, applianceType;
        double price;

        cout << "Enter Product ID: ";
        cin >> id;

        for (int i = 0; i < productCount; i++)
        {
            if (products[i]->getProductId() == id)
            {
                throw runtime_error("Product ID already exists!");
            }
        }

        cout << "Enter Product Name: ";
        cin >> ws;
        getline(cin, name);

        cout << "Enter Brand: ";
        getline(cin, brand);

        cout << "Enter Price: ";
        cin >> price;

        cout << "Enter Stock: ";
        cin >> stock;

        if (price < 0 || stock < 0)
        {
            throw invalid_argument("Price and stock cannot be negative!");
        }

        cout << "Select Product Type (1. Electronic Product, 2. Appliance): ";
        cin >> type;

        if (type == 1)
        {
            cout << "Enter Warranty (months): ";
            cin >> warrantyMonths;

            if (warrantyMonths < 0)
            {
                throw invalid_argument("Warranty cannot be negative!");
            }

            products[productCount] = new ElectronicProduct(
                id, name, brand, price, stock, warrantyMonths);
        }
        else if (type == 2)
        {
            cout << "Enter Appliance Type: ";
            cin >> ws;
            getline(cin, applianceType);

            products[productCount] = new Appliance(
                id, name, brand, price, stock, applianceType);
        }
        else
        {
            throw invalid_argument("Invalid product type!");
        }

        productCount++;
        cout << "Product added successfully!" << endl;
    }
    catch (const exception& e)
    {
        cout << "Error: " << e.what() << endl;
    }
}


void Store::displayProducts()
{
    if (productCount == 0)
    {
        cout << "No products available." << endl;
        return;
    }

    for (int i = 0; i < productCount; i++)
    {
        cout << "\n--- Product " << i + 1 << " ---" << endl;
        products[i]->display();
    }
}

void Store::searchProduct()
{
    int id;

    cout << "Enter Product ID to search: ";
    cin >> id;

    for (int i = 0; i < productCount; i++)
    {
        if (products[i]->getProductId() == id)
        {
            products[i]->display();
            return;
        }
    }

    cout << "Product not found." << endl;
}

void Store::updateProduct()
{
    int id;
    double price;
    int stock;

    cout << "Enter Product ID to update: ";
    cin >> id;

    for (int i = 0; i < productCount; i++)
    {
        if (products[i]->getProductId() == id)
        {
            cout << "Enter new price: ";
            cin >> price;

            cout << "Enter new stock: ";
            cin >> stock;

            if (price < 0 || stock < 0)
            {
                cout << "Price and stock cannot be negative!" << endl;
                return;
            }

            products[i]->setPrice(price);
            products[i]->setStock(stock);

            cout << "Product updated successfully!" << endl;
            return;
        }
    }

    cout << "Product not found." << endl;
}

void Store::deleteProduct()
{
    int id;

    cout << "Enter Product ID to delete: ";
    cin >> id;

    for (int i = 0; i < productCount; i++)
    {
        if (products[i]->getProductId() == id)
        {
            delete products[i];

            for (int j = i; j < productCount - 1; j++)
                products[j] = products[j + 1];

            products[productCount - 1] = nullptr;
            productCount--;

            cout << "Product deleted successfully!" << endl;
            return;
        }
    }

    cout << "Product not found." << endl;
}
void Store::addCustomer()
{
    if (customerCount >= customerCapacity)
    {
        cout << "Customer storage is full!" << endl;
        return;
    }

    int id;
    string name, phone;

    cout << "Enter Customer ID: ";
    cin >> id;

    for (int i = 0; i < customerCount; i++)
    {
        if (customers[i].getCustomerId() == id)
        {
            cout << "Customer ID already exists!" << endl;
            return;
        }
    }

    cout << "Enter Customer Name: ";
    cin >> ws;
    getline(cin, name);

    cout << "Enter Phone Number: ";
    getline(cin, phone);

    customers[customerCount] = Customer(id, name, phone);
    customerCount++;

    cout << "Customer added successfully!" << endl;
}

void Store::displayCustomers()
{
    if (customerCount == 0)
    {
        cout << "No customers available." << endl;
        return;
    }

    for (int i = 0; i < customerCount; i++)
    {
        cout << "\n--- Customer " << i + 1 << " ---" << endl;
        customers[i].display();
    }
}

void Store::makeSale()
{
    if (saleCount >= saleCapacity)
    {
        cout << "Sale storage is full!" << endl;
        return;
    }

    int saleId, productId, customerId, quantity;

    cout << "Enter Sale ID: ";
    cin >> saleId;

    for (int i = 0; i < saleCount; i++)
    {
        if (sales[i].getSaleId() == saleId)
        {
            cout << "Sale ID already exists!" << endl;
            return;
        }
    }

    cout << "Enter Product ID: ";
    cin >> productId;

    int productIndex = -1;

    for (int i = 0; i < productCount; i++)
    {
        if (products[i]->getProductId() == productId)
        {
            productIndex = i;
            break;
        }
    }

    if (productIndex == -1)
    {
        cout << "Product not found!" << endl;
        return;
    }

    cout << "Enter Customer ID: ";
    cin >> customerId;

    bool customerFound = false;

    for (int i = 0; i < customerCount; i++)
    {
        if (customers[i].getCustomerId() == customerId)
        {
            customerFound = true;
            break;
        }
    }

    if (!customerFound)
    {
        cout << "Customer not found!" << endl;
        return;
    }

    cout << "Enter Quantity: ";
    cin >> quantity;

    if (quantity <= 0 || quantity > products[productIndex]->getStock())
    {
        cout << "Invalid quantity or insufficient stock!" << endl;
        return;
    }

    double price = products[productIndex]->getPrice();
    double total = price * quantity;

    sales[saleCount] = Sale(saleId, productId, customerId, quantity, total);
    saleCount++;

    products[productIndex]->setStock(
        products[productIndex]->getStock() - quantity);

    cout << "Sale completed successfully!" << endl;
    cout << "Total Amount: " << total << endl;
}

void Store::showReport()
{
    cout << "\n===== STORE REPORT =====" << endl;
    cout << "Total Products: " << productCount << endl;
    cout << "Total Customers: " << customerCount << endl;
    cout << "Total Sales: " << saleCount << endl;

    double revenue = 0;

    for (int i = 0; i < saleCount; i++)
    {
        revenue += sales[i].getTotal();
    }

    cout << "Total Revenue: " << revenue << endl;

    if (saleCount > 0)
    {
        cout << "\n===== SALES DETAILS =====" << endl;

        for (int i = 0; i < saleCount; i++)
        {
            sales[i].display();
            cout << endl;
        }
    }
}
void Store::saveData()
{
    ofstream productFile("products.txt");
    ofstream customerFile("customers.txt");

    if (!productFile || !customerFile)
    {
        cout << "Error opening files for saving!" << endl;
        return;
    }

    productFile << productCount << endl;

    for (int i = 0; i < productCount; i++)
    {
        productFile << products[i]->getProductId() << endl;
        productFile << products[i]->getName() << endl;
        productFile << products[i]->getBrand() << endl;
        productFile << products[i]->getPrice() << endl;
        productFile << products[i]->getStock() << endl;

        if (dynamic_cast<ElectronicProduct*>(products[i]) != nullptr)
        {
            ElectronicProduct* ep =
                dynamic_cast<ElectronicProduct*>(products[i]);

            productFile << 1 << endl;
            productFile << ep->getWarrantyMonths() << endl;
        }
        else
        {
            Appliance* ap = dynamic_cast<Appliance*>(products[i]);

            productFile << 2 << endl;
            productFile << ap->getType() << endl;
        }
    }

    customerFile << customerCount << endl;

    for (int i = 0; i < customerCount; i++)
    {
        customerFile << customers[i].getCustomerId() << endl;
        customerFile << customers[i].getName() << endl;
        customerFile << customers[i].getPhone() << endl;
    }

    productFile.close();
    customerFile.close();

    cout << "Data saved successfully!" << endl;
}

void Store::loadData()
{
    ifstream productFile("products.txt");
    ifstream customerFile("customers.txt");

    if (productFile)
    {
        int count;
        productFile >> count;
        productFile.ignore();

        for (int i = 0; i < productCount; i++)
        {
            delete products[i];
            products[i] = nullptr;
        }

        productCount = 0;

        for (int i = 0; i < count && i < productCapacity; i++)
        {
            int id, stock, type, warrantyMonths;
            string name, brand, applianceType;
            double price;

            productFile >> id;
            productFile.ignore();
            getline(productFile, name);
            getline(productFile, brand);
            productFile >> price >> stock >> type;
            productFile.ignore();

            if (type == 1)
            {
                productFile >> warrantyMonths;
                productFile.ignore();

                products[productCount++] = new ElectronicProduct(
                    id, name, brand, price, stock, warrantyMonths);
            }
            else
            {
                getline(productFile, applianceType);

                products[productCount++] = new Appliance(
                    id, name, brand, price, stock, applianceType);
            }
        }

        productFile.close();
    }

    if (customerFile)
    {
        int count;
        customerFile >> count;
        customerFile.ignore();

        customerCount = 0;

        for (int i = 0; i < count && i < customerCapacity; i++)
        {
            int id;
            string name, phone;

            customerFile >> id;
            customerFile.ignore();
            getline(customerFile, name);
            getline(customerFile, phone);

            customers[customerCount++] = Customer(id, name, phone);
        }

        customerFile.close();
    }

    cout << "Data loaded successfully." << endl;
}