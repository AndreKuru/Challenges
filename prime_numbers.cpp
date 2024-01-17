#include <iostream>
#include <sstream>
#include <string>
#include <cmath>
#include <vector>

bool check_number(long number, std::vector<long>& primes)
{
    auto is_prime = true;
    for (auto& prime : primes) {
        if (prime >= number) {
            break;
        }
        if (number % prime == 0) {
            is_prime = false;
            break;
        }
    }
    return is_prime;
}

void check_numbers(long min_prime, long max_prime, std::vector<long>& primes)
{
    auto n = min_prime;
    if (n == 2) {
        std::cout << n << '\n';
        ++n;
    } else if (n % 2 == 0) {
        ++n;
    }
    for (; n <= max_prime; ++n) {
        if (check_number(n, primes)) {
            std::cout << n << '\n';
        }
    }
}

void consult_numbers(long max_prime, std::vector<long>& primes)
{
    auto i = 0;
    while (i < primes.size() and primes[i] <= max_prime) {
        std::cout << primes[i] << '\n';
        ++i;
    }
}
int main()
{
    auto primes = std::vector<long>{};
    auto high_limit = 0l;
    auto testing_limit = 1l;
    std::vector<bool> numbers(2, false);

    while(true) {
        auto max_prime = 0l;
        auto line = std::string();
        while(true) {
            std::cout << "Entrada: ";
            std::getline(std::cin, line);
            auto line_stream = std::stringstream{line};
            line_stream >> max_prime;

            if (max_prime > 1) {
                break;
            } else {
                std::cout << "Entrada inválida! Insira um número inteiro maior que 1.\n";
            }
        }

        // Values until sqrt
        if (max_prime > high_limit) {
            high_limit = max_prime;

            double testing_limit_aux = sqrt(high_limit);
            auto new_testing_limit = ceil((double)testing_limit_aux);
            numbers.insert(numbers.end(), new_testing_limit - testing_limit, false);

            // Extend old values
            for (auto i = 2; i <= testing_limit; ++i) {
                if (numbers[i] == false) {
                    auto shift = i - (testing_limit % i);
                    for (auto j = testing_limit + shift; j < numbers.size(); j += i) {
                        numbers[j] = true;
                    }
                }
            }

            // Calculate new values
            for (auto i = testing_limit + 1; i <= new_testing_limit; ++i) {
                if (numbers[i] == false) {
                    primes.push_back(i);
                    for (auto j = i * i; j < numbers.size(); j += i) {
                        numbers[j] = true;
                    }
                }
            }

            testing_limit = new_testing_limit;
        }

        // Print all requested values
        if (max_prime <= testing_limit) {
            consult_numbers(max_prime, primes);
        } else {
            consult_numbers(testing_limit, primes);
            check_numbers(testing_limit + 1, max_prime, primes);
        }

        std::cout << std::endl;
    }
}