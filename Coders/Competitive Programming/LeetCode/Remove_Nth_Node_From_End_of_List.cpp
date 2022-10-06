// Problem Link: https://leetcode.com/problems/remove-nth-node-from-end-of-list/
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution
{
public:
    // A linked list is a data structure where the objects are arranged in a linear order. Unlike an array, however, in which the linear order is determined by the array indices, the order in a linked list is determined by a pointer in each object

    ListNode *removeNthFromEnd(ListNode *head, int n)
    {

        //****************************************************
        // Approach - 1
        // TC: O(n) + O(n) , i.e. O(2n); SC: O(1)
        //*****************************************************
        ListNode *p = head, *q = NULL;
        int l = 0;

        // Caculating the length of the Linked List
        while (p != NULL)
        {
            l++;
            p = p->next;
        }
        p = head;
        int temp = l - n, i = 1;

        // Traverse till the pointer p points on the node to be deleted and q to the previous node of the deleting node.
        if (temp != 0)
        {
            while (i <= temp)
            {
                q = p;
                p = p->next;
                i++;
            }
        }
        // if length == n i.e. first node is to be deleted
        else
        {
            head = p->next;
            return head;
        }
        // Link the previous node of the node to be deleted to the next node of the node to be deleted.
        q->next = p->next;
        return head;

        //******************************************************
        // Approach - 2
        // Optimized
        // Slow and Fast pointer approach, TC: O(n); SC: O(1)
        //******************************************************

        ListNode *slow = head, *fast = head;
        int c = n;
        // Iterate the fast pointer till the node previous to the node to be deleted.
        while (c)
        {
            fast = fast->next;
            c--;
        }

        // if fast == NULL i.e. the first node is to be deleted from the linked list.
        if (fast == NULL)
            return head->next;

        // Slow pointer will now point to the previous node of the node to be deleted.
        while (fast && fast->next != NULL)
        {
            slow = slow->next;
            fast = fast->next;
        }

        // Link the previous node of the node to be deleted to the next node of the node to be deleted.
        slow->next = slow->next->next;
        return head;
    }
};