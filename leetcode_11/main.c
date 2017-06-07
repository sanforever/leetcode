/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   main.c
 * Author: San-NB
 *
 * Created on 2017年6月6日, 下午 11:56
 */

#include <stdio.h>
#include <stdlib.h>

#define MIN(a,b) (((a)<(b))?(a):(b))
int maxArea(int* height, int heightSize) {
    int i, j;
    int area, max_area, max_end;
    int find_larger, next;
    // {9, 6, 14, 11, 2, 2, 4, 9, 3, 8};
    max_area = 0;
    for(i = 0; i < heightSize - 1; i++) {
        find_larger = max_end = 0;
        for(j = i + 1; j < heightSize; j++) {
            area = (j - i) * MIN(height[i], height[j]);
            if(area > max_area) {
                max_end = j;
                max_area = area;
            }
            
            /* Find the first aj, which is larger than ai*/
            if(find_larger == 0 && height[j] > height[i]) {
                find_larger = 1;
                next = j - 1;
            }
        }
        
        if(max_end == 0 && find_larger == 0) {
            break;
        } else if(find_larger == 0) {
            i = max_end - 1;
        } else if(find_larger == 1) {
            i = next;
        }
    }
    
    return max_area;
}

/*
 * 
 */
int main(int argc, char** argv) {
    //int height_array[] = {3, 1, 9, 2, 1, 8, 0, 6};
    //int height_array[] = {10, 9, 8, 7, 6, 5, 4, 3, 2, 1};
    //int height_array[] = {2, 3, 4, 5, 18, 17, 6};
    int height_array[] = {9, 6, 14, 11, 2, 2, 4, 9, 3, 8};
    printf("%d\n", maxArea(height_array, sizeof(height_array) / sizeof(int)));
    
    return (EXIT_SUCCESS);
}

