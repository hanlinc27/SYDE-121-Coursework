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



void check_subsets(int set [], int subset[], int start, int end, int index, int subset_size, int product);

int compare (const void * a, const void * b)
{
    return ( *(int*)a - *(int*)b );

}


void sort_set(int set[], int size, int subset_size,int product)
{
    // A temporary array to store all combination one by one
    int subset [subset_size];


    // Sort array to handle duplicates
     qsort (set, size, sizeof(int), compare);

    // Print all combination using temprary array 'data[]'
    check_subsets(set, subset, 0, size-1, 0, subset_size, product);
}

void check_subsets(int set [], int subset[], int start, int end, int index, int subset_size, int product)
{

    if (index == subset_size)
    {

        int target = 1;
        for (int i=0; i<subset_size; i++) {

        target = target*subset[i];
        }
        if (target == product){
            for (int t = 0; t<subset_size; t++){
               std::cout << subset[t] << " " ;

            }
            std::cout << " " << std::endl;
        }

        return;
    }


    for (int i=start; i<=end && end-i+1 >= subset_size-index; i++)
    {
       subset[index] = set[i];
        check_subsets(set, subset, i+1, end, index+1, subset_size, product);


        // Remove duplicates
        while (set[i]== set[i+1])
            i++;
    }
}

bool find_target_integer_subsets () {
    int n;
    int temp;
    int product;
    std::cout << "How many values are in your given set?" << std::endl;
    std::cin >> n;
    int set [n];
    std::cout << "Please enter the numbers in your set, press ENTER after each value: " << std::endl;
    for (int i = 0; i < n; i++) {
        std::cin >> temp;
        set[i] = temp;
    }
    std::cout << "Your set of values are: " << std::endl;
    for (int j = 0; j < n; j++) {
        std::cout << set[j] << "  " ;
    }
    std::cout << " " << std::endl;
    std::cout << "What is your target product? " << std::endl;
    std::cin >> product;


    int subset_size = 3;
    std::cout << "The subsets of size three that work are : " << std::endl;
    sort_set(set, n, subset_size, product);
    subset_size = 2;
    std::cout << "The subsets of size two that work are : " << std::endl;
     sort_set(set, n, subset_size, product);
    return true;
}
int main(int argc, const char * argv[]) {

    if(find_target_integer_subsets()) {
        std::cout << " " << std::endl;
        std::cout << "Finding target integer subsets compeleted." << std::endl;
    }

    return 0;
}
