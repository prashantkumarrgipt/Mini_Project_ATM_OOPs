#include<conio.h>
#include<iostream>
#include<string>
using namespace std;

/* Mini Project - ATM
   -> Check Balance
   -> Cash withdraw
   -> User Details
   -> Update Mobile No.
*/

class atm {

private:
    long int account_no;
    string name;
    int PIN;
    double balance;
    string mobile_no;

public:

// setData function is setting the Data into the private member variables
    void setData(long int account_nu ,string name_u,int PIN_u, double balance_u, string mobile_no_u){
        account_no = account_nu;
        name = name_u;
        PIN=PIN_u;
        balance=balance_u;
        mobile_no=mobile_no_u;

    }

    long int getAccountNo(){
        return account_no;
    
    }
    string getName(){
        return name;
    }
    int getPin(){
        return PIN;
    }
    double getBalance(){
        return balance;
    }
    string getMobileNo(){
        return mobile_no;
    }

    // update mobile number
    void setMobile(string mob_prev , string mob_new){
        if(mob_prev == mobile_no){
            mobile_no=mob_new;
        cout<<"Your Phone Number Changes from "<<mob_prev<<" to "<<mob_new;

        _getch(); // holds screen
        }
        else{
            cout<<"Incorrect Old mobile no ";
            _getch(); // holds screen
        }

    }
    // cash withdraw
    void cashWithDraw(int amount_w){
        if(amount_w>0 && amount_w<=balance){
            balance-=amount_w;
            cout << endl << "Please Collect Your Cash";
			cout << endl << "Available Balance :" << balance;
			_getch();	
        }
        else{
            cout << endl << "Invalid Input or Insufficient Balance";
			_getch();
        }
    }
};

int main(){
    int choice = 0 , enterPin;
    long int enterAccountNo;
    system("cls");
    atm user1; // object
    user1.setData(1234567, "Tim", 1111, 45000.90, "9087654321"); // set values
    do{
    system("cls");

		cout << endl << "****Welcome to ATM*****" << endl;
		cout << endl << "Enter Your Account No ";	  // asking user to enter account no
		cin >> enterAccountNo;

		cout << endl << "Enter PIN ";				 // asking user to enter PIN
		cin >> enterPin;



		// check whether enter values matches with user details
		if ((enterAccountNo == user1.getAccountNo()) && (enterPin == user1.getPin()))
		{
			do
			{
				int amount = 0;
				string oldMobileNo, newMobileNo;

				system("cls");
				// user Interface
				cout << endl << "**** Welcome to ATM *****" << endl;
				cout << endl << "Select Options ";
				cout << endl << "1. Check Balance";
				cout << endl << "2. Cash withdraw";
				cout << endl << "3. Show User Details";
				cout << endl << "4. Update Mobile no.";
				cout << endl << "5. Exit" << endl;
				cin >> choice;						// taking user choice

				switch (choice)						// switch condition
				{
				case 1:								// if user presses 1 
					cout << endl << "Your Bank balance is :" << user1.getBalance(); 
                    // getBalance is ... printing the users									bank balance
					_getch();
					break;


				case 2:									// if user presses 2
					cout << endl << "Enter the amount :";		
					cin >> amount;
					user1.cashWithDraw(amount);			// calling cashWithdraw function 
													    // passing the withdraw amount 
					break;


				case 3:										// if user presses 3
					cout << endl << "*** User Details are :- ";
					cout << endl << "-> Account no" << user1.getAccountNo();
					cout << endl << "-> Name      " << user1.getName();
					cout << endl << "-> Balance   " << user1.getBalance();
					cout << endl << "-> Mobile No." << user1.getMobileNo();
													// getting and printing user details
					_getch();
					break;


				case 4:								   //  if user presses 4
					cout << endl << "Enter Old Mobile No. ";
					cin >> oldMobileNo;							// take old mobile no

					cout << endl << "Enter New Mobile No. ";
					cin >> newMobileNo;							// take new mobile no

					user1.setMobile(oldMobileNo, newMobileNo);	// now set new mobile no
					break;

													// if user presses 5
				case 5:
					exit(0);						// exit application

				default:							// handle invalid user inputs
					cout << endl << "Enter Valid Data !!!";
				} 

			} while (1);				// MENU	   // condition will always TRUE and loop is										capable of running infinite times
		}

		else
		{
			cout << endl << "User Details are Invalid !!! ";
			_getch();
		}
	} while (1);						//LOGIN		// condition will always TRUE and loop is										capable of running infinite times

	return 0;
}
