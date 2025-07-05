#include <iostream>
#include <vector>
#include <tuple>
#include <unordered_map>
using namespace std;

class Item {
private:
    int id;
    int profit;
    int weight;

public:
    Item(int i, int p, int w) : id(i), profit(p), weight(w) {}

    // Getter functions
    int getId() const {
        return id;
    }

    int getProfit() const {
        return profit;
    }

    int getWeight() const {
        return weight;
    }
};

class Knapsack {
private:
    vector<Item> items;
    int capacity;
    unordered_map<tuple<int, int>, int> memo;

public:
    Knapsack(const vector<Item>& item, int c) : items(item), capacity(c) {}

    // Recursive approach
    int kp_rec(int n, int capacity) {
        // Base case
        if (n == 0 || capacity == 0) return 0;

        if (items[n - 1].getWeight() > capacity) {
            return kp_rec(n - 1, capacity);
        } else {
            return max(
                items[n - 1].getProfit() + kp_rec(n - 1, capacity - items[n - 1].getWeight()),
                kp_rec(n - 1, capacity)
            );
        }
    }

    // Memoization approach
    int kp_mem(int n, int capacity) {
        auto key = make_tuple(n, capacity);
        if (memo.find(key) != memo.end()) {
            return memo[key];
        }

        // Base case
        if (n == 0 || capacity == 0) return 0;

        if (items[n - 1].getWeight() > capacity) {
            return memo[key] = kp_mem(n - 1, capacity);
        } else {
            return memo[key] = max(
                items[n - 1].getProfit() + kp_mem(n - 1, capacity - items[n - 1].getWeight()),
                kp_mem(n - 1, capacity)
            );
        }
    }
};

int main() {
    vector<Item> items = {
        Item(1, 10, 1),
        Item(2, 15, 2),
        Item(3, 40, 3)
    };
    int capacity = 6;
    int n = items.size();

    Knapsack napsack(items, capacity);

    int max_value_rec = napsack.kp_rec(n, capacity);
    cout << "Maximum value (Recursive): " << max_value_rec << endl;

    // Resetting the memoization for fresh calculation
    napsack = Knapsack(items, capacity);
    int max_value_mem = napsack.kp_mem(n, capacity);
    cout << "Maximum value (Memoization): " << max_value_mem << endl;

    return 0;
}
