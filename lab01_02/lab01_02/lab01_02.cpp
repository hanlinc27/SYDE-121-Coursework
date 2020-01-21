//
//  lab01_02
//  Prof. Audrey Chung
//  Created by Hanlin Cheng on 2019-09-13.
//  Copyright © 2019 Hanlin Cheng. All rights reserved.
//

 /*
  Author: Hanlin Cheng
  Student Number: 20830973
  Date: 09/13/2019
  Course: SYDE 121
  Instructor: A. Chung
  Lab Room: CPH 1346
  Lab Number, Assignment Number: 01, 02
  
  The values used to test the program logic was through entering the boundary points of acceptable values.
  Since the year it begins with is 2000, that's the leftmost boundary point, with the right going towards infinity.
  However, the max year is the max value that population can be. Since population is stored as a 64 bit float, the max value it can contain is 3.4 * 10^38. Working backwards, we then know that the max year that can be computed inside
  of the computer program is the year 6346. Thus, the range of years is 2000 to 6346. 
  
  
  Program Output:
 The population for the year : 2018 , is: 8.59998 billion people
 The population for the year : 2025 , is: 9.89233 billion people
 The population for the year : 2050 , is: 16.3097 billion people
 The population for the year : 2100 , is: 44.3343 billion people
 Program ended with exit code: 0
 */
 
 /*
  The logic of how this program works is that it should take an input year from the user,
  compute it inside of the population equation and output that value to screen
  
  */

//include necessary packages
#include <iostream>
#include <math.h> //math library

int main(int argc, const char * argv[]) {
    
    //declare variables
    int current_year; //the current year to calculate the population
    float population; //population of people (billions)
    
   //population calculations for the year 2018
    current_year = 2018;
    population = 6 * exp(0.02 * (current_year-2000));
    
    //output screen results for 2018 population
    std::cout << "The population for the year : " << current_year << " , is: " <<population<< " billion people " << std::endl;
    
    //population calculations for the year 2025
    current_year = 2025;
    population = 6 * exp(0.02 * (current_year-2000));
    
    //output screen results for 2025 population
    std::cout << "The population for the year : " << current_year << " , is: " << population <<" billion people " <<std::endl;
    
    //population calculations for the year 2050
    current_year = 2050;
    population = 6 * exp(0.02 * (current_year-2000));
    
    //output screen results for the 2050 population
    std::cout << "The population for the year : " << current_year << " , is: " <<population <<" billion people " <<std::endl;
    
    //population calculations for the year 2100
    current_year = 2100;
    population = 6 * exp(0.02 * (current_year-2000));
   
    //output screen results for the 2100 population
    std::cout << "The population for the year : " << current_year << " , is: " <<population <<" billion people " <<std::endl;
    
    //get year input from user
    std::cout << "Enter a year : ";
    std::cin >> current_year;
    
    //print output to screen
    std::cout<< "The year entered is : " <<current_year << std::endl;
    
    //calculation for the user inputted year
     population = 6 * exp(0.02 * (current_year-2000));
    
    //print population for the user inputted year
        std::cout << "The population for the year : " << current_year << " , is: " <<population <<" billion people " <<std::endl;
    
    return 0;
    
}
