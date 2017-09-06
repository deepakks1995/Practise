#include<iostream>
using namespace std;
#include<string.h>
class person
{
public:
    char *name;
    int id;
public:
    void get_details()
    {
        name=new char[20];
        cout<<"\nEnter name of person :";
        cin>>name;
        cout<<"\nEnter ID of person :";
        cin>>id;
    }
    void print_details()
    {
        cout<<"\nName: "<<name;
        cout<<"\nID : "<<id;
    }
};
class student : public person
{
public:
    int marks;
public:
    student()
    {
        name=new char[20];
        strcpy(name,"NOT ASSIGNED");
        id=0;
        marks=0;
    }
    student(char *name,int id,int marks)
    {
       this->name=new char[20];
        strcpy(this->name,name);
        this->id=id;
        this->marks=marks;
    }
    void get_marks()
    {
        cout<<"\nEnter marks :";
        cin>>marks;
    }
    void print_marks()
    {
        cout<<"\nMarks :"<<marks<<endl;
    }
};
class faculty : public person
{
public:
    char *dept;
    int salary;
public:
    faculty()
    {
        name=new char[20];
        strcpy(name,"NOT ASSIGNED");
        id=0;
        dept=new char[30];
        strcpy(dept,"NOT ASSIGNED");
        salary=0;
    }
    faculty(char *name, int id,char *dept,int salary)
    {
       this->name=new char[20];
        strcpy(this->name,name);
        this->id=id;
        this->dept=new char[30];
        strcpy(this->dept,dept);
        this->salary=salary;
    }
    void get_fdetails()
    {
        dept=new char[30];
        cout<<"\nEnter department :";
        cin>>dept;
        cout<<"\nEnter salary : ";
        cin>>salary;
        cout<<"\n";
    }
    void print_fdetails()
    {
        cout<<"\nDepartment :"<<dept;
        cout<<"\nSalary :"<<salary<<"\n";
    }
};
int main()
{
    student st1("RAHUL",25,98),st;
    faculty f1("JAYESH",98,"ELECTRICAL",65456),f;
    cout<<"predefined details :";
    st1.print_details();
    st1.print_marks();
    f1.print_details();
    f1.print_fdetails();
    cout<<endl;
    st.get_details();
    st.get_marks();
    f.get_details();
    f.get_fdetails();
    cout<<"\n\nDetails of student";
    st.print_details();
    st.print_marks();
    cout<<"\n\nDetails of faculty";
    f.print_details();
    f.print_fdetails();
    return 0;

}
