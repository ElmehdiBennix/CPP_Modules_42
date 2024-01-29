
#include "iostream"

class a
{
    int x;

    public:
        a(): x(2){{std::cout<<"a\n";}};

        int get_x(){return x;};
};

class b : public a
{
    public:
        b():a(){std::cout<<"b\n";};
};

int main ()
{
    b one;

    std::cout << one.get_x() << std::endl;
}