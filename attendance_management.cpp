#include <iostream>
#include <iomanip>
using namespace std;

struct Students{
    int rollNo;
    string name;
    int presentClasses;
    int totalClasses;
    float attendance;
};

Students student[100]; // array of structure
int n = 0; // by default system has 0 student records

// Calculate Attendance
void calculateAttendance(int i){
    if(student[i].totalClasses == 0)
    student[i].attendance = 0;

    else
    student[i].attendance = (student[i].presentClasses * 100.0)/ student[i].totalClasses;
}

// Add Student
void addStudent(){
    cout<<"\nEnter Roll Number: ";
    cin>>student[n].rollNo;

    cout<<"Enter Student Name: ";
    cin.ignore();
    getline(cin ,  student[n].name);
    cout<<"Enter Total Classes: ";
    cin>>student[n].totalClasses;

    cout<<"Enter Present Classes: ";
    cin>>student[n].presentClasses;

    calculateAttendance(n);
    n++; // student record successfuly saved  now move to next

    cout<<"\nStudent Added successfully!\n";
}

void displayStudents(){
    if(n==0){
        cout<<"\nNo student records available.\n";
        return;
    }
    cout<<"\n";
    cout<<left <<setw(10)<<"Roll No"
    << setw(25)<<"Name"
    << setw(15)<<"Total"
    << setw(15)<<"Present"
    << setw(15)<<"Attendance"<<endl;

    cout<<string(80 , '-')<<endl;

    for(int i = 0; i<n; i++){
        cout<<left<<setw(10)<<student[i].rollNo
        <<setw(25)<<student[i].name
        <<setw(15)<<student[i].totalClasses
        <<setw(15)<<student[i].presentClasses
        <<fixed<<setprecision(2)
        <<student[i].attendance<<"%"<<endl;
    }
}

// Search Student
void searchStudent(){
    int roll;
    cout<<"\nEnter Roll Number to search: ";
    cin>>roll;

    for(int i = 0; i<n; i++){
        if(student[i].rollNo == roll){
            cout<<"\nStudent Found!\n";
            cout<<"Roll Number: "<<student[i].rollNo<<endl;
            cout<<"Name: "<<student[i].name<<endl;
            cout<<"Total Classes: "<<student[i].totalClasses<<endl;
            cout<<"Present Classes: "<<student[i].presentClasses<<endl;
            cout<<fixed<<setprecision(2);
            cout<<"Attendance: "<<student[i].attendance<<"%"<<endl;
            return;
        }
    }
    cout<<"\nStudent not found!\n";
}

// update Attendance
void updateAttendance(){
    int roll;
    cout<<"\nEnter Roll Number: ";
    cin>>roll;
    for(int i = 0; i<n; i++){
        if(student[i].rollNo == roll){
            cout<<"Enter Total Classes: "<<endl;
            cin>>student[i].totalClasses;
            cout<<"Enter Present Classes: "<<endl;
            cin>>student[i].presentClasses;
            calculateAttendance(i);
            cout<<"Attendance updated successfully!\n";
            return;
        }
    }
    cout<<"\nStudent not found!\n";
}

// Students with low attendance
void lowAttendance(){
    bool found = false;
    cout<<"\nStudent with Attendance Below 75%\n";
    cout<<string(60,'-');
    for(int i =0; i<n; i++){
        if(student[i].attendance<75){
            cout<<"Roll No: "<<student[i].rollNo<<endl;
            cout<<"Name: "<<student[i].name<<endl;
            cout<<fixed<<setprecision(2);
            cout<<"Attendance: "<<student[i].attendance<<"%"<<endl;
            cout<<string(40 , '-')<<endl;
            found = true;
        }
    }
    if(!found){
        cout<<"No student has attendance below 75%.\n";
    }
}

int main() {
    int choice;
    do{
        cout<<"\n======================================\n";
        cout<<" STUDENT ATTENDANCE MANAGEMENT SYSTEM \n";
        cout<<"======================================\n";

        cout<<"1. Add Student\n";
        cout<<"2. Display All Students\n";
        cout<<"3. Search Student\n";
        cout<<"4. Update Attendance\n";
        cout<<"5. Show Low Attendance Students\n";
        cout<<"6. Exit\n";

        cout<<"\nEnter your Choice: ";
        cin>>choice;
        switch(choice){
            case 1:
            addStudent();
            break;

            case 2:
            displayStudents();
            break;

            case 3:
            searchStudent();
            break;

            case 4:
            updateAttendance();
            break;

            case 5:
            lowAttendance();
            break;

            case 6:
            cout<<"Thank you for using the system!\n";
            break;

            default:
            cout<<"Invalid choice! Please try again.\n";
        }
        

    }while(choice!=6);

    

    return 0;
}