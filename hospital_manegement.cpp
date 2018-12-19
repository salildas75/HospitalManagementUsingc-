                            ///**************Hospital Management************///

#include<iostream>
#include<cstring>
#include<conio.h>
#include<cstdio>
#include<iomanip>
#include<fstream>
using namespace std;

void main_menu();///main menu diclare global


class patient_cl
{
public:
    string pf_name;
    string pl_name;
    string dises;
    string date;
};

class login_cl
{
public:
    string username;
    char password[50];
};

///start function list*********

void pass_gen(char pass[])      ///interesting things, create a password
{
    char ch;
    int i=0;
    while(1)
    {
        ch=getch();
        if(ch==13)              //...13 new line ar ascii value
            break;
        putchar('o');           //password mark ... as i wish
        pass[i++]=ch;
    }
    pass[i]='\0';
}

int login()
{
    login_cl ob;
    cout<<"     ^^^>>>^^^Please Firstly Log In Your Account^^^>>>^^^"<<endl<<endl;
    cout<<"Enter Your Username:\t";
        cin>>ob.username;
    cout<<"Enter Your Password:\t";
        pass_gen(ob.password);
    if(ob.username=="uncommon"){
        main_menu();
    }
    else{
        cout<<endl<<"***Incorrect Username.I think you are a thief.....alarm.mp3***"<<endl;
        return 0;
    }
}

istream &operator >>(istream &stream,patient_cl &obj) ///   (>>) operator overloading
{
    cout<<"Enter first name:";
    stream>>obj.pf_name;
    cout<<"Enter last name:";
    stream>>obj.pl_name;
    cout<<"Enter your disease:";
    stream>>obj.dises;
    cout<<"Enter admit date:";
    stream>>obj.date;
    return stream;
}
ostream &operator <<(ostream &stream,patient_cl ob)   ///   (<<) operator overloading
{
    stream<<"Patient Name: "<<ob.pf_name<<" "<<ob.pl_name<<endl;
    stream<<"Disease: "<<ob.dises<<endl;
    stream<<"Admit Date: "<<ob.date<<endl;
    return stream;
}

void patient_list()
{
    patient_cl show[10];
    int i=0;
        ifstream in;
        in.open("patient_info.txt");
        while(!in.eof()){
        in.read((char *)&show,sizeof(patient_cl));
        cout<<show[i]<<endl;
        i++;
        }
        in.close();
}

int patient()
{
    cout<<"1.Admit"<<endl<<"2.Patient List"<<endl<<"3.Main Menu"<<endl<<"4.Exit"<<endl;
    int i;
    cin>>i;
        if(i==1)
        {
            int i;
            patient_cl obj1;
            cin>>obj1;
                    ofstream out;
                    out.open("patient_info.txt",ios::app);
                    out.write((char *)&obj1,sizeof(patient_cl));
                    out.close();

            cout<<endl<<endl<<"           >>>>>>>>>This is your details<<<<<<<<<"<<endl<<obj1<<endl;

            cout<<"1.Main Menu"<<endl;
            cin>>i;
            if(i==1){
                main_menu();
            }
            else{
                cout<<"Wrong Input"<<endl;
            }
        }
        else if(i==2)
        {
            patient_list();
        }
        else if(i==3)
        {
            main_menu();
        }
        else if(i==4)
        {
            cout<<"Close this program"<<endl;
            return 0;
        }
        else
        {
            cout<<"wrong input"<<endl;
        }
}

void sec_doc()
{
    cout<<"1.Gaini Section"<<endl<<"2.Heart Section"<<endl<<"3.Eye Section"<<endl<<"4.Coming Soon"<<endl<<"5.Main Menu"<<endl;
    int i;
    cin>>i;
    if(i==1)
    {
        cout<<"Name: Doctor Jannat"<<endl<<"Time: 9.00am-2.00pm"<<endl;
    }

    else if(i==2)
    {
        cout<<"Name: Doctor Salil"<<endl<<"Time: 10.00am-1.00pm"<<endl;
    }
    else if(i==3)
    {
        cout<<"Name: Doctor Nadim"<<endl<<"Time: 10.00am-1.00pm"<<endl;
    }
    else if(i==4)
    {
        cout<<"****Coming Soon****"<<endl;
    }
    else if(i==5)
    {
        main_menu();
    }
    else
    {
        cout<<"Wrong Input"<<endl;
    }

}

void about()
{
    cout<<"       About Us:"<<endl<<"This is a special hospital... r kicu jani na :/"<<endl;
    int i;
    cout<<endl<<"1.Main Menu"<<endl;
    cin>>i;
    if(i==1)
    {
        main_menu();
    }
    else
    {
        cout<<"wrong input"<<endl;
    }
}

void setting()
{
    cout<<"Coming soon"<<endl;
}


void main_menu()///main menu
{
    cout<<endl<<"                                _--Uncommon Hospital--_"<<endl<<"    Main Menu"<<endl<<"1.Patient"<<endl<<"2.Section & Doctors"<<endl<<"3.About Us"<<endl<<"4.Setting"<<endl<<endl<<"Please Enter Your Key"<<endl;
    int i;
    cin>>i;
    if(i==1)
        patient();
    else if(i==2)
        sec_doc();
    else if(i==3)
        about();
    else if(i==4)
        setting();

    else
        {
            cout<<"wrong input"<<endl;
        }
}

int main()  ///main function
{
    login();
    return 0;
}
