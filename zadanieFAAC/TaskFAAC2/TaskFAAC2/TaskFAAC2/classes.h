#include <iostream>

using namespace std;
#pragma once

int obj_Cuboid = 0; //object of type Cuboid
int obj_Cone = 1; //object of type Cone
int obj_Cylinder = 2; //object of type Cylinder
int obj_Sphere = 3; //object of type Sphere

class Shape
{
public:
    double shapeVolume; //Volume var

    Shape()
    {
        shapeVolume = 0;
    };

    Shape(double shapeVolume)
    {
        this->shapeVolume = shapeVolume;
    }

    double getVolume() { return this->shapeVolume; }

    void printAllData()
    {
        if (getType() == obj_Cuboid)
            cout << "Cuboid ";

        if (getType() == obj_Cone)
            cout << "Cone ";

        if (getType() == obj_Cylinder)
            cout << "Cylinder ";

        if (getType() == obj_Sphere)
            cout << "Sphere ";

        cout << "Volume: " << this->shapeVolume << endl; //display volume
    }

    virtual int getType() = 0;
    virtual void getData() {}
};

const int max_Obj = 100;
Shape* dataOBJ[max_Obj];
int count_Obj = 0;

class Cuboid : public Shape
{
private:
    float l, b, h; //length, breadth, height
public:
    Cuboid() : Shape()
    {

    }

    Cuboid(double shapeVolume) : Shape(shapeVolume)
    {

    }

    int getType()
    {
        return obj_Cuboid;
    }

    void getData()
    {
        cout << "Enter length of cuboid: " << endl;
        cin >> l;
        cout << "Enter breadth of cuboid: " << endl;
        cin >> b;
        cout << "Enter height of cuboid: " << endl;
        cin >> h;

        shapeVolume = (l * b * h); //calculate volume
    }
};

class Cone : public Shape
{
private:
    float r, h; //radius, height
public:
    Cone() : Shape()
    {

    }

    Cone(double shapeVolume) : Shape(shapeVolume)
    {

    }

    int getType()
    {
        return obj_Cone;
    }

    void getData()
    {
        cout << "Enter radius of cone: " << endl;
        cin >> r;
        cout << "Enter height of cone: " << endl;
        cin >> h;

        shapeVolume = (M_PI * pow(r, 2) * h) / 3; //calculate volume
    }
};

class Cylinder : public Shape
{
private:
    float r, h; //radius, height

public:
    Cylinder() : Shape()
    {

    }

    Cylinder(double shapeVolume) : Shape(shapeVolume)
    {

    }

    int getType()
    {
        return obj_Cylinder;
    }

    void getData()
    {
        cout << "Enter radius of cylinder: " << endl;
        cin >> r;
        cout << "Enter height of cylinder: " << endl;
        cin >> h;

        shapeVolume = M_PI * pow(r, 2) * h; //calculate volume
    }


};

class Sphere : public Shape
{
private:
    float r;
public:
    Sphere() : Shape()
    {

    }

    Sphere(double shapeVolume) : Shape(shapeVolume)
    {

    }

    int getType()
    {
        return obj_Sphere;
    }

    void getData()
    {
        cout << "Enter radius of sphere: " << endl;
        cin >> r;

        shapeVolume = (4 * M_PI * pow(r, 3)) / 3; //calculate volume
    }
};

void allObjects() //Prints all the objects and their volume in the order of their creation
{
    for (int i = 0; i < count_Obj; i++)
    {
        dataOBJ[i]->printAllData();
    }
};

void typeAllObjects() //Prints all objects sorted by their type
{

    //Selection Sort
    Shape* temp[max_Obj];

    for (int i = 0; i < count_Obj; i++)
    {
        temp[i] = dataOBJ[i];
    }

    for (int i = 0; i < count_Obj; i++)
    {
        int idx = i;
        for (int c = i + 1; c < count_Obj; c++)
        {
            if (temp[c]->getType() < temp[idx]->getType())
            {
                idx = c;
            }
        }
        swap(temp[i], temp[idx]);
    }
    for (int i = 0; i < count_Obj; i++)
    {
        temp[i]->printAllData();
    }

};

void typeAndVolumeObject() //Prints all objects sorted by their type and volume
{
    //Selection Sort
    Shape* temp[max_Obj];

    for (int i = 0; i < count_Obj; i++)
    {
        temp[i] = dataOBJ[i];
    }

    for (int i = 0; i < count_Obj; i++) //Type
    {
        int idx = i;
        for (int c = i + 1; c < count_Obj; c++)
        {
            if (temp[c]->getType() < temp[idx]->getType())
            {
                idx = c;
            }
        }
        swap(temp[i], temp[idx]);
    }
    for (int i = 0; i < count_Obj; i++) //Volume
    {
        int idx = i;
        for (int c = i + 1; c < count_Obj; c++)
        {
            if ((temp[c]->getType() == temp[idx]->getType()) && (temp[c]->getVolume() < temp[idx]->getVolume()))
            {
                idx = c;
            }
        }
        swap(temp[i], temp[idx]);
    }
    for (int i = 0; i < count_Obj; i++)
    {
        temp[i]->printAllData();
    }
};

void allObjectsVolume() //Prints the total volume of all objects
{
    double totalVolume{};
    for (int i = 0; i < count_Obj; i++)
    {
        totalVolume = dataOBJ[i]->getVolume() + totalVolume;

    }
    cout << "Total volume of all objects is: " << totalVolume << endl;
};

void allObjectsTypeVolume() //Prints the total volume of each type of objects
{
    double typeCuboidTotal = 0;
    double typeConeTotal = 0;
    double typeCylinderTotal = 0;
    double typeSphereTotal = 0;

    for (int i = 0; i < count_Obj; i++)
    {
        switch (dataOBJ[i]->getType())
        {
        case 0:
        {
            typeCuboidTotal = (dataOBJ[i]->getVolume()) + typeCuboidTotal;
            break;
        }
        case 1:
        {
            typeConeTotal = (dataOBJ[i]->getVolume()) + typeConeTotal;
            break;
        }
        case 2:
        {
            typeCylinderTotal = (dataOBJ[i]->getVolume()) + typeCylinderTotal;
            break;
        }
        case 3:
        {
            typeSphereTotal = (dataOBJ[i]->getVolume()) + typeSphereTotal;
            break;
        }
        }
    }
    cout << "Total volume of Cuboid objects is: " << typeCuboidTotal << endl;
    cout << "Total volume of Cone objects is: " << typeConeTotal << endl;
    cout << "Total volume of Cylinder objects is: " << typeCylinderTotal << endl;
    cout << "Total volume of Sphere objects is: " << typeSphereTotal << endl;
};