#include <string>

using namespace std;

class VendingMachine 
{

public:
  // Constructor
  VendingMachine();

  // Accessor Method
  string getName(int id);
  float getPrice(int id);
  int getCalories(int id);
	void printMenu();

private: 
  string snacks[10] = {"KitKat", "Lay's" , "Chips", "Doritos", "Oreo", "Reese", "HerShey", "M&M", "PopCorn", "Caramel"};
  float price[10] = {2, 3, 4, 4, 5, 2, 3, 1, 5, 3};
  int calories[10] = {150, 200,300,200,350,150,200,150,300,250};
  
};
