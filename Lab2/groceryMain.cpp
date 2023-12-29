//Christopher Desmond 
//COSC 220 - Lab 2 
//Dr. Park
//09/13/2023

#include<iostream>
#include<fstream> //include fstream library 
using namespace std;
int main () 
{
//ifstream read in var and open
ifstream fileRead;
fileRead.open("item.txt");

ofstream fileWrite;
fileWrite.open("Desmond_Christopher.txt"); //create receipt .txt file


if(!fileRead) //error validation 
{
cout << "Error - could not open file" << endl;
	return 0; 
}

//user variables
int userInput = -1;
float userAmount = -1;

//grocery variables
int current_item_num = -1;
char item_name[40];
char tax_type;
char sales_type;
float unit_price = 0.00;

//tax rate
const float tax_rate = 0.06;

//calculations
float tax_amount = 0.00;
float subtotal = 0.00;
float total = 0.00;



//check if user_input is same as item num

//print to receipt .txt file
    //head
    fileWrite << left << setw(15) << "Item Number" << setw(15) << "Item Name"  << setw(10) << "Unit" << setw(15) << "Unit Price" << setw(10) << "Tax" << setw(15) << "Subtotal" << endl;
    fileWrite << "__________________________________________________________________________________________" << endl;

//main while loop
while(userInput != 0) 
{
//reset fileRead obj
fileRead.clear();
fileRead.seekg(0);

//if found in list true
bool foundInList = false;

cout << "Enter an item number : Enter '0' to end program and print receipt. " << endl;
cin >> userInput;




//nest loop
while(!fileRead.eof())
{

//read in grocery data
fileRead >> current_item_num;
fileRead >> item_name;
fileRead >> tax_type;
fileRead >> sales_type;
fileRead >> unit_price;


//found
if(userInput == current_item_num) 
{
foundInList = true;
//debug if found in list
//cout << "Valid" << endl;


//if tax == t + 0.06 if tax = n no tax
if(tax_type == 't') 
{
   cout << item_name << " is Taxed " <<endl;
   tax_amount = unit_price * tax_rate;
}



switch(sales_type) {
case 's':
 userAmount = 1;
 cout << item_name << " - $" << unit_price  << "\n" << ", Has been added to the list." << endl;

 break;   
case 'n':
cout << "How many number of " << item_name << ", Would you like? " << endl;
cin >> userAmount;

cout << item_name << "x" << userAmount << ", Has been added to the list." << endl;

   break;
case 'p':
cout << "How many pounds of " << item_name << ", Would you like? " << endl;
cin >> userAmount;   

cout << userAmount << " pounds of " << item_name << ", Has been added to the list." << endl;
break;
}




//calculations
subtotal = userAmount * (unit_price + tax_amount);

total = total + subtotal; 


if(sales_type == 's') 
{
  static_cast<int> (userAmount =1);
}

//print outstream items
fileWrite << setw(10) << current_item_num << setw(25) << item_name << setw(12) << userAmount << "$" << setw(10)  << fixed << setprecision(2)  << unit_price << "$" << setw(10) << tax_amount << "$" << setw(10) << fixed  << setprecision(2) << subtotal << endl << endl;
break;
}
}


//if not found in list 
if(foundInList == false && userInput != 0) 
{
   cout << "Item number not found, Try another number" << endl;
}


}


fileWrite << "Total" << setw(75) << right << fixed << setprecision(2) << "$" << total << endl;

//debug
//cout << "0 entered" << endl;
cout << "Thanks for using the grocery receipt system, Please check recipt file for results";


//close file
fileRead.close();
fileWrite.close();
return 0;
}
