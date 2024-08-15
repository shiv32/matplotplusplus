#include <chrono>
#include <iostream>
#include <random>
#include <thread>

#include <matplot/matplot.h>

int main() {

    using namespace matplot;

    //--------------------------------------
    // Initialize random number generator
    std::random_device rd;
    std::mt19937 gen(rd()); // Mersenne Twister pseudo-random generator

    // Define a distribution
    std::uniform_int_distribution<> dis(1, 100); // Generates integers in the range [1, 100];



    while (true) {

       int random_number = dis(gen);

        // Output the random number
        std::cout << "Random number: " << random_number << std::endl;

        auto x = transform(iota(1, random_number), [](double x) { return pow(x, 2); });

        plot(x);

        xlabel("Population");

        show();

        // Wait for 2 seconds
        std::this_thread::sleep_for(std::chrono::seconds(2));
    }

    //--------------------------------------

    // auto x = transform(iota(1, 10), [](double x) { return pow(x, 2); });

    // plot(x);

    // xlabel("Population");

    // show();

    return 0;
}

/*
#include <chrono>
#include <iostream>
#include <random>
#include <thread>

int main() {
    // Initialize random number generator
    std::random_device rd;
    std::mt19937 gen(rd()); // Mersenne Twister pseudo-random generator

    // Define a distribution
    std::uniform_int_distribution<> dis(1, 100); // Generates integers in the
range [1, 100]

    while (true) {
        // Generate a random number
        int random_number = dis(gen);

        // Output the random number
        std::cout << "Random number: " << random_number << std::endl;

        // Wait for 2 seconds
        std::this_thread::sleep_for(std::chrono::seconds(2));
    }

    return 0;
}



*/