#include <iostream>
#include <string>
#include <cstdlib>
#include <string.h>

#define size 1000
using namespace std;

int seat[size];
string u_first_name;
string u_surname;
int u_id;
int u_age;
int u_phone;
int u_seat;
class airport{
	public:
		string location;
	airport(){
		location="none";
	}
	airport(string location){
		this->location=location;
	}
};
class plane{

	public:
		string p_location;
		string p_destination;
		int id;
		int e_seats;
		int b_seats;
		float e_price;
		float b_price;

	plane(){
	    p_location="none";
	    p_destination="none";
		id=0;
		e_seats=0;
		b_seats=0;
		e_price=0;
		b_price=0;
	}
	plane(string p_location,string p_destination, int id, int e_seats, int b_seats, float e_price, float b_price ){
		this->p_location=p_location;
		this->p_destination=p_destination;
		this->id=id;
		this->e_seats=e_seats;
		this->b_seats=b_seats;
		this->e_price=e_price;
		this->	b_price=b_price;
	}
	plane(plane &object){
         p_location=object.p_location;
         p_destination=object.p_destination;
	     id=object.id;
	}

	void seat_fill(){
		for(int i=1;i<=(e_seats+b_seats);i++){
			seat[i]=0;
		}
	}
};
class passenger{
    public:
        string first_name;
		string surname;
		int id;
		int age;
		int phone;
		passenger(){
		    first_name=" ";
		    surname=" ";
		    id=0;
		    age=0;
		    phone=0;
		}
		passenger(string first_name, string surname, int id, int age, int phone){
		    this->first_name=first_name;
		    this->surname=surname;
		    this->id=id;
		    this->age=age;
		    this->phone=phone;
		}
		~passenger();
		
};
class card{
     public:
        long card_nr;
        int cvv;
        string date;
        int sum;
        string first_name;
        string surname;
        card(){
            cout<<"Please enter your card number: ";
            cin>>card_nr;
            cout<<"Please enter your credit card surname: ";
            cin>>surname;
            cout<<"Please enter your credit card first name: ";
            cin>>first_name;
            cout<<"Please enter your cvv: ";
            cin>>cvv;
            cout<<"Please enter your expiry date: ";
            cin>>date;
            sum=1000;
        }

};
int main(){
    airport a1("London");
    airport a2("Bucharest");
    airport a3("Berlin");
    airport a4("Amsterdam");

    plane pl1("London","Bucharest",1076,100,50,220,350);
    plane pl2("Bucharest","Amsterdam",3029,150,25,200,300);
    plane pl3("Amsterdam","Berlin",2056,100,25,50,100);
    plane pl4("Berlin","Bucharest",4362,200,45,250,400);

    passenger pr1("Olteanu", "Catalin",23,23,4345);

    char choice;

do{
cout <<"\t \xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd \n";
cout <<"\t Create account    ------ [1] \n";
cout <<"\t \xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd \n";
cout <<"\t Book a flight  ------ [2] \n ";
cout <<"\t \xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd \n";
cout <<"\t See your flights  ------ [3] \n";
cout <<"\t \xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd \n";
cout <<"\t Delete your account  ------ [4] \n";
cout <<"\t \xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd \n";
cout <<"\t Quit        ------ [5] \n";
cout <<"\t \xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd \n";
cout <<"   Option : ";
  cin>>choice;
  choice=(int)choice-'0';
switch(choice){
    case 1:{cout<<"Please enter your first name: ";
            cin>>u_first_name;
            cout<<"Please enter your surname: ";
            cin>>u_surname;
            cout<<"Please enter your id: ";
            cin>>u_id;
            cout<<"Please enter your age: ";
            cin>>u_age;
            cout<<"Please enter your phone number: ";
            cin>>u_phone;
            passenger pr1(u_first_name, u_surname,u_id,u_age,u_phone);
            break;
            }
    case 2:{
        string loc,dest;
        cout<<"Please enter your location: ";
        cin>>loc;
        cout<<"Please enter your destination: ";
        cin>>dest;
        cout<<"Searching for flights...\n";
        if(loc==pl1.p_location){
            if(dest==pl1.p_destination){
                cout<<"!We found your plane!\n";
                cout<<"The prices are: \n";
                cout<<"For economy class: "<<pl1.e_price<<endl;
                cout<<"For bussiness class: "<<pl1.b_price<<endl;
                string answer;
                cout<<"Do you wish to buy a ticket?(Y/N)";
                cin>>answer;
                if(answer=="Y"||answer=="y"){
                    string clasa;
                    cout<<"Economy or bussiness class?(E/B)";
                    cin>>clasa;
                    if(clasa=="E"||clasa=="e"){
                        jump2:
                        cout<<"Please enter your credit card credentials\n";
                        card c1=card();
                        string m=c1.first_name;
                        if(m==pr1.first_name){
                            if(c1.sum>=pl1.e_price){
                                int p_seat;
                                jump:
                                cout<<" Please choose a seat number from 1 to "<<pl1.e_seats<<": ";
                                cin>>p_seat;
                                if(p_seat>pl1.e_seats){
                                    cout<<"!Please choose a valid seat number!\n";
                                    goto jump;
                                }
                                else{
                                    if(seat[p_seat]==0){
                                        seat[p_seat]=1;
                                        cout<<"You successfully bought a seat in flight number: "<<pl1.id<<endl;
                                        plane pl4(plane pl1);
                                    }
                                    else{
                                        cout<<"This seat is taken, please choose another one!\n";
                                        goto jump;
                                    }
                                }
                            }
                            else{
                                cout<<"Oops! Looks like you don't have enough money on your credit card!\n";
                                cout<<"We are sorry for the inconvenience, you will be redirected to our main page...\n";
                            }
                        }
                        else{
                            cout<<"We had a problem validating your card credentials \n";
                            cout<<"Please try again!";
                            goto jump2;
                        }
                    }
                    else{
                        jump3:
                            cout<<"Please enter your credit card credentials\n";
                            card c1=card();
                            if(c1.first_name==pr1.first_name){
                                    if(c1.sum>=pl1.b_price){
                                            int p_seat;
                                            jump4:
                                            cout<<" Please choose a seat number from 1 to "<<pl1.b_seats<<": ";
                                            cin>>p_seat;
                                            if(p_seat>pl1.b_seats){
                                                cout<<"!Please choose a valid seat number!";
                                                goto jump4;
                                            }
                                            else{
                                                if(seat[p_seat]==0){
                                                    seat[p_seat]=1;
                                                    cout<<"You successfully bought a seat in flight number: "<<pl1.id<<endl;
                                                    plane pl4(plane pl1);
                                                }
                                                else{
                                                    cout<<"This seat is taken, please choose another one!";
                                                    goto jump4;
                                                }
                                            }
                                    }
                                    else{
                                        cout<<"Oops! Looks like you don't have enough money on your credit card!\n";
                                        cout<<"We are sorry for the inconvenience, you will be redirected to our main page...\n";
                                    }

                            }
                            else{
                                cout<<"We had a problem validating your card credentials \n";
                                cout<<"Please try again!";
                                goto jump3;
                            }

                    }
                }
                else{
                    cout<<"We understand, thank you for your time!";
                }
            }
            else{
                cout<<"Sorry we could not find a flight to your destination";
            }
        }
        else{
            if(loc==pl2.p_location){
            if(dest==pl2.p_destination){
                cout<<"!We found your plane!\n";
                cout<<"The prices are: \n";
                cout<<"For economy class: "<<pl2.e_price<<endl;
                cout<<"For bussiness class: "<<pl2.b_price<<endl;
                string answer;
                cout<<"Do you wish to buy a ticket?(Y/N)";
                cin>>answer;
                if(answer=="Y"||answer=="y"){
                    string clasa;
                    cout<<"Economy or bussiness class?(E/B)";
                    cin>>clasa;
                    if(clasa=="E"||clasa=="e"){
                        jump5:
                        cout<<"Please enter your credit card credentials\n";
                        card c1=card();
                        string m=c1.first_name;
                        if(m==pr1.first_name){
                            if(c1.sum>=pl2.e_price){
                                int p_seat;
                                jump6:
                                cout<<" Please choose a seat number from 1 to "<<pl2.e_seats<<": ";
                                cin>>p_seat;
                                if(p_seat>pl2.e_seats){
                                    cout<<"!Please choose a valid seat number!\n";
                                    goto jump6;
                                }
                                else{
                                    if(seat[p_seat]==0){
                                        seat[p_seat]=1;
                                        cout<<"You successfully bought a seat in flight number: "<<pl2.id<<endl;
                                        plane pl4(plane pl2);
                                    }
                                    else{
                                        cout<<"This seat is taken, please choose another one!\n";
                                        goto jump6;
                                    }
                                }
                            }
                            else{
                                cout<<"Oops! Looks like you don't have enough money on your credit card!\n";
                                cout<<"We are sorry for the inconvenience, you will be redirected to our main page...\n";
                            }
                        }
                        else{
                            cout<<"We had a problem validating your card credentials \n";
                            cout<<"Please try again!";
                            goto jump5;
                        }
                    }
                    else{
                        jump8:
                            cout<<"Please enter your credit card credentials\n";
                            card c1=card();
                            if(c1.first_name==pr1.first_name){
                                    if(c1.sum>=pl2.b_price){
                                            int p_seat;
                                            jump7:
                                            cout<<" Please choose a seat number from 1 to "<<pl2.b_seats<<": ";
                                            cin>>p_seat;
                                            if(p_seat>pl2.b_seats){
                                                cout<<"!Please choose a valid seat number!";
                                                goto jump7;
                                            }
                                            else{
                                                if(seat[p_seat]==0){
                                                    seat[p_seat]=1;
                                                    cout<<"You successfully bought a seat in flight number: "<<pl2.id<<endl;
                                                    plane pl4(plane pl2);
                                                }
                                                else{
                                                    cout<<"This seat is taken, please choose another one!";
                                                    goto jump7;
                                                }
                                            }
                                    }
                                    else{
                                        cout<<"Oops! Looks like you don't have enough money on your credit card!\n";
                                        cout<<"We are sorry for the inconvenience, you will be redirected to our main page...\n";
                                    }

                            }
                            else{
                                cout<<"We had a problem validating your card credentials \n";
                                cout<<"Please try again!";
                                goto jump8;
                            }

                    }
                }
                else{
                    cout<<"We understand, thank you for your time!";
                }
            }
            else{
                cout<<"Sorry we could not find a flight to your destination";
            }
        }
        else{
            if(loc==pl3.p_location){
            if(dest==pl3.p_destination){
                cout<<"!We found your plane!\n";
                cout<<"The prices are: \n";
                cout<<"For economy class: "<<pl3.e_price<<endl;
                cout<<"For bussiness class: "<<pl3.b_price<<endl;
                string answer;
                cout<<"Do you wish to buy a ticket?(Y/N)";
                cin>>answer;
                if(answer=="Y"||answer=="y"){
                    string clasa;
                    cout<<"Economy or bussiness class?(E/B)";
                    cin>>clasa;
                    if(clasa=="E"||clasa=="e"){
                        jump9:
                        cout<<"Please enter your credit card credentials\n";
                        card c1=card();
                        string m=c1.first_name;
                        if(m==pr1.first_name){
                            if(c1.sum>=pl3.e_price){
                                int p_seat;
                                jump10:
                                cout<<" Please choose a seat number from 1 to "<<pl3.e_seats<<": ";
                                cin>>p_seat;
                                if(p_seat>pl3.e_seats){
                                    cout<<"!Please choose a valid seat number!\n";
                                    goto jump10;
                                }
                                else{
                                    if(seat[p_seat]==0){
                                        seat[p_seat]=1;
                                        cout<<"You successfully bought a seat in flight number: "<<pl3.id<<endl;
                                        plane pl4(plane p31);
                                    }
                                    else{
                                        cout<<"This seat is taken, please choose another one!\n";
                                        goto jump10;
                                    }
                                }
                            }
                            else{
                                cout<<"Oops! Looks like you don't have enough money on your credit card!\n";
                                cout<<"We are sorry for the inconvenience, you will be redirected to our main page...\n";
                            }
                        }
                        else{
                            cout<<"We had a problem validating your card credentials \n";
                            cout<<"Please try again!";
                            goto jump9;
                        }
                    }
                    else{
                        jump12:
                            cout<<"Please enter your credit card credentials\n";
                            card c1=card();
                            if(c1.first_name==pr1.first_name){
                                    if(c1.sum>=pl3.b_price){
                                            int p_seat;
                                            jump11:
                                            cout<<" Please choose a seat number from 1 to "<<pl3.b_seats;
                                            cin>>p_seat;
                                            if(p_seat>pl3.b_seats){
                                                cout<<"!Please choose a valid seat number!";
                                                goto jump11;
                                            }
                                            else{
                                                if(seat[p_seat]==0){
                                                    seat[p_seat]=1;
                                                    cout<<"You successfully bought a seat in flight number: "<<pl3.id<<endl;
                                                    plane pl4(plane p31);

                                                }
                                                else{
                                                    cout<<"This seat is taken, please choose another one!";
                                                    goto jump11;
                                                }
                                            }
                                    }
                                    else{
                                        cout<<"Oops! Looks like you don't have enough money on your credit card!\n";
                                        cout<<"We are sorry for the inconvenience, you will be redirected to our main page...\n";
                                    }

                            }
                            else{
                                cout<<"We had a problem validating your card credentials \n";
                                cout<<"Please try again!";
                                goto jump12;
                            }

                    }
                }
                else{
                    cout<<"We understand, thank you for your time!\n";
                }
            }
            else{
                cout<<"Sorry we could not find a flight to your destination\n";
            }
        }
        else{
            if(loc==pl4.p_location){
            if(dest==pl4.p_destination){
                cout<<"!We found your plane!\n";
                cout<<"The prices are: \n";
                cout<<"For economy class: "<<pl4.e_price<<endl;
                cout<<"For bussiness class: "<<pl4.b_price<<endl;
                string answer;
                cout<<"Do you wish to buy a ticket?(Y/N)";
                cin>>answer;
                if(answer=="Y"||answer=="y"){
                    string clasa;
                    cout<<"Economy or bussiness class?(E/B)";
                    cin>>clasa;
                    if(clasa=="E"||clasa=="e"){
                        jump13:
                        cout<<"Please enter your credit card credentials\n";
                        card c1=card();
                        string m=c1.first_name;
                        if(m==pr1.first_name){
                            if(c1.sum>=pl4.e_price){
                                int p_seat;
                                jump14:
                                cout<<" Please choose a seat number from 1 to "<<pl4.e_seats<<": ";
                                cin>>p_seat;
                                if(p_seat>pl4.e_seats){
                                    cout<<"!Please choose a valid seat number!\n";
                                    goto jump14;
                                }
                                else{
                                    if(seat[p_seat]==0){
                                        seat[p_seat]=1;
                                        cout<<"You successfully bought a seat in flight number: "<<pl4.id<<endl;
                                        plane pl4(plane p41);
                                    }
                                    else{
                                        cout<<"This seat is taken, please choose another one!\n";
                                        goto jump14;
                                    }
                                }
                            }
                            else{
                                cout<<"Oops! Looks like you don't have enough money on your credit card!\n";
                                cout<<"We are sorry for the inconvenience, you will be redirected to our main page...\n";
                            }
                        }
                        else{
                            cout<<"We had a problem validating your card credentials \n";
                            cout<<"Please try again!";
                            goto jump13;
                        }
                    }
                    else{
                        jump16:
                            cout<<"Please enter your credit card credentials\n";
                            card c1=card();
                            if(c1.first_name==pr1.first_name){
                                    if(c1.sum>=pl4.b_price){
                                            int p_seat;
                                            jump15:
                                            cout<<" Please choose a seat number from 1 to "<<pl4.b_seats;
                                            cin>>p_seat;
                                            if(p_seat>pl4.b_seats){
                                                cout<<"!Please choose a valid seat number!";
                                                goto jump15;
                                            }
                                            else{
                                                if(seat[p_seat]==0){
                                                    seat[p_seat]=1;
                                                    cout<<"You successfully bought a seat in flight number: "<<pl4.id<<endl;
                                                    plane pl4(plane p41);
                                                }
                                                else{
                                                    cout<<"This seat is taken, please choose another one!";
                                                    goto jump15;
                                                }
                                            }
                                    }
                                    else{
                                        cout<<"Oops! Looks like you don't have enough money on your credit card!\n";
                                        cout<<"We are sorry for the inconvenience, you will be redirected to our main page...\n";
                                    }

                            }
                            else{
                                cout<<"We had a problem validating your card credentials \n";
                                cout<<"Please try again!";
                                goto jump16;
                            }

                    }
                }
                else{
                    cout<<"We understand, thank you for your time!\n";
                }
            }
            else{
                cout<<"Sorry we could not find a flight to your destination\n";
            }
        }
        }

        }
        }
    break;
    }
    case 3:{
        int a_id;
        cout<<"To see your flight please enter your id: ";
        cin>>a_id;
        if(a_id==pr1.id){
            cout<<"The user "<<pr1.surname<<" "<<pr1.first_name<<"has the following flight booked:"<<endl;
            cout<<"From: "<<pl4.p_location<<endl;
            cout<<"To: "<<pl4.p_destination<<endl;
            cout<<"Flight id: "<<pl4.id<<endl;
        }
        else{
            cout<<"!Invalid passenger id please try again!\n";
        }
    break;
    }
    case 4:{
        string answer;
        cout<<"Are you sure you want to delete your account?(Y/N): ";
        cin>>answer;
        if(answer=="Y"||answer=="y"){
            pr1.~passenger();
            cout<<"Your account has been deleted!\n";
        }
        else{
            cout<<"Returning to the home page...\n";
        }



    break;
    }
    case 5:{
    cout<<"Thank you for using our services!\n";
    break;
    }
    default:cout<<"!Please choose a valid number!";
            break;
}



}while(choice!=5);



    return 0;
}

passenger::~passenger()
{
}
