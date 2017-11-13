//
//  main.cpp
//  Add Two Numbers
//
//  Created by 伏开宇 on 2017/7/9.
//  Copyright © 2017年 伏开宇. All rights reserved.
//

#include <iostream>
struct ListNode {
     int val;
     ListNode *next;
     ListNode(int x) : val(x), next(NULL) {}
};
ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
    ListNode* cur1 = l1;
    ListNode* cur2 = l2;
    ListNode* ret = new ListNode(0);
    ListNode* head = ret;
    int i = 0;
    int flag = 0;
    while(cur1 != NULL || cur2 != NULL){
        if(i == 0){
            int sum = cur1->val + cur2->val;
            if(sum >= 10){
                flag = 1;
                sum -= 10;
            }
            else {
                flag = 0;
            }
            cur1 = cur1->next;
            cur2 = cur2->next;
            ret->val = sum;
            i++;
        }
        else{
            if(cur1 != NULL and cur2 != NULL){
                int sum = cur1->val + cur2->val + flag;
                if(sum >= 10){
                    flag = 1;
                    sum -= 10;
                }
                else {
                    flag = 0;
                }
                cur1 = cur1->next;
                cur2 = cur2->next;
                ret->next = new ListNode(sum);
                ret = ret->next;
                i++;
            }
            else {
                ListNode* temp;
                if(cur1  == NULL)
                    temp = cur2;
                else
                    temp = cur1;
                ret->next = temp;
                ListNode* curNode;
                ListNode* prevNode;
                for(curNode = temp; curNode != NULL; curNode = curNode->next){
                    curNode->val += flag;
                    if(curNode->val >= 10){
                        prevNode = curNode;
                        curNode->val -= 10;
                    }
                    else {
                        flag = 0;
                        break;
                    }
                    
                }
                if(flag == 1){
                    prevNode->next = new ListNode(1);
                    flag = 0;
                }
                break;
            }
        }
    }
    if(flag == 1)
        ret->next = new ListNode(1);
    return head;
}
int main(int argc, const char * argv[]) {
    ListNode* c1 = new ListNode(1);
    ListNode* c2 = new ListNode(9);
    c2->next = new ListNode(9);
    ListNode* temp = addTwoNumbers(c1, c2);
    return 0;
}
