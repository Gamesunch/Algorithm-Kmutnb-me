#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

struct Item {
    float weight, value, ratio;
    int index;
};


bool compare(Item a, Item b) {
    return a.ratio > b.ratio;
}

int main() {
    int n, k;
    cin >> n >> k;

    vector<Item> items(n);
    vector<float> check(n, 0.0);

    for (int i = 0; i < n; i++) {
        cin >> items[i].weight;
        items[i].index = i;
    }

    for (int i = 0; i < n; i++) {
        cin >> items[i].value;
        items[i].ratio = items[i].value / items[i].weight;
    }

    sort(items.begin(), items.end(), compare);

    float sumValue = 0.0, sumWeight = 0.0;

    for (int i = 0; i < n && sumWeight < k; i++) {
        int locate = items[i].index;
        
        if (sumWeight + items[i].weight <= k) {
            check[locate] = 1.0;
            sumWeight += items[i].weight;
            sumValue += items[i].value;
        } else {
            check[locate] = (k - sumWeight) / items[i].weight;
            sumValue += check[locate] * items[i].value;
            sumWeight = k;
            break;
        }
    }

    for (int i = 0; i < n; i++) {
        cout<<check[i]<<" ";
    }
    cout<<endl;

    cout<<sumValue;
}

