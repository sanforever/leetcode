/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   main.c
 * Author: San-NB
 *
 * Created on 2017年6月2日, 上午 12:37
 */

#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <limits.h>

/*
 "+-2" => 0
 "    10522545459" => 2147483647
 "2147483648" => 2147483647
 */
int myAtoi(char* str) {
    long long ans;
    int i, sign;
    char tmp;
    
    i = ans = 0;
    sign = 1;

    /* skip space */
    while(isspace(str[i])) {
        i++;
    }
    
    /* +, -, or nothing */
    if(str[i] == '-') {
        sign = -1;
        i++;
    } else if(str[i] == '+') {
        sign = 1;
        i++;
    }

    while (isdigit(str[i])) {
        tmp = str[i];
        i++;
        
        ans = ans * 10 + (tmp - '0') * sign;
        
        /* overflow */
        if (sign > 0 && ans > INT_MAX) {
            return INT_MAX;
        } else if(sign < 0 && ans < INT_MIN) {
            return INT_MIN;
        }
    }
    
    return (int)ans;
}

/*
 * 
 */
int main(int argc, char** argv) {
    int ans;
    
    ans = myAtoi("2147483648");
    ans = myAtoi("    10522545459");
    ans = myAtoi("+-2");
    printf("%d\n", ans);
    
    return (EXIT_SUCCESS);
}

