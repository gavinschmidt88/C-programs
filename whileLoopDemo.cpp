#include <iostream>
using namespace std;

int main() 
{
  int count = 1; //intializing variables
  int mult = -15; //intializing variables

  while(count < 8) //loops while the variable count is less than 8
  {
    mult = mult + 15; //setting the variable mult = to its value plus 15
    count++; //adds one to the vraible count
  }

  int i = 20; //intializing variables
  while (i < 20) //loops while the variable i is less than 20
  {
    cout << i << " "; //prints the value of i and a space after it
    i = i + 5; //adds 5 to the value of the vriable of i
  }
  cout << endl; //ends the line

  cout << "8 * -15 = " << mult << endl; // prints 8 * -15 = followed by the value of mult

  double a=0, b=0; //intializing variables

  cout << "Enter a number : "; //prints Enter a number : 
  cin >> a; //assigns a the value of the user input
  cout << endl; //ends the line

  while(!cin) //loops while the user input is not number
  {
    cin.clear(); //clears the variable
    cin.ignore(1000,'\n'); //ignores the first 1000 characters of the input
    cout << "You did not enter a number!" << endl; //prints You did not enter a number!
    cout << "Enter a number : "; //prints Enter a number : 
    cin >> a; //assigns a the value of the user input
    cout << endl; //ends the line
  }

  cout << "Enter a number : "; //prints Enter a number :
  cin >> b; //assigns a the value of the user input
  cout << endl; //ends the line

  while(!cin) //loops while the user input is not number
  {
    cin.clear();
    cin.ignore(1000,'\n');
    cout << "You did not enter a number!" << endl;
    cout << "Enter a number : ";
    cin >> b;
    cout << endl;
  }

  cout << a << " * " << b << " = " << a*b << endl;

  return 0;
}
