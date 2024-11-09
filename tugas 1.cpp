#include <iostream>
#include <cmath>
using namespace std;

float distance(float x1, float x2, float y1, float y2)
float radius(float x1, float x2, float y1, float y2)
float circumference(float r)
float area(float r)

distance(float, float, float, float)
radius(float, float, float, float)
circumference(float)
area(float)

#define pi 3.1416

float distance(float x1, float x2, float y1, float y2){
    float dist = sqrt((x2-x1)*(x2-x1) + (y2-y1)*(y2-y1));
    return dist;
}

float radius(float x1, float x2, float y1, float y2){
    return distance(x1, x2, y1, y2);
}

float circumference(float r){
    float circum = 2*pi*r;
    return circum;
}

float area(float r){
    float a = pi*r*r;
    return a;
}

int main(){
    // Menggunakan titik (3,4) sebagai titik pusat lingkaran dan titik (11.2,13.8) sebagai titik di keliling lingkaran

    float x1 = 3;
    float x2 = 4;
    float y1 = 11.2;
    float y2 = 13.8;
    
    float dist = distance(x1, x2, y1, y2);
    float r = radius(x1, x2, y1, y2);
    float circum = circumference(r);
    float a = area(r);
    
    cout << "Distance : " << dist << endl;
    cout << "Radius : " << r << endl;
    cout << "Circumference : " << circum << endl;
    cout << "Area : " << a << endl;
    
    return 0;
}