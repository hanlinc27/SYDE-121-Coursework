/*
Author: Hanlin Cheng
Student Number: 20830973
Date: 09/22/2019
Course: SYDE 121
Instructor: A. Chung
Lab Room: CPH 1346
Lab Number, Assignment Number: 04, 02a
*/


#include <iostream>
#include <string>
#include <cstdlib>
#include <vector>
#include <stdio.h>
#include <stdlib.h>

int compare (const void * a, const void * b);
/*
Purpose: Used by the built in quicksort function in order to compare elements to know whether or not one is greater
than the other in an array. There are void pointers to the elements (casting to integer in this case) (dereferenced) 
Input: Two values, a and b
Output: It gives a negative value if a is before b, a positive value if b is supposed to come before a, and zero if the
two values are equal. 
*/
void sort_set(int set[], int size, int subset_size,int product);
/*
Purpose: To declare the subset array in which each of the subsets will then be created from and then running the finding all
subsets function. It also sorts the original array before finding subsets. 
Input: The initial array, the initial array size, the subset size you wish to create, and the target product. 
Output: Modifying the original set so that it's sorted. 
*/
void check_subsets(int set [], int subset[], int start, int end, int index, int subset_size, int product);
/*
Purpose: To To find all subsets (of size subset_size) given a sorted array. Uses recursion. 
Input: The original array, a subset array to store values in (continuously overwritten), the start and end of the arrays.
Output: All the subsets of a given size for the sorted array. Each of the subsets are printed on one line. 
*/
bool find_target_integer_subsets ();    
/*
Purpose: to run the finding subsets that are valid simulation. It calls on the sort_set function which begins the process of
finding valid subsets for the given size. 
Input: The program does not pass in any values but it asks user input for how many values are in the set, which values
they are, and the target product. 
Output: The valid subsets of size two and size three. 
*/

int main(int argc, const char * argv[]) {

    //Return zero if target simulation ran successfully 
    if(find_target_integer_subsets()) {
        std::cout << " " << std::endl;
        std::cout << "Finding target integer subsets compeleted." << std::endl;
    }

    return 0;
}



int compare (const void *a, const void *b)
{
    //comparing the a and b via difference
    return ( *(int*)a - *(int*)b );

}


void sort_set(int set[], int size, int subset_size,int product)
{
    //Create an integer subset (size two or three as appropriate)
    int subset [subset_size];


    //sort the original set of values
     qsort (set, size, sizeof(int), compare);

   //Call check_subsets to find all subsets for the set of the given size and storing it in subset each time
    check_subsets(set, subset, 0, size-1, 0, subset_size, product);
}

void check_subsets(int set [], int subset[], int start, int end, int index, int subset_size, int product)
{

    //similar to first part of lab, thinking of it as a pointer to increment along the indices 
    //if the index is equal to the subset size
    if (index == subset_size)
    {
        //set target to check if the product matches later on
        int target = 1;
        //Find the target for the given subset
        for (int i=0; i<subset_size; i++) {

        target = target*subset[i];
        }
        //If the target is equal to the product, print out the product
        if (target == product){
            for (int t = 0; t<subset_size; t++){
               std::cout << subset[t] << " " ;

            }
            std::cout << " " << std::endl;
        }

        return;
    }


    //This is a recursive for loop to iterate through the set
    for (int i = start; i <= end && end-i+1 >= subset_size-index; i++)
    {
        //the subset is copied from the original set
       subset[index] = set[i];
       //checking for the subsets recursively
        check_subsets(set, subset, i+1, end, index+1, subset_size, product);


        //Utilized to remove duplicates for the subsets
        while (set[i]== set[i+1])
            i++;
    }
}

bool find_target_integer_subsets () {
    int n; //size of the set
    int temp; //for each value in the set
    int product; //the target product
    //Ask users for how many values
    std::cout << "How many values are in your given set?" << std::endl;
    std::cin >> n;
    int set [n]; //create the set according to size
    std::cout << "Please enter the numbers in your set, press ENTER after each value: " << std::endl;
    //Iterate through the set to add in values from user
    for (int i = 0; i < n; i++) {
        std::cin >> temp;
        set[i] = temp;
    }
    //Echo the values back 
    std::cout << "Your set of values are: " << std::endl;
    for (int j = 0; j < n; j++) {
        std::cout << set[j] << "  " ;
    }
    std::cout << " " << std::endl;
    //Ask for the target product
    std::cout << "What is your target product? " << std::endl;
    std::cin >> product;


    //Find valid subsets of size 3
    int subset_size = 3;
    std::cout << "The subsets of size three that work are : " << std::endl;
    sort_set(set, n, subset_size, product);
    //Find valid subsets of size 2
    subset_size = 2;
    std::cout << "The subsets of size two that work are : " << std::endl;
     sort_set(set, n, subset_size, product);
    return true;
}

