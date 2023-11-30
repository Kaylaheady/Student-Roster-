#include "student.h"

//Student ////////////////////////////////////////////////////////
Student::Student()
{
    name = "n"; 
    classification = 'c';
    major = "m";
    studentid = 4;
}
Student::Student(string Name, char Classification, string Major, int studentId){
    name = Name;
    classification = Classification; 
    major = Major; 
    studentid = studentId; 
}

void Student::setName(string nam){
    nam = name;

}
void Student::setClassif(char sclass){
    sclass = classification; 
}
void Student::setMajor(string m){
    m = major; 
}
void Student::setStudentid(int id){
    id = studentid;
}

char Student::getClassification(){
    return classification; 
} 
string Student::getMajor(){
    return major; 
}
int Student::getstudentid(){
    return studentid; 
}

string Student::getName(){
    return name; 
}

ostream& operator << (ostream& os, const Student& student){
    os << student.name << student.classification << student.major << student.studentid;
    return os; 

}





//course ////////////////////////////////////////////////////////
Course::Course(){
    roster = new Student[2];
    currentSize = 0; 
    maxSize = 2; 
}
Course::Course(string coursename, string code, string Location){
    courseName = coursename; 
    courseCode = code; 
    location =  Location; 

}
Course:: ~Course(){
    delete[] roster; 
}
void Course::grow(){
    maxSize = maxSize + 10; 
    Student* newRoster = new Student[maxSize]; 
    for(int i = 0; i < currentSize; i++){
        newRoster[i] = roster[i];
    }
    delete[] roster; 
    roster = newRoster; 
}


void Course::addStudent(){
    if(currentSize == maxSize){
        grow(); 
    }
        
    cout << "What is the students name? " << endl; 
    char name[500]; 
    cin.getline(name, 500);
    cout << "What is the students Classification? " << endl;
    char classification; 
    cin >> classification; 
    cout << "What is the students major? " << endl; 
    char major[500];
    cin.getline(major, 500);
    cout << "What is the students Student ID? " << endl; 
    int studentId; 
    cout << studentId; 

    Student temp(name, classification, major, studentId);
    roster[currentSize] = temp; 
    currentSize++; 


}
string Course::updateRoster(){
    string studname, change, upname, upcourse; 
    cout << "What is the students name or id that you want to update? "<< endl; 
    getline(cin, studname); 
    int studenti = findStudent(studname);
    cout << "What do you want to change about the student name or course?" << endl; 
    getline(cin, change); 
    if(change == "name"){
        cout << "What is the updated name of the student" << endl; 
        getline(cin, upname); 
        roster[studenti].setName(upname);
    }
    if(change == "course"){
        cout << "What is the updated course of the student" << endl; 
        getline(cin, upcourse); 
        setcourseName(upcourse);
    }


}
 ostream& operator << (ostream& os, const Course& course){
    os << course.courseName << course.courseCode << course.location;
    for(int i = 0; i < course.currentSize; i++){
        os << course.roster[i]; 
    
    }
    return os; 

}


int Course::findStudent(string studname){
    string ans, studentname; 
    studname = studentname; 
    int num; 
    cout << "How do you want to find the student id or name?" << endl; 
    getline(cin, ans); 
    if(ans == "name" || "Name"){
        cout << "What is the name of the student? " << endl; 
        getline(cin, studentname);
        for(int i = 0; i < currentSize; i++){
            if(studentname == roster[i].getName()){
                return i;
            }
        }
    }
    if(ans == "Student id" || "student id"){
        cout << "What is the number of the student id? " << endl; 
        cin >> num; 
        for(int i = 0; i < currentSize; i++){
            if(num == roster[i].getstudentid()){
                return i; 
            }
        }

    }

   
}



void Course::setcourseName(string cn){
    cn = courseName; 
}
void Course::setcourseCode(string code){
    code = courseCode; 
}
void Course::setlocation(string l){
    l = location; 
}

string Course::getcourseName(){
    return courseName; 
}
string Course::getcourseCode(){
    return courseCode; 
}
string Course::getlocation(){
    return location; 

}
void Course::removeStudent(){
    string selection;
    cout << "Enter the name of the student." << endl;
    cin >> selection;
    int select = findStudent(selection);
    if(select == -1){
        cout << "Could not find student in directory"; 

    }
    else{
        for(int i = select + 1; i < currentSize;i++)
        {
            roster[i-1]= roster[i];
            currentSize--;
            cout << "Entry is remvoved ";
        }
    }


}
