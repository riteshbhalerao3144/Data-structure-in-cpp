#include <iostream>
#include <string>
using namespace std;

struct Node
{
    string name;
    int duration;
    Node* next;
    Node* prev;
};

// Create a new node
Node* createNode(string name, int duration)
{
    Node* newNode = new Node();
    newNode->name = name;
    newNode->duration = duration;
    newNode->next = NULL;
    newNode->prev = NULL;
    return newNode;
}

// Insert node at the end
void insertEnd(Node*& head, string name, int duration)
{
    Node* newNode = createNode(name, duration);

    if (head == NULL)
    {
        head = newNode;
        return;
    }

    Node* temp = head;

    while (temp->next != NULL)
        temp = temp->next;

    temp->next = newNode;
    newNode->prev = temp;
}

// Display forward
void displayForward(Node* head)
{
    if (head == NULL)
    {
        cout << "List is empty." << endl;
        return;
    }

    Node* temp = head;

    while (temp != NULL)
    {
        cout << temp->name << " - "
             << temp->duration << " min" << endl;
        temp = temp->next;
    }
}

// Display backward
void displayBackward(Node* head)
{
    if (head == NULL)
    {
        cout << "List is empty." << endl;
        return;
    }

    Node* temp = head;

    while (temp->next != NULL)
        temp = temp->next;

    while (temp != NULL)
    {
        cout << temp->name << " - "
             << temp->duration << " min" << endl;
        temp = temp->prev;
    }
}

// Merge two lists
Node* mergeLists(Node* head1, Node* head2)
{
    if (head1 == NULL)
        return head2;

    if (head2 == NULL)
        return head1;

    Node* temp = head1;

    while (temp->next != NULL)
        temp = temp->next;

    temp->next = head2;
    head2->prev = temp;

    return head1;
}

// Search for a caller
Node* search(Node* head, string name)
{
    Node* temp = head;

    while (temp != NULL)
    {
        if (temp->name == name)
            return temp;

        temp = temp->next;
    }

    return NULL;
}

// Delete a node
void deleteNode(Node*& head, string name)
{
    Node* temp = search(head, name);

    if (temp == NULL)
    {
        cout << name << " not found." << endl;
        return;
    }

    if (temp->prev == NULL)
    {
        head = temp->next;

        if (head != NULL)
            head->prev = NULL;
    }
    else
    {
        temp->prev->next = temp->next;

        if (temp->next != NULL)
            temp->next->prev = temp->prev;
    }

    delete temp;
    cout << name << " deleted successfully." << endl;
}

// Main function
int main()
{
    Node* head1 = NULL;
    Node* head2 = NULL;

    int n, duration;
    string name;

    cout << "Enter number of calls in first list: ";
    cin >> n;

    for (int i = 0; i < n; i++)
    {
        cout << "Enter caller name and duration: ";
        cin >> name >> duration;
        insertEnd(head1, name, duration);
    }

    cout << "\nEnter number of calls in second list: ";
    cin >> n;

    for (int i = 0; i < n; i++)
    {
        cout << "Enter caller name and duration: ";
        cin >> name >> duration;
        insertEnd(head2, name, duration);
    }

    cout << "\nFirst Call List:\n";
    displayForward(head1);

    cout << "\nSecond Call List:\n";
    displayForward(head2);

    head1 = mergeLists(head1, head2);
    head2 = NULL;

    cout << "\nMerged Call List:\n";
    displayForward(head1);

    cout << "\nMerged List in Backward Order:\n";
    displayBackward(head1);

    cout << "\nEnter caller name to search: ";
    cin >> name;

    Node* result = search(head1, name);

    if (result != NULL)
        cout << "Caller found: " << result->name
             << ", Duration: " << result->duration << " min" << endl;
    else
        cout << "Caller not found." << endl;

    cout << "\nEnter caller name to delete: ";
    cin >> name;

    deleteNode(head1, name);

    cout << "\nCall List After Deletion:\n";
    displayForward(head1);

    return 0;
}
