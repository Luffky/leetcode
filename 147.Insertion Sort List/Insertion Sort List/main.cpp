//
//  main.cpp
//  test
//
//  Created by 伏开宇 on 2017/4/12.
//  Copyright © 2017年 伏开宇. All rights reserved.
//

#include <iostream>
#include <vector>
using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};
void Print(ListNode* x){
    for(int i = 0 ; i < 10; i++){
        cout<<x->val<<" ";
        x = x->next;
    }
    cout<<endl;
}
ListNode* insertionSortList(ListNode* head) {
    ListNode* r = head;
    r = r->next;
    ListNode* tail = head;
    ListNode* q = head;
    while(r != NULL){
        q = head;
        if(head->val > r->val){
            tail->next = r->next;
            r->next = head;
            head = r;
        }
        else{
            while(q->next->val <= r->val and q->next != r){
                q = q->next;
            }
            if(q->next != r){
                tail->next = r->next;
                r->next = q->next;
                q->next = r;
            }
            else{
                tail = r;
            }
        }
        r = tail->next;
    }
    return head;
}

int main(int argc, const char * argv[]) {
    ListNode** l = new ListNode*[10];
    for(int i = 0 ; i < 10; i++){
        int a;
        cin>>a;
        l[i] = new ListNode(a);
    }
    for(int i = 0 ; i < 9; i++)
        l[i]->next = l[i + 1];
    ListNode* head;
    head = insertionSortList(l[0]);
    return 0;
}
