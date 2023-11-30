#include <iostream>
#include "student.h"
#include "cstring"
using namespace std;

//grow course list
//add course to list
//remove course from list

int findCourse(Course* courselist, int);
char Getmenu();


int main(){

Course* courselist = new Course[2];   
int currentSize = 0; 
int maxSize = 2;

char pick; 
int courseSelection;
string studentselection; 
do {
    pick = Getmenu();
    switch (pick)
    {
        case '1':
        {
        // Add courses
            string location, code; 
            if(currentSize == maxSize){
                courselist->grow(); 
            }
            cout << "What is the course name? " << endl; 
            char cname[500]; 
            cin.getline(cname, 500);
            cout << "What is the course code? " << endl;
            cin >> code;
            cout << "What is the course location? " << endl; 
            cin >> location;


            //Student temp(name, classification, major, studentid);
            Course temp(cname, code, location);
            courselist[currentSize] = temp;
            currentSize++; 


           break; 
        }
        case '2':
        {
        //  Add student 
            //which course
            cout << "Which course do you want to add student? " << endl; 
            cin >> courseSelection; 
            courselist[courseSelection].addStudent(); 
            break; 
        }
        case '3':
        {
        // update course 
            //which course
            cout << "Which course do you want to update? " << endl; 
            cin >> courseSelection; 
            courseSelection = findCourse(courselist, currentSize);
            courselist[courseSelection].updateRoster(); 
           
            break; 
        }
        case '4':{
        // list all courses 
            for(int i = 0; i < currentSize; i++){
                cout << courselist[i] << endl;
            }
            break; 
        }
        case '5':
        {
        //find student 
            Course c;
            cout << "Which student do you want to find? " << endl; 
            getline(cin, studentselection); 
             for(int i = 0; i < currentSize; i++){
                c.findStudent(studentselection); 
            }
        
            break; 
        }
        case '6':
        {
        //find course 
            int foundCourse = findCourse(courselist, currentSize);
            cout << courselist[foundCourse]; 

            break; 
        }   
        case '7':
        {
        //remove a course
            delete[] courselist;
            int course = 0; 
            break; 
        }
        case 'Q': 
        {
        // quit 
            break; 
        }
        default:
            cout << "INVALID SELECTION "; 
            break; 
    }
}while(pick != 'Q' && pick != 'q'); 



return 0; 
}



char Getmenu(){     //in the driver
    cout << "1. Add course to the list " << endl; 
    cout << "2. Add students to the course " << endl; 
    cout << "3  Update a course " << endl; 
    cout << "4. List courses including students " << endl; 
    cout << "5. Find student by name or id" << endl; 
    cout << "6. Find a course by name, course code, or location " << endl; 
    cout << "7. Remove a course from the list by course code" << endl;          
    cout << "Q. Quit" << endl; 
    char pick; 
    cin >> pick; 
    return pick; 

}

int findCourse(Course* courselist, int currentSize){
    string ans2, coursename, loc, Ccode; 
 
        cout << "How do you want to find the course? name, course code, or location " << endl;
        getline(cin, ans2); 
        if(ans2 == "Name " || "name")
        {
            cout << "What is the name of the course?" << endl; 
            getline(cin, coursename);
            for(int i = 0; i < currentSize; i++){
                if(coursename == courselist[i].getcourseName()){
                    return i; 
                }
            }
        }
        if(ans2 == "course code" || "code"){
            cout << "What is the code of the course?" << endl; 
            getline(cin,Ccode);
            for(int i = 0; i < currentSize; i++){
                string courcode = courselist[i].getcourseCode(); 
                if(Ccode == courcode){
                    return i; 
            }
        }
    }
        if(ans2 == "location" || "Location"){
            cout << "What is the location of the course?" << endl; 
            getline(cin,loc); 
            for(int i = 0; i < currentSize; i++){
                string courloc = courselist[i].getlocation(); 
                if(loc == courloc){
                    return i; 
                 }
        }
    }
}



