#include "Bureaucrat.hpp"

int main()
{
    try
    {
        Bureaucrat Teddy("Teddy", 2);
        Teddy.gradePlus();
        std::cout << "Promotion réussie : " << Teddy.getName() << ", grade " << Teddy.getGrade() << '\n';
    }
    catch(const std::exception& e)
    {
        std::cerr << "Erreur (promotion) : " << e.what() << '\n';
    }

    try
    {
        Bureaucrat Toddy("Toddy", 149);
        Toddy.gradeMinus();
        std::cout << "Rétrogradation réussie : " << Toddy.getName() << ", grade " << Toddy.getGrade() << '\n';
    }
    catch(const std::exception& e)
    {
        std::cerr << "Erreur (rétrogradation) : " << e.what() << '\n';
    }

    try
    {
        Bureaucrat Bozo("Bozo", 150);
        Bozo.gradeMinus();
    }
    catch(const std::exception& e)
    {
        std::cerr << "Erreur (rétrogradation à 150) : " << e.what() << '\n';
    }

    try
    {
        Bureaucrat King("King", 1);
        King.gradePlus();
    }
    catch(const std::exception& e)
    {
        std::cerr << "Erreur (promotion à 1) : " << e.what() << '\n';
    }

    return 0;
}
