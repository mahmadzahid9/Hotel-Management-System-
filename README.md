# include <iostream>
# include <fstream>
# include <cstring>
# include <iomanip>
using namespace std;

class guest 
{
	private:
		string name;
		string room_type;
        int room_id,number_ppl,days_stay;
	    double balance;
	
	public:
	//setters
    void set_name(string a) 
	{ 
	    name=a;
	}
    void set_room_type(string b) 
	{	
	    room_type=b; 
	}
    void set_room_id(int c) 
	{ 
	    room_id=c;
	}
    void set_number_ppl(int d) 
	{ 
	    number_ppl=d;
	}
    void set_days_stay(int e) 
	{
 	    days_stay=e; 
	}
    void set_balance(double f)
	{   
	    balance=f;
	}
	
	//getters
    string get_name()
    {
    	return name;
	}
	string get_room_type()
	{
		return room_type;
	}
	int get_room_id()
	{
		return room_id;
	}
	int get_number_ppl()
	{
		return number_ppl;
	}
	int get_days_stay()
	{
		return days_stay;
	}
	int get_balance()
	{
		return balance;
	}
    
	void show_guests()
{
	cout<<endl<<left<<setw(10)<<name<<setw(15)<<room_id<<setw(15)<<number_ppl<<setw(18)<<room_type<<setw(15)<<balance<<setw(35)<<days_stay;
}

void add_new_guest() 
{
    ofstream fout("guests.txt",ios::app);
    fout<<left<<setw(10)<<name<<setw(10)<<room_id<<setw(10)<<number_ppl<<setw(10)<<room_type<<setw(10)<<balance<<setw(15)<<days_stay;
	cout<<endl;
	set_name(name);
    set_room_id(room_id);
    set_number_ppl(number_ppl);
	set_room_type(room_type);
	set_balance(balance);
	set_days_stay(days_stay);
    
    fout.close();
}
};
	
	class room
	{	
	private:
		int room_id,cost_day;
		string room_type;
		string status;
			
	public:
	//setters
	void set_room_id(int a)
	{
		room_id=a;
	}
	void set_cost(int b)
	{
		cost_day=b;
	}		
	void set_room_type (string c)
	{
		room_type=c;
	}
	void set_status(string d)
	{
		status=d;
	}
	
	//getters
	int get_room_id()
	{
		return room_id;
	}
	int get_cost()
	{
		return cost_day;
	}
	string get_room_type()
	{
		return room_type;
	}
	string get_status()
	{
		return status;
	}
			
	void show_room()
	{
		cout<<left<<setw(10)<<room_id<<setw(10)<<room_type<<setw(10)<<cost_day<<setw(10)<<status;
		cout<<endl;
	}

};

	void change_status(room r[],int size)
{
    ofstream fout("rooms.txt");
    fout<<left<<setw(10)<<"Room ID"<<setw(10)<<"Type"<<setw(10)<<"Cost"<<setw(10)<<"Status"<< endl;
    for (int i=0;i<size;i++)
    {
        fout <<left<<setw(10)<<r[i].get_room_id()<<setw(10)<<r[i].get_room_type()<<setw(10)<<r[i].get_cost()<<setw(10)<<r[i].get_status()<<endl;
    }
    fout.close();
}

void view_feedback()
{
	ifstream fin("feedback.txt");
	if (!fin)
	{
		cout<<"File not found";
	}
	char ch;
	while (fin.get(ch))
	{
		cout<<ch;
	}
	fin.close();
}


int main ()
{
	int counter=0;
	string name,room_type;
    int room_id,number_ppl,days_stay;
	double balance;
	guest g[150];
	room r[150];
	int id1=5643,password1=1965,id2=6025,password2=1234;
	int choice;
	int cost_day;
	int room_id2;
	string status;
	string room_type2;
	
	ifstream fin("guests.txt");
	string header;
    getline(fin, header);              // clearing the heading
	if (!fin)
	{
    	cout<<"Error Error file not found";
	}
	while (fin>>name>>room_id>>number_ppl>>room_type>>balance>>days_stay)
	{
		g[counter].set_name(name);
		g[counter].set_room_id(room_id);
		g[counter].set_number_ppl(number_ppl);
		g[counter].set_room_type(room_type);
		g[counter].set_balance(balance);
		g[counter].set_days_stay(days_stay);
		counter++;
	}
		fin.close();
	
	int counter1=0;	
	ifstream file("rooms.txt");
	string header2;
    getline(file, header2);              // clearing the heading
	if (!file)
	{
    	cout<<"Error Error file not found";
	}
	while (file>>room_id2>>room_type2>>cost_day>>status)
	{
		r[counter1].set_room_id(room_id2);
		r[counter1].set_room_type(room_type2);
		r[counter1].set_cost(cost_day);
		r[counter1].set_status(status);
		counter1++;
	}
		file.close();	
		
	cout<<"                                        Welcome to Fast Nuces Hotel\n\n";
	cout<<"Please select one of the following options\n1- Login as Employee\n2- Login as Guest\n";
	cin>>choice;
	while (true)
	{
			if (choice==1 || choice==2)
		{
			break;
		}
		
		else if (choice!=1 || choice!=2)
		{
			cout<<"Sorry wrong option please try again\n\n";
			cout<<"Please select one of the following options\n1- Login as Employee\n2- Login as Guest\n";
			cin>>choice;
		}
	}
	
	int id3,password3;
	for (int i=3;i>0;i--)
	{
		if (choice==1)
	{
		cout<<endl;
		cout<<"Please enter your id: ";
		cin>>id3;
		cout<<"Please enter your password: ";
		cin>>password3;
		cout<<endl;
    
    if ((id1==id3 || id2==id3) && (password1==password3 || password2==password3))
    {
    	break;
	}
    else if ((id1!=id3 && id1!=id2) && (password1!=password3 && password2!=password3))
    {
    	if (i==1)
    	{
    		cout<<"You are out of tries";
    		return 0;
		}
		else
    	cout<<"Wrong Please try again, You have "<<i-1<<" tries left";
	}
	}
    }
	
	if (choice==1)
	{
		while (true)	
	{
		if ((id1==id3 || id2==id3) && (password1==password3 || password2==password3))
		{
			int second_option;
			cout<<endl;
			cout<<"Please select one option\n1-View all guests\n2-View all rooms\n3-View feedback\n4-Exit\n";
			cin>>second_option;
			if (second_option==1)
			{
				cout<<endl;
				cout<<left<<setw(10)<<"Name"<<setw(15)<<"Room_ID"<<setw(15)<<"No of Persons"<<setw(18)
                <<"Room Type"<<setw(15)<<"Balance"<<setw(35)<<"Days of Stay"<<endl;
                cout<<"------------------------------------------------------------------------------------------------------------------------";
			   for (int i=0;i<counter;i++)
			   {
			   	g[i].show_guests();
			   }
			}
		    else if (second_option==2)
			{
				 cout<<endl;
				 cout<<left<<setw(10)<<"Room ID"<<setw(10)<<"Type"<<setw(10)<<"Cost"<<setw(10)<<"Status"<< endl;
				 cout<<"------------------------------------------------------------------------------------------------------------------------";
				for (int i=0;i<counter1;i++)
				{
					r[i].show_room();
					
				}
			}
			else if (second_option==3)
			{
				cout<<endl;
				view_feedback();
				cout<<endl;
			}
			else if (second_option==4)
			{
				cout<<"Thank you for using the website!\n";
				cout<<"Exiting.....\n";
				break;
			}
			else if (second_option>4 || second_option<0)
			{
				cout<<"Please try again\n";
			}
		}
	}
}
		
		if (choice==2)
		{
			int guest_choice;
			cout<<endl;
			cout<<"Hey welcome Please select one of the following options\n";
			cout<<"1-Check in\n2-Check out\n";
			cin>>guest_choice;
			
			while (true)
	        {
			if (guest_choice==1 || guest_choice==2)
		{
			break;
		}
		   else if (guest_choice!=1 && guest_choice!=2)
		{
			cout<<"Sorry wrong option please try again\n\n";
			cout<<"Please select one of the following options\n1-Check in\n2-Check out\n";
			cin>>guest_choice;
		}
	        }
			
			if (guest_choice==1)
			{
				int room_cost=0;
				cout<<endl;
				cout<<"Please enter the following information\n";
    	        cout<<"Enter your name please: ";
    	        cin>>name;
             	cout<<"Enter the type of room you want i.e (Deluxe,Standard,Suite,Family): ";
            	cin>>room_type;
    	        cout<<"Please enter number of persons for stay: ";
    	        cin>>number_ppl;
    	        cout<<"Enter number of days of your stay: ";
    	        cin>>days_stay;
    	        cout<<"Lastly please enter your bank balance: ";
    	        cin>>balance;
    	        
    	bool room_allocated=false;
        int position=-1;

        for (int i=0;i<counter1;i++)
		 {
            if (r[i].get_room_type()==room_type && r[i].get_status()=="Available")
			{
                room_cost=r[i].get_cost();
                position=i;
                break;
            }
        }

        if (position!=-1) 
		{
            int total_cost=room_cost*days_stay;

            if (balance>=total_cost)
			 {
                r[position].set_status("Occupied");

                g[counter].set_name(name);
                g[counter].set_room_type(room_type);
                g[counter].set_room_id(r[position].get_room_id());
                g[counter].set_number_ppl(number_ppl);
                g[counter].set_days_stay(days_stay);
                g[counter].set_balance(balance);
                g[counter].add_new_guest();
                change_status(r,counter1);
                counter++;
                

                cout <<"A room has been allocated to you successfully\nYour Room ID is: "<<r[position].get_room_id()<<endl;
                room_allocated=true;	
                
		    }
	    	else 
		{
        cout << "Sorry but your bank balance is insufficient. Hope to see you soon :/\n";
        }
        }
		 else 
		{
            cout << "Sorry no room of your desire is currently available\n";
        }
        }
        if (guest_choice==2)
        {
        	int id;
        	string feedback;
        	bool find=false;
        	cout<<endl;
        	cout<<"Please provide your room id: ";
            cin>>id;
			
			for (int i=0;i<counter;i++)
			{
			if (id==g[i].get_room_id())	
        	{
        		find=true;
        		cout<<"Please provide your valuable feedback as it helps us to improve\n";
        	cin.ignore();
        	getline(cin, feedback);
        	
        	ofstream fout("feedback.txt",ios ::app);
        	fout<<endl<<left<<setw(10)<<g[i].get_name()<<setw(10)<<feedback;
        	fout.close();
        	
        	ofstream file2("guests.txt");
            file2<<left<<setw(10)<<"Name"<<setw(10)<<"Room_ID"<<setw(10)<<"No of Persons"<<setw(10)
            <<"Room Type"<<setw(10)<<"Balance"<<setw(15)<<"Days of Stay"<<endl;

            for (int j=0;j<counter;j++)
            {
                if (j!=i) 
                {
                file2<<left<<setw(10)<<g[j].get_name()<<setw(10) << g[j].get_room_id()<<setw(10)<< g[j].get_number_ppl()<<setw(10)<<g[j].get_room_type()
				<<setw(10)<<g[j].get_balance()<<setw(15) << g[j].get_days_stay()<<endl;
                }
            }
            file2.close();

            for (int k=0;k<counter1;k++)
            {
                if (r[k].get_room_id()==id)
                {
                    r[k].set_status("Available");
                    break;
                }
            }
            change_status(r,counter1);

            cout << "You have successfully checked out. Thank you for staying with us!\n";
            break;
			}
			}
			}		
		if (guest_choice==2)
		{
			cout<<"Removing your name from guests if it exists......\n";
     	}	
		}
		  return 0;
}
    
