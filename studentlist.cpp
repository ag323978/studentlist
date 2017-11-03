/*
  Author: Aryan Gupta
  Date: 11/2/17
  This program allows a user to create a list of students and store some of their information
 */


#include <iostream>
#include <vector>
#include <cstring>
#include <iterator>
#include <iomanip>

using namespace std;

// student struct
struct Student {
  char firstName[20];
  char lastName[20];
  int ID;
  float gpa;
};

Student * addStudent(char firstName[20], char lastName[20], int ID, float gpa);
void print (vector<Student*> &v);
void deleteStudent(vector<Student*> &v, int ID);

int main() {

  // vector of students
  vector<Student*> v;
  cout << endl << endl << endl;
  cout << "Make a student list." << endl;
  cout << "To create a student list..." << endl;
  cout << "Type 'ADD' to add a student to the list" << endl;
  cout << "Type 'DELETE' to remove a student from the list" << endl;
  cout << "Type 'PRINT' to print all the students in the list" << endl;
  cout << "Type 'QUIT' to exit the program" << endl << endl;
  cout << "--------------------------------------------------" << endl;
  cout << endl;
  
  while(true) {

    char input[6];
    char firstName[20];
    char lastName[20];
    int ID;
    float gpa;

    // get the user's input for the commands
    cout << "Type one of the above commands: ";
    cin >> input;
    if(strcmp(input, "ADD") == 0) {
      // if the user typed 'ADD' prompt them to enter their information
      cout << "What is the student's first name? First name: ";
      cin >> firstName;
      cout << "What is the student's last name? Last name: ";
      cin >> lastName;
      cout << "What is the student's ID number? ID: ";
      cin >> ID;
      cout << "What is the student's GPA? GPA: ";
      cin >> gpa;
      // after the user has entered student's information add student to the vector
      v.push_back(addStudent(firstName, lastName, ID, gpa));
    } else if(strcmp(input, "PRINT") == 0) {
      // print everything stored in the vector
      print(v);
    } else if(strcmp(input, "DELETE") == 0) {
      // enter the student's ID number to remove them
      cout << "Enter the student's ID number that you want to remove from the list: ";
      cin >> ID;
      deleteStudent(v, ID);
    } else if(strcmp(input, "QUIT") == 0) {
      // program ends when user types in quit
      break;
    } else {
      cout << "Not a valid command. ";
    }
  }
}


Student* addStudent(char firstName[20], char lastName[20], int ID, float gpa) {
  // make and use a makeshift student
  Student* temp = new Student();
  strcpy(temp->firstName, firstName);
  strcpy(temp->lastName, lastName);
  temp->ID = ID;
  temp->gpa = gpa;
  return temp;
}

void print(vector<Student*> &v) {
  // print only to 2 decimal places for gpa which is float
  cout.setf(ios::fixed);
  cout.precision(2);
  // print all elements in vector
  for(vector<Student*>::iterator it = v.begin(); it != v.end(); it++) {
    // got help from Jason Shi on iterators
    cout << (*it)->firstName << " " << (*it)->lastName << ", " << (*it)->ID << ", " << (*it)->gpa << endl;
  }
}

void deleteStudent(vector<Student*> &v, int ID) {
  // go through vector
  for(vector<Student*>::iterator it = v.begin(); it != v.end(); it++) {
    // if the ID the user entered matches with one of the ones from the vector
    if((*it)->ID == ID) {
      delete *it;
      v.erase(it);
      break;
    }
  }
}

