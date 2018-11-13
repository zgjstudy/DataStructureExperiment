// Cinkye 2018.11.9 201730684427
// Experiment 3
// A file with many sorting functions and their testbench       sort.cpp

#include <iostream>
#include <ctime>
#include <stdlib.h>
#include <iomanip>
#include "heap.h"
#include <cmath>

#define NUMS 518959

using namespace std;

void insSort(int* nums,int size)
{
    for (int i = 0;i < size;++i)
    {
        for(int j = i+1;j > 0;--j)
        {
            if(nums[j] < nums[j-1])
            {
                int tmp = nums[j];
                nums[j] = nums[j-1];
                nums[j-1] = tmp;
            }
            else break;
        }
    }
}

void selectionSort(int* nums,int size)
{
    for(int i = 0;i < size;++i)
    {
        int min = i;
        for(int j = i;j < size;++j)
        {
            if(nums[j]<nums[min])
                min = j;
        }
        int tmp = nums[min];
        nums[min] = nums[i];
        nums[i] = tmp;
    }
}

void bubbleSort(int* nums,int size)
{
    for(int i = 0;i < size;++i)
    {
        for(int j = size-1;j > i;--j)
        {
            if(nums[j] < nums[j-1])
            {
                int tmp = nums[j];
                nums[j] = nums[j-1];
                nums[j-1] = tmp;
            }
        }
    }
}

void shellHelp(int* nums,int size,int gap)
{
    for(int i = gap;i < size;i += gap)
    {
        for(int j = i;j >= gap;--j)
        {
            if(nums[j]<nums[j-gap])
            {
                int tmp = nums[j];
                nums[j] = nums[j-gap];
                nums[j-gap] = tmp;
            }
            else break;
        }
    }
}

void ShellSort(int* nums,int size)
{
    for(int i = size / 2;i > 2 ;i /= 2)
    {
        for(int j = 0;j < i;++j)
            shellHelp(&nums[j],size-j,i);
    }
    shellHelp(nums,size,1);
}

void mergeSort(int* nums,int* temp,int left,int right)
{
    if(left == right)   return;
    int mid = (left + right) / 2;
    mergeSort(nums,temp,left,mid);
    mergeSort(nums,temp,mid+1,right);
    for(int i = left;i<=right;++i)
        temp[i] = nums[i];
    int l = left,r = mid + 1;
    for(int curr = left;curr <= right;++curr)
    {
        if(l == mid+1)
            nums[curr] = temp[r++];
        else if(r > right)
            nums[curr] = temp[l++];
        else if(temp[l] < temp[r])
            nums[curr] = temp[l++];
        else
            nums[curr] = temp[r++];
    }
}

void quickSort(int* nums,int left,int right)
{
    if(right - left <= 9)
    {
        insSort(&nums[left],right - left);
        return;
    }
    int pivotIndex = (left + right) / 2;
    // Swap pivot to the end
    int tmp = nums[pivotIndex];
    nums[pivotIndex] = nums[right];
    nums[right] = tmp;
    int l = left;
    int r = right - 1;
    while(l < r)
    {
        if(nums[r] < nums[right])
        {
            if(nums[l] > nums[right])
            {
               tmp = nums[r];
               nums[r] = nums[l];
               nums[l] = tmp;
               l++;
               r--;
            }
            else
               l++;
        }
        else
           r--;
   }
    quickSort(nums,left,l);
    quickSort(nums,l+1,right);
}

void heapSort(int* nums,int size)
{
    int max;
    heap<int> h(nums,size,size);
    for(int i = 0;i < size;++i)
        max = h.removefirst();
}


void radix(int A[], int B[], int n, int k, int r, int cnt[]) {
  // cnt[i] stores number of records in bin[i]
  int j;

  for (int i=0, rtoi=1; i<k; i++, rtoi*=r) { // For k digits
    for (j=0; j<r; j++) cnt[j] = 0;        // Initialize cnt

    // Count the number of records for each bin on this pass
    for (j=0; j<n; j++) cnt[(A[j]/rtoi)%r]++;

    // // Index B: cnt[j] will be index for last slot of bin j.
    for (j=1; j<r; j++) cnt[j] = cnt[j-1] + cnt[j];

    // // Put records into bins, work from bottom of each bin.
    // // Since bins fill from bottom, j counts downwards
    for (j=n-1; j>=0; j--)
      B[--cnt[(A[j]/rtoi)%r]] = A[j];

    for (j=0; j<n; j++) A[j] = B[j];    // Copy B back to A
  }
}



int main()
{
    cout << "Data size is " << NUMS << endl << endl;
    int* d = new int[10000000];
    int* tmp = new int[10000000];
    srand((int)time(0));
    for(int i = 0;i < NUMS;++i)
        tmp[i] = d[i] = ((int)(rand()*rand()%3000000))/100.0;
    int select = 0;
    for(;select <= 7;++select)
    {
        for(int i = 0;i < NUMS;++i)
            d[i] = tmp[i];
        clock_t start = clock();
        switch(select)
        {
        case 0:
            {
                cout << "Doing InsertionSort....." << endl;
                insSort(d,NUMS);
                break;
            }
        case 1:
            {
                cout << "Doing BubbleSort....." << endl;
                bubbleSort(d,NUMS);
                break;
            }
        case 2:
            {
                cout << "Doing selectionSort....." << endl;
                selectionSort(d,NUMS);
                break;
            }
        case 3:
            {
                cout << "Doing ShellSort....." << endl;
                ShellSort(d,NUMS);
                break;
            }
        case 4:
            {
                cout << "Doing mergeSort....." << endl;
                int temp[NUMS];
                mergeSort(d,temp,0,NUMS);
                break;
            }
        case 5:
            {
                cout << "Doing quickSort......" << endl;
                quickSort(d,0,NUMS-1);
                break;
            }
        case 6:
            {
                cout << "Doing heapSort......" << endl;
                heapSort(d,NUMS);
                break;
            }
        case 7:
            {
                cout << "Doing radixSort....." << endl;
                int* temp = new int[NUMS];
                int cnt[10];
                radix(d,temp,NUMS,log10(NUMS)+1,10,cnt);
                delete []temp;
            }
        }
        clock_t end = clock();
        cout << "Time it takes is " << (double)(end - start)/(double)CLOCKS_PER_SEC*1000.0 << " ms." << endl << endl;
    }
    delete []d;
    delete []tmp;
//    codes for outputting the array
//    int count = 1;
//    for(int i = 0;i < 10000;++i)
//    {
//        cout << fixed << setprecision(2) << setw(8) << d[i] << " ";
//        if(count != 10)
//            ++count;
//        else
//        {
//            count = 1;
//            cout << endl;
//        }
//    }


}
