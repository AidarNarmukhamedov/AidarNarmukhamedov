#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

struct Order {
    string name;
    int quantity;
    double price;
};

bool compareByName(const Order& a, const Order& b) {
    return a.name < b.name;
}

int main() {
    int numOrders;
    cout << "Введите количество заказанных товаров: ";
    cin >> numOrders;

    vector<Order> orders;

    for (int i = 0; i < numOrders; ++i) {
        Order order;
        cout << "Введите название товара " << i + 1 << ": ";
        cin.ignore();
        getline(std::cin, order.name);
        cout << "Введите количество единиц товара " << i + 1 << ": ";
        cin >> order.quantity;
        cout << "Введите цену за единицу товара " << i + 1 << ": ";
        cin >> order.price;

        double total = order.quantity * order.price;
        cout << "Общая стоимость заказа: " << total << std::endl;

        orders.push_back(order);
    }

    double totalCost = 0;
    sort(orders.begin(), orders.end(), compareByName);

    cout << "Общая стоимость всех заказов:\n";

    for (const Order& order : orders) {
        double orderTotal = order.quantity * order.price;
        totalCost += orderTotal;
        cout << order.name << " - " << orderTotal << std::endl;
    }

    cout << "Общая стоимость всех заказов: " << totalCost << std::endl;

    return 0;
}
