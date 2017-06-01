/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   main.c
 * Author: San-NB
 *
 * Created on 2017年6月1日, 下午 11:47
 */

#include <stdio.h>
#include <stdlib.h>

/*
Example1: x = 123, return 321
Example2: x = -123, return -321
 "The input is assumed to be a 32-bit signed integer. Your function should return 0 when the reversed integer overflows."
*/
int reverse(int x) {
    long long ans = 0;
    
    while(x != 0) {
        ans = ans * 10 + (x % 10);
        x /= 10;
    }
    
    if((ans > 2147483647) || (ans < -2147483648)) {
        ans = 0;
    }
    
    return (int)ans;
}

/*
 * 
 */
int main(int argc, char** argv) {
    int ans;
    ans = reverse(1000000003);
    printf("%d\n", ans);
    
    return (EXIT_SUCCESS);
}

