#include <iostream>

class Circle
{
    const double PI{ 3.1415 };

    double radius;
public:
    void SetRadius(double radius) { this->radius = radius; }
    double GetRadius() { return this->radius; }

    friend double CircleSquare(Circle circle);
};

double CircleSquare(Circle circle)
{
    return circle.PI * circle.radius * circle.radius;
}


class User
{
    static int Id;

    int id;
    char* name{ new char[20] };
public:
    User(const char* name)
    {
        strcpy_s(this->name, 20, name);
        id = ++Id;
    }
    
    void Info()
    {
        std::cout << "Name " << name << ", Id " << id << "\n";
    }
};


static class Math
{
public:
    static double Sin(double x)
    {
        return sin(x);
    }
};

class Arr
{
    int* pointer;
public:
    Arr() : pointer{ new int }
    {
        *pointer = 0;
        std::cout << "Arr construct\n";
    }
    Arr(int value) : pointer{ new int }
    {
        *pointer = value;
        std::cout << "Arr parametr construct\n";
    }
    Arr(const Arr& arr)
    {
        pointer = new int;
        *pointer = *arr.pointer;

        std::cout << "Arr copy construct\n";
    }

    ~Arr()
    {
        delete pointer;
        std::cout << "Arr destruct\n";
    }
};

void Func(Arr a)
{
    std::cout << "Func is work\n";
}

int User::Id = 0;

int main()
{
    {
        Arr arr(20);
        Arr arr2 = arr;
        Arr arr3(arr);

        Arr arr4;
        arr4 = arr;
    }
    
    //Arr arr(20);
    //Func(arr);
    
    std::cout << "end of programm\n";

    //User user1("Bobby");
    //User user2("Tommy");
    ////user.Id = 100;
    //user1.Info();
    //user2.Info();

    //User user3 = user1;
    //user3.Info();

    //std::cout << Math::Sin(23) << "\n";
}
