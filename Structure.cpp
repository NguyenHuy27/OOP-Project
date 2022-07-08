#include "Header.h"

//Construct node
struct node
{
    int receipt_number, x;

    string customerName, date;

    int quantity[10], menu2[10];

    int amount[10], total;

    string type[10] = {"8GB", "4GB", "4GB", "8GB", "8GB", "8GB", "4GB", "8GB", "4GB", "8GB"};

    string specifications[10] = {"Intel Core i5(10th Gen)", "Intel Core i3 (10th Gen)", "Intel Core i5(8th Gen)", "Intel Core i5 (10th Gen)", "macOS Catalina M1", "Intel Core i5(10th Gen)", "Intel Core i5(5th Gen)", "Intel Core i3(7th Gen)", "Intel Core i5(10th Gen)", "Intel Core i7(10th Gen)"};

    string computerName[10] = {"Dell Inspiron 15 5590", "Asus X412FA-EK361T", "Lenovo Ideapad 330", "Acer Nitro 5", "Apple MacBook Air", "HP 15s-du1034tu", "Acer Aspire ES1-571", "HP 15-DA0070TX ", "Lenovo Ideapad Gaming", "HP Pavilion 15-ac028TX"};

    int computer[10] = {18900000, 10690000, 9990000, 22990000, 24990000, 10000000, 14999000, 15290000, 20390000, 17290000};

    
    node *next;

} *q, *temp; // Pointer declaration

node *start_ptr = NULL;

