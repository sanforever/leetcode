/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   main.c
 * Author: san
 *
 * Created on June 2, 2017, 12:25 PM
 */

#include <stdio.h>
#include <stdlib.h>

typedef char bool;
#define true	1
#define	false	0

/*
    2147483647 ~ -2147483648
  
    -2147447412 => false ???? (from leetcode's submission result)
 */
bool isPalindrome(int x) {
    int start_div, end_div;
    
    if(x < 0) {
	return false;
    }
    
    start_div = 1000000000;
    end_div = 1;
    
    /* Search for the leading number */
    while((x / start_div) == 0 && start_div > 1) {
	start_div /= 10;
    }
    
    /* Compare the MSB digit and LSB digit */
    while(((x / start_div) % 10) == ((x / end_div) % 10)) {
	start_div /= 10;
	end_div *= 10;
	
	if(end_div >= start_div) {
	    return true;
	}	
    }
    
    return false;
}

/*
 * 
 */
int main(int argc, char** argv)
{
    printf("%d\n", isPalindrome(-1331));

    return (EXIT_SUCCESS);
}

