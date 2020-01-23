/*
 Author: Hanlin Cheng
 Student Number: 20830973
 Date: 11/12/2019
 Course: SYDE 121
 Instructor: A.Chung
 Lab Room: CPH 1346
 Lab Number, Assignment Number: 06, 02
 */


/*
 To test the program, I ran a variety of different simulations by having substrings located at different places
 in the string and also varying the length and number of spaces that are existent inside of my string.
 */
#include <iostream>
#include <string.h>
#include <cstring>
#include <stdio.h>
#include <stdlib.h>

bool check_if_contains(std::string &target, std::string &substr);
/*
 Purpose: To check if a substring is contained inside of a specific string. It does so through a base case and
 recursive calls to itself.
 Input: The inputs to this function are the target substring and the substring, both were user entered from an earlier
 function.
 Output: It outputs true or false regarding if a specific substring is contained inside of a string.
 */
void user_input(std::string &target, std::string &substr);
/*
 Purpose: To obtain the values of the target string and the substring as determined by the user.
 Input: The target string and substring are pushed in as parameters of the function.
 Output: There is no output, it is a void function.
*/

int main(int argc, const char * argv[]) {
    //Declare string variables for the target and the substring
    std::string target, substr;
    //Call for user input
    user_input(target, substr);
    
    //Print out whether or not the substring is contained inside of the string and check for substring length
    if (substr.length() < target.length()) {
    if (check_if_contains(target, substr)){
        std::cout << "The substring exists inside of the target string." <<std::endl;
    }
    else {
        std::cout << "The substring does not exist in the target string." << std::endl;
    }
    }
    else {
        std::cout << "Substring must be shorter than target string" <<std::endl;
    }
}

bool check_if_contains(std::string &target, std::string &substr) {
   
    //create a temporary string variable to manipulate target with
    std::string temp = target;
   
    //section off, starting from the front, the part of target that is the same length as substring
    temp.erase(substr.length(), target.length()-substr.length());
    
    //base case, if the substring equals the temporary string
    if (substr == temp)
    {
        return true;
    }
    //if the target string is still longer than the substring
    else if (target.length() > substr.length())
    {
        //keep erasing the front of the target string
        target.erase(0, 1);
    
        //call the function recursively to see if the new cut word is equal to the substring
       return check_if_contains(target, substr);
    }
    return false;
}

void user_input(std::string &target, std::string &substr) {
    
    //ask for user input for the target string
    std::cout << "What is your target string?" << std::endl;
    //use get line to account for spaces
    getline(std::cin,target);
    
    //ask the user for the target substring
    std::cout << "What is your target substring?" << std::endl;
    getline(std::cin, substr);
    
}



