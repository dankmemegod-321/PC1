#include <iostream>
using namespace std;

struct Node
{
    char ch;
    int freq;
    Node *left, *right;
};

// Function to create a new node
Node *createNode(char ch, int freq)
{
    Node *node = new Node;
    node->ch = ch;
    node->freq = freq;
    node->left = node->right = NULL;
    return node;
}

// Function to find the two smallest frequencies
void findTwoSmallest(Node *arr[], int n, int &first, int &second)
{
    first = second = -1;

    for (int i = 0; i < n; i++)
    {
        if (arr[i] == NULL)
            continue;
        if (first == -1 || arr[i]->freq < arr[first]->freq)
        {
            second = first;
            first = i;
        }
        else if (second == -1 || arr[i]->freq < arr[second]->freq)
        {
            second = i;
        }
    }
}

// Recursive function to print Huffman codes
void printCodes(Node *root, string str)
{
    if (!root)
        return;
    if (root->left == NULL && root->right == NULL)
    {
        cout << root->ch << " : " << str << endl;
        return;
    }
    printCodes(root->left, str + "0");
    printCodes(root->right, str + "1");
}

int main()
{
    int n;
    cout << "Enter number of characters: ";
    cin >> n;

    Node *arr[100]; // array to store nodes
    char ch;
    int freq;

    for (int i = 0; i < n; i++)
    {
        cout << "Enter character and its frequency: ";
        cin >> ch >> freq;
        arr[i] = createNode(ch, freq);
    }

    int size = n;

    // Build Huffman Tree
    while (size > 1)
    {
        int first, second;
        findTwoSmallest(arr, n, first, second);

        Node *newNode = createNode('$', arr[first]->freq + arr[second]->freq);
        newNode->left = arr[first];
        newNode->right = arr[second];

        arr[first] = newNode;
        arr[second] = NULL;
        size--;
    }

    // Find the root node
    Node *root = NULL;
    for (int i = 0; i < n; i++)
    {
        if (arr[i] != NULL)
        {
            root = arr[i];
            break;
        }
    }

    cout << "\nHuffman Codes:\n";
    printCodes(root, "");

    return 0;
}