//  Node Definition
struct Node
{
    Node *next;
    int data;
};

int Length(Node *head)
{
    return (head) ? (Length(head->next) + 1) : 0;
}

int Count(Node *head, int data)
{
    return (!head) ? 0 : (Count(head->next, data) + (head->data == data));