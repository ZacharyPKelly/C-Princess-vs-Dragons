/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/cFiles/main.c to edit this template
 */

/*
 * This file contains methods, logic and code in order to run the Princess vs 
 * Dragon program required for Assignment One in AUCSC 370. The user is 
 * prompted to select a board size then navigate around the randomly placed
 * dragons in order to reach the edge of the board.
 * 
 * Class: AUCSC 370
 * Name: Zachary Kelly
 * Student ID: 1236421
 * Date: September 29th. 2022
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include "headerFile.h"

/**
 * gameMessage: Prints the rules and explanation for the game
 */

void gameMessage(){
    
    printf("--------------------------------------------------------------------------------------\n\n");
    printf("You are the PRINCESS! You must escape the EVIL DRAGONS!\n\n");
    printf("Thankfully these DRAGONS are STUPID, they can't even move!\n\n");
    printf("Navigate around the DRAGONS to the edge of the board where the water is to WIN!\n\n");
    printf("You can move with the following commands:\n\n");
    printf("Enter 'L' for left\n");
    printf("Enter 'R' for right\n");
    printf("Enter 'U' for up\n");
    printf("Enter 'D' for down\n\n");
    printf("Capitalization doesn't matter!\n");
    printf("Any word or phrase that starts with those letters will move you in that direction!\n\n");
    printf("--------------------------------------------------------------------------------------\n\n");
    
}//gameMessage

/**
 * intConverter: Takes a string and determines if that string is representative
 * of an integer between 4 - 10 (inclusive); i.e.:"4" will return 4 as an int.
 * @param gridSize - The string to be checked.
 * @return The string's integer version, else -1;
 */

int intConverter(char gridSize[]){
    
    int size;
    
    char four[] = "4";
    char five[] = "5";
    char six[] = "6";
    char seven[] = "7";
    char eight[] = "8";
    char nine[] = "9";
    char ten[] = "10";
    
    if(strcmp(gridSize, four) == 0){
        
        size = 4;    
        return size;
        
    }//if
    else if(strcmp(gridSize, five) == 0){
        
        size = 5;      
        return size;
        
    }//if
    else if(strcmp(gridSize, six) == 0){
        
        size = 6;        
        return size;
        
    }//if
    else if(strcmp(gridSize, seven) == 0){
        
        size = 7;        
        return size;
        
    }//if
    else if(strcmp(gridSize, eight) == 0){
        
        size = 8;      
        return size;
        
    }//if
    else if(strcmp(gridSize, nine) == 0){
        
        size = 9;     
        return size;
        
    }//if
    else if(strcmp(gridSize, ten) == 0){
        
        size = 10;      
        return size;
        
    }//if
    
    return -1;
    
}//intConverter

/**
 * sizeOfGrid: Takes from the user as a string how large a board they wish
 * to play on between 4 - 10 (inclusive). Returns the size of the grid the user
 * chose as an int.
 * @return The size of the game board as a integer.
 */

int sizeOfGrid(){
    
    int size;
    char gridSize[100]; //Program crashes if input is to much larger then array 
                        //size so large array chosen to prevent crashes
    char four[] = "4";
    char five[] = "5";
    char six[] = "6";
    char seven[] = "7";
    char eight[] = "8";
    char nine[] = "9";
    char ten[] = "10";
    
    printf("Please enter the size of the board you wish to play on from 4-10: ");
    fflush(stdout);
    scanf(" %[^\n]", &gridSize); //%[^\n] skips white space at beginning of                              
    fflush(stdout);              //string and ignores any white space contained
    
    //checking to see if input matches what correct input should be
    while(strcmp(gridSize, four) != 0 && strcmp(gridSize, five) != 0 && 
          strcmp(gridSize, six) != 0 && strcmp(gridSize, seven) != 0 && 
          strcmp(gridSize, eight) != 0 && strcmp(gridSize, nine) != 0 && 
          strcmp(gridSize, ten)){
        
        printf("Your grid size must be a number from 4 to 10 \n\n");
        
        printf("Please enter the size of the board you wish to play on from 4-10: ");
        fflush(stdout);
        scanf(" %[^\n]", &gridSize);
        fflush(stdout);
        
    }//while
    
    printf("\n");
    printf("--------------------------------------------------------------------------------------\n\n");
    
    size = intConverter(gridSize); //converts string to int
    
    return size;

}//sizeOfGrid

/**
 * 
 * @param size The number of rows and column of the game board.
 * @param col The column position of the index
 * @param row The row position of the index
 * @return 1 if an edge column, 2 if a edge row, 0 otherwise.
 */

int outsideEdge(int size, int col, int row){
    
    int indexConstant = size - 1;
    int i, j, k, l;
    
    //check top row
    
    for(k = 0; k < size; k++){
        
        if(row == 0 && col == k){
        
            return 2;
        
        }//if
    }//for
    
    //check bottom row
    
    for(l = 0; l < size; l++){
        
        if(row == indexConstant && col == l){
        
            return 2;
        
        }//if
    }//for
    
    //check left column
    
    for(i = 0; i < size; i++){
        
        if(col == 0 && row == i){
        
            return 1;
        
        }//if
    }//for
    
    //check right column
    
    for(j = 0; j < size; j++){
        
        if(col == indexConstant && row == j){
        
            return 1;
        
        }//if
    }//for
    
    return 0;
    
}//outsideEdge

/**
 * Takes a string and returns the first character of the string if it begins
 * with 'l', 'r', 'u', 'd' lower or upper case.
 * @param string The string to have its first character checked.
 * @return 'l', 'r', 'u', 'd' if string starts with any of those characters
 * upper or lower case, 'w' otherwise.
 */

char firstLetter(char string[]){
    
    char firstLetter;
    firstLetter = string[0]; //gets the first character of the given string.
    
    //if user wants to go left
    if(firstLetter == 'l' || firstLetter == 'L'){
        
        return 'l';
        
    }//if
    
    //if user wants to go right
    else if(firstLetter == 'r' || firstLetter == 'R'){
        
        return 'r';
        
    }//if
    
    //if user wants to go up
    else if(firstLetter == 'u' || firstLetter == 'U'){
        
        return 'u';
        
    }
    //if user wants to go down
    else if(firstLetter == 'd' || firstLetter == 'D'){
       
        return 'd';
        
    }//if
    
    //if user input something wrong
    else{
        
        return 'w';
        
    }//else
    
}//firstLetter

/**
 * playGame: Contains the logic for moving the Princess around the board, as
 * well as determining whether or not the user have moved into the water to
 * win or into a dragon to lose.
 * @param size The size the user input as the size of the board as an int.
 */

void playGame(int size){
    
    size = size + 2; //Two extra rows/columns to account for water at edges of
                     //the game board.
    
    char board[12][12][10]; //array is 12x12 to account for the water at the
                            //edges of the board for size 10 boards.
    
    char directionInput[100];//Program crashes if input is to much larger then array 
                             //size so large array chosen to prevent crashes
    char directionCleaned;
    
    int dragonChance[] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10 , 11, 12, 13, 14, 
                          15, 16, 17, 18, 19, 20};
    int dragon;
    int winFlag = 0; //0 for hasn't won yet, 1 for game is over
    int directionFlag; //to check that user input correct direction.
    int i, j, k, l, m, n;
    int princessRow;
    int princessCol;
    int princessRowTemp;
    int princessColTemp;
    
    //building the board
    for(i = 0; i < size; i++){
        
        for(j = 0; j < size; j++){
            
            if(outsideEdge(size, i, j) == 1){ //if an outside row
                
                strcpy(board[i][j], "wwwwwwww");
                
            }//if
            else if(outsideEdge(size, i, j) == 2){ //if an outside col
                                                   //corners are columns for
                strcpy(board[i][j], "www");        //formatting the board
                
            }//else if
            else{ //if not an outside edge
                
                dragon = rand() % 20; //20 items in dragonChance array
                                      //Will return a number 0-19 inclusive that
                                      //will be used as an index.
                
                //5 'correct' indices for dragon to create a 25% chance of 
                //placing a dragon
                if(dragonChance[dragon] == 1 || dragonChance[dragon] == 2 || 
                   dragonChance[dragon] == 3 || dragonChance[dragon] == 4 || 
                   dragonChance[dragon] == 5){
                
                    strcpy(board[i][j], "-DRAGON-");
                    
                }//if
                else{//if not a dragon place a 'blank'
                
                    strcpy(board[i][j], "--------");
                
                }//else
            }//else
        }//for
    }//for
    
    if(size % 2 == 1){//if an odd sized board
        
        princessCol = ((size - 1) / 2);
        princessRow = ((size - 1) / 2);
        //place Princess in center of board.
        strcpy(board[princessCol][princessRow], "PRINCESS");
        
    }//if
    else{//if an even sized board
        
        princessCol = size / 2;
        princessRow = size / 2;
        //Place princess in bottom right of center indices
        strcpy(board[princessCol][princessRow], "PRINCESS");
        
    }//else
    
    //printBoard
    for(k = 0; k < size; k++){
        
        for(l = 0; l < size; l++){
            
            printf("%s", board[k][l]);
            printf("  ");
            
        }//for
        
        printf("\n");
        
    }//for
    
    printf("\n");
    
    //logic for movement of Princess around board
    while(winFlag == 0){
        
        printf("Which Direction Would You Like To Move: ");
        fflush(stdout);
        scanf(" %[^\n]", &directionInput);
        fflush(stdout);
        
        //grab first letter of input
        directionCleaned = firstLetter(directionInput);
        
        directionFlag = 0;//0 while input not correct, 1 otherwise
        
        //check that the first letter of the user input is 'l', 'r', 'u', 'd'
        //either lower or uppercase
        while(directionFlag == 0){
            
            if(directionCleaned == 'w'){//if not 'l', 'r', 'u', 'd'
                
                printf("Not sure of your selection. Try again!\n\n");
                printf("Which Direction Would You Like To Move: ");
                fflush(stdout);
                scanf(" %[^\n]", &directionInput);
                fflush(stdout);
                
                directionCleaned = firstLetter(directionInput);
                
            }//if
            else{
                
                directionFlag = 1;
                
            }//else
        }//while
        
        //if user wants to move left
        if(directionCleaned == 'l'){
            
            //save Princes pervious position to replace with empty game square
            princessRowTemp = princessRow;
            princessColTemp = princessCol;
            
            princessRow = princessRow - 1; //moving princess left in row.
            
            //if moved into a dragon
            if(strcmp(board[princessCol][princessRow], "-DRAGON-") == 0){
                
                printf("\n");
                
                strcpy(board[princessCol][princessRow], "YUM  YUM");
                strcpy(board[princessColTemp][princessRowTemp], "--------");
                
                printf("--------------------------------------------------------------------------------------\n\n");
                
                //print board
                for(k = 0; k < size; k++){
        
                    for(l = 0; l < size; l++){
            
                        printf("%s", board[k][l]);
                        printf("  ");
            
                    }//for   
        
                    printf("\n");
        
                }//for
                
                printf("\n");
                printf("You somehow managed to run into a completely avoidable DRAGON!\n");
                printf("The DRAGON gobbles you up. YUM!\n\n");
                printf("GAME OVER\n\n");
                
                winFlag = 1; //exit game loop as user has lost
                
            }//if
            
            //if moved into the water
            else if(outsideEdge(size, princessCol, princessRow) == 1 || outsideEdge(size, princessCol, princessRow) == 2){
                
                printf("\n");
                
                strcpy(board[princessColTemp][princessRowTemp], "--------");
                
                printf("--------------------------------------------------------------------------------------\n\n");
                
                //print board
                for(k = 0; k < size; k++){
        
                    for(l = 0; l < size; l++){
            
                        printf("%s", board[k][l]);
                        printf("  ");
            
                    }//for   
        
                    printf("\n");
        
                }//for
                
                printf("\n");
                printf("The PRINCESS has escaped!\n\n");
                printf("YOU WIN!\n\n");
                
                winFlag = 1;//exit game loop as the user has won
                
            }//else if
            
            //if moved into an empty game square
            else{
                
                strcpy(board[princessCol][princessRow], "PRINCESS");
                strcpy(board[princessColTemp][princessRowTemp], "--------");
                
                printf("\n");
                printf("You moved LEFT\n\n");
                printf("--------------------------------------------------------------------------------------\n\n");
                
                //print board
                for(k = 0; k < size; k++){
        
                    for(l = 0; l < size; l++){
            
                        printf("%s", board[k][l]);
                        printf("  ");
            
                    }//for   
        
                    printf("\n");
        
                }//for
                
                printf("\n");
                
            }//else
        }//if
        
        //if user wants to move right
        else if(directionCleaned == 'r'){
            
            //save Princes pervious position to replace with empty game square
            princessRowTemp = princessRow;
            princessColTemp = princessCol;
            
            princessRow = princessRow + 1; //moving princess right in row. 
            
            //if moved into a dragon
            if(strcmp(board[princessCol][princessRow], "-DRAGON-") == 0){
                
                printf("\n");
                
                strcpy(board[princessCol][princessRow], "YUM  YUM");
                strcpy(board[princessColTemp][princessRowTemp], "--------");
                
                printf("--------------------------------------------------------------------------------------\n\n");
                
                //print board
                for(k = 0; k < size; k++){
        
                    for(l = 0; l < size; l++){
            
                        printf("%s", board[k][l]);
                        printf("  ");
            
                    }//for   
        
                    printf("\n");
        
                }//for
                
                printf("\n");
                printf("You somehow managed to run into a completely avoidable DRAGON!\n");
                printf("The DRAGON gobbles you up. YUM!\n\n");
                printf("GAME OVER\n\n");
                
                winFlag = 1; //exit game loop as user has lost
                
            }//if
            
            //if moved into the water
            else if(outsideEdge(size, princessCol, princessRow) == 1 || outsideEdge(size, princessCol, princessRow) == 2){
                
                printf("\n");
                
                strcpy(board[princessColTemp][princessRowTemp], "--------");
                
                printf("--------------------------------------------------------------------------------------\n\n");
                
                //print board
                for(k = 0; k < size; k++){
        
                    for(l = 0; l < size; l++){
            
                        printf("%s", board[k][l]);
                        printf("  ");
            
                    }//for   
        
                    printf("\n");
        
                }//for
                
                printf("\n");
                printf("The PRINCESS has escaped!\n\n");
                printf("YOU WIN!\n\n");
                
                winFlag = 1; //exit game loop as user has won
                
            }//else if
            
            //if moved into an empty game square
            else{
                
                strcpy(board[princessCol][princessRow], "PRINCESS");
                strcpy(board[princessColTemp][princessRowTemp], "--------");
                
                printf("\n");
                printf("You moved RIGHT\n\n");
                printf("--------------------------------------------------------------------------------------\n\n");
                
                
                //print board
                for(k = 0; k < size; k++){
        
                    for(l = 0; l < size; l++){
            
                        printf("%s", board[k][l]);
                        printf("  ");
            
                    }//for   
        
                    printf("\n");
        
                }//for
                
                printf("\n");
                
            }//else
        }//else if
        
        //if user wants to move up
        else if(directionCleaned == 'u'){
            
            //save Princes pervious position to replace with empty game square
            princessRowTemp = princessRow;
            princessColTemp = princessCol;
            
            princessCol = princessCol - 1; //moving princess up in column
            
            //if moved into a dragon
            if(strcmp(board[princessCol][princessRow], "-DRAGON-") == 0){
                
                printf("\n");
                
                strcpy(board[princessCol][princessRow], "YUM  YUM");
                strcpy(board[princessColTemp][princessRowTemp], "--------");
                
                printf("--------------------------------------------------------------------------------------\n\n");
                
                //print board
                for(k = 0; k < size; k++){
        
                    for(l = 0; l < size; l++){
            
                        printf("%s", board[k][l]);
                        printf("  ");
            
                    }//for   
        
                    printf("\n");
        
                }//for
                
                printf("\n");
                printf("You somehow managed to run into a completely avoidable DRAGON!\n");
                printf("The DRAGON gobbles you up. YUM!\n\n");
                printf("GAME OVER\n\n");
                
                winFlag = 1;//exit game loop as user has lost
                
            }//if
            
            //if moved into the water
            else if(outsideEdge(size, princessCol, princessRow) == 1 || outsideEdge(size, princessCol, princessRow) == 2){
                
                printf("\n");
                
                strcpy(board[princessColTemp][princessRowTemp], "--------");
                
                printf("--------------------------------------------------------------------------------------\n\n");
                
                //print board
                for(k = 0; k < size; k++){
        
                    for(l = 0; l < size; l++){
            
                        printf("%s", board[k][l]);
                        printf("  ");
            
                    }//for   
        
                    printf("\n");
        
                }//for
                
                printf("\n");
                printf("The PRINCESS has escaped!\n\n");
                printf("YOU WIN!\n\n");
                
                winFlag = 1; //exit game loop as user has won
                
            }//else if
            
            //if moved into an empty game square
            else{
                
                strcpy(board[princessCol][princessRow], "PRINCESS");
                strcpy(board[princessColTemp][princessRowTemp], "--------");
                
                printf("\n");
                printf("You moved UP\n\n");
                printf("--------------------------------------------------------------------------------------\n\n");
                
                //print board
                for(k = 0; k < size; k++){
        
                    for(l = 0; l < size; l++){
            
                        printf("%s", board[k][l]);
                        printf("  ");
            
                    }//for   
        
                    printf("\n");
        
                }//for
                
                printf("\n");
                
            }//else
        }//else if
        
        //if user want to move down
        else if(directionCleaned == 'd'){
            
            //save Princes pervious position to replace with empty game square
            princessRowTemp = princessRow;
            princessColTemp = princessCol;
            
            princessCol = princessCol + 1; //moving princess down in column.
            
            //if moved into a dragon
            if(strcmp(board[princessCol][princessRow], "-DRAGON-") == 0){
                
                printf("\n");
                
                strcpy(board[princessCol][princessRow], "YUM  YUM");
                strcpy(board[princessColTemp][princessRowTemp], "--------");
                
                printf("--------------------------------------------------------------------------------------\n\n");
                
                //print board
                for(k = 0; k < size; k++){
        
                    for(l = 0; l < size; l++){
            
                        printf("%s", board[k][l]);
                        printf("  ");
            
                    }//for   
        
                    printf("\n");
        
                }//for
                
                printf("\n");
                printf("You somehow managed to run into a completely avoidable DRAGON!\n");
                printf("The DRAGON gobbles you up. YUM!\n\n");
                printf("GAME OVER\n\n");
                
                winFlag = 1; //exit game loop as user has lost
                
            }//if
            
            //if moved into the water
            else if(outsideEdge(size, princessCol, princessRow) == 1 || outsideEdge(size, princessCol, princessRow) == 2){
                
                printf("\n");
                
                strcpy(board[princessColTemp][princessRowTemp], "--------");
                
                printf("--------------------------------------------------------------------------------------\n\n");
                
                //print board
                for(k = 0; k < size; k++){
        
                    for(l = 0; l < size; l++){
            
                        printf("%s", board[k][l]);
                        printf("  ");
            
                    }//for
        
                    printf("\n");
        
                }//for
                
                printf("\n");
                printf("The PRINCESS has escaped!\n\n");
                printf("YOU WIN!\n\n");
                
                winFlag = 1;//exit game loop as user has won
                
            }//else if
            
            //if moved into an empty game square
            else{
                
                strcpy(board[princessCol][princessRow], "PRINCESS");
                strcpy(board[princessColTemp][princessRowTemp], "--------");
                
                printf("\n");
                printf("You moved DOWN\n\n");
                printf("--------------------------------------------------------------------------------------\n\n");
                
                //print board
                for(k = 0; k < size; k++){
        
                    for(l = 0; l < size; l++){
            
                        printf("%s", board[k][l]);
                        printf("  ");
            
                    }//for   
        
                    printf("\n");
        
                }//for
                
                printf("\n");
                
            }//else
        }//else if    
    }//while
    
}//playGame

/**
 * program: Wrapper for methods required to play the game as well as containing
 * logic for either continuing with another game when finished or exiting
 * the program.
 */

void program(){
    
    int size;
    int stillPlayingFlag = 0; //0 for still playing, 1 for finished
    int yesNoFlag = 0; //0 for unaccepted/no response, 1 for accepted response
    
    char decision[100]; //Program crashes if input is to much larger then array 
                        //size so large array chosen to prevent crashes
    
    printf("Welcome to Princess vs Dragons!\n\n");
    
    while(stillPlayingFlag == 0){
        
        srand(time(NULL)); //sets a new seed for rand based on the 
        
        gameMessage();//print rules and game description
        size = sizeOfGrid();//get input from user on how big game board will be
        playGame(size);//play the game
        
        yesNoFlag = 0;
        
        while(yesNoFlag == 0){
        
            printf("Would you like to play another game (Yes/No): ");
            fflush(stdout);
            scanf(" %[^\n]", &decision);
            fflush(stdout);
            
            //if user wants to play again
            if(strcmp(decision, "Yes") == 0 || strcmp(decision, "YES") == 0 || 
               strcmp(decision, "yes") == 0 || strcmp(decision, "Y") == 0 || 
               strcmp(decision, "y") == 0){

                printf("\n");
                yesNoFlag = 1;
            }//if
            
            //if user wants to exit the program
            else if(strcmp(decision, "No") == 0 || strcmp(decision, "NO") == 0 || 
               strcmp(decision, "no") == 0 || strcmp(decision, "N") == 0 || 
               strcmp(decision, "n") == 0){

                stillPlayingFlag = 1;
                yesNoFlag = 1;
                
                printf("\n");
                printf("See you, come play again!\n");

            }//else if
            
            //if the user input unaccepted response
            else{
                
                printf("Not sure of your selection. Try again!\n\n");
                
            }//else
        }//while
    }//while
}//program

int main(){
   
    program();

}//main