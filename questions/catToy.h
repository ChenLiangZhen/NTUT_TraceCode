//
// Created by Light Chen on 2024/1/3.
//

#ifndef TRACECODE_CATTOY_H
#define TRACECODE_CATTOY_H

#include <iostream>
#include <string>

#define PI 3
using namespace std;

class MathVector {

private:
    double *_content;
    int _size;
public:
    MathVector() {}

    MathVector(double *input, int size = 0) {
        _content = new double[size];
        _size = size;
        for (int i = 0; i < size; i++) {
            _content[i] = input[i];
        }
    }

    MathVector(const MathVector &input) {
        _content = new double[input._size];
        _size = input._size;
        for (int i = 0; i < _size; i++) {
            _content[i] = input._content[i];
        }
    }

    ~MathVector() {
        if (_content != NULL) delete[] _content;
    }

    MathVector &operator=(const MathVector &input) {
        if (_content != NULL) {
            delete[] _content;
        }
        _size = input._size;
        _content = new double[_size];
        for (int i = 0; i < _size; i++) {
            _content[i] = input._content[i];
        }
        return *this;
    }

    double &component(int index) const {
        return _content[index - 1];
    }

};

class Shape {
protected:
    MathVector _center;
public:
    Shape(MathVector center) {
        _center = center;
    }

    virtual double perimeter() const = 0;

    virtual ~Shape() {};
};

class Circle : public Shape {
private:
    double _radius;
public:
    Circle(double radius, MathVector center) : Shape(center) {
        _radius = radius;
    }

    ~Circle() override {}

    double perimeter() const override {
        return 2 * _radius * PI;
    }
};

void execute_ca() {

    double y[2] = {1, 90};
    MathVector output = MathVector(y, 2);
    cout << output.component(2) << endl;
    Shape *output2 = new Circle(1, output);
    cout << output2->perimeter() << endl;
    delete output2;
}

#endif //TRACECODE_CATTOY_H
