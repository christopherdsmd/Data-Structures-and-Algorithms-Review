#include<iostream>

#include<fstream>

using namespace std;
int main () 
{

ifstream fileRead;

fileRead.open("item.txt");

//current item name
int userInput = -1;

//grocery variables
int current_item_num = -1;
char item_name[40];
char tax;
char sales_type;
float price;


bool found = false;




//check if user_input is same as item num

while(userInput != 0) 
{

cout << "Enter an item number : Enter '0' to end program and price receipt. " << endl;
cin >> userInput;





while(!fileRead.eof())
{

fileRead >> current_item_num;
fileRead >> item_name;
fileRead >> tax;
fileRead >> sales_type;
fileRead >> price;


if(userInput == current_item_num) 
{
cout << "Valid" << endl;

userInput = -1;

fileRead.seekg(0);

}

if(fileRead.eof()) 
{

cout << "Item Number not found, Enter another item number" << endl;
userInput = -1;

}
}


//debug
cout << current_item_num << " ";
cout << item_name << " ";
cout << tax << " ";
cout << sales_type << " ";
cout << price << " ";
cout << endl;



return 0;
   }
}

