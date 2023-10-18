/* Student List is a program where you can add new students to a database and print them out or delete them from it
   Author: Rowan Miller
   10/16/23
 */ 

#include <iostream>
#include <cstring>
#include <vector>

using namespace std;
 

struct Student {
  char firstName[14];
  char lastName[14];
  int id;
  float gpa; 
};

void add(vector<Student*>& students, char input[10]);
void print(vector<Student*>& students); 
void erase(vector<Student*>& students); 

int main () {
  bool stillUsing = true; 
  
  vector <Student*> students;

  while (stillUsing == true)  {
    cout << "Please type in either ADD, PRINT, DELETE, or QUIT" << endl;
    char input [10];
     cin >> input;
     cin.ignore(10, '\n'); 
     //if the user types in ADD
    if(strcmp(input, "ADD") == 0) {
      add(students, input); 
    }
    
    //if user types PRINT
    if(strcmp(input, "PRINT") == 0) {
      print(students); 
    }
    
    //if user types DELETE
    if(strcmp(input, "DELETE") == 0) {
      erase(students); 
    }
    
    //if user types QUIT
    if(strcmp(input, "QUIT") == 0) {
      cout << "Quitting" << endl; 
      bool stillUsing = false; 
      exit(0);
    } 
  }
    return 0;
}

void add(vector<Student*>& students, char input[10]) {
    Student* s = new Student();
    cout << "Please type in a first name" << endl;
    cin >> input;
    strcpy(s->firstName, input);
    cout << "Please type in a last name" << endl;
    cin >> input;
    strcpy(s->lastName, input);
    cout << "Please type in a student id" << endl;
    cin >> s->id;
    cout << "Please type in a gpa" << endl;
    cin >> s->gpa;
    students.push_back(s);
}

//prints student
void print(vector<Student*>& students) {
  cout << "Printing out students" << endl; 
  for(vector<Student*>::iterator it = students.begin(); it != students.end(); it++) {
    cout << (*it) -> firstName << "\t";
    cout << (*it) -> lastName << ", ";
    cout << (*it) -> id << ", ";
    cout.setf(ios::fixed, ios::floatfield);
    cout.precision(2); //makes sure gpa only prints to 2 places
    cout << (*it) -> gpa << endl;
  }
}

//deletes students from the database 
void erase(vector<Student*>& students) {
  int stored;
  cout << "Type in the student id of the student you want to delete" << endl; 
  cin >> stored;
  cin.ignore(); 
  for(vector<Student*>::iterator it = students.begin(); it != students.end(); it++) {
    if((*it) -> id == stored) { //if the student id typed in is equal to one in the data base 
      delete *it;
      students.erase(it);
      break;
    }
   }
}
