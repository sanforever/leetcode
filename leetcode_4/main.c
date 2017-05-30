/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   main.c
 * Author: San-NB
 *
 * Created on 2017年5月25日, 上午 12:45
 */

#include <stdio.h>
#include <stdlib.h>

/*
Example 1:
nums1 = [1, 3]
nums2 = [2]

The median is 2.0
Example 2:
nums1 = [1, 2]
nums2 = [3, 4]

The median is (2 + 3)/2 = 2.5
 */

#define MAX(a,b) (((a)>(b))?(a):(b))
#define MIN(a,b) (((a)<(b))?(a):(b))

double findMedianSortedArrays(int* nums1, int nums1Size, int* nums2, int nums2Size) {

    /* Always make the first array have a smaller size of array */
    if(nums1Size > nums2Size) {
        return findMedianSortedArrays(nums2, nums2Size, nums1, nums1Size);
    }
    
    /* Case 1: [], [odd elements] */
    if(nums1Size == 0 && (nums2Size % 2 == 1)) {
        return nums2[nums2Size / 2];
    }
    
    /* Case 2: [], [even elements] */
    if(nums1Size == 0 && (nums2Size % 2 == 0)) {
        return (double)(nums2[nums2Size / 2 - 1] + nums2[nums2Size / 2]) / 2;
    }
    
    /* Case 3: [a0], [b0] */
    if(nums1Size == 1 && nums2Size == 1) {
        return (double)(nums1[0] + nums2[0]) / 2;
    }
    
    /* Case 4: [a0], [even elements] */
    if(nums1Size == 1 && (nums2Size % 2 == 0)) {
        return MIN(MAX(nums1[0], nums2[nums2Size / 2 - 1]), nums2[nums2Size / 2]);
    }
    
    /* Case 5: [a0], [odd elements and size > 1] */
    if(nums1Size == 1 && (nums2Size % 2 == 1)) {
        if(nums1[0] >= nums2[nums2Size / 2 - 1] && nums1[0] <= nums2[nums2Size / 2 + 1]) {
            return (double)(nums1[0] + nums2[nums2Size / 2]) / 2;
        } else if(nums1[0] < nums2[nums2Size / 2 - 1]) {
            return (double)(nums2[nums2Size / 2 - 1] + nums2[nums2Size / 2]) / 2;
        } else if(nums1[0] > nums2[nums2Size / 2 + 1]) {
            return (double)(nums2[nums2Size / 2] + nums2[nums2Size / 2 + 1]) / 2;
        }
    }
    
    /* Case 6: [a0, a1], [b0, b1] */
    if(nums1Size == 2 && nums2Size == 2) {
        return (double)(MAX(nums1[0], nums2[0]) + MIN(nums1[1], nums2[1])) / 2;
    }

    /* Case 7: [a0, a1], [even elements and size > =4] */
    if(nums1Size == 2 && (nums2Size % 2 == 0)) {
        if(nums1[0] >= nums2[nums2Size / 2 - 1] && nums1[0] <= nums2[nums2Size / 2] && \
           nums1[1] >= nums2[nums2Size / 2 - 1] && nums1[1] <= nums2[nums2Size / 2]) {
            return (double)(nums1[0] + nums1[1]) / 2;
        }
    }
        
    /* Remaining cases: compare median */
    double m1, m2;
    int reduce;
    if(nums1Size % 2 == 1) {
        m1 = nums1[nums1Size / 2];
    } else {
        m1 = (double)(nums1[nums1Size / 2 - 1] + nums1[nums1Size / 2]) / 2;
    }
    if(nums2Size % 2 == 1) {
        m2 = nums2[nums2Size / 2];
    } else {
        m2 = (double)(nums2[nums2Size / 2 - 1] + nums2[nums2Size / 2]) / 2;
    }
    
    reduce = nums1Size / 2 - 1;
    reduce = (reduce < 1)?1:reduce;
    if(m1 == m2) {
        return m1;
    } else if(m1 > m2) {
        return findMedianSortedArrays(nums1, nums1Size - reduce, \
                                nums2 + reduce, nums2Size - reduce);
    } else {
        return findMedianSortedArrays(nums1 + reduce, nums1Size - reduce, \
                                nums2, nums2Size - reduce);
    }
    
    /* impossible path */
    return 0;
}

/*
 * 
 */
int main(int argc, char** argv) {

    int array1[] = {1, 2, 6, 7};
    int array2[] = {3, 4, 5, 8};
    double ans;
    
    ans = findMedianSortedArrays(array1, sizeof(array1) / sizeof(int), \
            array2, sizeof(array2) / sizeof(int));
    printf("%f\n", ans);
    
    return (EXIT_SUCCESS);
}

