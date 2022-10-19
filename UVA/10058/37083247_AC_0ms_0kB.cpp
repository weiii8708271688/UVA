#include <bits/stdc++.h>
using namespace std;

string noun[8] = {"tom", "jerry", "goofy", "mickey", "jimmy", "dog", "cat", "mouse"};
string verb[] = {"hate", "love", "know", "like", "hates", "loves", "knows", "likes"};
string article[] = {"a", "the"};

bool isnoun(string s) {
    for(int i = 0 ; i < 8 ; i++) {
        if(s == noun[i]) return true;
    }
    return false;
}


bool isverb(string s) {
    for(int i = 0 ; i < 8 ; i++) {
        if(s == verb[i]) return true;
    }
    return false;
}


bool isarticle(string s) {
    for(int i = 0 ; i < 2 ; i++) {
        if(s == article[i]) return true;
    }
    return false;
}



int main() {
    string s;
    while(getline(cin, s)) {
        int verb = 0;

        vector<string> words;
        int l = 0;
        int r = s.find(" ");
        while(r != string::npos) {
            if(r-l != 0) {
                words.push_back(s.substr(l, r-l));
            }
            l = r+1;
            r = s.find(" ", l);
        }
        words.push_back(s.substr(l));
        for(int i = 0 ; i < words.size() ; i++) {
            if(words[i] == " " || words[i] == "") {words.erase(words.begin()+i);i = 0;}
        }
        bool pass = true;

        vector<int> arr(words.size()); //noun = 1, verb = 2, articale = 3, and = 4, other = 5
        for(int i = 0 ; i < words.size() ; i++) {
            if(isnoun(words[i])) {
                arr[i] = 1;
            }else if(isverb(words[i])) {
                verb++;
                arr[i] = 2;
            }else if(isarticle(words[i])) {
                arr[i] = 3;
            }else if(words[i] == ",") {
                verb--;
                arr[i] = 5;
            }else if(words[i] == "and") {
                arr[i] = 4;
            }else{
                arr[i] = 5;
                pass = false;
            }
        }


        arr.insert(arr.begin(), 5);
        arr.push_back(5);



        for(int i = 1 ; i < arr.size()-1 ; i++) {
            if(arr[i] == 1) {
                if(arr[i+1] == 1) pass = false;
            }
        }


        for(int i = 1 ; i < arr.size()-1 ; i++) {
            if(arr[i] == 3) {
                if(arr[i+1] == 1)  arr[i] = 1;
                else pass = false;
            }
        }
        for(int i = 1 ; i < arr.size()-1 ; i++) {
            if(arr[i] == 4) {
                if(arr[i+1] == 1 && arr[i-1] == 1)  arr[i] = 1;
                else pass = false;
            }
        }


        for(int i = 1 ; i < arr.size()-1 ; i++) {
            if(arr[i] == 2) {
                if(arr[i+1] != 1 || arr[i-1] != 1) pass = false;
            }
        }



        if(verb != 1) pass = false;


        if(pass) {
            cout << "YES I WILL" << endl;
        }else{
            cout << "NO I WON'T" << endl;
        }


    }
}
