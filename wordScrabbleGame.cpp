// Program name: main.cpp
// Author: Gavin Schmidt
// Date last updated: 2/17/2020
// Purpose: Play a game where the user must guess random words

//libaries
#include <iostream>
#include <string>
#include <fstream>
#include <cstdlib>
using namespace std;

//gloable variables
string wordListArray[59];

void fillWordList() //does not return anything but loads wordlist into an array that can be used later
{
  ifstream file("wordlist.txt"); //opens the text file
  if(file.is_open()) //makes sure the file was opened correctly
  {
    for(int i = 0; i < 59; i++) //itterates through each array value
      {
        file >> wordListArray[i]; //adds that line of the file to the array
      }
  }
}

int getSeedNumber()
{
  int seed;

  cin >> seed; //takes seed num from user without promt

  return seed; //returns the value when called
}

string scrambleWord(string currentCode){ //scrambles a word by randomly switching characters
    int randomIndex;
    int i = 0;
    char holder;
    int length = currentCode.length() - 1;

    while(i <= length){
        holder = currentCode[i]; //holds the letter
        randomIndex = rand() % (length + 1); //gets a random index to swap
        currentCode[i] = currentCode[randomIndex]; //takes the char from a random number (generated above) and puts it in the currentCode
        currentCode[randomIndex] = holder; //puts the char from holder into the string
        i++;
    }
    return currentCode;
}

void checkPosition(string scrambledWord, string guess){
    int counter1 = 0;
    int counter2 = 0;
    int counter3 = 0;
    int correctPosition = 0; //counts number of correct letters in the wrong position to later output to the user
    int correctLetter = 0; //counts number of correct letters in the correct position to later output to the user
    int currentPosition = 0; //used in each while loop to hold the current positon in the loop
    int length = guess.length(); //Checks how many letters are in the correct position.
    
    while(counter1 < length){ //loops while counter 1 is less than the length of the code word
        if (guess[counter1] == scrambledWord[counter1]){
            correctPosition++;
            guess[counter1] = 'x'; //represents correct char in wrong spot
            counter1++; //goes to the next word
        }
        else{
            counter1++;
        }
    } //ends while loop
    while(counter3 < length){
        counter2 = 0;
        while(counter2 < length){ //counts number of correct characters
            if(guess[counter3] == scrambledWord[counter2]){
                correctLetter++;
                guess[counter3] = 'o'; //represets correct char in right spot
                counter2++;
                continue;
            }
            else{
                counter2++;
            }
        }
        counter3++;
     } //ends while loop

    cout << "You have " << correctPosition << " correct characters in the right position, and you have " << correctLetter << " correct characters in the wrong position." << endl; //outputs number of correct character and wrong charactes
    cout << "Comparsion: "; //outputs the visual of the line above
    while(currentPosition < length){
        if(guess[currentPosition] == 'x'){ //converts the char to a string
            cout << "x "; //shows the user the letter in this spot was guessed in the correct spot
            currentPosition++;
        }
        else if(guess[currentPosition] == 'o'){ //converts the char to a string
            cout << "o "; //shows the user they guessed the character in that spot was guessed, but not in the correct spot
            currentPosition++;
        }
        else{ //if it wasnt marked x or o it means there is no character matching that spot
            cout << "_ "; //shows user they did not guess the correct letter in that spot
            currentPosition++;
        }
    }
    cout << endl;
}

int main() 
{
  char ready; //hold the y or n entered by the user

  cout << "Press any key to start: ";

  int seed = 1; //sets default for seed
  int numGuesses = 1;

  const int MAX_WORDS = 60; //make the maximum number of words 60
  string words[MAX_WORDS];

  

  string guess; //holds the users guess
  string currentCode; //holds the uncrambled words pulled from the file
  string scrambledWord; //holds the srambled word

  fillWordList(); //fills the word list array
  srand (getSeedNumber()); //gets seed number from the function

  cout << "Would you like to guess a word? (Enter y or n) "; //promts the user if they want to play
  cin >> ready;
  cout << endl;

  while(ready != 'y' && ready != 'n' && ready != 'Y' && ready != 'N'){ //asks for input again if the input is invalid
      cin.clear(); //clears the input
      cin.ignore(100, '\n'); //ignores 100 characters
      cout << "That is not a valid response." << endl;
      cout << "Would you like to guess a word? (Enter y or n) " << endl; //askes again if the user wants to play
      cin >> ready;
  }

  while(ready == 'y' || ready == 'Y'){ //promts user to comfirm they want to play
    currentCode = wordListArray[rand() % (59+1)]; //chooses a word for the array
    scrambledWord = scrambleWord(currentCode); //scrambles the word

    cout << "Your code is " << scrambledWord.length() << " characters long" << endl;
    cout << "Please make your guess or enter # to stop: ";
    cin >> guess;

    while(guess.length() != scrambledWord.length()){ //if the user does enter the same number of character in the code work this loop happens
      cout << "The guess must be the same number of characters as your code word." << endl;
      cout << "Your code is " << scrambledWord.length() << " characters long" << endl;
      cout << "Please make your guess or enter # to stop: ";
      cin >> guess;
    }

    if(guess == "#"){
      cout << "You failed to guess the word. You guessed " << numGuesses << " times" << endl;
      cout << "Your codeword was " << scrambledWord << endl; //tells the user the scrambled word
      cout << "It was created from " << currentCode << endl; //tells the user the unscrambled word
      cout << "Would you like to try again? Enter y or n: ";
      cin >> ready;
    }


    while(guess != scrambledWord){
      cout << "You have guessed " << numGuesses << " times" << endl; //tells the user how many times they have guessed
      numGuesses++; //adds one to numGuesses
      cout << "You entered " << guess << endl; //outputs the users guess
      cout << "That is not the code word." << endl;
      checkPosition(scrambledWord, guess); //this function determines the number of correct and incorect characters in the guess
      cout << endl;
      cout << "Your code is " << scrambledWord.length() << " characters long" << endl;
      cout << "Please make your guess or enter # to stop: "; //Prompts user to guess again
      cin >> guess;

      while(guess.length() != scrambledWord.length()){ //if the user does enter the same number of character in the code work this loop happens
      cout << "The guess must be the same number of characters as your code word." << endl;
      cout << "Your code is " << scrambledWord.length() << " characters long" << endl;
      cout << "Please make your guess or enter # to stop: ";
      cin >> guess;
      }
    }
    
      if(numGuesses == 10){
        cout << "You have guessed 10 times" << endl;
        cout << "Your codeword was " << scrambledWord << endl; //tells the user the scrambled word
        cout << "It was created from " << currentCode << endl; //tells the user the unscrambled word
        cout << "Would you like to try again? Enter y or n: ";
        cin >> ready;
        cout << endl;
      }
    

    if(guess == scrambledWord){
    cout << "You guessed the word in " << numGuesses << " tries! You Won!" << endl; 
    cout << "Your codeword was " << scrambledWord << endl; //tells the user the scrambled word
    cout << "It was created from " << currentCode << endl; //tells the user the unscrambled word
    cout << "Would you like to try again? Enter y or n: ";
    cin >> ready;
    guess = 1; //resets number of guesses
    //Code goes back to the beginning and chooses another word
    }
  }
  if (ready == 'n' || ready == 'N'){
        cout << endl;
  }

  return 0;
}