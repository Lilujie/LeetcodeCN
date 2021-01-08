/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode* reverseList(ListNode* head) { 
        // 迭代实现       
        ListNode* preNode = NULL,* currentNode = head, *tmp;
        while(currentNode) {
            tmp = currentNode->next;          
            currentNode->next = preNode;
            preNode = currentNode;
            currentNode = tmp;
        }

        return preNode;
        //递归实现
        // if (head == NULL || head->next == NULL) {
        //     return head;
        // }
        // ListNode *p = reverseList(head->next);
        // head->next->next = head;
        // head->next = NULL;
        // return p;
    }
};