/*

You are given two non-empty linked lists representing two non-negative integers. The digits are stored in reverse order, and each of their nodes contains a single digit. Add the two numbers and return the sum as a linked list.

You may assume the two numbers do not contain any leading zero, except the number 0 itself.

Definition for singly-linked list:

struct ListNode {
	int val;
	struct ListNode *next;
};

*/


struct ListNode* addTwoNumbers(struct ListNode* l1, struct ListNode* l2){
    int sum;
    struct ListNode *node = NULL;
    if (l1 != NULL && l2 != NULL)
    {
        node = calloc(1, sizeof(struct ListNode));
        int sum = l1->val + l2->val;
        node->val = sum % 10;
        if (sum > 9)
        {
            if (l1->next != NULL)
            {
                l1->next->val += 1;
                node->next = addTwoNumbers(l1->next, l2->next);
            }
            else if (l2->next != NULL)
            {
                l2->next->val += 1;
                node->next = addTwoNumbers(l1->next, l2->next);
            }
            else
            {
                node->next = calloc(1, sizeof(struct ListNode));
                node->next->val = 1;
            }
        }
        else
        {
            node->next = addTwoNumbers(l1->next, l2->next);
        }
    }
    else if (l1 != NULL || l2 != NULL)
    {
        node = calloc(1, sizeof(struct ListNode));
        if (l1 != NULL)
        {
            if (l1->val > 9)
            {
                if (l1->next != NULL)
                {
                    l1->next->val += 1;
                }
                else
                {
                    node->next = calloc(1, sizeof(struct ListNode));
                    node->next->val = 1;
                    node->val = l1->val % 10;
                    return node;
                }
            }

            node->val = l1->val % 10;
            node->next = addTwoNumbers(l1->next, l2);

        }
        else
        {
            if (l2->val > 9)
            {
                if (l2->next != NULL)
                {
                    l2->next->val += 1;
                }
                else
                {
                    node->next = calloc(1, sizeof(struct ListNode));
                    node->next->val = 1;
                    node->val = l2->val % 10;
                    return node;
                }
            }

            node->val = l2->val % 10;
            node->next = addTwoNumbers(l1, l2->next);
        }
    }

    return node;
}
