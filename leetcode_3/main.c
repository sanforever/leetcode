/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   main.c
 * Author: San-NB
 *
 * Created on 2017年5月24日, 上午 2:43
 */

/*
Given a string, find the length of the longest substring without repeating characters.

Examples:
Given "abcabcbb", the answer is "abc", which the length is 3.
Given "bbbbb", the answer is "b", with the length of 1.
Given "pwwkew", the answer is "wke", with the length of 3. Note that the answer must be a substring, "pwke" is a subsequence and not a substring.
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int lengthOfLongestSubstring(char* s) {
    int i, max_len, len, new_start;
    const int num_of_char = 256;
    int map[num_of_char]; /* 0x00 ~ 0xFF */
    unsigned char *cur;
  
    /* fill the map with -1 */
    for(i = 0; i < num_of_char; i++) {
        map[i] = -1;
    }
    
    i = 0;
    len = max_len = 0;
    new_start = 0;
    cur = (unsigned char *)s;
    while((*cur) != 0) {
        
        /* 
         *  Search from the position pointed by "cur" 
         *  until encountering a repeating character
         */
        while((map[*cur] == -1) || (map[*cur] < new_start)) {
            if(*cur == 0) {
                break;
            }
            
            map[*cur] = i;
            len++;
            cur++;
            i++;
        }
        
        if(len > max_len) {
            max_len = len;
        }

        if (*cur != 0) {
            /* map[*cur] store the index of the first repeating character */
            len = (cur - (unsigned char *)s) - map[*cur] - 1;
            new_start = map[*cur] + 1;
            map[*cur] = -1;
        } else {
            break;
        }
    }
    
    return max_len;
}

/*
 * 
 */
int main(int argc, char** argv) {

    lengthOfLongestSubstring("abba");
    
    return (EXIT_SUCCESS);
}

