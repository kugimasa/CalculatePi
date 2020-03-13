#include <iostream>
#include <cstdlib>
#include <random>

using namespace std;

// Error Handling
bool checkArgc(int argc)
{
    if (argc == 1)
    {
        cout << "🙅‍You must have an input number." << endl;
        return false;
    }
    else if (argc >= 3)
    {
        cout << "🙅‍The input must be a single number." << endl;
        return false;
    }
    else
    {
        return true;
    }
}

// Error Handling2
bool checkArgv(int num)
{
    if (num == 0)
    {
        cout << "🙅‍The input number must a number grater than 0." << endl;
        return false;
    }
    else
    {
        return true;
    }    
}

bool pointInQuater(float x, float y)
{
    float distance = sqrt(x*x + y*y);
    if (distance <= 1.0)
    {
        return true;
    }
    else
    {
        return false;
    }
}

float calculatePi(int quaterPoints, int num)
{
    return (float) 4 * quaterPoints / num;
}

int main (int argc, char *argv[])
{
    if (!checkArgc(argc))
    {
        return 0;
    }
    int num = atoi(argv[1]);
    if (!checkArgv(num))
    {
        return 0;
    }

    random_device seed_gen;
    mt19937 seed(seed_gen());
    int quater_points = 0;
    for (int i = 0; i < num; i++)
    {
        constexpr size_t bits = numeric_limits<float>::digits;
        float x = generate_canonical<float, bits>(seed);
        float y = generate_canonical<float, bits>(seed);
        if (pointInQuater(x, y))
        {
            quater_points++;
        }
    }
    float pi = calculatePi(quater_points, num);
    cout << "π : " << pi << endl;
    return 0;
}
