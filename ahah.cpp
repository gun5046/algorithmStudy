#include <iostream>
#include <vector>
#include <stack>

int minEffortToPullBooks(std::vector<int>& order) {
    std::stack<int> bookStack;
    int effort = 0;

    for (int book : order) {
        if (!bookStack.empty() && bookStack.top() == book) {
            bookStack.pop(); // If the current book matches the top of the stack, remove it
        }
        else {
            bookStack.push(book); // Otherwise, add the book to the stack
            effort += bookStack.size() - 1; // Increment effort based on the height of the stack
        }
    }

    return effort;
}

int main() {
    std::vector<int> order = { 1, 2, 1, 3, 3, 2 };
    int result = minEffortToPullBooks(order);
    std::cout << "Minimum effort to pull out all books: " << result << std::endl;

    return 0;
}
