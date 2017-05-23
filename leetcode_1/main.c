/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   main.c
 * Author: San-NB
 *
 * Created on 2017年5月23日, 上午 1:49
 */

#include <stdio.h>
#include <stdlib.h>


/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* twoSum(int* nums, int numsSize, int target) {
    int *ans = (int *)malloc(sizeof(int) * 2);
    int i, find;
    unsigned int idx;
    const int PRIME = 32771;

    /* Build a hash table */
    struct hash_entry {
        int val;
        struct hash_entry *next;
    } **table, *node, *tmp;
    
    table = (struct hash_entry **)malloc(sizeof(struct hash_entry *) * PRIME);
    for(i = 0; i < PRIME; i++) {
        table[i] = NULL;
    }
    
    node = (struct hash_entry *)malloc(sizeof(struct hash_entry) * numsSize);
    /* Insert each scanned number into the head of hash table */
    for(i = 0; i < numsSize; i++) {
        idx = ((unsigned int)nums[i] % PRIME);
        
        tmp = table[idx];        
        node[i].val = nums[i];
        if(tmp != NULL) {
            node[i].next = tmp;
        } else {
            node[i].next = NULL;
        }
        table[idx] = &(node[i]);
    }
    
    for(i = 0; i < numsSize; i++) {
        find = target - nums[i];
        
        /* if "find" exists in the hash table, return the result */
        idx = ((unsigned int)find % PRIME);
        tmp = table[idx];
        while(tmp != NULL) {
            if(tmp->val == find) {
                ans[0] = i;
                ans[1] = (tmp - node);
                /* may not use the same element twice */
                if(ans[0] == ans[1]) {
                    tmp = tmp->next;
                    continue;
                }
                
                free(table);
                free(node);
                return ans;
            }
            tmp = tmp->next;
        }
        
    }
    
    return ans;
}

/*
 * 
 */
int main(int argc, char** argv) {  
    int num[] = {-1, -2, -3, -4, -5};
    int *ans;
    
    ans = twoSum(num, 5, -8);
    
    return (EXIT_SUCCESS);
}

