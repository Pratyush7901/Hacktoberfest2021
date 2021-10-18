#include <bits/stdc++.h>

using namespace std;

struct node
{
    int data;
    struct node *next;
};

struct node *insert(struct node *head, int data)
{
    node *new_node = new node();
    new_node->data = data;

    node *point = head;
    while (point->next != NULL)
    {
        point = point->next;
    }
    point->next = new_node;
    new_node->next = NULL;
    return head;
}

struct node *reversegroup(struct node *head, int k)
{
    if (head == NULL) //head shouldn't be NULL as it would mean we have reached the end of the list
    {
        return NULL;
    }
    //we will define 3 nodes current,succ and pred to track the pointers
    node *pred = NULL;
    node *current = head;
    node *succ = NULL;

    int n = 1; // to track the number of times loop is executed

    //we will start with the head and upto the first k elements will form a group where we will do the reversal

    while (current != NULL && n <= k)
    {
        succ = current->next;                   //succ will be set to next of the current node
        current->next = pred;                    //and the next of current node will point to pred node
        pred = current;                         //then we will assign the value of pred node which will be current node
        current = succ;                          //and at last the current node will be point towards the succ node
        n++;
    }

    if (succ != NULL)
    {
        head->next = reversegroup(succ, k); // we will repeat this process till we reach the last block of the set
    }
    return pred;                //at last the pred node will be the current node which in fact will be the head node
}
void print(node *head)
{
    while (head != NULL)
    {
        cout << head->data << " ";
        head = head->next;
    }
}

int main()
{
    int t;
    cin >> t;

    while (t--)
    {
        int n; //no. of items in 1 linked list
        cin >> n;

        node *head = new node(); //assigning a head node

        int a;
        cin >> a;
        head->data = a;
        head->next = NULL;

        int i = 0;
        while (i < n - 1)
        {
            int b;
            cin >> b;
            head = insert(head, b);
            i++;
        }

        int k;
        cin >> k;
        head = reversegroup(head, k);
        print(head);
    }
}