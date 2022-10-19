#include <bits/stdc++.h>
#include <vector>
using namespace std;

struct Vertex{
    int x, y;
};

int n;

vector <Vertex> vertex;


double dist(Vertex a, Vertex b) {
    return sqrt((a.x-b.x)*(a.x-b.x) + (a.y-b.y)*(a.y-b.y));
}

int cross_product(Vertex a, Vertex b, Vertex c) {
    /*cout << "a " << a.x << " " << a.y << endl;
    cout << "b " << b.x << " " << b.y << endl;
    cout << "c " << c.x << " " << c.y << endl;*/
    return (b.x-a.x)*(c.y-a.y) - (c.x - a.x)*(b.y-a.y);
}

void output(vector <Vertex> s) {
    //cout << "output here " << endl;
    cout << s.size() << endl;
    for(int i = 0 ; i < s.size() ; i++) {
        cout << s[i].x << " " << s[i].y << endl;
    }
}

bool cmp1(Vertex a, Vertex b) {
    if(a.y == b.y) return a.x < b.x;
    else return a.y < b.y;
}

bool cmp2(Vertex a, Vertex b) {
    int cross = cross_product(vertex[0], a, b);
    return cross > 0 || (cross == 0 && dist(vertex[0], a) < dist(vertex[0], b));
}

void convexhull() {
    sort(vertex.begin(), vertex.end(), cmp1);
    int Size = vertex.size();
    for(int i = 1 ; i < Size ; i++) {
        for(int j = 1 ; j < Size ; j++) {
            if(i == j) continue;
            if(!cross_product(vertex[0], vertex[i], vertex[j])) {
                double d1 = dist(vertex[0], vertex[i]);
                double d2 = dist(vertex[0], vertex[j]);
                if(d1 > d2) {
                    vertex.erase(vertex.begin()+j);
                }else{
                    vertex.erase(vertex.begin()+i);
                }
                Size--;
                i = 1;
                j = 1;
                break;
            }
        }
    }
    sort(vertex.begin()+1, vertex.end(), cmp2);
    /*cout << "after sort" << endl;
    for(int i = 0 ; i < vertex.size() ; i++) {
        cout << vertex[i].x << " " << vertex[i].y << endl;
    }*/


    //if(vertex.size() == 2) {
     //   s.push_back(vertex[0]_
    //}
    vertex.push_back(vertex[0]);
    vector <Vertex> s;
    s.push_back(vertex[0]);
    s.push_back(vertex[1]);
    s.push_back(vertex[2]);
    /*for(int i = 0 ; i < s.size() ; i++) {
        cout << "s[" << i << "] == " << s[i].x << " " << s[i].y << endl;
    }*/
    for(int i = 3 ; i < vertex.size() ; i++) {
        while(cross_product(s[s.size()-2], s[s.size()-1], vertex[i]) <= 0) {
            s.pop_back();
        }
        s.push_back(vertex[i]);
    }
    output(s);
}


int main() {
    int T;
    cin >> T;
    cout << T << endl;
    for(int i = 0 ; i < T ; i++) {
        vertex.clear();
        if(i) {
            cin >> n;
            cout << "-1" << endl;
        }
        cin >> n;
        for(int i = 0 ; i < n ; i++) {
            Vertex temp;
            cin >> temp.x >> temp.y;
            vertex.push_back(temp);
        }
        convexhull();
    }
}
