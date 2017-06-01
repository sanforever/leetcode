/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   main.c
 * Author: San-NB
 *
 * Created on 2017年6月1日, 下午 11:09
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char* convert(char* s, int numRows) {
    int n = strlen(s);
    int i, next, row, offset;
    char *ans;
    char flag;
    
    if(numRows == 1) {
        return s;
    }
    
    ans = (char *)malloc(sizeof(char) * (n + 1));
    ans[n] = 0;
    i = 0;  /* index of next-output character */
    
    for(row = 0; row < numRows; row++) {
        next = row;
        flag = 0;
        while(next < n) {
            ans[i] = s[next];
            i++;
            
            /* Calculate the index of next-output */
            if(flag == 0) {
                offset = 2 * (numRows - row) - 2;
            } else {
                offset = 2 * (row + 1) - 2;
            }
            
            if(offset == 0) {
                i--;
            }
            
            next += offset;
            flag = !flag;
        }
        
    }

    return ans;
}

/*
 * 
 */
int main(int argc, char** argv) {

    printf("%s\n", convert("0123456789", 2));
    
    return (EXIT_SUCCESS);
}

