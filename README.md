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
    {
        temp = temp->next;
    }

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

    // Move to the last node
    while (temp->next != NULL)
    {
        temp = temp->next;
    }

    // Traverse backward
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
    {
        return head2;
    }

    if (head2 == NULL)
    {
        return head1;
    }

    Node* temp = head1;

    while (temp->next != NULL)
    {
        temp = temp->next;
    }

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
        {
            return temp;
        }

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

    // Delete first node
    if (temp == head)
    {
        head = temp->next;

        if (head != NULL)
        {
            head->prev = NULL;
        }

        delete temp;

        cout << name << " deleted successfully." << endl;
        return;
    }

    // Connect previous node to next node
    if (temp->prev != NULL)
    {
        temp->prev->next = temp->next;
    }

    // Connect next node to previous node
    if (temp->next != NULL)
    {
        temp->next->prev = temp->prev;
    }

    delete temp;

    cout << name << " deleted successfully." << endl;
}

// Calculate total duration
int totalDuration(Node* head)
{
    int total = 0;

    Node* temp = head;

    while (temp != NULL)
    {
        total = total + temp->duration;
        temp = temp->next;
    }

    return total;
}

// Count calls
int countCalls(Node* head)
{
    int count = 0;

    Node* temp = head;

    while (temp != NULL)
    {
        count++;
        temp = temp->next;
    }

    return count;
}

// Delete complete list
void deleteList(Node*& head)
{
    Node* temp = head;

    while (temp != NULL)
    {
        Node* nextNode = temp->next;

        delete temp;

        temp = nextNode;
    }

    head = NULL;
}

int main()
{
    Node* list1 = NULL;
    Node* list2 = NULL;

    int n, m;
    string name;
    int duration;

    // First list
    cout << "Enter number of calls in first log: ";
    cin >> n;

    cout << "\nEnter call details:" << endl;

    for (int i = 0; i < n; i++)
    {
        cout << "Enter caller name and duration: ";
        cin >> name >> duration;

        insertEnd(list1, name, duration);
    }

    // Second list
    cout << "\nEnter number of calls in second log: ";
    cin >> m;

    cout << "\nEnter call details:" << endl;

    for (int i = 0; i < m; i++)
    {
        cout << "Enter caller name and duration: ";
        cin >> name >> duration;

        insertEnd(list2, name, duration);
    }

    // Display first list
    cout << "\n========== FIRST CALL LOG ==========" << endl;
    displayForward(list1);

    // Display second list
    cout << "\n========== SECOND CALL LOG ==========" << endl;
    displayForward(list2);

    // Merge lists
    list1 = mergeLists(list1, list2);

    cout << "\n========== MERGED CALL LOG ==========" << endl;
    displayForward(list1);

    // Forward display
    cout << "\n========== FORWARD DISPLAY ==========" << endl;
    displayForward(list1);

    // Backward display
    cout << "\n========== BACKWARD DISPLAY ==========" << endl;
    displayBackward(list1);

    // Search
    cout << "\nEnter caller to search: ";
    cin >> name;

    Node* result = search(list1, name);

    cout << "\n========== SEARCH RESULT ==========" << endl;

    if (result != NULL)
    {
        cout << "Caller: " << result->name << endl;
        cout << "Duration: "
             << result->duration
             << " minutes" << endl;
    }
    else
    {
        cout << name << " not found!" << endl;
    }

    // Delete
    cout << "\nEnter caller to delete: ";
    cin >> name;

    deleteNode(list1, name);

    cout << "\n========== AFTER DELETING "
         << name
         << " ==========" << endl;

    displayForward(list1);

    // Statistics
    cout << "\n========== CALL STATISTICS ==========" << endl;

    cout << "Total Calls: "
         << countCalls(list1)
         << endl;

    cout << "Total Call Duration: "
         << totalDuration(list1)
         << " minutes"
         << endl;

    // Free memory
    deleteList(list1);

    return 0;
}
