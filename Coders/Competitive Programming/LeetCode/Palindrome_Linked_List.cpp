// Problem Link: https://leetcode.com/problems/palindrome-linked-list/
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

// A linked list is a data structure where the objects are arranged in a linear order. Unlike an array, however, in which the linear order is determined by the array indices, the order in a linked list is determined by a pointer in each object.
class Solution
{
public:
    bool isPalindrome(ListNode *head)
    {
        ListNode *slow = head, *fast = head;
        ListNode *reverse = NULL;
        // Move fast pointer to the last node for odd or to NULL for even no. of nodes.
        // Reverse the first half of the linked list with the help of slow and reverse pointers
        while (fast && fast->next)
        {
            fast = fast->next->next;
            ListNode *temp = reverse;
            reverse = slow;
            slow = slow->next;
            reverse->next = temp;
        }
        // If fast is at the last node, move slow one step further to point the first node of second half of linked list.
        if (fast)
        {
            slow = slow->next;
        }
        // Compare the first half and the second half of the linked list
        while (reverse && (reverse->val == slow->val))
        {
            slow = slow->next;
            reverse = reverse->next;
        }
        // If reverse becomes NULL i.e succesfully comes to the end of the first half then return true else false;
        return !reverse;
    }
};