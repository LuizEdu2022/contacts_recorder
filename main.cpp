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

void insertContact(Contact c);
Contact readContact();
bool existsContact(char name[],char family_name[]);
Contact searchContact(char name[],char family_name[]);
void showContact(Contact c);


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

int main(){
 if(existsContact("Jean","Rodriguez")){
    Contact c = searchContact("Jean","Rodriguez");
    showContact(c);
 }
 else{
    cout<<"There is no such contact registered!"<<endl;
 }
 listContacts();
 return 0;
}
