#include<bits/stdc++.h>
using namespace std;

namespace Using_Pair{
    struct ComparePair{
     bool operator()(pair<string, int>&p1, pair<string, int>&p2){
        return p1.second > p2.second;
     }
};

int main(){
    priority_queue<pair<string, int>, vector<pair<string, int>>, ComparePair>pq;
    pq.push(make_pair("Mehadi", 1500));
    pq.push(make_pair("Hasan", 2500));
    pq.push(make_pair("Talha", 500));
    pq.push(make_pair("Sorme", 3500));

    while(!pq.empty()){
        cout<<"Name :  "<<pq.top().first<<" Rank : "<<pq.top().second << endl;
        pq.pop();
    }

}
};

namespace Using_Object{
    class Student{
       string name;
       int marks;
       public:
       Student(string name, int marks){
           this->name = name; 
           this->marks = marks;
       }
       bool operator < (const Student &obj) const{
        return this->marks < obj.marks;
       }

       void show(){
        cout<<"Name : "<<name<<endl<<"Marks : "<<marks<<endl;
       }
    };


    int main(){
         priority_queue<Student>pq;
         pq.push(Student("Mehadi", 3500));
          pq.push(Student("Hasan", 500));
           pq.push(Student("Talha", 1500));
            pq.push(Student("Sorme", 5500));
        
            while(!pq.empty()){
                Student topper = pq.top();
                topper.show();
                pq.pop();
            }
    }
};


int main(){
    Using_Object::main();
}