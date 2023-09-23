#include<iostream>
using namespace std;

  class Rectangle {
  public:
    float l,w;
    Rectangle(float ll, float ww) {
      l=ll; w = ww;
    }
    float a() { return l*w; }
    float p() { return 2*(l+w); }
  };

int main() 
{
    float l,w;
    cout << "Enter the length of the rectangle: ";cin>>l;
    cout << "Enter the width of the rectangle: ";cin>>w;
    Rectangle r(l, w);
    cout << "Rectangle Area: " << r.a() << endl;
    cout << "Rectangle Perimeter: " << r.p() << endl;
    return 0;
}
