#include<bits/stdc++.h>
using namespace std;

void printIterary(unordered_map<string, string>tickets){
    unordered_set<string>to;
    for(pair<string, string>ticket : tickets){
        to.insert(ticket.second);
    }

    string start = "";

     for(pair<string, string>ticket : tickets){
        if(to.find(ticket.first) == to.end()){
            start = ticket.first;
        }
    }

    cout<<start<<"->";
    while(tickets.count(start)){
        cout<<tickets[start]<<"->";
        start = tickets[start];
    }

}




int main(){
    unordered_map<string, string>tickets;
    tickets["Dhaka"] = "Magura";
    tickets["Magura"] = "Chuadanga";
    tickets["Chuaganga"] = "Kustia";
    tickets["Kustia"] = "Pabna";
    tickets["Pabna"] = "Natore";
    printIterary(tickets);
}