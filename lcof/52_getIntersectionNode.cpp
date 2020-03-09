#include <iostream>
#include <vector>
#include <set>

using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};
 
class Solution {
public:
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        if (headA == NULL || headB == NULL) return NULL;

        ListNode* node1 = headA;
        ListNode* node2 = headB;
        int b1 = 0, b2 = 0;

        while (node1 != node2)
        {
            node1 = node1->next;
            node2 = node2->next;
            if (node1 == NULL) 
            {
                if (b1 == 0)
                {
                    node1 = headB;
                    b1 = 1;
                }
                else
                    break;
            }
            if (node2 == NULL) 
            {
                if (b2 == 0)
                {
                    node2 = headA;
                    b2 = 1;
                }
                else
                    break;
            }
        }

        return node1;
    }

    //利用set，空间复杂度n
    ListNode *getIntersectionNode1(ListNode *headA, ListNode *headB) {
        if (headA == NULL || headB == NULL) return NULL;

        set<ListNode*> s;
        while (headA != NULL)
        {
            s.insert(headA);
            headA = headA->next;
        }
        while (headB != NULL && s.find(headB) == s.end())
            headB = headB->next;
        
        return headB;
    }
};