#include <iostream>
using namespace std;

struct Node {
    string name;
    int duration;
    Node* next;
};

Node* createNode(string name, int duration) {
    Node* newNode = new Node();
    newNode->name = name;
    newNode->duration = duration;
    newNode->next = NULL;
    return newNode;
}

void insertEnd(Node*& head, string name, int duration) {
    Node* newNode = createNode(name, duration);

    if (head == NULL) {
        head = newNode;
        return;
    }

    Node* temp = head;
    while (temp->next != NULL)
        temp = temp->next;

    temp->next = newNode;
}

Node* mergeLists(Node* head1, Node* head2) {
    if (head1 == NULL)
        return head2;

    Node* temp = head1;
    while (temp->next != NULL)
        temp = temp->next;

    temp->next = head2;
    return head1;
}

void display(Node* head) {
    while (head != NULL) {
        cout << head->name << " - " << head->duration << " min" << endl;
        head = head->next;
    }
}

int main() {
    Node* list1 = NULL;
    Node* list2 = NULL;

    int n, m;
    string name;
    int duration;

    cout << "Enter number of calls in first log: ";
    cin >> n;

    for (int i = 0; i < n; i++) {
        cin >> name >> duration;
        insertEnd(list1, name, duration);
    }

    cout << "Enter number of calls in second log: ";
    cin >> m;

    for (int i = 0; i < m; i++) {
        cin >> name >> duration;
        insertEnd(list2, name, duration);
    }

    list1 = mergeLists(list1, list2);

    cout << "\nMerged Call Log:\n";
    display(list1);

    return 0;
}