/* 
 * Credit-limit calculating program: This program calculates if a customer has exceded
 * his or her credit limit on a charge account.
 * Author: Jose Luis Castillo
 * This program takes its input from a file called AccountInfoIn.txt the following data:
 * 1). Account number (an integer)
 * 2). Balance at the beginning of the month
 * 3). Total of all items charged by this customer this month
 * 4). Total of all credits applied to this customer's account this month
 * 5). Allowed credit limit
 * 
 * Each value in the file is separated by a space on the same line. This program reads in each value from the file,
 * calculates the new balance, and then determines if the new balance exceeds the customer's credit limit.
 * If the credit limit is exceeded, the progam writes to an ouput file with the name CreditLimitOut.txt the 
 * customer's account number, credit limit, new balance, and the message "Credit limit exceeded!".
 */

#include <iostream>
#include <fstream>	//for file Input/Output
#include <string>		
using namespace std;


int main()
{
	int Accountnumber;
	float BeginningBalance;
	float Charges;
	float Credits;
	float CreditLimit;
	float NewBalance;

	ifstream inputFile;	
	ofstream outputFile;

	inputFile.open("AccountInfoIn.txt");

	if (inputFile.fail())		// check if input file exists
	{
		cout << "The AccountInfoIn.txt file could not be opened.\n"
			 << "Make sure it is located in the directory\n"
			 << "where your compiler expects to find it.\n";
	}

	outputFile.open("CreditLimitOut.txt"); //open an output file

	// Read in contents of the AccountInfoIn.txt file
	inputFile >> Accountnumber;

	inputFile >> BeginningBalance;

	inputFile >> Charges;	

	inputFile >> Credits;		
	
	inputFile >> CreditLimit;


	NewBalance = BeginningBalance + Charges - Credits;
	
	if (NewBalance <= CreditLimit) {
		outputFile << "Accountnumber: " << Accountnumber << endl;
		outputFile << "Credit limit: " << CreditLimit << endl;
		outputFile << "New Balance: " << NewBalance << endl;
		outputFile << "Your New Balance is " << NewBalance << endl;
	} else {
		outputFile << "Accountnumber: " << Accountnumber << endl;
		outputFile << "Credit limit: " << CreditLimit << endl;
		outputFile << "New Balance: " << NewBalance << endl;
		outputFile << "Your New Balance is " << NewBalance << " dollars. " << endl;
		outputFile << "Credit Limit Exceeded!" << endl;
	}

	inputFile.close ();	//Close the input file
	outputFile.close (); //Close the output file

	return 0;

}