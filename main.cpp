#include <iostream>
#include <string>
#include <vector>
#include <limits>

struct Expense {
    std::string description;
    double amount;
    std::string category;
};

void addExpense(std::vector<Expense>& expenses) {
    Expense e;
    std::cout << "Description: ";
    std::getline(std::cin, e.description);
    std::cout << "Amount (EUR): ";
    std::cin >> e.amount;
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    std::cout << "Category: ";
    std::getline(std::cin, e.category);
    expenses.push_back(e);
}

void listExpenses(const std::vector<Expense>& expenses) {
    double total = 0;
    for (const auto& e : expenses) {
        std::cout << e.description << " | " << e.amount
                  << " EUR | " << e.category << "\n";
        total += e.amount;
    }
    std::cout << "Total: " << total << " EUR\n";
}

int main() {
    std::vector<Expense> expenses;
    int choice = 0;
    while (choice != 3) {
        std::cout << "\n1) Add  2) List  3) Quit\n> ";
        std::cin >> choice;
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        if (choice == 1) addExpense(expenses);
        else if (choice == 2) listExpenses(expenses);
    }
    return 0;
}
