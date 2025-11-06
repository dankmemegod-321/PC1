#include <iostream>
using namespace std;

// Function to find the maximum value that can be put in a knapsack
int knapSack(int W, int wt[], int val[], int n)
{
    int dp[20][20]; // Table for storing results

    // Build table dp[][] in bottom-up manner
    for (int i = 0; i <= n; i++)
    {
        for (int w = 0; w <= W; w++)
        {
            if (i == 0 || w == 0)
                dp[i][w] = 0;
            else if (wt[i - 1] <= w)
                dp[i][w] = max(val[i - 1] + dp[i - 1][w - wt[i - 1]], dp[i - 1][w]);
            else
                dp[i][w] = dp[i - 1][w];
        }
    }

    // Print the DP Table (for understanding)
    cout << "\nDP Table:\n";

    for (int i = 0; i <= n; i++)
    {
        for (int w = 0; w <= W; w++)
        {
            cout << dp[i][w] << " ";
        }
        cout << endl;
    }

    return dp[n][W]; // The last cell contains the maximum value
}

int main()
{
    int n, W;

    cout << "Enter number of items: ";
    cin >> n;

    int val[20], wt[20];

    for (int i = 0; i < n; i++)
    {
        cout << "Enter value and weight of item " << i + 1 << ": ";
        cin >> val[i] >> wt[i];
    }

    cout << "Enter capacity of knapsack: ";
    cin >> W;

    int maxValue = knapSack(W, wt, val, n);

    cout << "\nMaximum total value in knapsack = " << maxValue << endl;

    return 0;
}