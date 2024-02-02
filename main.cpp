/** This program has been developed by Eng. Luiz Eduardo for non-commercial purpose
 All rights reserved. **/

#include <cstring>
#include <iostream>
#include <fstream>
using namespace std;
const char DIR_FILE[] = "contacts.dat";

struct Contact(){
 char name[30];
 char family_name[30];
 int age;
 char mail[30];
};

/********  Program Functions **********/
void insertContact(Contact c);
Contact readContact();
bool existsContact(char name[],char family_name[]);
Contact searchContact(char name[],char family_name[]);
void showContact(Contact c);
void listContacts();
void removeContact(char name[],char family_name[]);
void updateContact(char name[],char family_name[]);
/***********************************/

/********  Menu Functions **********/
void menuInsertion();
void menuSearching();
void menuListing();
void menuRemoval();
void menuUpdate();
/***********************************/

void insertContact(Contact c){
    ofstream output;
    output.open(DIR_FILE,ios::binary);
    output.write((char*)&c,sizeof(Contact));
    output.close();
}

Contact readContact(){
 Contact c;
 cout<<"\t Name: ";
 cin.getline(c.name,30);
 cout<<"\t Last Name: ";
 cin.getline(c.family_name,30);
 cout<<"\t Age: ";
 cin>>c.age;
 cin.ignore();
 cout<<"\t E-mail Address: ";
 cin.getline(c.mail,30);
 return c;
}

bool existsContact(char name[],char family_name[]){
   Contact c;
   ifstream.input;
   input.open(DIR_FILE,ios::binary);
   if(input.good()){
     while(input.read((char*)&c,sizeof(Contact))){
        if(strcmp(name,c.name)==0 && strcmp(family_name,c.family_name)==0){
            input.close();
            return true;
        }

     }
     input.close();
     return false
   }
   else{
    input.close();
    return false;
   }
}
Contact searchContact(char name[],char family_name[]{
   Contact c;
   ifstream.input
   input.open(DIR_FILE,ios::binary);
   if(input.good()){
     while(input.read((char*)&c,sizeof(Contact))){
        if(strcmp(name,c.name)==0 && strcmp(family_name,c.family_name)==0){
            input.close();
            return c;
        }

     }

   }
 }
void showContact(Contact c){
 cout<<endl;
 cout<<"\t    Name: "<<c.name<<endl;
 cout<<"\t Surname: "<<c.family_name<<endl;
 cout<<"\t     Age: "<<c.age<<endl;
 cout<<"\t    Mail: "<<c.mail<<endl;
 cout<<endl;
}

void listContacts(){
    ifstream input;
    input.open(DIR_FILE,ios::binary);
    Contact c;
    if(input.good()){
    while(input.read((char*)&c,sizeof(Contact))){
        showContact(c);
    }
   }else{
   cout<<"Can't read the file!" <<endl;
   }
   input.close();
}

void removeContact(char name[],char family_name[]){
    ifstream input;
    ofstream temp;
    input.open(DIR_FILE,ios::binary);
    temp.open("temp.dat",ios::binary);
    Contact c;
    if(input.good()){
        while(input.read((char*)&c,sizeof(Contact))){
          if(strcmp(name,c.name)!=0 || strcmp(family_name,c.family_name)!=0){
            temp.write((char*)&c,sizeof(Contact));

          }
        }
    }
    input.close();
    temp.close();
    remove(DIR_FILE);
    rename("temp.dat",DIR_FILE);
}

void updateContact(char name[],char family_name[]){
    ifstream input;
    ofstream temp;
    input.open(DIR_FILE,ios::binary);
    temp.open("temp.dat",ios::binary);
    Contact c;
    if(input.good()){
        while(input.read((char*)&c,sizeof(Contact))){
          if(strcmp(name,c.name)!=0 || strcmp(family_name,c.family_name)!=0){
            Contact updated = readContact();
            temp.write((char*)&updated,sizeof(Contact));

          }
        }
    }
    input.close();
    temp.close();
    remove(DIR_FILE);
    rename("temp.dat",DIR_FILE);

}

void menuInsertion(){
  cout<<"\t\t\t - REGISTER NEW CONTACT" <<endl;
  Contact newone = readContact();
  if(existsContact(newone.name,newone.family_name)){
    cout<<"CONTACT ALREADY EXISTS! REGISTRATION FAILED!"<<endl;
  }
  insertContact(newone);
  cout<<"\t\t\t - CONTACT SUCCESFULLY REGISTERED" <<endl;
}
void menuSearching(){
    cout<<"\t\t\t - SEARCH CONTACT" <<endl;
    char name[30], family_name[30];
    cout<<"\t\t\t - INSERT DATA FOR SEARCHING:" <<endl;
    cout<<"\t\t\t - NAME:" ;
    cin.getline(name,30);
    cout<<"\t\t\t - LAST NAME:" ;
    cin.getline(family_name,30);
    if(existsContact(name,family_name)){
            Contact searched = searchContact(name,family_name);
            showContact(searched);
    } else{

       cout<<"CONTACT COULD NOT BE FOUND!"<<endl;

    }

}
void menuListing(){
    cout<<"\t\t\t - CONTACT LIST" <<endl;
    listContacts();

}
void menuRemoval(){
    cout<<"\t\t\t - REMOVE CONTACT" <<endl;
    char name[30], family_name[30];
    cout<<"\t\t\t - INSERT DATA FOR REMOVAL:" <<endl;
    cout<<"\t\t\t - NAME:" ;
    cin.getline(name,30);
    cout<<"\t\t\t - LAST NAME:" ;
    cin.getline(family_name,30);
    if(existsContact(name,family_name)){
            Contact eliminate = searchContact(name,family_name);
            int decision;
            cout<<"\t\t\t - ARE YOU SURE WANT TO REMOVE THIS CONTACT?" <<endl;
            showContact(eliminate);
            cout<<"\t\t\t - PRESS 1 FOR YES OR 2 FOR NO...";
            cin>>decision;
            if(decision==1){
            removeContact(name,family_name);
            cout<<"\t\t\t - CONTACT REMOVED!" <<endl;
            }
    }

}
void menuUpdate();



int main(){
 listContacts();
 removeContact("Teste1","Sobrenome1");
 updateContact("Test2","Sobrenome2");
 listContacts();
 return 0;
}
