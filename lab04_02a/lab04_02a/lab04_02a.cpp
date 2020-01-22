//
//  main.cpp
//  lab04_02a
//
//  Created by Hanlin Cheng on 2019-10-17.
//  Copyright © 2019 Hanlin Cheng. All rights reserved.
//

#include <iostream>
#include <string>
#include <cstdlib>
#include <vector>
#include <stdio.h>
#include <stdlib.h>
#include <bits/stdc++.h> 

void combinationUtil(std::vector <int> set, std::vector <int> &subset_three, int start, int end, int index, int subset_size);

int compare (const void * a, const void * b)
{
    return ( *(int*)a - *(int*)b );
    
}



/*
void check_three_subsets (std::vector <int> set, int size, int subset_size, int index, std::vector <int> &subset_three, int i){
   
  
    // Current combination is ready, print it
    if (index == subset_size) {
        for (int j = 0; j < subset_size; j++)
            printf("%d ", subset_three.at(j));
        printf("\n");
        return;
    }
    
    // When no more elements are there to put in data[]
    if (i >= size)
        return;
    
    // current is included, put next at next location
    subset_three.at(index) = set.at(i);
    check_three_subsets(set, size, 3, index + 1, subset_three, i + 1);
    
    // current is excluded, replace it with next
    // (Note that i+1 is passed, but index is not
    // changed)
    check_three_subsets(set, size, 3, index, subset_three, i + 1);
    
    
}*/

 

void printCombination(std::vector <int> &set, int size, int subset_size)
{
    // A temporary array to store all combination one by one
    std::vector <int> subset_three (subset_size);
    
    
    // Sort array to handle duplicates
    sort(set.begin(), set.end());
    
    // Print all combination using temprary array 'data[]'
    combinationUtil(set, subset_three, 0, size-1, 0, subset_size);
}

void combinationUtil(std::vector <int> set, std::vector <int> &subset_three, int start, int end, int index, int subset_size)
{
    // Current combination is ready to be printed, print it
    if (index == subset_size)
    {
        for (int i=0; i<subset_size; i++)
            printf("%d " ,subset_three.at(i));
        printf("\n");
        return;
    }
    
    // replace index with all possible elements. The condition
    // "end-i+1 >= r-index" makes sure that including one element
    // at index will make a combination with remaining elements
    // at remaining positions
    for (int i=start; i<=end && end-i+1 >= subset_size-index; i++)
    {
       subset_three.at(index) = set.at(i);
        combinationUtil(set, subset_three, i+1, end, index+1, subset_size);
        
        
        // Remove duplicates
        while (set.at(i) == set.at(i+1))
            i++;
    }
}
/*
void printCombination(int arr[], int n, int r)
{
    // A temporary array to store all combination
    // one by one
    int data[r];
    
    // Print all combination using temprary array 'data[]'
    combinationUtil(arr, n, r, 0, data, 0);
}

 arr[]  ---> Input Array
 n      ---> Size of input array
 r      ---> Size of a combination to be printed
 index  ---> Current index in data[]
 data[] ---> Temporary array to store current combination
 i      ---> index of current element in arr[]     */
bool find_target_integer_subsets () {
    int n;
    int temp;
    int product;
    std::cout << "How many values are in your given set?" << std::endl;
    std::cin >> n;
    std::vector <int> set (n);
    std::cout << "Please enter the numbers in your set, press ENTER after each value: " << std::endl;
    for (int i = 0; i < set.size(); i++) {
        std::cin >> temp;
        set.at(i) = temp;
    }
    std::cout << "Your set of values are: " << std::endl;
    for (int j = 0; j < set.size(); j++) {
        std::cout << set.at(j) << "  " ;
    }
    std::cout << "What is your target product? " << std::endl;
    std::cin >> product;
    
    std::vector<int> subset_three(3);
    int r = 3;
    printCombination(set, n, r);
    
    
    
    return true;
}
int main(int argc, const char * argv[]) {
    
    if(find_target_integer_subsets()) {
        std::cout << " " << std::endl;
        std::cout << "Finding target integer subsets compeleted." << std::endl;
    }
    
    return 0;
}
