#include <iostream>              //library to include input and out put streams.
#include <time.h>                //library to include time.
#include<iomanip>                //library to manipulate  the output.

using namespace std;

      void medicene_search();   //medicine search
      void medicene_order();        //function to take order.
      void payment();           //function to pay and receive  receipt.
      void new_med_reg();           //function to register medicine.
      void med_can();           //function to medicine cancellation.
      void daily_sum();            //function to daily summary.
      void courent_day(int a);  // print local time automatically.
      void leave();


const int Max = 50; //global variable

struct 	transaction    //child structure of receipt!
  {
    string med_name;
    int quantity;
    float price;

  };
    transaction t[Max];


struct reciept     //nested structure / parent structure/structure array!
  {
    int reciept_number;
	string customerName;
	string timecpy;
    transaction t[Max];
  };
    reciept r[Max];


struct medicene    //structure within array
  {
    int max_o=0;
    int num_reciept;
	string date[3];
	int ID[Max];
    int quantity[Max];
	int med_quan[Max]={500,250,143,567,85,46,23,90,32,50};
	int x, menu2[Max];
    double amount[Max];
    string medicine_ep_d[Max]={"12-02-2027","12-02-2027","22-22-2024","10-6-2026","29-7-2028","16-01-2022","25-01-2023","30-05-2027","11-09-2027","1-12-2026"};
    string medicineName[Max]={"Paracetamol","Vitamin C","Acid Free C","Surgical Mask","Panadol","Sanitizer",
	"Amino Zinc Tablet","Insulin","Amoxacillin","ORS"};
	int medicene_Shelf[Max]={3,1,9,6,11,4,5,3,2,9};
	double Medicine_price[Max] = {15.00,60.00,16.00,5.00,10.00,75.00,65.00,90.00,30.00,60.00};
	double total;
  }m;


int main()  //main function.

{
   system("color 3f"); //Windows-specific command to change background color of the terminal.

 int RESPONSE;
    do
       {
        system("cls"); //Windows-specific command to clear the system

        int RESPONSE;
        cout<<"\t\t\t\t\t\t \n";
		cout<<"\t\t\t\t\t  ==================================================\n";
		cout<<"\t\t\t\t\t /                KENEMA PHARMACY                  /|\n";
		cout<<"\t\t\t\t\t[+]=-------------------------------------------=[+] |\n";
		cout<<"\t\t\t\t\t|||\t       \t\t\t\t\t||| |\n";
		cout<<"\t\t\t\t\t|||\t1. Medicine order \t\t\t||| |\n";
		cout<<"\t\t\t\t\t|||\t2. Make Payment and Print the Receipt \t||| |\n";
		cout<<"\t\t\t\t\t|||\t3. New medicine register  \t\t||| |\n";
		cout<<"\t\t\t\t\t|||\t4. Medicine cancellation \t\t||| |\n";
        cout<<"\t\t\t\t\t|||\t5. daily summary         \t\t||| |\n";
        cout<<"\t\t\t\t\t|||\t6. Exit\t\t\t\t\t||| |\n";
		cout<<"\t\t\t\t\t|||\t       \t\t\t\t\t||| |\n";
		cout<<"\t\t\t\t\t[+]=-------------------------------------------=[+]/\n";
		cout<<"Enter your choice: ";
        cin>>RESPONSE;

switch(RESPONSE) //switch for the menu
		{
        case 1:
            medicene_order();//function calling.
            system("pause");//Windows-specific command,it will pause the function;
            break;
        case 2:
            payment();
            system("pause");
            break;
        case 3:
            new_med_reg();
            system("pause");
            break;
        case 4:
            med_can();
            system("pause");
            break;
        case 5:
            daily_sum();
            system("pause");
            break;

        case 6:
            goto a;
            break;
        default:
			{
				cout<<"You enter invalid input \n re-enter the input\n"<<endl;
				break;
            }
		}
   }
while(RESPONSE!=6);//end do
	a:

    cout<<"\t\t\t\t\t {<>}{<>}{<>}{<>}------------------------- Thank you!!! --------------------{<>}{<>}{<>}{<>}"<<endl;
    exit(0);
    system("pause");
	return 0;
}
void medicene_order()//medicine order function definition.
{
    m.max_o=0;
    system("cls");
    cout<<endl;
    cout <<"\t\t /***************************************************************************************************/^\n";
    cout<<"\t\t|)   "<<left<<setw(10)<<"DRUGS ID"<<"| "<<setw(10)<<" QUANTITY "<<"|"<<setw(25)<<"   DRUGS NAME"<<" |"<<setw(10)<<" PRICE(Birr)"<<"|"<<setw(15)<<"   EXPIRE DATE"<<" |"<<setw(10)<<" SHELF NUMBER"<<"||  |"<<endl;
    cout <<"\t\t****************************************************************************************************--|\n";
        for(int i=0;i<34;i++) // display medicine informations.
                {
                    if(m.Medicine_price[i]!=NULL)
                         {
                            cout<<"\t\t!}"<<"-------------------------------------------------------------------------------------------------{ /"<<endl;
                            cout<<"\t\t(  00"<<left<<setw(10)<<i+1<<"| "<<setw(10)<<m.med_quan[i]<<"| "<<setw(25)<<m.medicineName[i]<<"|  "<<setw(10)<<m.Medicine_price[i]<<"| "<<setw(15)<<m.medicine_ep_d[i]<<"| "<<setw(13)<<m.medicene_Shelf[i]<<")  |"<<endl;
                            m.max_o++;//maximum order increase.
                         }
                    else
                        break;
                }
            cout <<"\t\t ***************************************************************************************************\n";
            cout<<endl;
leave();

for(int r_n=0;r_n<Max;r_n++)
    {
    if(r[r_n].reciept_number==NULL)

    {
         cout <<endl;
         cout << " {<>} Receipt  Number: ";
         cin >> r[r_n].reciept_number;
         cout<< " {<>} Enter Customer Name: ";
         cin.ignore();//ignore garbage input.
         getline(cin, r[r_n].customerName);
         courent_day(r_n);//function calling for the time.
         cout << " {<>} How many Medicine would you like to order"<<" (Maximum is "<<m.max_o<<"  order for each transaction ): ";
         cin >> m.x;
	if (m.x > m.max_o)//excess order.
	   {
		 cout << " {<>} The Medicine you order is exceed the maximum amount of order !";
		 system("pause");
       }

	else{

	       for (int i=0; i<m.x; i++)//looping that gives chances to get your all order.
	          {
                 c:
                    medicene_search();

		         cout << " {<>} Please enter your selection ID Number: ";
		         cin>> m.menu2[i];
		         cout<<endl;

                  if(m.med_quan[m.menu2[i]-1]!=0 )//check if there is  supply.
                        {
                             cout<< "    {<>} Medicine Name: " <<m.medicineName[m.menu2[i]-1]<<endl;
                             cout<< "    {<>} Medicine price: " <<m.Medicine_price[m.menu2[i]-1]<<" Birr"<<endl;
                             cout <<"    {<>} How many Medicine do you want: ";
                             cin >>m. quantity[i];
                             cout<<endl;
                             m.amount[i] = m.quantity[i] *m.Medicine_price[m.menu2[i]-1];//
                             cout << "    {<>} The amount You need to pay is: " <<m.amount[i]<<" Birr"<<endl;
                             m.med_quan[m.menu2[i]-1]-=m.quantity[i];//the quantity of the medicine will decrease.

                    //to save the info to receipt structure!
                            r[r_n].t[i].med_name=m.medicineName[m.menu2[i]-1];
                            r[r_n].t[i].quantity=m. quantity[i];
                            r[r_n].t[i].price=m.amount[i];
                        }
                    else{
                        cout<<"\t\t\t\t\t {<>}{<>}{<>}{<>}--------------------sorry we do not have supply --------------{<>}{<>}{<>}{<>}"<<endl;
                        goto c;
                        }
        system("PAUSE");

	}
	cout<<"\t\t\t\t\t {<>}{<>}================================================{<>}{<>}\n";
    cout<<"\t\t\t\t\t {<>}"<<setw(45)<<"              Order Taken Successfully"<<"           {<>}"<<endl;
    cout<<"\t\t\t\t\t {<>}{<>}------------------------------------------------{<>}{<>}"<<endl;
    cout<<"\t\t\t\t\t {<>}"<<setw(45)<<"           Go To PAYMENT Menu To Pay The Bill"<<"           {<>}"<<endl;
    cout<<"\t\t\t\t\t {<>}{<>}================================================{<>}{<>}\n";

   system("pause");
    }
    break;
  }
}
}//medicine order function end.

void payment()//payment and receipt function definition.

   {
       system("cls");
       bool found=false;
       int reciept_number2;//declaration for receipt number that will entered by the user.
         int cash;               //declaration for cash input.

   cout<<endl;
   cout<<"\t\t\t\t\t {<>}{<>}{<>}{<>} =================================================={<>}{<>}{<>}{<>}\n";
   cout<<"\t\t\t\t\t {<>}{<>}{<>}{<>}        DO NOT PAY BILLS WITHOUT A RECEIPT!!!      {<>}{<>}{<>}{<>}\n";
   cout<<"\t\t\t\t\t {<>}{<>}{<>}{<>} =================================================={<>}{<>}{<>}{<>}\n";
   cout<<" \n";
    b:
    	leave();
   cout<<" {<>} Enter the Receipt Number To Print The Receipt ";
   cin>>reciept_number2;
   cout<<" \n";

   for(int r_n=0;r_n<=Max;r_n++)
  {
      if(reciept_number2==r[r_n].reciept_number)//check if exist.
    {
      found==true;
      cout <<" {<>} Receipt Number : "<<r[r_n].reciept_number;
      cout <<"\n";
      cout<<" {<>} Customer Name: "<<r[r_n].customerName<<endl;
      cout<<" {<>} Order Date : "<<r[r_n].timecpy<<endl;
      cout<<"\n";

	cout<<"\t\t\t\t\t {<>}{<>}{<>}{<>} =================================================={<>}{<>}{<>}{<>}\n";
	cout <<"\t\t\t\t\t {<>}{<>}{<>}                 Here is the Order list                    {<>}{<>}{<>}\n";
	cout<<"\t\t\t\t\t {<>}{<>}_________ _______________________________________________ _________{<>}{<>}\n";
    cout<<"\t\t\t\t\t {<>}                                                                           {<>}"<<endl;
    cout<<left<<"\t\t\t\t\t {<>}  \t "<<setw(25)<<"medicine name"<<setw(25)<<" Quantity"<<setw(21)<<" price "<<"{<>}"<<endl;
    cout<<"\t\t\t\t\t  ||                                                                             ||"<<endl;

    for (int i=0;i<m.x;i++)//looping for print all the orders.
		{
         cout<<left<<"\t\t\t\t\t  ||   \t "<<setw(25)<<r[r_n].t[i].med_name<<setw(25)<<r[r_n].t[i].quantity<<setw(21)<<r[r_n].t[i].price<<" ||"<<endl;
        }

         for(int i=0;i<m.x;i++)
          {
            m.total = m.total+ m.amount[i];// total amount of salary.
          }
        cout<<"\t\t\t\t\t  ||                                                                             ||"<<endl;
        cout<<"\t\t\t\t\t {<>}                                                                           {<>}"<<endl;
        cout<<"\t\t\t\t\t {<>}{<>}                                                                   {<>}{<>}"<<endl;
        cout <<left<<"\t\t\t\t\t {<>}{<>}{<>}    "<<"   Total Bill is : "<<setw(7)<<m.total<<"Birr"<<"\t\t\t        {<>}{<>}{<>}\n";
        cout<<"\t\t\t\t\t {<>}{<>}{<>}{<>} =================================================={<>}{<>}{<>}{<>}\n";
		cout<<"\n";
		cout << "{<>}Type the exact amount You need to pay: ";
        cin >> cash;
        cout <<"\n";
		cout <<"\n";
		cout<<"\t\t\t\t\t {<>}{<>}          Payment Done           {<>}{<>}\n";
		cout<<"\t\t\t\t\t {<>}{<>}{<>}{<>}   Thank You     {<>}{<>}{<>}{<>}\n";
		cout<<"\t\t\t\t\t\n_______________________________________________________________________________\n";
		break;
    }


  }
  if(found==false)
     {
        cout<<" {<>}The Receipt is not exist!\n";
         goto b;//jump b.
     }

    system("pause");
}//payment and receipt function.


void new_med_reg()//medicine registration function definition.
{
   system("cls");
   int num_of_med,i=1,j,coutj=0;
   cout<<endl;
   cout<<"\t\t\t\t\t {<>}{<>}{<>}{<>} =================================================={<>}{<>}{<>}{<>}\n";
   cout<<"\t\t\t\t\t {<>}{<>}          BE CAREFUL WITH THE INORMATION OF THE MEDICINE!!!        {<>}{<>}\n";
   cout<<"\t\t\t\t\t {<>}{<>}{<>}{<>} =================================================={<>}{<>}{<>}{<>}\n";
   cout<<" \n";
   cout<<" <+> How many Medicine do you want to register? ";
   cin>>num_of_med;

    for(j=9;j<=Max;j++)//add drugs
      {
    if(m.Medicine_price[j]==NULL)// To jump stored arrays.

       if(i<=num_of_med)//give chance as we went to add.
          {
            cout<<"\t===Enter Medicine Information  ---{ "<<i<<" }---"<<endl;
            cout<<endl;
            cout<<" <+> Enter Medicine Name :  ";
            cin.ignore();//to ignore garbage inputs.
            getline(cin,m.medicineName[j]);
            cout<<" <+> Enter Medicine quantity :  ";
            cin>>m.med_quan[j];
            cout<<" <+> Enter Medicine Expire Date (DD-MM-YY) : ";
            cin.ignore();
            getline(cin,m.medicine_ep_d[j]);
            cout<<" <+> Enter Medicine Price : ";
            cin>>m.Medicine_price[j];
            cout<<" <+> Enter Medicine SHELF : ";
            cin>> m.medicene_Shelf[j];
            cout<<endl;
             i=i+1;
          }
      }

          cout << "\t\t\t\t\t {<>}{<>}{<>}{<>}--Medicine Registered Successfully--{<>}{<>}{<>}{<>}\n"<<endl;


    system("pause");
}//medicine registration function end.

void med_can()//medicine cancellation function definition.


   {
     system("cls");
      int i,id_num;

      cout<<"\t\t\t\t\t {<>}{<>}{<>}{<>} =================================================={<>}{<>}{<>}{<>}\n";
      cout<<"\t\t\t\t\t {<>}{<>}         EXPIRED  MEDICINE MUST BE REMOVED!!!                     {<>}{<>}\n";
      cout<<"\t\t\t\t\t {<>}{<>}{<>}{<>} =================================================={<>}{<>}{<>}{<>}\n";
      cout<<endl;

     medicene_search();

      cout<<"\n\nEnter ID number of the medicine to remove from the store : ";
      cin>>id_num;

   if(id_num>m.max_o)//if it exist.
       {
        cout<<"\n\nThis ID number is not exist ! ";
       }
   else
      {
        --id_num;//to decrease array index.
        for(i=id_num;i<=m.max_o;i++)//it will interchange array elements starts from the deleted array downward.
              {
                   m.med_quan[i]=m.med_quan[i+1];
                   m.medicineName[i]=m.medicineName[i+1];
                   m.medicine_ep_d[i]=m.medicine_ep_d[i+1];
                   m.Medicine_price[i]=m.Medicine_price[i+1];

               }

       }
cout<<endl;
cout<<endl;
cout << "\t\t\t\t\t {<>}{<>}{<>}{<>}--Medicine Removed Successfully--{<>}{<>}{<>}{<>}\n"<<endl;

    system("pause");

}//medicine cancellation function end.

void medicene_search()
{
        s:
        bool found=false;//check searched string is not found found.
        string searched;
        cout<<" {<>} Please Search Here( Make The First letter Capital): ";
        cin>>searched;
        cout<<endl;

  for(int i=0;i<m.max_o;i++)
    {
        if(m.medicineName[i]==searched)//if the strings are equal.
            {
                cout<<"\t\t||   "<<"||>-----------------------------------------------------------------------------------------------|>"<<endl;
                cout<<"\t\t|||||||  "<<left<<setw(10)<<"DRUGS ID"<<"| "<<setw(10)<<" QUANTITY "<<"|"<<setw(25)<<"   DRUGS NAME"<<" |"<<setw(10)<<" PRICE(Birr)"<<"|"<<setw(15)<<"   EXPIRE DATE"<<" |"<<setw(10)<<" SHELF NUMBER"<<" | |----"<<endl;
                cout<<"\t\t"<<"|||||||>-----------------------------------------------------------------------------------------------| | | |}-------------------"<<endl;
                cout<<"\t\t|||||||00"<<left<<setw(10)<<i+1<<"| "<<setw(10)<<m.med_quan[i]<<"| "<<setw(25)<<m.medicineName[i]<<"|  "<<setw(10)<<m.Medicine_price[i]<<"| "<<setw(15)<<m.medicine_ep_d[i]<<"| "<<setw(13)<<m.medicene_Shelf[i]<<"| |----"<<endl;
                cout<<"\t\t"<<"||   ||>-----------------------------------------------------------------------------------------------|>"<<endl;
                cout<<endl;
                found=true;
            }

    }
           if(found==false)
                    {
                        cout<<"\t\t\t{<--->} We Have No This Type Of Medicine OR Make Sure Your Spelling Is Correct {<--->} "<<endl;
                        cout<<endl;
                         goto s;//jump to s.
                     }

}

void daily_sum()
    {   int total_sum=0;
            system("cls");
    cout<<endl;
    cout<<"\t\t\t\t\t {<>}{<>}{<>}{<>} =================================================={<>}{<>}{<>}{<>}\n";
    cout<<"\t\t\t\t\t {<>}{<>}             THIS IS SUMMARY OF DAILY SALD MEDECENCE!!!            {<>}{<>}\n";
    cout<<"\t\t\t\t\t {<>}------------ ==================================================------------{<>}\n";
    cout<<left<<"\t\t\t\t\t  []   \t "<<setw(25)<<"Medicine Name "<<setw(25)<<"Quantity"<<setw(21)<<"Price(Birr)"<<" []"<<endl;



     for (int r_n=0;r_n<Max;r_n++)          //loop for print all the orders.
		{  if(r[r_n].reciept_number!=NULL)   // if receipt  is not empty.
		     {
		        for(int i=0;i<Max;i++)
                  { if(r[r_n].t[i].quantity!=NULL)// if transaction is not empty.
                       {
                           cout<<left<<"\t\t\t\t\t  ||   \t "<<setw(25)<<r[r_n].t[i].med_name<<setw(25)<<r[r_n].t[i].quantity<<setw(21)<<r[r_n].t[i].price<<" ||"<<endl;
                           total_sum+=r[r_n].t[i].price;// update for total.
                       }

                  }
		     }
		     else
                break;

         }
    cout<<"\t\t\t\t\t  []                                                                             [] \n";
    cout<<"\t\t\t\t\t {<>}                                                                           {<>}\n";
    cout<<"\t\t\t\t\t {<>}{<>}       "<<"DAILY TOTAL REVENU IS: "<<setw(8)<<total_sum<<"Birr  \t\t            {<>}{<>}\n";
    cout<<"\t\t\t\t\t {<>}{<>}{<>}{<>} =================================================={<>}{<>}{<>}{<>}\n";

}  //daily summary function end.


void courent_day( int Max)//definition of function for print local time automatically .
    {
         time_t now = time(0);
         string dt = ctime(&now);// convert now to string form
         r[Max].timecpy=dt;
         cout << " {<>} date and time : " << r[Max].timecpy << endl;
    }   //function for local time automatically end.
     void leave()
     {
     	char des;
cout<<" Enter (Q) To Main Menu.  Any key To Continue : ";
cin>>des;

if(des=='q' || des=='Q')
    main();

	 }

