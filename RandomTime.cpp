#include <iostream>
#include <random>
#include <cstdlib>
#include <chrono>

using namespace std;

float generateRand()
{
    random_device seed_gen;
    mt19937 seed(seed_gen());
    constexpr size_t bits = numeric_limits<float>::digits;
    return generate_canonical<float, bits>(seed);
}

int main (int argc, char *argv[])
{
    int num = atoi(argv[1]);

    // Check time
    chrono::system_clock::time_point start, end;
    // generateRand1
    start = chrono::system_clock::now();
    random_device seed_gen;
    mt19937 seed(seed_gen());
    for (int i = 0; i < num; i++)
    {
        constexpr size_t bits = numeric_limits<float>::digits;
        float random_num = generate_canonical<float, bits>(seed);
    }
    end = chrono::system_clock::now();
    double time = static_cast<double>(chrono::duration_cast<chrono::microseconds>(end - start).count() / 1000.0);
    printf("generateRand1() %lf[ms]\n", time);

    // generateRand2
    start = chrono::system_clock::now();
    for (int i = 0; i < num; i++)
    {
        float random_num = generateRand();
    }
    end = chrono::system_clock::now();
    time = static_cast<double>(chrono::duration_cast<chrono::microseconds>(end - start).count() / 1000.0);
    printf("generateRand2() %lf[ms]\n", time);
    return 0;
}