#include <iostream>
#include <cstdlib>
#include <ctime>

int generateRandomNum() {
    srand(time(0));

    int randomNum{};

    randomNum = rand() % 11;

    return randomNum;
}

int main()
{
    bool running = true;
    int playerInput{};
    std::string answer{};
    int balance = 100;
    int moneyWon{};

    std::cout << "Welcome to the Casino Number Guessing game! " << '\n' << '\n';
    std::cout << "Are you ready to guess? Your balance is " << balance << "$ ." << '\n' << '\n';

    while (running) {
        
        std::cout << "Please enter a number from 1 to 10 (Cost: 10$): ";
        std::cin >> playerInput;
        balance -= 10;

        if (playerInput == generateRandomNum()) {
            moneyWon += 20;
            balance += moneyWon;
            std::cout << "You gessed it! You receive 20$" << '\n';
            std::cout << "You have: " << balance << "$ ." << '\n';
            std::cout << "Do you want to try again? (Y/N): ";
            std::cin >> answer;
            if (answer == "N")
            {
                std::cout << "You won: " << moneyWon << "$ !" << '\n';
                std::cout << "Thank you for playing!" << '\n';
                running = false;
            }


        }
        else {
            std::cout << "Sorry, your guess was wrong! Balance: " << balance << "$ " << '\n';
            std::cout << "Sorry. Do you want to try again? (Y/N): ";
            std::cin >> answer;
            if (answer == "N")
            {
                std::cout << "You ended up with: " << balance << "$ ." << '\n';
                std::cout << "Thank you for playing!" << '\n';
                running = false;
            }

            if (balance <= 0)
            {
                std::cout << "You have run out of money! Game over !" << '\n';
                running = false;
            }
        }

        return 0;
    }


}
