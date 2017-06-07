/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   main.c
 * Author: San-NB
 *
 * Created on 2017年6月7日, 下午 11:19
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char* intToRoman(int num) {
    int i = 0, div = 100, len = 0;
    int offset;
    char *ans = (char *)malloc(sizeof(char) * 32);
    const char *str_ones_tens_hundrers[][9] = {
        {"C", "CC", "CCC", "CD", "D", "DC", "DCC", "DCCC", "CM"},
        {"X", "XX", "XXX", "XL", "L", "LX", "LXX", "LXXX", "XC"},
        {"I", "II", "III", "IV", "V", "VI", "VII", "VIII", "IX"},
    };
    const char *str_thousands[] = {"M", "MM", "MMM"};
    
    if(num / 1000 != 0) {
        strcpy(ans, str_thousands[num / 1000 - 1]);
        len += strlen(str_thousands[num / 1000 - 1]);
    }
    
    while(div != 0) {
        offset = (num / div) % 10;
        if(offset != 0) {
            strcpy(ans + len, str_ones_tens_hundrers[i][offset - 1]);
            len += strlen(str_ones_tens_hundrers[i][offset - 1]);
        }
        i++;
        div /= 10;
    }
    
    return ans;
}

/*
 * 
 */
int main(int argc, char** argv) {
    int i;
    for(i = 1; i < 4000; i++) {
        printf("%d => %s\n", i, intToRoman(i));
    }

    return (EXIT_SUCCESS);
}

