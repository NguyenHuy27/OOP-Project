// Function to display receipt
void computerType ::order_list()
{
    int i, num;
    bool found = false; // Variable to search

    string str = "\t\t===========================================\n";

    system("cls");

    node *temp = start_ptr;

    if (temp == NULL) // If list is empty
    {
        cout << endl << str;
        cout << "\t\t\tThere is no Order to show!!!\n\t\t\tThe List is Empty\n";
        cout << str << endl;
    }
    
    else
    {
        cout << "\nEnter the Receipt Number To Print The Receipt: ";
        cin >> num;
        cout << "\n";
        
        while (temp != NULL && !found)
        {
            if (temp->receipt_number == num)
                found = true;

            else{
                temp = temp->next;
                found = false;
			}
		}
            if (found) // Print the receipt
            {
            	ofstream fo;
				fo.open("D:\\orderlist.txt");
				if(fo.is_open()){
                fo << "================================================================================================" << endl;
                fo << "\t\t\t\t  Here is the Ordered list\n";
                fo << "================================================================================================\n"
                     << endl;

                fo << "Receipt Number : " << temp->receipt_number << endl;
                fo << "Customer Name  : " << temp->customerName << endl;
                fo << "Order Date     : " << temp->date << endl
                     << endl;

                fo << "+===================+==============================+====================+=======================+" << endl;
                fo << "|   Computer Type   |         Computer Name        |      Quantity      |     Total Price (VND.)|" << endl;
                fo << "+===================+==============================+====================+=======================+" << endl;

                for (i = 0; i < temp->x; i++)
                {
                    fo << "\t" << temp->type[temp->menu2[i] - 1] << "  \t\t";
                    fo << " " << temp->computerName[temp->menu2[i] - 1] << "\t  ";
                    fo << "\t    " << temp->quantity[i] << "\t";
                    fo << "\t\t" << temp->amount[i] << ".00" << endl;
                    fo << "+-------------------+------------------------------+--------------------+-----------------------+" << endl;
                }

                temp->total = temp->amount[0] + temp->amount[1] + temp->amount[2] + temp->amount[3] + temp->amount[4] + temp->amount[5] + temp->amount[6] + temp->amount[7] + temp->amount[8] + temp->amount[9];
                fo << "\nTotal Bill: " << temp->total << ".00/- VND.";
                fo << "\n\n";

                fo << "Thank You!!!\n";
                fo << "------------\n";
                fo << "================================================================================================\n\n";
            	fo.close();
            	}
            	else 
					cout<<"File not found"<<endl;
        	
        	ifstream fi;
				string str;
				fi.open("D:\\orderlist.txt");
				if(fi.is_open()){
					while(!fi.eof()){
					getline(fi,str);
					cout<<str<<endl;
				}
			fi.close();
		}else
			cout<<"Error!"<<endl;
        }

        if (!found)
        {
            cout << str;
            cout << "\t\t\t  Invalid Receipt Number!\n";
            cout << str << endl;
        }
    }

} 
