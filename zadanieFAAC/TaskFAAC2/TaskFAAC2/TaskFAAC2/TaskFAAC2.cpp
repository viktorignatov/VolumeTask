#include <iostream>
#include "stdafx.h"
#define _USE_MATH_DEFINES
#include <math.h>
#include <conio.h>
#include <string>
#include <vector>
#include "classes.h"

using namespace std;

int main()
{
    int option{};

    while (option != 10)
    {
        cout << "\nOPTIONS: " << endl;

        cout << "1. Create Cuboid" << endl;
        cout << "2. Create Cone" << endl;
        cout << "3. Create Cylinder" << endl;
        cout << "4. Create Sphere" << endl;
        cout << "5. Calculate and display all objects and their volume in order of creation" << endl;
        cout << "6. Calculate and display all objects and their volume sorted by their type" << endl;
        cout << "7. Calculate and display all objects and their volume sorted by their type and volume" << endl;
        cout << "8. Display the total volume of all objects" << endl;
        cout << "9. Display the total volume of objects from the same type" << endl;
        cout << "10. Exit" << endl;

        cout << "\nEnter an option: " << endl;
        cin >> option;

        switch (option)
        {
            case 1: //Cuboid
            {
                dataOBJ[count_Obj] = new Cuboid();
                dataOBJ[count_Obj]->getData();
                count_Obj++;
                break;
            }
            case 2: //Cone
            {
                dataOBJ[count_Obj] = new Cone();
                dataOBJ[count_Obj]->getData();
                count_Obj++;
                break;
            }
            case 3: //Cylinder
            {
                dataOBJ[count_Obj] = new Cylinder();
                dataOBJ[count_Obj]->getData();
                count_Obj++;
                break;
            }
            case 4: //Sphere
            {
                dataOBJ[count_Obj] = new Sphere();
                dataOBJ[count_Obj]->getData();
                count_Obj++;
                break;
            }
            case 5:
            {
                allObjects();
                break;
            }
            case 6:
            {
                typeAllObjects();
                break;
            }
            case 7:
            {
                typeAndVolumeObject();
                break;
            }
            case 8:
            {
                allObjectsVolume();
                break;
            }
            case 9:
            {
                allObjectsTypeVolume();
                break;
            }
        } 
    }
    return 0;
}

    



