/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   main.c
 * Author: San-NB
 *
 * Created on 2017年6月5日, 下午 8:48
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef char bool;
#define true	1
#define	false	0

bool isMatch(char* s, char* p) {
    int i, j;
    int len_s, len_p;
    char **match;
    bool ans = false;
    
    len_s = strlen(s);
    len_p = strlen(p);
 
    /*
     *      if s0...si match p0...pj
     *      match[i + 1][j + 1] == true
     */
    match = (char **)malloc(sizeof(char *) * (len_s + 1));
    for(i = 0; i < len_s + 1; i++) {
        match[i] = (char *)malloc(sizeof(char) * (len_p + 1));
    }
    
    /* Empty string matches empty pattern */
    match[0][0] = true;
    
    /* Fill-in the first column */
    for(i = 1; i < len_s + 1; i++) {
        match[i][0] = false;
    }
    
    /* Finn-in the fistt row */
    for(i = 1; i < len_p + 1; i++) {
        match[0][i] = false;
        if(i > 1 && p[i - 1] == '*') {
            match[0][i] = match[0][i - 2];
        }        
    }
    
    for(i = 0; i < len_s; i++) {
        for(j = 0; j < len_p; j++) {
            match[i + 1][j + 1] = false;
            if((s[i] == p[j]) || (p[j] == '.')) {
                match[i + 1][j + 1] = match[i][j];
            } else if(p[j] == '*') {
                if(j > 0) {
                    match[i + 1][j + 1] = match[i + 1][j - 1];
                    if(match[i + 1][j + 1] == true) {
                        continue;
                    }
                }

                if(match[i + 1][j] == true) {
                    match[i + 1][j + 1] = true;
                    continue;
                }
                
                if((s[i] == p[j - 1]) || p[j - 1] == '.') {
                    match[i + 1][j + 1] = match[i][j + 1];
                    if(match[i + 1][j + 1] == true) {
                        continue;
                    }                    
                }
            }
        }
    }
    
    ans = match[len_s][len_p];
    
    for(i = 0; i < len_s; i++) {
        free(match[i]);
    }
    free(match);
    
    return ans;
}

/*
 * 
 */
int main(int argc, char** argv) {
    printf("%d\n", isMatch("a", ".*..a*"));
    printf("%d\n", isMatch("abcd", "d*"));
    printf("%d\n", isMatch("aa", "a"));
    printf("%d\n", isMatch("aa", "aa"));
    printf("%d\n", isMatch("aaa", "aa"));
    printf("%d\n", isMatch("aa", "a*"));
    printf("%d\n", isMatch("aa", ".*"));
    printf("%d\n", isMatch("ab", ".*"));
    printf("%d\n", isMatch("aab", "c*a*b"));
    
    return (EXIT_SUCCESS);
}

