/*
Given an array which has two arithmetic sequences and 
one geometric sequence (in any order).
Copy indexes where each sequence starts and ends into an Array and return it.

Note : Each sequence will be of atleast LENGTH 3,and The sequences can be overlapping

Ex : 1, 3, 5, 7, 2, 4, 8, 16 18 20, output is [0, 3, 7, 9, 4, 7]
Ex : 1 ,2, 4, 8, 12, 16, 21, 26     output is [2, 5, 5, 7, 0, 3]
Ex : 10 15 20 30 50 70 100 200 400 800  output is [0, 2, 3, 5, 6, 9]

The final_arr[0], final_arr[1] values in final array  
will be start and end indexes of First A.P in the Original Array

The final_arr[2], final_arr[3] values in final array  
will be start and end indexes of Second A.P 

The final_arr[4], final_arr[5] values in final array  
will be start and end indexes of First  G.P (Only)

Input: Array and Length of Array
Output : New Array which has 6 integers , which denote the (start,end) indexes .

Note : All elements in the array will be part of atleast 1 sequence .
Two A.P cannot start at same index . 

Difficulty : Medium
*/

#include <stdlib.h>
#include <stdio.h>
#include <math.h>

int * find_sequences(int *arr, int len){

	if (arr == NULL || len<0)
		return NULL;

	int *res;
	res = (int *)malloc(sizeof(int) * 7);
	int diff1 = 0, diff2 = 0,r_val=0,flag1=0,flag2=0,flag3=0;
	int flag1_end = 0, flag2_end = 0, flag3_end = 0;
	
	for (int i = 0; i < len-2; i++)
	{
		if (flag1==0 && abs(arr[i] - arr[i + 1]) == abs(arr[i + 1] - arr[i + 2]))
		{
			flag1 = 1;
			diff1 = abs(arr[i] - arr[i + 1]);
			res[0] = i;

		}
		if (flag1 == 1 && flag2 == 0 && abs(arr[i] - arr[i + 1]) == abs(arr[i + 1] - arr[i + 2]) && abs(arr[i] - arr[i + 1])!=diff1)
		{
			flag2 = 1;
			diff2 = abs(arr[i] - arr[i + 1]);
			res[2] = i;

		}
		
		if (flag3=0 && arr[i]==arr[i+1])
		{
			flag3 = 1;
			r_val = 1;
			res[4] = i;
			if (flag1 == 1 && flag2 == 0)
			{
				flag2 = 1;
				diff2 = 0;
				res[2] = i;
			}
			if (flag1 == 0 && flag2 == 0)
			{
				flag1 = 1;
				diff1 = 0;
				res[0] = i;
			}

		}

		if (flag3 == 0 && arr[i] != 0 && arr[i + 1] != 0 && arr[i + 2] != 0)
		{
			if ((arr[i + 1] / arr[i]) == (arr[i + 2] / arr[i+1]))
			{
				flag3 = 1;
				r_val = arr[i + 1] / arr[i];
				res[4] = i;
			}
		}

		if (flag3 == 1 && arr[i] != 0 && arr[i + 1] != 0 && flag3_end==0)
		{
			if ((arr[i + 1] / arr[i]) != (arr[i + 2] / arr[i + 1]))
			{
				flag3_end = 1;
				res[5] = i;
			}
		}		
		if (abs(arr[i] - arr[i + 1]) != diff1 && flag1 == 1 && flag1_end==0)
		{
			res[1] = i;
			flag1_end = 1;
		}
		if (abs(arr[i] - arr[i + 1]) != diff2 && flag2 == 1 && flag2_end == 0)
		{
			res[3] = i;
			flag2_end = 1;

		}
	}
	for (int i = 0; i < 6; i++)
		printf("%d\t", res[i]);
	return res;
}