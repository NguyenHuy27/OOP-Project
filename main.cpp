#include "Class.cpp"
#include "Structure.cpp"
#include "TakeOrder.cpp"
#include "DeleteOrder.cpp"
#include "DisplayReceipt.cpp"
#include "ModifyOrder.cpp"
#include "DailySummary.cpp"
#include "Exit.cpp"
#include "Employee.cpp"

int main() // main function
{
    computerType computer;
	List cn;
	Parttime pt[10];
    Fulltime ft[10];
    employee e[20];
    int n,m;
    int menu;
    int menu2;
    int menu3;
    b:
		cout << "\t\t==================================================\n";
        cout << "\t\t   Employee - Computer Store Management System \n";
        cout << "\t\t==================================================\n";
        cout << "\t\t---------------------------------------------------\n";
        cout << "\t\t||\t1. Computer Store Management System \t ||\n";
        cout << "\t\t||\t2. Employee Management System\t\t ||\n";
        cout << "\t\t||\t3. Exit\t\t\t\t\t ||\n";
        cout << "\t\t---------------------------------------------------\n";
		cout << endl
			 << "Enter Choice: ";  
	cin >> menu;
	switch(menu)
	{
	case 1:
	{
    do
    {
        system("cls");

        cout << "\t\t==================================================\n";
        cout << "\t\t\t Computer Store Management System \n";
        cout << "\t\t==================================================\n";
        cout << "\t\t---------------------------------------------------\n";
        cout << "\t\t||\t1. Take New Computer Order \t\t ||\n";
        cout << "\t\t||\t2. Delete Latest Order\t\t\t ||\n";
        cout << "\t\t||\t3. Modify Order List \t\t\t ||\n";
        cout << "\t\t||\t4. Print the Receipt                  \t ||\n";
        cout << "\t\t||\t5. Daily Summary of Total Sale \t\t ||\n";
        cout << "\t\t||\t6. Back\t\t\t\t\t ||\n";
        cout << "\t\t---------------------------------------------------\n";

        cout << "\nEnter Choice: ";
        cin >> menu2;

        switch (menu2)
        {
        case 1:
        {
            computer.take_order(); 
            break;
        } // End case 1

        case 2:
        {
            computer.delete_order(); 
            system("PAUSE");
            break;
        } // End case 2

        case 3:
        {
            computer.modify(); 
            system("PAUSE");
            break;
        } // End case 3

        case 4:
        {
            computer.order_list();
            system("PAUSE");
            break;
        } // End case 4
        case 5:
        {
            computer.daily_summary(); 
            system("PAUSE");
            break;
        } // End case 5

        case 6:
        {
            system("cls");
            goto b;
            break;
            system("PAUSE");
        } // End case 6

        default:
        {
            cout << "Invalid input\nPlease re-enter the input\n"
                 << endl;
        } // End default

        } // End Switch

    } while (menu != 6); // End do
}
	case 2:
	{
	do
    {
        system("cls");

        cout << "\t\t==================================================\n";
        cout << "\t\t\t Employee Management System \n";
        cout << "\t\t==================================================\n";
        cout << "\t\t---------------------------------------------------\n";
        cout << "\t\t||\t1. Enter a list of employees \t\t ||\n";
        cout << "\t\t||\t2. Show list of Part-time employees\t ||\n";
        cout << "\t\t||\t3. Show list of Full-time employees \t ||\n";
        cout << "\t\t||\t4. Delete Employee                  \t ||\n";
        cout << "\t\t||\t5. ...                                   ||\n";
        cout << "\t\t||\t6. Back\t\t\t\t\t ||\n";
        cout << "\t\t---------------------------------------------------\n";

      cout << "\nEnter Choice: ";
        cin >> menu3;

        switch (menu3)
        {
        case 1:
        {
            cn.inlist(pt,n,ft,m); 
            break;
        } // End case 1

        case 2:
        {
        	system("cls");
            cn.outPart(pt); 
            system("PAUSE");
            break;
        } // End case 2

        case 3:
        {
        	system("cls");
            cn.outFull(ft); 
            system("PAUSE");
            break;
        } // End case 3

        case 4:
        {
        		char pf;
        		cout<<"\nDo you want to remove full-time or part-time employees? (P or F): ";
        		cin>>pf;
        		pf=toupper(pf);
       		if(pf=='P'){
            	if(n > 0) {
                    int id;
                    cout << "\nDelete Employee.";
                    cout << "\n Enter ID: "; cin >> id;
                    if (cn.deletePart(pt, id) == 1) {
                        n--;
                    }
                }else{
                    cout << "\nEmployee ID does not exist!";
                }	
        	}else if(pf=='F'){
            	if(m > 0) {
                    int id;
                    cout << "\nDelete Employee.";
                    cout << "\n Enter ID: "; cin >> id;
                    if (cn.deleteFull(ft, id) == 1) {

                        m--;
                    }
                }else{
                    cout << "\nEmployee ID does not exist!";
                }
        	}else{
				cout << "Incorrect syntax, re-enter!\n ";
			}		
	
        
            system("PAUSE");
            break;
        } // End case 4
		case 5:
		{
			
			system("PAUSE");
            break;	
		}
        case 6:
        {
            system("cls");
            goto b;
            break;
            system("PAUSE");
        } // End case 6

        default:
        {
            cout << "Invalid input\nPlease re-enter the input\n"
                 << endl;
        } // End default

        } // End Switch

    } while (menu3 != 6); // End do
}
	case 3:
		{
			computer.exit();
			goto a;
			break;
		}
}while (menu != 3);
a: // goto

    cout << "\t\t==================================\n";
    cout << "\t\t\tExit the program!!!\n";
    cout << "\t\t==================================\n\n";

    system("PAUSE");

    return 0;

} // End main function

