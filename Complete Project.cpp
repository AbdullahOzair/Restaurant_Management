#include <iostream>
#include <vector>
#include <sstream>
#include <string>
#include <iomanip>
#include <conio.h>
#include <windows.h>
#include <fstream>
using namespace std;

/* run this program using the console pauser or add your own getch, system("pause") or input loop */
class Information;
class UserData 
{
	private:
		string Name;
		string Address;
		string Email;
		string Password;
		string Phone;
		string Catagroy;
		UserData* RecordNext;

	public:
		UserData()
		{
			Name="";
			Address="";
			Email="";
			Password="";
			Phone="";
			Catagroy="";
			RecordNext = NULL;
		}		
		void setName(string n)
		{
			Name = n;
		}
		void setAddress(string a)
		{
			Address = a;
		}
		void setEmail(string e)
		{
			Email = e;
		}
		void setPassword(string pw)
		{
			Password = pw;
		}
		void setPhone(string ph)
		{
			Phone = ph;
		}
		void setCatagroy(string c)
		{
			Catagroy = c;
		}
		void setRecordNext(UserData* r)
		{
			RecordNext = r;
		}
		string getName()
		{
			return Name;
		}
		string getAddress()
		{
			return Address;
		}
		string getEmail()
		{
			return Email;
		}
		string getPassword()
		{
			return Password;
		}
		string getPhone()
		{
			return Phone;
		}
		string getCatagroy()
		{
			return Catagroy;
		}
		UserData* getRecordNext()
		{
			return RecordNext;
		}	
};

class FoodData 
{
	private:
	    string foodName;
		int quantity;
		string itemName;
		int itemPrice;
		int itemAmo;
		int totalprice;
		int totalItemPrice;
		FoodData* FoodRecordNext;
	public:
		FoodData()
		{
			quantity=0;
			foodName ="";
			itemName ="";
			itemPrice = 0;
			itemAmo = 0;
			totalprice = 0;
			totalItemPrice = 0;
			FoodRecordNext = NULL;
		}
		void setFoodName(string f)
		{
			foodName = f;
		}
		void setItemName(string in)
		{
			itemName = in;
		}
		void setQuantity(int q)
		{
			quantity = q;
		}
		void setItemPrice(int ip)
		{
			itemPrice = ip;
		}
		void setTotalPrice(int tp)
		{
			totalprice = tp;
		}
		void setItemAmo(int ia)
		{
			itemAmo = ia;
		}
		void setTotalItemPrice(int tp)
		{
			totalItemPrice = tp;
		}
		string getFoodName()
		{
			return foodName;
		}
		string getItemName()
		{
			return itemName;
		}
		void setFoodRecordNext(FoodData* r)
		{
			FoodRecordNext = r;
		}
		int getQuantity()
		{
			return quantity;
		}
		int getItemPrice()
		{
			return itemPrice;
		}
		int getItemAmo()
		{
			return itemAmo;
		}
		int getTotalItemPrice()
		{
			return totalItemPrice;
	    }
	    int getTotalPrice()
		{
			return totalprice;
		}
		FoodData* getFoodRecordNext()
		{
			return FoodRecordNext;
		}
};
class Information
{
	private:
		int total;
		UserData* head;
		UserData* head1;
		UserData* nextNode;
		FoodData* food;
		FoodData* foodnextNode;
		//FoodMenu  menu;
		string email;
		string password;
	public:
		Information()
		{
			total = 0;
			head = NULL;
			head1 = NULL;
		}
		void UPDATE_FOOD_FILE(string n,string p);
//		{
//			ifstream File("FOOD.txt");
//			vector<string> line;
//			if(File.is_open())
//			{
//				string l;
//				while(getline(File,l))
//				{
//					line.push_back(l);
//				}
//			}
//			File.close();
//			
//			for(string& readLine : line)
//			{
//				size_t position = readLine.find(n); 
//				int s = n.length();
//				if(position != string::npos)
//				{
//					readLine.replace(s+1,readLine.length(),p);
//					break;
//				}
//			}
//			ofstream oFile("FOOD.txt", ios::out | ios::trunc);
//			if(oFile.is_open())
//			{
//				for(const string& updateLine : line)
//				{
//					oFile<<updateLine<<endl;
//				}
//			}
//			oFile.close();
//		}
		//seprate line function(file wali information ko alada karna ka lia)
		vector<string> parseCommadString(string line)
        {
            vector<string> result;
            stringstream s_stream(line);

            while(s_stream.good())
            {
	            string substr;
	            getline(s_stream,substr,',');
	            result.push_back(substr);
            }
            return result;
        }
        //seprate line function(file wali information ko alada karna ka lia)
		vector<string> foodString(string line)
        {
            vector<string> result;
            stringstream s_stream(line);

            while(s_stream.good())
            {
	            string substr;
	            getline(s_stream,substr,'=');
	            result.push_back(substr);
            }
            return result;
        }
        // Customer Sign Function (ya function file ma data store karata ha)
		void SIGN_UP (string n,string p,string a,string e,string pw,string c)
		{
			UserData* newNode = new UserData;
			newNode->setName(n);
			newNode->setPhone(p);
			newNode->setAddress(a);
			newNode->setEmail(e);
			newNode->setPassword(pw);
			newNode->setCatagroy(c);
			newNode->setRecordNext(NULL);
			if(head==NULL)
			{
				head = newNode;
				SET_File_CUSTOMER(newNode);
			}else
			{
				nextNode = head;
				while(nextNode->getRecordNext() != NULL)
				{
					nextNode = nextNode->getRecordNext();
				}
				nextNode->setRecordNext(newNode);
				SET_File_CUSTOMER(newNode);
			}
			
		}
		// Employ Function (ya function file ma data store karata ha)
		void EMPLOY_SIGH_UP(string n,string p,string a,string e,string pw,string c)
		{
			UserData* newNode = new UserData;
			newNode->setName(n);
			newNode->setPhone(p);
			newNode->setAddress(a);
			newNode->setEmail(e);
			newNode->setPassword(pw);
			newNode->setCatagroy(c);
			newNode->setRecordNext(NULL);
			if(head1==NULL)
			{
				head1 = newNode;
				SET_File_EMPLOY(newNode);
			}else
			{
				UserData* nextNode1 = head1;
				while(nextNode1->getRecordNext() != NULL)
				{
					nextNode1 = nextNode1->getRecordNext();
				}
				nextNode1->setRecordNext(newNode);
				SET_File_EMPLOY(newNode);
			}	
		}
		// file to linklist Function (ya function file ma sa data lata ha or SSL ma store karata ha)
		void GET_FILE_DATA(string n,string p,string a,string e,string pw,string c)
		{
			UserData* newNode = new UserData;
			newNode->setName(n);
			newNode->setPhone(p);
			newNode->setAddress(a);
			newNode->setEmail(e);
			newNode->setPassword(pw);
			newNode->setCatagroy(c);
			newNode->setRecordNext(NULL);
			if(head==NULL)
			{
				head = newNode;
			}else
			{
				nextNode = head;
				while(nextNode->getRecordNext() != NULL)
				{
					nextNode = nextNode->getRecordNext();
				}
				nextNode->setRecordNext(newNode);
				
			}	
		}
		//Employ file to linklist Function (ya function file ma sa data lata ha or SSL ma store karata ha)
		void MAKE_FILE_Employ(string n,string p,string a,string e,string pw,string c)
		{
			UserData* newNode = new UserData;
			newNode->setName(n);
			newNode->setPhone(p);
			newNode->setAddress(a);
			newNode->setEmail(e);
			newNode->setPassword(pw);
			newNode->setCatagroy(c);
			newNode->setRecordNext(NULL);
			if(head1==NULL)
			{
				head1 = newNode;
			}else
			{
				UserData* nextNode1 = head1;
				while(nextNode1->getRecordNext() != NULL)
				{
					nextNode1 = nextNode1->getRecordNext();
				}
				nextNode1->setRecordNext(newNode);
			}	
		}
		//SSL display Function
		void DisplayRecord()
	    {
		    UserData* newNode = head;
            while (newNode != NULL) 
		    { 
                cout <<"\t Name : "<< newNode->getName();
                cout <<"\t Phone NO : "<< newNode->getPhone();
                cout <<"\t ADRESS : "<< newNode->getAddress();
                cout <<"\t EMAIL : "<< newNode->getEmail();
                cout <<"\t PASWORD : "<< newNode->getPassword();
                cout <<"\t Catagory : "<< newNode->getCatagroy();
                newNode = newNode->getRecordNext();
                cout<<endl;
            }
            cout << endl;
     	}
     	void DisplayRecord2()
	    {
		    UserData* newNode = head1;
            while (newNode != NULL) 
		    { 
                cout <<"\t Name : "<< newNode->getName();
                cout <<"\t Phone NO : "<< newNode->getPhone();
                cout <<"\t ADRESS : "<< newNode->getAddress();
                cout <<"\t EMAIL : "<< newNode->getEmail();
                cout <<"\t PASWORD : "<< newNode->getPassword();
                cout <<"\t Catagory : "<< newNode->getCatagroy();
                newNode = newNode->getRecordNext();
                cout<<endl;
            }
            cout << endl;
     	}
     	//store Coustumer data to File 
	    void SET_File_CUSTOMER(UserData* n)
		{
		    fstream File("Customer.txt",ios::app);
		    File<<n->getName()<<","<<n->getPhone()<<","<<n->getAddress()<<","<<n->getEmail()<<","<<n->getPassword()<<","<<n->getCatagroy()<<"\n";
		 	File.close();
		}
		//store Employ data to File 
	    void SET_File_EMPLOY(UserData* n)
		{
		 	fstream File("Employ.txt",ios::app);
		 	File<<n->getName()<<","<<n->getPhone()<<","<<n->getAddress()<<","<<n->getEmail()<<","<<n->getPassword()<<","<<n->getCatagroy()<<"\n";
		 	File.close();
		}
		//saparate Custumer record
		void GET_File_CUSTOMER()
		{
			fstream File;
			File.open("Customer.txt",ios::in);
			if(File.is_open())
			{
			    string line;
			    while(getline(File,line))
			    {
			        vector<string> Sline=parseCommadString(line);
			        const char* name = Sline.at(0).c_str();
			        const char* Phone = Sline.at(1).c_str();
			        const char* adress = Sline.at(2).c_str();
			        const char* Email = Sline.at(3).c_str();
			        const char* Password = Sline.at(4).c_str();
			        const char* Catagroy = Sline.at(5).c_str();
			        GET_FILE_DATA(name,Phone,adress,Email,Password,Catagroy);
			    }
			}
			File.close();
	    }
	    //saparate Employ record
		void GET_File_EMPLOY()
		{
			fstream File;
			File.open("Employ.txt",ios::in);
			if(File.is_open())
			{
			    string line;
			    while(getline(File,line))
			    {
			        vector<string> Sline=parseCommadString(line);
			        const char* name = Sline.at(0).c_str();
			        const char* Phone = Sline.at(1).c_str();
			        const char* adress = Sline.at(2).c_str();
			        const char* Email = Sline.at(3).c_str();
			        const char* Password = Sline.at(4).c_str();
			        const char* Catagroy = Sline.at(5).c_str();
			        MAKE_FILE_Employ(name,Phone,adress,Email,Password,Catagroy);
			    }
			}
			File.close();
	    }
	    //Login
		string Login(string e,string p)
		{
			UserData* newNode = head;
			UserData* newNode1 = head1;
			while(newNode->getRecordNext() != NULL || newNode1->getRecordNext() != NULL)
			{
				if(e == "admin" && p == "pword")
				{
					return "A";
				}
			    else if(newNode1->getEmail() == e && newNode1->getPassword() == p && newNode1->getCatagroy() == "A")
				{
					newNode1->setCatagroy("P");
					return "E";
				}else if(newNode->getEmail() == e && newNode->getPassword() == p && newNode->getCatagroy() == "C")
				{
					return "C";
				}
				if(newNode->getRecordNext() != NULL)
				    newNode = newNode->getRecordNext();
				if(newNode1->getRecordNext() != NULL)
				    newNode1 = newNode1->getRecordNext();
			}
			return "F";
		}
		
		//display coustmer data 
		void Display_File_CUSTOMER()
		{
			ifstream File("Customer.txt");
			cout<<setw(20)<<"\n             ______________________________________________________________________________________________________\n";
			cout<<setw(20)<<"|  NAME"<<setw(15)<<"PHONE"<<setw(30)<<"ADDRESS"<<setw(30)<<"EMAIL"<<setw(20)<<"PASSWORD|"<<endl;
			cout<<setw(20)<<"             ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n";
			string line;
			while(getline(File,line))
			{
				vector<string> Sline=parseCommadString(line);
			    const char* name = Sline.at(0).c_str();
			    const char* Phone = Sline.at(1).c_str();
			    const char* adress = Sline.at(2).c_str();
			    const char* Email = Sline.at(3).c_str();
			    const char* Password = Sline.at(4).c_str();
				cout<<setw(20)<<name<<setw(15)<<Phone<<setw(30)<<adress<<setw(30)<<Email<<setw(20)<<Password<<endl;
			}
			File.close();
		}
		//Display Coustmer data
		void Display_File_Employ()
		{
			ifstream File("Employ.txt");
			cout<<setw(20)<<"\n             ______________________________________________________________________________________________________\n";
			cout<<setw(20)<<"|  NAME"<<setw(15)<<"PHONE"<<setw(30)<<"ADDRESS"<<setw(30)<<"EMAIL"<<setw(20)<<"PASSWORD|"<<endl;
			cout<<setw(20)<<"             ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n";
			string line;
			while(getline(File,line))
			{
				vector<string> Sline=parseCommadString(line);
			    const char* name = Sline.at(0).c_str();
			    const char* Phone = Sline.at(1).c_str();
			    const char* adress = Sline.at(2).c_str();
			    const char* Email = Sline.at(3).c_str();
			    const char* Password = Sline.at(4).c_str();
				cout<<setw(20)<<name<<setw(15)<<Phone<<setw(30)<<adress<<setw(30)<<Email<<setw(20)<<Password<<endl;
			}
			File.close();
		}
		//display Employ attendance
		void Display_Employ_Attendence()
		{
			UserData* newNode = head1;
			cout<<setw(50)<<"                                ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~               \n";
			cout<<setw(50)<<"                                |       present(P)          |         Absent(A)            |               \n";
			cout<<setw(50)<<"                                ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~               \n";
			cout<<setw(50)<<"                                |       NAME                |       Attendence             |               \n";
			cout<<setw(50)<<"                                ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~               \n";
			string line;
			while(newNode != NULL)
			{
				cout<<setw(33)<<"|"<<setw(11)<<newNode->getName()<<setw(17)<<"|"<<setw(11)<<newNode->getCatagroy()<<setw(36)<<"|               \n";
				cout<<setw(50)<<"                                ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~               \n";
				newNode = newNode->getRecordNext();
			}
		}
//		Update value on file
//		void UPDATE_FOOD_FILE(string n,string p)
//		{
//			ifstream File("FOOD.txt");
//			vector<string> line;
//			if(File.is_open())
//			{
//				string l;
//				while(getline(File,l))
//				{
//					line.push_back(l);
//				}
//			}
//			File.close();
//			
//			for(string& readLine : line)
//			{
//				size_t position = readLine.find(n); 
//				int s = n.length();
//				if(position != string::npos)
//				{
//					readLine.replace(s+1,readLine.length(),p);
//					break;
//				}
//			}
//			ofstream oFile("FOOD.txt", ios::out | ios::trunc);
//			if(oFile.is_open())
//			{
//				for(const string& updateLine : line)
//				{
//					oFile<<updateLine<<endl;
//				}
//			}
//			oFile.close();
//		}
        // store food to file
		void STORE_FOOD_TO_FILE (string f,int q)
		{
			ifstream File("FOOD.txt");
			string line;
			const char* quantity;
			const char* Nfood;
			int a,add;
		    while(getline(File,line))
			{
			    vector<string> Sline=foodString(line);
			    Nfood = Sline.at(0).c_str();
			    quantity = Sline.at(1).c_str();
			    if(Nfood==f)
				{
					stringstream convert;
			        convert<<quantity;
			        convert>>a;
			        add = a+q;
			        string str =to_string(add);
			        UPDATE_FOOD_FILE(f,str);
					break;
				}
			}      
			File.close();
			if(Nfood != f)
			{
				FoodData* newNode = new FoodData;
			    newNode->setFoodName(f);
			    newNode->setQuantity(q);
			    newNode->setFoodRecordNext(NULL);
			    if(food==NULL)
			    {
				    food = newNode;
				    SET_FOOD_FILE(newNode);
			    }
				else
			    {
				    foodnextNode = food;
				    while(foodnextNode->getFoodRecordNext() != NULL)
				    {
					    foodnextNode = foodnextNode->getFoodRecordNext();
				    }
				    foodnextNode->setFoodRecordNext(newNode);
				    SET_FOOD_FILE(newNode);
			    }
			}
		}
		//store Food data to File 
	    void SET_FOOD_FILE(FoodData* n)
		{
		    fstream File("FOOD.txt",ios::app);
		    File<<n->getFoodName()<<"="<<n->getQuantity()<<"\n";
		 	File.close();
		}
		
		void Display_File_FOOD()
		{
			ifstream File("FOOD.txt");
			cout<<setw(50)<<"                                |       FOOD                |       QUANTITY               |               \n";
			cout<<setw(50)<<"                                ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~               \n";
			string line;
			while(getline(File,line))
			{
				vector<string> Sline=foodString(line);
			    const char* food = Sline.at(0).c_str();
			    const char* quantity = Sline.at(1).c_str();
				cout<<setw(33)<<"|"<<setw(11)<<food<<setw(17)<<"|"<<setw(11)<<quantity<<setw(36)<<"|               \n";
				cout<<setw(50)<<"                                ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~               \n";
			}
			File.close();
		}
		
};

class FoodMenu
{
	private:
		int temporary;
		int temp;
		FoodData    *bill;
		Information  info;
	public:
		FoodMenu()
		{
			temp = 0;
			temporary = 0;
			bill=NULL;
		}
		//seprate line function(file wali information ko alada karna ka lia)
		vector<string> foodString(string line)
        {
            vector<string> result;
            stringstream s_stream(line);

            while(s_stream.good())
            {
	            string substr;
	            getline(s_stream,substr,'=');
	            result.push_back(substr);
            }
            return result;
        }
		//Burger function
		void Burger(int cho,int amount )
		{
			switch(cho)
			{
				case 1:
					BILL_RECIEPT("ZINGER_BURGER",350,amount);
					Change_Value("BURGER",amount);
					break;					 
				case 2:
					BILL_RECIEPT("CRUNCH_BURGER",230,amount);
					Change_Value("BURGER",amount);				
				    break;
				case 3:
					BILL_RECIEPT("DOUBLE_PATTY_BURGER",450,amount);
					Change_Value("BURGER",amount);					
				    break;
				case 4:
					BILL_RECIEPT("CHEESE_BURGER",400,amount);
					Change_Value("BURGER",amount);					
				    break;
				case 5:
					BILL_RECIEPT("ZINGER_SUPREME_BURGER",520,amount);
					Change_Value("BURGER",amount);						
				    break;										
		    }			
		}
		//Pizza Function
		void PIZZA(int t,char size,int s)
		{
			switch(t)
			{
				case 1:
					switch(size)
					{
						case 'S':
							BILL_RECIEPT("FAJITA_SMALL",450,s);
					        Change_Value("PIZZA",s);
							break;
						case 'M':
							BILL_RECIEPT("FAJITA_MEDIUM",850,s);
					        Change_Value("PIZZA",s);
							break;
						case 'L':
							BILL_RECIEPT("FAJITA_LARGE",1250,s);
					        Change_Value("PIZZA",s);
							break;
					}
					break;					 
				case 2:
				    switch(size)
					{
						case 'S':
							BILL_RECIEPT("TIKKA_SMALL",450,s);
					        Change_Value("PIZZA",s);
							break;
						case 'M':
							BILL_RECIEPT("TIKKA_MEDIUM",850,s);
					        Change_Value("PIZZA",s);
							break;
						case 'L':
							BILL_RECIEPT("TIKKA_LARGE",1250,s);
					        Change_Value("PIZZA",s);
							break;
					}				
				    break;
				case 3:
					switch(size)
					{
						case 'S':
							BILL_RECIEPT("CHEESE_LODER_SMALL",450,s);
					        Change_Value("PIZZA",s);
							break;
						case 'M':
							BILL_RECIEPT("CHEESE_LODER_MEDIUM",850,s);
					        Change_Value("PIZZA",s);
							break;
						case 'L':
							BILL_RECIEPT("CHEESE_LODER_LARGE",1250,s);
					        Change_Value("PIZZA",s);
							break;
					}					
				    break;
				case 4:
					switch(size)
					{
						case 'S':
							BILL_RECIEPT("BARBIE_KU_SMALL",450,s);
					        Change_Value("PIZZA",s);
							break;
						case 'M':
							BILL_RECIEPT("BARBIE_KU_MEDIUM",850,s);
					        Change_Value("PIZZA",s);
							break;
						case 'L':
							BILL_RECIEPT("BARBIE_KU_LARGE",1250,s);
					        Change_Value("PIZZA",s);
							break;
					}					
				    break;
				case 5:
					switch(size)
					{
						case 'S':
							BILL_RECIEPT("AZ_SPECIAL_SMALL",450,s);
					        Change_Value("PIZZA",s);
							break;
						case 'M':
							BILL_RECIEPT("AZ_SPECIAL_MEDIUM",850,s);
					        Change_Value("PIZZA",s);
							break;
						case 'L':
							BILL_RECIEPT("AZ_SPECIAL_LARGE",1250,s);
					        Change_Value("PIZZA",s);
							break;
					}					
				    break;
										
		    }
			
		}
		//SHAWARMA
		void SHAWARMA(int t,char size,int s)
		{
			switch(t)
			{
				case 1:
					switch(size)
					{
						case 'S':
							BILL_RECIEPT("ZINGER_SHAWARMA_SMALL",170,s);
					        Change_Value("SHAWARMA",s);
							break;
						case 'L':
							BILL_RECIEPT("ZINGER_SHAWARMA_LARGE",250,s);
					        Change_Value("SHAWARMA",s);
							break;
					}
					break;					 
				case 2:
				    switch(size)
					{
						case 'S':
							BILL_RECIEPT("CHICKEN_SHAWARMA_SMALL",170,s);
					        Change_Value("SHAWARMA",s);
							break;
						case 'L':
							BILL_RECIEPT("CHICKEN_SHAWARMA_LARGE",210,s);
					        Change_Value("SHAWARMA",s);
							break;
					}				
				    break;
				case 3:
					switch(size)
					{
						case 'S':
							BILL_RECIEPT("CHEESE_SHAWARMA_SMALL",200,s);
					        Change_Value("SHAWARMA",s);
							break;
						case 'L':
							BILL_RECIEPT("CHEESE_SHAWARMA_LARGE",280,s);
					        Change_Value("SHAWARMA",s);
							break;
					}					
				    break;
				case 4:
					switch(size)
					{
						case 'S':
							BILL_RECIEPT("A&Z_SPECIAL_SHAWARMA_SMALL",250,s);
					        Change_Value("SHAWARMA",s);
							break;
						case 'L':
							BILL_RECIEPT("A&Z_SPECIAL_SHAWARMA_LARGE",320,s);
					        Change_Value("SHAWARMA",s);
							break;
					}					
				    break;
										
		    }
			
		}
		//Sandwich Function
		void SANDWITCH(int cho,int amount)
		{
			switch(cho)
			{
				case 1:
					BILL_RECIEPT("CHICKEN_SANDWITCH",350,amount);
					Change_Value("SANDWITCH",amount);
					break;					 
				case 2:
					BILL_RECIEPT("CLUB_SANDWITCH",230,amount);
					Change_Value("SANDWITCH",amount);				
				    break;										
		    }			
		}
		//Fish Function
		void FISH(int cho,int amount)
		{
			switch(cho)
			{
				case 1:
					BILL_RECIEPT("FINGER_FISH",220,amount);
					Change_Value("FISH",amount);
					break;
				case 2:
					BILL_RECIEPT("MASALA_FISH",160,amount);
					Change_Value("FISH",amount);				
				    break;										
		    }			
		}
		//Chicken Piece
		void CHICKEN_PIECE(int cho)
		{
			switch(cho)
			{
				case 1:
					BILL_RECIEPT("1_CHICKEN_PIECE",250,1);
					Change_Value("CHICKENPIECE",1);
					break;					 
				case 2:
					BILL_RECIEPT("3_CHICKEN_PIECE",630,1);
					Change_Value("CHICKENPIECE",3);				
				    break;
				case 3:
					BILL_RECIEPT("5_CHICKEN_PIECE",1050,1);
					Change_Value("CHICKENPIECE",5);					
				    break;
				case 4:
					BILL_RECIEPT("12_FD_CHICKEN_PIECE",1700,1);
					Change_Value("CHICKENPIECE",12);					
				    break;									
		    }			
		}
		//Chicken Wings
		void CHICKEN_WINGS(int cho)
		{
			switch(cho)
			{
				case 1:
					BILL_RECIEPT("8pc_CHICKEN_WINGS",520,1);
					Change_Value("CHICKENWINGS",8);
					break;					 
				case 2:
					BILL_RECIEPT("14pc_CHICKEN_WINGS",950,1);
					Change_Value("CHICKENWINGS",14);				
				    break;									
		    }			
		}
		//Chicken NUGGETS
		void CHICKEN_NUGGETS(int cho)
		{
			switch(cho)
			{
				case 1:
					BILL_RECIEPT("8pc_CHICKEN_NUGGETS",650,1);
					Change_Value("CHICKENNUGGETS",8);
					break;					 
				case 2:
					BILL_RECIEPT("14pc_CHICKEN_NUGGETS",1150,1);
					Change_Value("CHICKENNUGGETS",14);				
				    break;									
		    }			
		}
		//Chicken NUGGETS
		void CHICKEN_HOT_SPICY(int cho)
		{
			switch(cho)
			{
				case 1:
					BILL_RECIEPT("8pc_HOT_&_SPICE",600,1);
					Change_Value("HOT&SPICY",8);
					break;					 
				case 2:
					BILL_RECIEPT("14pc_HOT_&_SPICE",1050,1);
					Change_Value("HOT&SPICY",14);				
				    break;									
		    }			
		}
		//BBQ
		void BBQ(int cho)
		{
			switch(cho)
			{
				case 1:
					BILL_RECIEPT("1_BBQ",120,1);
					Change_Value("BBQ",1);
					break;					 
				case 2:
					BILL_RECIEPT("3_BBQ",320,1);
					Change_Value("BBQ",3);				
				    break;
				case 3:
					BILL_RECIEPT("5_BBQ",550,1);
					Change_Value("BBQ",5);					
				    break;
				case 4:
					BILL_RECIEPT("12_FD_BBQ",950,1);
					Change_Value("BBQ",12);					
				    break;									
		    }			
		}
		//Pasta function
		void Pasta(int t,char size,int s)
		{
			switch(t)
			{
				case 1:
					switch(size)
					{
						case 'S':
							BILL_RECIEPT("CRUNCH_PASTA_SMALL",650,s);
					        Change_Value("PASTA",s);
							break;
						case 'L':
							BILL_RECIEPT("CRUNCH_PASTA_LARGE",850,s);
					        Change_Value("PASTA",s);
							break;
					}
					break;					 
				case 2:
				    switch(size)
					{
						case 'S':
							BILL_RECIEPT("CHEESE_LOADER_PASTA_SMALL",750,s);
					        Change_Value("PASTA",s);
							break;
						case 'L':
							BILL_RECIEPT("CHEESE_LOADER_PASTA_LARGE",950,s);
					        Change_Value("PASTA",s);
							break;
					}				
				    break;										
		    }			
		}
		//DRUM STICK
		void DRUM_STICK(int cho)
		{
			switch(cho)
			{
				case 1:
					BILL_RECIEPT("1_DRUM_STICK",160,1);
					Change_Value("DRUMSTICK",1);
					break;					 
				case 2:
					BILL_RECIEPT("3_DRUM_STICK",450,1);
					Change_Value("DRUMSTICK",3);				
				    break;
				case 3:
					BILL_RECIEPT("5_DRUM_STICK",750,1);
					Change_Value("DRUMSTICK",5);					
				    break;
				case 4:
					BILL_RECIEPT("10_FD_DRUM_STICK",1450,1);
					Change_Value("DRUMSTICK",10);					
				    break;									
		    }			
		}
		//SAMOSA FUNCTION
		void SOMASA(int cho,int amount)
		{
			switch(cho)
			{
				case 1:
					BILL_RECIEPT("CHIKEN_SOMASA",90,amount);
					Change_Value("SOMASA",amount);
					break;
				case 2:
					BILL_RECIEPT("SOMASA_SOMASA",60,amount);
					Change_Value("SOMASA",amount);				
				    break;										
		    }			
		}
		//Roll_paratha
		void ROLL_PARATHA(int t,char size,int s)
		{
			switch(t)
			{
				case 1:
					switch(size)
					{
						case 'S':
							BILL_RECIEPT("ZINGER_ROLL_PARATHA_SMALL",190,s);
					        Change_Value("ROLLPARATHA",s);
							break;
						case 'L':
							BILL_RECIEPT("ZINGER_ROLL_PARATHA_LARGE",310,s);
					        Change_Value("ROLLPARATHA",s);
							break;
					}
					break;					 
				case 2:
				    switch(size)
					{
						case 'S':
							BILL_RECIEPT("CHICKEN_ROLL_PARATHA_SMALL",150,s);
					        Change_Value("ROLLPARATHA",s);
							break;
						case 'L':
							BILL_RECIEPT("CHICKEN_ROLL_PARATHA_LARGE",210,s);
					        Change_Value("ROLLPARATHA",s);
							break;
					}				
				    break;
				case 3:
					switch(size)
					{
						case 'S':
							BILL_RECIEPT("CHEESE_ROLL_PARATHA_SMALL",220,s);
					        Change_Value("ROLLPARATHA",s);
							break;
						case 'L':
							BILL_RECIEPT("CHEESE_ROLL_PARATHA_LARGE",350,s);
					        Change_Value("ROLLPARATHA",s);
							break;
					}					
				    break;
				case 4:
					switch(size)
					{
						case 'S':
							BILL_RECIEPT("A&Z_ROLL_PARATHA_SMALL",300,s);
					        Change_Value("ROLLPARATHA",s);
							break;
						case 'L':
							BILL_RECIEPT("A&Z_ROLL_PARATHA_LARGE",400,s);
					        Change_Value("ROLLPARATHA",s);
							break;
					}					
				    break;				
		    }
			
		}
		//Fruit CHAT
		void CHAT(int t,char size,int s)
		{
			switch(t)
			{
				case 1:
					switch(size)
					{
						case 'S':
							BILL_RECIEPT("FRUIT_CHAT_SMALL",160,s);
					        Change_Value("PASTA",s);
							break;
						case 'L':
							BILL_RECIEPT("FRUIT_CHAT_LARGE",230,s);
					        Change_Value("PASTA",s);
							break;
					}
					break;					 
				case 2:
				    switch(size)
					{
						case 'S':
							BILL_RECIEPT("CHANA_CHAT_PASTA_SMALL",170,s);
					        Change_Value("PASTA",s);
							break;
						case 'L':
							BILL_RECIEPT("CHANA_CHAT_PASTA_LARGE",240,s);
					        Change_Value("PASTA",s);
							break;
					}				
				    break;
				case 3:
				    switch(size)
					{
						case 'S':
							BILL_RECIEPT("PAPARI_CHAT_PASTA_SMALL",180,s);
					        Change_Value("PASTA",s);
							break;
						case 'L':
							BILL_RECIEPT("PAPARI_CHAT_PASTA_LARGE",250,s);
					        Change_Value("PASTA",s);
							break;
					}				
				    break;										
		    }			
		}
		//Chicken Function
		void CHICKEN(int cho,char size,int q)
		{
			switch(cho)
			{
				case 1:
					switch(size)
					{
						case 'F':
							BILL_RECIEPT("SIMPLE_KARAHI",1200,q);
					        Change_Value("CHICKEN",q);
							break;
						case 'H':
							BILL_RECIEPT("SIMPLE_KARAHI",600,q);
					        Change_Value("CHICKEN",q);
							break;
					}
					break;					 
				case 2:
				    switch(size)
					{
						case 'F':
							BILL_RECIEPT("WHITE_KARAHI",1300,q);
					        Change_Value("CHICKEN",q);
							break;
						case 'H':
							BILL_RECIEPT("WHITE_KARAHI",700,q);
					        Change_Value("CHICKEN",q);
							break;
					}
					break;
					case 3:
				    switch(size)
					{
						case 'F':
							BILL_RECIEPT("BBQ_KARAHI",1300,q);
					        Change_Value("CHICKEN",q);
							break;
						case 'H':
							BILL_RECIEPT("BBQ_KARAHI",700,q);
					        Change_Value("CHICKEN",q);
							break;
					}
					break;
					case 4:
				    switch(size)
					{
						case 'F':
							BILL_RECIEPT("CHICKEN_ROAST",1200,q);
					        Change_Value("CHICKEN",q);
							break;
						case 'H':
							BILL_RECIEPT("CHICKEN_ROAST",600,q);
					        Change_Value("CHICKEN",q);
							break;
					}				
				    break;
				    case 5:
				    switch(size)
					{
						case 'F':
							BILL_RECIEPT("CHICKEN_SAJI",1200,q);
					        Change_Value("CHICKEN",q);
							break;
						case 'H':
							BILL_RECIEPT("CHICKEN_SAJI",600,q);
					        Change_Value("CHICKEN",q);
							break;
					}				
				    break;
			}
		}
		//Mutton Function
		void MUTTON(int cho,char size,int q)
		{
			switch(cho)
			{
				case 1:
					switch(size)
					{
						case 'F':
							BILL_RECIEPT("SIMPLE_KARAHI",1400,q);
					        Change_Value("MUTTON",q);
							break;
						case 'H':
							BILL_RECIEPT("SIMPLE_KARAHI",700,q);
					        Change_Value("MUTTON",q);
							break;
					}
					break;					 
				case 2:
				    switch(size)
					{
						case 'F':
							BILL_RECIEPT("WHITE_KARAHI",1600,q);
					        Change_Value("MUTTON",q);
							break;
						case 'H':
							BILL_RECIEPT("WHITE_KARAHI",800,q);
					        Change_Value("MUTTON",q);
							break;
					}
					break;
					case 3:
				    switch(size)
					{
						case 'F':
							BILL_RECIEPT("BBQ_KARAHI",1200,q);
					        Change_Value("MUTTON",q);
							break;
						case 'H':
							BILL_RECIEPT("BBQ_KARAHI",600,q);
					        Change_Value("MUTTON",q);
							break;
					}
					break;
					case 4:
				    switch(size)
					{
						case 'F':
							BILL_RECIEPT("MUTTON_ROAST",1400,q);
					        Change_Value("MUTTON",q);
							break;
						case 'H':
							BILL_RECIEPT("MUTTON_ROAST",700,q);
					        Change_Value("MUTTON",q);
							break;
					}				
				    break;
				    case 5:
				    switch(size)
					{
						case 'F':
							BILL_RECIEPT("MUTTON_SAJI",1400,q);
					        Change_Value("MUTTON",q);
							break;
						case 'H':
							BILL_RECIEPT("MUTTON_SAJI",700,q);
					        Change_Value("MUTTON",q);
							break;
					}				
				    break;
			}
		}
		//Beef Function
		void BEEF(int cho,char size,int q)
		{
			switch(cho)
			{
				case 1:
					switch(size)
					{
						case 'F':
							BILL_RECIEPT("SIMPLE_KARAHI",1300,q);
					        Change_Value("BEEF",q);
							break;
						case 'H':
							BILL_RECIEPT("SIMPLE_KARAHI",650,q);
					        Change_Value("BEEF",q);
							break;
					}
					break;					 
				case 2:
				    switch(size)
					{
						case 'F':
							BILL_RECIEPT("WHITE_KARAHI",1300,q);
					        Change_Value("BEEF",q);
							break;
						case 'H':
							BILL_RECIEPT("WHITE_KARAHI",650,q);
					        Change_Value("BEEF",q);
							break;
					}
					break;
					case 3:
				    switch(size)
					{
						case 'F':
							BILL_RECIEPT("BBQ_KARAHI",1300,q);
					        Change_Value("BEEF",q);
							break;
						case 'H':
							BILL_RECIEPT("BBQ_KARAHI",650,q);
					        Change_Value("BEEF",q);
							break;
					}
					break;
					case 4:
				    switch(size)
					{
						case 'F':
							BILL_RECIEPT("BEEF_ROAST",1300,q);
					        Change_Value("BEEF",q);
							break;
						case 'H':
							BILL_RECIEPT("BEEF_ROAST",650,q);
					        Change_Value("BEEF",q);
							break;
					}				
				    break;
			}
		}
		//Sabzi Function
		void SABZI(int cho,char size,int q)
		{
			switch(cho)
			{
				case 1:
					switch(size)
					{
						case 'S':
							BILL_RECIEPT("GOBY_SABZI",150,q);
					        Change_Value("SABZI",q);
							break;
						case 'D':
							BILL_RECIEPT("GOBY_SABZI",300,q);
					        Change_Value("SABZI",q);
							break;
					}
					break;					 
				case 2:
				    switch(size)
					{
						case 'S':
							BILL_RECIEPT("PALAK_SABZI",200,q);
					        Change_Value("SABZI",q);
							break;
						case 'D':
							BILL_RECIEPT("PALAK_SABZI",350,q);
					        Change_Value("SABZI",q);
							break;
					}
					break;
					case 3:
				    switch(size)
					{
						case 'S':
							BILL_RECIEPT("ALLU_MATAR_SABZI",170,q);
					        Change_Value("SABZI",q);
							break;
						case 'D':
							BILL_RECIEPT("ALLU_MATAR_SABZI",280,q);
					        Change_Value("SABZI",q);
							break;
					}
					break;
					case 4:
				    switch(size)
					{
						case 'S':
							BILL_RECIEPT("MIX_SABZI",250,q);
					        Change_Value("SABZI",q);
							break;
						case 'D':
							BILL_RECIEPT("MIX_SABZI",400,q);
					        Change_Value("SABZI",q);
							break;
					}				
				    break;
			}
		}
		//Daal Function
		void DAAL(int cho,char size,int q)
		{
			switch(cho)
			{
				case 1:
					switch(size)
					{
						case 'S':
							BILL_RECIEPT("DAAL_MASH",150,q);
					        Change_Value("DAAL",q);
							break;
						case 'D':
							BILL_RECIEPT("DAAL_MASH",300,q);
					        Change_Value("DAAL",q);
							break;
					}
					break;					 
				case 2:
				    switch(size)
					{
						case 'S':
							BILL_RECIEPT("DAAL_MONG",150,q);
					        Change_Value("DAAL",q);
							break;
						case 'D':
							BILL_RECIEPT("DAAL_MONG",300,q);
					        Change_Value("DAAL",q);
							break;
					}
					break;
					case 3:
				    switch(size)
					{
						case 'S':
							BILL_RECIEPT("DAAL_MASAR",150,q);
					        Change_Value("DAAL",q);
							break;
						case 'D':
							BILL_RECIEPT("DAAL_MASAR",300,q);
					        Change_Value("DAAL",q);
							break;
					}
					break;
					case 4:
				    switch(size)
					{
						case 'S':
							BILL_RECIEPT("MIX_DAAL",150,q);
					        Change_Value("DAAL",q);
							break;
						case 'D':
							BILL_RECIEPT("MIX_DAAL",300,q);
					        Change_Value("DAAL",q);
							break;
					}				
				    break;
			}
		}
		//Fish Function
		void Fish(int cho,char size,int q)
		{
			switch(cho)
			{
				case 1:
					switch(size)
					{
						case 'F':
							BILL_RECIEPT("FISH_KARAHI",1700,q);
					        Change_Value("Fish",q);
							break;
						case 'H':
							BILL_RECIEPT("FISH_KARAHI",800,q);
					        Change_Value("Fish",q);
							break;
					}
					break;					 
				case 2:
				    switch(size)
					{
						case 'F':
							BILL_RECIEPT("RAU_FRY",1700,q);
					        Change_Value("Fish",q);
							break;
						case 'H':
							BILL_RECIEPT("RAU_FRY",800,q);
					        Change_Value("Fish",q);
							break;
					}
					break;
					case 3:
				    switch(size)
					{
						case 'F':
							BILL_RECIEPT("TUNA_FRY",1700,q);
					        Change_Value("Fish",q);
							break;
						case 'H':
							BILL_RECIEPT("TUNA_FRY",800,q);
					        Change_Value("Fish",q);
							break;
					}
					break;
					case 4:
				    switch(size)
					{
						case 'F':
							BILL_RECIEPT("MAHI_FRY",1700,q);
					        Change_Value("Fish",q);
							break;
						case 'H':
							BILL_RECIEPT("MAHI_FRY",800,q);
					        Change_Value("Fish",q);
							break;
					}				
				    break;
				    case 5:
				    switch(size)
					{
						case 'F':
							BILL_RECIEPT("FINGER_FISH",1700,q);
					        Change_Value("DAAL",q);
							break;
						case 'H':
							BILL_RECIEPT("FINGER_FISH",800,q);
					        Change_Value("Fish",q);
							break;
					}				
				    break;
			}
		}
		//Biryani Function
		void BIRYANI(int cho,char size,int q)
		{
			switch(cho)
			{
				case 1:
					switch(size)
					{
						case 'S':
							BILL_RECIEPT("SINGLE_BIRYANI",150,q);
					        Change_Value("BIRYANI",q);
							break;
						case 'D':
							BILL_RECIEPT("SINGLE_BIRYANI",300,q);
					        Change_Value("BIRYANI",q);
							break;
					}
					break;					 
				case 2:
				    switch(size)
					{
						case 'S':
							BILL_RECIEPT("CHICKEN_BIRYANI",150,q);
					        Change_Value("BIRYANI",q);
							break;
						case 'D':
							BILL_RECIEPT("CHICKEN_BIRYANI",300,q);
					        Change_Value("BIRYANI",q);
							break;
					}
					break;
			}
		}
		//Pulao Function
		void PULAO(int cho,char size,int q)
		{
			switch(cho)
			{
				case 1:
					switch(size)
					{
						case 'S':
							BILL_RECIEPT("BEEF_PULAO",150,q);
					        Change_Value("PULAO",q);
							break;
						case 'D':
							BILL_RECIEPT("BEEF_PULAO",300,q);
					        Change_Value("PULAO",q);
							break;
					}
					break;					 
				case 2:
				    switch(size)
					{
						case 'S':
							BILL_RECIEPT("CHICKEN_PULAO",150,q);
					        Change_Value("PULAO",q);
							break;
						case 'D':
							BILL_RECIEPT("CHICKEN_PULAO",300,q);
					        Change_Value("PULAO",q);
							break;
					}
					break;
			}
		}
		//Roti/Paratha Function
		void ROTI(int cho,int amount )
		{
			switch(cho)
			{
				case 1:
					BILL_RECIEPT("SADA_ROTI",350,amount);
					Change_Value("ROTI",amount);
					break;					 
				case 2:
					BILL_RECIEPT("DESI_PARATHA",230,amount);
					Change_Value("ROTI",amount);				
				    break;
				case 3:
					BILL_RECIEPT("ROGHNI_NAAN",450,amount);
					Change_Value("ROTI",amount);					
				    break;
				case 4:
					BILL_RECIEPT("SADA_NAAN",400,amount);
					Change_Value("ROTI",amount);					
				    break;
				case 5:
					BILL_RECIEPT("GARLIC_NAAN",520,amount);
					Change_Value("ROTI",amount);						
				    break;										
		    }			
		}
		//Raita/Salad Function
		void RAITA_SALAD(int cho,int amount )
		{
			switch(cho)
			{
				case 1:
					BILL_RECIEPT("RAITA",50,amount);
					Change_Value("RAITA_SALAD",amount);
					break;					 
				case 2:
					BILL_RECIEPT("CHUTNEY",70,amount);
					Change_Value("RAITA_SALAD",amount);				
				    break;
				case 3:
					BILL_RECIEPT("DHAI",40,amount);
					Change_Value("RAITA_SALAD",amount);					
				    break;
				case 4:
					BILL_RECIEPT("SALAD",50,amount);
					Change_Value("RAITA_SALAD",amount);					
				    break;										
		    }			
		}
		//Kheer Function
		void KHEER(int cho,char size,int q)
		{
			switch(cho)
			{
				case 1:
					switch(size)
					{
						case 'S':
							BILL_RECIEPT("KHEER",150,q);
					        Change_Value("KHEER",q);
							break;
						case 'D':
							BILL_RECIEPT("KHEER",300,q);
					        Change_Value("KHEER",q);
							break;
					}
					break;					 
				case 2:
				    switch(size)
					{
						case 'S':
							BILL_RECIEPT("SPECIAL_MALAI_KHEER",150,q);
					        Change_Value("KHEER",q);
							break;
						case 'D':
							BILL_RECIEPT("SPECIAL_MALAI_KHEER",300,q);
					        Change_Value("KHEER",q);
							break;
					}
					break;
			}
		}
		//Custard Function
		void CUSTARD(int cho,char size,int q)
		{
			switch(cho)
			{
				case 1:
					switch(size)
					{
						case 'S':
							BILL_RECIEPT("MANGO_CUSTARD",170,q);
					        Change_Value("CUSTARD",q);
							break;
						case 'D':
							BILL_RECIEPT("MANGO_CUSTARD",230,q);
					        Change_Value("CUSTARD",q);
							break;
					}
					break;					 
				case 2:
				    switch(size)
					{
						case 'S':
							BILL_RECIEPT("BANANA_CUSTARD",170,q);
					        Change_Value("CUSTARD",q);
							break;
						case 'D':
							BILL_RECIEPT("BANANA_CUSTARD",230,q);
					        Change_Value("CUSTARD",q);
							break;
					}
					break;
				case 3:
				    switch(size)
					{
						case 'S':
							BILL_RECIEPT("STRAWBERRY_CUSTARD",170,q);
					        Change_Value("CUSTARD",q);
							break;
						case 'D':
							BILL_RECIEPT("STRAWBERRY_CUSTARD",230,q);
					        Change_Value("CUSTARD",q);
							break;
					}
					break;
			}
		}
		//Jelly Function
		void JELLY(int cho,char size,int q)
		{
			switch(cho)
			{
				case 1:
					switch(size)
					{
						case 'S':
							BILL_RECIEPT("MANGO_JELLY",120,q);
					        Change_Value("JELLY",q);
							break;
						case 'D':
							BILL_RECIEPT("MANGO_JELLY",180,q);
					        Change_Value("JELLY",q);
							break;
					}
					break;					 
				case 2:
				    switch(size)
					{
						case 'S':
							BILL_RECIEPT("BANANA_JELLY",120,q);
					        Change_Value("JELLY",q);
							break;
						case 'D':
							BILL_RECIEPT("BANANA_JELLY",180,q);
					        Change_Value("JELLY",q);
							break;
					}
					break;
				case 3:
				    switch(size)
					{
						case 'S':
							BILL_RECIEPT("STRAWBERRY_JELLY",120,q);
					        Change_Value("JELLY",q);
							break;
						case 'D':
							BILL_RECIEPT("STRAWBERRY_JELLY",180,q);
					        Change_Value("JELLY",q);
							break;
					}
					break;
			}
		}
		//Rasmalai Function
		void RASMALAI(int cho,char size,int q)
		{
			switch(cho)
			{
				case 1:
					switch(size)
					{
						case 'S':
							BILL_RECIEPT("RASMALAI",200,q);
					        Change_Value("RASMALAI",q);
							break;
						case 'D':
							BILL_RECIEPT("RASMALAI",300,q);
					        Change_Value("RASMALAI",q);
							break;
					}
					break;					 
				case 2:
				    switch(size)
					{
						case 'S':
							BILL_RECIEPT("PISTA_RASMALAI",250,q);
					        Change_Value("RASMALAI",q);
							break;
						case 'D':
							BILL_RECIEPT("PISTA_RASMALAI",400,q);
					        Change_Value("RASMALAI",q);
							break;
					}
					break;
			}
		}
		//Halwa Function
		void HALWA(int cho,char size,int q)
		{
			switch(cho)
			{
				case 1:
					switch(size)
					{
						case 'F':
							BILL_RECIEPT("GAJAR_HALWA",400,q);
					        Change_Value("HALWA",q);
							break;
						case 'H':
							BILL_RECIEPT("GAJAR_HALWA",700,q);
					        Change_Value("HALWA",q);
							break;
					}
					break;					 
				case 2:
				    switch(size)
					{
						case 'F':
							BILL_RECIEPT("SUJI_HALWA",300,q);
					        Change_Value("HALWA",q);
							break;
						case 'H':
							BILL_RECIEPT("SUJI_HALWA",600,q);
					        Change_Value("HALWA",q);
							break;
					}
					break;
				case 3:
				    switch(size)
					{
						case 'F':
							BILL_RECIEPT("ANDA_HALWA",350,q);
					        Change_Value("HALWA",q);
							break;
						case 'H':
							BILL_RECIEPT("ANDA_HALWA",650,q);
					        Change_Value("HALWA",q);
							break;
					}
					break;
			}
		}
		//Ice_Cream Function
		void ICECREAM(int cho,char size,int s)
		{
			switch(cho)
			{
				case 1:
					switch(size)
					{
						case 'S':
							BILL_RECIEPT("MANGO_ICECREAM_1_SCOOP",80,s);
					        Change_Value("ICECREAM",s);
							break;
						case 'D':
							BILL_RECIEPT("MANGO_ICECREAM_2_SCOOP",120,s);
					        Change_Value("ICECREAM",s);
							break;
						case 'T':
							BILL_RECIEPT("MANGO_ICECREAM_3_SCOOP",170,s);
					        Change_Value("ICECREAM",s);
							break;
					}
					break;					 
				case 2:
				    switch(size)
					{
						case 'S':
							BILL_RECIEPT("VANAILA_ICECREAM_1_SCOOP",80,s);
					        Change_Value("ICECREAM",s);
							break;
						case 'D':
							BILL_RECIEPT("VANAILA_ICECREAM_2_SCOOP",120,s);
					        Change_Value("ICECREAM",s);
							break;
						case 'T':
							BILL_RECIEPT("VANAILA_ICECREAM_3_SCOOP",170,s);
					        Change_Value("ICECREAM",s);
							break;
					}				
				    break;
				case 3:
					switch(size)
					{
						case 'S':
							BILL_RECIEPT("STRAWBERRY_ICECREAM_1_SCOOP",80,s);
					        Change_Value("ICECREAM",s);
							break;
						case 'D':
							BILL_RECIEPT("STRAWBERRY_ICECREAM_2_SCOOP",120,s);
					        Change_Value("ICECREAM",s);
							break;
						case 'T':
							BILL_RECIEPT("STRAWBERRY_ICECREAM_3_SCOOP",170,s);
					        Change_Value("ICECREAM",s);
							break;
					}					
				    break;
				case 4:
					switch(size)
					{
						case 'S':
							BILL_RECIEPT("CHOCOLATE_ICECREAM_1_SCOOP",80,s);
					        Change_Value("ICECREAM",s);
							break;
						case 'D':
							BILL_RECIEPT("CHOCOLATE_ICECREAM_2_SCOOP",120,s);
					        Change_Value("ICECREAM",s);
							break;
						case 'T':
							BILL_RECIEPT("CHOCLATE_ICECREAM_3_SCOOP",170,s);
					        Change_Value("ICECREAM",s);
							break;
					}					
				    break;										
		    }			
		}
		//Chat Function
		void REFREASHMENT(int cho,char size,int q)
		{
			switch(cho)
			{
				case 1:
					switch(size)
					{
						case 'S':
							BILL_RECIEPT("FRUIT_CHAT",100,q);
					        Change_Value("CHAT",q);
							break;
						case 'L':
							BILL_RECIEPT("FRUIT_CHAT",170,q);
					        Change_Value("CHAT",q);
							break;
					}
					break;					 
				case 2:
				    switch(size)
					{
						case 'S':
							BILL_RECIEPT("CREAM_CHAT",120,q);
					        Change_Value("CHAT",q);
							break;
						case 'L':
							BILL_RECIEPT("CREAM_CHAT",200,q);
					        Change_Value("CHAT",q);
							break;
					}
					break;
				case 3:
				    switch(size)
					{
						case 'S':
							BILL_RECIEPT("RUSSIAN_SALAD",150,q);
					        Change_Value("CHAT",q);
							break;
						case 'L':
							BILL_RECIEPT("RUSSIAN_SALAD",220,q);
					        Change_Value("CHAT",q);
							break;
					}
					break;
			}
		}
		//Falooda Function
		void FALOODA(int cho,char size,int q)
		{
			switch(cho)
			{
				case 1:
					switch(size)
					{
						case 'S':
							BILL_RECIEPT("FRUIT_CHAT",150,q);
					        Change_Value("FALOODA",q);
							break;
						case 'L':
							BILL_RECIEPT("FRUIT_CHAT",300,q);
					        Change_Value("FALOODA",q);
							break;
					}
					break;					 
				case 2:
				    switch(size)
					{
						case 'S':
							BILL_RECIEPT("CREAM_CHAT",200,q);
					        Change_Value("FALOODA",q);
							break;
						case 'L':
							BILL_RECIEPT("CREAM_CHAT",350,q);
					        Change_Value("FALOODA",q);
							break;
					}
					break;
			}
		}
		//CAKE
		void CAKE(int cho,int amount)
		{
			switch(cho)
			{
				case 1:
					BILL_RECIEPT("NUTELLA_CAKE",1600,amount);
					Change_Value("CAKE",amount);
					break;
				case 2:
					BILL_RECIEPT("LOTUS_CAKE",1700,amount);
					Change_Value("CAKE",amount);				
				    break;
				case 3:
					BILL_RECIEPT("RED_VELVET_CAKE",1500,amount);
					Change_Value("CAKE",amount);				
				    break;
				case 4:
					BILL_RECIEPT("RAFFAELLO_CAKE",210,amount);
					Change_Value("CAKE",amount);				
				    break;										
		    }			
		}
		//MATHAI 
		void MATHAI(int cho,int amount)
		{
			switch(cho)
			{
				case 1:
					BILL_RECIEPT("RAS_GULA_MATHAI",600,amount);
					Change_Value("MATHAI",amount);
					break;
				case 2:
					BILL_RECIEPT("GULABJAMAN_MATHAI",600,amount);
					Change_Value("MATHAI",amount);				
				    break;
				case 3:
					BILL_RECIEPT("PASITA_MATHAI",900,amount);
					Change_Value("MATHAI",amount);				
				    break;
				case 4:
					BILL_RECIEPT("BARFI_MATHAI",1200,amount);
					Change_Value("MATHAI",amount);				
				    break;										
		    }			
		}				
		//7updrinks
		void s7_UP(int cho,int amount)
		{
			switch(cho)
			{
				case 1:
					BILL_RECIEPT("7_UP_RAGULAR",50,amount);
					Change_Value("7UP",amount);
					break;
				case 2:
					BILL_RECIEPT("7_UP_1_lITER",130,amount);
					Change_Value("7UP",amount);				
				    break;
				case 3:
					BILL_RECIEPT("7_UP_1.5_lITER",160,amount);
					Change_Value("7UP",amount);				
				    break;
				case 4:
					BILL_RECIEPT("7_UP_2.25_lITER",210,amount);
					Change_Value("7UP",amount);				
				    break;										
		    }			
		}
		//Coke_Cola function
		void COKE_COLA(int cho,int amount)
		{
			switch(cho)
			{
				case 1:
					BILL_RECIEPT("COKE_COLA_RAGULAR",50,amount);
					Change_Value("COKECOLA",amount);
					break;
				case 2:
					BILL_RECIEPT("COKE_COLA_1_lITER",130,amount);
					Change_Value("COKECOLA",amount);				
				    break;
				case 3:
					BILL_RECIEPT("COKE_COLA_1.5_lITER",160,amount);
					Change_Value("COKECOLA",amount);				
				    break;
				case 4:
					BILL_RECIEPT("COKE_COLA_2.25_lITER",210,amount);
					Change_Value("COKECOLA",amount);				
				    break;										
		    }			
		}
		//Fanta function
		void Fanta(int cho,int amount)
		{
			switch(cho)
			{
				case 1:
					BILL_RECIEPT("Fanta_RAGULAR",50,amount);
					Change_Value("FANTA",amount);
					break;
				case 2:
					BILL_RECIEPT("Fanta_1_lITER",130,amount);
					Change_Value("FANTA",amount);				
				    break;
				case 3:
					BILL_RECIEPT("Fanta_1.5_lITER",160,amount);
					Change_Value("FANTA",amount);				
				    break;
				case 4:
					BILL_RECIEPT("Fanta_2.25_lITER",210,amount);
					Change_Value("FANTA",amount);				
				    break;										
		    }			
		}
		//string Function;
		void STRING(int cho,int amount)
		{
			switch(cho)
			{
				case 1:
					BILL_RECIEPT("STRING_RAGULAR",50,amount);
					Change_Value("STRING",amount);
					break;
				case 2:
					BILL_RECIEPT("STRING_1_lITER",130,amount);
					Change_Value("STRING",amount);				
				    break;
				case 3:
					BILL_RECIEPT("STRING_1.5_lITER",160,amount);
					Change_Value("STRING",amount);				
				    break;
				case 4:
					BILL_RECIEPT("STRING_2.25_lITER",210,amount);
					Change_Value("STRING",amount);				
				    break;										
		    }			
		}
		//Water function
		void WATER(int cho,int amount)
		{
			switch(cho)
			{
				case 1:
					BILL_RECIEPT("WATER_RAGULAR",50,amount);
					Change_Value("WATER",amount);
					break;
				case 2:
					BILL_RECIEPT("WATER_1.5_lITER",100,amount);
					Change_Value("WATER",amount);				
				    break;										
		    }			
		}
		//MANGO_JUICE function
		void MANGO_JUICE(int cho,int amount)
		{
			switch(cho)
			{
				case 1:
					BILL_RECIEPT("MANGO_JUICE_RAGULAR",80,amount);
					Change_Value("MANGOJUICE",amount);
					break;
				case 2:
					BILL_RECIEPT("MANGO_JUICE_1_lITER",180,amount);
					Change_Value("MANGOJUICE",amount);				
				    break;										
		    }			
		}
		//BANANA function
		void BANANA_JUICE(int cho,int amount)
		{
			switch(cho)
			{
				case 1:
					BILL_RECIEPT("BANANA_JUICE_RAGULAR",80,amount);
					Change_Value("BANANAJUICE",amount);
					break;
				case 2:
					BILL_RECIEPT("BANANA_JUICE_1_lITER",180,amount);
					Change_Value("BANANAJUICE",amount);				
				    break;										
		    }			
		}
		//STAWBERRY function
		void STAWBERRY_JUICE(int cho,int amount)
		{
			switch(cho)
			{
				case 1:
					BILL_RECIEPT("STAWBERRY_JUICE_RAGULAR",100,amount);
					Change_Value("STAWBERRYJUICE",amount);
					break;
				case 2:
					BILL_RECIEPT("STAWBERRY_JUICE_1_lITER",250,amount);
					Change_Value("STAWBERRYJUICE",amount);				
				    break;										
		    }			
		}
		//APPLE function
		void APPLE_JUICE(int cho,int amount)
		{
			switch(cho)
			{
				case 1:
					BILL_RECIEPT("APPLE_JUICE_RAGULAR",80,amount);
					Change_Value("APPLEJUICE",amount);
					break;
				case 2:
					BILL_RECIEPT("APPLE_JUICE_1_lITER",180,amount);
					Change_Value("APPLEJUICE",amount);				
				    break;										
		    }			
		}
		//ICE_CREAM function
		void ICE_CREAM_Shake(int cho,int amount)
		{
			switch(cho)
			{
				case 1:
					BILL_RECIEPT("ICE_CREAM_SHAKE_RAGULAR",80,amount);
					Change_Value("ICECREAMJUICE",amount);
					break;
				case 2:
					BILL_RECIEPT("ICE_CREAM_SHAKE_1_lITER",180,amount);
					Change_Value("ICECREAMJUICE",amount);				
				    break;										
		    }			
		}
		//Bill Reciept(take data and store it in the linkedlist)
		void BILL_RECIEPT(string fname,int fprice, int amount){
			FoodData *newnode = new FoodData;
			newnode->setItemName(fname);
			newnode->setItemPrice(fprice);
			newnode->setItemAmo(amount);
			newnode->setTotalItemPrice(fprice*amount);
			temporary += newnode->getTotalItemPrice();
			newnode->setTotalPrice(temporary);
			newnode->setFoodRecordNext(NULL);
			if(bill==NULL)
			{
				bill = newnode;
			}
			else
			{			
			    FoodData *temp= bill;
			    while(temp->getFoodRecordNext()!=NULL)
			    {
			  	    temp=temp->getFoodRecordNext();
			    }	
				temp->setFoodRecordNext(newnode);
			}
		}
		//to display the bill
		void DISPLAY_BILL(){
			int hour,min,sec,year,month,day;
			FoodData *newNode=bill;
			temp+=1;
			time_t ttime=time(0);
            tm*local_time =localtime(&ttime);
            year = 1900 + local_time->tm_year;
            month = 1 + local_time->tm_mon;
            day = local_time->tm_mday;
            hour = local_time->tm_hour;
            min = local_time->tm_min;
            sec = local_time->tm_sec;
			cout<<setw(50)<<"                                ___________________________________________________________________________________________\n";
			cout<<setw(50)<<"                                |                                       A   &   Z                                         |\n";
			cout<<setw(50)<<"                                |                                        PAKISTAN                                         |\n";
			cout<<setw(50)<<"                                |                                        RESTURANT                                        |\n";
			cout<<setw(50)<<"                                |*****************************************************************************************|\n";
			cout<<setw(50)<<"                                |                        #8395R,Down Cafa,Air University,E-9,Islamabad                    |\n";
			cout<<setw(50)<<"                                |                                   Tel:03077881137                                       |\n";
			cout<<setw(50)<<"                                |                             Email:azresturant.gmail.com                                 |\n";
			cout<<setw(50)<<"                                |*****************************************************************************************|\n";
			cout<<setw(50)<<"                                |----------------------------------- I N V O I C E ---------------------------------------|\n";
			cout<<setw(50)<<"                                |                                                                        "<<day<<"/"<<month<<"/"<<year<<setw(9)<<"|\n";
			cout<<setw(30)<<"                                |"<<setw(4)<<hour<<":"<<min<<":"<<sec<<setw(71)<<"BILL NO :"<<temp<<"       |\n";
			cout<<setw(50)<<"                                |-----------------------------------------------------------------------------------------|\n";
			cout<<setw(50)<<"                                |               ITEMS                                      QTY       PRICE       TOTAL    |\n";
			cout<<setw(50)<<"                                |-----------------------------------------------------------------------------------------|\n";
			while(newNode != NULL)
			{
//			cout<<setw(50)<<"                                |       FOOD                |       QUANTITY               |               \n";
//			cout<<setw(50)<<"                                ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~               \n";
                cout<<setw(60)<<newNode->getItemName()<<setw(33)<<newNode->getItemAmo()<<setw(12)<<newNode->getItemPrice()<<setw(12)<<newNode->getTotalItemPrice()<<setw(6)<<"|"<<endl;
				if(newNode->getFoodRecordNext()==NULL)
				{
					cout<<setw(50)<<"                                |=========================================================================================|\n";
					cout<<setw(50)<<"                                |                                                                      TOTAL : "<<newNode->getTotalPrice()<<"       |\n";
					
					
				}
				newNode=newNode->getFoodRecordNext();
			}
			delete newNode;
			cout<<setw(50)<<"                                |=========================================================================================|"<<endl;
			cout<<setw(50)<<"                                |*****************************************************************************************|"<<endl;
			cout<<"                                |                                THANK YOU FOR JOINING US                               |"<<endl;
			cout<<"                                |                              * We have free home dlivery *                            |"<<endl;
			cout<<setw(50)<<"                                |*****************************************************************************************|"<<endl;
			cout<<setw(50)<<"                                |_________________________________________________________________________________________|"<<endl;
		}
		//display the bill 2
		void DISPLAY_BILL2(){
			int hour,min,sec,year,month,day;
			FoodData *newNode=bill;
			temp+=1;
			time_t ttime=time(0);
            tm*local_time =localtime(&ttime);
            year = 1900 + local_time->tm_year;
            month = 1 + local_time->tm_mon;
            day = local_time->tm_mday;
            hour = local_time->tm_hour;
            min = local_time->tm_min;
            sec = local_time->tm_sec;
			cout<<setw(50)<<"                                ___________________________________________________________________________________________\n";
			cout<<setw(50)<<"                                |                                       A   &   Z                                         |\n";
			cout<<setw(50)<<"                                |                                        PAKISTAN                                         |\n";
			cout<<setw(50)<<"                                |                                        RESTURANT                                        |\n";
			cout<<setw(50)<<"                                |*****************************************************************************************|\n";
			cout<<setw(50)<<"                                |                        #8395R,Down Cafa,Air University,E-9,Islamabad                    |\n";
			cout<<setw(50)<<"                                |                                   Tel:03077881137                                       |\n";
			cout<<setw(50)<<"                                |                             Email:azresturant.gmail.com                                 |\n";
			cout<<setw(50)<<"                                |*****************************************************************************************|\n";
			cout<<setw(50)<<"                                |----------------------------------- I N V O I C E ---------------------------------------|\n";
			cout<<setw(50)<<"                                |                                                                        "<<day<<"/"<<month<<"/"<<year<<setw(9)<<"|\n";
			cout<<setw(30)<<"                                |"<<setw(4)<<hour<<":"<<min<<":"<<sec<<setw(71)<<"BILL NO :"<<temp<<"       |\n";
			cout<<setw(50)<<"                                |-----------------------------------------------------------------------------------------|\n";
			cout<<setw(50)<<"                                |               ITEMS                                      QTY       PRICE       TOTAL    |\n";
			cout<<setw(50)<<"                                |-----------------------------------------------------------------------------------------|\n";
			while(newNode != NULL)
			{
//			cout<<setw(50)<<"                                |       FOOD                |       QUANTITY               |               \n";
//			cout<<setw(50)<<"                                ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~               \n";
                cout<<setw(60)<<newNode->getItemName()<<setw(33)<<newNode->getItemAmo()<<setw(12)<<newNode->getItemPrice()<<setw(12)<<newNode->getTotalItemPrice()<<setw(6)<<"|"<<endl;
				if(newNode->getFoodRecordNext()==NULL)
				{
					cout<<setw(50)<<"                                |=========================================================================================|\n";
					cout<<setw(50)<<"                                |                                                                      TOTAL : "<<newNode->getTotalPrice()<<"       |\n";
					SET_SALES(newNode);
					
				}
				newNode=newNode->getFoodRecordNext();
			}
			delete newNode;
			cout<<setw(50)<<"                                |=========================================================================================|"<<endl;
			cout<<setw(50)<<"                                |*****************************************************************************************|"<<endl;
			cout<<"                                |                                THANK YOU FOR JOINING US                               |"<<endl;
			cout<<"                                |                              * We have free home dlivery *                            |"<<endl;
			cout<<setw(50)<<"                                |*****************************************************************************************|"<<endl;
			cout<<setw(50)<<"                                |_________________________________________________________________________________________|"<<endl;
		}
		//setsales
		void SET_SALES(FoodData* n)
		{
		    fstream File("SALE.txt",ios::app);
		    File<<n->getTotalPrice()<<"\n";
		 	File.close();
		}
		//getsale
		void DISPLAY_SALES()
		{
			int temp=0,si=1;
			ifstream File("SALE.txt",ios::app);
			cout<<setw(50)<<"                                |       NUMBER              |         PRICE                |               \n";
			cout<<setw(50)<<"                                ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~               \n";
			int line;
			while(File>>line)
			{
				temp+=line;
				cout<<setw(33)<<"|"<<setw(11)<<si<<setw(17)<<"|"<<setw(11)<<line<<setw(36)<<"|               \n";
				cout<<setw(50)<<"                                ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~               \n";
				si++;
			}
			cout<<setw(33)<<"|"<<setw(11)<<"TOTAL "<<setw(28)<<temp<<setw(36)<<"|               \n";
			cout<<setw(50)<<"                                ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~               \n";
			File.close();
		}
		//Change File value
		void Change_Value(string foodType,int s)
		{
			ifstream File("FOOD.txt");
			FoodData* newNode = new FoodData;
			string line;
			const char* quantity;
			const char* food;
			int v,v1;
		    while(getline(File,line))
			{
			    vector<string> Sline=foodString(line);
			    food = Sline.at(0).c_str();
			    quantity = Sline.at(1).c_str();
			    //cout<<food<<" "<<quantity<<endl;
			    if(food==foodType)
				{
					break;
				}
			}      
			File.close();
			stringstream convert1;
			convert1<<quantity;
			convert1>>v1;
			if(v1 > 0 && food ==foodType)
			{
				v=v1-s;
			    string str =to_string(v);
			    info.UPDATE_FOOD_FILE(foodType,str);
			}
			else if(v1 <= 0)
			{
				cout<<"                         ###### YOU DON'T HAVE ENOUGH FOOD ######\n";
				getch();
			}			
		}		
};

//main 
int main() 
{
	char i,size;
	int choice,choice1,q,siz,quantity;
	char s;
	string n,a,e,pw,l,T,f;
	string ph;
	bool temp = false,Free=true;
	Information R;
	FoodMenu F;
	system("color f9");
	cout<<"\n\n\n\n\n\n\n\n\n\n\n\n";            
	cout<<setw(50)<<"                                         $$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$               \n";
	cout<<setw(50)<<"                                         |                                                 |               \n";
	cout<<setw(20)<<"                                         |              Welcome to A&Z Resturant           |               \n";
	cout<<setw(20)<<"                                         |                                                 |               \n";
	cout<<setw(20)<<"                                         $$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$               \n";
	getch();
	system("cls");
	do{	
	T="";
	temp = false;
	cout<<T;
	system("color f9");
	cout<<"\n\n\n\n\n\n\n";
	cout<<setw(50)<<"                                                       ENTER (s) FOR SHUTDOWN"<<endl;     
	cout<<setw(50)<<"                                         $$$$$$$$$$$$$$$                      $$$$$$$$$$$$$$$                    \n";
	cout<<setw(50)<<"                                         |  Sign up/x  |                      |  Log in/y   |                    \n";
	cout<<setw(50)<<"                                         $$$$$$$$$$$$$$$                      $$$$$$$$$$$$$$$                    \n\n\n\n";
	cout<<setw(50)<<"                                                              x/y : ";
	
	cin>>i;
	system("cls");
	
	if(i=='x'||i=='X')
	{
		cout<<"\n\n\n\n\n\n\n\n\n\n\n\n";
		cout<<setw(50)<<"\n                                          Name       :  ";
	    cin>>n;
	    cout<<setw(50)<<"\n                                          Phone NO   :  ";
	    cin>>ph;
	    cout<<setw(50)<<"\n                                          Address    :  ";
	    cin>>a;
	    cout<<setw(50)<<"\n                                          Email      :  ";
	    cin>>e;
	    cout<<setw(50)<<"\n                                          Password   :  ";
	    cin>>pw;
	    R.SIGN_UP(n,ph,a,e,pw,"C");
	    system("cls");
	    continue;
	}else if(i=='y'||i=='Y')
	{
		if(Free)
		{
			R.GET_File_CUSTOMER();
			R.GET_File_EMPLOY();
			Free=false;
		}  
		//R.DisplayRecord();
		//R.DisplayRecord2();
		cout<<"\n\n\n\n\n\n\n\n\n\n\n\n";
		cout<<setw(50)<<"\n                                          Login ID  :  ";                          
		cin>>l;
		cout<<setw(50)<<"\n                                          Password  :  ";
		cin>>pw;
		T = R.Login(l,pw);
		 
	}else if(i=='s'||i=='S')
	{
		cout<<"\n\n\n\n\n\n\n\n";
	    system("color f4");
		cout<<setw(50)<<"                                ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~               \n";
		cout<<setw(50)<<"                                |                Shut Down (enter / Esc + F1)              |               \n";
		cout<<setw(50)<<"                                ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~               \n";
		getch();
		if(getch())
		{
			terminate();
		}
		if(temp==true)
		    l="";
		    pw="";
		    temp=false;
		system("cls");
	}
	else 
	{
		system("cls");
		cout<<setw(50)<<"                                         ############ Default Choice ############  \n";
	}
	if(T=="A")
		{
			temp=true;	
		}
	else if(T=="E")
		{
			temp=true;	
		} 
	else if(T=="C")
		{
			temp=true;	
		}      
	else 
	{
		system("cls");
		cout<<"\n\n\n\n\n\n\n\n\n\n\n\n";
		system("color f4");
		cout<<setw(50)<<"                                         ############ Wrong ID PASSWORD ############  \n";
		getch();
		system("cls");
	}
		temp=false;
		if(T=="A")
		{
			do{
			system("cls");
			cout<<setw(50)<<"                                ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~               \n";
			cout<<setw(50)<<"                                |                         MANAGER                          |               \n";
			cout<<setw(50)<<"                                ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~               \n";
	        cout<<setw(50)<<"                                |                                                          |               \n";
	        cout<<setw(20)<<"                                |        1 . Cheak Attendence                              |               \n";
	        cout<<setw(20)<<"                                |        2 . Cheak Amount of food                          |               \n";
	        cout<<setw(20)<<"                                |        3 . Add Amount of food                            |               \n";
	        cout<<setw(20)<<"                                |        4 . Cheak Daily Sales                             |               \n";
	        cout<<setw(20)<<"                                |        5 . Hired Employee                                |               \n";
	        cout<<setw(20)<<"                                |        6 . Fired Employee                                |               \n";
	        cout<<setw(20)<<"                                |        7 . Cheak Empolyee data                           |               \n";
	        cout<<setw(20)<<"                                |        8 . Cheak Customer data                           |               \n";
	        cout<<setw(20)<<"                                |        9 . Log out                                       |               \n";
	        cout<<setw(20)<<"                                |                                                          |               \n";
	        cout<<setw(50)<<"                                ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~               \n";
	        cout<<setw(40)<<"                                Choice : ";
	        cin>>choice;
	        switch(choice)
			{
				case 1:
					system("cls");
					cout<<"\n\n\n\n\n\n";
					cout<<setw(50)<<"                                ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~               \n";
					cout<<setw(50)<<"                                |                     Daily Attendence                     |               \n";
					cout<<setw(50)<<"                                ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~               \n";
					R.Display_Employ_Attendence();
					getch();
					break;
				case 2:
					system("cls");
					cout<<"\n\n\n\n\n\n";
					cout<<setw(50)<<"                                ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~               \n";
					cout<<setw(50)<<"                                |                     Stock Available                      |               \n";
					cout<<setw(50)<<"                                ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~               \n";
					R.Display_File_FOOD();
					getch();
					break;
				case 3:
					system("cls");
					cout<<"\n\n\n\n\n\n";
					cout<<setw(50)<<"                                ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~               \n";
					cout<<setw(50)<<"                                |                     Add Amount of food                   |               \n";
					cout<<setw(50)<<"                                ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~               \n";
					cout<<setw(50)<<"\n                                Food Name       :  ";
	                cin>>f;
	                cout<<setw(50)<<"\n                                Quantity        :  ";
	                cin>>q;
	                R.STORE_FOOD_TO_FILE(f,q);
					break;
				case 4:
					system("cls");
					cout<<"\n\n\n\n\n\n";
					cout<<setw(50)<<"                                ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~               \n";
					cout<<setw(50)<<"                                |                   Daily Sales or Profit                  |               \n";
					cout<<setw(50)<<"                                ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~               \n";
					F.DISPLAY_SALES();
					getch();
					break;
				case 5:
					system("cls");
					cout<<"\n\n\n\n\n\n";
					cout<<setw(50)<<"                                ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~               \n";
					cout<<setw(50)<<"                                |                     Hired Employee                       |               \n";
					cout<<setw(50)<<"                                ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~               \n";
					cout<<setw(50)<<"\n                                Name       :  ";
	                cin>>n;
	                cout<<setw(50)<<"\n                                Phone NO   :  ";
	                cin>>ph;
	                cout<<setw(50)<<"\n                                Address    :  ";
	                cin>>a;
	                cout<<setw(50)<<"\n                                Email      :  ";
	                cin>>e;
	                cout<<setw(50)<<"\n                                Password   :  ";
	                cin>>pw;
	                R.EMPLOY_SIGH_UP(n,ph,a,e,pw,"A");
					break;
				case 6:
					system("cls");
					cout<<"\n\n\n\n\n\n";
					cout<<setw(50)<<"                                ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~               \n";
					cout<<setw(50)<<"                                |                     Fired Employee                       |               \n";
					cout<<setw(50)<<"                                ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~               \n";
					break;
				case 7:
					system("cls");
					cout<<"\n\n\n\n\n\n";
					cout<<setw(20)<<"             ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n";
					cout<<setw(50)<<"             |                                          EMPLOY DATA                                               |\n";
					cout<<setw(20)<<"             ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n";
					R.Display_File_Employ();
					getch();
					break;
				case 8:
					system("cls");
					cout<<"\n\n\n\n";
					cout<<setw(20)<<"             ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n";
					cout<<setw(50)<<"             |                                          COSTUMER DATA                                             |\n";
					cout<<setw(20)<<"             ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n";
					R.Display_File_CUSTOMER();
					getch();
					break;
				case 9:
					system("cls");
					cout<<"\n\n\n\n\n\n\n\n\n\n\n\n";
					system("color f4");
					cout<<setw(50)<<"                                ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~               \n";
					cout<<setw(50)<<"                                |                     LOG OUT                              |               \n";
					cout<<setw(50)<<"                                ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~               \n";
					getch();
					system("cls");
					temp=false;
					break;
			}
		    }while(choice != 9);
			
		}
		else if(T=="E")
		{
			do{
			system("cls");
			cout<<setw(50)<<"                                ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~               \n";
			cout<<setw(50)<<"                                |                         EMPLOYEE                         |               \n";
			cout<<setw(50)<<"                                ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~               \n";
	        cout<<setw(50)<<"                                |                                                          |               \n";
	        cout<<setw(20)<<"                                |        1 . Menu                                          |               \n";
	        cout<<setw(20)<<"                                |        2 . Attendence                                    |               \n";
	        cout<<setw(20)<<"                                |        3 . Cheak Daily Sales                             |               \n";
	        cout<<setw(20)<<"                                |        4 . Your Bill                                     |               \n";
	        cout<<setw(20)<<"                                |        5 . Your Record                                   |               \n";
	        cout<<setw(20)<<"                                |        6 . Log Out                                       |               \n";
	        cout<<setw(20)<<"                                |                                                          |               \n";
	        cout<<setw(50)<<"                                ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~               \n";
	        cout<<setw(40)<<"                                Choice : ";
	        cin>>choice;
	        switch(choice)
			{
				case 1:
					system("cls");
					do{
					cout<<"\n\n\n";
					cout<<setw(50)<<"                                ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~              \n";
					cout<<setw(50)<<"                                |                                     MENU                                        |               \n";
					cout<<setw(50)<<"                                ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~               \n";
					cout<<setw(50)<<"                                |                    1  .  FAST FOOD                                              |               \n";
					cout<<setw(50)<<"                                |                                                                                 |               \n";
					cout<<setw(50)<<"                                |                                                                                 |               \n";
					cout<<setw(50)<<"                                |                    2  .  DESI FOOD                                              |               \n";
					cout<<setw(50)<<"                                |                                                                                 |               \n";
					cout<<setw(50)<<"                                |                                                                                 |               \n";
					cout<<setw(50)<<"                                |                    3  .  SWEETS & DISERT                                        |               \n";
					cout<<setw(50)<<"                                |                                                                                 |               \n";
					cout<<setw(50)<<"                                |                                                                                 |               \n";
					cout<<setw(50)<<"                                |                    4  .  DRINKS                                                 |               \n";
					cout<<setw(50)<<"                                |                                                                                 |               \n";
					cout<<setw(50)<<"                                |                                                                                 |               \n";
					cout<<setw(50)<<"                                |                    5  .  EXIT                                                   |               \n";
					cout<<setw(50)<<"                                ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~              \n";
					cout<<setw(40)<<"                                Choice : ";
					cin>>choice;
					if (choice==1)
					{
						system("cls");
						do{
					    cout<<"\n\n\n";
						cout<<setw(50)<<"                       ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~  \n";
					    cout<<setw(50)<<"                       |                                                          FAST FOOD                                                   |  \n";
					    cout<<setw(50)<<"                       ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~  \n";
					    cout<<setw(50)<<"                       |            1  .  BURGER              |       6  .  CHICKEN PIECE              |         11  .  PASTA                 |  \n";
					    cout<<setw(50)<<"                       |                                      |                                        |                                      |  \n";
					    cout<<setw(50)<<"                       |                                      |                                        |                                      |  \n";
					    cout<<setw(50)<<"                       |            2  .  PIZZA               |       7  .  CHICKEN WINGS              |         12  .  DRUM STICK            |  \n";
					    cout<<setw(50)<<"                       |                                      |                                        |                                      |  \n";
					    cout<<setw(50)<<"                       |                                      |                                        |                                      |  \n";
					    cout<<setw(50)<<"                       |            3  .  SHAWARMA            |       8  .  CHICKEN NUGGETS            |         13  .  SOMASA                |  \n";
					    cout<<setw(50)<<"                       |                                      |                                        |                                      |  \n";
					    cout<<setw(50)<<"                       |                                      |                                        |                                      |  \n";
					    cout<<setw(50)<<"                       |            4  .  SANDWITCH           |       9  .  HOT & SPICY                |         14  .  ROLL PARATHA          |  \n";
					    cout<<setw(50)<<"                       |                                      |                                        |                                      |  \n";
					    cout<<setw(50)<<"                       |                                      |                                        |                                      |  \n";
					    cout<<setw(50)<<"                       |            5  .  FISH                |      10  .  BARBIE KU                  |         15  .  CHAT                  |  \n";
					    cout<<setw(50)<<"                       |                                      |                                        |                                      |  \n";
					    cout<<setw(50)<<"                       |                                      |                                        |                                      |  \n";
					    cout<<setw(50)<<"                       ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~  \n";
					    cout<<setw(50)<<"                       |                                                      16 . EXIT                                                       |  \n";
					    cout<<setw(50)<<"                       ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~  \n";
					    cout<<setw(40)<<"                       Choice : ";
					    cin>>choice;
					    switch(choice)
						{
							case 1:
								system("cls");
								do{
					            cout<<"\n\n\n";
						        cout<<setw(50)<<"                                ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~             \n";
					            cout<<setw(50)<<"                                |              BURGER                  |             \n";
					            cout<<setw(50)<<"                                ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~             \n";
					            cout<<setw(50)<<"                                |         1  .  ZINGER (350)           |             \n";
					            cout<<setw(50)<<"                                |                                      |             \n";
					            cout<<setw(50)<<"                                |                                      |             \n";
					            cout<<setw(50)<<"                                |         2  .  CRUNCH (230)           |             \n";
					            cout<<setw(50)<<"                                |                                      |             \n";
					            cout<<setw(50)<<"                                |                                      |             \n";
					            cout<<setw(50)<<"                                |         3  .  DOUBLE PATTY (450)     |             \n";
					            cout<<setw(50)<<"                                |                                      |             \n";
					            cout<<setw(50)<<"                                |                                      |             \n";
					            cout<<setw(50)<<"                                |         4  .  CHEESE BURGER (400)    |             \n";
					            cout<<setw(50)<<"                                |                                      |             \n";
					            cout<<setw(50)<<"                                |                                      |             \n";
					            cout<<setw(50)<<"                                |         5  .  ZINGER SUPREME (520)   |             \n";
					            cout<<setw(50)<<"                                |                                      |             \n";
					            cout<<setw(50)<<"                                ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~             \n";
					            cout<<setw(50)<<"                                |            6 . EXIT                  |             \n";
					            cout<<setw(50)<<"                                ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~             \n";
					            cout<<setw(40)<<"                                Choice : ";
					            cin>>choice1;
					            switch(choice1)
								{
									case 1:
										quantity=0;
										cout<<"                                Zinger Burger\n";
										cout<<"                                Amount : ";
										cin>>quantity;
										//cout<<quantity<<endl;
										F.Burger(choice1,quantity);
										system("cls");
										cout<<"                                        "<<quantity<<" Zinger Burger DONE \n"; 
										break;
									case 2:
										quantity=0;
										cout<<"                                Crunch Burger\n";
										cout<<"                                Amount : ";
										cin>>quantity;
										F.Burger(choice1,quantity);
										system("cls");
										cout<<"                                        "<<quantity<<" Crunch Burger DONE \n";
										break;
									case 3:
									    quantity=0;
										cout<<"                                Double Patty Burger\n";
										cout<<"                                Amount : ";			
										cin>>quantity;
										F.Burger(choice1,quantity);
										system("cls");
										cout<<"                                        "<<quantity<<" Double Patty Burger DONE \n";
										break;
									case 4:
										quantity=0;
										cout<<"                                Chesse Burger\n";
										cout<<"                                Amount : ";
										cin>>quantity;
										F.Burger(choice1,quantity);
										system("cls");
										cout<<"                                        "<<quantity<<" Cheese Burger DONE \n";
										break;
									case 5:
										quantity=0;
										cout<<"                                ZINGER SUPREME\n";
										cout<<"                                Amount : ";
										cin>>quantity;
										F.Burger(choice1,quantity);
										system("cls");
										cout<<"                                        "<<quantity<<" ZINGER SUPREME DONE \n";
										break;
									case 6:
										system("cls");
										cout<<setw(50)<<"\n                       #########################################              EXIT BURGER MENU              ######################################## \n ";
										break;
									default:
										system("cls");
										cout<<setw(50)<<"\n                                ########       WRONG INPUT      ########\n";
										
								}
							    }while(choice1 != 6);
							    break;
						
						    case 2:
						    	system("cls");
								do{
					            cout<<"\n\n\n";
						        cout<<setw(50)<<"                                ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n";
					            cout<<setw(50)<<"                                |              PIZZA                   |     Size     |\n";
					            cout<<setw(50)<<"                                |~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~|~~~~~~~~~~~~~~|\n";
					            cout<<setw(50)<<"                                |         1  .  FAJITA (S/M/L)         |              |\n";
					            cout<<setw(50)<<"                                |                                      |              |\n";
					            cout<<setw(50)<<"                                |                                      |              |\n";
					            cout<<setw(50)<<"                                |         2  .  TIKKA  (S/M/L)         | SMALL = 450  |\n";
					            cout<<setw(50)<<"                                |                                      |              |\n";
					            cout<<setw(50)<<"                                |                                      | MEDIUM = 850 |\n";
					            cout<<setw(50)<<"                                |         3  .  CHEESE LODER (S/M/L)   |              |\n";
					            cout<<setw(50)<<"                                |                                      | LARGE = 1250 |\n";
					            cout<<setw(50)<<"                                |                                      |              |\n";
					            cout<<setw(50)<<"                                |         4  .  BARBIE KU  (S/M/L)     |              |\n";
					            cout<<setw(50)<<"                                |~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~|~~~~~~~~~~~~~~|\n";
					            cout<<setw(50)<<"                                |                                      | SMALL = 550  |\n";
					            cout<<setw(50)<<"                                |         5  .  A & Z SPECIAL (S/M/L)  | MEDIUM = 950 |\n";
					            cout<<setw(50)<<"                                |                                      | LARGE = 1350 |\n";
					            cout<<setw(50)<<"                                |~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~|\n";
					            cout<<setw(50)<<"                                |                       6 . EXIT                      |\n";
					            cout<<setw(50)<<"                                ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n";
					            cout<<setw(40)<<"                                Choice : ";
					            cin>>choice1;
					            switch(choice1)
								{
									case 1:
									    quantity=0;
										cout<<"                                FAJITA PIZZA  \n";
										cout<<"                                SIZE(S/M/L) : ";
										cin>>s;
										cout<<"                                QUANTITY : ";
										cin>>quantity;
										F.PIZZA(choice1,s,quantity);
										system("cls");
										cout<<"                                        "<<quantity<<" "<< s <<" FAJITA PIZZA DONE \n";
										break;
									case 2:
										quantity=0;
										cout<<"                                TIKKA \n";
										cout<<"                                SIZE(S/M/L) : ";
										cin>>s;
										cout<<"                                Quantity : ";
										cin>>quantity;
										F.PIZZA(choice1,s,quantity);
										system("cls");
										cout<<"                                        "<<quantity<<" "<< s <<" TIKKA DONE \n";
										break;
									case 3:
										quantity=0;
										cout<<"                                CHEESE LOADER \n";
										cout<<"                                SIZE(S/M/L) : ";
										cin>>s;
										cout<<"                                Quantity : ";
										cin>>quantity;
										F.PIZZA(choice1,s,quantity);
										system("cls");
										cout<<"                                        "<<quantity<<" "<< s <<" CHEESE LOADER DONE \n";
										break;
									case 4:
										quantity=0;
										cout<<"                                BBQ \n";
										cout<<"                                SIZE(S/M/L) : ";
										cin>>s;
										cout<<"                                Quantity : ";
										cin>>quantity;
										F.PIZZA(choice1,s,quantity);
										system("cls");
										cout<<"                                        "<<quantity<<" "<< s <<" BBQ DONE \n";
										break;
									case 5:
										quantity=0;
										cout<<"                                A & Z SPECIAL \n";
										cout<<"                                SIZE(S/M/L) : ";
										cin>>s;
										cout<<"                                Quantity : ";
										cin>>quantity;
										F.PIZZA(choice1,s,quantity);
										system("cls");
										cout<<"                                        "<<quantity<<" "<< s <<" A & Z SPECIAL DONE \n";
										break;
									case 6:
										system("cls");
										cout<<setw(50)<<"\n                       #########################################              EXIT PIZZA              ######################################### \n ";
										break;
									default:
										system("cls");
										cout<<setw(50)<<"\n                                ########       WRONG INPUT      ########\n";
								
										
								}
							    }while(choice1 != 6);
							    break;
						case 3:
							system("cls");
								do{
					            cout<<"\n\n\n";
						        cout<<setw(50)<<"                                ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n";
					            cout<<setw(50)<<"                                |              SHAWARMA                |    SIZE     |\n";
					            cout<<setw(50)<<"                                |~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~|~~~~~~~~~~~~~|\n";
					            cout<<setw(50)<<"                                |         1  .  ZINGER (S/L)           | Small  170  |\n";
					            cout<<setw(50)<<"                                |                                      | Large  250  |\n";
					            cout<<setw(50)<<"                                |                                      |~~~~~~~~~~~~~|\n";
					            cout<<setw(50)<<"                                |         2  .  CHICKEN  (S/L)         | Small  150  |\n";
					            cout<<setw(50)<<"                                |                                      | Large  210  |\n";
					            cout<<setw(50)<<"                                |                                      |~~~~~~~~~~~~~|\n";
					            cout<<setw(50)<<"                                |         3  .  CHEESE (S/L)           | Small  200  |\n";
					            cout<<setw(50)<<"                                |                                      | Large  280  |\n";
					            cout<<setw(50)<<"                                |                                      |~~~~~~~~~~~~~|\n";
					            cout<<setw(50)<<"                                |         4  .  A & Z SPECIAL (S/L)    | Small  250  |\n";
					            cout<<setw(50)<<"                                |                                      | Large  320  |\n";
					            cout<<setw(50)<<"                                |~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~|\n";
					            cout<<setw(50)<<"                                |                       5 . EXIT                     |\n";
					            cout<<setw(50)<<"                                ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n";
					            cout<<setw(40)<<"                                Choice : ";
					            cin>>choice1;
					            switch(choice1)
								{
									case 1:
										quantity=0;
										cout<<"                                ZINGER  \n";
										cout<<"                                SIZE(S/L) : ";
										cin>>s;
										cout<<"                                Quantity : ";
										cin>>quantity;
										F.SHAWARMA(choice1,s,quantity);										
										system("cls");
										cout<<"\n                                        "<<quantity<<" ZINGER SHAWARMA DONE \n";
										break;
									case 2:
										quantity=0;
										cout<<"                                CHICKEN \n";
										cout<<"                                SIZE (S/L) : ";
										cin>>s;
										cout<<"                                Quantity : ";
										cin>>quantity;
										F.SHAWARMA(choice1,s,quantity);	
										system("cls");
										cout<<"\n                                        "<<quantity<<" CHICKEN SHAWARMA DONE \n";
										break;
									case 3:
										quantity=0;
										cout<<"                                CHEESE  \n";
										cout<<"                                SIZE (S/L) : ";
										cin>>s;
										cout<<"                                Quantity : ";
										cin>>quantity;
										F.SHAWARMA(choice1,s,quantity);	
										system("cls");
										cout<<"\n                                        "<<quantity<<" CHEESE SHAWARMA DONE \n";
										break;
									case 4:
										quantity=0;
										cout<<"                                A & Z SPECIAL \n";
										cout<<"                                SIZE (S/L) : ";
										cin>>s;
										cout<<"                                Quantity : ";
										cin>>quantity;
										F.SHAWARMA(choice1,s,quantity);	
										system("cls");
										cout<<"\n                                        "<<quantity<<" A & Z SPECIAL SHAWARMA DONE \n";
										break;
									case 5:
										system("cls");
										cout<<setw(50)<<"\n                       ########################################              EXIT SHAWARMA              ####################################### \n ";
										break;
									default:
										system("cls");
										cout<<setw(50)<<"\n                                ########       WRONG INPUT      ########\n";
										
								}
							    }while(choice1 != 5);
							    break;
						case 4:
							system("cls");
								do{							
					            cout<<"\n\n\n";
						        cout<<setw(50)<<"                                ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n";
					            cout<<setw(50)<<"                                |              SANDWITCH               |\n";
					            cout<<setw(50)<<"                                |~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~|\n";
					            cout<<setw(50)<<"                                |         1  .  CHICKEN (180)          |\n";
					            cout<<setw(50)<<"                                |                                      |\n";
					            cout<<setw(50)<<"                                |                                      |\n";
					            cout<<setw(50)<<"                                |         2  .  CLUB  (220)            |\n";
					            cout<<setw(50)<<"                                |                                      |\n";
					            cout<<setw(50)<<"                                |~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~|\n";
					            cout<<setw(50)<<"                                |              3 . EXIT                |\n";
					            cout<<setw(50)<<"                                ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n";
					            cout<<setw(40)<<"                                Choice : ";
					            cin>>choice1;
					            switch(choice1)
								{
									case 1:
										cout<<"                                CHICKEN SANDWITCH (S/L) \n";
										cout<<"                                Quantity : ";
										cin>>quantity;
										F.SANDWITCH(choice1,quantity);
										system("cls");
										cout<<"\n                                        "<<quantity<<" CHICKEN SANDWITCH DONE \n";
										break;
									case 2:
										cout<<"                                CLUB SANDWITCH (S/L) \n";
										cout<<"                                Quantity : ";
										cin>>quantity;
										F.SANDWITCH(choice1,quantity);
										system("cls");
										cout<<"\n                                        "<<quantity<<" CLUB SANDWITCH DONE \n";
										break;
									case 3:
										system("cls");
										cout<<setw(50)<<"\n                       #######################################              EXIT SANDWITCH              ####################################### \n ";
										break;
									default:
										system("cls");
										cout<<setw(50)<<"\n                                ########       WRONG INPUT      ########\n";
										
								}
							    }while(choice1 != 3);
							    break;
						case 5:
							system("cls");
								do{
						        cout<<setw(50)<<"                                ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n";
					            cout<<setw(50)<<"                                |              FISH                    |             |\n";
					            cout<<setw(50)<<"                                ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~|~~~~~~~~~~~~~|\n";
					            cout<<setw(50)<<"                                |         1  .  Finger Fish            | 1 piece 220 |\n";
					            cout<<setw(50)<<"                                |                                      |             |\n";
					            cout<<setw(50)<<"                                |                                      |~~~~~~~~~~~~~|\n";
					            cout<<setw(50)<<"                                |         2  .  Masala Fish            | 1 piece 160 |\n";
					            cout<<setw(50)<<"                                |                                      |             |\n";
					            cout<<setw(50)<<"                                ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~|\n";
					            cout<<setw(50)<<"                                |                      3 . EXIT                      |\n";
					            cout<<setw(50)<<"                                ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n";
					            cout<<setw(40)<<"                                Choice : ";
					            cin>>choice1;;
					            switch(choice1)
								{
									case 1:
										cout<<"                                FINGER FISH \n";
										cout<<"                                quantity : ";
										cin>>quantity;
										F.FISH(choice1,quantity);
										system("cls");
										cout<<"\n                                        "<<quantity<<" FINGER FISH PIECE DONE \n";
										break;
									case 2:
										cout<<"                                MASALA FISH \n";
										cout<<"                                quantity : ";
										cin>>quantity;
										F.FISH(choice1,quantity);
										system("cls");
										cout<<"\n                                        "<<quantity<<" MASALA FISH PIECE DONE \n";
										break;
									case 3:
										system("cls");
										cout<<setw(50)<<"\n                       #########################################               EXIT FISH              ######################################### \n ";
										break;
									default:
										system("cls");
										cout<<setw(50)<<"\n                                ########       WRONG INPUT      ########\n";
										
								}
							    }while(choice1 != 3);
							    break;
						case 6:
							system("cls");
								do{
					            cout<<"\n\n\n";
						        cout<<setw(50)<<"                                ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~             \n";
					            cout<<setw(50)<<"                                |              CHICKEN PIECE           |             \n";
					            cout<<setw(50)<<"                                ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~             \n";
					            cout<<setw(50)<<"                                |         1  .  1 PIECE (250)          |             \n";
					            cout<<setw(50)<<"                                |                                      |             \n";
					            cout<<setw(50)<<"                                |                                      |             \n";
					            cout<<setw(50)<<"                                |         2  .  3 PIECE (650)          |             \n";
					            cout<<setw(50)<<"                                |                                      |             \n";
					            cout<<setw(50)<<"                                |                                      |             \n";
					            cout<<setw(50)<<"                                |         3  .  5 PIECE (1050)         |             \n";
					            cout<<setw(50)<<"                                |                                      |             \n";
					            cout<<setw(50)<<"                                |                                      |             \n";
					            cout<<setw(50)<<"                                |         4  .  12pc Family deal (1700)|             \n";
					            cout<<setw(50)<<"                                |                                      |             \n";
					            cout<<setw(50)<<"                                ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~             \n";
					            cout<<setw(50)<<"                                |            5 . EXIT                  |             \n";
					            cout<<setw(50)<<"                                ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~             \n";
					            cout<<setw(40)<<"                                Choice : ";
					            cin>>choice1;
					            switch(choice1)
								{
									case 1:
										F.CHICKEN_PIECE(choice1);
										system("cls");
										cout<<"\n                                         1 PIECE DONE \n";
										break;
									case 2:
										F.CHICKEN_PIECE(choice1);
										system("cls");
										cout<<"\n                                         3 PIECE DONE \n";
										break;
									case 3:
										F.CHICKEN_PIECE(choice1);
										system("cls");
										cout<<"\n                                         5 PIECE DONE \n";
										break;
									case 4:
										F.CHICKEN_PIECE(choice1);
										system("cls");
										cout<<"\n                                         Family deal (12pc) DONE \n";
										break;
									case 5:
										system("cls");
										cout<<setw(50)<<"\n                       #####################################              EXIT CHICKEN PIECE              ##################################### \n ";
										break;
									default:
										system("cls");
										cout<<setw(50)<<"\n                                ########       WRONG INPUT      ########\n";
										
								}
							    }while(choice1 != 5);
							    break;
						case 7:
							system("cls");
								do{
					            cout<<"\n\n\n";
						        cout<<setw(50)<<"                                ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~             \n";
					            cout<<setw(50)<<"                                |             CHICKEN WINGS            |             \n";
					            cout<<setw(50)<<"                                |~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~|             \n";
					            cout<<setw(50)<<"                                |         1  .  MINI BUCKET (520)      |             \n";
					            cout<<setw(50)<<"                                |                                      |             \n";
					            cout<<setw(50)<<"                                |                                      |             \n";
					            cout<<setw(50)<<"                                |         2  .  FULL BUCKET (950)      |             \n";
					            cout<<setw(50)<<"                                |                                      |             \n";
					            cout<<setw(50)<<"                                |~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~|             \n";
					            cout<<setw(50)<<"                                |            3 . EXIT                  |             \n";
					            cout<<setw(50)<<"                                ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~             \n";
					            cout<<setw(40)<<"                                Choice : ";
					            cin>>choice1;
					            switch(choice1)
								{
									case 1:
										F.CHICKEN_WINGS(choice1);
										system("cls");
										cout<<"\n                                         MINI BUCKET (8pc) DONE\n";
										break;
									case 2:
										F.CHICKEN_WINGS(choice1);
										system("cls");
										cout<<"\n                                         FULL BUCKET (14pc) DONE\n";
										break;
									case 3:
										system("cls");
										cout<<setw(50)<<"\n                       #####################################              EXIT CHICKEN WINGS              ##################################### \n ";
										break;
									default:
										system("cls");
										cout<<setw(50)<<"\n                                ########       WRONG INPUT      ########\n";
										
								}
							    }while(choice1 != 3);
							    break;
						case 8:
							system("cls");
								do{
					            cout<<"\n\n\n";
						        cout<<setw(50)<<"                                ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~             \n";
					            cout<<setw(50)<<"                                |             CHICKEN NUGGETS          |             \n";
					            cout<<setw(50)<<"                                ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~             \n";
					            cout<<setw(50)<<"                                |         1  .  MINI BUCKET (650)      |             \n";
					            cout<<setw(50)<<"                                |                                      |             \n";
					            cout<<setw(50)<<"                                |                                      |             \n";
					            cout<<setw(50)<<"                                |         2  .  FULL BUCKET (1150)     |             \n";
					            cout<<setw(50)<<"                                |                                      |             \n";
					            cout<<setw(50)<<"                                ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~             \n";
					            cout<<setw(50)<<"                                |            3 . EXIT                  |             \n";
					            cout<<setw(50)<<"                                ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~             \n";
					            cout<<setw(40)<<"                                Choice : ";
					            cin>>choice1;
					            switch(choice1)
								{
									case 1:
										F.CHICKEN_NUGGETS(choice1);
										system("cls");
										cout<<"\n                                         MINI BUCKET (8pc) DONE\n";
										break;
									case 2:
										F.CHICKEN_NUGGETS(choice1);
										system("cls");
										cout<<"\n                                         FULL BUCKET (14pc) DONE\n";
										break;
									case 3:
										system("cls");
										cout<<setw(50)<<"\n                       ####################################              EXIT CHICKEN NUGGETS              #################################### \n ";
										break;
									default:
										system("cls");
										cout<<setw(50)<<"\n                                ########       WRONG INPUT      ########\n";
										
								}
							    }while(choice1 != 3);
							    break;
						case 9:
							system("cls");
								do{
					            cout<<"\n\n\n";
						        cout<<setw(50)<<"                                ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~             \n";
					            cout<<setw(50)<<"                                |             HOT & SPICY              |             \n";
					            cout<<setw(50)<<"                                ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~             \n";
					            cout<<setw(50)<<"                                |         1  .  MINI BUCKET (600)      |             \n";
					            cout<<setw(50)<<"                                |                                      |             \n";
					            cout<<setw(50)<<"                                |                                      |             \n";
					            cout<<setw(50)<<"                                |         2  .  FULL BUCKET (1050)     |             \n";
					            cout<<setw(50)<<"                                |                                      |             \n";
					            cout<<setw(50)<<"                                ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~             \n";
					            cout<<setw(50)<<"                                |            3 . EXIT                  |             \n";
					            cout<<setw(50)<<"                                ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~             \n";
					            cout<<setw(40)<<"                                Choice : ";
					            cin>>choice1;
					            switch(choice1)
								{
									case 1:
										cout<<"                                MINI BUCKET (8pc) \n";
										F.CHICKEN_HOT_SPICY(choice1);
										system("cls");
										cout<<"\n                                         MINI BUCKET (8pc) DONE\n";
										break;
									case 2:
										cout<<"                                FULL BUCKET (14pc) \n";
										F.CHICKEN_HOT_SPICY(choice1);
										system("cls");
										cout<<"\n                                         FULL BUCKET (14pc) DONE\n";
										break;
									case 3:
										system("cls");
										cout<<setw(50)<<"\n                       ######################################              EXIT HOT & SPICY              ###################################### \n ";
										break;
									default:
										system("cls");
										cout<<setw(50)<<"\n                                ########       WRONG INPUT      ########\n";
										
								}
							    }while(choice1 != 3);
							    break;
						case 10:
							system("cls");
								do{
					            cout<<"\n\n\n";
						        cout<<setw(50)<<"                                ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~             \n";
					            cout<<setw(50)<<"                                |                  BBQ                 |             \n";
					            cout<<setw(50)<<"                                |~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~|             \n";
					            cout<<setw(50)<<"                                |         1  .  1 PIECE (120)          |             \n";
					            cout<<setw(50)<<"                                |                                      |             \n";
					            cout<<setw(50)<<"                                |                                      |             \n";
					            cout<<setw(50)<<"                                |         2  .  3 PIECE (320)          |             \n";
					            cout<<setw(50)<<"                                |                                      |             \n";
					            cout<<setw(50)<<"                                |                                      |             \n";
					            cout<<setw(50)<<"                                |         3  .  5 PIECE (550)          |             \n";
					            cout<<setw(50)<<"                                |                                      |             \n";
					            cout<<setw(50)<<"                                |                                      |             \n";
					            cout<<setw(50)<<"                                |         4  .  10pc Family deal (950) |             \n";
					            cout<<setw(50)<<"                                |                                      |             \n";
					            cout<<setw(50)<<"                                |~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~|             \n";
					            cout<<setw(50)<<"                                |            5 . EXIT                  |             \n";
					            cout<<setw(50)<<"                                ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~             \n";
					            cout<<setw(40)<<"                                Choice : ";
					            cin>>choice1;
					            switch(choice1)
								{
									case 1:
										F.BBQ(choice1);
										system("cls");
										cout<<"\n                                         1 PIECE DONE \n";
										break;
									case 2:
										cout<<"                                3 PIECE \n";
										F.BBQ(choice1);
										system("cls");
										cout<<"\n                                         3 PIECE DONE \n";
										break;
									case 3:
										cout<<"                                5 PIECE \n";
										F.BBQ(choice1);
										system("cls");
										cout<<"\n                                         5 PIECE DONE \n";
										break;
									case 4:
										cout<<"                                Family deal (12pc) \n";
										F.BBQ(choice1);
										system("cls");
										cout<<"\n                                         Family deal (10pc) DONE \n";
										break;
									case 5:
										system("cls");
										cout<<setw(50)<<"\n                       #######################################              EXIT BARBIE KU              ####################################### \n ";
										break;
									default:
										system("cls");
										cout<<setw(50)<<"\n                                ########       WRONG INPUT      ########\n";
										
								}
							    }while(choice1 != 5);
							    break;
						case 11:
							system("cls");
								do{
					            cout<<"\n\n\n";
					            cout<<setw(50)<<"                                ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n";
					            cout<<setw(50)<<"                                |                 PASTA                |    SIZE     |\n";
					            cout<<setw(50)<<"                                ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~|~~~~~~~~~~~~~|\n";
					            cout<<setw(50)<<"                                |         1  .  CRUNCH (S/L)           | Small  650  |\n";
					            cout<<setw(50)<<"                                |                                      | Large  850  |\n";
					            cout<<setw(50)<<"                                |                                      |~~~~~~~~~~~~~|\n";
					            cout<<setw(50)<<"                                |         2  .  CHEESE LOADER (S/L)    | Small  750  |\n";
					            cout<<setw(50)<<"                                |                                      | Large  950  |\n";
					            cout<<setw(50)<<"                                ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~|\n";
					            cout<<setw(50)<<"                                |                      3 . EXIT                      |\n";
					            cout<<setw(50)<<"                                ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n";
					            cout<<setw(40)<<"                                Choice : ";
					            cin>>choice1;
					            switch(choice1)
								{
									case 1:
										cout<<"                                CRUNCH (S/L) \n";
										cout<<"                                SIZE (S/L) : ";
										cin>>s;
										cout<<"                                Quantity : ";
										cin>>quantity;
										F.Pasta(choice1,s,quantity);
										system("cls");
										cout<<"\n                                        "<<quantity<<" CRUNCH PASTA DONE \n";
										break;
									case 2:
										cout<<"                                CHEESE LOADER (S/L) \n";
										cout<<"                                SIZE (S/L) : ";
										cin>>s;
										cout<<"                                Quantity : ";
										cin>>quantity;
										F.Pasta(choice1,s,quantity);
										system("cls");
										cout<<"\n                                        "<<quantity<<" CHEESE LOADER DONE \n";
										break;
									case 3:
										system("cls");
										cout<<setw(50)<<"\n                       #########################################              EXIT PASTA              ######################################### \n ";
										break;
									default:
										system("cls");
										cout<<setw(50)<<"\n                                ########       WRONG INPUT      ########\n";
										
								}
							    }while(choice1 != 3);
							    break;
						case 12:
							system("cls");
								do{
					            cout<<"\n\n\n";
						        cout<<setw(50)<<"                                ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~             \n";
					            cout<<setw(50)<<"                                |              DRUM STICK              |             \n";
					            cout<<setw(50)<<"                                ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~             \n";
					            cout<<setw(50)<<"                                |         1  .  1 STICK  (160)         |             \n";
					            cout<<setw(50)<<"                                |                                      |             \n";
					            cout<<setw(50)<<"                                |                                      |             \n";
					            cout<<setw(50)<<"                                |         2  .  3 STICK  (450)         |             \n";
					            cout<<setw(50)<<"                                |                                      |             \n";
					            cout<<setw(50)<<"                                |                                      |             \n";
					            cout<<setw(50)<<"                                |         3  .  5 STICK  (750)         |             \n";
					            cout<<setw(50)<<"                                |                                      |             \n";
					            cout<<setw(50)<<"                                |                                      |             \n";
					            cout<<setw(50)<<"                                |         4  .  10pc Family deal (1450)|             \n";
					            cout<<setw(50)<<"                                |                                      |             \n";
					            cout<<setw(50)<<"                                ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~             \n";
					            cout<<setw(50)<<"                                |            5 . EXIT                  |             \n";
					            cout<<setw(50)<<"                                ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~             \n";
					            cout<<setw(40)<<"                                Choice : ";
					            cin>>choice1;
					            switch(choice1)
								{
									case 1:
										F.DRUM_STICK(choice1);
										system("cls");
										cout<<"\n                                         1 DRUM STICK DONE \n";
										break;
									case 2:
										F.DRUM_STICK(choice1);
										system("cls");
										cout<<"\n                                         3 DRUM STICK DONE \n";
										break;
									case 3:
										F.DRUM_STICK(choice1);
										system("cls");
										cout<<"\n                                         5 DRUM STICK DONE \n";
										break;
									case 4:
										F.DRUM_STICK(choice1);
										system("cls");
										cout<<"\n                                         Family deal (10pc) DONE \n";
										break;
									case 5:
										system("cls");
										cout<<setw(50)<<"\n                       ######################################               EXIT DRUM STICK              ###################################### \n ";
										break;
									default:
										system("cls");
										cout<<setw(50)<<"\n                                ########       WRONG INPUT      ########\n";
										
								}
							    }while(choice1 != 5);
							    break;
							    
						case 13:
							system("cls");
								do{
					            cout<<"\n\n\n";
					            cout<<setw(50)<<"                                ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n";
					            cout<<setw(50)<<"                                |                 SOMASA               |    SIZE     |\n";
					            cout<<setw(50)<<"                                ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~|~~~~~~~~~~~~~|\n";
					            cout<<setw(50)<<"                                |         1  .  CHICKEN SOMASA         | 1 piece 90  |\n";
					            cout<<setw(50)<<"                                |                                      |             |\n";
					            cout<<setw(50)<<"                                |                                      |~~~~~~~~~~~~~|\n";
					            cout<<setw(50)<<"                                |         2  .  ALLU SOMASA            | 1 piece 60  |\n";
					            cout<<setw(50)<<"                                |                                      |             |\n";
					            cout<<setw(50)<<"                                ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~|\n";
					            cout<<setw(50)<<"                                |                      3 . EXIT                      |\n";
					            cout<<setw(50)<<"                                ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n";
					            cout<<setw(40)<<"                                Choice : ";
					            cin>>choice1;
					            switch(choice1)
								{
									case 1:
										cout<<"                                CHICKEN SOMASA \n";
										cout<<"                                Amount : ";
										cin>>quantity;
										F.SOMASA(choice1,quantity);
										system("cls");
										cout<<"\n                                        "<<quantity<<" CHICKEN SOMASA DONE \n";
										break;
									case 2:
										cout<<"                                ALLU SOMASA \n";
										cout<<"                                Amount : ";
										cin>>quantity;
										F.SOMASA(choice1,quantity);
										system("cls");
										cout<<"\n                                        "<<quantity<<" ALLU SOMASA DONE \n";
										break;
									case 3:
										system("cls");
										cout<<setw(50)<<"\n                       ########################################               EXIT SOMASA              ######################################## \n ";
										break;
									default:
										system("cls");
										cout<<setw(50)<<"\n                                ########       WRONG INPUT      ########\n";
										
								}
							    }while(choice1 != 3);
							    break;
						case 14:
							system("cls");
								do{
					            cout<<"\n\n\n";
						        cout<<setw(50)<<"                                ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n";
					            cout<<setw(50)<<"                                |              ROLL PRATHA             |    SIZE     |\n";
					            cout<<setw(50)<<"                                |~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~|~~~~~~~~~~~~~|\n";
					            cout<<setw(50)<<"                                |         1  .  ZINGER (S/L)           | Small  190  |\n";
					            cout<<setw(50)<<"                                |                                      | Large  310  |\n";
					            cout<<setw(50)<<"                                |                                      |~~~~~~~~~~~~~|\n";
					            cout<<setw(50)<<"                                |         2  .  CHICKEN  (S/L)         | Small  150  |\n";
					            cout<<setw(50)<<"                                |                                      | Large  210  |\n";
					            cout<<setw(50)<<"                                |                                      |~~~~~~~~~~~~~|\n";
					            cout<<setw(50)<<"                                |         3  .  CHEESE (S/L)           | Small  220  |\n";
					            cout<<setw(50)<<"                                |                                      | Large  350  |\n";
					            cout<<setw(50)<<"                                |                                      |~~~~~~~~~~~~~|\n";
					            cout<<setw(50)<<"                                |         4  .  A & Z SPECIAL (S/L)    | Small  300  |\n";
					            cout<<setw(50)<<"                                |                                      | Large  400  |\n";
					            cout<<setw(50)<<"                                |~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~|\n";
					            cout<<setw(50)<<"                                |                       5 . EXIT                     |\n";
					            cout<<setw(50)<<"                                ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n";
					            cout<<setw(40)<<"                                Choice : ";
					            cin>>choice1;
					            switch(choice1)
								{
									case 1:
										cout<<"                                ZINGER \n";
										cout<<"                                SIZE (S/L) : ";
										cin>>s;
										cout<<"                                Quantity : ";
										cin>>quantity;
										F.ROLL_PARATHA(choice1,s,quantity);
										system("cls");
										cout<<"\n                                        "<<quantity<<" ZINGER ROLL PRATHA DONE \n";
										break;
									case 2:
										cout<<"                                CHICKEN \n";
										cout<<"                                SIZE (S/L) : ";
										cin>>s;
										cout<<"                                Quantity : ";
										cin>>quantity;
										F.ROLL_PARATHA(choice1,s,quantity);
										system("cls");
										cout<<"\n                                        "<<quantity<<" CHICKEN ROLL PRATHA DONE \n";
										break;
									case 3:
										cout<<"                                CHEESE \n";
										cout<<"                                SIZE (S/L) : ";
										cin>>s;
										cout<<"                                Quantity : ";
										cin>>quantity;
										F.ROLL_PARATHA(choice1,s,quantity);
										system("cls");
										cout<<"\n                                        "<<quantity<<" CHEESE ROLL PRATHA DONE \n";
										break;
									case 4:
										cout<<"                                A & Z SPECIAL \n";
										cout<<"                                SIZE (S/L) : ";
										cin>>s;
										cout<<"                                Quantity : ";
										cin>>quantity;
										F.ROLL_PARATHA(choice1,s,quantity);
										system("cls");
										cout<<"\n                                        "<<quantity<<" A & Z SPECIAL ROLL PRATHA DONE \n";
										break;
									case 5:
										system("cls");
										cout<<setw(50)<<"\n                       ######################################              EXIT ROLL PRATHA              ###################################### \n ";
										break;
									default:
										system("cls");
										cout<<setw(50)<<"\n                                ########       WRONG INPUT      ########\n";
										
								}
							    }while(choice1 != 5);
							    break;
						case 15:
							system("cls");
								do{
					            cout<<"\n\n\n";
					            cout<<setw(50)<<"                                ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n";
					            cout<<setw(50)<<"                                |                 PASTA                |    SIZE     |\n";
					            cout<<setw(50)<<"                                ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~|~~~~~~~~~~~~~|\n";
					            cout<<setw(50)<<"                                |         1  .  FRUIT CHAT (S/L)       | Small  160  |\n";
					            cout<<setw(50)<<"                                |                                      | Large  230  |\n";
					            cout<<setw(50)<<"                                |                                      |~~~~~~~~~~~~~|\n";
					            cout<<setw(50)<<"                                |         2  .  CHANA CHAT (S/L)       | Small  170  |\n";
					            cout<<setw(50)<<"                                |                                      | Large  240  |\n";
					            cout<<setw(50)<<"                                |                                      |~~~~~~~~~~~~~|\n";
					            cout<<setw(50)<<"                                |         3  .  PAPARI CHAT (S/L)      | Small  180  |\n";
					            cout<<setw(50)<<"                                |                                      | Large  250  |\n";
					            cout<<setw(50)<<"                                ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~|\n";
					            cout<<setw(50)<<"                                |                      4 . EXIT                      |\n";
					            cout<<setw(50)<<"                                ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n";
					            cout<<setw(40)<<"                                Choice : ";
					            cin>>choice1;
					            switch(choice1)
								{
									case 1:
										cout<<"                                FRUIT CHAT (S/L) \n";
										cout<<"                                Quantity : ";
										cin>>quantity;
										system("cls");
										cout<<"\n                                        "<<quantity<<" FRUIT CHAT DONE \n";
										break;
									case 2:
										cout<<"                                CHANA CHAT (S/L) \n";
										cout<<"                                Quantity : ";
										cin>>quantity;
										system("cls");
										cout<<"\n                                        "<<quantity<<" CHANA CHAT DONE \n";
										break;
									case 3:
										cout<<"                                PAPARI CHAT (S/L) \n";
										cout<<"                                Quantity : ";
										cin>>quantity;
										system("cls");
										cout<<"\n                                        "<<quantity<<" PAPARI CHAT DONE \n";
										break;
									case 4:
										system("cls");
										cout<<setw(50)<<"\n                       #########################################              EXIT CHAT              ######################################### \n ";
										break;
									default:
										system("cls");
										cout<<setw(50)<<"\n                                ########       WRONG INPUT      ########\n";		
								}
							    }while(choice1 != 4);
							    break;
						case 16:
							system("cls");
							cout<<setw(50)<<"\n                                ###################              EXIT FAST FOOD              ###################### \n ";
							break;
						default:
							system("cls");
							cout<<setw(50)<<"\n                       #######################################                WRONG INPUT               ####################################### \n ";	    
					    }
						}while(choice != 16);
					}
					else if (choice==2)
					{
					system("cls");
						do{
					    cout<<"\n\n\n";
						cout<<setw(50)<<"                       ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~  \n";
					    cout<<setw(50)<<"                       |                                                      DESI FOOD                                                       |  \n";
					    cout<<setw(50)<<"                       ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~  \n";
					    cout<<setw(50)<<"                       |                     1  .  CHICKEN                        |                     6  .  DAAL                            |  \n";
					    cout<<setw(50)<<"                       |                                                          |                                                           |  \n";
					    cout<<setw(50)<<"                       |                                                          |                                                           |  \n";
					    cout<<setw(50)<<"                       |                     2  .  MUTTON                         |                     7  .  BIRYANI                         |  \n";
					    cout<<setw(50)<<"                       |                                                          |                                                           |  \n";
					    cout<<setw(50)<<"                       |                                                          |                                                           |  \n";
					    cout<<setw(50)<<"                       |                     3  .  BEEF                           |                     8  .  PULAO                           |  \n";
					    cout<<setw(50)<<"                       |                                                          |                                                           |  \n";
					    cout<<setw(50)<<"                       |                                                          |                                                           |  \n";
					    cout<<setw(50)<<"                       |                     4  .  SABBZI                         |                     9  .  ROTI/PRATHA                     |  \n";
					    cout<<setw(50)<<"                       |                                                          |                                                           |  \n";
					    cout<<setw(50)<<"                       |                                                          |                                                           |  \n";
					    cout<<setw(50)<<"                       |                     5  .  FISH                           |                    10  .  RAYATA/SALAD                      |  \n";
					    cout<<setw(50)<<"                       |                                                          |                                                           |  \n";
					    cout<<setw(50)<<"                       ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~  \n";
					    cout<<setw(50)<<"                       |                                                      11 . EXIT                                                       |  \n";
					    cout<<setw(50)<<"                       ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~  \n";
					    cout<<setw(40)<<"                       Choice : ";
					    cin>>choice;
					    switch(choice)
						{
							case 1:
								system("cls");
								do{
					            cout<<"\n\n\n";
						        cout<<setw(50)<<"                                ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n";
					            cout<<setw(50)<<"                                |                 CHICKEN              |     SIZE    |\n";
					            cout<<setw(50)<<"                                ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~|~~~~~~~~~~~~~|\n";
					            cout<<setw(50)<<"                                |         1  .  SIMPLE KARAHI (F/H)    |  FULL 1200  |\n";
					            cout<<setw(50)<<"                                |                                      |  HALF 600   |\n";
					            cout<<setw(50)<<"                                |                                      |~~~~~~~~~~~~~|\n";
					            cout<<setw(50)<<"                                |         2  .  WHITE KARAHI (F/H)     |  FULL 1300  |\n";
					            cout<<setw(50)<<"                                |                                      |  HALF 700   |\n";
					            cout<<setw(50)<<"                                |                                      |~~~~~~~~~~~~~|\n";
					            cout<<setw(50)<<"                                |         3  .  BBQ KARAHI (F/H)       |  FULL 1300  |\n";
					            cout<<setw(50)<<"                                |                                      |  HALF 700   |\n";
					            cout<<setw(50)<<"                                |                                      |~~~~~~~~~~~~~|\n";
					            cout<<setw(50)<<"                                |         4  .  CHICKEN ROAST (F/H)    |  FULL 1200  |\n";
					            cout<<setw(50)<<"                                |                                      |  HALF 900   |\n";
					            cout<<setw(50)<<"                                |                                      |~~~~~~~~~~~~~|\n";
					            cout<<setw(50)<<"                                |         5  .  CHICKEN SAJI (F/H)     |  FULL 1200  |\n";
					            cout<<setw(50)<<"                                |                                      |  HALF 600   |\n";
					            cout<<setw(50)<<"                                ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n";
					            cout<<setw(50)<<"                                |                         6 . EXIT                    \n";
					            cout<<setw(50)<<"                                ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n";
					            cout<<setw(40)<<"                                Choice : ";
					            cin>>choice1;
					            switch(choice1)
								{
									case 1:
										quantity=0;
										cout<<"                                SIMPLE KARAHI \n";
										cout<<"                                FULL/HALF(F/H) : ";
										cin>>s;
										cout<<"                                QUANTITY \n";
										cin>> quantity;
										F.CHICKEN(choice1,s,quantity);
										system("cls");
										cout<<"                                        "<<quantity<<" "<<s<<" SIMPLE KARAHI DONE \n"; 
										break;
									case 2:
										quantity=0;
										cout<<"                                WHITE KARAHI (F/H)\n";
										cout<<"                                FULL/HALF(F/H) : ";
										cin>>s;
										cout<<"                                QUANTITY \n";
										cin>> quantity;
										F.CHICKEN(choice1,s,quantity);
										system("cls");
										cout<<"                                        "<<quantity<<" "<<s<<" WHITE KARAHI DONE \n";
										break;
									case 3:
										quantity=0;
										cout<<"                                BBQ KARAHI (F/H)\n";
										cout<<"                                FULL/HALF(F/H) : ";
										cin>>s;
										cout<<"                                QUANTITY \n";
										cin>> quantity;
										F.CHICKEN(choice1,s,quantity);
										system("cls");
										cout<<"                                        "<<quantity<<" "<<s<<" BBQ KARAHI DONE \n";
										break;
									case 4:
										quantity=0;
										cout<<"                                CHICKEN ROAST (F/H)\n";
										cout<<"                                FULL/HALF(F/H) : ";
										cin>>s;
										cout<<"                                QUANTITY \n";
										cin>> quantity;
										F.CHICKEN(choice1,s,quantity);
										system("cls");
										cout<<"                                        "<<quantity<<" "<<s<<" CHICKEN ROAST DONE \n";
										break;
									case 5:
										quantity=0;
										cout<<"                                CHICKEN SAJI\n";
										cout<<"                                FULL/HALF(F/H) : ";
										cin>>s;
										cout<<"                                QUANTITY \n";
										cin>> quantity;
										F.CHICKEN(choice1,s,quantity);
										system("cls");
										cout<<"                                        "<<quantity<<" "<<s<<" CHICKEN SAJI DONE \n";
										break;
									case 6:
										system("cls");
										cout<<setw(50)<<"\n                       #####################################              EXIT CHICKEN MENU              #################################### \n ";
										break;
									default:
										system("cls");
										cout<<setw(50)<<"\n                                ########       WRONG INPUT      ########\n";
										
								}
							    }while(choice1 != 6);
							    break;
						case 2:
								system("cls");
								do{
					            cout<<"\n\n\n";
						        cout<<setw(50)<<"                                ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n";
					            cout<<setw(50)<<"                                |                 MUTTON               |     SIZE    |\n";
					            cout<<setw(50)<<"                                ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~|\n";
					            cout<<setw(50)<<"                                |         1  .  SIMPLE KARAHI (F/H)    |  FULL 1400  |\n";
					            cout<<setw(50)<<"                                |                                      |  HALF 700   |\n";
					            cout<<setw(50)<<"                                |                                      |~~~~~~~~~~~~~|\n";
					            cout<<setw(50)<<"                                |         2  .  WHITE KARAHI (F/H)     |  FULL 1600  |\n";
					            cout<<setw(50)<<"                                |                                      |  HALF 800   |\n";
					            cout<<setw(50)<<"                                |                                      |~~~~~~~~~~~~~|\n";
					            cout<<setw(50)<<"                                |         3  .  BBQ KARAHI (F/H)       |  FULL 1200  |\n";
					            cout<<setw(50)<<"                                |                                      |  HALF 600   |\n";
					            cout<<setw(50)<<"                                |                                      |~~~~~~~~~~~~~|\n";
					            cout<<setw(50)<<"                                |         4  .  MUTTON ROAST (F/H)     |  FULL 1400  |\n";
					            cout<<setw(50)<<"                                |                                      |  HALF 700   |\n";
					            cout<<setw(50)<<"                                |                                      |~~~~~~~~~~~~~|\n";
					            cout<<setw(50)<<"                                |         5  .  MUTTON SAJI (F/H)      |  FULL 1400  |\n";
					            cout<<setw(50)<<"                                |                                      |  HALF 700   |\n";
					            cout<<setw(50)<<"                                ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~|\n";
					            cout<<setw(50)<<"                                |                          6 . EXIT                  |\n";
					            cout<<setw(50)<<"                                ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~|\n";
					            cout<<setw(40)<<"                                Choice : ";
					            cin>>choice1;
					            switch(choice1)
								{
									case 1:
										quantity=0;
										cout<<"                                SIMPLE KARAHI (F/H)\n";
										cout<<"                                FULL/HALF(F/H) : ";
										cin>>s;
										cout<<"                                QUANTITY \n";
										cin>> quantity;
										F.MUTTON(choice1,s,quantity);
										system("cls");
										cout<<"                                        "<<quantity<<" "<<s<<" SIMPLE KARAHI DONE \n"; 
										break;
									case 2:
										quantity=0;
										cout<<"                                WHITE KARAHI (F/H)\n";
										cout<<"                                FULL/HALF(F/H) : ";
										cin>>s;
										cout<<"                                QUANTITY \n";
										cin>> quantity;
										F.MUTTON(choice1,s,quantity);
										system("cls");
										cout<<"                                        "<<quantity<<" "<<s<<" WHITE KARAHI DONE \n";
										break;
									case 3:
										quantity=0;
										cout<<"                                BBQ KARAHI (F/H)\n";
										cout<<"                                FULL/HALF(F/H) : ";
										cin>>s;
										cout<<"                                QUANTITY \n";
										cin>> quantity;
										F.MUTTON(choice1,s,quantity);
										system("cls");
										cout<<"                                        "<<quantity<<" "<<s<<" BBQ KARAHI DONE \n";
										break;
									case 4:
										quantity=0;
										cout<<"                                MUTTON ROAST (F/H)\n";
										cout<<"                                FULL/HALF(F/H) : ";
										cin>>s;
										cout<<"                                QUANTITY \n";
										cin>> quantity;
										F.MUTTON(choice1,s,quantity);
										system("cls");
										cout<<"                                        "<<quantity<<" "<<s<<" MUTTON ROAST DONE \n";
										break;
									case 5:
										quantity=0;
										cout<<"                                MUTTON SAJI\n";
										cout<<"                                FULL/HALF(F/H) : ";
										cin>>s;
										cout<<"                                QUANTITY \n";
										cin>> quantity;
										F.MUTTON(choice1,s,quantity);
										system("cls");
										cout<<"                                        "<<quantity<<" "<<s<<" MUTTON SAJI DONE \n";
										break;
									case 6:
										system("cls");
										cout<<setw(50)<<"\n                       ######################################              EXIT MUTTON MENU              #################################### \n ";
										break;
									default:
										system("cls");
										cout<<setw(50)<<"\n                                ########       WRONG INPUT      ########\n";
										
								}
													
							    }
								while(choice1 != 6);
							    break;
						case 3:
								system("cls");
								do{
					            cout<<"\n\n\n";
						        cout<<setw(50)<<"                                ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n";
					            cout<<setw(50)<<"                                |                  BEEF                |     SIZE    |\n";
					            cout<<setw(50)<<"                                ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n";
					            cout<<setw(50)<<"                                |         1  .  SIMPLE KARAHI (F/H)    |   FULL 1300 |\n";
					            cout<<setw(50)<<"                                |                                      |   HALF 650  |\n";
					            cout<<setw(50)<<"                                |                                      |~~~~~~~~~~~~~|\n";
					            cout<<setw(50)<<"                                |         2  .  WHITE KARAHI (F/H)     |   FULL 1300 |\n";
					            cout<<setw(50)<<"                                |                                      |   HALF 650  |\n";
					            cout<<setw(50)<<"                                |                                      |~~~~~~~~~~~~~|\n";
					            cout<<setw(50)<<"                                |         3  .  BBQ KARAHI (F/H)       |   FULL 1300 |\n";
					            cout<<setw(50)<<"                                |                                      |   HALF 650  |\n";
					            cout<<setw(50)<<"                                |                                      |~~~~~~~~~~~~~|\n";
					            cout<<setw(50)<<"                                |         4  .  BEEF ROAST (F/H)       |   FULL 1300 |\n";
					            cout<<setw(50)<<"                                |                                      |   HALF 650  |\n";
					            cout<<setw(50)<<"                                ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~|\n";
					            cout<<setw(50)<<"                                |                        5 . EXIT                    |\n";
					            cout<<setw(50)<<"                                ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~|\n";
					            cout<<setw(40)<<"                                Choice : ";
					            cin>>choice1;
					            switch(choice1)
								{
									case 1:
										quantity=0;
										cout<<"                                SIMPLE KARAHI (F/H)\n";
										cout<<"                                FULL/HALF(F/H) : ";
										cin>>s;
										cout<<"                                QUANTITY \n";
										cin>> quantity;
										F.BEEF(choice1,s,quantity);
										system("cls");
										cout<<"                                        "<<quantity<<" "<<s<<" SIMPLE KARAHI DONE \n"; 
										break;
									case 2:
										quantity=0;
										cout<<"                                WHITE KARAHI (F/H)\n";
										cout<<"                                FULL/HALF(F/H) : ";
										cin>>s;
										cout<<"                                QUANTITY \n";
										cin>> quantity;
										F.BEEF(choice1,s,quantity);
										system("cls");
										cout<<"                                        "<<quantity<<" "<<s<<" WHITE KARAHI DONE \n";
										break;
									case 3:
										quantity=0;
										cout<<"                                BBQ KARAHI (F/H)\n";
										cout<<"                                FULL/HALF(F/H) : ";
										cin>>s;
										cout<<"                                QUANTITY \n";
										cin>> quantity;
										F.BEEF(choice1,s,quantity);
										system("cls");
										cout<<"                                        "<<quantity<<" "<<s<<" BBQ KARAHI DONE \n";
										break;
									case 4:
										quantity=0;
										cout<<"                                BEEF ROAST (F/H)\n";
										cout<<"                                FULL/HALF(F/H) : ";
										cin>>s;
										cout<<"                                QUANTITY \n";
										cin>> quantity;
										F.BEEF(choice1,s,quantity);
										system("cls");
										cout<<"                                        "<<quantity<<" "<<s<<" BEEF ROAST DONE \n";
										break;
									case 5:
										system("cls");
										cout<<setw(50)<<"\n                       #######################################              EXIT BEEF MENU              ##################################### \n ";
										break;
									default:
										system("cls");
										cout<<setw(50)<<"\n                                ########       WRONG INPUT      ########\n";
										
								}
							    }while(choice1 != 5);
							    break;
						case 4:
								system("cls");
								do{
					            cout<<"\n\n\n";
						        cout<<setw(50)<<"                                ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n";
					            cout<<setw(50)<<"                                |                  SABZI               |     SIZE     |\n";
					            cout<<setw(50)<<"                                ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n";
					            cout<<setw(50)<<"                                |         1  .  GOBY (S/D)             | SINGLE 150   |\n";
					            cout<<setw(50)<<"                                |                                      | DOUBLE 300   |\n";
					            cout<<setw(50)<<"                                |                                      |~~~~~~~~~~~~~~|\n";
					            cout<<setw(50)<<"                                |         2  .  PALAK (S/D)            | SINGLE 200   |\n";
					            cout<<setw(50)<<"                                |                                      | DOUBLE 350   |\n";
					            cout<<setw(50)<<"                                |                                      |~~~~~~~~~~~~~~|\n";
					            cout<<setw(50)<<"                                |         3  .  ALLU MATAR (S/D)       | SINGLE 170   |\n";
					            cout<<setw(50)<<"                                |                                      | DOUBLE 280   |\n";
					            cout<<setw(50)<<"                                |                                      |~~~~~~~~~~~~~~|\n";
					            cout<<setw(50)<<"                                |         4  .  MIX SABZI (S/D)        | SINGLE 250   |\n";
					            cout<<setw(50)<<"                                |                                      | DOUBLE 400   |\n";
					            cout<<setw(50)<<"                                ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~|\n";
					            cout<<setw(50)<<"                                |                         5 . EXIT                    |\n";
					            cout<<setw(50)<<"                                ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n";
					            cout<<setw(40)<<"                                Choice : ";
					            cin>>choice1;
					            switch(choice1)
								{
									case 1:
										quantity=0;
										cout<<"                                GOBY (S/D)\n";
										cout<<"                                Single/Double(S/D) : ";
                                        cin>>s;
										cout<<"                                QUANTITY \n";
										cin>> quantity;
										F.SABZI(choice1,s,quantity);
										system("cls");
										cout<<"                                        "<<quantity<<" "<<s<<" GOBY DONE \n"; 
										break;
									case 2:
										quantity=0;
										cout<<"                                PALAK (S/D)\n";
										cout<<"                                Single/Double(S/D) : ";
                                        cin>>s;
										cout<<"                                QUANTITY \n";
										cin>> quantity;
										F.SABZI(choice1,s,quantity);	
										system("cls");
										cout<<"                                        "<<quantity<<" "<<s<<" PALAK DONE \n";
										break;
									case 3:
										quantity=0;
										cout<<"                                ALLU MATAR (S/D)\n";
										cout<<"                                Single/Double(S/D) : ";
										cin>>s;
										cout<<"                                QUANTITY \n";
										cin>> quantity;
										F.SABZI(choice1,s,quantity);
										system("cls");
										cout<<"                                        "<<quantity<<" "<<s<<" ALLU MATAR DONE \n";
										break;
									case 4:
										quantity=0;
										cout<<"                                MIX (S/D)\n";
										cout<<"                                Single/Double(S/D) : ";
										cin>>s;
										cout<<"                                QUANTITY \n";
										cin>> quantity;
										F.SABZI(choice1,s,quantity);
										system("cls");
										cout<<"                                        "<<quantity<<" "<<s<<" MIX SABBZI DONE \n";
										break;
									case 5:
										system("cls");
										cout<<setw(50)<<"\n                       #########################################               EXIT SABBZI MENU              ####################################### \n ";
										break;
									default:
										system("cls");
										cout<<setw(50)<<"\n                                ########       WRONG INPUT      ########\n";		
								}
							    }while(choice1 != 5);
							    break;
						case 5:
								system("cls");
								do{
					            cout<<"\n\n\n";
						        cout<<setw(50)<<"                                ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n";
					            cout<<setw(50)<<"                                |                  FISH                |      SIZE     |\n";
					            cout<<setw(50)<<"                                ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n";
					            cout<<setw(50)<<"                                |         1  .  FISH KARAHI (F/H)      |  FULL 1700    |\n";
					            cout<<setw(50)<<"                                |                                      |  HALF 800     |\n";
					            cout<<setw(50)<<"                                |                                      |~~~~~~~~~~~~~~~|\n";
					            cout<<setw(50)<<"                                |         2  .  RAU FRY(F/H)           |  FULL 1700    |\n";
					            cout<<setw(50)<<"                                |                                      |  HALF 800     |\n";
					            cout<<setw(50)<<"                                |                                      |~~~~~~~~~~~~~~~|\n";
					            cout<<setw(50)<<"                                |         3  .  TUNA FRY (F/H)         |  FULL 1700    |\n";
					            cout<<setw(50)<<"                                |                                      |  HALF 800     |\n";
					            cout<<setw(50)<<"                                |                                      |~~~~~~~~~~~~~~~|\n";
					            cout<<setw(50)<<"                                |         4  .  MAHI FRY (F/H)         |  FULL 1700    |\n";
					            cout<<setw(50)<<"                                |                                      |  HALF 800     |\n";
					            cout<<setw(50)<<"                                |                                      |~~~~~~~~~~~~~~~|\n";
					            cout<<setw(50)<<"                                |         5  .  FINGER FISH (F/H)      |  FULL 1700    |\n";
					            cout<<setw(50)<<"                                |                                      |  HALF 800     |\n";
					            cout<<setw(50)<<"                                ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~|\n";
					            cout<<setw(50)<<"                                |                          6 . EXIT                    |\n";
					            cout<<setw(50)<<"                                ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~|\n";
					            cout<<setw(40)<<"                                Choice : ";
					            cin>>choice1;
					            switch(choice1)
								{
									case 1:
										quantity=0;
										cout<<"                                FISH KARAHI (F/H)\n";
										cout<<"                                FULL/HALF(F/H) : ";
										cin>>s;
										cout<<"                                QUANTITY \n";
										cin>> quantity;
										F.Fish(choice1,s,quantity);
										system("cls");
										cout<<"                                        "<<quantity<<" "<<s<<" FISH KARAHI DONE \n"; 
										break;
									case 2:
										quantity=0;
										cout<<"                                RAU FRY (F/H)\n";
										cout<<"                                FULL/HALF(F/H) : ";
										cin>>s;
										cout<<"                                QUANTITY \n";
										cin>> quantity;
									    F.Fish(choice1,s,quantity);
										system("cls");
										cout<<"                                        "<<quantity<<" "<<s<<" RAU FRY DONE \n";
										break;
									case 3:
										quantity=0;
										cout<<"                                TUNA FRY (F/H)\n";
										cout<<"                                FULL/HALF(F/H) : ";
										cin>>s;
										cout<<"                                QUANTITY \n";
										cin>> quantity;
										F.Fish(choice1,s,quantity);
										system("cls");
										cout<<"                                        "<<quantity<<" "<<s<<" TUNA FRY DONE \n";
										break;
									case 4:
										quantity=0;
										cout<<"                                MAHI FRY (F/H)\n";
										cout<<"                                FULL/HALF(F/H) : ";
										cin>>s;
										cout<<"                                QUANTITY \n";
										cin>> quantity;
										F.Fish(choice1,s,quantity);
										system("cls");
										cout<<"                                        "<<quantity<<" "<<s<<" MAHI FRY DONE \n";
										break;
									case 5:
										quantity=0;
										cout<<"                                FINGER FISH\n";
										cout<<"                                Amount : ";
										cin>>s;
										cout<<"                                QUANTITY \n";
										cin>> quantity;
										F.Fish(choice1,s,quantity);
										system("cls");
										cout<<"                                        "<<quantity<<" "<<s<<" FINGER FISH DONE \n";
										break;
									case 6:
										system("cls");
										cout<<setw(50)<<"\n                       ##########################################               EXIT FISH MENU             ######################################## \n ";
										break;
									default:
										system("cls");
										cout<<setw(50)<<"\n                                ########       WRONG INPUT      ########\n";
										
								}
							    }while(choice1 != 6);
							    break;
						case 6:
								system("cls");
								do{
					            cout<<"\n\n\n";
						        cout<<setw(50)<<"                                ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n";
					            cout<<setw(50)<<"                                |                  DAAL                |     SIZE     |\n";
					            cout<<setw(50)<<"                                ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~|\n";
					            cout<<setw(50)<<"                                |         1  .  DAAL MASH (S/D)        |   SINGLE 150 |\n";
					            cout<<setw(50)<<"                                |                                      |   DOUBLE 300 |\n";
					            cout<<setw(50)<<"                                |                                      |~~~~~~~~~~~~~~|\n";
					            cout<<setw(50)<<"                                |         2  .  DAAL MONG (S/D)        |   SINGLE 150 |\n";
					            cout<<setw(50)<<"                                |                                      |   DOUBLE 300 |\n";
					            cout<<setw(50)<<"                                |                                      |~~~~~~~~~~~~~~|\n";
					            cout<<setw(50)<<"                                |         3  .  DAAL MASAR (S/D)       |   SINGLE 150 |\n";
					            cout<<setw(50)<<"                                |                                      |   DOUBLE 300 |\n";
					            cout<<setw(50)<<"                                |                                      |~~~~~~~~~~~~~~|\n";
					            cout<<setw(50)<<"                                |         4  .  MIX DAAL (S/D)         |   SINGLE 150 |\n";
					            cout<<setw(50)<<"                                |                                      |   DOUBLE 300 |\n";
					            cout<<setw(50)<<"                                ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~|\n";
					            cout<<setw(50)<<"                                |                            5 . EXIT                 |\n";
					            cout<<setw(50)<<"                                ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ \n";
					            cout<<setw(40)<<"                                Choice : ";
					            cin>>choice1;
					            switch(choice1)
								{
									case 1:
										quantity=0;
										cout<<"                                DAAL MASH (S/D)\n";
										cout<<"                                Single/Double(S/D) : ";
										cin>>s;
										cout<<"                                QUANTITY \n";
										cin>> quantity;
										F.DAAL(choice1,s,quantity);
										system("cls");
										cout<<"                                        "<<quantity<<" "<<s<<" DAAL MASH DONE \n"; 
										break;
									case 2:
										quantity=0;
										cout<<"                                DAAL MONG (S/D)\n";
										cout<<"                                Single/Double(S/D) : ";
										cin>>s;
										cout<<"                                QUANTITY \n";
										cin>> quantity;
										F.DAAL(choice1,s,quantity);
										system("cls");
										cout<<"                                        "<<quantity<<" "<<s<<" DAAL MONG DONE \n";
										break;
									case 3:
										quantity=0;
										cout<<"                                DAAL MASAR (S/D)\n";
										cout<<"                                Single/Double(S/D) : ";
									    cin>>s;
										cout<<"                                QUANTITY \n";
										cin>> quantity;
										F.DAAL(choice1,s,quantity);
										system("cls");
										cout<<"                                        "<<quantity<<" "<<s<<" DAAL MASAR DONE \n";
										break;
									case 4:
									    quantity=0;
										cout<<"                                MIX DAAL (S/D)\n";
										cout<<"                                Single/Double(S/D) : ";
										cin>>s;
										cout<<"                                QUANTITY \n";
										cin>> quantity;
										F.DAAL(choice1,s,quantity);
										system("cls");
										cout<<"                                        "<<quantity<<" "<<s<<" MIX DAAL DONE \n";
										break;
									case 5:									
										system("cls");
										cout<<setw(50)<<"\n                       ##########################################               EXIT DAAL MENU              ######################################## \n ";
										break;
									default:
										system("cls");
										cout<<setw(50)<<"\n                                ########       WRONG INPUT      ########\n";		
								}
							    }while(choice1 != 5);
							    break;
						case 7:
								system("cls");
								do{
					            cout<<"\n\n\n";
						        cout<<setw(50)<<"                                ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n";
					            cout<<setw(50)<<"                                |                  BIRYANI             |     SIZE      |\n";
					            cout<<setw(50)<<"                                ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~|\n";
					            cout<<setw(50)<<"                                |         1  .  SIMPLE BIRYANI (S/D)   |  SINGLE 100   |\n";
					            cout<<setw(50)<<"                                |                                      |  DOUBLE 150   |\n";
					            cout<<setw(50)<<"                                |                                      |~~~~~~~~~~~~~~~|\n";
					            cout<<setw(50)<<"                                |         2  .  CHICKEN BIRYANI (S/D)  |  SINGLE 150   |\n";
					            cout<<setw(50)<<"                                |                                      |  DOUBLE 250   |\n";
					            cout<<setw(50)<<"                                ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n";
					            cout<<setw(50)<<"                                |                          3 . EXIT                    |\n";
					            cout<<setw(50)<<"                                ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n";
					            cout<<setw(40)<<"                                Choice : ";
					            cin>>choice1;
					            switch(choice1)
								{
									case 1:
										quantity=0;
										cout<<"                                SIMPLE BIRYANI (S/D)\n";
										cout<<"                                Single/Double(S/D) : ";
										cin>>s;
										cout<<"                                QUANTITY \n";
										cin>> quantity;
										F.BIRYANI(choice1,s,quantity);
										system("cls");
										cout<<"                                        "<<quantity<<" "<<s<<" SIMPLE BIRYANI DONE \n"; 
										break;
									case 2:
										quantity=0;
										cout<<"                                CHICKEN BIRYANI (S/D)\n";
										cout<<"                                Single/Double(S/D) : ";
										cin>>s;
										cout<<"                                QUANTITY \n";
										cin>> quantity;
										F.BIRYANI(choice1,s,quantity);
										system("cls");
										cout<<"                                        "<<quantity<<" "<<s<<" CHICKEN BIRYANI DONE \n";
										break;
									case 3:
										system("cls");
										cout<<setw(50)<<"\n                       ########################################               EXIT BIRYANI MENU              ###################################### \n ";
										break;
									default:
										system("cls");
										cout<<setw(50)<<"\n                                ########       WRONG INPUT      ########\n";		
								}
							    }while(choice1 != 3);
							    break;
						case 8:
								system("cls");
								do{
					            cout<<"\n\n\n";
						        cout<<setw(50)<<"                                ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n";
					            cout<<setw(50)<<"                                |                  PULAO               |      SIZE     |\n";
					            cout<<setw(50)<<"                                ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n";
					            cout<<setw(50)<<"                                |         1  .  BEEF PULAO (S/D)       |  SINGLE 300   |\n";
					            cout<<setw(50)<<"                                |                                      |  DOUBLE 500   |\n";
					            cout<<setw(50)<<"                                |                                      |~~~~~~~~~~~~~~~|\n";
					            cout<<setw(50)<<"                                |         2  .  CHICKEN PULAO (S/D)    |  SINGLE 350   |\n";
					            cout<<setw(50)<<"                                |                                      |  DOUBLE 550   |\n";
					            cout<<setw(50)<<"                                ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n";
					            cout<<setw(50)<<"                                |               3 . EXIT               |               |\n";
					            cout<<setw(50)<<"                                ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n";
					            cout<<setw(40)<<"                                Choice : ";
					            cin>>choice1;
					            switch(choice1)
								{
									case 1:
										quantity=0;
										cout<<"                                BEEF PULAO (S/D)\n";
										cout<<"                                Single/Double(S/D) : ";
										cin>>s;
										cout<<"                                QUANTITY \n";
										cin>> quantity;
										F.PULAO(choice1,s,quantity);
										system("cls");
										cout<<"                                        "<<quantity<<" "<<s<<" BEEF PULAO DONE \n"; 
										break;
									case 2:
										quantity=0;
										cout<<"                                CHICKEN PULAO (S/D)\n";
										cout<<"                                Single/Double(S/D) : ";
										cin>>s;
										cout<<"                                QUANTITY \n";
										cin>> quantity;
										F.PULAO(choice1,s,quantity);
										system("cls");
										cout<<"                                        "<<quantity<<" "<<s<<" CHICKEN PULAO DONE \n";
										break;
									case 3:
										system("cls");
										cout<<setw(50)<<"\n                       #########################################               EXIT PULAO MENU               ####################################### \n ";
										break;
									default:
										system("cls");
										cout<<setw(50)<<"\n                                ########       WRONG INPUT      ########\n";		
								}
							    }while(choice1 != 3);
							    break;
						case 9:
								system("cls");
								do{
					            cout<<"\n\n\n";
						        cout<<setw(50)<<"                                ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~             \n";
					            cout<<setw(50)<<"                                |               ROTI/PRATHA            |             \n";
					            cout<<setw(50)<<"                                ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~             \n";
					            cout<<setw(50)<<"                                |         1  .  SADA ROTI              |             \n";
					            cout<<setw(50)<<"                                |                                      |             \n";
					            cout<<setw(50)<<"                                |                                      |             \n";
					            cout<<setw(50)<<"                                |         2  .  DESI PRATHA            |             \n";
					            cout<<setw(50)<<"                                |                                      |             \n";
					            cout<<setw(50)<<"                                |                                      |             \n";
					            cout<<setw(50)<<"                                |         3  .  ROGNI NAAN             |             \n";
					            cout<<setw(50)<<"                                |                                      |             \n";
					            cout<<setw(50)<<"                                |                                      |             \n";
					            cout<<setw(50)<<"                                |         4  .  SADA NAAN              |             \n";
					            cout<<setw(50)<<"                                |                                      |             \n";
					            cout<<setw(50)<<"                                |                                      |             \n";
					            cout<<setw(50)<<"                                |         5  .  GARLIC NAAN            |             \n";
					            cout<<setw(50)<<"                                |                                      |             \n";
					            cout<<setw(50)<<"                                ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~             \n";
					            cout<<setw(50)<<"                                |               6 . EXIT               |             \n";
					            cout<<setw(50)<<"                                ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~             \n";
					            cout<<setw(40)<<"                                Choice : ";
					            cin>>choice1;
					            switch(choice1)
								{
									case 1:
										cout<<"                                SADA ROTI\n";
										cout<<"                                Amount : ";
										cin>>s;
										F.ROTI(choice1,s);
										system("cls");
										cout<<"                                        "<<s<<" SADA ROTI DONE \n"; 
										break;
									case 2:
										cout<<"                                DESI PRATHA\n";
										cout<<"                                Amount : ";
										cin>>s;
										F.ROTI(choice1,s);
										system("cls");
										cout<<"                                        "<<s<<" DESI PRATHA DONE \n";
										break;
									case 3:
										cout<<"                                ROGHNI NAAN\n";
										cout<<"                                Amount : ";
										cin>>s;
										F.ROTI(choice1,s);
										system("cls");
										cout<<"                                        "<<s<<" ROGHNI NAAN DONE \n";
										break;
									case 4:
										cout<<"                                SADA NAAN\n";
										cout<<"                                Amount : ";
										cin>>s;
										F.ROTI(choice1,s);
										system("cls");
										cout<<"                                        "<<s<<" SADA NAAN DONE \n";
										break;
									case 5:
										cout<<"                                GARLIC NAAN\n";
										cout<<"                                Amount : ";
										cin>>s;
										F.ROTI(choice1,s);
										system("cls");
										cout<<"                                        "<<s<<" GARLIC NAAN DONE \n";
										break;
									case 6:
										cout<<setw(50)<<"\n                       ######################################               EXIT ROTI/PRATHA MENU            ###################################### \n ";
										break;
									default:
										system("cls");
										cout<<setw(50)<<"\n                                ########       WRONG INPUT      ########\n";	
								}
							    }while(choice1 != 6);
							    break;
						case 10:
								system("cls");
								do{
					            cout<<"\n\n\n";
						        cout<<setw(50)<<"                                ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~             \n";
					            cout<<setw(50)<<"                                |              RAITA/SALAD             |             \n";
					            cout<<setw(50)<<"                                ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~             \n";
					            cout<<setw(50)<<"                                |         1  .  RAITA                  |             \n";
					            cout<<setw(50)<<"                                |                                      |             \n";
					            cout<<setw(50)<<"                                |                                      |             \n";
					            cout<<setw(50)<<"                                |         2  .  CHUTNEY                |             \n";
					            cout<<setw(50)<<"                                |                                      |             \n";
					            cout<<setw(50)<<"                                |                                      |             \n";
					            cout<<setw(50)<<"                                |         3  .  DHAI                   |             \n";
					            cout<<setw(50)<<"                                |                                      |             \n";
					            cout<<setw(50)<<"                                |                                      |             \n";
					            cout<<setw(50)<<"                                |         4  .  SALAD                  |             \n";
					            cout<<setw(50)<<"                                |                                      |             \n";
					            cout<<setw(50)<<"                                ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~             \n";
					            cout<<setw(50)<<"                                |               6 . EXIT               |             \n";
					            cout<<setw(50)<<"                                ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~             \n";
					            cout<<setw(40)<<"                                Choice : ";
					            cin>>choice1;
					            switch(choice1)
								{
									case 1:
										cout<<"                                RAITA\n";
										cout<<"                                Amount : ";
										cin>>s;
										F.RAITA_SALAD(choice1,s);
										system("cls");
										cout<<"                                        "<<s<<" RAITA DONE \n"; 
										break;
									case 2:
										cout<<"                                CHUTNEY\n";
										cout<<"                                Amount : ";
										cin>>s;
										F.RAITA_SALAD(choice1,s);
										system("cls");
										cout<<"                                        "<<s<<" CHUTNEY DONE \n";
										break;
									case 3:
										cout<<"                                DHAI\n";
										cout<<"                                Amount : ";
										cin>>s;
										F.RAITA_SALAD(choice1,s);
										system("cls");
										cout<<"                                        "<<s<<" DHAI DONE \n";
										break;
									case 4:
										cout<<"                                SALAD\n";
										cout<<"                                Amount : ";
										cin>>s;
										F.RAITA_SALAD(choice1,s);
										system("cls");
										cout<<"                                        "<<s<<" SALAD DONE \n";
										break;
									case 5:
										cout<<setw(50)<<"\n                       #####################################               EXIT RAITA/SALAD MENU             ###################################### \n ";
										break;
									default:
										system("cls");
										cout<<setw(50)<<"\n                                ########       WRONG INPUT      ########\n";		
								}
							    }while(choice1 != 5);
							    break;
						case 11:
							system("cls");
							cout<<setw(50)<<"\n                                ###################              EXIT DESI FOOD              ###################### \n ";
							break;
						default:
							system("cls");
							cout<<setw(50)<<"\n                       #######################################                WRONG INPUT               ####################################### \n ";
						}
					    }while(choice!=11);						
					}
					else if (choice==3)
					{
						system("cls");
						do{
					    cout<<"\n\n\n";
						cout<<setw(50)<<"                       ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~  \n";
					    cout<<setw(50)<<"                       |                                                   SWEETS & DISERT                                                    |  \n";
					    cout<<setw(50)<<"                       ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~  \n";
					    cout<<setw(50)<<"                       |                     1  .  KHEER                          |                     6  .  ICE-CREAM                       |  \n";
					    cout<<setw(50)<<"                       |                                                          |                                                           |  \n";
					    cout<<setw(50)<<"                       |                                                          |                                                           |  \n";
					    cout<<setw(50)<<"                       |                     2  .  CUSTARD                        |                     7  .  CAKE                            |  \n";
					    cout<<setw(50)<<"                       |                                                          |                                                           |  \n";
					    cout<<setw(50)<<"                       |                                                          |                                                           |  \n";
					    cout<<setw(50)<<"                       |                     3  .  JELLY                          |                     8  .  CHAT                            |  \n";
					    cout<<setw(50)<<"                       |                                                          |                                                           |  \n";
					    cout<<setw(50)<<"                       |                                                          |                                                           |  \n";
					    cout<<setw(50)<<"                       |                     4  .  RASMALAI                       |                     9  .  MATHI                           |  \n";
					    cout<<setw(50)<<"                       |                                                          |                                                           |  \n";
					    cout<<setw(50)<<"                       |                                                          |                                                           |  \n";
					    cout<<setw(50)<<"                       |                     5  .  HALWA                          |                    10  .  FALOODA                         |  \n";
					    cout<<setw(50)<<"                       |                                                          |                                                           |  \n";
					    cout<<setw(50)<<"                       |                                                          |                                                           |  \n";
					    cout<<setw(50)<<"                       ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~  \n";
					    cout<<setw(50)<<"                       |                                                      11 . EXIT                                                       |  \n";
					    cout<<setw(50)<<"                       ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~  \n";
					    cout<<setw(40)<<"                       Choice : ";
					    cin>>choice;
					    switch(choice)
						{	
						case 1:
								system("cls");
								do{
					            cout<<"\n\n\n";
						        cout<<setw(50)<<"                                ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n";
					            cout<<setw(50)<<"                                |                  KHEER               |    SIZE     |\n";
					            cout<<setw(50)<<"                                |~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~|\n";
					            cout<<setw(50)<<"                                |        1  .  KHEER (S/D)             | SINGLE 100  |\n";
					            cout<<setw(50)<<"                                |                                      | DOUBLE 200  |\n";
					            cout<<setw(50)<<"                                |                                      |~~~~~~~~~~~~~|\n";
					            cout<<setw(50)<<"                                |        2  .  SPECIAL MALAI KHEER(S/D)| SINGLE 150  |\n";
					            cout<<setw(50)<<"                                |                                      | DOUBLE 230  |\n";
					            cout<<setw(50)<<"                                |~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~|\n";
					            cout<<setw(50)<<"                                |                           3 . EXIT                 |\n";
					            cout<<setw(50)<<"                                ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n";
					            cout<<setw(40)<<"                                Choice : ";
					            cin>>choice1;
					            switch(choice1)
								{
									case 1:
										quantity=0;
										cout<<"                                KHEER (S/D)\n";
										cout<<"                                Single/Double(S/D) : ";
										cin>>s;
										cout<<"                                QUANTITY \n";
										cin>> quantity;
										F.KHEER(choice1,s,quantity);
										system("cls");
										cout<<"                                        "<<quantity<<" "<<s<<" KHEER DONE \n"; 
										break;
									case 2:
										quantity=0;
										cout<<"                                SPICAL MALI KHEER (S/D)\n";
										cout<<"                                Single/Double(S/D) : ";
										cin>>s;
										cout<<"                                QUANTITY \n";
										cin>> quantity;
										F.KHEER(choice1,s,quantity);
										system("cls");
										cout<<"                                        "<<quantity<<" "<<s<<" SPICAL MALI KHEER DONE \n";
										break;
									case 3:
										system("cls");
										cout<<setw(50)<<"\n                       #########################################               EXIT KHEER               ####################################### \n ";
										break;
									default:
										system("cls");
										cout<<setw(50)<<"\n                                ########       WRONG INPUT      ########\n";		
								}
							    }while(choice1 != 3);
							    break;
						case 2:
								system("cls");
								do{
					            cout<<"\n\n\n";
						        cout<<setw(50)<<"                                ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n";
					            cout<<setw(50)<<"                                |                  CUSTARD             |    SIZE     |\n";
					            cout<<setw(50)<<"                                |~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~|\n";
					            cout<<setw(50)<<"                                |         1  .  MANGO CUSTARD (S/D)    |  SINGLE 170 |\n";
					            cout<<setw(50)<<"                                |                                      |  DOUBLE 230 |\n";
					            cout<<setw(50)<<"                                |                                      |~~~~~~~~~~~~~|\n";
					            cout<<setw(50)<<"                                |         2  .  BANANA CUSTARD(S/D)    |  SINGLE 170 |\n";
					            cout<<setw(50)<<"                                |                                      |  DOUBLE 230 |\n";
					            cout<<setw(50)<<"                                |                                      |~~~~~~~~~~~~~|\n";
					            cout<<setw(50)<<"                                |         3  .  STRAWBERRY CUSTARD(S/D)|  SINGLE 170 |\n";
					            cout<<setw(50)<<"                                |                                      |  DOUBLE 230 |\n";
					            cout<<setw(50)<<"                                |~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~|\n";
					            cout<<setw(50)<<"                                |                          4 . EXIT                  |\n";
					            cout<<setw(50)<<"                                ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n";
					            cout<<setw(40)<<"                                Choice : ";
					            cin>>choice1;
					            switch(choice1)
								{
									case 1:
										quantity=0;
										cout<<"                                MANGO CUSTARD (S/D)\n";
										cout<<"                                Single/Double(S/D) : ";
										cin>>s;
										cout<<"                                QUANTITY \n";
										cin>> quantity;
										F.CUSTARD(choice1,s,quantity);
										system("cls");
										cout<<"                                        "<<quantity<<" "<<s<<" MANGO CUSTARD DONE \n"; 
										break;
									case 2:
										quantity=0;
										cout<<"                                BANANA CUSTARD (S/D)\n";
										cout<<"                                Single/Double(S/D) : ";
										cin>>s;
										cout<<"                                QUANTITY \n";
										cin>> quantity;
										F.CUSTARD(choice1,s,quantity);
										system("cls");
										cout<<"                                        "<<quantity<<" "<<s<<" BANANA CUSTARD DONE \n";
										break;
									case 3:
										quantity=0;
										cout<<"                                STRAWBERRY CUSTARD(S/D)\n";
										cout<<"                                Single/Double(S/D) : ";
										cin>>s;
										cout<<"                                QUANTITY \n";
										cin>> quantity;
										F.CUSTARD(choice1,s,quantity);
										system("cls");
										cout<<"                                        "<<quantity<<" "<<s<<" STRAWBERRY CUSTARD DONE \n";
										break;
									case 4:
										system("cls");
										cout<<setw(50)<<"\n                       ########################################               EXIT CUSTARD               ###################################### \n ";
										break;
									default:
										system("cls");
										cout<<setw(50)<<"\n                                ########       WRONG INPUT      ########\n";		
								}
							    }while(choice1 != 4);
							    break;
						case 3:
								system("cls");
								do{
					            cout<<"\n\n\n";
						        cout<<setw(50)<<"                                ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n";
					            cout<<setw(50)<<"                                |                 JELLY                |    SIZE     |\n";
					            cout<<setw(50)<<"                                ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n";
					            cout<<setw(50)<<"                                |         1  .  MANGO JELLY (S/D)      |  SINGLE 120 |\n";
					            cout<<setw(50)<<"                                |                                      |  DOUBLE 180 |\n";
					            cout<<setw(50)<<"                                |                                      |~~~~~~~~~~~~~|\n";
					            cout<<setw(50)<<"                                |         2  .  BANANA JELLY(S/D)      |  SINGLE 120 |\n";
					            cout<<setw(50)<<"                                |                                      |  DOUBLE 180 |\n";
					            cout<<setw(50)<<"                                |                                      |~~~~~~~~~~~~~|\n";
					            cout<<setw(50)<<"                                |         3  .  STRAWBERRY JELLY(S/D)  |  SINGLE 120 |\n";
					            cout<<setw(50)<<"                                |                                      |  DOUBLE 180 |\n";
					            cout<<setw(50)<<"                                ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~|\n";
					            cout<<setw(50)<<"                                |               4 . EXIT                             | \n";
					            cout<<setw(50)<<"                                ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n";
					            cout<<setw(40)<<"                                Choice : ";
					            cin>>choice1;
					            switch(choice1)
								{
									case 1:
										quantity=0;
										cout<<"                                MANGO JELLY (S/D)\n";
										cout<<"                                Single/Double(S/D) : ";
										cin>>s;
										cout<<"                                QUANTITY \n";
										cin>> quantity;
										F.JELLY(choice1,s,quantity);
										system("cls");
										cout<<"                                        "<<quantity<<" "<<s<<" MANGO JELLY DONE \n"; 
										break;
									case 2:
										quantity=0;
										cout<<"                                BANANA JELLY (S/D)\n";
										cout<<"                                Single/Double(S/D) : ";
										cin>>s;
										cout<<"                                QUANTITY \n";
										cin>> quantity;
										F.JELLY(choice1,s,quantity);
										system("cls");
										cout<<"                                        "<<quantity<<" "<<s<<" BANANA JELLY DONE \n";
										break;
									case 3:
										quantity=0;
										cout<<"                                STRAWBERRY JELLY(S/D)\n";
										cout<<"                                Single/Double(S/D) : ";
										cin>>s;
										cout<<"                                QUANTITY \n";
										cin>> quantity;
										F.JELLY(choice1,s,quantity);
										system("cls");
										cout<<"                                        "<<quantity<<" "<<s<<" STRAWBERRY CUSTARD DONE \n";
										break;
									case 4:
										system("cls");
										cout<<setw(50)<<"\n                       #######################################               EXIT JELLY               ##################################### \n ";
										break;
									default:
										system("cls");
										cout<<setw(50)<<"\n                                ########       WRONG INPUT      ########\n";		
								}
							    }while(choice1 != 4);
							    break;
						case 4:
								system("cls");
								do{
					            cout<<"\n\n\n";
						        cout<<setw(50)<<"                                ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n";
					            cout<<setw(50)<<"                                |                  RASMALAI            |    SIZE     |\n";
					            cout<<setw(50)<<"                                |~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~|\n";
					            cout<<setw(50)<<"                                |         1  .  RASMALAI (S/D)         | SINGLE 200  |\n";
					            cout<<setw(50)<<"                                |                                      | DOUBLE 300  |\n";
					            cout<<setw(50)<<"                                |                                      |~~~~~~~~~~~~~|\n";
					            cout<<setw(50)<<"                                |         2  .  PISTA RASMALAI(S/D)    | SINGLE 250  |\n";
					            cout<<setw(50)<<"                                |                                      | DOUBLE 400  |\n";
					            cout<<setw(50)<<"                                |~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~|\n";
					            cout<<setw(50)<<"                                |                          3 . EXIT                  |\n";
					            cout<<setw(50)<<"                                ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n";
					            cout<<setw(40)<<"                                Choice : ";
					            cin>>choice1;
					            switch(choice1)
								{
									case 1:
										quantity=0;
										cout<<"                                RASMALAI (S/D)\n";
										cout<<"                                Single/Double(S/D) : ";
										cin>>s;
										cout<<"                                QUANTITY \n";
										cin>> quantity;
										F.RASMALAI(choice1,s,quantity);
										system("cls");
										cout<<"                                        "<<quantity<<" "<<s<<" RASMALAI DONE \n"; 
										break;
									case 2:
										quantity=0;
										cout<<"                                PISTA RASMALAI (S/D)\n";
										cout<<"                                Single/Double(S/D) : ";
										cin>>s;
										cout<<"                                QUANTITY \n";
										cin>> quantity;
										F.RASMALAI(choice1,s,quantity);
										system("cls");
										cout<<"                                        "<<quantity<<" "<<s<<" PISTA RASMALAI DONE \n";
										break;
									case 3:
										system("cls");
										cout<<setw(50)<<"\n                       #######################################               EXIT RASMALAI               ###################################### \n ";
										break;
									default:
										system("cls");
										cout<<setw(50)<<"\n                                ########       WRONG INPUT      ########\n";		
								}
							    }while(choice1 != 3);
							    break;
						case 5:
								system("cls");
								do{
					            cout<<"\n\n\n";
						        cout<<setw(50)<<"                                ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n";
					            cout<<setw(50)<<"                                |                 HALWA                |    SIZE     |\n";
					            cout<<setw(50)<<"                                |~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~|\n";
					            cout<<setw(50)<<"                                |         1  .  GAJAR KA HALWA (H/F)   | HALF 400    |\n";
					            cout<<setw(50)<<"                                |                                      | FULL 700    |\n";
					            cout<<setw(50)<<"                                |                                      |~~~~~~~~~~~~~|\n";
					            cout<<setw(50)<<"                                |         2  .  SUJI KA HALWA(H/F)     | HALF 300    |\n";
					            cout<<setw(50)<<"                                |                                      | FULL 600    |\n";
					            cout<<setw(50)<<"                                |                                      |~~~~~~~~~~~~~|\n";
					            cout<<setw(50)<<"                                |         3  .  ANDA KA HALWA(S/D)     | HALF 450    |\n";
					            cout<<setw(50)<<"                                |                                      | FULL 650    |\n";
					            cout<<setw(50)<<"                                |~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~|\n";
					            cout<<setw(50)<<"                                |                           4 . EXIT                 |\n";
					            cout<<setw(50)<<"                                ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n";
					            cout<<setw(40)<<"                                Choice : ";
					            cin>>choice1;
					            switch(choice1)
								{
									case 1:
										quantity=0;
										cout<<"                                GAJAR KA HALWA (H/F)\n";
										cout<<"                                HALF/FULL(H/F) : ";
										cin>>s;
										cout<<"                                QUANTITY \n";
										cin>> quantity;
										F.HALWA(choice1,s,quantity);
										system("cls");
										cout<<"                                        "<<quantity<<" "<<s<<" GAJAR KA HALWA DONE \n"; 
										break;
									case 2:
										quantity=0;
										cout<<"                                SUJI KA HALWA (H/F)\n";
										cout<<"                                HALF/FULL(H/F) : ";
										cin>>s;
										cout<<"                                QUANTITY \n";
										cin>> quantity;
										F.HALWA(choice1,s,quantity);
										system("cls");
										cout<<"                                        "<<quantity<<" "<<s<<" SUJI KA HALWA DONE \n";
										break;
									case 3:
										quantity=0;
										cout<<"                                ANDA KA HALWA (H/F)\n";
										cout<<"                                HALF/FULL(H/F) : ";
										cin>>s;
										cout<<"                                QUANTITY \n";
										cin>> quantity;
										F.HALWA(choice1,s,quantity);
										system("cls");
										cout<<"                                        "<<quantity<<" "<<s<<" ANDA KA HALWA DONE \n";
										break;
									case 4:
										system("cls");
										cout<<setw(50)<<"\n                       #########################################               EXIT HALWA               ####################################### \n ";
										break;
									default:
										system("cls");
										cout<<setw(50)<<"\n                                ########       WRONG INPUT      ########\n";		
								}
							    }while(choice1 != 4);
							    break;
						case 6:
								system("cls");
								do{
					            cout<<"\n\n\n";
						        cout<<setw(50)<<"                                ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n";
					            cout<<setw(50)<<"                                |                ICE-CREAM               |    SIZE    |\n";
					            cout<<setw(50)<<"                                |~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~|\n";
					            cout<<setw(50)<<"                                |       1  .  MANGO ICE-CREAM (S/D/T)    | SINGLE  80 |\n";
					            cout<<setw(50)<<"                                |                                        | DOUBLE  120|\n";
					            cout<<setw(50)<<"                                |                                        | TRIPPLE 170|\n";
					            cout<<setw(50)<<"                                |                                        |~~~~~~~~~~~~|\n";
					            cout<<setw(50)<<"                                |       2  .  VANAILA ICE-CREAM(S/D/T)   | SINGLE  80 |\n";
					            cout<<setw(50)<<"                                |                                        | DOUBLE  120|\n";
					            cout<<setw(50)<<"                                |                                        | TRIPPLE 170|\n";
					            cout<<setw(50)<<"                                |                                        |~~~~~~~~~~~~|\n";
					            cout<<setw(50)<<"                                |       3  .  STRAWBERRY ICE-CREAM(S/D/T)| SINGLE  80 |\n";
					            cout<<setw(50)<<"                                |                                        | DOUBLE  120|\n";
					            cout<<setw(50)<<"                                |                                        | TRIPPLE 170|\n";
					            cout<<setw(50)<<"                                |                                        |~~~~~~~~~~~~|\n";
					            cout<<setw(50)<<"                                |       4  .  CHOCOLATE ICE-CREAM(S/D/T) | SINGLE  80 |\n";
					            cout<<setw(50)<<"                                |                                        | DOUBLE  120|\n";
					            cout<<setw(50)<<"                                |                                        | TRIPPLE 170|\n";
					            cout<<setw(50)<<"                                |~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~|\n";
					            cout<<setw(50)<<"                                |                          5 . EXIT                   |\n";
					            cout<<setw(50)<<"                                ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n";
					            cout<<setw(40)<<"                                Choice : ";
					            cin>>choice1;
					            switch(choice1)
								{
									case 1:
									    quantity=0;	
										cout<<"                                Single/Double/Tripple(S/D/T) : ";
										cin>>s;
										cout<<"                                QUANTITY \n";
										cin>> quantity;
										F.ICECREAM(choice1,s,quantity);
										system("cls");
										cout<<"                                        "<<quantity<<" "<<s<<" MANGO ICE-CREAM DONE \n"; 
										break;
									case 2:
										quantity=0;
										cout<<"                                VANAILA ICE-CREAM (S/D/T)\n";
										cout<<"                                Single/Double/Tripple(S/D/T) : ";
										cin>>s;
										cout<<"                                QUANTITY \n";
										cin>> quantity;
										F.ICECREAM(choice1,s,quantity);
										system("cls");
										cout<<"                                        "<<quantity<<" "<<s<<" VANAILA ICE-CREAM DONE \n";
										break;
									case 3:
										quantity=0;
										cout<<"                                STRAWBERRY ICE-CREAM(S/D/T)\n";
										cout<<"                                Single/Double/Tripple(S/D/T) : ";
										cin>>s;
										cout<<"                                QUANTITY \n";
										cin>> quantity;
										F.ICECREAM(choice1,s,quantity);
										system("cls");
										cout<<"                                        "<<quantity<<" "<<s<<" STRAWBERRY ICE-CREAM DONE \n";
										break;
									case 4:
										quantity=0;
										cout<<"                                CHOCOLATE ICE-CREAM(S/D/T)\n";
										cout<<"                                Single/Double/Tripple(S/D/T) : ";
										cin>>s;
										cout<<"                                QUANTITY \n";
										cin>> quantity;
										F.ICECREAM(choice1,s,quantity);
										system("cls");
										cout<<"                                        "<<quantity<<" "<<s<<" CHOCOLATE ICE-CREAM DONE \n";
										break;
									case 5:
										system("cls");
										cout<<setw(50)<<"\n                       #######################################               EXIT ICE-CREAM               ##################################### \n ";
										break;
									default:
										system("cls");
										cout<<setw(50)<<"\n                                ########       WRONG INPUT      ########\n";		
								}
							    }while(choice1 != 5);
							    break;
						case 7:
								system("cls");
								do{
					            cout<<"\n\n\n";
						        cout<<setw(50)<<"                                ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~             \n";
					            cout<<setw(50)<<"                                |                  CAKE                |             \n";
					            cout<<setw(50)<<"                                |~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~|             \n";
					            cout<<setw(50)<<"                                |       1  .  NUTELLA (1600)           |             \n";
					            cout<<setw(50)<<"                                |                                      |             \n";
					            cout<<setw(50)<<"                                |                                      |             \n";
					            cout<<setw(50)<<"                                |       2  .  LOTUS   (1700)           |             \n";
					            cout<<setw(50)<<"                                |                                      |             \n";
					            cout<<setw(50)<<"                                |                                      |             \n";
					            cout<<setw(50)<<"                                |       3  .  RED VELVET (1500)        |             \n";
					            cout<<setw(50)<<"                                |                                      |             \n";
					            cout<<setw(50)<<"                                |                                      |             \n";
					            cout<<setw(50)<<"                                |       4  .  RAFFAELLO  (2400)        |             \n";
					            cout<<setw(50)<<"                                |                                      |             \n";
					            cout<<setw(50)<<"                                |~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~|             \n";
					            cout<<setw(50)<<"                                |               5 . EXIT               |             \n";
					            cout<<setw(50)<<"                                ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~             \n";
					            cout<<setw(40)<<"                                Choice : ";
					            cin>>choice1;
					            switch(choice1)
								{
									case 1:
										cout<<"                                NUTELLA \n";
										cout<<"                                Amount : ";
										cin>>quantity;
										F.CAKE(choice1,quantity);
										system("cls");
										cout<<"                                        "<<quantity<<" NUTELLA DONE \n"; 
										break;
									case 2:
										cout<<"                                LOTUS \n";
										cout<<"                                Amount : ";
										cin>>quantity;
										F.CAKE(choice1,quantity);
										system("cls");
										cout<<"                                        "<<quantity<<" LOTUS DONE \n";
										break;
									case 3:
										cout<<"                                RED VELVET\n";
										cout<<"                                Amount : ";
										cin>>quantity;
										F.CAKE(choice1,quantity);
										system("cls");
										cout<<"                                        "<<quantity<<" SRED VELVET DONE \n";
										break;
									case 4:
										cout<<"                                RAFFAELLO\n";
										cout<<"                                Amount : ";
										cin>>quantity;
										F.CAKE(choice1,quantity);
										system("cls");
										cout<<"                                        "<<quantity<<" RAFFAELLO DONE \n";
										break;
									case 5:
										system("cls");
										cout<<setw(50)<<"\n                       #########################################               EXIT CAKE                ####################################### \n ";
										break;
									default:
										system("cls");
										cout<<setw(50)<<"\n                                ########       WRONG INPUT      ########\n";		
								}
							    }while(choice1 != 5);
							    break;
						case 8:
						    	system("cls");
								do{
					            cout<<"\n\n\n";
						        cout<<setw(50)<<"                                ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n";
					            cout<<setw(50)<<"                                |                  CHAT                |   SIZE      |\n";
					            cout<<setw(50)<<"                                |~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~|\n";
					            cout<<setw(50)<<"                                |         1  .  FRUIT CHAT (S/L)       |  SMALL 100  |\n";
					            cout<<setw(50)<<"                                |                                      |  LARGE 170  |\n";
					            cout<<setw(50)<<"                                |                                      |~~~~~~~~~~~~~|\n";
					            cout<<setw(50)<<"                                |         2  .  CREAM CHAT (S/L)       |  SMALL 120  |\n";
					            cout<<setw(50)<<"                                |                                      |  LARGE 200  |\n";
					            cout<<setw(50)<<"                                |                                      |~~~~~~~~~~~~~|\n";
					            cout<<setw(50)<<"                                |         3  .  RUSSIAN SALAD (S/L)    |  SMALL 150  |\n";
					            cout<<setw(50)<<"                                |                                      |  LARGE 220  |\n";
					            cout<<setw(50)<<"                                |~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~|\n";
					            cout<<setw(50)<<"                                |                         4 . EXIT                   |\n";
					            cout<<setw(50)<<"                                ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n";
					            cout<<setw(40)<<"                                Choice : ";
					            cin>>choice1;
					            switch(choice1)
								{
									case 1:
										quantity=0;
										cout<<"                                FRUIT CHAT (S/L) \n";
										cout<<"                                Size : ";
										cin>>s;
										cout<<"                                QUANTITY \n";
										cin>> quantity;
										F.REFREASHMENT(choice1,s,quantity);
										system("cls");
										cout<<"\n                                        "<<quantity<<" "<<s<<" FRUIT CHAT DONE \n";
										break;
									case 2:
										quantity=0;
										cout<<"                                CREAM CHAT (S/L) \n";
										cout<<"                                Size : ";
										cin>>s;
										cout<<"                                QUANTITY \n";
										cin>> quantity;
										F.REFREASHMENT(choice1,s,quantity);
										system("cls");
										cout<<"\n                                        "<<quantity<<" "<<s<<" CREAM CHAT DONE \n";
										break;
									case 3:
										quantity=0;
										cout<<"                                RUSSIAN SALAD (S/L) \n";
										cout<<"                                Size : ";
										cin>>s;
										cout<<"                                QUANTITY \n";
										cin>> quantity;
										F.REFREASHMENT(choice1,s,quantity);
										system("cls");
										cout<<"\n                                        "<<quantity<<" "<<s<<" RUSSIAN SALAD DONE \n";
										break;
									case 4:
										system("cls");
										cout<<setw(50)<<"\n                       #########################################              EXIT CHAT               ######################################### \n ";
										break;
									default:
										system("cls");
										cout<<setw(50)<<"\n                                ########       WRONG INPUT      ########\n";		
								}
							    }while(choice1 != 4);
							    break;
						case 9:
								system("cls");
								do{
					            cout<<"\n\n\n";
						        cout<<setw(50)<<"                                ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~             \n";
					            cout<<setw(50)<<"                                |                  MATHI               |             \n";
					            cout<<setw(50)<<"                                ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~             \n";
					            cout<<setw(50)<<"                                |       1  .  RAS GULA  (600)          |             \n";
					            cout<<setw(50)<<"                                |                                      |             \n";
					            cout<<setw(50)<<"                                |                                      |             \n";
					            cout<<setw(50)<<"                                |       2  .  GULABJAMAN (600)         |             \n";
					            cout<<setw(50)<<"                                |                                      |             \n";
					            cout<<setw(50)<<"                                |                                      |             \n";
					            cout<<setw(50)<<"                                |       3  .  PATISA (900)             |             \n";
					            cout<<setw(50)<<"                                |                                      |             \n";
					            cout<<setw(50)<<"                                |                                      |             \n";
					            cout<<setw(50)<<"                                |       4  .  BARFI  (1200)            |             \n";
					            cout<<setw(50)<<"                                |                                      |             \n";
					            cout<<setw(50)<<"                                ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~             \n";
					            cout<<setw(50)<<"                                |               5 . EXIT               |             \n";
					            cout<<setw(50)<<"                                ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~             \n";
					            cout<<setw(40)<<"                                Choice : ";
					            cin>>choice1;
					            switch(choice1)
								{
									case 1:
										cout<<"                                RAS GULA \n";
										cout<<"                                (1kg/2kg) : ";
										cin>>quantity;
										F.MATHAI(choice1,quantity);
										system("cls");
										cout<<"                                        "<<quantity<<" RAS GULA DONE \n"; 
										break;
									case 2:
										cout<<"                                GULABJAMAN \n";
										cout<<"                                (1kg/2kg) : ";
										cin>>quantity;
										F.MATHAI(choice1,quantity);
										system("cls");
										cout<<"                                        "<<quantity<<" GULABJAMAN DONE \n";
										break;
									case 3:
										cout<<"                                PATISA\n";
										cout<<"                                (1kg/2kg) : ";
										cin>>quantity;
										F.MATHAI(choice1,quantity);
										system("cls");
										cout<<"                                        "<<quantity<<" PATISA DONE \n";
										break;
									case 4:
										cout<<"                                BARFI\n";
										cout<<"                                (1kg/2kg) : ";
										cin>>quantity;
										F.MATHAI(choice1,quantity);
										system("cls");
										cout<<"                                        "<<quantity<<" BARFI DONE \n";
										break;
									case 5:
										system("cls");
										cout<<setw(50)<<"\n                       #########################################               EXIT MATHI               ####################################### \n ";
										break;
									default:
										system("cls");
										cout<<setw(50)<<"\n                                ########       WRONG INPUT      ########\n";		
								}
							    }while(choice1 != 5);
							    break;
						case 10:
			                    system("cls");
								do{
					            cout<<"\n\n\n";
						        cout<<setw(50)<<"                                ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n";
					            cout<<setw(50)<<"                                |                 FALOODA              |    SIZE      |\n";
					            cout<<setw(50)<<"                                |~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~|\n";
					            cout<<setw(50)<<"                                |      1  .  FALOODA (S/D)             |   SINGLE 150 |\n";
					            cout<<setw(50)<<"                                |                                      |   DOUBLE 300 |\n";
					            cout<<setw(50)<<"                                |                                      |~~~~~~~~~~~~~~|\n";
					            cout<<setw(50)<<"                                |      2  .  SPECIAL MALAI FALOODA(S/D)|   SINGLE 200 |\n";
					            cout<<setw(50)<<"                                |                                      |   DOUBLE 350 |\n";
					            cout<<setw(50)<<"                                |~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~|\n";
					            cout<<setw(50)<<"                                |                         3 . EXIT                    |\n";
					            cout<<setw(50)<<"                                |~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~|\n";
					            cout<<setw(40)<<"                                Choice : ";
					            cin>>choice1;
					            switch(choice1)
								{
									case 1:
										quantity=0;
										cout<<"                                FALOODA \n";
										cout<<"                                Single/Double(S/D) : ";
										cin>>s;
										cout<<"                                QUANTITY \n";
										cin>> quantity;
										F.FALOODA(choice1,s,quantity);
										system("cls");
										cout<<"                                        "<<quantity<<" "<<s<<" FALOODA DONE \n"; 
										break;
									case 2:
										quantity=0;
										cout<<"                                SPECIAL MALAI  FALOODA \n";
										cout<<"                                Single/Double(S/D) : ";
										cin>>s;
										cout<<"                                QUANTITY \n";
										cin>> quantity;
										F.FALOODA(choice1,s,quantity);
										system("cls");
										cout<<"                                        "<<quantity<<" "<<s<<" SPECIAL MALAI FALOODA DONE \n";
										break;
									case 3:
										system("cls");
										cout<<setw(50)<<"\n                       ########################################               EXIT FALOODA               ###################################### \n ";
										break;
									default:
										system("cls");
										cout<<setw(50)<<"\n                                ########       WRONG INPUT      ########\n";		
								}
							    }while(choice1 != 3);
							    break;
						case 11:
							system("cls");
							cout<<setw(50)<<"\n                                ###################            EXIT SWEETS & DISERT          ###################### \n ";
							break;
						default:
							system("cls");
							cout<<setw(50)<<"\n                       #######################################                WRONG INPUT               ####################################### \n ";
						}
					    }while(choice!=11);
						
					}
					else if (choice==4)
					{
						system("cls");
						do{
					    cout<<"\n\n\n";
						cout<<setw(50)<<"                       ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~  \n";
					    cout<<setw(50)<<"                       |                                                       DRINKS                                                         |  \n";
					    cout<<setw(50)<<"                       ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~  \n";
					    cout<<setw(50)<<"                       |                     1  .  7 UP                           |                     6  .  MANGO JUICE/SHAKE               |  \n";
					    cout<<setw(50)<<"                       |                                                          |                                                           |  \n";
					    cout<<setw(50)<<"                       |                                                          |                                                           |  \n";
					    cout<<setw(50)<<"                       |                     2  .  COKA COLA                      |                     7  .  BANANA JUICE/SHAKE              |  \n";
					    cout<<setw(50)<<"                       |                                                          |                                                           |  \n";
					    cout<<setw(50)<<"                       |                                                          |                                                           |  \n";
					    cout<<setw(50)<<"                       |                     3  .  FANTA                          |                     8  .  STRAWBERRY JUICE/SHAKE          |  \n";
					    cout<<setw(50)<<"                       |                                                          |                                                           |  \n";
					    cout<<setw(50)<<"                       |                                                          |                                                           |  \n";
					    cout<<setw(50)<<"                       |                     4  .  STRING                         |                     9  .  APPLE JUICE                     |  \n";
					    cout<<setw(50)<<"                       |                                                          |                                                           |  \n";
					    cout<<setw(50)<<"                       |                                                          |                                                           |  \n";
					    cout<<setw(50)<<"                       |                     5  .  MINERAL WATER                  |                    10  .  ICE-CREAM SHAKE                 |  \n";
					    cout<<setw(50)<<"                       |                                                          |                                                           |  \n";
					    cout<<setw(50)<<"                       |                                                          |                                                           |  \n";
					    cout<<setw(50)<<"                       ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~  \n";
					    cout<<setw(50)<<"                       |                                                      11 . EXIT                                                       |  \n";
					    cout<<setw(50)<<"                       ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~  \n";
					    cout<<setw(40)<<"                       Choice : ";
					    cin>>choice;
					    switch(choice)
						{
							case 1:
								system("cls");
								do{
					            cout<<"\n\n\n";
						        cout<<setw(50)<<"                                ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~             \n";
					            cout<<setw(50)<<"                                |                 7 UP                 |             \n";
					            cout<<setw(50)<<"                                ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~             \n";
					            cout<<setw(50)<<"                                |       1  .  RAGULAR                  |             \n";
					            cout<<setw(50)<<"                                |                                      |             \n";
					            cout<<setw(50)<<"                                |                                      |             \n";
					            cout<<setw(50)<<"                                |       2  .  1 lITER                  |             \n";
					            cout<<setw(50)<<"                                |                                      |             \n";
					            cout<<setw(50)<<"                                |                                      |             \n";
					            cout<<setw(50)<<"                                |       3  .  1.5 lITER                |             \n";
					            cout<<setw(50)<<"                                |                                      |             \n";
					            cout<<setw(50)<<"                                |                                      |             \n";
					            cout<<setw(50)<<"                                |       4  .  2.25 lITER               |             \n";
					            cout<<setw(50)<<"                                |                                      |             \n";
					            cout<<setw(50)<<"                                ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~             \n";
					            cout<<setw(50)<<"                                |               5 . EXIT               |             \n";
					            cout<<setw(50)<<"                                ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~             \n";
					            cout<<setw(40)<<"                                Choice : ";
					            cin>>choice1;
					            switch(choice1)
								{
									case 1:
										cout<<"                                RAGULAR \n";
										cout<<"                                Amount : ";
										cin>>quantity;
										F.s7_UP(choice1,quantity);
										system("cls");
										cout<<"                                        "<<quantity<<" RAGULAR DONE \n"; 
										break;
									case 2:
										cout<<"                                1 lITER \n";
										cout<<"                                AMOUNT : ";
										cin>>quantity;
										F.s7_UP(choice1,quantity);
										system("cls");
										cout<<"                                        "<<size<<" 1 lITER DONE \n";
										break;
									case 3:
										cout<<"                                1.5 lITER\n";
										cout<<"                                AMOUNT : ";
										cin>>quantity;
										F.s7_UP(choice1,quantity);
										system("cls");
										cout<<"                                        "<<size<<" 1.5 lITER DONE \n";
										break;
									case 4:
										cout<<"                                2.25 lITER\n";
										cout<<"                                AMOUNT : ";
										cin>>quantity;
										F.s7_UP(choice1,quantity);
										system("cls");
										cout<<"                                        "<<size<<" 2.25 lITER DONE \n";
										break;
									case 5:
										system("cls");
										cout<<setw(50)<<"\n                       #########################################               EXIT 7 UP                ####################################### \n ";
										break;
									default:
										system("cls");
										cout<<setw(50)<<"\n                                ########       WRONG INPUT      ########\n";		
								}
							    }while(choice1 != 5);
							    break;
						case 2:
								system("cls");
								do{
					            cout<<"\n\n\n";
						        cout<<setw(50)<<"                                ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~             \n";
					            cout<<setw(50)<<"                                |               COKA COLA              |             \n";
					            cout<<setw(50)<<"                                ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~             \n";
					            cout<<setw(50)<<"                                |       1  .  RAGULAR                  |             \n";
					            cout<<setw(50)<<"                                |                                      |             \n";
					            cout<<setw(50)<<"                                |                                      |             \n";
					            cout<<setw(50)<<"                                |       2  .  1 lITER                  |             \n";
					            cout<<setw(50)<<"                                |                                      |             \n";
					            cout<<setw(50)<<"                                |                                      |             \n";
					            cout<<setw(50)<<"                                |       3  .  1.5 lITER                |             \n";
					            cout<<setw(50)<<"                                |                                      |             \n";
					            cout<<setw(50)<<"                                |                                      |             \n";
					            cout<<setw(50)<<"                                |       4  .  2.25 lITER               |             \n";
					            cout<<setw(50)<<"                                |                                      |             \n";
					            cout<<setw(50)<<"                                ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~             \n";
					            cout<<setw(50)<<"                                |               5 . EXIT               |             \n";
					            cout<<setw(50)<<"                                ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~             \n";
					            cout<<setw(40)<<"                                Choice : ";
					            cin>>choice1;
					            switch(choice1)
								{
									case 1:
										cout<<"                                RAGULAR \n";
										cout<<"                                Amount : ";
										cin>>quantity;
										F.COKE_COLA(choice1,quantity);
										system("cls");
										cout<<"                                        "<<quantity<<" RAGULAR DONE \n"; 
										break;
									case 2:
										cout<<"                                1 lITER \n";
										cout<<"                                Amount : ";
										cin>>quantity;
										F.COKE_COLA(choice1,quantity);
										system("cls");
										cout<<"                                        "<<quantity<<" 1 lITER DONE \n";
										break;
									case 3:
										cout<<"                                1.5 lITER\n";
										cout<<"                                Amount : ";
										cin>>quantity;
										F.COKE_COLA(choice1,quantity);
										system("cls");
										cout<<"                                        "<<quantity<<" 1.5 lITER DONE \n";
										break;
									case 4:
										cout<<"                                2.25 lITER\n";
										cout<<"                                Amount : ";
										cin>>quantity;
										F.COKE_COLA(choice1,quantity);
										system("cls");
										cout<<"                                        "<<quantity<<" 2.25 lITER DONE \n";
										break;
									case 5:
										system("cls");
										cout<<setw(50)<<"\n                       #######################################              EXIT COKA COLA                ##################################### \n ";
										break;
									default:
										system("cls");
										cout<<setw(50)<<"\n                                ########       WRONG INPUT      ########\n";		
								}
							    }while(choice1 != 5);
							    break;
						case 3:
								system("cls");
								do{
					            cout<<"\n\n\n";
						        cout<<setw(50)<<"                                ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~             \n";
					            cout<<setw(50)<<"                                |                 FANTA                |             \n";
					            cout<<setw(50)<<"                                ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~             \n";
					            cout<<setw(50)<<"                                |       1  .  RAGULAR                  |             \n";
					            cout<<setw(50)<<"                                |                                      |             \n";
					            cout<<setw(50)<<"                                |                                      |             \n";
					            cout<<setw(50)<<"                                |       2  .  1 lITER                  |             \n";
					            cout<<setw(50)<<"                                |                                      |             \n";
					            cout<<setw(50)<<"                                |                                      |             \n";
					            cout<<setw(50)<<"                                |       3  .  1.5 lITER                |             \n";
					            cout<<setw(50)<<"                                |                                      |             \n";
					            cout<<setw(50)<<"                                |                                      |             \n";
					            cout<<setw(50)<<"                                |       4  .  2.25 lITER               |             \n";
					            cout<<setw(50)<<"                                |                                      |             \n";
					            cout<<setw(50)<<"                                ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~             \n";
					            cout<<setw(50)<<"                                |               5 . EXIT               |             \n";
					            cout<<setw(50)<<"                                ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~             \n";
					            cout<<setw(40)<<"                                Choice : ";
					            cin>>choice1;
					            switch(choice1)
								{
									case 1:
										cout<<"                                RAGULAR \n";
										cout<<"                                Amount : ";
										cin>>quantity;
										F.Fanta(choice1,quantity);
										system("cls");
										cout<<"                                        "<<quantity<<" RAGULAR DONE \n"; 
										break;
									case 2:
										cout<<"                                1 lITER \n";
										cout<<"                                Amount : ";
										cin>>quantity;
										F.Fanta(choice1,quantity);
										system("cls");
										cout<<"                                        "<<quantity<<" 1 lITER DONE \n";
										break;
									case 3:
										cout<<"                                1.5 lITER\n";
										cout<<"                                Amount : ";
										cin>>quantity;
										F.Fanta(choice1,quantity);
										system("cls");
										cout<<"                                        "<<quantity<<" 1.5 lITER DONE \n";
										break;
									case 4:
										cout<<"                                2.25 lITER\n";
										cout<<"                                Amount : ";
										cin>>quantity;
										F.Fanta(choice1,quantity);
										system("cls");
										cout<<"                                        "<<quantity<<" 2.25 lITER DONE \n";
										break;
									case 5:
										system("cls");
										cout<<setw(50)<<"\n                       #########################################               EXIT FANTA               ####################################### \n ";
										break;
									default:
										system("cls");
										cout<<setw(50)<<"\n                                ########       WRONG INPUT      ########\n";		
								}
							    }while(choice1 != 5);
							    break;
						case 4:
								system("cls");
								do{
					            cout<<"\n\n\n";
						        cout<<setw(50)<<"                                ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~             \n";
					            cout<<setw(50)<<"                                |                 STRING               |             \n";
					            cout<<setw(50)<<"                                ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~             \n";
					            cout<<setw(50)<<"                                |       1  .  RAGULAR                  |             \n";
					            cout<<setw(50)<<"                                |                                      |             \n";
					            cout<<setw(50)<<"                                |                                      |             \n";
					            cout<<setw(50)<<"                                |       2  .  1 lITER                  |             \n";
					            cout<<setw(50)<<"                                |                                      |             \n";
					            cout<<setw(50)<<"                                |                                      |             \n";
					            cout<<setw(50)<<"                                |       3  .  1.5 lITER                |             \n";
					            cout<<setw(50)<<"                                |                                      |             \n";
					            cout<<setw(50)<<"                                |                                      |             \n";
					            cout<<setw(50)<<"                                |       4  .  2.25 lITER               |             \n";
					            cout<<setw(50)<<"                                |                                      |             \n";
					            cout<<setw(50)<<"                                ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~             \n";
					            cout<<setw(50)<<"                                |               5 . EXIT               |             \n";
					            cout<<setw(50)<<"                                ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~             \n";
					            cout<<setw(40)<<"                                Choice : ";
					            cin>>choice1;
					            switch(choice1)
								{
									case 1:
										cout<<"                                RAGULAR \n";
										cout<<"                                Amount : ";
										cin>>quantity;
										F.STRING(choice1,quantity);
										system("cls");
										cout<<"                                        "<<quantity<<" RAGULAR DONE \n"; 
										break;
									case 2:
										cout<<"                                1 lITER \n";
										cout<<"                                Amount : ";
										cin>>quantity;
										F.STRING(choice1,quantity);
										system("cls");
										cout<<"                                        "<<quantity<<" 1 lITER DONE \n";
										break;
									case 3:
										cout<<"                                1.5 lITER\n";
										cout<<"                                Amount : ";
										cin>>quantity;
										F.STRING(choice1,quantity);
										system("cls");
										cout<<"                                        "<<quantity<<" 1.5 lITER DONE \n";
										break;
									case 4:
										cout<<"                                2.25 lITER\n";
										cout<<"                                Amount : ";
										cin>>quantity;
										F.STRING(choice1,quantity);
										system("cls");
										cout<<"                                        "<<quantity<<" 2.25 lITER DONE \n";
										break;
									case 5:
										system("cls");
										cout<<setw(50)<<"\n                       ########################################               EXIT STRING                ###################################### \n ";
										break;
									default:
										system("cls");
										cout<<setw(50)<<"\n                                ########       WRONG INPUT      ########\n";		
								}
							    }while(choice1 != 5);
							    break;
						case 5:
								system("cls");
								do{
					            cout<<"\n\n\n";
						        cout<<setw(50)<<"                                ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~             \n";
					            cout<<setw(50)<<"                                |             MINERAL WATER            |             \n";
					            cout<<setw(50)<<"                                ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~             \n";
					            cout<<setw(50)<<"                                |       1  .  RAGULAR                  |             \n";
					            cout<<setw(50)<<"                                |                                      |             \n";
					            cout<<setw(50)<<"                                |                                      |             \n";
					            cout<<setw(50)<<"                                |       2  .  1.5 lITER                |             \n";
					            cout<<setw(50)<<"                                |                                      |             \n";
					            cout<<setw(50)<<"                                ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~             \n";
					            cout<<setw(50)<<"                                |               3 . EXIT               |             \n";
					            cout<<setw(50)<<"                                ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~             \n";
					            cout<<setw(40)<<"                                Choice : ";
					            cin>>choice1;
					            switch(choice1)
								{
									case 1:
										cout<<"                                RAGULAR \n";
										cout<<"                                Amount : ";
										cin>>quantity;
										F.WATER(choice1,quantity);
										system("cls");
										cout<<"                                        "<<quantity<<" RAGULAR DONE \n"; 
										break;
									case 2:
										cout<<"                                1.5 lITER\n";
										cout<<"                                Amount : ";
										cin>>quantity;
										F.WATER(choice1,quantity);
										system("cls");
										cout<<"                                        "<<quantity<<" 1.5 lITER DONE \n";
										break;
									case 3:
										system("cls");
										cout<<setw(50)<<"\n                       #########################################               EXIT 7 UP                ####################################### \n ";
										break;
									default:
										system("cls");
										cout<<setw(50)<<"\n                                ########       WRONG INPUT      ########\n";		
								}
							    }while(choice1 != 3);
							    break;
						case 6:
								system("cls");
								do{
					            cout<<"\n\n\n";
						        cout<<setw(50)<<"                                ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~             \n";
					            cout<<setw(50)<<"                                |             MANGO JUICE/SHAKE        |             \n";
					            cout<<setw(50)<<"                                ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~             \n";
					            cout<<setw(50)<<"                                |       1  .  RAGULAR                  |             \n";
					            cout<<setw(50)<<"                                |                                      |             \n";
					            cout<<setw(50)<<"                                |                                      |             \n";
					            cout<<setw(50)<<"                                |       2  .  1 lITER                  |             \n";
					            cout<<setw(50)<<"                                |                                      |             \n";
					            cout<<setw(50)<<"                                ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~             \n";
					            cout<<setw(50)<<"                                |               3 . EXIT               |             \n";
					            cout<<setw(50)<<"                                ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~             \n";
					            cout<<setw(40)<<"                                Choice : ";
					            cin>>choice1;
					            switch(choice1)
								{
									case 1:
										cout<<"                                RAGULAR \n";
										cout<<"                                Amount : ";
										cin>>quantity;
										F.MANGO_JUICE(choice1,quantity);
										system("cls");
										cout<<"                                        "<<quantity<<" RAGULAR DONE \n"; 
										break;
									case 2:
										cout<<"                                1 lITER\n";
										cout<<"                                Amount : ";
										cin>>quantity;
										F.MANGO_JUICE(choice1,quantity);
										system("cls");
										cout<<"                                        "<<quantity<<" 1 lITER DONE \n";
										break;
									case 3:
										system("cls");
										cout<<setw(50)<<"\n                       ####################################              EXIT MANGO JUICE/SHAKE              ################################## \n ";
										break;
									default:
										system("cls");
										cout<<setw(50)<<"\n                                ########       WRONG INPUT      ########\n";		
								}
							    }while(choice1 != 3);
							    break;
						case 7:
								system("cls");
								do{
					            cout<<"\n\n\n";
						        cout<<setw(50)<<"                                ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~             \n";
					            cout<<setw(50)<<"                                |             BANANA JUICE/SHAKE       |             \n";
					            cout<<setw(50)<<"                                ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~             \n";
					            cout<<setw(50)<<"                                |       1  .  RAGULAR                  |             \n";
					            cout<<setw(50)<<"                                |                                      |             \n";
					            cout<<setw(50)<<"                                |                                      |             \n";
					            cout<<setw(50)<<"                                |       2  .  1 lITER                  |             \n";
					            cout<<setw(50)<<"                                |                                      |             \n";
					            cout<<setw(50)<<"                                ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~             \n";
					            cout<<setw(50)<<"                                |               3 . EXIT               |             \n";
					            cout<<setw(50)<<"                                ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~             \n";
					            cout<<setw(40)<<"                                Choice : ";
					            cin>>choice1;
					            switch(choice1)
								{
									case 1:
										cout<<"                                RAGULAR \n";
										cout<<"                                Amount : ";
										cin>>quantity;
										F.BANANA_JUICE(choice1,quantity);
										system("cls");
										cout<<"                                        "<<quantity<<" RAGULAR DONE \n"; 
										break;
									case 2:
										cout<<"                                1 lITER\n";
										cout<<"                                Amount : ";
										cin>>quantity;
										F.BANANA_JUICE(choice1,quantity);
										system("cls");
										cout<<"                                        "<<quantity<<" 1 lITER DONE \n";
										break;
									case 3:
										system("cls");
										cout<<setw(50)<<"\n                       ####################################              EXIT BANANA JUICE/SHAKE             ################################## \n ";
										break;
									default:
										system("cls");
										cout<<setw(50)<<"\n                                ########       WRONG INPUT      ########\n";		
								}
							    }while(choice1 != 3);
							    break;
						case 8:
								system("cls");
								do{
					            cout<<"\n\n\n";
						        cout<<setw(50)<<"                                ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~             \n";
					            cout<<setw(50)<<"                                |         STRAWBERRY JUICE/SHAKE       |             \n";
					            cout<<setw(50)<<"                                ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~             \n";
					            cout<<setw(50)<<"                                |       1  .  RAGULAR                  |             \n";
					            cout<<setw(50)<<"                                |                                      |             \n";
					            cout<<setw(50)<<"                                |                                      |             \n";
					            cout<<setw(50)<<"                                |       2  .  1 lITER                  |             \n";
					            cout<<setw(50)<<"                                |                                      |             \n";
					            cout<<setw(50)<<"                                ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~             \n";
					            cout<<setw(50)<<"                                |               3 . EXIT               |             \n";
					            cout<<setw(50)<<"                                ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~             \n";
					            cout<<setw(40)<<"                                Choice : ";
					            cin>>choice1;
					            switch(choice1)
								{
									case 1:
										cout<<"                                RAGULAR \n";
										cout<<"                                Amount : ";
										cin>>quantity;
										F.STAWBERRY_JUICE(choice1,quantity);
										system("cls");
										cout<<"                                        "<<quantity<<" RAGULAR DONE \n"; 
										break;
									case 2:
										cout<<"                                1 lITER\n";
										cout<<"                                Amount : ";
										cin>>quantity;
										F.STAWBERRY_JUICE(choice1,quantity);
										system("cls");
										cout<<"                                        "<<quantity<<" 1 lITER DONE \n";
										break;
									case 3:
										system("cls");
										cout<<setw(50)<<"\n                       #################################              EXIT STRAWBERRY JUICE/SHAKE             ################################ \n ";
										break;
									default:
										system("cls");
										cout<<setw(50)<<"\n                                ########       WRONG INPUT      ########\n";		
								}
							    }while(choice1 != 3);
							    break;
						case 9:
								system("cls");
								do{
					            cout<<"\n\n\n";
						        cout<<setw(50)<<"                                ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~             \n";
					            cout<<setw(50)<<"                                |             APPLE JUICE              |             \n";
					            cout<<setw(50)<<"                                ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~             \n";
					            cout<<setw(50)<<"                                |       1  .  RAGULAR                  |             \n";
					            cout<<setw(50)<<"                                |                                      |             \n";
					            cout<<setw(50)<<"                                |                                      |             \n";
					            cout<<setw(50)<<"                                |       2  .  1 lITER                  |             \n";
					            cout<<setw(50)<<"                                |                                      |             \n";
					            cout<<setw(50)<<"                                ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~             \n";
					            cout<<setw(50)<<"                                |               3 . EXIT               |             \n";
					            cout<<setw(50)<<"                                ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~             \n";
					            cout<<setw(40)<<"                                Choice : ";
					            cin>>choice1;
					            switch(choice1)
								{
									case 1:
										cout<<"                                RAGULAR \n";
										cout<<"                                Amount : ";
										cin>>quantity;
										F.APPLE_JUICE(choice1,quantity);
										system("cls");
										cout<<"                                        "<<quantity<<" RAGULAR DONE \n"; 
										break;
									case 2:
										cout<<"                                1 lITER\n";
										cout<<"                                Amount : ";
										cin>>quantity;
										F.APPLE_JUICE(choice1,quantity);
										system("cls");
										cout<<"                                        "<<quantity<<" 1 lITER DONE \n";
										break;
									case 3:
										system("cls");
										cout<<setw(50)<<"\n                       ######################################               EXIT APPLE JUICE               #################################### \n ";
										break;
									default:
										system("cls");
										cout<<setw(50)<<"\n                                ########       WRONG INPUT      ########\n";		
								}
							    }while(choice1 != 3);
							    break;
						case 10:
								system("cls");
								do{
					            cout<<"\n\n\n";
						        cout<<setw(50)<<"                                ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~             \n";
					            cout<<setw(50)<<"                                |             ICE-CREAM SHAKE          |             \n";
					            cout<<setw(50)<<"                                ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~             \n";
					            cout<<setw(50)<<"                                |       1  .  RAGULAR                  |             \n";
					            cout<<setw(50)<<"                                |                                      |             \n";
					            cout<<setw(50)<<"                                |                                      |             \n";
					            cout<<setw(50)<<"                                |       2  .  1 lITER                  |             \n";
					            cout<<setw(50)<<"                                |                                      |             \n";
					            cout<<setw(50)<<"                                ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~             \n";
					            cout<<setw(50)<<"                                |               3 . EXIT               |             \n";
					            cout<<setw(50)<<"                                ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~             \n";
					            cout<<setw(40)<<"                                Choice : ";
					            cin>>choice1;
					            switch(choice1)
								{
									case 1:
										cout<<"                                RAGULAR \n";
										cout<<"                                Amount : ";
										cin>>quantity;
										F.ICE_CREAM_Shake(choice1,quantity);
										system("cls");
										cout<<"                                        "<<quantity<<" RAGULAR DONE \n"; 
										break;
									case 2:
										cout<<"                                1 lITER\n";
										cout<<"                                Amount : ";
										cin>>quantity;
										F.ICE_CREAM_Shake(choice1,quantity);
										system("cls");
										cout<<"                                        "<<quantity<<" 1 lITER DONE \n";
										break;
									case 3:
										system("cls");
										cout<<setw(50)<<"\n                       #####################################              EXIT ICE-CREAM SHAKE              ################################### \n ";
										break;
									default:
										system("cls");
										cout<<setw(50)<<"\n                                ########       WRONG INPUT      ########\n";		
								}
							    }while(choice1 != 3);
							    break;
						case 11:
							system("cls");
							cout<<setw(50)<<"\n                                ####################               EXIT DRINKS              ####################### \n ";
							break;
						default:
							system("cls");
							cout<<setw(50)<<"\n                       #######################################                WRONG INPUT               ####################################### \n ";
						}
					    }while(choice!=11);
					}
					else if (choice==5)
					{
						system("cls");
						F.DISPLAY_BILL2();
						getch();
						system("cls");
						cout<<setw(50)<<"                                ######################   EXIT MENU    ######################               \n";
					}
					else
					{
						system("cls");
						cout<<setw(50)<<"\n                                #############################      WRONG INPUT     ################################ \n ";	
					}
					}while(choice !=5);
					break;
				case 2:
					system("cls");
					cout<<"\n\n\n\n\n\n";
					cout<<setw(50)<<"                                ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~               \n";
					cout<<setw(50)<<"                                |                     Attendence                           |               \n";
					cout<<setw(50)<<"                                ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~               \n";
					cout<<setw(50)<<"                                |                     Press (enter)                        |               \n";
					cout<<setw(50)<<"                                ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~               \n";
					getch();
					break;
				case 3:
					system("cls");
					cout<<"\n\n\n\n\n\n";
					cout<<setw(50)<<"                                ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~               \n";
					cout<<setw(50)<<"                                |                     Daily sales                          |               \n";
					cout<<setw(50)<<"                                ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~               \n";
					F.DISPLAY_SALES();
					getch();
					break;
				case 4:
					system("cls");
					cout<<"\n\n\n\n\n\n";
					F.DISPLAY_BILL();
					getch();
					break;	
				case 5:
					system("cls");
					cout<<"\n\n\n\n\n\n";
					cout<<setw(50)<<"                                ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~               \n";
					cout<<setw(50)<<"                                |                     YOUR RECORD                          |               \n";
					cout<<setw(50)<<"                                ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~               \n";
					break;
				case 6:
					system("cls");
					cout<<"\n\n\n\n\n\n\n\n\n\n\n\n";
					system("color f4");
					cout<<setw(50)<<"                                ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~               \n";
					cout<<setw(50)<<"                                |                     LOG OUT                              |               \n";
					cout<<setw(50)<<"                                ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~               \n";
					getch();
					system("cls");

					temp=false;
					break;
			}
		}
		while(choice != 6);
		}
		else if(T=="C")
		{
			do{
			system("cls");
			cout<<setw(50)<<"                                ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~               \n";
			cout<<setw(50)<<"                                |                         CUSTOMER                         |               \n";
			cout<<setw(50)<<"                                ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~               \n";
	        cout<<setw(50)<<"                                |                                                          |               \n";
	        cout<<setw(20)<<"                                |        1 . Menu                                          |               \n";
	        cout<<setw(20)<<"                                |        2 . Your record                                   |               \n";
	        cout<<setw(20)<<"                                |        3 . Log out                                       |               \n";
	        cout<<setw(20)<<"                                |                                                          |               \n";
	        cout<<setw(50)<<"                                ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~               \n";
	        cout<<setw(40)<<"                                Choice : ";
	        cin>>choice;
	        switch(choice)
			{
				case 1:
					system("cls");
					do{
					cout<<"\n\n\n";
					cout<<setw(50)<<"                                ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~              \n";
					cout<<setw(50)<<"                                |                                     MENU                                        |               \n";
					cout<<setw(50)<<"                                ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~               \n";
					cout<<setw(50)<<"                                |                    1  .  FAST FOOD                                              |               \n";
					cout<<setw(50)<<"                                |                                                                                 |               \n";
					cout<<setw(50)<<"                                |                                                                                 |               \n";
					cout<<setw(50)<<"                                |                    2  .  DESI FOOD                                              |               \n";
					cout<<setw(50)<<"                                |                                                                                 |               \n";
					cout<<setw(50)<<"                                |                                                                                 |               \n";
					cout<<setw(50)<<"                                |                    3  .  SWEETS & DISERT                                        |               \n";
					cout<<setw(50)<<"                                |                                                                                 |               \n";
					cout<<setw(50)<<"                                |                                                                                 |               \n";
					cout<<setw(50)<<"                                |                    4  .  DRINKS                                                 |               \n";
					cout<<setw(50)<<"                                |                                                                                 |               \n";
					cout<<setw(50)<<"                                |                                                                                 |               \n";
					cout<<setw(50)<<"                                |                    5  .  EXIT                                                   |               \n";
					cout<<setw(50)<<"                                ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~              \n";
					cout<<setw(40)<<"                                Choice : ";
					cin>>choice;
					if (choice==1)
					{
						system("cls");
						do{
					    cout<<"\n\n\n";
						cout<<setw(50)<<"                       ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~  \n";
					    cout<<setw(50)<<"                       |                                                          FAST FOOD                                                   |  \n";
					    cout<<setw(50)<<"                       ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~  \n";
					    cout<<setw(50)<<"                       |            1  .  BURGER              |       6  .  CHICKEN PIECE              |         11  .  PASTA                 |  \n";
					    cout<<setw(50)<<"                       |                                      |                                        |                                      |  \n";
					    cout<<setw(50)<<"                       |                                      |                                        |                                      |  \n";
					    cout<<setw(50)<<"                       |            2  .  PIZZA               |       7  .  CHICKEN WINGS              |         12  .  DRUM STICK            |  \n";
					    cout<<setw(50)<<"                       |                                      |                                        |                                      |  \n";
					    cout<<setw(50)<<"                       |                                      |                                        |                                      |  \n";
					    cout<<setw(50)<<"                       |            3  .  SHAWARMA            |       8  .  CHICKEN NUGGETS            |         13  .  SOMASA                |  \n";
					    cout<<setw(50)<<"                       |                                      |                                        |                                      |  \n";
					    cout<<setw(50)<<"                       |                                      |                                        |                                      |  \n";
					    cout<<setw(50)<<"                       |            4  .  SANDWITCH           |       9  .  HOT & SPICY                |         14  .  ROLL PARATHA          |  \n";
					    cout<<setw(50)<<"                       |                                      |                                        |                                      |  \n";
					    cout<<setw(50)<<"                       |                                      |                                        |                                      |  \n";
					    cout<<setw(50)<<"                       |            5  .  FISH                |      10  .  BARBIE KU                  |         15  .  CHAT                  |  \n";
					    cout<<setw(50)<<"                       |                                      |                                        |                                      |  \n";
					    cout<<setw(50)<<"                       |                                      |                                        |                                      |  \n";
					    cout<<setw(50)<<"                       ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~  \n";
					    cout<<setw(50)<<"                       |                                                      16 . EXIT                                                       |  \n";
					    cout<<setw(50)<<"                       ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~  \n";
					    cout<<setw(40)<<"                       Choice : ";
					    cin>>choice;
					    switch(choice)
						{
							case 1:
								system("cls");
								do{
					            cout<<"\n\n\n";
						        cout<<setw(50)<<"                                ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~             \n";
					            cout<<setw(50)<<"                                |              BURGER                  |             \n";
					            cout<<setw(50)<<"                                ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~             \n";
					            cout<<setw(50)<<"                                |         1  .  ZINGER (350)           |             \n";
					            cout<<setw(50)<<"                                |                                      |             \n";
					            cout<<setw(50)<<"                                |                                      |             \n";
					            cout<<setw(50)<<"                                |         2  .  CRUNCH (230)           |             \n";
					            cout<<setw(50)<<"                                |                                      |             \n";
					            cout<<setw(50)<<"                                |                                      |             \n";
					            cout<<setw(50)<<"                                |         3  .  DOUBLE PATTY (450)     |             \n";
					            cout<<setw(50)<<"                                |                                      |             \n";
					            cout<<setw(50)<<"                                |                                      |             \n";
					            cout<<setw(50)<<"                                |         4  .  CHEESE BURGER (400)    |             \n";
					            cout<<setw(50)<<"                                |                                      |             \n";
					            cout<<setw(50)<<"                                |                                      |             \n";
					            cout<<setw(50)<<"                                |         5  .  ZINGER SUPREME (520)   |             \n";
					            cout<<setw(50)<<"                                |                                      |             \n";
					            cout<<setw(50)<<"                                ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~             \n";
					            cout<<setw(50)<<"                                |            6 . EXIT                  |             \n";
					            cout<<setw(50)<<"                                ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~             \n";
					            cout<<setw(40)<<"                                Choice : ";
					            cin>>choice1;
					            switch(choice1)
								{
									case 1:
										quantity=0;
										cout<<"                                Zinger Burger\n";
										cout<<"                                Amount : ";
										cin>>quantity;
										//cout<<quantity<<endl;
										F.Burger(choice1,quantity);
										system("cls");
										cout<<"                                        "<<quantity<<" Zinger Burger DONE \n"; 
										break;
									case 2:
										quantity=0;
										cout<<"                                Crunch Burger\n";
										cout<<"                                Amount : ";
										cin>>quantity;
										F.Burger(choice1,quantity);
										system("cls");
										cout<<"                                        "<<quantity<<" Crunch Burger DONE \n";
										break;
									case 3:
									    quantity=0;
										cout<<"                                Double Patty Burger\n";
										cout<<"                                Amount : ";			
										cin>>quantity;
										F.Burger(choice1,quantity);
										system("cls");
										cout<<"                                        "<<quantity<<" Double Patty Burger DONE \n";
										break;
									case 4:
										quantity=0;
										cout<<"                                Chesse Burger\n";
										cout<<"                                Amount : ";
										cin>>quantity;
										F.Burger(choice1,quantity);
										system("cls");
										cout<<"                                        "<<quantity<<" Cheese Burger DONE \n";
										break;
									case 5:
										quantity=0;
										cout<<"                                ZINGER SUPREME\n";
										cout<<"                                Amount : ";
										cin>>quantity;
										F.Burger(choice1,quantity);
										system("cls");
										cout<<"                                        "<<quantity<<" ZINGER SUPREME DONE \n";
										break;
									case 6:
										system("cls");
										cout<<setw(50)<<"\n                       #########################################              EXIT BURGER MENU              ######################################## \n ";
										break;
									default:
										system("cls");
										cout<<setw(50)<<"\n                                ########       WRONG INPUT      ########\n";
										
								}
							    }while(choice1 != 6);
							    break;
						
						    case 2:
						    	system("cls");
								do{
					            cout<<"\n\n\n";
						        cout<<setw(50)<<"                                ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n";
					            cout<<setw(50)<<"                                |              PIZZA                   |     Size     |\n";
					            cout<<setw(50)<<"                                |~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~|~~~~~~~~~~~~~~|\n";
					            cout<<setw(50)<<"                                |         1  .  FAJITA (S/M/L)         |              |\n";
					            cout<<setw(50)<<"                                |                                      |              |\n";
					            cout<<setw(50)<<"                                |                                      |              |\n";
					            cout<<setw(50)<<"                                |         2  .  TIKKA  (S/M/L)         | SMALL = 450  |\n";
					            cout<<setw(50)<<"                                |                                      |              |\n";
					            cout<<setw(50)<<"                                |                                      | MEDIUM = 850 |\n";
					            cout<<setw(50)<<"                                |         3  .  CHEESE LODER (S/M/L)   |              |\n";
					            cout<<setw(50)<<"                                |                                      | LARGE = 1250 |\n";
					            cout<<setw(50)<<"                                |                                      |              |\n";
					            cout<<setw(50)<<"                                |         4  .  BARBIE KU  (S/M/L)     |              |\n";
					            cout<<setw(50)<<"                                |~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~|~~~~~~~~~~~~~~|\n";
					            cout<<setw(50)<<"                                |                                      | SMALL = 550  |\n";
					            cout<<setw(50)<<"                                |         5  .  A & Z SPECIAL (S/M/L)  | MEDIUM = 950 |\n";
					            cout<<setw(50)<<"                                |                                      | LARGE = 1350 |\n";
					            cout<<setw(50)<<"                                |~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~|\n";
					            cout<<setw(50)<<"                                |                       6 . EXIT                      |\n";
					            cout<<setw(50)<<"                                ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n";
					            cout<<setw(40)<<"                                Choice : ";
					            cin>>choice1;
					            switch(choice1)
								{
									case 1:
									    quantity=0;
										cout<<"                                FAJITA PIZZA  \n";
										cout<<"                                SIZE(S/M/L) : ";
										cin>>s;
										cout<<"                                QUANTITY : ";
										cin>>quantity;
										F.PIZZA(choice1,s,quantity);
										system("cls");
										cout<<"                                        "<<quantity<<" "<< s <<" FAJITA PIZZA DONE \n";
										break;
									case 2:
										quantity=0;
										cout<<"                                TIKKA \n";
										cout<<"                                SIZE(S/M/L) : ";
										cin>>s;
										cout<<"                                Quantity : ";
										cin>>quantity;
										F.PIZZA(choice1,s,quantity);
										system("cls");
										cout<<"                                        "<<quantity<<" "<< s <<" TIKKA DONE \n";
										break;
									case 3:
										quantity=0;
										cout<<"                                CHEESE LOADER \n";
										cout<<"                                SIZE(S/M/L) : ";
										cin>>s;
										cout<<"                                Quantity : ";
										cin>>quantity;
										F.PIZZA(choice1,s,quantity);
										system("cls");
										cout<<"                                        "<<quantity<<" "<< s <<" CHEESE LOADER DONE \n";
										break;
									case 4:
										quantity=0;
										cout<<"                                BBQ \n";
										cout<<"                                SIZE(S/M/L) : ";
										cin>>s;
										cout<<"                                Quantity : ";
										cin>>quantity;
										F.PIZZA(choice1,s,quantity);
										system("cls");
										cout<<"                                        "<<quantity<<" "<< s <<" BBQ DONE \n";
										break;
									case 5:
										quantity=0;
										cout<<"                                A & Z SPECIAL \n";
										cout<<"                                SIZE(S/M/L) : ";
										cin>>s;
										cout<<"                                Quantity : ";
										cin>>quantity;
										F.PIZZA(choice1,s,quantity);
										system("cls");
										cout<<"                                        "<<quantity<<" "<< s <<" A & Z SPECIAL DONE \n";
										break;
									case 6:
										system("cls");
										cout<<setw(50)<<"\n                       #########################################              EXIT PIZZA              ######################################### \n ";
										break;
									default:
										system("cls");
										cout<<setw(50)<<"\n                                ########       WRONG INPUT      ########\n";
								
										
								}
							    }while(choice1 != 6);
							    break;
						case 3:
							system("cls");
								do{
					            cout<<"\n\n\n";
						        cout<<setw(50)<<"                                ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n";
					            cout<<setw(50)<<"                                |              SHAWARMA                |    SIZE     |\n";
					            cout<<setw(50)<<"                                |~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~|~~~~~~~~~~~~~|\n";
					            cout<<setw(50)<<"                                |         1  .  ZINGER (S/L)           | Small  170  |\n";
					            cout<<setw(50)<<"                                |                                      | Large  250  |\n";
					            cout<<setw(50)<<"                                |                                      |~~~~~~~~~~~~~|\n";
					            cout<<setw(50)<<"                                |         2  .  CHICKEN  (S/L)         | Small  150  |\n";
					            cout<<setw(50)<<"                                |                                      | Large  210  |\n";
					            cout<<setw(50)<<"                                |                                      |~~~~~~~~~~~~~|\n";
					            cout<<setw(50)<<"                                |         3  .  CHEESE (S/L)           | Small  200  |\n";
					            cout<<setw(50)<<"                                |                                      | Large  280  |\n";
					            cout<<setw(50)<<"                                |                                      |~~~~~~~~~~~~~|\n";
					            cout<<setw(50)<<"                                |         4  .  A & Z SPECIAL (S/L)    | Small  250  |\n";
					            cout<<setw(50)<<"                                |                                      | Large  320  |\n";
					            cout<<setw(50)<<"                                |~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~|\n";
					            cout<<setw(50)<<"                                |                       5 . EXIT                     |\n";
					            cout<<setw(50)<<"                                ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n";
					            cout<<setw(40)<<"                                Choice : ";
					            cin>>choice1;
					            switch(choice1)
								{
									case 1:
										quantity=0;
										cout<<"                                ZINGER  \n";
										cout<<"                                SIZE(S/L) : ";
										cin>>s;
										cout<<"                                Quantity : ";
										cin>>quantity;
										F.SHAWARMA(choice1,s,quantity);										
										system("cls");
										cout<<"\n                                        "<<quantity<<" ZINGER SHAWARMA DONE \n";
										break;
									case 2:
										quantity=0;
										cout<<"                                CHICKEN \n";
										cout<<"                                SIZE (S/L) : ";
										cin>>s;
										cout<<"                                Quantity : ";
										cin>>quantity;
										F.SHAWARMA(choice1,s,quantity);	
										system("cls");
										cout<<"\n                                        "<<quantity<<" CHICKEN SHAWARMA DONE \n";
										break;
									case 3:
										quantity=0;
										cout<<"                                CHEESE  \n";
										cout<<"                                SIZE (S/L) : ";
										cin>>s;
										cout<<"                                Quantity : ";
										cin>>quantity;
										F.SHAWARMA(choice1,s,quantity);	
										system("cls");
										cout<<"\n                                        "<<quantity<<" CHEESE SHAWARMA DONE \n";
										break;
									case 4:
										quantity=0;
										cout<<"                                A & Z SPECIAL \n";
										cout<<"                                SIZE (S/L) : ";
										cin>>s;
										cout<<"                                Quantity : ";
										cin>>quantity;
										F.SHAWARMA(choice1,s,quantity);	
										system("cls");
										cout<<"\n                                        "<<quantity<<" A & Z SPECIAL SHAWARMA DONE \n";
										break;
									case 5:
										system("cls");
										cout<<setw(50)<<"\n                       ########################################              EXIT SHAWARMA              ####################################### \n ";
										break;
									default:
										system("cls");
										cout<<setw(50)<<"\n                                ########       WRONG INPUT      ########\n";
										
								}
							    }while(choice1 != 5);
							    break;
						case 4:
							system("cls");
								do{							
					            cout<<"\n\n\n";
						        cout<<setw(50)<<"                                ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n";
					            cout<<setw(50)<<"                                |              SANDWITCH               |\n";
					            cout<<setw(50)<<"                                |~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~|\n";
					            cout<<setw(50)<<"                                |         1  .  CHICKEN (180)          |\n";
					            cout<<setw(50)<<"                                |                                      |\n";
					            cout<<setw(50)<<"                                |                                      |\n";
					            cout<<setw(50)<<"                                |         2  .  CLUB  (220)            |\n";
					            cout<<setw(50)<<"                                |                                      |\n";
					            cout<<setw(50)<<"                                |~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~|\n";
					            cout<<setw(50)<<"                                |              3 . EXIT                |\n";
					            cout<<setw(50)<<"                                ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n";
					            cout<<setw(40)<<"                                Choice : ";
					            cin>>choice1;
					            switch(choice1)
								{
									case 1:
										cout<<"                                CHICKEN SANDWITCH (S/L) \n";
										cout<<"                                Quantity : ";
										cin>>quantity;
										F.SANDWITCH(choice1,quantity);
										system("cls");
										cout<<"\n                                        "<<quantity<<" CHICKEN SANDWITCH DONE \n";
										break;
									case 2:
										cout<<"                                CLUB SANDWITCH (S/L) \n";
										cout<<"                                Quantity : ";
										cin>>quantity;
										F.SANDWITCH(choice1,quantity);
										system("cls");
										cout<<"\n                                        "<<quantity<<" CLUB SANDWITCH DONE \n";
										break;
									case 3:
										system("cls");
										cout<<setw(50)<<"\n                       #######################################              EXIT SANDWITCH              ####################################### \n ";
										break;
									default:
										system("cls");
										cout<<setw(50)<<"\n                                ########       WRONG INPUT      ########\n";
										
								}
							    }while(choice1 != 3);
							    break;
						case 5:
							system("cls");
								do{
						        cout<<setw(50)<<"                                ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n";
					            cout<<setw(50)<<"                                |              FISH                    |             |\n";
					            cout<<setw(50)<<"                                ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~|~~~~~~~~~~~~~|\n";
					            cout<<setw(50)<<"                                |         1  .  Finger Fish            | 1 piece 220 |\n";
					            cout<<setw(50)<<"                                |                                      |             |\n";
					            cout<<setw(50)<<"                                |                                      |~~~~~~~~~~~~~|\n";
					            cout<<setw(50)<<"                                |         2  .  Masala Fish            | 1 piece 160 |\n";
					            cout<<setw(50)<<"                                |                                      |             |\n";
					            cout<<setw(50)<<"                                ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~|\n";
					            cout<<setw(50)<<"                                |                      3 . EXIT                      |\n";
					            cout<<setw(50)<<"                                ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n";
					            cout<<setw(40)<<"                                Choice : ";
					            cin>>choice1;;
					            switch(choice1)
								{
									case 1:
										cout<<"                                FINGER FISH \n";
										cout<<"                                quantity : ";
										cin>>quantity;
										F.FISH(choice1,quantity);
										system("cls");
										cout<<"\n                                        "<<quantity<<" FINGER FISH PIECE DONE \n";
										break;
									case 2:
										cout<<"                                MASALA FISH \n";
										cout<<"                                quantity : ";
										cin>>quantity;
										F.FISH(choice1,quantity);
										system("cls");
										cout<<"\n                                        "<<quantity<<" MASALA FISH PIECE DONE \n";
										break;
									case 3:
										system("cls");
										cout<<setw(50)<<"\n                       #########################################               EXIT FISH              ######################################### \n ";
										break;
									default:
										system("cls");
										cout<<setw(50)<<"\n                                ########       WRONG INPUT      ########\n";
										
								}
							    }while(choice1 != 3);
							    break;
						case 6:
							system("cls");
								do{
					            cout<<"\n\n\n";
						        cout<<setw(50)<<"                                ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~             \n";
					            cout<<setw(50)<<"                                |              CHICKEN PIECE           |             \n";
					            cout<<setw(50)<<"                                ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~             \n";
					            cout<<setw(50)<<"                                |         1  .  1 PIECE (250)          |             \n";
					            cout<<setw(50)<<"                                |                                      |             \n";
					            cout<<setw(50)<<"                                |                                      |             \n";
					            cout<<setw(50)<<"                                |         2  .  3 PIECE (650)          |             \n";
					            cout<<setw(50)<<"                                |                                      |             \n";
					            cout<<setw(50)<<"                                |                                      |             \n";
					            cout<<setw(50)<<"                                |         3  .  5 PIECE (1050)         |             \n";
					            cout<<setw(50)<<"                                |                                      |             \n";
					            cout<<setw(50)<<"                                |                                      |             \n";
					            cout<<setw(50)<<"                                |         4  .  12pc Family deal (1700)|             \n";
					            cout<<setw(50)<<"                                |                                      |             \n";
					            cout<<setw(50)<<"                                ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~             \n";
					            cout<<setw(50)<<"                                |            5 . EXIT                  |             \n";
					            cout<<setw(50)<<"                                ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~             \n";
					            cout<<setw(40)<<"                                Choice : ";
					            cin>>choice1;
					            switch(choice1)
								{
									case 1:
										F.CHICKEN_PIECE(choice1);
										system("cls");
										cout<<"\n                                         1 PIECE DONE \n";
										break;
									case 2:
										F.CHICKEN_PIECE(choice1);
										system("cls");
										cout<<"\n                                         3 PIECE DONE \n";
										break;
									case 3:
										F.CHICKEN_PIECE(choice1);
										system("cls");
										cout<<"\n                                         5 PIECE DONE \n";
										break;
									case 4:
										F.CHICKEN_PIECE(choice1);
										system("cls");
										cout<<"\n                                         Family deal (12pc) DONE \n";
										break;
									case 5:
										system("cls");
										cout<<setw(50)<<"\n                       #####################################              EXIT CHICKEN PIECE              ##################################### \n ";
										break;
									default:
										system("cls");
										cout<<setw(50)<<"\n                                ########       WRONG INPUT      ########\n";
										
								}
							    }while(choice1 != 5);
							    break;
						case 7:
							system("cls");
								do{
					            cout<<"\n\n\n";
						        cout<<setw(50)<<"                                ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~             \n";
					            cout<<setw(50)<<"                                |             CHICKEN WINGS            |             \n";
					            cout<<setw(50)<<"                                |~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~|             \n";
					            cout<<setw(50)<<"                                |         1  .  MINI BUCKET (520)      |             \n";
					            cout<<setw(50)<<"                                |                                      |             \n";
					            cout<<setw(50)<<"                                |                                      |             \n";
					            cout<<setw(50)<<"                                |         2  .  FULL BUCKET (950)      |             \n";
					            cout<<setw(50)<<"                                |                                      |             \n";
					            cout<<setw(50)<<"                                |~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~|             \n";
					            cout<<setw(50)<<"                                |            3 . EXIT                  |             \n";
					            cout<<setw(50)<<"                                ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~             \n";
					            cout<<setw(40)<<"                                Choice : ";
					            cin>>choice1;
					            switch(choice1)
								{
									case 1:
										F.CHICKEN_WINGS(choice1);
										system("cls");
										cout<<"\n                                         MINI BUCKET (8pc) DONE\n";
										break;
									case 2:
										F.CHICKEN_WINGS(choice1);
										system("cls");
										cout<<"\n                                         FULL BUCKET (14pc) DONE\n";
										break;
									case 3:
										system("cls");
										cout<<setw(50)<<"\n                       #####################################              EXIT CHICKEN WINGS              ##################################### \n ";
										break;
									default:
										system("cls");
										cout<<setw(50)<<"\n                                ########       WRONG INPUT      ########\n";
										
								}
							    }while(choice1 != 3);
							    break;
						case 8:
							system("cls");
								do{
					            cout<<"\n\n\n";
						        cout<<setw(50)<<"                                ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~             \n";
					            cout<<setw(50)<<"                                |             CHICKEN NUGGETS          |             \n";
					            cout<<setw(50)<<"                                ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~             \n";
					            cout<<setw(50)<<"                                |         1  .  MINI BUCKET (650)      |             \n";
					            cout<<setw(50)<<"                                |                                      |             \n";
					            cout<<setw(50)<<"                                |                                      |             \n";
					            cout<<setw(50)<<"                                |         2  .  FULL BUCKET (1150)     |             \n";
					            cout<<setw(50)<<"                                |                                      |             \n";
					            cout<<setw(50)<<"                                ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~             \n";
					            cout<<setw(50)<<"                                |            3 . EXIT                  |             \n";
					            cout<<setw(50)<<"                                ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~             \n";
					            cout<<setw(40)<<"                                Choice : ";
					            cin>>choice1;
					            switch(choice1)
								{
									case 1:
										F.CHICKEN_NUGGETS(choice1);
										system("cls");
										cout<<"\n                                         MINI BUCKET (8pc) DONE\n";
										break;
									case 2:
										F.CHICKEN_NUGGETS(choice1);
										system("cls");
										cout<<"\n                                         FULL BUCKET (14pc) DONE\n";
										break;
									case 3:
										system("cls");
										cout<<setw(50)<<"\n                       ####################################              EXIT CHICKEN NUGGETS              #################################### \n ";
										break;
									default:
										system("cls");
										cout<<setw(50)<<"\n                                ########       WRONG INPUT      ########\n";
										
								}
							    }while(choice1 != 3);
							    break;
						case 9:
							system("cls");
								do{
					            cout<<"\n\n\n";
						        cout<<setw(50)<<"                                ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~             \n";
					            cout<<setw(50)<<"                                |             HOT & SPICY              |             \n";
					            cout<<setw(50)<<"                                ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~             \n";
					            cout<<setw(50)<<"                                |         1  .  MINI BUCKET (600)      |             \n";
					            cout<<setw(50)<<"                                |                                      |             \n";
					            cout<<setw(50)<<"                                |                                      |             \n";
					            cout<<setw(50)<<"                                |         2  .  FULL BUCKET (1050)     |             \n";
					            cout<<setw(50)<<"                                |                                      |             \n";
					            cout<<setw(50)<<"                                ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~             \n";
					            cout<<setw(50)<<"                                |            3 . EXIT                  |             \n";
					            cout<<setw(50)<<"                                ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~             \n";
					            cout<<setw(40)<<"                                Choice : ";
					            cin>>choice1;
					            switch(choice1)
								{
									case 1:
										cout<<"                                MINI BUCKET (8pc) \n";
										F.CHICKEN_HOT_SPICY(choice1);
										system("cls");
										cout<<"\n                                         MINI BUCKET (8pc) DONE\n";
										break;
									case 2:
										cout<<"                                FULL BUCKET (14pc) \n";
										F.CHICKEN_HOT_SPICY(choice1);
										system("cls");
										cout<<"\n                                         FULL BUCKET (14pc) DONE\n";
										break;
									case 3:
										system("cls");
										cout<<setw(50)<<"\n                       ######################################              EXIT HOT & SPICY              ###################################### \n ";
										break;
									default:
										system("cls");
										cout<<setw(50)<<"\n                                ########       WRONG INPUT      ########\n";
										
								}
							    }while(choice1 != 3);
							    break;
						case 10:
							system("cls");
								do{
					            cout<<"\n\n\n";
						        cout<<setw(50)<<"                                ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~             \n";
					            cout<<setw(50)<<"                                |                  BBQ                 |             \n";
					            cout<<setw(50)<<"                                |~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~|             \n";
					            cout<<setw(50)<<"                                |         1  .  1 PIECE (120)          |             \n";
					            cout<<setw(50)<<"                                |                                      |             \n";
					            cout<<setw(50)<<"                                |                                      |             \n";
					            cout<<setw(50)<<"                                |         2  .  3 PIECE (320)          |             \n";
					            cout<<setw(50)<<"                                |                                      |             \n";
					            cout<<setw(50)<<"                                |                                      |             \n";
					            cout<<setw(50)<<"                                |         3  .  5 PIECE (550)          |             \n";
					            cout<<setw(50)<<"                                |                                      |             \n";
					            cout<<setw(50)<<"                                |                                      |             \n";
					            cout<<setw(50)<<"                                |         4  .  10pc Family deal (950) |             \n";
					            cout<<setw(50)<<"                                |                                      |             \n";
					            cout<<setw(50)<<"                                |~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~|             \n";
					            cout<<setw(50)<<"                                |            5 . EXIT                  |             \n";
					            cout<<setw(50)<<"                                ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~             \n";
					            cout<<setw(40)<<"                                Choice : ";
					            cin>>choice1;
					            switch(choice1)
								{
									case 1:
										F.BBQ(choice1);
										system("cls");
										cout<<"\n                                         1 PIECE DONE \n";
										break;
									case 2:
										cout<<"                                3 PIECE \n";
										F.BBQ(choice1);
										system("cls");
										cout<<"\n                                         3 PIECE DONE \n";
										break;
									case 3:
										cout<<"                                5 PIECE \n";
										F.BBQ(choice1);
										system("cls");
										cout<<"\n                                         5 PIECE DONE \n";
										break;
									case 4:
										cout<<"                                Family deal (12pc) \n";
										F.BBQ(choice1);
										system("cls");
										cout<<"\n                                         Family deal (10pc) DONE \n";
										break;
									case 5:
										system("cls");
										cout<<setw(50)<<"\n                       #######################################              EXIT BARBIE KU              ####################################### \n ";
										break;
									default:
										system("cls");
										cout<<setw(50)<<"\n                                ########       WRONG INPUT      ########\n";
										
								}
							    }while(choice1 != 5);
							    break;
						case 11:
							system("cls");
								do{
					            cout<<"\n\n\n";
					            cout<<setw(50)<<"                                ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n";
					            cout<<setw(50)<<"                                |                 PASTA                |    SIZE     |\n";
					            cout<<setw(50)<<"                                ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~|~~~~~~~~~~~~~|\n";
					            cout<<setw(50)<<"                                |         1  .  CRUNCH (S/L)           | Small  650  |\n";
					            cout<<setw(50)<<"                                |                                      | Large  850  |\n";
					            cout<<setw(50)<<"                                |                                      |~~~~~~~~~~~~~|\n";
					            cout<<setw(50)<<"                                |         2  .  CHEESE LOADER (S/L)    | Small  750  |\n";
					            cout<<setw(50)<<"                                |                                      | Large  950  |\n";
					            cout<<setw(50)<<"                                ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~|\n";
					            cout<<setw(50)<<"                                |                      3 . EXIT                      |\n";
					            cout<<setw(50)<<"                                ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n";
					            cout<<setw(40)<<"                                Choice : ";
					            cin>>choice1;
					            switch(choice1)
								{
									case 1:
										cout<<"                                CRUNCH (S/L) \n";
										cout<<"                                SIZE (S/L) : ";
										cin>>s;
										cout<<"                                Quantity : ";
										cin>>quantity;
										F.Pasta(choice1,s,quantity);
										system("cls");
										cout<<"\n                                        "<<quantity<<" CRUNCH PASTA DONE \n";
										break;
									case 2:
										cout<<"                                CHEESE LOADER (S/L) \n";
										cout<<"                                SIZE (S/L) : ";
										cin>>s;
										cout<<"                                Quantity : ";
										cin>>quantity;
										F.Pasta(choice1,s,quantity);
										system("cls");
										cout<<"\n                                        "<<quantity<<" CHEESE LOADER DONE \n";
										break;
									case 3:
										system("cls");
										cout<<setw(50)<<"\n                       #########################################              EXIT PASTA              ######################################### \n ";
										break;
									default:
										system("cls");
										cout<<setw(50)<<"\n                                ########       WRONG INPUT      ########\n";
										
								}
							    }while(choice1 != 3);
							    break;
						case 12:
							system("cls");
								do{
					            cout<<"\n\n\n";
						        cout<<setw(50)<<"                                ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~             \n";
					            cout<<setw(50)<<"                                |              DRUM STICK              |             \n";
					            cout<<setw(50)<<"                                ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~             \n";
					            cout<<setw(50)<<"                                |         1  .  1 STICK  (160)         |             \n";
					            cout<<setw(50)<<"                                |                                      |             \n";
					            cout<<setw(50)<<"                                |                                      |             \n";
					            cout<<setw(50)<<"                                |         2  .  3 STICK  (450)         |             \n";
					            cout<<setw(50)<<"                                |                                      |             \n";
					            cout<<setw(50)<<"                                |                                      |             \n";
					            cout<<setw(50)<<"                                |         3  .  5 STICK  (750)         |             \n";
					            cout<<setw(50)<<"                                |                                      |             \n";
					            cout<<setw(50)<<"                                |                                      |             \n";
					            cout<<setw(50)<<"                                |         4  .  10pc Family deal (1450)|             \n";
					            cout<<setw(50)<<"                                |                                      |             \n";
					            cout<<setw(50)<<"                                ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~             \n";
					            cout<<setw(50)<<"                                |            5 . EXIT                  |             \n";
					            cout<<setw(50)<<"                                ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~             \n";
					            cout<<setw(40)<<"                                Choice : ";
					            cin>>choice1;
					            switch(choice1)
								{
									case 1:
										F.DRUM_STICK(choice1);
										system("cls");
										cout<<"\n                                         1 DRUM STICK DONE \n";
										break;
									case 2:
										F.DRUM_STICK(choice1);
										system("cls");
										cout<<"\n                                         3 DRUM STICK DONE \n";
										break;
									case 3:
										F.DRUM_STICK(choice1);
										system("cls");
										cout<<"\n                                         5 DRUM STICK DONE \n";
										break;
									case 4:
										F.DRUM_STICK(choice1);
										system("cls");
										cout<<"\n                                         Family deal (10pc) DONE \n";
										break;
									case 5:
										system("cls");
										cout<<setw(50)<<"\n                       ######################################               EXIT DRUM STICK              ###################################### \n ";
										break;
									default:
										system("cls");
										cout<<setw(50)<<"\n                                ########       WRONG INPUT      ########\n";
										
								}
							    }while(choice1 != 5);
							    break;
							    
						case 13:
							system("cls");
								do{
					            cout<<"\n\n\n";
					            cout<<setw(50)<<"                                ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n";
					            cout<<setw(50)<<"                                |                 SOMASA               |    SIZE     |\n";
					            cout<<setw(50)<<"                                ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~|~~~~~~~~~~~~~|\n";
					            cout<<setw(50)<<"                                |         1  .  CHICKEN SOMASA         | 1 piece 90  |\n";
					            cout<<setw(50)<<"                                |                                      |             |\n";
					            cout<<setw(50)<<"                                |                                      |~~~~~~~~~~~~~|\n";
					            cout<<setw(50)<<"                                |         2  .  ALLU SOMASA            | 1 piece 60  |\n";
					            cout<<setw(50)<<"                                |                                      |             |\n";
					            cout<<setw(50)<<"                                ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~|\n";
					            cout<<setw(50)<<"                                |                      3 . EXIT                      |\n";
					            cout<<setw(50)<<"                                ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n";
					            cout<<setw(40)<<"                                Choice : ";
					            cin>>choice1;
					            switch(choice1)
								{
									case 1:
										cout<<"                                CHICKEN SOMASA \n";
										cout<<"                                Amount : ";
										cin>>quantity;
										F.SOMASA(choice1,quantity);
										system("cls");
										cout<<"\n                                        "<<quantity<<" CHICKEN SOMASA DONE \n";
										break;
									case 2:
										cout<<"                                ALLU SOMASA \n";
										cout<<"                                Amount : ";
										cin>>quantity;
										F.SOMASA(choice1,quantity);
										system("cls");
										cout<<"\n                                        "<<quantity<<" ALLU SOMASA DONE \n";
										break;
									case 3:
										system("cls");
										cout<<setw(50)<<"\n                       ########################################               EXIT SOMASA              ######################################## \n ";
										break;
									default:
										system("cls");
										cout<<setw(50)<<"\n                                ########       WRONG INPUT      ########\n";
										
								}
							    }while(choice1 != 3);
							    break;
						case 14:
							system("cls");
								do{
					            cout<<"\n\n\n";
						        cout<<setw(50)<<"                                ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n";
					            cout<<setw(50)<<"                                |              ROLL PRATHA             |    SIZE     |\n";
					            cout<<setw(50)<<"                                |~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~|~~~~~~~~~~~~~|\n";
					            cout<<setw(50)<<"                                |         1  .  ZINGER (S/L)           | Small  190  |\n";
					            cout<<setw(50)<<"                                |                                      | Large  310  |\n";
					            cout<<setw(50)<<"                                |                                      |~~~~~~~~~~~~~|\n";
					            cout<<setw(50)<<"                                |         2  .  CHICKEN  (S/L)         | Small  150  |\n";
					            cout<<setw(50)<<"                                |                                      | Large  210  |\n";
					            cout<<setw(50)<<"                                |                                      |~~~~~~~~~~~~~|\n";
					            cout<<setw(50)<<"                                |         3  .  CHEESE (S/L)           | Small  220  |\n";
					            cout<<setw(50)<<"                                |                                      | Large  350  |\n";
					            cout<<setw(50)<<"                                |                                      |~~~~~~~~~~~~~|\n";
					            cout<<setw(50)<<"                                |         4  .  A & Z SPECIAL (S/L)    | Small  300  |\n";
					            cout<<setw(50)<<"                                |                                      | Large  400  |\n";
					            cout<<setw(50)<<"                                |~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~|\n";
					            cout<<setw(50)<<"                                |                       5 . EXIT                     |\n";
					            cout<<setw(50)<<"                                ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n";
					            cout<<setw(40)<<"                                Choice : ";
					            cin>>choice1;
					            switch(choice1)
								{
									case 1:
										cout<<"                                ZINGER \n";
										cout<<"                                SIZE (S/L) : ";
										cin>>s;
										cout<<"                                Quantity : ";
										cin>>quantity;
										F.ROLL_PARATHA(choice1,s,quantity);
										system("cls");
										cout<<"\n                                        "<<quantity<<" ZINGER ROLL PRATHA DONE \n";
										break;
									case 2:
										cout<<"                                CHICKEN \n";
										cout<<"                                SIZE (S/L) : ";
										cin>>s;
										cout<<"                                Quantity : ";
										cin>>quantity;
										F.ROLL_PARATHA(choice1,s,quantity);
										system("cls");
										cout<<"\n                                        "<<quantity<<" CHICKEN ROLL PRATHA DONE \n";
										break;
									case 3:
										cout<<"                                CHEESE \n";
										cout<<"                                SIZE (S/L) : ";
										cin>>s;
										cout<<"                                Quantity : ";
										cin>>quantity;
										F.ROLL_PARATHA(choice1,s,quantity);
										system("cls");
										cout<<"\n                                        "<<quantity<<" CHEESE ROLL PRATHA DONE \n";
										break;
									case 4:
										cout<<"                                A & Z SPECIAL \n";
										cout<<"                                SIZE (S/L) : ";
										cin>>s;
										cout<<"                                Quantity : ";
										cin>>quantity;
										F.ROLL_PARATHA(choice1,s,quantity);
										system("cls");
										cout<<"\n                                        "<<quantity<<" A & Z SPECIAL ROLL PRATHA DONE \n";
										break;
									case 5:
										system("cls");
										cout<<setw(50)<<"\n                       ######################################              EXIT ROLL PRATHA              ###################################### \n ";
										break;
									default:
										system("cls");
										cout<<setw(50)<<"\n                                ########       WRONG INPUT      ########\n";
										
								}
							    }while(choice1 != 5);
							    break;
						case 15:
							system("cls");
								do{
					            cout<<"\n\n\n";
					            cout<<setw(50)<<"                                ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n";
					            cout<<setw(50)<<"                                |                 PASTA                |    SIZE     |\n";
					            cout<<setw(50)<<"                                ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~|~~~~~~~~~~~~~|\n";
					            cout<<setw(50)<<"                                |         1  .  FRUIT CHAT (S/L)       | Small  160  |\n";
					            cout<<setw(50)<<"                                |                                      | Large  230  |\n";
					            cout<<setw(50)<<"                                |                                      |~~~~~~~~~~~~~|\n";
					            cout<<setw(50)<<"                                |         2  .  CHANA CHAT (S/L)       | Small  170  |\n";
					            cout<<setw(50)<<"                                |                                      | Large  240  |\n";
					            cout<<setw(50)<<"                                |                                      |~~~~~~~~~~~~~|\n";
					            cout<<setw(50)<<"                                |         3  .  PAPARI CHAT (S/L)      | Small  180  |\n";
					            cout<<setw(50)<<"                                |                                      | Large  250  |\n";
					            cout<<setw(50)<<"                                ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~|\n";
					            cout<<setw(50)<<"                                |                      4 . EXIT                      |\n";
					            cout<<setw(50)<<"                                ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n";
					            cout<<setw(40)<<"                                Choice : ";
					            cin>>choice1;
					            switch(choice1)
								{
									case 1:
										cout<<"                                FRUIT CHAT (S/L) \n";
										cout<<"                                Quantity : ";
										cin>>quantity;
										system("cls");
										cout<<"\n                                        "<<quantity<<" FRUIT CHAT DONE \n";
										break;
									case 2:
										cout<<"                                CHANA CHAT (S/L) \n";
										cout<<"                                Quantity : ";
										cin>>quantity;
										system("cls");
										cout<<"\n                                        "<<quantity<<" CHANA CHAT DONE \n";
										break;
									case 3:
										cout<<"                                PAPARI CHAT (S/L) \n";
										cout<<"                                Quantity : ";
										cin>>quantity;
										system("cls");
										cout<<"\n                                        "<<quantity<<" PAPARI CHAT DONE \n";
										break;
									case 4:
										system("cls");
										cout<<setw(50)<<"\n                       #########################################              EXIT CHAT              ######################################### \n ";
										break;
									default:
										system("cls");
										cout<<setw(50)<<"\n                                ########       WRONG INPUT      ########\n";		
								}
							    }while(choice1 != 4);
							    break;
						case 16:
							system("cls");
							cout<<setw(50)<<"\n                                ###################              EXIT FAST FOOD              ###################### \n ";
							break;
						default:
							system("cls");
							cout<<setw(50)<<"\n                       #######################################                WRONG INPUT               ####################################### \n ";	    
					    }
						}while(choice != 16);
					}
					else if (choice==2)
					{
					system("cls");
						do{
					    cout<<"\n\n\n";
						cout<<setw(50)<<"                       ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~  \n";
					    cout<<setw(50)<<"                       |                                                      DESI FOOD                                                       |  \n";
					    cout<<setw(50)<<"                       ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~  \n";
					    cout<<setw(50)<<"                       |                     1  .  CHICKEN                        |                     6  .  DAAL                            |  \n";
					    cout<<setw(50)<<"                       |                                                          |                                                           |  \n";
					    cout<<setw(50)<<"                       |                                                          |                                                           |  \n";
					    cout<<setw(50)<<"                       |                     2  .  MUTTON                         |                     7  .  BIRYANI                         |  \n";
					    cout<<setw(50)<<"                       |                                                          |                                                           |  \n";
					    cout<<setw(50)<<"                       |                                                          |                                                           |  \n";
					    cout<<setw(50)<<"                       |                     3  .  BEEF                           |                     8  .  PULAO                           |  \n";
					    cout<<setw(50)<<"                       |                                                          |                                                           |  \n";
					    cout<<setw(50)<<"                       |                                                          |                                                           |  \n";
					    cout<<setw(50)<<"                       |                     4  .  SABBZI                         |                     9  .  ROTI/PRATHA                     |  \n";
					    cout<<setw(50)<<"                       |                                                          |                                                           |  \n";
					    cout<<setw(50)<<"                       |                                                          |                                                           |  \n";
					    cout<<setw(50)<<"                       |                     5  .  FISH                           |                    10  .  RAYATA/SALAD                      |  \n";
					    cout<<setw(50)<<"                       |                                                          |                                                           |  \n";
					    cout<<setw(50)<<"                       ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~  \n";
					    cout<<setw(50)<<"                       |                                                      11 . EXIT                                                       |  \n";
					    cout<<setw(50)<<"                       ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~  \n";
					    cout<<setw(40)<<"                       Choice : ";
					    cin>>choice;
					    switch(choice)
						{
							case 1:
								system("cls");
								do{
					            cout<<"\n\n\n";
						        cout<<setw(50)<<"                                ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n";
					            cout<<setw(50)<<"                                |                 CHICKEN              |     SIZE    |\n";
					            cout<<setw(50)<<"                                ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~|~~~~~~~~~~~~~|\n";
					            cout<<setw(50)<<"                                |         1  .  SIMPLE KARAHI (F/H)    |  FULL 1200  |\n";
					            cout<<setw(50)<<"                                |                                      |  HALF 600   |\n";
					            cout<<setw(50)<<"                                |                                      |~~~~~~~~~~~~~|\n";
					            cout<<setw(50)<<"                                |         2  .  WHITE KARAHI (F/H)     |  FULL 1300  |\n";
					            cout<<setw(50)<<"                                |                                      |  HALF 700   |\n";
					            cout<<setw(50)<<"                                |                                      |~~~~~~~~~~~~~|\n";
					            cout<<setw(50)<<"                                |         3  .  BBQ KARAHI (F/H)       |  FULL 1300  |\n";
					            cout<<setw(50)<<"                                |                                      |  HALF 700   |\n";
					            cout<<setw(50)<<"                                |                                      |~~~~~~~~~~~~~|\n";
					            cout<<setw(50)<<"                                |         4  .  CHICKEN ROAST (F/H)    |  FULL 1200  |\n";
					            cout<<setw(50)<<"                                |                                      |  HALF 900   |\n";
					            cout<<setw(50)<<"                                |                                      |~~~~~~~~~~~~~|\n";
					            cout<<setw(50)<<"                                |         5  .  CHICKEN SAJI (F/H)     |  FULL 1200  |\n";
					            cout<<setw(50)<<"                                |                                      |  HALF 600   |\n";
					            cout<<setw(50)<<"                                ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n";
					            cout<<setw(50)<<"                                |                         6 . EXIT                    \n";
					            cout<<setw(50)<<"                                ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n";
					            cout<<setw(40)<<"                                Choice : ";
					            cin>>choice1;
					            switch(choice1)
								{
									case 1:
										quantity=0;
										cout<<"                                SIMPLE KARAHI \n";
										cout<<"                                FULL/HALF(F/H) : ";
										cin>>s;
										cout<<"                                QUANTITY \n";
										cin>> quantity;
										F.CHICKEN(choice1,s,quantity);
										system("cls");
										cout<<"                                        "<<quantity<<" "<<s<<" SIMPLE KARAHI DONE \n"; 
										break;
									case 2:
										quantity=0;
										cout<<"                                WHITE KARAHI (F/H)\n";
										cout<<"                                FULL/HALF(F/H) : ";
										cin>>s;
										cout<<"                                QUANTITY \n";
										cin>> quantity;
										F.CHICKEN(choice1,s,quantity);
										system("cls");
										cout<<"                                        "<<quantity<<" "<<s<<" WHITE KARAHI DONE \n";
										break;
									case 3:
										quantity=0;
										cout<<"                                BBQ KARAHI (F/H)\n";
										cout<<"                                FULL/HALF(F/H) : ";
										cin>>s;
										cout<<"                                QUANTITY \n";
										cin>> quantity;
										F.CHICKEN(choice1,s,quantity);
										system("cls");
										cout<<"                                        "<<quantity<<" "<<s<<" BBQ KARAHI DONE \n";
										break;
									case 4:
										quantity=0;
										cout<<"                                CHICKEN ROAST (F/H)\n";
										cout<<"                                FULL/HALF(F/H) : ";
										cin>>s;
										cout<<"                                QUANTITY \n";
										cin>> quantity;
										F.CHICKEN(choice1,s,quantity);
										system("cls");
										cout<<"                                        "<<quantity<<" "<<s<<" CHICKEN ROAST DONE \n";
										break;
									case 5:
										quantity=0;
										cout<<"                                CHICKEN SAJI\n";
										cout<<"                                FULL/HALF(F/H) : ";
										cin>>s;
										cout<<"                                QUANTITY \n";
										cin>> quantity;
										F.CHICKEN(choice1,s,quantity);
										system("cls");
										cout<<"                                        "<<quantity<<" "<<s<<" CHICKEN SAJI DONE \n";
										break;
									case 6:
										system("cls");
										cout<<setw(50)<<"\n                       #####################################              EXIT CHICKEN MENU              #################################### \n ";
										break;
									default:
										system("cls");
										cout<<setw(50)<<"\n                                ########       WRONG INPUT      ########\n";
										
								}
							    }while(choice1 != 6);
							    break;
						case 2:
								system("cls");
								do{
					            cout<<"\n\n\n";
						        cout<<setw(50)<<"                                ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n";
					            cout<<setw(50)<<"                                |                 MUTTON               |     SIZE    |\n";
					            cout<<setw(50)<<"                                ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~|\n";
					            cout<<setw(50)<<"                                |         1  .  SIMPLE KARAHI (F/H)    |  FULL 1400  |\n";
					            cout<<setw(50)<<"                                |                                      |  HALF 700   |\n";
					            cout<<setw(50)<<"                                |                                      |~~~~~~~~~~~~~|\n";
					            cout<<setw(50)<<"                                |         2  .  WHITE KARAHI (F/H)     |  FULL 1600  |\n";
					            cout<<setw(50)<<"                                |                                      |  HALF 800   |\n";
					            cout<<setw(50)<<"                                |                                      |~~~~~~~~~~~~~|\n";
					            cout<<setw(50)<<"                                |         3  .  BBQ KARAHI (F/H)       |  FULL 1200  |\n";
					            cout<<setw(50)<<"                                |                                      |  HALF 600   |\n";
					            cout<<setw(50)<<"                                |                                      |~~~~~~~~~~~~~|\n";
					            cout<<setw(50)<<"                                |         4  .  MUTTON ROAST (F/H)     |  FULL 1400  |\n";
					            cout<<setw(50)<<"                                |                                      |  HALF 700   |\n";
					            cout<<setw(50)<<"                                |                                      |~~~~~~~~~~~~~|\n";
					            cout<<setw(50)<<"                                |         5  .  MUTTON SAJI (F/H)      |  FULL 1400  |\n";
					            cout<<setw(50)<<"                                |                                      |  HALF 700   |\n";
					            cout<<setw(50)<<"                                ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~|\n";
					            cout<<setw(50)<<"                                |                          6 . EXIT                  |\n";
					            cout<<setw(50)<<"                                ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~|\n";
					            cout<<setw(40)<<"                                Choice : ";
					            cin>>choice1;
					            switch(choice1)
								{
									case 1:
										quantity=0;
										cout<<"                                SIMPLE KARAHI (F/H)\n";
										cout<<"                                FULL/HALF(F/H) : ";
										cin>>s;
										cout<<"                                QUANTITY \n";
										cin>> quantity;
										F.MUTTON(choice1,s,quantity);
										system("cls");
										cout<<"                                        "<<quantity<<" "<<s<<" SIMPLE KARAHI DONE \n"; 
										break;
									case 2:
										quantity=0;
										cout<<"                                WHITE KARAHI (F/H)\n";
										cout<<"                                FULL/HALF(F/H) : ";
										cin>>s;
										cout<<"                                QUANTITY \n";
										cin>> quantity;
										F.MUTTON(choice1,s,quantity);
										system("cls");
										cout<<"                                        "<<quantity<<" "<<s<<" WHITE KARAHI DONE \n";
										break;
									case 3:
										quantity=0;
										cout<<"                                BBQ KARAHI (F/H)\n";
										cout<<"                                FULL/HALF(F/H) : ";
										cin>>s;
										cout<<"                                QUANTITY \n";
										cin>> quantity;
										F.MUTTON(choice1,s,quantity);
										system("cls");
										cout<<"                                        "<<quantity<<" "<<s<<" BBQ KARAHI DONE \n";
										break;
									case 4:
										quantity=0;
										cout<<"                                MUTTON ROAST (F/H)\n";
										cout<<"                                FULL/HALF(F/H) : ";
										cin>>s;
										cout<<"                                QUANTITY \n";
										cin>> quantity;
										F.MUTTON(choice1,s,quantity);
										system("cls");
										cout<<"                                        "<<quantity<<" "<<s<<" MUTTON ROAST DONE \n";
										break;
									case 5:
										quantity=0;
										cout<<"                                MUTTON SAJI\n";
										cout<<"                                FULL/HALF(F/H) : ";
										cin>>s;
										cout<<"                                QUANTITY \n";
										cin>> quantity;
										F.MUTTON(choice1,s,quantity);
										system("cls");
										cout<<"                                        "<<quantity<<" "<<s<<" MUTTON SAJI DONE \n";
										break;
									case 6:
										system("cls");
										cout<<setw(50)<<"\n                       ######################################              EXIT MUTTON MENU              #################################### \n ";
										break;
									default:
										system("cls");
										cout<<setw(50)<<"\n                                ########       WRONG INPUT      ########\n";
										
								}
													
							    }
								while(choice1 != 6);
							    break;
						case 3:
								system("cls");
								do{
					            cout<<"\n\n\n";
						        cout<<setw(50)<<"                                ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n";
					            cout<<setw(50)<<"                                |                  BEEF                |     SIZE    |\n";
					            cout<<setw(50)<<"                                ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n";
					            cout<<setw(50)<<"                                |         1  .  SIMPLE KARAHI (F/H)    |   FULL 1300 |\n";
					            cout<<setw(50)<<"                                |                                      |   HALF 650  |\n";
					            cout<<setw(50)<<"                                |                                      |~~~~~~~~~~~~~|\n";
					            cout<<setw(50)<<"                                |         2  .  WHITE KARAHI (F/H)     |   FULL 1300 |\n";
					            cout<<setw(50)<<"                                |                                      |   HALF 650  |\n";
					            cout<<setw(50)<<"                                |                                      |~~~~~~~~~~~~~|\n";
					            cout<<setw(50)<<"                                |         3  .  BBQ KARAHI (F/H)       |   FULL 1300 |\n";
					            cout<<setw(50)<<"                                |                                      |   HALF 650  |\n";
					            cout<<setw(50)<<"                                |                                      |~~~~~~~~~~~~~|\n";
					            cout<<setw(50)<<"                                |         4  .  BEEF ROAST (F/H)       |   FULL 1300 |\n";
					            cout<<setw(50)<<"                                |                                      |   HALF 650  |\n";
					            cout<<setw(50)<<"                                ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~|\n";
					            cout<<setw(50)<<"                                |                        5 . EXIT                    |\n";
					            cout<<setw(50)<<"                                ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~|\n";
					            cout<<setw(40)<<"                                Choice : ";
					            cin>>choice1;
					            switch(choice1)
								{
									case 1:
										quantity=0;
										cout<<"                                SIMPLE KARAHI (F/H)\n";
										cout<<"                                FULL/HALF(F/H) : ";
										cin>>s;
										cout<<"                                QUANTITY \n";
										cin>> quantity;
										F.BEEF(choice1,s,quantity);
										system("cls");
										cout<<"                                        "<<quantity<<" "<<s<<" SIMPLE KARAHI DONE \n"; 
										break;
									case 2:
										quantity=0;
										cout<<"                                WHITE KARAHI (F/H)\n";
										cout<<"                                FULL/HALF(F/H) : ";
										cin>>s;
										cout<<"                                QUANTITY \n";
										cin>> quantity;
										F.BEEF(choice1,s,quantity);
										system("cls");
										cout<<"                                        "<<quantity<<" "<<s<<" WHITE KARAHI DONE \n";
										break;
									case 3:
										quantity=0;
										cout<<"                                BBQ KARAHI (F/H)\n";
										cout<<"                                FULL/HALF(F/H) : ";
										cin>>s;
										cout<<"                                QUANTITY \n";
										cin>> quantity;
										F.BEEF(choice1,s,quantity);
										system("cls");
										cout<<"                                        "<<quantity<<" "<<s<<" BBQ KARAHI DONE \n";
										break;
									case 4:
										quantity=0;
										cout<<"                                BEEF ROAST (F/H)\n";
										cout<<"                                FULL/HALF(F/H) : ";
										cin>>s;
										cout<<"                                QUANTITY \n";
										cin>> quantity;
										F.BEEF(choice1,s,quantity);
										system("cls");
										cout<<"                                        "<<quantity<<" "<<s<<" BEEF ROAST DONE \n";
										break;
									case 5:
										system("cls");
										cout<<setw(50)<<"\n                       #######################################              EXIT BEEF MENU              ##################################### \n ";
										break;
									default:
										system("cls");
										cout<<setw(50)<<"\n                                ########       WRONG INPUT      ########\n";
										
								}
							    }while(choice1 != 5);
							    break;
						case 4:
								system("cls");
								do{
					            cout<<"\n\n\n";
						        cout<<setw(50)<<"                                ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n";
					            cout<<setw(50)<<"                                |                  SABZI               |     SIZE     |\n";
					            cout<<setw(50)<<"                                ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n";
					            cout<<setw(50)<<"                                |         1  .  GOBY (S/D)             | SINGLE 150   |\n";
					            cout<<setw(50)<<"                                |                                      | DOUBLE 300   |\n";
					            cout<<setw(50)<<"                                |                                      |~~~~~~~~~~~~~~|\n";
					            cout<<setw(50)<<"                                |         2  .  PALAK (S/D)            | SINGLE 200   |\n";
					            cout<<setw(50)<<"                                |                                      | DOUBLE 350   |\n";
					            cout<<setw(50)<<"                                |                                      |~~~~~~~~~~~~~~|\n";
					            cout<<setw(50)<<"                                |         3  .  ALLU MATAR (S/D)       | SINGLE 170   |\n";
					            cout<<setw(50)<<"                                |                                      | DOUBLE 280   |\n";
					            cout<<setw(50)<<"                                |                                      |~~~~~~~~~~~~~~|\n";
					            cout<<setw(50)<<"                                |         4  .  MIX SABZI (S/D)        | SINGLE 250   |\n";
					            cout<<setw(50)<<"                                |                                      | DOUBLE 400   |\n";
					            cout<<setw(50)<<"                                ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~|\n";
					            cout<<setw(50)<<"                                |                         5 . EXIT                    |\n";
					            cout<<setw(50)<<"                                ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n";
					            cout<<setw(40)<<"                                Choice : ";
					            cin>>choice1;
					            switch(choice1)
								{
									case 1:
										quantity=0;
										cout<<"                                GOBY (S/D)\n";
										cout<<"                                Single/Double(S/D) : ";
                                        cin>>s;
										cout<<"                                QUANTITY \n";
										cin>> quantity;
										F.SABZI(choice1,s,quantity);
										system("cls");
										cout<<"                                        "<<quantity<<" "<<s<<" GOBY DONE \n"; 
										break;
									case 2:
										quantity=0;
										cout<<"                                PALAK (S/D)\n";
										cout<<"                                Single/Double(S/D) : ";
                                        cin>>s;
										cout<<"                                QUANTITY \n";
										cin>> quantity;
										F.SABZI(choice1,s,quantity);	
										system("cls");
										cout<<"                                        "<<quantity<<" "<<s<<" PALAK DONE \n";
										break;
									case 3:
										quantity=0;
										cout<<"                                ALLU MATAR (S/D)\n";
										cout<<"                                Single/Double(S/D) : ";
										cin>>s;
										cout<<"                                QUANTITY \n";
										cin>> quantity;
										F.SABZI(choice1,s,quantity);
										system("cls");
										cout<<"                                        "<<quantity<<" "<<s<<" ALLU MATAR DONE \n";
										break;
									case 4:
										quantity=0;
										cout<<"                                MIX (S/D)\n";
										cout<<"                                Single/Double(S/D) : ";
										cin>>s;
										cout<<"                                QUANTITY \n";
										cin>> quantity;
										F.SABZI(choice1,s,quantity);
										system("cls");
										cout<<"                                        "<<quantity<<" "<<s<<" MIX SABBZI DONE \n";
										break;
									case 5:
										system("cls");
										cout<<setw(50)<<"\n                       #########################################               EXIT SABBZI MENU              ####################################### \n ";
										break;
									default:
										system("cls");
										cout<<setw(50)<<"\n                                ########       WRONG INPUT      ########\n";		
								}
							    }while(choice1 != 5);
							    break;
						case 5:
								system("cls");
								do{
					            cout<<"\n\n\n";
						        cout<<setw(50)<<"                                ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n";
					            cout<<setw(50)<<"                                |                  FISH                |      SIZE     |\n";
					            cout<<setw(50)<<"                                ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n";
					            cout<<setw(50)<<"                                |         1  .  FISH KARAHI (F/H)      |  FULL 1700    |\n";
					            cout<<setw(50)<<"                                |                                      |  HALF 800     |\n";
					            cout<<setw(50)<<"                                |                                      |~~~~~~~~~~~~~~~|\n";
					            cout<<setw(50)<<"                                |         2  .  RAU FRY(F/H)           |  FULL 1700    |\n";
					            cout<<setw(50)<<"                                |                                      |  HALF 800     |\n";
					            cout<<setw(50)<<"                                |                                      |~~~~~~~~~~~~~~~|\n";
					            cout<<setw(50)<<"                                |         3  .  TUNA FRY (F/H)         |  FULL 1700    |\n";
					            cout<<setw(50)<<"                                |                                      |  HALF 800     |\n";
					            cout<<setw(50)<<"                                |                                      |~~~~~~~~~~~~~~~|\n";
					            cout<<setw(50)<<"                                |         4  .  MAHI FRY (F/H)         |  FULL 1700    |\n";
					            cout<<setw(50)<<"                                |                                      |  HALF 800     |\n";
					            cout<<setw(50)<<"                                |                                      |~~~~~~~~~~~~~~~|\n";
					            cout<<setw(50)<<"                                |         5  .  FINGER FISH (F/H)      |  FULL 1700    |\n";
					            cout<<setw(50)<<"                                |                                      |  HALF 800     |\n";
					            cout<<setw(50)<<"                                ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~|\n";
					            cout<<setw(50)<<"                                |                          6 . EXIT                    |\n";
					            cout<<setw(50)<<"                                ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~|\n";
					            cout<<setw(40)<<"                                Choice : ";
					            cin>>choice1;
					            switch(choice1)
								{
									case 1:
										quantity=0;
										cout<<"                                FISH KARAHI (F/H)\n";
										cout<<"                                FULL/HALF(F/H) : ";
										cin>>s;
										cout<<"                                QUANTITY \n";
										cin>> quantity;
										F.Fish(choice1,s,quantity);
										system("cls");
										cout<<"                                        "<<quantity<<" "<<s<<" FISH KARAHI DONE \n"; 
										break;
									case 2:
										quantity=0;
										cout<<"                                RAU FRY (F/H)\n";
										cout<<"                                FULL/HALF(F/H) : ";
										cin>>s;
										cout<<"                                QUANTITY \n";
										cin>> quantity;
									    F.Fish(choice1,s,quantity);
										system("cls");
										cout<<"                                        "<<quantity<<" "<<s<<" RAU FRY DONE \n";
										break;
									case 3:
										quantity=0;
										cout<<"                                TUNA FRY (F/H)\n";
										cout<<"                                FULL/HALF(F/H) : ";
										cin>>s;
										cout<<"                                QUANTITY \n";
										cin>> quantity;
										F.Fish(choice1,s,quantity);
										system("cls");
										cout<<"                                        "<<quantity<<" "<<s<<" TUNA FRY DONE \n";
										break;
									case 4:
										quantity=0;
										cout<<"                                MAHI FRY (F/H)\n";
										cout<<"                                FULL/HALF(F/H) : ";
										cin>>s;
										cout<<"                                QUANTITY \n";
										cin>> quantity;
										F.Fish(choice1,s,quantity);
										system("cls");
										cout<<"                                        "<<quantity<<" "<<s<<" MAHI FRY DONE \n";
										break;
									case 5:
										quantity=0;
										cout<<"                                FINGER FISH\n";
										cout<<"                                Amount : ";
										cin>>s;
										cout<<"                                QUANTITY \n";
										cin>> quantity;
										F.Fish(choice1,s,quantity);
										system("cls");
										cout<<"                                        "<<quantity<<" "<<s<<" FINGER FISH DONE \n";
										break;
									case 6:
										system("cls");
										cout<<setw(50)<<"\n                       ##########################################               EXIT FISH MENU             ######################################## \n ";
										break;
									default:
										system("cls");
										cout<<setw(50)<<"\n                                ########       WRONG INPUT      ########\n";
										
								}
							    }while(choice1 != 6);
							    break;
						case 6:
								system("cls");
								do{
					            cout<<"\n\n\n";
						        cout<<setw(50)<<"                                ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n";
					            cout<<setw(50)<<"                                |                  DAAL                |     SIZE     |\n";
					            cout<<setw(50)<<"                                ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~|\n";
					            cout<<setw(50)<<"                                |         1  .  DAAL MASH (S/D)        |   SINGLE 150 |\n";
					            cout<<setw(50)<<"                                |                                      |   DOUBLE 300 |\n";
					            cout<<setw(50)<<"                                |                                      |~~~~~~~~~~~~~~|\n";
					            cout<<setw(50)<<"                                |         2  .  DAAL MONG (S/D)        |   SINGLE 150 |\n";
					            cout<<setw(50)<<"                                |                                      |   DOUBLE 300 |\n";
					            cout<<setw(50)<<"                                |                                      |~~~~~~~~~~~~~~|\n";
					            cout<<setw(50)<<"                                |         3  .  DAAL MASAR (S/D)       |   SINGLE 150 |\n";
					            cout<<setw(50)<<"                                |                                      |   DOUBLE 300 |\n";
					            cout<<setw(50)<<"                                |                                      |~~~~~~~~~~~~~~|\n";
					            cout<<setw(50)<<"                                |         4  .  MIX DAAL (S/D)         |   SINGLE 150 |\n";
					            cout<<setw(50)<<"                                |                                      |   DOUBLE 300 |\n";
					            cout<<setw(50)<<"                                ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~|\n";
					            cout<<setw(50)<<"                                |                            5 . EXIT                 |\n";
					            cout<<setw(50)<<"                                ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ \n";
					            cout<<setw(40)<<"                                Choice : ";
					            cin>>choice1;
					            switch(choice1)
								{
									case 1:
										quantity=0;
										cout<<"                                DAAL MASH (S/D)\n";
										cout<<"                                Single/Double(S/D) : ";
										cin>>s;
										cout<<"                                QUANTITY \n";
										cin>> quantity;
										F.DAAL(choice1,s,quantity);
										system("cls");
										cout<<"                                        "<<quantity<<" "<<s<<" DAAL MASH DONE \n"; 
										break;
									case 2:
										quantity=0;
										cout<<"                                DAAL MONG (S/D)\n";
										cout<<"                                Single/Double(S/D) : ";
										cin>>s;
										cout<<"                                QUANTITY \n";
										cin>> quantity;
										F.DAAL(choice1,s,quantity);
										system("cls");
										cout<<"                                        "<<quantity<<" "<<s<<" DAAL MONG DONE \n";
										break;
									case 3:
										quantity=0;
										cout<<"                                DAAL MASAR (S/D)\n";
										cout<<"                                Single/Double(S/D) : ";
									    cin>>s;
										cout<<"                                QUANTITY \n";
										cin>> quantity;
										F.DAAL(choice1,s,quantity);
										system("cls");
										cout<<"                                        "<<quantity<<" "<<s<<" DAAL MASAR DONE \n";
										break;
									case 4:
									    quantity=0;
										cout<<"                                MIX DAAL (S/D)\n";
										cout<<"                                Single/Double(S/D) : ";
										cin>>s;
										cout<<"                                QUANTITY \n";
										cin>> quantity;
										F.DAAL(choice1,s,quantity);
										system("cls");
										cout<<"                                        "<<quantity<<" "<<s<<" MIX DAAL DONE \n";
										break;
									case 5:									
										system("cls");
										cout<<setw(50)<<"\n                       ##########################################               EXIT DAAL MENU              ######################################## \n ";
										break;
									default:
										system("cls");
										cout<<setw(50)<<"\n                                ########       WRONG INPUT      ########\n";		
								}
							    }while(choice1 != 5);
							    break;
						case 7:
								system("cls");
								do{
					            cout<<"\n\n\n";
						        cout<<setw(50)<<"                                ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n";
					            cout<<setw(50)<<"                                |                  BIRYANI             |     SIZE      |\n";
					            cout<<setw(50)<<"                                ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~|\n";
					            cout<<setw(50)<<"                                |         1  .  SIMPLE BIRYANI (S/D)   |  SINGLE 100   |\n";
					            cout<<setw(50)<<"                                |                                      |  DOUBLE 150   |\n";
					            cout<<setw(50)<<"                                |                                      |~~~~~~~~~~~~~~~|\n";
					            cout<<setw(50)<<"                                |         2  .  CHICKEN BIRYANI (S/D)  |  SINGLE 150   |\n";
					            cout<<setw(50)<<"                                |                                      |  DOUBLE 250   |\n";
					            cout<<setw(50)<<"                                ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n";
					            cout<<setw(50)<<"                                |                          3 . EXIT                    |\n";
					            cout<<setw(50)<<"                                ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n";
					            cout<<setw(40)<<"                                Choice : ";
					            cin>>choice1;
					            switch(choice1)
								{
									case 1:
										quantity=0;
										cout<<"                                SIMPLE BIRYANI (S/D)\n";
										cout<<"                                Single/Double(S/D) : ";
										cin>>s;
										cout<<"                                QUANTITY \n";
										cin>> quantity;
										F.BIRYANI(choice1,s,quantity);
										system("cls");
										cout<<"                                        "<<quantity<<" "<<s<<" SIMPLE BIRYANI DONE \n"; 
										break;
									case 2:
										quantity=0;
										cout<<"                                CHICKEN BIRYANI (S/D)\n";
										cout<<"                                Single/Double(S/D) : ";
										cin>>s;
										cout<<"                                QUANTITY \n";
										cin>> quantity;
										F.BIRYANI(choice1,s,quantity);
										system("cls");
										cout<<"                                        "<<quantity<<" "<<s<<" CHICKEN BIRYANI DONE \n";
										break;
									case 3:
										system("cls");
										cout<<setw(50)<<"\n                       ########################################               EXIT BIRYANI MENU              ###################################### \n ";
										break;
									default:
										system("cls");
										cout<<setw(50)<<"\n                                ########       WRONG INPUT      ########\n";		
								}
							    }while(choice1 != 3);
							    break;
						case 8:
								system("cls");
								do{
					            cout<<"\n\n\n";
						        cout<<setw(50)<<"                                ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n";
					            cout<<setw(50)<<"                                |                  PULAO               |      SIZE     |\n";
					            cout<<setw(50)<<"                                ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n";
					            cout<<setw(50)<<"                                |         1  .  BEEF PULAO (S/D)       |  SINGLE 300   |\n";
					            cout<<setw(50)<<"                                |                                      |  DOUBLE 500   |\n";
					            cout<<setw(50)<<"                                |                                      |~~~~~~~~~~~~~~~|\n";
					            cout<<setw(50)<<"                                |         2  .  CHICKEN PULAO (S/D)    |  SINGLE 350   |\n";
					            cout<<setw(50)<<"                                |                                      |  DOUBLE 550   |\n";
					            cout<<setw(50)<<"                                ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n";
					            cout<<setw(50)<<"                                |               3 . EXIT               |               |\n";
					            cout<<setw(50)<<"                                ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n";
					            cout<<setw(40)<<"                                Choice : ";
					            cin>>choice1;
					            switch(choice1)
								{
									case 1:
										quantity=0;
										cout<<"                                BEEF PULAO (S/D)\n";
										cout<<"                                Single/Double(S/D) : ";
										cin>>s;
										cout<<"                                QUANTITY \n";
										cin>> quantity;
										F.PULAO(choice1,s,quantity);
										system("cls");
										cout<<"                                        "<<quantity<<" "<<s<<" BEEF PULAO DONE \n"; 
										break;
									case 2:
										quantity=0;
										cout<<"                                CHICKEN PULAO (S/D)\n";
										cout<<"                                Single/Double(S/D) : ";
										cin>>s;
										cout<<"                                QUANTITY \n";
										cin>> quantity;
										F.PULAO(choice1,s,quantity);
										system("cls");
										cout<<"                                        "<<quantity<<" "<<s<<" CHICKEN PULAO DONE \n";
										break;
									case 3:
										system("cls");
										cout<<setw(50)<<"\n                       #########################################               EXIT PULAO MENU               ####################################### \n ";
										break;
									default:
										system("cls");
										cout<<setw(50)<<"\n                                ########       WRONG INPUT      ########\n";		
								}
							    }while(choice1 != 3);
							    break;
						case 9:
								system("cls");
								do{
					            cout<<"\n\n\n";
						        cout<<setw(50)<<"                                ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~             \n";
					            cout<<setw(50)<<"                                |               ROTI/PRATHA            |             \n";
					            cout<<setw(50)<<"                                ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~             \n";
					            cout<<setw(50)<<"                                |         1  .  SADA ROTI              |             \n";
					            cout<<setw(50)<<"                                |                                      |             \n";
					            cout<<setw(50)<<"                                |                                      |             \n";
					            cout<<setw(50)<<"                                |         2  .  DESI PRATHA            |             \n";
					            cout<<setw(50)<<"                                |                                      |             \n";
					            cout<<setw(50)<<"                                |                                      |             \n";
					            cout<<setw(50)<<"                                |         3  .  ROGNI NAAN             |             \n";
					            cout<<setw(50)<<"                                |                                      |             \n";
					            cout<<setw(50)<<"                                |                                      |             \n";
					            cout<<setw(50)<<"                                |         4  .  SADA NAAN              |             \n";
					            cout<<setw(50)<<"                                |                                      |             \n";
					            cout<<setw(50)<<"                                |                                      |             \n";
					            cout<<setw(50)<<"                                |         5  .  GARLIC NAAN            |             \n";
					            cout<<setw(50)<<"                                |                                      |             \n";
					            cout<<setw(50)<<"                                ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~             \n";
					            cout<<setw(50)<<"                                |               6 . EXIT               |             \n";
					            cout<<setw(50)<<"                                ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~             \n";
					            cout<<setw(40)<<"                                Choice : ";
					            cin>>choice1;
					            switch(choice1)
								{
									case 1:
										cout<<"                                SADA ROTI\n";
										cout<<"                                Amount : ";
										cin>>s;
										F.ROTI(choice1,s);
										system("cls");
										cout<<"                                        "<<s<<" SADA ROTI DONE \n"; 
										break;
									case 2:
										cout<<"                                DESI PRATHA\n";
										cout<<"                                Amount : ";
										cin>>s;
										F.ROTI(choice1,s);
										system("cls");
										cout<<"                                        "<<s<<" DESI PRATHA DONE \n";
										break;
									case 3:
										cout<<"                                ROGHNI NAAN\n";
										cout<<"                                Amount : ";
										cin>>s;
										F.ROTI(choice1,s);
										system("cls");
										cout<<"                                        "<<s<<" ROGHNI NAAN DONE \n";
										break;
									case 4:
										cout<<"                                SADA NAAN\n";
										cout<<"                                Amount : ";
										cin>>s;
										F.ROTI(choice1,s);
										system("cls");
										cout<<"                                        "<<s<<" SADA NAAN DONE \n";
										break;
									case 5:
										cout<<"                                GARLIC NAAN\n";
										cout<<"                                Amount : ";
										cin>>s;
										F.ROTI(choice1,s);
										system("cls");
										cout<<"                                        "<<s<<" GARLIC NAAN DONE \n";
										break;
									case 6:
										cout<<setw(50)<<"\n                       ######################################               EXIT ROTI/PRATHA MENU            ###################################### \n ";
										break;
									default:
										system("cls");
										cout<<setw(50)<<"\n                                ########       WRONG INPUT      ########\n";	
								}
							    }while(choice1 != 6);
							    break;
						case 10:
								system("cls");
								do{
					            cout<<"\n\n\n";
						        cout<<setw(50)<<"                                ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~             \n";
					            cout<<setw(50)<<"                                |              RAITA/SALAD             |             \n";
					            cout<<setw(50)<<"                                ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~             \n";
					            cout<<setw(50)<<"                                |         1  .  RAITA                  |             \n";
					            cout<<setw(50)<<"                                |                                      |             \n";
					            cout<<setw(50)<<"                                |                                      |             \n";
					            cout<<setw(50)<<"                                |         2  .  CHUTNEY                |             \n";
					            cout<<setw(50)<<"                                |                                      |             \n";
					            cout<<setw(50)<<"                                |                                      |             \n";
					            cout<<setw(50)<<"                                |         3  .  DHAI                   |             \n";
					            cout<<setw(50)<<"                                |                                      |             \n";
					            cout<<setw(50)<<"                                |                                      |             \n";
					            cout<<setw(50)<<"                                |         4  .  SALAD                  |             \n";
					            cout<<setw(50)<<"                                |                                      |             \n";
					            cout<<setw(50)<<"                                ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~             \n";
					            cout<<setw(50)<<"                                |               6 . EXIT               |             \n";
					            cout<<setw(50)<<"                                ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~             \n";
					            cout<<setw(40)<<"                                Choice : ";
					            cin>>choice1;
					            switch(choice1)
								{
									case 1:
										cout<<"                                RAITA\n";
										cout<<"                                Amount : ";
										cin>>s;
										F.RAITA_SALAD(choice1,s);
										system("cls");
										cout<<"                                        "<<s<<" RAITA DONE \n"; 
										break;
									case 2:
										cout<<"                                CHUTNEY\n";
										cout<<"                                Amount : ";
										cin>>s;
										F.RAITA_SALAD(choice1,s);
										system("cls");
										cout<<"                                        "<<s<<" CHUTNEY DONE \n";
										break;
									case 3:
										cout<<"                                DHAI\n";
										cout<<"                                Amount : ";
										cin>>s;
										F.RAITA_SALAD(choice1,s);
										system("cls");
										cout<<"                                        "<<s<<" DHAI DONE \n";
										break;
									case 4:
										cout<<"                                SALAD\n";
										cout<<"                                Amount : ";
										cin>>s;
										F.RAITA_SALAD(choice1,s);
										system("cls");
										cout<<"                                        "<<s<<" SALAD DONE \n";
										break;
									case 5:
										cout<<setw(50)<<"\n                       #####################################               EXIT RAITA/SALAD MENU             ###################################### \n ";
										break;
									default:
										system("cls");
										cout<<setw(50)<<"\n                                ########       WRONG INPUT      ########\n";		
								}
							    }while(choice1 != 5);
							    break;
						case 11:
							system("cls");
							cout<<setw(50)<<"\n                                ###################              EXIT DESI FOOD              ###################### \n ";
							break;
						default:
							system("cls");
							cout<<setw(50)<<"\n                       #######################################                WRONG INPUT               ####################################### \n ";
						}
					    }while(choice!=11);						
					}
					else if (choice==3)
					{
						system("cls");
						do{
					    cout<<"\n\n\n";
						cout<<setw(50)<<"                       ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~  \n";
					    cout<<setw(50)<<"                       |                                                   SWEETS & DISERT                                                    |  \n";
					    cout<<setw(50)<<"                       ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~  \n";
					    cout<<setw(50)<<"                       |                     1  .  KHEER                          |                     6  .  ICE-CREAM                       |  \n";
					    cout<<setw(50)<<"                       |                                                          |                                                           |  \n";
					    cout<<setw(50)<<"                       |                                                          |                                                           |  \n";
					    cout<<setw(50)<<"                       |                     2  .  CUSTARD                        |                     7  .  CAKE                            |  \n";
					    cout<<setw(50)<<"                       |                                                          |                                                           |  \n";
					    cout<<setw(50)<<"                       |                                                          |                                                           |  \n";
					    cout<<setw(50)<<"                       |                     3  .  JELLY                          |                     8  .  CHAT                            |  \n";
					    cout<<setw(50)<<"                       |                                                          |                                                           |  \n";
					    cout<<setw(50)<<"                       |                                                          |                                                           |  \n";
					    cout<<setw(50)<<"                       |                     4  .  RASMALAI                       |                     9  .  MATHI                           |  \n";
					    cout<<setw(50)<<"                       |                                                          |                                                           |  \n";
					    cout<<setw(50)<<"                       |                                                          |                                                           |  \n";
					    cout<<setw(50)<<"                       |                     5  .  HALWA                          |                    10  .  FALOODA                         |  \n";
					    cout<<setw(50)<<"                       |                                                          |                                                           |  \n";
					    cout<<setw(50)<<"                       |                                                          |                                                           |  \n";
					    cout<<setw(50)<<"                       ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~  \n";
					    cout<<setw(50)<<"                       |                                                      11 . EXIT                                                       |  \n";
					    cout<<setw(50)<<"                       ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~  \n";
					    cout<<setw(40)<<"                       Choice : ";
					    cin>>choice;
					    switch(choice)
						{	
						case 1:
								system("cls");
								do{
					            cout<<"\n\n\n";
						        cout<<setw(50)<<"                                ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n";
					            cout<<setw(50)<<"                                |                  KHEER               |    SIZE     |\n";
					            cout<<setw(50)<<"                                |~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~|\n";
					            cout<<setw(50)<<"                                |        1  .  KHEER (S/D)             | SINGLE 100  |\n";
					            cout<<setw(50)<<"                                |                                      | DOUBLE 200  |\n";
					            cout<<setw(50)<<"                                |                                      |~~~~~~~~~~~~~|\n";
					            cout<<setw(50)<<"                                |        2  .  SPECIAL MALAI KHEER(S/D)| SINGLE 150  |\n";
					            cout<<setw(50)<<"                                |                                      | DOUBLE 230  |\n";
					            cout<<setw(50)<<"                                |~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~|\n";
					            cout<<setw(50)<<"                                |                           3 . EXIT                 |\n";
					            cout<<setw(50)<<"                                ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n";
					            cout<<setw(40)<<"                                Choice : ";
					            cin>>choice1;
					            switch(choice1)
								{
									case 1:
										quantity=0;
										cout<<"                                KHEER (S/D)\n";
										cout<<"                                Single/Double(S/D) : ";
										cin>>s;
										cout<<"                                QUANTITY \n";
										cin>> quantity;
										F.KHEER(choice1,s,quantity);
										system("cls");
										cout<<"                                        "<<quantity<<" "<<s<<" KHEER DONE \n"; 
										break;
									case 2:
										quantity=0;
										cout<<"                                SPICAL MALI KHEER (S/D)\n";
										cout<<"                                Single/Double(S/D) : ";
										cin>>s;
										cout<<"                                QUANTITY \n";
										cin>> quantity;
										F.KHEER(choice1,s,quantity);
										system("cls");
										cout<<"                                        "<<quantity<<" "<<s<<" SPICAL MALI KHEER DONE \n";
										break;
									case 3:
										system("cls");
										cout<<setw(50)<<"\n                       #########################################               EXIT KHEER               ####################################### \n ";
										break;
									default:
										system("cls");
										cout<<setw(50)<<"\n                                ########       WRONG INPUT      ########\n";		
								}
							    }while(choice1 != 3);
							    break;
						case 2:
								system("cls");
								do{
					            cout<<"\n\n\n";
						        cout<<setw(50)<<"                                ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n";
					            cout<<setw(50)<<"                                |                  CUSTARD             |    SIZE     |\n";
					            cout<<setw(50)<<"                                |~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~|\n";
					            cout<<setw(50)<<"                                |         1  .  MANGO CUSTARD (S/D)    |  SINGLE 170 |\n";
					            cout<<setw(50)<<"                                |                                      |  DOUBLE 230 |\n";
					            cout<<setw(50)<<"                                |                                      |~~~~~~~~~~~~~|\n";
					            cout<<setw(50)<<"                                |         2  .  BANANA CUSTARD(S/D)    |  SINGLE 170 |\n";
					            cout<<setw(50)<<"                                |                                      |  DOUBLE 230 |\n";
					            cout<<setw(50)<<"                                |                                      |~~~~~~~~~~~~~|\n";
					            cout<<setw(50)<<"                                |         3  .  STRAWBERRY CUSTARD(S/D)|  SINGLE 170 |\n";
					            cout<<setw(50)<<"                                |                                      |  DOUBLE 230 |\n";
					            cout<<setw(50)<<"                                |~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~|\n";
					            cout<<setw(50)<<"                                |                          4 . EXIT                  |\n";
					            cout<<setw(50)<<"                                ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n";
					            cout<<setw(40)<<"                                Choice : ";
					            cin>>choice1;
					            switch(choice1)
								{
									case 1:
										quantity=0;
										cout<<"                                MANGO CUSTARD (S/D)\n";
										cout<<"                                Single/Double(S/D) : ";
										cin>>s;
										cout<<"                                QUANTITY \n";
										cin>> quantity;
										F.CUSTARD(choice1,s,quantity);
										system("cls");
										cout<<"                                        "<<quantity<<" "<<s<<" MANGO CUSTARD DONE \n"; 
										break;
									case 2:
										quantity=0;
										cout<<"                                BANANA CUSTARD (S/D)\n";
										cout<<"                                Single/Double(S/D) : ";
										cin>>s;
										cout<<"                                QUANTITY \n";
										cin>> quantity;
										F.CUSTARD(choice1,s,quantity);
										system("cls");
										cout<<"                                        "<<quantity<<" "<<s<<" BANANA CUSTARD DONE \n";
										break;
									case 3:
										quantity=0;
										cout<<"                                STRAWBERRY CUSTARD(S/D)\n";
										cout<<"                                Single/Double(S/D) : ";
										cin>>s;
										cout<<"                                QUANTITY \n";
										cin>> quantity;
										F.CUSTARD(choice1,s,quantity);
										system("cls");
										cout<<"                                        "<<quantity<<" "<<s<<" STRAWBERRY CUSTARD DONE \n";
										break;
									case 4:
										system("cls");
										cout<<setw(50)<<"\n                       ########################################               EXIT CUSTARD               ###################################### \n ";
										break;
									default:
										system("cls");
										cout<<setw(50)<<"\n                                ########       WRONG INPUT      ########\n";		
								}
							    }while(choice1 != 4);
							    break;
						case 3:
								system("cls");
								do{
					            cout<<"\n\n\n";
						        cout<<setw(50)<<"                                ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n";
					            cout<<setw(50)<<"                                |                 JELLY                |    SIZE     |\n";
					            cout<<setw(50)<<"                                ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n";
					            cout<<setw(50)<<"                                |         1  .  MANGO JELLY (S/D)      |  SINGLE 120 |\n";
					            cout<<setw(50)<<"                                |                                      |  DOUBLE 180 |\n";
					            cout<<setw(50)<<"                                |                                      |~~~~~~~~~~~~~|\n";
					            cout<<setw(50)<<"                                |         2  .  BANANA JELLY(S/D)      |  SINGLE 120 |\n";
					            cout<<setw(50)<<"                                |                                      |  DOUBLE 180 |\n";
					            cout<<setw(50)<<"                                |                                      |~~~~~~~~~~~~~|\n";
					            cout<<setw(50)<<"                                |         3  .  STRAWBERRY JELLY(S/D)  |  SINGLE 120 |\n";
					            cout<<setw(50)<<"                                |                                      |  DOUBLE 180 |\n";
					            cout<<setw(50)<<"                                ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~|\n";
					            cout<<setw(50)<<"                                |               4 . EXIT                             | \n";
					            cout<<setw(50)<<"                                ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n";
					            cout<<setw(40)<<"                                Choice : ";
					            cin>>choice1;
					            switch(choice1)
								{
									case 1:
										quantity=0;
										cout<<"                                MANGO JELLY (S/D)\n";
										cout<<"                                Single/Double(S/D) : ";
										cin>>s;
										cout<<"                                QUANTITY \n";
										cin>> quantity;
										F.JELLY(choice1,s,quantity);
										system("cls");
										cout<<"                                        "<<quantity<<" "<<s<<" MANGO JELLY DONE \n"; 
										break;
									case 2:
										quantity=0;
										cout<<"                                BANANA JELLY (S/D)\n";
										cout<<"                                Single/Double(S/D) : ";
										cin>>s;
										cout<<"                                QUANTITY \n";
										cin>> quantity;
										F.JELLY(choice1,s,quantity);
										system("cls");
										cout<<"                                        "<<quantity<<" "<<s<<" BANANA JELLY DONE \n";
										break;
									case 3:
										quantity=0;
										cout<<"                                STRAWBERRY JELLY(S/D)\n";
										cout<<"                                Single/Double(S/D) : ";
										cin>>s;
										cout<<"                                QUANTITY \n";
										cin>> quantity;
										F.JELLY(choice1,s,quantity);
										system("cls");
										cout<<"                                        "<<quantity<<" "<<s<<" STRAWBERRY CUSTARD DONE \n";
										break;
									case 4:
										system("cls");
										cout<<setw(50)<<"\n                       #######################################               EXIT JELLY               ##################################### \n ";
										break;
									default:
										system("cls");
										cout<<setw(50)<<"\n                                ########       WRONG INPUT      ########\n";		
								}
							    }while(choice1 != 4);
							    break;
						case 4:
								system("cls");
								do{
					            cout<<"\n\n\n";
						        cout<<setw(50)<<"                                ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n";
					            cout<<setw(50)<<"                                |                  RASMALAI            |    SIZE     |\n";
					            cout<<setw(50)<<"                                |~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~|\n";
					            cout<<setw(50)<<"                                |         1  .  RASMALAI (S/D)         | SINGLE 200  |\n";
					            cout<<setw(50)<<"                                |                                      | DOUBLE 300  |\n";
					            cout<<setw(50)<<"                                |                                      |~~~~~~~~~~~~~|\n";
					            cout<<setw(50)<<"                                |         2  .  PISTA RASMALAI(S/D)    | SINGLE 250  |\n";
					            cout<<setw(50)<<"                                |                                      | DOUBLE 400  |\n";
					            cout<<setw(50)<<"                                |~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~|\n";
					            cout<<setw(50)<<"                                |                          3 . EXIT                  |\n";
					            cout<<setw(50)<<"                                ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n";
					            cout<<setw(40)<<"                                Choice : ";
					            cin>>choice1;
					            switch(choice1)
								{
									case 1:
										quantity=0;
										cout<<"                                RASMALAI (S/D)\n";
										cout<<"                                Single/Double(S/D) : ";
										cin>>s;
										cout<<"                                QUANTITY \n";
										cin>> quantity;
										F.RASMALAI(choice1,s,quantity);
										system("cls");
										cout<<"                                        "<<quantity<<" "<<s<<" RASMALAI DONE \n"; 
										break;
									case 2:
										quantity=0;
										cout<<"                                PISTA RASMALAI (S/D)\n";
										cout<<"                                Single/Double(S/D) : ";
										cin>>s;
										cout<<"                                QUANTITY \n";
										cin>> quantity;
										F.RASMALAI(choice1,s,quantity);
										system("cls");
										cout<<"                                        "<<quantity<<" "<<s<<" PISTA RASMALAI DONE \n";
										break;
									case 3:
										system("cls");
										cout<<setw(50)<<"\n                       #######################################               EXIT RASMALAI               ###################################### \n ";
										break;
									default:
										system("cls");
										cout<<setw(50)<<"\n                                ########       WRONG INPUT      ########\n";		
								}
							    }while(choice1 != 3);
							    break;
						case 5:
								system("cls");
								do{
					            cout<<"\n\n\n";
						        cout<<setw(50)<<"                                ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n";
					            cout<<setw(50)<<"                                |                 HALWA                |    SIZE     |\n";
					            cout<<setw(50)<<"                                |~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~|\n";
					            cout<<setw(50)<<"                                |         1  .  GAJAR KA HALWA (H/F)   | HALF 400    |\n";
					            cout<<setw(50)<<"                                |                                      | FULL 700    |\n";
					            cout<<setw(50)<<"                                |                                      |~~~~~~~~~~~~~|\n";
					            cout<<setw(50)<<"                                |         2  .  SUJI KA HALWA(H/F)     | HALF 300    |\n";
					            cout<<setw(50)<<"                                |                                      | FULL 600    |\n";
					            cout<<setw(50)<<"                                |                                      |~~~~~~~~~~~~~|\n";
					            cout<<setw(50)<<"                                |         3  .  ANDA KA HALWA(S/D)     | HALF 450    |\n";
					            cout<<setw(50)<<"                                |                                      | FULL 650    |\n";
					            cout<<setw(50)<<"                                |~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~|\n";
					            cout<<setw(50)<<"                                |                           4 . EXIT                 |\n";
					            cout<<setw(50)<<"                                ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n";
					            cout<<setw(40)<<"                                Choice : ";
					            cin>>choice1;
					            switch(choice1)
								{
									case 1:
										quantity=0;
										cout<<"                                GAJAR KA HALWA (H/F)\n";
										cout<<"                                HALF/FULL(H/F) : ";
										cin>>s;
										cout<<"                                QUANTITY \n";
										cin>> quantity;
										F.HALWA(choice1,s,quantity);
										system("cls");
										cout<<"                                        "<<quantity<<" "<<s<<" GAJAR KA HALWA DONE \n"; 
										break;
									case 2:
										quantity=0;
										cout<<"                                SUJI KA HALWA (H/F)\n";
										cout<<"                                HALF/FULL(H/F) : ";
										cin>>s;
										cout<<"                                QUANTITY \n";
										cin>> quantity;
										F.HALWA(choice1,s,quantity);
										system("cls");
										cout<<"                                        "<<quantity<<" "<<s<<" SUJI KA HALWA DONE \n";
										break;
									case 3:
										quantity=0;
										cout<<"                                ANDA KA HALWA (H/F)\n";
										cout<<"                                HALF/FULL(H/F) : ";
										cin>>s;
										cout<<"                                QUANTITY \n";
										cin>> quantity;
										F.HALWA(choice1,s,quantity);
										system("cls");
										cout<<"                                        "<<quantity<<" "<<s<<" ANDA KA HALWA DONE \n";
										break;
									case 4:
										system("cls");
										cout<<setw(50)<<"\n                       #########################################               EXIT HALWA               ####################################### \n ";
										break;
									default:
										system("cls");
										cout<<setw(50)<<"\n                                ########       WRONG INPUT      ########\n";		
								}
							    }while(choice1 != 4);
							    break;
						case 6:
								system("cls");
								do{
					            cout<<"\n\n\n";
						        cout<<setw(50)<<"                                ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n";
					            cout<<setw(50)<<"                                |                ICE-CREAM               |    SIZE    |\n";
					            cout<<setw(50)<<"                                |~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~|\n";
					            cout<<setw(50)<<"                                |       1  .  MANGO ICE-CREAM (S/D/T)    | SINGLE  80 |\n";
					            cout<<setw(50)<<"                                |                                        | DOUBLE  120|\n";
					            cout<<setw(50)<<"                                |                                        | TRIPPLE 170|\n";
					            cout<<setw(50)<<"                                |                                        |~~~~~~~~~~~~|\n";
					            cout<<setw(50)<<"                                |       2  .  VANAILA ICE-CREAM(S/D/T)   | SINGLE  80 |\n";
					            cout<<setw(50)<<"                                |                                        | DOUBLE  120|\n";
					            cout<<setw(50)<<"                                |                                        | TRIPPLE 170|\n";
					            cout<<setw(50)<<"                                |                                        |~~~~~~~~~~~~|\n";
					            cout<<setw(50)<<"                                |       3  .  STRAWBERRY ICE-CREAM(S/D/T)| SINGLE  80 |\n";
					            cout<<setw(50)<<"                                |                                        | DOUBLE  120|\n";
					            cout<<setw(50)<<"                                |                                        | TRIPPLE 170|\n";
					            cout<<setw(50)<<"                                |                                        |~~~~~~~~~~~~|\n";
					            cout<<setw(50)<<"                                |       4  .  CHOCOLATE ICE-CREAM(S/D/T) | SINGLE  80 |\n";
					            cout<<setw(50)<<"                                |                                        | DOUBLE  120|\n";
					            cout<<setw(50)<<"                                |                                        | TRIPPLE 170|\n";
					            cout<<setw(50)<<"                                |~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~|\n";
					            cout<<setw(50)<<"                                |                          5 . EXIT                   |\n";
					            cout<<setw(50)<<"                                ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n";
					            cout<<setw(40)<<"                                Choice : ";
					            cin>>choice1;
					            switch(choice1)
								{
									case 1:
									    quantity=0;	
										cout<<"                                Single/Double/Tripple(S/D/T) : ";
										cin>>s;
										cout<<"                                QUANTITY \n";
										cin>> quantity;
										F.ICECREAM(choice1,s,quantity);
										system("cls");
										cout<<"                                        "<<quantity<<" "<<s<<" MANGO ICE-CREAM DONE \n"; 
										break;
									case 2:
										quantity=0;
										cout<<"                                VANAILA ICE-CREAM (S/D/T)\n";
										cout<<"                                Single/Double/Tripple(S/D/T) : ";
										cin>>s;
										cout<<"                                QUANTITY \n";
										cin>> quantity;
										F.ICECREAM(choice1,s,quantity);
										system("cls");
										cout<<"                                        "<<quantity<<" "<<s<<" VANAILA ICE-CREAM DONE \n";
										break;
									case 3:
										quantity=0;
										cout<<"                                STRAWBERRY ICE-CREAM(S/D/T)\n";
										cout<<"                                Single/Double/Tripple(S/D/T) : ";
										cin>>s;
										cout<<"                                QUANTITY \n";
										cin>> quantity;
										F.ICECREAM(choice1,s,quantity);
										system("cls");
										cout<<"                                        "<<quantity<<" "<<s<<" STRAWBERRY ICE-CREAM DONE \n";
										break;
									case 4:
										quantity=0;
										cout<<"                                CHOCOLATE ICE-CREAM(S/D/T)\n";
										cout<<"                                Single/Double/Tripple(S/D/T) : ";
										cin>>s;
										cout<<"                                QUANTITY \n";
										cin>> quantity;
										F.ICECREAM(choice1,s,quantity);
										system("cls");
										cout<<"                                        "<<quantity<<" "<<s<<" CHOCOLATE ICE-CREAM DONE \n";
										break;
									case 5:
										system("cls");
										cout<<setw(50)<<"\n                       #######################################               EXIT ICE-CREAM               ##################################### \n ";
										break;
									default:
										system("cls");
										cout<<setw(50)<<"\n                                ########       WRONG INPUT      ########\n";		
								}
							    }while(choice1 != 5);
							    break;
						case 7:
								system("cls");
								do{
					            cout<<"\n\n\n";
						        cout<<setw(50)<<"                                ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~             \n";
					            cout<<setw(50)<<"                                |                  CAKE                |             \n";
					            cout<<setw(50)<<"                                |~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~|             \n";
					            cout<<setw(50)<<"                                |       1  .  NUTELLA (1600)           |             \n";
					            cout<<setw(50)<<"                                |                                      |             \n";
					            cout<<setw(50)<<"                                |                                      |             \n";
					            cout<<setw(50)<<"                                |       2  .  LOTUS   (1700)           |             \n";
					            cout<<setw(50)<<"                                |                                      |             \n";
					            cout<<setw(50)<<"                                |                                      |             \n";
					            cout<<setw(50)<<"                                |       3  .  RED VELVET (1500)        |             \n";
					            cout<<setw(50)<<"                                |                                      |             \n";
					            cout<<setw(50)<<"                                |                                      |             \n";
					            cout<<setw(50)<<"                                |       4  .  RAFFAELLO  (2400)        |             \n";
					            cout<<setw(50)<<"                                |                                      |             \n";
					            cout<<setw(50)<<"                                |~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~|             \n";
					            cout<<setw(50)<<"                                |               5 . EXIT               |             \n";
					            cout<<setw(50)<<"                                ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~             \n";
					            cout<<setw(40)<<"                                Choice : ";
					            cin>>choice1;
					            switch(choice1)
								{
									case 1:
										cout<<"                                NUTELLA \n";
										cout<<"                                Amount : ";
										cin>>quantity;
										F.CAKE(choice1,quantity);
										system("cls");
										cout<<"                                        "<<quantity<<" NUTELLA DONE \n"; 
										break;
									case 2:
										cout<<"                                LOTUS \n";
										cout<<"                                Amount : ";
										cin>>quantity;
										F.CAKE(choice1,quantity);
										system("cls");
										cout<<"                                        "<<quantity<<" LOTUS DONE \n";
										break;
									case 3:
										cout<<"                                RED VELVET\n";
										cout<<"                                Amount : ";
										cin>>quantity;
										F.CAKE(choice1,quantity);
										system("cls");
										cout<<"                                        "<<quantity<<" SRED VELVET DONE \n";
										break;
									case 4:
										cout<<"                                RAFFAELLO\n";
										cout<<"                                Amount : ";
										cin>>quantity;
										F.CAKE(choice1,quantity);
										system("cls");
										cout<<"                                        "<<quantity<<" RAFFAELLO DONE \n";
										break;
									case 5:
										system("cls");
										cout<<setw(50)<<"\n                       #########################################               EXIT CAKE                ####################################### \n ";
										break;
									default:
										system("cls");
										cout<<setw(50)<<"\n                                ########       WRONG INPUT      ########\n";		
								}
							    }while(choice1 != 5);
							    break;
						case 8:
						    	system("cls");
								do{
					            cout<<"\n\n\n";
						        cout<<setw(50)<<"                                ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n";
					            cout<<setw(50)<<"                                |                  CHAT                |   SIZE      |\n";
					            cout<<setw(50)<<"                                |~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~|\n";
					            cout<<setw(50)<<"                                |         1  .  FRUIT CHAT (S/L)       |  SMALL 100  |\n";
					            cout<<setw(50)<<"                                |                                      |  LARGE 170  |\n";
					            cout<<setw(50)<<"                                |                                      |~~~~~~~~~~~~~|\n";
					            cout<<setw(50)<<"                                |         2  .  CREAM CHAT (S/L)       |  SMALL 120  |\n";
					            cout<<setw(50)<<"                                |                                      |  LARGE 200  |\n";
					            cout<<setw(50)<<"                                |                                      |~~~~~~~~~~~~~|\n";
					            cout<<setw(50)<<"                                |         3  .  RUSSIAN SALAD (S/L)    |  SMALL 150  |\n";
					            cout<<setw(50)<<"                                |                                      |  LARGE 220  |\n";
					            cout<<setw(50)<<"                                |~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~|\n";
					            cout<<setw(50)<<"                                |                         4 . EXIT                   |\n";
					            cout<<setw(50)<<"                                ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n";
					            cout<<setw(40)<<"                                Choice : ";
					            cin>>choice1;
					            switch(choice1)
								{
									case 1:
										quantity=0;
										cout<<"                                FRUIT CHAT (S/L) \n";
										cout<<"                                Size : ";
										cin>>s;
										cout<<"                                QUANTITY \n";
										cin>> quantity;
										F.REFREASHMENT(choice1,s,quantity);
										system("cls");
										cout<<"\n                                        "<<quantity<<" "<<s<<" FRUIT CHAT DONE \n";
										break;
									case 2:
										quantity=0;
										cout<<"                                CREAM CHAT (S/L) \n";
										cout<<"                                Size : ";
										cin>>s;
										cout<<"                                QUANTITY \n";
										cin>> quantity;
										F.REFREASHMENT(choice1,s,quantity);
										system("cls");
										cout<<"\n                                        "<<quantity<<" "<<s<<" CREAM CHAT DONE \n";
										break;
									case 3:
										quantity=0;
										cout<<"                                RUSSIAN SALAD (S/L) \n";
										cout<<"                                Size : ";
										cin>>s;
										cout<<"                                QUANTITY \n";
										cin>> quantity;
										F.REFREASHMENT(choice1,s,quantity);
										system("cls");
										cout<<"\n                                        "<<quantity<<" "<<s<<" RUSSIAN SALAD DONE \n";
										break;
									case 4:
										system("cls");
										cout<<setw(50)<<"\n                       #########################################              EXIT CHAT               ######################################### \n ";
										break;
									default:
										system("cls");
										cout<<setw(50)<<"\n                                ########       WRONG INPUT      ########\n";		
								}
							    }while(choice1 != 4);
							    break;
						case 9:
								system("cls");
								do{
					            cout<<"\n\n\n";
						        cout<<setw(50)<<"                                ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~             \n";
					            cout<<setw(50)<<"                                |                  MATHI               |             \n";
					            cout<<setw(50)<<"                                ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~             \n";
					            cout<<setw(50)<<"                                |       1  .  RAS GULA  (600)          |             \n";
					            cout<<setw(50)<<"                                |                                      |             \n";
					            cout<<setw(50)<<"                                |                                      |             \n";
					            cout<<setw(50)<<"                                |       2  .  GULABJAMAN (600)         |             \n";
					            cout<<setw(50)<<"                                |                                      |             \n";
					            cout<<setw(50)<<"                                |                                      |             \n";
					            cout<<setw(50)<<"                                |       3  .  PATISA (900)             |             \n";
					            cout<<setw(50)<<"                                |                                      |             \n";
					            cout<<setw(50)<<"                                |                                      |             \n";
					            cout<<setw(50)<<"                                |       4  .  BARFI  (1200)            |             \n";
					            cout<<setw(50)<<"                                |                                      |             \n";
					            cout<<setw(50)<<"                                ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~             \n";
					            cout<<setw(50)<<"                                |               5 . EXIT               |             \n";
					            cout<<setw(50)<<"                                ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~             \n";
					            cout<<setw(40)<<"                                Choice : ";
					            cin>>choice1;
					            switch(choice1)
								{
									case 1:
										cout<<"                                RAS GULA \n";
										cout<<"                                (1kg/2kg) : ";
										cin>>quantity;
										F.MATHAI(choice1,quantity);
										system("cls");
										cout<<"                                        "<<quantity<<" RAS GULA DONE \n"; 
										break;
									case 2:
										cout<<"                                GULABJAMAN \n";
										cout<<"                                (1kg/2kg) : ";
										cin>>quantity;
										F.MATHAI(choice1,quantity);
										system("cls");
										cout<<"                                        "<<quantity<<" GULABJAMAN DONE \n";
										break;
									case 3:
										cout<<"                                PATISA\n";
										cout<<"                                (1kg/2kg) : ";
										cin>>quantity;
										F.MATHAI(choice1,quantity);
										system("cls");
										cout<<"                                        "<<quantity<<" PATISA DONE \n";
										break;
									case 4:
										cout<<"                                BARFI\n";
										cout<<"                                (1kg/2kg) : ";
										cin>>quantity;
										F.MATHAI(choice1,quantity);
										system("cls");
										cout<<"                                        "<<quantity<<" BARFI DONE \n";
										break;
									case 5:
										system("cls");
										cout<<setw(50)<<"\n                       #########################################               EXIT MATHI               ####################################### \n ";
										break;
									default:
										system("cls");
										cout<<setw(50)<<"\n                                ########       WRONG INPUT      ########\n";		
								}
							    }while(choice1 != 5);
							    break;
						case 10:
			                    system("cls");
								do{
					            cout<<"\n\n\n";
						        cout<<setw(50)<<"                                ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n";
					            cout<<setw(50)<<"                                |                 FALOODA              |    SIZE      |\n";
					            cout<<setw(50)<<"                                |~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~|\n";
					            cout<<setw(50)<<"                                |      1  .  FALOODA (S/D)             |   SINGLE 150 |\n";
					            cout<<setw(50)<<"                                |                                      |   DOUBLE 300 |\n";
					            cout<<setw(50)<<"                                |                                      |~~~~~~~~~~~~~~|\n";
					            cout<<setw(50)<<"                                |      2  .  SPECIAL MALAI FALOODA(S/D)|   SINGLE 200 |\n";
					            cout<<setw(50)<<"                                |                                      |   DOUBLE 350 |\n";
					            cout<<setw(50)<<"                                |~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~|\n";
					            cout<<setw(50)<<"                                |                         3 . EXIT                    |\n";
					            cout<<setw(50)<<"                                |~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~|\n";
					            cout<<setw(40)<<"                                Choice : ";
					            cin>>choice1;
					            switch(choice1)
								{
									case 1:
										quantity=0;
										cout<<"                                FALOODA \n";
										cout<<"                                Single/Double(S/D) : ";
										cin>>s;
										cout<<"                                QUANTITY \n";
										cin>> quantity;
										F.FALOODA(choice1,s,quantity);
										system("cls");
										cout<<"                                        "<<quantity<<" "<<s<<" FALOODA DONE \n"; 
										break;
									case 2:
										quantity=0;
										cout<<"                                SPECIAL MALAI  FALOODA \n";
										cout<<"                                Single/Double(S/D) : ";
										cin>>s;
										cout<<"                                QUANTITY \n";
										cin>> quantity;
										F.FALOODA(choice1,s,quantity);
										system("cls");
										cout<<"                                        "<<quantity<<" "<<s<<" SPECIAL MALAI FALOODA DONE \n";
										break;
									case 3:
										system("cls");
										cout<<setw(50)<<"\n                       ########################################               EXIT FALOODA               ###################################### \n ";
										break;
									default:
										system("cls");
										cout<<setw(50)<<"\n                                ########       WRONG INPUT      ########\n";		
								}
							    }while(choice1 != 3);
							    break;
						case 11:
							system("cls");
							cout<<setw(50)<<"\n                                ###################            EXIT SWEETS & DISERT          ###################### \n ";
							break;
						default:
							system("cls");
							cout<<setw(50)<<"\n                       #######################################                WRONG INPUT               ####################################### \n ";
						}
					    }while(choice!=11);
						
					}
					else if (choice==4)
					{
						system("cls");
						do{
					    cout<<"\n\n\n";
						cout<<setw(50)<<"                       ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~  \n";
					    cout<<setw(50)<<"                       |                                                       DRINKS                                                         |  \n";
					    cout<<setw(50)<<"                       ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~  \n";
					    cout<<setw(50)<<"                       |                     1  .  7 UP                           |                     6  .  MANGO JUICE/SHAKE               |  \n";
					    cout<<setw(50)<<"                       |                                                          |                                                           |  \n";
					    cout<<setw(50)<<"                       |                                                          |                                                           |  \n";
					    cout<<setw(50)<<"                       |                     2  .  COKA COLA                      |                     7  .  BANANA JUICE/SHAKE              |  \n";
					    cout<<setw(50)<<"                       |                                                          |                                                           |  \n";
					    cout<<setw(50)<<"                       |                                                          |                                                           |  \n";
					    cout<<setw(50)<<"                       |                     3  .  FANTA                          |                     8  .  STRAWBERRY JUICE/SHAKE          |  \n";
					    cout<<setw(50)<<"                       |                                                          |                                                           |  \n";
					    cout<<setw(50)<<"                       |                                                          |                                                           |  \n";
					    cout<<setw(50)<<"                       |                     4  .  STRING                         |                     9  .  APPLE JUICE                     |  \n";
					    cout<<setw(50)<<"                       |                                                          |                                                           |  \n";
					    cout<<setw(50)<<"                       |                                                          |                                                           |  \n";
					    cout<<setw(50)<<"                       |                     5  .  MINERAL WATER                  |                    10  .  ICE-CREAM SHAKE                 |  \n";
					    cout<<setw(50)<<"                       |                                                          |                                                           |  \n";
					    cout<<setw(50)<<"                       |                                                          |                                                           |  \n";
					    cout<<setw(50)<<"                       ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~  \n";
					    cout<<setw(50)<<"                       |                                                      11 . EXIT                                                       |  \n";
					    cout<<setw(50)<<"                       ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~  \n";
					    cout<<setw(40)<<"                       Choice : ";
					    cin>>choice;
					    switch(choice)
						{
							case 1:
								system("cls");
								do{
					            cout<<"\n\n\n";
						        cout<<setw(50)<<"                                ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~             \n";
					            cout<<setw(50)<<"                                |                 7 UP                 |             \n";
					            cout<<setw(50)<<"                                ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~             \n";
					            cout<<setw(50)<<"                                |       1  .  RAGULAR                  |             \n";
					            cout<<setw(50)<<"                                |                                      |             \n";
					            cout<<setw(50)<<"                                |                                      |             \n";
					            cout<<setw(50)<<"                                |       2  .  1 lITER                  |             \n";
					            cout<<setw(50)<<"                                |                                      |             \n";
					            cout<<setw(50)<<"                                |                                      |             \n";
					            cout<<setw(50)<<"                                |       3  .  1.5 lITER                |             \n";
					            cout<<setw(50)<<"                                |                                      |             \n";
					            cout<<setw(50)<<"                                |                                      |             \n";
					            cout<<setw(50)<<"                                |       4  .  2.25 lITER               |             \n";
					            cout<<setw(50)<<"                                |                                      |             \n";
					            cout<<setw(50)<<"                                ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~             \n";
					            cout<<setw(50)<<"                                |               5 . EXIT               |             \n";
					            cout<<setw(50)<<"                                ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~             \n";
					            cout<<setw(40)<<"                                Choice : ";
					            cin>>choice1;
					            switch(choice1)
								{
									case 1:
										cout<<"                                RAGULAR \n";
										cout<<"                                Amount : ";
										cin>>quantity;
										F.s7_UP(choice1,quantity);
										system("cls");
										cout<<"                                        "<<quantity<<" RAGULAR DONE \n"; 
										break;
									case 2:
										cout<<"                                1 lITER \n";
										cout<<"                                AMOUNT : ";
										cin>>quantity;
										F.s7_UP(choice1,quantity);
										system("cls");
										cout<<"                                        "<<size<<" 1 lITER DONE \n";
										break;
									case 3:
										cout<<"                                1.5 lITER\n";
										cout<<"                                AMOUNT : ";
										cin>>quantity;
										F.s7_UP(choice1,quantity);
										system("cls");
										cout<<"                                        "<<size<<" 1.5 lITER DONE \n";
										break;
									case 4:
										cout<<"                                2.25 lITER\n";
										cout<<"                                AMOUNT : ";
										cin>>quantity;
										F.s7_UP(choice1,quantity);
										system("cls");
										cout<<"                                        "<<size<<" 2.25 lITER DONE \n";
										break;
									case 5:
										system("cls");
										cout<<setw(50)<<"\n                       #########################################               EXIT 7 UP                ####################################### \n ";
										break;
									default:
										system("cls");
										cout<<setw(50)<<"\n                                ########       WRONG INPUT      ########\n";		
								}
							    }while(choice1 != 5);
							    break;
						case 2:
								system("cls");
								do{
					            cout<<"\n\n\n";
						        cout<<setw(50)<<"                                ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~             \n";
					            cout<<setw(50)<<"                                |               COKA COLA              |             \n";
					            cout<<setw(50)<<"                                ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~             \n";
					            cout<<setw(50)<<"                                |       1  .  RAGULAR                  |             \n";
					            cout<<setw(50)<<"                                |                                      |             \n";
					            cout<<setw(50)<<"                                |                                      |             \n";
					            cout<<setw(50)<<"                                |       2  .  1 lITER                  |             \n";
					            cout<<setw(50)<<"                                |                                      |             \n";
					            cout<<setw(50)<<"                                |                                      |             \n";
					            cout<<setw(50)<<"                                |       3  .  1.5 lITER                |             \n";
					            cout<<setw(50)<<"                                |                                      |             \n";
					            cout<<setw(50)<<"                                |                                      |             \n";
					            cout<<setw(50)<<"                                |       4  .  2.25 lITER               |             \n";
					            cout<<setw(50)<<"                                |                                      |             \n";
					            cout<<setw(50)<<"                                ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~             \n";
					            cout<<setw(50)<<"                                |               5 . EXIT               |             \n";
					            cout<<setw(50)<<"                                ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~             \n";
					            cout<<setw(40)<<"                                Choice : ";
					            cin>>choice1;
					            switch(choice1)
								{
									case 1:
										cout<<"                                RAGULAR \n";
										cout<<"                                Amount : ";
										cin>>quantity;
										F.COKE_COLA(choice1,quantity);
										system("cls");
										cout<<"                                        "<<quantity<<" RAGULAR DONE \n"; 
										break;
									case 2:
										cout<<"                                1 lITER \n";
										cout<<"                                Amount : ";
										cin>>quantity;
										F.COKE_COLA(choice1,quantity);
										system("cls");
										cout<<"                                        "<<quantity<<" 1 lITER DONE \n";
										break;
									case 3:
										cout<<"                                1.5 lITER\n";
										cout<<"                                Amount : ";
										cin>>quantity;
										F.COKE_COLA(choice1,quantity);
										system("cls");
										cout<<"                                        "<<quantity<<" 1.5 lITER DONE \n";
										break;
									case 4:
										cout<<"                                2.25 lITER\n";
										cout<<"                                Amount : ";
										cin>>quantity;
										F.COKE_COLA(choice1,quantity);
										system("cls");
										cout<<"                                        "<<quantity<<" 2.25 lITER DONE \n";
										break;
									case 5:
										system("cls");
										cout<<setw(50)<<"\n                       #######################################              EXIT COKA COLA                ##################################### \n ";
										break;
									default:
										system("cls");
										cout<<setw(50)<<"\n                                ########       WRONG INPUT      ########\n";		
								}
							    }while(choice1 != 5);
							    break;
						case 3:
								system("cls");
								do{
					            cout<<"\n\n\n";
						        cout<<setw(50)<<"                                ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~             \n";
					            cout<<setw(50)<<"                                |                 FANTA                |             \n";
					            cout<<setw(50)<<"                                ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~             \n";
					            cout<<setw(50)<<"                                |       1  .  RAGULAR                  |             \n";
					            cout<<setw(50)<<"                                |                                      |             \n";
					            cout<<setw(50)<<"                                |                                      |             \n";
					            cout<<setw(50)<<"                                |       2  .  1 lITER                  |             \n";
					            cout<<setw(50)<<"                                |                                      |             \n";
					            cout<<setw(50)<<"                                |                                      |             \n";
					            cout<<setw(50)<<"                                |       3  .  1.5 lITER                |             \n";
					            cout<<setw(50)<<"                                |                                      |             \n";
					            cout<<setw(50)<<"                                |                                      |             \n";
					            cout<<setw(50)<<"                                |       4  .  2.25 lITER               |             \n";
					            cout<<setw(50)<<"                                |                                      |             \n";
					            cout<<setw(50)<<"                                ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~             \n";
					            cout<<setw(50)<<"                                |               5 . EXIT               |             \n";
					            cout<<setw(50)<<"                                ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~             \n";
					            cout<<setw(40)<<"                                Choice : ";
					            cin>>choice1;
					            switch(choice1)
								{
									case 1:
										cout<<"                                RAGULAR \n";
										cout<<"                                Amount : ";
										cin>>quantity;
										F.Fanta(choice1,quantity);
										system("cls");
										cout<<"                                        "<<quantity<<" RAGULAR DONE \n"; 
										break;
									case 2:
										cout<<"                                1 lITER \n";
										cout<<"                                Amount : ";
										cin>>quantity;
										F.Fanta(choice1,quantity);
										system("cls");
										cout<<"                                        "<<quantity<<" 1 lITER DONE \n";
										break;
									case 3:
										cout<<"                                1.5 lITER\n";
										cout<<"                                Amount : ";
										cin>>quantity;
										F.Fanta(choice1,quantity);
										system("cls");
										cout<<"                                        "<<quantity<<" 1.5 lITER DONE \n";
										break;
									case 4:
										cout<<"                                2.25 lITER\n";
										cout<<"                                Amount : ";
										cin>>quantity;
										F.Fanta(choice1,quantity);
										system("cls");
										cout<<"                                        "<<quantity<<" 2.25 lITER DONE \n";
										break;
									case 5:
										system("cls");
										cout<<setw(50)<<"\n                       #########################################               EXIT FANTA               ####################################### \n ";
										break;
									default:
										system("cls");
										cout<<setw(50)<<"\n                                ########       WRONG INPUT      ########\n";		
								}
							    }while(choice1 != 5);
							    break;
						case 4:
								system("cls");
								do{
					            cout<<"\n\n\n";
						        cout<<setw(50)<<"                                ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~             \n";
					            cout<<setw(50)<<"                                |                 STRING               |             \n";
					            cout<<setw(50)<<"                                ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~             \n";
					            cout<<setw(50)<<"                                |       1  .  RAGULAR                  |             \n";
					            cout<<setw(50)<<"                                |                                      |             \n";
					            cout<<setw(50)<<"                                |                                      |             \n";
					            cout<<setw(50)<<"                                |       2  .  1 lITER                  |             \n";
					            cout<<setw(50)<<"                                |                                      |             \n";
					            cout<<setw(50)<<"                                |                                      |             \n";
					            cout<<setw(50)<<"                                |       3  .  1.5 lITER                |             \n";
					            cout<<setw(50)<<"                                |                                      |             \n";
					            cout<<setw(50)<<"                                |                                      |             \n";
					            cout<<setw(50)<<"                                |       4  .  2.25 lITER               |             \n";
					            cout<<setw(50)<<"                                |                                      |             \n";
					            cout<<setw(50)<<"                                ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~             \n";
					            cout<<setw(50)<<"                                |               5 . EXIT               |             \n";
					            cout<<setw(50)<<"                                ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~             \n";
					            cout<<setw(40)<<"                                Choice : ";
					            cin>>choice1;
					            switch(choice1)
								{
									case 1:
										cout<<"                                RAGULAR \n";
										cout<<"                                Amount : ";
										cin>>quantity;
										F.STRING(choice1,quantity);
										system("cls");
										cout<<"                                        "<<quantity<<" RAGULAR DONE \n"; 
										break;
									case 2:
										cout<<"                                1 lITER \n";
										cout<<"                                Amount : ";
										cin>>quantity;
										F.STRING(choice1,quantity);
										system("cls");
										cout<<"                                        "<<quantity<<" 1 lITER DONE \n";
										break;
									case 3:
										cout<<"                                1.5 lITER\n";
										cout<<"                                Amount : ";
										cin>>quantity;
										F.STRING(choice1,quantity);
										system("cls");
										cout<<"                                        "<<quantity<<" 1.5 lITER DONE \n";
										break;
									case 4:
										cout<<"                                2.25 lITER\n";
										cout<<"                                Amount : ";
										cin>>quantity;
										F.STRING(choice1,quantity);
										system("cls");
										cout<<"                                        "<<quantity<<" 2.25 lITER DONE \n";
										break;
									case 5:
										system("cls");
										cout<<setw(50)<<"\n                       ########################################               EXIT STRING                ###################################### \n ";
										break;
									default:
										system("cls");
										cout<<setw(50)<<"\n                                ########       WRONG INPUT      ########\n";		
								}
							    }while(choice1 != 5);
							    break;
						case 5:
								system("cls");
								do{
					            cout<<"\n\n\n";
						        cout<<setw(50)<<"                                ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~             \n";
					            cout<<setw(50)<<"                                |             MINERAL WATER            |             \n";
					            cout<<setw(50)<<"                                ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~             \n";
					            cout<<setw(50)<<"                                |       1  .  RAGULAR                  |             \n";
					            cout<<setw(50)<<"                                |                                      |             \n";
					            cout<<setw(50)<<"                                |                                      |             \n";
					            cout<<setw(50)<<"                                |       2  .  1.5 lITER                |             \n";
					            cout<<setw(50)<<"                                |                                      |             \n";
					            cout<<setw(50)<<"                                ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~             \n";
					            cout<<setw(50)<<"                                |               3 . EXIT               |             \n";
					            cout<<setw(50)<<"                                ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~             \n";
					            cout<<setw(40)<<"                                Choice : ";
					            cin>>choice1;
					            switch(choice1)
								{
									case 1:
										cout<<"                                RAGULAR \n";
										cout<<"                                Amount : ";
										cin>>quantity;
										F.WATER(choice1,quantity);
										system("cls");
										cout<<"                                        "<<quantity<<" RAGULAR DONE \n"; 
										break;
									case 2:
										cout<<"                                1.5 lITER\n";
										cout<<"                                Amount : ";
										cin>>quantity;
										F.WATER(choice1,quantity);
										system("cls");
										cout<<"                                        "<<quantity<<" 1.5 lITER DONE \n";
										break;
									case 3:
										system("cls");
										cout<<setw(50)<<"\n                       #########################################               EXIT 7 UP                ####################################### \n ";
										break;
									default:
										system("cls");
										cout<<setw(50)<<"\n                                ########       WRONG INPUT      ########\n";		
								}
							    }while(choice1 != 3);
							    break;
						case 6:
								system("cls");
								do{
					            cout<<"\n\n\n";
						        cout<<setw(50)<<"                                ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~             \n";
					            cout<<setw(50)<<"                                |             MANGO JUICE/SHAKE        |             \n";
					            cout<<setw(50)<<"                                ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~             \n";
					            cout<<setw(50)<<"                                |       1  .  RAGULAR                  |             \n";
					            cout<<setw(50)<<"                                |                                      |             \n";
					            cout<<setw(50)<<"                                |                                      |             \n";
					            cout<<setw(50)<<"                                |       2  .  1 lITER                  |             \n";
					            cout<<setw(50)<<"                                |                                      |             \n";
					            cout<<setw(50)<<"                                ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~             \n";
					            cout<<setw(50)<<"                                |               3 . EXIT               |             \n";
					            cout<<setw(50)<<"                                ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~             \n";
					            cout<<setw(40)<<"                                Choice : ";
					            cin>>choice1;
					            switch(choice1)
								{
									case 1:
										cout<<"                                RAGULAR \n";
										cout<<"                                Amount : ";
										cin>>quantity;
										F.MANGO_JUICE(choice1,quantity);
										system("cls");
										cout<<"                                        "<<quantity<<" RAGULAR DONE \n"; 
										break;
									case 2:
										cout<<"                                1 lITER\n";
										cout<<"                                Amount : ";
										cin>>quantity;
										F.MANGO_JUICE(choice1,quantity);
										system("cls");
										cout<<"                                        "<<quantity<<" 1 lITER DONE \n";
										break;
									case 3:
										system("cls");
										cout<<setw(50)<<"\n                       ####################################              EXIT MANGO JUICE/SHAKE              ################################## \n ";
										break;
									default:
										system("cls");
										cout<<setw(50)<<"\n                                ########       WRONG INPUT      ########\n";		
								}
							    }while(choice1 != 3);
							    break;
						case 7:
								system("cls");
								do{
					            cout<<"\n\n\n";
						        cout<<setw(50)<<"                                ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~             \n";
					            cout<<setw(50)<<"                                |             BANANA JUICE/SHAKE       |             \n";
					            cout<<setw(50)<<"                                ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~             \n";
					            cout<<setw(50)<<"                                |       1  .  RAGULAR                  |             \n";
					            cout<<setw(50)<<"                                |                                      |             \n";
					            cout<<setw(50)<<"                                |                                      |             \n";
					            cout<<setw(50)<<"                                |       2  .  1 lITER                  |             \n";
					            cout<<setw(50)<<"                                |                                      |             \n";
					            cout<<setw(50)<<"                                ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~             \n";
					            cout<<setw(50)<<"                                |               3 . EXIT               |             \n";
					            cout<<setw(50)<<"                                ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~             \n";
					            cout<<setw(40)<<"                                Choice : ";
					            cin>>choice1;
					            switch(choice1)
								{
									case 1:
										cout<<"                                RAGULAR \n";
										cout<<"                                Amount : ";
										cin>>quantity;
										F.BANANA_JUICE(choice1,quantity);
										system("cls");
										cout<<"                                        "<<quantity<<" RAGULAR DONE \n"; 
										break;
									case 2:
										cout<<"                                1 lITER\n";
										cout<<"                                Amount : ";
										cin>>quantity;
										F.BANANA_JUICE(choice1,quantity);
										system("cls");
										cout<<"                                        "<<quantity<<" 1 lITER DONE \n";
										break;
									case 3:
										system("cls");
										cout<<setw(50)<<"\n                       ####################################              EXIT BANANA JUICE/SHAKE             ################################## \n ";
										break;
									default:
										system("cls");
										cout<<setw(50)<<"\n                                ########       WRONG INPUT      ########\n";		
								}
							    }while(choice1 != 3);
							    break;
						case 8:
								system("cls");
								do{
					            cout<<"\n\n\n";
						        cout<<setw(50)<<"                                ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~             \n";
					            cout<<setw(50)<<"                                |         STRAWBERRY JUICE/SHAKE       |             \n";
					            cout<<setw(50)<<"                                ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~             \n";
					            cout<<setw(50)<<"                                |       1  .  RAGULAR                  |             \n";
					            cout<<setw(50)<<"                                |                                      |             \n";
					            cout<<setw(50)<<"                                |                                      |             \n";
					            cout<<setw(50)<<"                                |       2  .  1 lITER                  |             \n";
					            cout<<setw(50)<<"                                |                                      |             \n";
					            cout<<setw(50)<<"                                ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~             \n";
					            cout<<setw(50)<<"                                |               3 . EXIT               |             \n";
					            cout<<setw(50)<<"                                ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~             \n";
					            cout<<setw(40)<<"                                Choice : ";
					            cin>>choice1;
					            switch(choice1)
								{
									case 1:
										cout<<"                                RAGULAR \n";
										cout<<"                                Amount : ";
										cin>>quantity;
										F.STAWBERRY_JUICE(choice1,quantity);
										system("cls");
										cout<<"                                        "<<quantity<<" RAGULAR DONE \n"; 
										break;
									case 2:
										cout<<"                                1 lITER\n";
										cout<<"                                Amount : ";
										cin>>quantity;
										F.STAWBERRY_JUICE(choice1,quantity);
										system("cls");
										cout<<"                                        "<<quantity<<" 1 lITER DONE \n";
										break;
									case 3:
										system("cls");
										cout<<setw(50)<<"\n                       #################################              EXIT STRAWBERRY JUICE/SHAKE             ################################ \n ";
										break;
									default:
										system("cls");
										cout<<setw(50)<<"\n                                ########       WRONG INPUT      ########\n";		
								}
							    }while(choice1 != 3);
							    break;
						case 9:
								system("cls");
								do{
					            cout<<"\n\n\n";
						        cout<<setw(50)<<"                                ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~             \n";
					            cout<<setw(50)<<"                                |             APPLE JUICE              |             \n";
					            cout<<setw(50)<<"                                ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~             \n";
					            cout<<setw(50)<<"                                |       1  .  RAGULAR                  |             \n";
					            cout<<setw(50)<<"                                |                                      |             \n";
					            cout<<setw(50)<<"                                |                                      |             \n";
					            cout<<setw(50)<<"                                |       2  .  1 lITER                  |             \n";
					            cout<<setw(50)<<"                                |                                      |             \n";
					            cout<<setw(50)<<"                                ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~             \n";
					            cout<<setw(50)<<"                                |               3 . EXIT               |             \n";
					            cout<<setw(50)<<"                                ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~             \n";
					            cout<<setw(40)<<"                                Choice : ";
					            cin>>choice1;
					            switch(choice1)
								{
									case 1:
										cout<<"                                RAGULAR \n";
										cout<<"                                Amount : ";
										cin>>quantity;
										F.APPLE_JUICE(choice1,quantity);
										system("cls");
										cout<<"                                        "<<quantity<<" RAGULAR DONE \n"; 
										break;
									case 2:
										cout<<"                                1 lITER\n";
										cout<<"                                Amount : ";
										cin>>quantity;
										F.APPLE_JUICE(choice1,quantity);
										system("cls");
										cout<<"                                        "<<quantity<<" 1 lITER DONE \n";
										break;
									case 3:
										system("cls");
										cout<<setw(50)<<"\n                       ######################################               EXIT APPLE JUICE               #################################### \n ";
										break;
									default:
										system("cls");
										cout<<setw(50)<<"\n                                ########       WRONG INPUT      ########\n";		
								}
							    }while(choice1 != 3);
							    break;
						case 10:
								system("cls");
								do{
					            cout<<"\n\n\n";
						        cout<<setw(50)<<"                                ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~             \n";
					            cout<<setw(50)<<"                                |             ICE-CREAM SHAKE          |             \n";
					            cout<<setw(50)<<"                                ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~             \n";
					            cout<<setw(50)<<"                                |       1  .  RAGULAR                  |             \n";
					            cout<<setw(50)<<"                                |                                      |             \n";
					            cout<<setw(50)<<"                                |                                      |             \n";
					            cout<<setw(50)<<"                                |       2  .  1 lITER                  |             \n";
					            cout<<setw(50)<<"                                |                                      |             \n";
					            cout<<setw(50)<<"                                ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~             \n";
					            cout<<setw(50)<<"                                |               3 . EXIT               |             \n";
					            cout<<setw(50)<<"                                ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~             \n";
					            cout<<setw(40)<<"                                Choice : ";
					            cin>>choice1;
					            switch(choice1)
								{
									case 1:
										cout<<"                                RAGULAR \n";
										cout<<"                                Amount : ";
										cin>>quantity;
										F.ICE_CREAM_Shake(choice1,quantity);
										system("cls");
										cout<<"                                        "<<quantity<<" RAGULAR DONE \n"; 
										break;
									case 2:
										cout<<"                                1 lITER\n";
										cout<<"                                Amount : ";
										cin>>quantity;
										F.ICE_CREAM_Shake(choice1,quantity);
										system("cls");
										cout<<"                                        "<<quantity<<" 1 lITER DONE \n";
										break;
									case 3:
										system("cls");
										cout<<setw(50)<<"\n                       #####################################              EXIT ICE-CREAM SHAKE              ################################### \n ";
										break;
									default:
										system("cls");
										cout<<setw(50)<<"\n                                ########       WRONG INPUT      ########\n";		
								}
							    }while(choice1 != 3);
							    break;
						case 11:
							system("cls");
							cout<<setw(50)<<"\n                                ####################               EXIT DRINKS              ####################### \n ";
							break;
						default:
							system("cls");
							cout<<setw(50)<<"\n                       #######################################                WRONG INPUT               ####################################### \n ";
						}
					    }while(choice!=11);
					}
					else if (choice==5)
					{
						system("cls");
						F.DISPLAY_BILL2();
						getch();
						system("cls");
						cout<<setw(50)<<"                                ######################   EXIT MENU    ######################               \n";
					}
					else
					{
						system("cls");
						cout<<setw(50)<<"\n                                #############################      WRONG INPUT     ################################ \n ";	
					}
					}while(choice !=5);
					break;
				case 2:
					system("cls");
					cout<<"\n\n\n\n\n\n";
					cout<<setw(50)<<"                                ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~               \n";
					cout<<setw(50)<<"                                |                     YOUR RECORD                          |               \n";
					cout<<setw(50)<<"                                ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~               \n";
					break;
				case 3:
					system("cls");
					cout<<"\n\n\n\n\n\n\n\n\n\n\n\n";
					system("color f4");
					cout<<setw(50)<<"                                ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~               \n";
					cout<<setw(50)<<"                                |                     LOG OUT                              |               \n";
					cout<<setw(50)<<"                                ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~               \n";
					getch();
					system("cls");

					temp=false;
					break;
			}
		}while(choice != 3);
		}
		else
		{
		    system("cls");
		    temp=true;
		}
	//}while(temp1==false);
    }while(i!=s);
	return 0;
}
void Information::UPDATE_FOOD_FILE(string n,string p)
{
			ifstream File("FOOD.txt");
			vector<string> line;
			if(File.is_open())
			{
				string l;
				while(getline(File,l))
				{
					line.push_back(l);
				}
			}
			File.close();
			
			for(string& readLine : line)
			{
				size_t position = readLine.find(n); 
				int s = n.length();
				if(position != string::npos)
				{
					readLine.replace(s+1,readLine.length(),p);
					break;
				}
			}
			ofstream oFile("FOOD.txt", ios::out | ios::trunc);
			if(oFile.is_open())
			{
				for(const string& updateLine : line)
				{
					oFile<<updateLine<<endl;
				}
			}
			oFile.close();
}
