#include <iostream>
#include <string>

int main()
{
    std::string score;
    std::cin >> score;
    
    if (score == "A+"){
        std::cout << "4.3";
    }
    else if (score == "A0"){
        std::cout << "4.0";
    }
    else if (score == "A-"){
        std::cout << "3.7";
    }
    else if (score == "B+"){
        std::cout << "3.3";
    }
    else if (score == "B0"){
        std::cout << "3.0";
    }
    else if (score == "B-"){
        std::cout << "2.7";
    }
    else if (score == "C+"){
        std::cout << "2.3";
    }
    else if (score == "C0"){
        std::cout << "2.0";
    }
    else if (score == "C-"){
        std::cout << "1.7";
    }
    else if (score == "D+"){
        std::cout << "1.3";
    }
    else if (score == "D0"){
        std::cout << "1.0";
    }
    else if (score == "D-"){
        std::cout << "0.7";
    }
    else if (score == "F"){
        std::cout << "0.0";
    }
    
    return 0;
}