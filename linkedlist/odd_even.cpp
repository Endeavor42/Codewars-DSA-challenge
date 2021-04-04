// 328. Odd Even Linked List
#include <iostream>

using namespace std;

// Definition for singly-linked list.
struct ListNode
{
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};
class Solution
{
public:
    ListNode *oddEvenList(ListNode *head)
    {
        auto odd = head;
        auto even = odd->next;
        auto evenHead = even;
        while (odd->next)
        {
            odd->next = even->next;
            odd = odd->next;
            even->next = odd->next;
            even = even->next;
        }
        odd->next = evenHead;
        return head;
    }

    ListNode *initialize(int arr[], int SIZE)
    {
        ListNode *head = new ListNode(arr[SIZE - 1]);
        for (int i = SIZE - 2; i >= 0; i--)
        {
            ListNode *newNode = new ListNode(arr[i], head);
            head = newNode;
        }
        return head;
    }

    void display(ListNode *head)
    {
        auto curr = head;
        while (curr)
        {
            cout << curr->val;
            curr = curr->next;
        }
    }
};

// 1 2 3 4 5
// 1 3 5 2 4

int main()
{
    Solution ll;
    const int SIZE = 5;
    int arr[SIZE] = {1, 2, 3, 4, 5};
    auto head = ll.initialize(arr, SIZE);
    ll.oddEvenList(head);
    ll.display(head);
}