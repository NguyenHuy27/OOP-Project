//Employee class
class employee{
	public:
		int id;
		string name;
		int age;
	employee(){
		this->id = 0;
		
		this->age = 0;
	}
	virtual void input();
	virtual void output();
	float bonus(){
		return 0;
	}
};
void employee::input(){
	cout<<"Enter employee ID: ";
	cin>>id;
	cin.ignore();
	cout<<"Enter employee name: ";
	getline(cin,name);	
	cout<<"Enter age: ";
	cin >> age;
}
void employee::output(){
    cout << "\t" << this->id << "\t\t";
    cout << this->name  ;
    cout << "\t\t" << this->age << "\t\t";
}
class Parttime:public employee{
	public:
		char shift;
		int workTime;
		int salary;
	Parttime(){
		this->shift;
		this->workTime=0;
		this->salary=0;
	}
	void input();
	void output();
	float bonus(){
		if(this->workTime>6)
			return salary+(workTime - 6)*200;
		else
			return salary;
	}
};
void Parttime::input(){
	employee::input();
a:
	cout<<"What shift do you work in ?"
		<<endl
		<<"( Morning:M - Afternoon:A - Night: N ): ";
	cin>>shift;
	shift=toupper(shift);
	if(shift!='M'&&shift!='A'&&shift!='N'){
		cout<<"Incorrect syntax, please re-enter !";
		goto a;
	}else{
		cout <<"Working time in one shift: ";
		cin	>> this->workTime;
		cout <<"Solid salary for a month : ";
		cin >> this->salary;
	}
}
void Parttime::output(){
	employee::output();
	cout<<this->shift<<"\t\t\t"<<this->workTime<<"\t\t\t"<<this->bonus()<<"\t\t"<<endl;
}
class Fulltime:public employee{
	public:
		int kpi;
		int salary;
	void input();
	void output();
	float bonus(){
		if(kpi>15)
			return salary+(kpi-10)*100;
		else
			return salary;
	}
};
void Fulltime::input(){
	employee::input();
	cout<<"Number of machines sold in the month: ";
	cin>>kpi;
	cout<<"Solid salary for a month :";
	cin>>salary;
}
void Fulltime::output(){
	employee::output();
	cout<<this->kpi<<"\t\t"<<this->salary<<"\t\t"<<endl;
}
class List{
	public:
		vector <Parttime> p;
        vector <Fulltime> f;
	void inlist(Parttime pt[], int &n, Fulltime ft[], int &m){
            n=0;
            m=0;
            
            while(true){
            	system("cls");
                char lc;
                cout<<"Are you a full-time or part-time employee?(P or F): ";
                cin>>lc;
                lc=toupper(lc);
                if(lc=='P'){
                    pt[n].input();
                    p.push_back(pt[n]);
                    n++;
                }else if(lc=='F'){
                    ft[m].input();
                    f.push_back(ft[m]);
                    m++;
                }else{
					cout << "Incorrect syntax, re-enter!\n ";
				}
                char c;
                b:
                cout<<"Do you want to continue? (Y or N):";
                cin>>c;
                c=toupper(c);
            	if(c!='Y'&&c!='N'){
            		cout<<"Incorrect syntax, re-enter!\n";
            		goto b;
            	}else if(c=='N'){
                    break;
                }
            }
        }	    	
        void outPart(Parttime pt[]){
            if(p.size()!=0){
                cout<<"Employee Parttime List: \n";
                cout << "+================+===================+=================+===================+==========================+============================+" << endl;
                cout << "|       ID       |        NAME       |       AGE       |       SHIFT       |       WORKING TIME       |       Salary + Bonus       |" << endl;
                cout << "+================+===================+=================+===================+==========================+============================+" << endl;
                for(int i=0;i<p.size();i++){
                pt[i].output();
                }
                cout << "+----------------+-------------------+-----------------+-------------------+--------------------------+----------------------------+" << endl;
            }
        }
        void outFull(Fulltime ft[]){    
            if(f.size()!=0){
                cout<<"Employee Fulltime List: \n";
                cout << "+================+===================+=================+=================+============================+" << endl;
                cout << "|       ID       |        NAME       |       AGE       |       KPI       |       Salary + Bonus       |" << endl;
                cout << "+================+===================+=================+=================+============================+" << endl;
                for(int j=0;j<f.size();j++){
                ft[j].output();
                }
                cout << "+----------------+-------------------+-----------------+-----------------+----------------------------+" << endl;
            }
        }
    	
	int deletePart(Parttime pt[],int id){
	int found = 0;
    for(int i = 0; i < p.size(); i++) {
        if (pt[i].id == id) {
            found = 1;
            
            for (int j = i; j < p.size(); j++) {
                pt[j] = pt[j+1];
            }
            cout << "\n Removed employee with id = " << id;
            
            break;
        }
    }
    if (found == 0) {
        cout<<"\n Employee ID does not exist.";
        return 0;
    } else {
        return 1;
    }
}	
	int deleteFull(Fulltime ft[],int id){
	int found = 0;
    for(int i = 0; i < f.size(); i++) {
        if (ft[i].id == id) {
            found = 1;
            
            for (int j = i; j < f.size(); j++) { 
                ft[j] = ft[j+1];
            }
            cout << "\n Removed employee with id = " << id;
            
            break;
        }
    }
    if (found == 0) {
        cout<<"\n Employee ID does not exist.";
        return 0;
    } else {
        return 1;
    }
}

};

