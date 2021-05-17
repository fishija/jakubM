// STRING COMPRESSION
//
// Jakub Mikuła

#include<iostream>
#include<string>

using namespace std;

void compress(string &s){
    string toSave="";
    
    for(int i=0; i<s.length(); i++){
        int c=1;
        //no possibility that last char is repeated further
        if(i<s.length()-1){
            char t=s[i];
            //counting how many repeated characters
            while(t==s[++i]){
                c++;
            }
            toSave+=s[--i]; //going back to the char that was repeated
        }
        else{
            toSave+=s[i];
        }
        //if there is 1 char in row, do not write int after char (to make text more compressed)
        if(c>1){
            toSave+=to_string(c);
        }
    }
    s=toSave; //change s to new string
}

void decompress(string &s){
    string toSave="";
    
    for(int i=0; i<s.length(); i++){
        string tempStr="0";
        int c=0;
        //loop because of numbers like 10, 64, 111 etc.
        while(s[i+1]>='0' && s[i+1]<='9'){
            tempStr+=s[i+1]; //string with number
            c++;
            i++;
        }
        int j=0;
        //adding characters to the string (as much as needed)
        do{
            if(c){
                toSave+=s[i-c];
            }
            else{
                toSave+=s[i];
            }

        } while(++j<stoi(tempStr));
    }
    s=toSave; //change s to new string
}

void solution(string s){
    compress(s);
    cout<<endl<<"COMPRESSED:"<<endl;
    cout<<s<<endl;
    
    decompress(s);
    cout<<endl<<"DECOMPRESSED:"<<endl;
    cout<<s<<endl;
}

int main(int argc,char** argv){
    cout<<"Write txt string to compress:"<<endl;
    
    string s;
    cin>>s;
    
    solution(s);
    
    return 0;
}
