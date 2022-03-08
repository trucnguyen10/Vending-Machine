/*
  *****PROJECT 1: VENDING MACHINE*****
  Member:
    1. Ky Nguyen
    2. Truc Nguyen
    3. Huy Tran
  Instructor: professor Grant Skipper
  Course: CSC122A - Data Structure
  File Created Date: 02/22/2022
*/

#include "VendingMachine.h"
#include <cmath>
#include <ctype.h>
#include <iostream>
#include <string>
#include <vector>

using namespace std;

VendingMachine::VendingMachine() {}
VendingMachine machine;

int customer[10], quantity[10];
bool isPrinted[10];
float cost = 0.0;
string s;
int calories = 0, count = 0;

void VendingMachine::printMenu() {
  cout << "This is our menu: " << endl;
  cout << "ID  Name      Price   Calories" << endl;
  for (int i = 0; i < 10; i++) {
    cout << i << " - " << snacks[i];
    for (int j = 0; j < 10 - snacks[i].length(); j++)
      cout << " ";
    cout << "$" << price[i];
    for (int j = 0; j < 7; j++)
      cout << " ";
    cout << calories[i] << " cal" << endl;
  }
}

string VendingMachine::getName(int id) { return snacks[id]; }

float VendingMachine::getPrice(int id) { return price[id]; }

int VendingMachine::getCalories(int id) { return calories[id]; }

// max function
string max() {
  int max = customer[0];
  for (int i = 1; i < count; i++) {
    if (machine.getPrice(customer[i]) > machine.getPrice(max))
      max = customer[i];
  }
  return machine.getName(max);
}

// min function
string min() {
  int min = customer[0];
  for (int i = 1; i < count; i++) {
    if (machine.getPrice(customer[i]) < machine.getPrice(min))
      min = customer[i];
  }
  return machine.getName(min);
}

bool isNumber(string s) {
  for (int i = 0; i < s.length(); i++) {
    if (!isdigit(s[i]))
      return false;
  }
  return true;
}

void checkError() {
  cout << "Please choose your snack ID number: " << endl;
  cin >> s;
  while (!isNumber(s) || (isNumber(s) && s.length() > 1)) {
    cout << "You entered invalid ID!" << endl;
    cout << "Please re-enter: " << endl;
    cin >> s;
  }
  customer[count] = stoi(s);
  cost += machine.getPrice(customer[count]);
  calories += machine.getCalories(customer[count]);
  quantity[customer[count]]++;
  count++;
}

int main() {
  for (int i = 0; i <= 30; i++)
    cout << "-";
  cout << endl;
  machine.printMenu();
  for (int i = 0; i <= 30; i++)
    cout << "-";
  cout << endl;

  checkError();

  string ans;
  bool check = false;

  while (check || count < 10) {
    cout << "Would you like more snacks?" << endl;
    cout << "Press Y/y if Yes, N/n if No" << endl;
    cout << "Your Answer: " << endl;
    cin >> ans;

    while (ans != "Y" && ans != "y" && ans != "N" && ans != "n") {
      cout << "Only Y/y or N/n" << endl;
      cout << "Please Re-enter: " << endl;
      cin >> ans;
    }
    if (ans == "Y" || ans == "y") {
      checkError();
    } else
      break;
  }

  for (int i = 0; i <= 20; i++)
    cout << "-";
  cout << endl;
  if (count < 10)
    cout << "We got it! Thank you for supporting us!" << endl;
  else
    cout << "Sorry! Our order limit is only 10!" << endl;

  for (int i = 0; i <= 30; i++)
    cout << "-";
  cout << endl;

  cout << "ORDER INFORMATION" << endl;
  cout << "The Total Cost: " << cost << endl;
  cout << "The Total Cost After Tax(5%): " << cost + cost * (5.0 / 100.0)
       << endl;

  for (int i = 0; i <= 30; i++)
    cout << "-";
  cout << endl;
  cout << "Your Order List: " << endl;
  cout << "Name      Quantity" << endl;

  for (int i = 0; i < 10; i++)
    isPrinted[i] = true;

  for (int i = 0; i < count; i++)
    if (isPrinted[customer[i]]) {
      cout << machine.getName(customer[i]);
      for (int j = 0; j < 10 - machine.getName(customer[i]).length(); j++)
        cout << " ";
      cout << quantity[customer[i]] << endl;
      isPrinted[customer[i]] = false;
    }

  for (int i = 0; i <= 30; i++)
    cout << "-";
  cout << endl;

  cout << "Average Calories: " << round(calories / count) << endl;
  cout << "The Total Calories: " << calories << endl;

  for (int i = 0; i <= 30; i++)
    cout << "-";
  cout << endl;

  cout << "The most expensive Snack: " << max() << endl;
  cout << "The least expensive Snack: " << min() << endl;

  for (int i = 0; i <= 30; i++)
    cout << "-";
  cout << endl;

  cout << "THANK YOU AND HAVE A GREAT DAY!" << endl;

  for (int i = 0; i <= 30; i++)
    cout << "*";
  cout << endl;
}
