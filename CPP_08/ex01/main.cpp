#include "Span.hpp"

#define SIZE 50

int main()
{
    try
    {
        srand(time(0));

        std::vector<int> vec(SIZE);
        std::cout << "====> starting print <====" << std::endl;
        for (int i = 0; i < SIZE; i++)
        {
            vec[i] = rand();
            std::cout << vec[i] << " ";
        }
        std::cout << std::endl;

        Span holder(SIZE);
        holder.addNumber(vec.begin(),vec.end());
        const std::vector<int>& x = holder.getvec();

        std::cout << "====> starting print <====" << std::endl;
        for (int i = 0; i < SIZE; i++)
            std::cout << x[i] << " ";
        std::cout << std::endl;
        std::cout << "<===================>" << std::endl;

        std::cout << "shortest span : " << holder.shortestSpan() << std::endl;
        std::cout << "longest span : " << holder.longestSpan() << std::endl;

        std::cout << "<===================>" << std::endl;
        Span sp = Span(6);

        sp.addNumber(6);
        sp.addNumber(3);
        sp.addNumber(17);
        sp.addNumber(9);
        sp.addNumber(11);

        std::cout << "shortest span : " << sp.shortestSpan() << std::endl;
        std::cout << "longest span : " << sp.longestSpan() << std::endl;
        std::cout << "<===================>" << std::endl;
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << std::endl;
    }

    return 0;
}
