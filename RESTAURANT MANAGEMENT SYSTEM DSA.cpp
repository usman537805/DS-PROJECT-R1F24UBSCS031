#include <iostream>
using namespace std;

class Restaurant
{
private:
    static const int SIZE = 100;

    // Queue for pending orders
    int orderID[SIZE];
    string customerName[SIZE];
    string foodItem[SIZE];
    int quantity[SIZE];
    float billAmount[SIZE];

    int front, rear;

    // Stack for completed orders
    int completedOrderID[SIZE];
    string completedCustomerName[SIZE];
    string completedFoodItem[SIZE];
    int completedQuantity[SIZE];
    float completedBillAmount[SIZE];

    int top;

public:
    Restaurant()
    {
        front = -1;
        rear = -1;
        top = -1;
    }

    // Add Order (Queue)
    void addOrder()
    {
        if (rear == SIZE - 1)
        {
            cout << "Queue is Full!\n";
            return;
        }

        if (front == -1)
            front = 0;

        rear++;

        cout << "\nEnter Order ID: ";
        cin >> orderID[rear];

        cin.ignore();

        cout << "Enter Customer Name: ";
        getline(cin, customerName[rear]);

        cout << "Enter Food Item: ";
        getline(cin, foodItem[rear]);

        cout << "Enter Quantity: ";
        cin >> quantity[rear];

        cout << "Enter Bill Amount: ";
        cin >> billAmount[rear];

        cout << "Order Added Successfully!\n";
    }

    // Display Pending Orders
    void displayOrders()
    {
        if (front == -1 || front > rear)
        {
            cout << "\nNo Pending Orders!\n";
            return;
        }

        cout << "\n----- Pending Orders -----\n";

        for (int i = front; i <= rear; i++)
        {
            cout << "\nOrder ID: " << orderID[i];
            cout << "\nCustomer Name: " << customerName[i];
            cout << "\nFood Item: " << foodItem[i];
            cout << "\nQuantity: " << quantity[i];
            cout << "\nBill Amount: " << billAmount[i];
            cout << "\n----------------------\n";
        }
    }

    // Search Order
    void searchOrder()
    {
        if (front == -1 || front > rear)
        {
            cout << "\nNo Orders Available!\n";
            return;
        }

        int id;
        cout << "Enter Order ID to Search: ";
        cin >> id;

        bool found = false;

        for (int i = front; i <= rear; i++)
        {
            if (orderID[i] == id)
            {
                cout << "\nOrder Found!\n";
                cout << "Customer Name: " << customerName[i] << endl;
                cout << "Food Item: " << foodItem[i] << endl;
                cout << "Quantity: " << quantity[i] << endl;
                cout << "Bill Amount: " << billAmount[i] << endl;

                found = true;
                break;
            }
        }

        if (!found)
            cout << "Order Not Found!\n";
    }

    // Serve Order (Queue -> Stack)
    void serveOrder()
    {
        if (front == -1 || front > rear)
        {
            cout << "\nNo Orders to Serve!\n";
            return;
        }

        // ? FIX: stack overflow check
        if (top == SIZE - 1)
        {
            cout << "Completed Orders Stack Full!\n";
            return;
        }

        top++;

        completedOrderID[top] = orderID[front];
        completedCustomerName[top] = customerName[front];
        completedFoodItem[top] = foodItem[front];
        completedQuantity[top] = quantity[front];
        completedBillAmount[top] = billAmount[front];

        cout << "\nOrder Served Successfully!\n";
        cout << "Served Order ID: " << orderID[front] << endl;

        front++;

        if (front > rear)
        {
            front = rear = -1;
        }
    }

    // Show Completed Orders
    void showCompletedOrders()
    {
        if (top == -1)
        {
            cout << "\nNo Completed Orders!\n";
            return;
        }

        cout << "\n----- Completed Orders History -----\n";

        for (int i = top; i >= 0; i--)
        {
            cout << "\nOrder ID: " << completedOrderID[i];
            cout << "\nCustomer Name: " << completedCustomerName[i];
            cout << "\nFood Item: " << completedFoodItem[i];
            cout << "\nQuantity: " << completedQuantity[i];
            cout << "\nBill Amount: " << completedBillAmount[i];
            cout << "\n----------------------\n";
        }
    }

    // Count Orders
    void countOrders()
    {
        if (front == -1 || front > rear)
            cout << "\nTotal Pending Orders: 0\n";
        else
            cout << "\nTotal Pending Orders: " << (rear - front + 1) << endl;
    }
};

int main()
{
    Restaurant r;
    int choice;

    do
    {
        cout << "\n========== Restaurant Management System ==========\n";
        cout << "1. Add Order\n";
        cout << "2. Display Orders\n";
        cout << "3. Search Order\n";
        cout << "4. Serve/Delete Order\n";
        cout << "5. Show Completed Orders History\n";
        cout << "6. Count Total Orders\n";
        cout << "7. Exit\n";

        cout << "\nEnter Your Choice: ";
        cin >> choice;

        switch (choice)
        {
        case 1:
            r.addOrder();
            break;

        case 2:
            r.displayOrders();
            break;

        case 3:
            r.searchOrder();
            break;

        case 4:
            r.serveOrder();
            break;

        case 5:
            r.showCompletedOrders();
            break;

        case 6:
            r.countOrders();
            break;

        case 7:
            cout << "\nProgram Ended Successfully.\n";
            break;

        default:
            cout << "\nInvalid Choice!\n";
        }

    } while (choice != 7);

    return 0;
}
