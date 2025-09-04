// Merge k Sortest Linked List [1,4,5], [1,3,4], [2,6]
// T.C - O(n * k log k) && S.C - O(k)
#include <bits/stdc++.h>
using namespace std;
class Node
{
public:
    int data;
    Node *next;
    Node(int d)
    {
        this->data = d;
        next = NULL;
    }
};

class compare
{
public:
    bool operator()(Node *a, Node *b)
    {
        return a->data > b->data;
    }
};

void createLinkedList(Node *&head, int data)
{
    Node *newData = new Node(data);

    if (head == NULL)
    {
        head = newData;
        return;
    }
    Node *temp = head;
    while (temp->next != NULL)
    {
        temp = temp->next;
    }
    temp->next = newData;
}

void printLL(Node *&head)
{
    Node *temp = head;
    while (temp != NULL)
    {
        cout << temp->data << " ";
        temp = temp->next;
    }
}
Node *mergeKLinkedList(vector<Node *> &arr)
{
    priority_queue<Node *, vector<Node *>, compare> minHeap;

    int k = arr.size();
    for (int i = 0; i < k; i++)
    {
        if (arr[i] != NULL)
            minHeap.push(arr[i]);
    }

    Node *head = NULL;
    Node *tail = NULL;
    while (!minHeap.empty())
    {
        Node *temp = minHeap.top();
        minHeap.pop();
        if (head == NULL)
        {
            head = tail = temp;
        }
        else
        {
            tail->next = temp;
            tail = temp;
        }
        if (tail->next != NULL)
        {
            minHeap.push(tail->next);
        }
    }
    return head;
}

int main()
{
    Node *head1 = NULL;
    createLinkedList(head1, 1);
    createLinkedList(head1, 4);
    createLinkedList(head1, 5);
    Node *head2 = NULL;
    createLinkedList(head2, 1);
    createLinkedList(head2, 3);
    createLinkedList(head2, 4);
    Node *head3 = NULL;
    createLinkedList(head3, 2);
    createLinkedList(head3, 6);
    // printLL(head1);
    // printLL(head2);
    // printLL(head3);

    vector<Node *> arr = {head1, head2, head3};
    Node *result = mergeKLinkedList(arr);

    printLL(result);

    return 0;
}