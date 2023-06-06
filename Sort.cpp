#include "Sort.h"
#include <stdio.h>
int Quick_Sort(int A[], int low, int high)
{
    if (low < high)
    {
        int mid = Partition(A, low, high);
        Quick_Sort(A, low, mid-1);
        Quick_Sort(A, mid+1, high);
        return 1;
    }
}

int Partition(int A[], int low, int high)
{
    int key = A[low];A[low] = 0;    //记录数轴
    int i = low, j = high;          
    while (i < j)       
    {
        while(A[j] >= key && j > i)//从左向寻找一个小于key的元素
            j--;                    
        A[i] = A[j];
        while (A[i] < key && j > i)//右向寻找一个大于于key的元素
            i++;
        A[j] = A[i];
    }
    A[i] = key;
    return i;
}