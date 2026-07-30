# include <iostream>
# include <fstream>
# include <cstring>
# include <cctype>
# include <iomanip>
using namespace std;

// ---------- ASCII box-border helpers for a nicer console UI ----------
const int BOX_WIDTH = 74;

string h_line(char fill)
{
	string s="+";
	s+=string(BOX_WIDTH,fill);
	s+="+";
	return s;
}

void print_center(string text)
{
	int pad=BOX_WIDTH-(int)text.length();
	if (pad<0)
	{
		pad=0;
	}
	int left_pad=pad/2;
	int right_pad=pad-left_pad;
	cout<<"|"<<string(left_pad,' ')<<text<<string(right_pad,' ')<<"|"<<endl;
}

void print_left(string text)
{
	cout<<"| "<<left<<setw(BOX_WIDTH-1)<<text<<"|"<<endl;
}

void print_banner()
{
	cout<<h_line('=')<<endl;
	print_center("WELCOME TO FAST NUCES HOTEL");
	cout<<h_line('=')<<endl;
}

void print_header(string title)
{
	cout<<endl<<h_line('-')<<endl;
	print_left(title);
	cout<<h_line('-')<<endl;
}

string guest_table_border()
{
	int widths[]={10,15,15,18,15,35};
	string s="+";
	for (int i=0;i<6;i++)
	{
		s+=string(widths[i],'-');
		s+="+";
	}
	return s;
}

string room_table_border()
{
	int widths[]={10,10,10,10};
	string s="+";
	for (int i=0;i<4;i++)
	{
		s+=string(widths[i],'-');
		s+="+";
	}
	return s;
}

// ---------- validated input helpers (added for input validation) ----------
int read_int_in_range(string prompt,int minv,int maxv)
{
	int value;
	while (true)
	{
		cout<<prompt;
		cin>>value;
		if (cin.fail() || value<minv || value>maxv)
		{
			cin.clear();
			cin.ignore(10000,'\n');
			cout<<"[ERROR] Invalid input, please enter a whole number between "<<minv<<" and "<<maxv<<endl;
		}
		else
		{
			break;
		}
	}
	return value;
}

double read_double_min(string prompt,double minv)
{
	double value;
	while (true)
	{
		cout<<prompt;
		cin>>value;
		if (cin.fail() || value<minv)
		{
			cin.clear();
			cin.ignore(10000,'\n');
			cout<<"[ERROR] Invalid input, please enter a number of at least "<<minv<<endl;
		}
		else
		{
			break;
		}
	}
	return value;
}

string read_valid_name(string prompt)
{
	string value;
	while (true)
	{
		cout<<prompt;
		cin>>value;
		bool valid=true;
		for (int i=0;i<(int)value.length();i++)
		{
			if (!isalpha((unsigned char)value[i]))
			{
				valid=false;
				break;
			}
		}
		if (valid && value.length()>0)
		{
			break;
		}
		cout<<"[ERROR] Invalid name, please use letters only"<<endl;
	}
	return value;
}

string read_valid_room_type(string prompt)
{
	string value;
	while (true)
	{
		cout<<prompt;
		cin>>value;
		for (int i=0;i<(int)value.length();i++)
		{
			value[i]=tolower(value[i]);
		}
		if (value=="deluxe" || value=="standard" || value=="suite" || value=="family")
		{
			value[0]=toupper(value[0]);
			break;
		}
		cout<<"[ERROR] Invalid room type, choose from Deluxe, Standard, Suite, Family"<<endl;
	}
	return value;
}

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
	double get_balance()
	{
		return balance;
	}
    
	void show_guests()
{
	cout<<"|"<<left<<setw(10)<<name<<"|"<<setw(15)<<room_id<<"|"<<setw(15)<<number_ppl<<"|"<<setw(18)<<room_type<<"|"<<setw(15)<<balance<<"|"<<setw(35)<<days_stay<<"|"<<endl;
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
		cout<<"|"<<left<<setw(10)<<room_id<<"|"<<setw(10)<<room_type<<"|"<<setw(10)<<cost_day<<"|"<<setw(10)<<status<<"|"<<endl;
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
		cout<<"[ERROR] File not found";
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
    	cout<<"[ERROR] Error file not found";
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
    	cout<<"[ERROR] Error file not found";
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
		
	print_banner();
	print_header("MAIN MENU");
	print_left(" 1. Login as Employee");
	print_left(" 2. Login as Guest");
	cout<<h_line('-')<<endl;
	choice=read_int_in_range("Enter your choice: ",1,2);
	
	int id3=0,password3=0;
	bool logged_in=false;
	if (choice==1)
	{
	for (int i=3;i>0 && !logged_in;i--)
	{
		cout<<endl;
		id3=read_int_in_range("Please enter your id: ",0,999999);
		password3=read_int_in_range("Please enter your password: ",0,999999);
		cout<<endl;
    
    if ((id1==id3 || id2==id3) && (password1==password3 || password2==password3))
    {
    	logged_in=true;
    	break;
	}
    else
    {
    	if (i==1)
    	{
    		cout<<"[ERROR] You are out of tries"<<endl;
    		return 0;
		}
		else
    	cout<<"[ERROR] Wrong Please try again, You have "<<i-1<<" tries left"<<endl;
	}
    }
    }
	
	if (choice==1)
	{
		while (logged_in)	
	{
			int second_option;
			cout<<endl;
			print_header("EMPLOYEE MENU");
			print_left(" 1. View all guests");
			print_left(" 2. View all rooms");
			print_left(" 3. View feedback");
			print_left(" 4. Exit");
			cout<<h_line('-')<<endl;
			second_option=read_int_in_range("Enter your choice: ",1,4);
			if (second_option==1)
			{
				cout<<endl;
				cout<<guest_table_border()<<endl;
				cout<<"|"<<left<<setw(10)<<"Name"<<"|"<<setw(15)<<"Room_ID"<<"|"<<setw(15)<<"No of Persons"<<"|"<<setw(18)
                <<"Room Type"<<"|"<<setw(15)<<"Balance"<<"|"<<setw(35)<<"Days of Stay"<<"|"<<endl;
                cout<<guest_table_border()<<endl;
			   for (int i=0;i<counter;i++)
			   {
			   	g[i].show_guests();
			   }
			   cout<<guest_table_border()<<endl;
			}
		    else if (second_option==2)
			{
				 cout<<endl;
				 cout<<room_table_border()<<endl;
				 cout<<"|"<<left<<setw(10)<<"Room ID"<<"|"<<setw(10)<<"Type"<<"|"<<setw(10)<<"Cost"<<"|"<<setw(10)<<"Status"<<"|"<<endl;
				 cout<<room_table_border()<<endl;
				for (int i=0;i<counter1;i++)
				{
					r[i].show_room();
					
				}
				cout<<room_table_border()<<endl;
			}
			else if (second_option==3)
			{
				cout<<endl;
				print_header("GUEST FEEDBACK");
				view_feedback();
				cout<<endl;
			}
			else if (second_option==4)
			{
				cout<<"Thank you for using the website!\n";
				cout<<"Exiting.....\n";
				break;
			}
	}
}
		
		if (choice==2)
		{
			int guest_choice;
			cout<<endl;
			print_header("GUEST MENU");
			print_left(" 1. Check in");
			print_left(" 2. Check out");
			cout<<h_line('-')<<endl;
			guest_choice=read_int_in_range("Enter your choice: ",1,2);
			
			if (guest_choice==1)
			{
				int room_cost=0;
				cout<<endl;
				print_header("PLEASE ENTER THE FOLLOWING INFORMATION");
    	        name=read_valid_name("Enter your name please: ");
             	room_type=read_valid_room_type("Enter the type of room you want i.e (Deluxe,Standard,Suite,Family): ");
    	        number_ppl=read_int_in_range("Please enter number of persons for stay: ",1,10);
    	        days_stay=read_int_in_range("Enter number of days of your stay: ",1,365);
    	        balance=read_double_min("Lastly please enter your bank balance: ",0);
    	        
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
                

                cout<<"[OK] A room has been allocated to you successfully\nYour Room ID is: "<<r[position].get_room_id()<<endl;
                room_allocated=true;	
                
		    }
	    	else 
		{
        cout<<"[ERROR] Sorry but your bank balance is insufficient. Hope to see you soon :/\n";
        }
        }
		 else 
		{
            cout<<"[ERROR] Sorry no room of your desire is currently available\n";
        }
        }
        if (guest_choice==2)
        {
        	int id;
        	string feedback;
        	bool find=false;
        	cout<<endl;
        	id=read_int_in_range("Please provide your room id: ",1,999999);
			
			for (int i=0;i<counter;i++)
			{
			if (id==g[i].get_room_id())	
        	{
        		find=true;
        		cout<<"Please provide your valuable feedback as it helps us to improve\n";
        	cin.ignore();
        	getline(cin, feedback);
        	while (feedback.length()==0)
        	{
        		cout<<"[ERROR] Feedback cannot be empty, please try again: ";
        		getline(cin, feedback);
        	}
        	
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

            cout<<"[OK] You have successfully checked out. Thank you for staying with us!\n";
            break;
			}
			}
			if (!find)
			{
				cout<<"[ERROR] Sorry, we could not find a booking with that room id\n";
			}
			}		
		if (guest_choice==2)
		{
			cout<<"Removing your name from guests if it exists......\n";
     	}	
		}
		  return 0;
}
