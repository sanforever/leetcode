/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   main.c
 * Author: san
 *
 * Created on June 8, 2017, 2:35 PM
 */

#include <stdio.h>
#include <stdlib.h>

int romanCharToInt(char c)
{
    switch(c) {
        case 'I':
            return 1;
        case 'V':
            return 5;
        case 'X':
            return 10;
        case 'L':
            return 50;
        case 'C':
            return 100;
        case 'D':
            return 500;
        case 'M':
            return 1000;
        default:
            return 0;
    }
}

int romanToInt(char* s) {
    int ans = 0;
    int i = 0, cur, next;
    
    
    while(s[i] != 0) {
        cur = romanCharToInt(s[i]);
        next = romanCharToInt(s[i + 1]);
        if(cur >= next) {
            ans += cur;
        } else {
            ans -= cur;
        }
        i++;
    }
    
    return ans;
}

/*
 * 
 */
int main(int argc, char** argv) {

    printf("%d\n", romanToInt("DCCC"));
    
    return (EXIT_SUCCESS);
}

