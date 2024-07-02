#include "easyfind.hpp"
#include <vector>

int main(void)
{
    int arr[] = {0, 1, 2, 3, 4, 5};
    std::vector<int> x(arr, arr + sizeof(arr) / sizeof(arr[0]));


    try {
        std::vector<int>::iterator it = easyfind(x, 10);
        std::cout << "found a number : " << *it << std::endl;

    } catch(std::exception &e) {
        std::cout << e.what() << std::endl;
    }
    
    // for (std::vector<int>::iterator it = x.begin() ; )
    // std::vector<int>::iterator it = x.begin() ;
    // std::cout << *(++it) << std::endl;


}