// DELETION OF ELEMENTS
//
// Jakub Mikuła

#include<iostream>
#include<vector>

using namespace std;

void fillContainer(vector<int> &c){
    for(int i=0; i<40; i++){
        c.push_back(i);
    }
}

//solution to delete random item from vector
void solution(vector<int> &c){
    int toDel=rand()%c.size()-1;
    
    swap(c[toDel], c[c.size()-1]);
    
    c.pop_back();
}

int main(int argc,char** argv){
    srand((unsigned)time(NULL));
    
    vector<int> c;
    
    fillContainer(c);
    
    solution(c);
    
    return 0;
}
