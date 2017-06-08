/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   main.c
 * Author: San-NB
 *
 * Created on 2017年6月9日, 上午 12:15
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char* longestCommonPrefix(char** strs, int strsSize) {
    int i, end;
    char c;
    
    if(strsSize == 0) {
        return "";
    }
    
    end = 0;
    c = strs[0][end];
    while (c != 0) {
        for (i = 1; i < strsSize; i++) {
            if(strs[i][end] != c) {
                break;
            }
        }
        if(i != strsSize) {
            break;
        }
        end++;
        c = strs[0][end];
    }
    strs[0][end] = 0;
    return strs[0];
}

/*
 * 
 */
int main(int argc, char** argv) {
    char **strs;
    int i;
    
    strs = (char **)malloc(sizeof(char *) * 5);
    for(i = 0; i < 5; i++) {
        strs[i] = (char *)malloc(sizeof(char) * 3);
    }
    
    strcpy(strs[0], "ab");
    strcpy(strs[1], "ab");
    strcpy(strs[2], "ab");
    strcpy(strs[3], "ab");
    strcpy(strs[4], "ab");
    
    printf("%s\n", longestCommonPrefix(strs, 5));

    for (i = 0; i < 5; i++) {
        free(strs[i]);
    }
    free(strs);
    
    return (EXIT_SUCCESS);
}

