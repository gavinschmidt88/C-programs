/* Program name: File I/O.cpp
*  Author: Gavin Schmidt
*  Date last updated: 3/29/2021
* Purpose: Demonsrate input and output using data files
*/

#include <iostream>
#include <fstream>
#include <string>
using namespace std;

int main() {
  int menuInput;
  string name, species, breed, color, info;

  ofstream myfile;

  while(menuInput != 1 | menuInput != 2){
    cout << "1. Add a pet" << endl;
    cout << "2. View pets" << endl;
    cout << "3. Use any other key to exit" << endl;
    cout << "Make your selection: ";
    cin >> menuInput;
    cout << endl;

    if(menuInput == 1){

      cout << "Animal name: ";
      cin >> name;

      cout << "Animal species: ";
      cin >> species;

      cout << "Animal breed: ";
      cin >> breed;

      cout << "Animal color: ";
      cin >> color;
      cout << endl;

      myfile.open ("animals.txt");
      myfile << "Name: " << name << "\n";
      myfile << "Species: " << species << "\n";
      myfile << "Breed: " << breed << "\n";
      myfile << "Color: " << color << "\n";
      myfile << "\n";
      myfile.close();
      
    } //end of if statement

    else if(menuInput == 2){


      string output;
      
      ifstream myfile;
      myfile.open ("animals.txt");
      
      while(getline(myfile, output))
      {
        cout << output << endl;
      }

      myfile.close();
      
    }//ends else if

    else
    {
      cout << "Good bye!" << endl;
      return 0;
    }
  }//ends while
  
  return 0;
};