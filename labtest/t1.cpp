#include<iostream>
#include<time.h>
#include<random>
using namespace std;

class Course {
    private:

    string name;
    int semester;
    double credit;
    string courseid;

    public:

    

    Course(){
        name="";
        semester=1;
        credit=3.0;
    }

    void info(string name,int semester,double credit){
        this->name=name;
        this->semester=semester;
        this->credit=credit;
    }

    void generateCourseID(int r,int s){
        courseid[0]=4;
        courseid[1]=semester;
        courseid[2]=r;
        courseid[3]=s;
    }
    void display(){
        cout<<name<<" "<<semester<<" "<<credit;
    }
    friend void sortBySemesterAndName(Course p1[]);


};

void sortBySemesterAndName(Course p1[]){
    for(int i=0;i<9;i++){
        if(p1[i].semester<p1[i+1].semester){
            Course temp=p1[i];
            p1[i]=p1[i+1];
            p1[i+1]=temp;
        }
    }

    for(int i=0;i<9;i++){
        if(p1[i].name<p1[i+1].name){
            Course temp=p1[i];
            p1[i]=p1[i+1];
            p1[i+1]=temp;
        }
    }

}




int main(){
    int r1,s1;
    srand(time(0)%100);
    r1=rand()/10;
    s1=rand()%10;


    Course c1[10];

    
    c1[0].info("MATH",2,3.0);
    c1[0].generateCourseID(r1,s1);
    
    c1[1].info("DLD",3,4.0);
    c1[2].generateCourseID(r1,s1);

    c1[2].info("COA",4,3.0);
    c1[2].generateCourseID(r1,s1);

    c1[3].info("OOP",1,4.0);
    c1[3].generateCourseID(r1,s1);

    c1[4].info("TES",4,3.0);
    c1[4].generateCourseID(r1,s1);

    c1[5].info("HUM",2,4.0);
    c1[5].generateCourseID(r1,s1);

    c1[6].info("DSA",4,3.0);
    c1[6].generateCourseID(r1,s1);

    c1[7].info("LEA",3,4.0);
    c1[7].generateCourseID(r1,s1);

    c1[8].info("EEE",1,3.0);
    c1[8].generateCourseID(r1,s1);

    c1[9].info("SP1",2,4.0);
    c1[9].generateCourseID(r1,s1);




    cout<<"Before sorting :"<<endl;
    for(int i=0;i<10;i++){
        c1[i].display();
        cout<<endl;
    }
    cout<<endl;

    sortBySemesterAndName(c1);
    
    cout<<"After sorting :"<<endl;
    for(int i=0;i<10;i++){
        c1[i].display();
        cout<<endl;
    }
    cout<<endl;





    
}
