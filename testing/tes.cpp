
#include <iostream>

class orto
{
    private:
        int a;
        int *p;
    public:
        orto(){};
        orto(int a){
            this->a = a;
            p = new int(70);
        };
        ~orto(){
            std::cout << "destructor called"<< std::endl;
            delete this->p;            
        };
        orto(const orto &obj)
        {
            this->a = obj.a;
            this->p = new int(*obj.p);
        }
        void print(){
            std::cout << "orto called " << p << std::endl;
        }
};

int main()
{
    orto a(5);
    orto b = a;

    orto c(70);


    c = a;

    std::cout << a << std::endl;


    a.print();
    b.print();
}