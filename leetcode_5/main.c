/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   main.c
 * Author: san
 *
 * Created on May 31, 2017, 4:56 PM
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/*
Given a string s, find the longest palindromic substring in s. 
You may assume that the maximum length of s is 1000.

Example:
Input: "babad"
Output: "bab"
Note: "aba" is also a valid answer.

Example:
Input: "cbbd"
Output: "bb"
 */

char* longestPalindrome(char* s) {
    int i;
    int start, end;
    int max_start, max_end, max_len;
    int n;
    
    n = strlen(s);    
    max_len = -1;
    
    /* Assume tha size of a longest palindromic is odd */
    for(i = 0; i < n; i++) {
	/* Expand the currently scanned character to both directions, and check whether a palindrome is formed */	
	start = end = i;
	while(s[start] == s[end]) {
	    start--;
	    end++;
	    if(start < 0 || end == n) {
		break;
	    }
	}
	
	start++;
	end--;
	if((end - start + 1) > max_len) {
	    max_len = end - start + 1;
	    max_start = start;
	    max_end = end;
	}	
    }
            
    /* Assume tha size of a longest palindromic is even */
    for(i = 0; i < n - 1 ; i++) {	
	if(s[i] != s[i + 1]) {
	    continue;
	}
	
	start = i;
	end = i + 1;
	while(s[start] == s[end]) {
	    start--;
	    end++;
	    if(start < 0 || end == n) {
		break;
	    }
	}	

	start++;
	end--;
	if((end - start + 1) > max_len) {
	    max_len = end - start + 1;
	    max_start = start;
	    max_end = end;
	}	
    }
    
    if(max_end != n - 1) {
	s[max_end + 1] = 0;
    }
	   
    return s + max_start;
}

/*
 * 
 */
int main(int argc, char** argv)
{
    char input[] = "cbbd";
    printf("%s\n", longestPalindrome(input));

    return (EXIT_SUCCESS);
}

