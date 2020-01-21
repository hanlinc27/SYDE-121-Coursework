//
//  lab01_01
//  Prof. Audrey Chung
//  Created by Hanlin Cheng on 2019-09-13.
//  Copyright © 2019 Hanlin Cheng. All rights reserved.
//
/*
 *
 Author: Hanlin Cheng
 Student Number: 20830973
 Date: 09/13/2019
 Course: SYDE 121
 Instructor: A. Chung
 Lab Room: CPH 1346
 Lab Number, Assignment Number: 01, 01
 */
 
 
 /*
 To test values for the program:
 Utilized the 1048 sample case as well as the boundary points.
 Since the initial weight is stored as a 32 bit integer, the maximum value can be 2,147,483,647 kg and the minimum is 0 kg. These boundaries are the test cases that were used for weight_given.
        Thus, the valid range for which the program will work is from 0kg to 2147483647 kg.
 */
/*
 Screen Output
 
 Please enter the initial weight:
 1048
 Weight entered is : 1048
 Number of 150 weights: 6
 Number of 50 weights: 2
 Number of 30 weights: 1
 Nmber of 15 weights: 1
 Number of 1 weights: 3
 Program ended with exit code: 0
 */

//Test Case with Maximum Value
/*
 Please enter the initial weight:
 2147483647
 Weight entered is : 2147483647lbs
 Number of 150 weights: 14316557
 Number of 50 weights: 1
 Number of 30 weights: 1
 Nmber of 15 weights: 1
 Number of 1 weights: 2
 Program ended with exit code: 0
 */

//Demonstrates that it conforms to theory where the max value that can be stored in a 32 bit integer
/*
//The logic of how this program should operate is:
// accept weight from user
 - compute amount of weights of each mass to match
 - output answer to screen
 
 
 
 */
#include <iostream>

int main(int argc, const char * argv[]) {
   
    //declare variables
    int weight_given;   // initial object weight (kg)
    int weights150;     // number of 150 kg weights
    int weights50;      // number of 50 kg weights
    int weights30;      // number of 30 kg weights
    int weights15;      // number of 15 kg weights
    int weights1;       // number of 1 kg weights
    int remaining_amt;  // variable to store the remaining amount of weights to be matched (kg)

   //get input from user
    std::cout << "Please enter the initial weight: " << std::endl;
    std::cin >> weight_given;
    
    //output result to screen
    std::cout << "Weight entered is : " << weight_given << "lbs " << std::endl;
    
    //compute the amount of weights needed for each mass
    weights150 = weight_given/150;
    remaining_amt = weight_given%150;
    weights50 = remaining_amt/50;
    remaining_amt = remaining_amt%50;
    weights30 = remaining_amt/30;
    remaining_amt = remaining_amt%30;
    weights15 = remaining_amt/15;
    remaining_amt = remaining_amt%15;
    weights1 = remaining_amt;
    
    //output amount of each weight to screen
    std::cout << "Number of 150 weights: " << weights150 << std::endl;
    std::cout << "Number of 50 weights: " <<weights50 << std::endl;
    std::cout << "Number of 30 weights: " <<weights30 << std::endl;
    std::cout << "Nmber of 15 weights: " <<weights15<< std::endl;
    std::cout << "Number of 1 weights: " <<weights1  << std::endl;
    
    
    return 0;
}
