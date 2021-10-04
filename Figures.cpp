#include <iostream>
#include <sstream>
#include <iomanip>
#include <string>
#include <cmath>
#include <vector>
#include <memory>

using namespace std;

class Figure{
public:
    Figure(const string& name): name_(name){}
    virtual string Name() = 0;
    virtual float Perimeter() = 0;
    virtual float Area() = 0;

    const string name_;
};

class Triangle : public Figure{
public:
    Triangle(const int&a, const int&b, const int&c):
        Figure("TRIANGLE"), a_(a), b_(b), c_(c){

    }

    string Name()override{
        return name_;
    }

    float Perimeter() override{
        return a_+b_+c_;
    }

    float Area() override{
        float s = float(a_+b_+c_)/2;
        return sqrt(s*(s-a_)*(s-b_)*(s-c_));
    }

private:
    int a_, b_, c_;
};

class Rect : public Figure{
public:
    Rect(const int& w, const int& h):
        Figure("RECT"), w_(w), h_(h){

    }

    string Name()override{
        return name_;
    }

    float Perimeter() override{
        return float(w_+h_)*2;
    }

    float Area() override{
        return float(w_*h_);
    }
private:
    int w_, h_;
};

class Circle : public Figure{
public:
    Circle(const int& r):
        Figure("CIRCLE"), r_(r){

    }

    string Name()override{
        return name_;
    }

    float Perimeter() override{
        return 2*3.14*r_;
    }

    float Area() override{
        return 3.14*pow(r_,2);
    }
private:
    int r_;
};

shared_ptr<Figure> CreateFigure(istringstream& is){
    string name;
    is >> name;
    if(name == "RECT"){
        int w, h;
        is >> w >> h;
        return make_shared<Rect>(w, h);
    }else if(name == "TRIANGLE"){
        int a, b, c;
        is >> a >> b >> c;
        return make_shared<Triangle>(a, b, c);
    }else if(name == "CIRCLE"){
        int r;
        is >> r;
        return make_shared<Circle>(r);
    }else{
        return 0;
    }
}

int main() {
  vector<shared_ptr<Figure>> figures;
  for (string line; getline(cin, line); ) {
    istringstream is(line);

    string command;
    is >> command;
    if (command == "ADD") {
      is >> ws;
      figures.push_back(CreateFigure(is));
    } else if (command == "PRINT") {
      for (const auto& current_figure : figures) {
        cout << fixed << setprecision(3)
             << current_figure->Name() << " "
             << current_figure->Perimeter() << " "
             << current_figure->Area() << endl;
      }
    }
  }
  return 0;
}
