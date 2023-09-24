#include<iostream>
using namespace std;

  class Rectangle {
  public:
    float length, width;
    Rectangle (float input_length, float input_width) {
      length = input_length; width = input_width;
    }

    /*
    pre: none
    post: returns the area of the rectangle
    */
    float area() { 
      return length * width; 
    }
    /*
    pre: none
    post: returns the perimeter of the rectangle
    */
    float perimeter() {
      return 2 * (length + width);
    }
  };

int main() 
{
    float length, width;
    cout << "Enter the length of the rectangle: ";
    cin >> length;
    cout << "Enter the width of the rectangle: ";
    cin >> width;
    Rectangle my_rectangle(length, width);
    cout << "Rectangle Area: " << my_rectangle.area() << endl;
    cout << "Rectangle Perimeter: " << my_rectangle.perimeter() << endl;
    return 0;
}
