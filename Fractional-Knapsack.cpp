#include <iostream>
using namespace std;

struct Item
{
    int weight;
    int value;
    float ratio;
};

int main()
{
    int n, capacity;
    cout << "Enter number of items: ";
    cin >> n;

    Item items[100];

    for (int i = 0; i < n; i++)
    {
        cout << "Enter value and weight of item " << i + 1 << ": ";
        cin >> items[i].value >> items[i].weight;
        items[i].ratio = (float)items[i].value / items[i].weight;
    }

    cout << "Enter knapsack capacity: ";
    cin >> capacity;

    // Sort items based on value/weight ratio (descending order)
    for (int i = 0; i < n - 1; i++)
    {
        for (int j = i + 1; j < n; j++)
        {
            if (items[i].ratio < items[j].ratio)
            {
                Item temp = items[i];
                items[i] = items[j];
                items[j] = temp;
            }
        }
    }

    float totalValue = 0;
    int currentWeight = 0;

    cout << "\nSelected Items:\n";
    for (int i = 0; i < n; i++)
    {
        if (currentWeight + items[i].weight <= capacity)
        {
            // Take full item
            currentWeight += items[i].weight;
            totalValue += items[i].value;
            cout << "Item " << i + 1 << " taken completely (Value: "
                 << items[i].value << ", Weight: " << items[i].weight << ")\n";
        }
        else
        {
            // Take fraction of item
            int remain = capacity - currentWeight;
            totalValue += items[i].ratio * remain;

            cout << "Item " << i + 1 << " taken partially (Weight taken: "
                 << remain << ")\n";
            break;
        }
    }

    cout << "\nMaximum total value in knapsack = " << totalValue << endl;

    return 0;
}