#include <iostream>
class Base
{
    public:
        Base()
        {
            construct();
        }
        virtual void construct() = 0;
};

class Derived : public Base
{
    public:
        void construct() override
        {
            std::cout << "constructed" << std::endl;
        }
};

int main(int argc, char **argv)
{
    Derived d;
}
