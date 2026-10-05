#include <iostream>
using namespace std;

struct Node {
    int yield;
    Node* left;
    Node* right;
};

Node* createNode(int value) {
    Node* newNode = new Node();
    newNode->yield = value;
    newNode->left = NULL;
    newNode->right = NULL;
    return newNode;
}

Node* insert(Node* root, int value) {
    if (root == NULL)
        return createNode(value);

    if (value < root->yield)
        root->left = insert(root->left, value);
    else
        root->right = insert(root->right, value);

    return root;
}

void rangeQuery(Node* root, int low, int high) {
    if (root == NULL)
        return;

    if (root->yield > low)
        rangeQuery(root->left, low, high);

    if (root->yield >= low && root->yield <= high)
        cout << root->yield << " ";

    if (root->yield < high)
        rangeQuery(root->right, low, high);
}

int main() {
    Node* root = NULL;
    int n, value;
    int low, high;

    cout << "Enter number of grape plants: ";
    cin >> n;

    cout << "Enter grape yields:\n";
    for (int i = 0; i < n; i++) {
        cin >> value;
        root = insert(root, value);
    }

    cout << "Enter minimum and maximum yield: ";
    cin >> low >> high;

    cout << "\nGrape yields in range: ";
    rangeQuery(root, low, high);

    return 0;
}