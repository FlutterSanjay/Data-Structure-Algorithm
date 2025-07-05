#include <iostream>
#include <vector>
using namespace std;

class Item {
public:
    int id;
    int weight;
    int profit;

    Item(int itemId, int w, int p) : id(itemId), weight(w), profit(p) {}
};

class Knapsack {
public:
    Knapsack(int capacity) : capacity(capacity) {}

    int kp_rec(vector<Item>& items, int n, int capacity) {
        // Base Case
        if (n == 0 || capacity == 0) {
            return 0;
        }

        // If weight of the nth item is more than capacity, skip it
        if (items[n - 1].weight > capacity) {
            return kp_rec(items, n - 1, capacity);
        }

        // Return the maximum of two cases:
        // 1. nth item included
        // 2. not included
        else {
            int included = items[n - 1].profit + kp_rec(items, n - 1, capacity - items[n - 1].weight);
            int excluded = kp_rec(items, n - 1, capacity);
            return max(included, excluded);
        }
    }

    int kp_mem(vector<Item>& items, int n, int capacity, vector<vector<int>>& memo) {
        // Base Case
        if (n == 0 || capacity == 0) {
            return 0;
        }

        // Check if result is already computed
        if (memo[n][capacity] != -1) {
            return memo[n][capacity];
        }

        // If weight of the nth item is more than capacity, skip it
        if (items[n - 1].weight > capacity) {
            memo[n][capacity] = kp_mem(items, n - 1, capacity, memo);
        } else {
            // Calculate the maximum value we can get by including or excluding the nth item
            int included = items[n - 1].profit + kp_mem(items, n - 1, capacity - items[n - 1].weight, memo);
            int excluded = kp_mem(items, n - 1, capacity, memo);
            memo[n][capacity] = max(included, excluded);
        }

        return memo[n][capacity];
    }

private:
    int capacity;
};

int main() {
    vector<Item> items = {
        Item(1, 2, 3),
        Item(2, 3, 4),
        Item(3, 4, 5),
        Item(4, 5, 6)
    };

    int capacity = 5;
    Knapsack knapsack(capacity);

    int n = items.size();
    cout << "Maximum profit (Recursive): " << knapsack.kp_rec(items, n, capacity) << endl;

    // Initialize memoization table with -1
    vector<vector<int>> memo(n + 1, vector<int>(capacity + 1, -1));
    cout << "Maximum profit (Memoization): " << knapsack.kp_mem(items, n, capacity, memo) << endl;

    return 0;
}
