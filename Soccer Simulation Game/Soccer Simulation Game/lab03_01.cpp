/*Author: Hanlin Cheng
Student Number: 20830973
Date: 10/08/2019
Course: SYDE 121
Instructor: A. Chung
Lab Room: CPH 1346
Lab Number, Assignment Number: 03 01
 
 */
/*
 Tested this code extremely thoroughly and extensively using cout statements at the end of functions in order to echo what the variables are
 */
//Include header files
#include <iostream>
#include <string>
#include <cstdlib>
#include <ctime>
#include <chrono>
#include <thread>
#include <iomanip>
void shot_on_target(std::string team_name, int& goals, int& on_goal, int& off_goal, int& blocked);
void free_kick(std::string team_name, int& goals, int& on_goal, int& off_goal, int& blocked, int&r_cards, int&y_cards);
void penalty_kick(std::string team_name, int& goals, int& on_goal, int& off_goal, int& blocked, int&r_cards, int&y_cards);

bool run_soccer_simulation ();
int main(int argc, const char * argv[]) {
    
    //run the soccer simulation
    if (run_soccer_simulation())
        std::cout << "Soccer simulation completed successfully." << std::endl;
    return 0;
}



//Shot on Target Function
/*
 Purpose: To randomly generate the shot outcome when a player from a team shoots and increment that variable for the
 specific event
 Input: The team name, the current goals, the amount on goal shots, the amount of off goal shots, blocked shots
 Output: Void (The function only performs the appropriate calculations
 */
void shot_on_target(std::string team_name, int& goals, int& on_goal, int& off_goal, int& blocked) {
   //variable declaration for shot outcome
    int shot_outcome;
    //randomly generate the shot outcome
    shot_outcome = std::rand()%4;
    
    //the outcome for when each of 0,1,2 and 3 are generated
    if (shot_outcome == 0) {
        std::cout <<  "\t" << team_name << " has scored a goal! Fantastic shot!\n\n";
        goals = goals+1;
    }
    
    else if (shot_outcome == 1) {
        std::cout << "\t" << team_name << " has shot on goal. Great save by the opposing team.\n\n";
        on_goal = on_goal + 1;
    }
    else if (shot_outcome == 2){
        std::cout << "\t" <<  team_name << " has shot off goal. Excellent attempt.\n\n";
        off_goal = off_goal + 1;
    }
    else {
        std::cout << "\t" << team_name << "'s shot was blocked. Excellent attempt.\n\n";
        blocked = blocked + 1;
    }
}
//Free Kick Function
/*
 Purpose: To randomly generate the shot outcome when a player from a team performs a free kick and increments that variable for the specific event
 Input: The team name, the current goals, the amount on goal shots, the amount of off goal shots, blocked shots, red cards and yellow cards
 Output: Void (The function only performs the appropriate calculations
 */
void free_kick(std::string team_name, int& goals, int& on_goal, int& off_goal, int& blocked, int&r_cards, int&y_cards) {
    
    //declare the variables in which the random integers will be assigned to
    int free_kick_outcome;
    int card_given;
    
    //assign the random number declarations to the appropriate variables
    free_kick_outcome = std::rand()%4;
    card_given = std::rand()%3;
  
    //outcomes for giving out cards for the fouls
    if (card_given == 0){
       
        std::cout <<" No card was given. ";
    }
    else if (card_given == 1){
        y_cards = y_cards+1;
        std::cout <<" Yellow card given. ";
    }
    else { // for when card given is equal to 2
        r_cards = r_cards+1;
        std::cout <<" Red card given. ";
        
    }
    
    //outcomes for each of the free kicks
    if (free_kick_outcome == 0) {
        std::cout << team_name << " has scored a goal! Fantastic shot!\n\n";
        goals = goals + 1;
    }
    else if (free_kick_outcome == 1){
        std::cout<< team_name << " has shot on goal. Great save by the opposing team.\n\n";
        on_goal = on_goal+1;
    }
    else if (free_kick_outcome == 2){
        std::cout  << team_name << " has shot off goal. Excellent attempt.\n\n";
        off_goal = off_goal + 1;
    }
    else { // for if free kick outcome is equal to 3
        std::cout << team_name << "'s shot was blocked. Excellent attempt.\n\n";
        blocked = blocked + 1;
    }
}
//Penalty Kick Function
/*
 Purpose: To randomly generate the shot outcome when a player from a team performs a penalty kick and increments that variable for the specific event
 Input: The team name, the current goals, the amount on goal shots, the amount of off goal shots, blocked shots, red cards and yellow cards
 Output: Void (The function only performs the appropriate calculations
 */
void penalty_kick(std::string team_name, int& goals, int& on_goal, int& off_goal, int& blocked, int&r_cards, int&y_cards) {
  
    //declare variables for the penalty kick outcome and card given outcome
    int penalty_kick_outcome;
    int card_given;
    
    penalty_kick_outcome = std::rand()%3;
    card_given = std::rand()%3;
    
    //outcome for the randomly generated cards
    if (card_given == 0){
        
        std::cout <<" No card was given. ";
    }
    else if (card_given == 1){
        y_cards = y_cards+1;
        std::cout <<" Yellow card given. ";
    }
    else { // for when card given is equal to 2
        r_cards = r_cards+1;
        std::cout <<" Red card given. ";
        
    }
    
    //print and give the outcome for each of the random possibilities for the penalty kick
    if (penalty_kick_outcome == 0) {
        std::cout << team_name << " has scored a goal! Fantastic shot!\n\n";
        goals = goals + 1;
    }
    else if (penalty_kick_outcome == 1){
        std::cout<< team_name << " has shot on goal. Great save by the opposing team.\n\n";
        on_goal = on_goal+1;
    }
    else {
        std::cout  << team_name << " has shot off goal. Excellent attempt.\n\n";
        off_goal = off_goal + 1;
   
}
}

//Run soccer simulation function
/*
 Purpose: to generate the (up to) 30 different events  in the soccer game -> with each having six different possibilities, split it up randomly, and output the statistics twice
 Input: No input entered
 Output No output generated
 */
bool run_soccer_simulation ()  {
  
    //initializing in order to add delays
    using namespace std::this_thread;     // sleep_for, sleep_until
    using namespace std::chrono_literals; // ns, us, ms, s, h, etc.
    using std::chrono::system_clock;
    
    //names of Team A and Team B
    const std::string team_a = "Team A", team_b = "Team B";
    
    //variable declarations and inititializations to zero (variable names tell us what is)
    int a_goals, b_goals, a_on_goal, b_on_goal, a_off_goal, b_off_goal;
    int a_blocked, b_blocked, a_yellow, b_yellow, a_red, b_red, no_of_events, cur_event;
    int a_fouls = 0;
    int b_fouls = 0;
    a_goals = 0;
    b_goals = 0;
    a_on_goal = 0;
    b_on_goal = 0;
    a_off_goal = 0;
    b_off_goal = 0;
    a_blocked = 0;
    b_blocked = 0;
    a_yellow = 0;
    b_yellow = 0;
    a_red = 0;
    b_red=0;
    int count = 0;

    
    //seed for the random generation
    std::srand (std::time(NULL)); // might have to move this to another location?
    
    //randomly generate 30 events
    no_of_events = std::rand() % 30 + 1;
    
    //variables for the halftime split of when to print out the statistics
    int split_1,split_2;
    

    split_1 = std::rand()%no_of_events+1;
    split_2 = no_of_events - split_1;
    
    //the output for each random event generation
    for (int i = 0; i < no_of_events; i++){
        
        //the current event for each of the events
        cur_event = std::rand()%6+1;
      
        //for if team A or B shoot on target
        if (cur_event == 1) {
            shot_on_target(team_a, a_goals, a_on_goal, a_off_goal, a_blocked);
        }
        else if (cur_event == 2){
            shot_on_target(team_b, b_goals, b_on_goal, b_off_goal, b_blocked);
        }
        
        //for if team A or B get awarded a free kick
        else if (cur_event == 3) {
            std::cout << "\t" << team_b << " has committed a foul, Team A has been awarded a free kick.";
            b_fouls = b_fouls+1;
            free_kick(team_a,  a_goals, a_on_goal, a_off_goal, a_blocked, a_red, b_yellow);
        }
        else if (cur_event == 4) {
            std::cout << "\t" << team_a << " has committed a foul, Team B has been awarded a free kick.";
            a_fouls = a_fouls+1;
            free_kick(team_b, b_goals, b_on_goal, b_off_goal, b_blocked, b_red, b_yellow);
        }
        
        //for if team A or B get awarded a penalty kick
        else if (cur_event == 5) {
            std::cout << "\t" << team_b << " has committed a foul close to the goal, Team A has been awarded a penalty kick.";
            b_fouls = b_fouls+1;
            penalty_kick(team_a,  a_goals, a_on_goal, a_off_goal, a_blocked, a_red, b_yellow);
        }
        else if (cur_event == 6) {
            std::cout << "\t" << team_a << " has committed a foul close to the goal, Team B has been awarded a penalty kick.";
            a_fouls = a_fouls+1;
            penalty_kick(team_b, b_goals, b_on_goal, b_off_goal, b_blocked, b_red, b_yellow);
        }
        
        //time delay between events
       sleep_for(500ms); //adding a time delay
      
        //print statistics at the randomly generated "halftime"
        if (i == split_1 || i == no_of_events-1) {
            std::cout <<"**************************************************************************************" << std::endl;
            
            //check for if it's halftime or the end of game
            if (count == 0){
            std::cout <<std::setw(33) << "FIRST HALF" << std::endl;
            }
            else {
                std::cout <<std::setw(30) << "FINAL" << std::endl;
            }
                   count ++;
            
            
            //print out statistics
            std::cout <<"\n" << team_a << std::setw(20) << a_goals << " - " << b_goals << std::setw(20) << team_b <<std::endl;;
            std::cout << "\n" << std::setw(32) << "TEAM STATS" << std::endl;
            
            std::cout << " " << std::endl;
            std::cout <<a_on_goal<< std::setw(33) << "Shots on Goal" << std::setw(12) << b_on_goal << std::endl;
            std::cout <<a_off_goal <<std::setw(33) << "Shots Off Goal" << std::setw(12) << b_off_goal << std::endl;
            std::cout <<a_blocked <<std::setw(33) << "Blocked Shots" << std::setw(12) <<b_blocked << std::endl;
            std::cout <<a_fouls << std::setw(28) << "Fouls" << std::setw(17) << b_fouls <<std::endl;
            std::cout <<a_yellow << std::setw(31) << "Yellow Cards" << std::setw(14) << b_yellow << std::endl;
            std::cout <<a_red << std::setw(30) << "Red Cards" << std::setw(15) << b_red << std::endl;
        
            
            
            
          std::cout <<"**************************************************************************************" << std::endl;
        }
    }
    return true;
}


