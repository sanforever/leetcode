/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   main.c
 * Author: San-NB
 *
 * Created on 2017年5月24日, 上午 12:22
 */

#include <stdio.h>
#include <stdlib.h>

struct ListNode {
    int val;
    struct ListNode *next;
};

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
struct ListNode* addTwoNumbers(struct ListNode* l1, struct ListNode* l2) {
    struct ListNode *ans, *cur, *tmp;
    char flag1, flag2;
    int val1, val2;
    int carry;
    
    carry = 0;
    ans = cur = NULL;
    while(1) {
        flag1 = flag2 = 0;
        val1 = val2 = 0;
        
        if(l1 != NULL) {
            val1 = l1->val;
            flag1 = 1;
            l1 = l1->next;
        }
        
        if(l2 != NULL) {
            val2 = l2->val;
            flag2 = 1;
            l2 = l2->next;
        }
        
        if((flag1 != 0) || (flag2 != 0) || (carry != 0)) {
            tmp = (struct ListNode *)malloc(sizeof(struct ListNode));
            tmp->val = (val1 + val2 + carry) % 10;
            tmp->next = NULL;
            carry = ((val1 + val2 + carry) >= 10)?1:0;
            
            if(cur == NULL) {
                cur = tmp;
                ans = tmp;
            } else {
                cur->next = tmp;
                cur = tmp;
            }
        } else {
            break;
        }        
    }
    
    return ans;
}

/*
 * 
 */
int main(int argc, char** argv) {
    struct ListNode first[3];
    struct ListNode second[3];
    
    first[0].val = 2;
    first[0].next = &(first[1]);
    first[1].val = 4;
    first[1].next = &(first[2]);
    first[2].val = 3;
    first[2].next = NULL;
    
    second[0].val = 5;
    second[0].next = &(second[1]);
    second[1].val = 6;
    second[1].next = &(second[2]);
    second[2].val = 4;
    second[2].next = NULL;
    
    addTwoNumbers(first, second);
    
    return (EXIT_SUCCESS);
}

