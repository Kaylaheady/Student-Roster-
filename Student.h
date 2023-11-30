#include <iostream>
using namespace std; 
#include <string>


class Student{ 
friend ostream& operator << (ostream&, const Student&);

private: 
string name; 
char classification; 
string major; 
int studentid; 


public:
Student(); 
Student(string, char, string, int); 

//Student(const Student&);
//deep copy constructor


void setName(string); 
void setClassif(char);
void setMajor(string);
void setStudentid(int); 


string getName(); 
char getClassification(); 
string getMajor();
int getstudentid();




};


class Course{
friend ostream& operator << (ostream&, const Course&);



public: 
Course(); 
Course(string,string,string); 
void setcourseName(string);
void setcourseCode(string);
void setlocation(string); 



void grow(); 

string getcourseName(); 
string getcourseCode();
string getlocation(); 
string updateRoster();
int findStudent(string); 
void removeStudent();
void addStudent();





~Course();

private: 

string courseName; 
string courseCode;
string location; 

Student* roster; 
int maxSize; 
int currentSize; 

};
