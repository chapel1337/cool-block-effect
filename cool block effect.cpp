#include <iostream>
#include <string>
#include <random>
#include <windows.h>

using std::cout; using std::cin; using std::string;

// written by chapel1337
// made on 10/12/2022
// somewhat crappy, mostly just experimenting with for loops
// it still hurts my brain when reading it
// still debating if i want to publicize this
// was originally supposed to be a wave simulation, so that's why the functions contain the name "wave"

// ------- \\

void menu();

void sleep(auto time)
{
    Sleep(time * 1000);
}

void clear()
{
    std::system("cls");
}

void title(string title)
{
    std::system(("title " + title).c_str());
}

int previousRandom{ 0 };

int getRandom(int min, int max)
{
    // https://learncpp.com
    std::mt19937 mt{ std::random_device{}() };
    std::uniform_int_distribution random{ min, max };

    return random(mt);
}

// ------- \\

void randomRaise(int height, int width)
{
    clear();
    int random{ getRandom(1,3) };

    for (int i{ 0 }; i < height; i++)
    {
        cout << '\n';
    }

    //

    for (int i{ 0 }; i < random; i++)
    {
        for (int i{ 0 }; i < width; i++)
        {
            cout << '#';
        }
        cout << '\n';
    }

    /*
    for (int i{ 0 }; i < getRandom(1, 3); i++)
    {
        for (int i{ 0 }; i < width; i++)
        {
            for (int i{ 0 }; i < getRandom(1, 5); i++)
            {
                cout << '#';
            }
            for (int i{ 0 }; i < getRandom(1, 5); i++)
            {
                cout << ' ';
            }
        }
        cout << '\n';
    }
    */

    for (int i{ 0 }; i < height - 1; i++) // -1 because it added an extra line for some reason
    {
        for (int i{ 0 }; i < width; i++)
        {
            cout << '#';
        }
        cout << '\n';
    }

    sleep(0.5);
    randomRaise(height, width);
}

void makeWave(int height, int width, auto speed)
{
    int skyHeight = height;

    // you are now entering: for loop hell
    for (int i{ 0 }; i < height; i++)
    {
        for (int i{ 0 }; i < 5; i++)
        {
            cout << '\n';
        }

        for (int i{ skyHeight }; i > 0; --i)
        {
            cout << '\n';
        }

        for (int i{ skyHeight }; i < height; ++i)
        {
            for (int i{ 0 }; i < width; ++i)
            {
                sleep(speed);
                cout << '#';
            }
            cout << '\n';
        }

        --skyHeight;

        if (skyHeight == 0)
        {
            sleep(1);
            randomRaise(height, width);
        }

        sleep(0.15);
        clear();
    }
    // you are now exiting: for loop hell
}

// ------- \\

void invalidInput(string message)
{
    clear();
    title("cool block effect - invalid input");
    
    cout << message << '\n';

    sleep(2);
    menu();
}

void checkForInvalid(int inputHeight, int inputWidth, auto inputSpeed)
{
    if (inputHeight <= 0 || inputWidth <= 0 || inputSpeed <= 0)
    {
        invalidInput("number cannot be less or equal to zero!");
    }

    else if (inputHeight > 20)
    {
        invalidInput("height cannot be greater than 20!");
    }
    else if (inputWidth > 100)
    {
        invalidInput("width cannot be greater than 100!");
    }

    else if (inputSpeed > 5)
    {
        invalidInput("speed cannot be greater than 5 seconds!");
    }

    makeWave(inputHeight, inputWidth, inputSpeed);
}

void menu()
{
    clear();
    title("cool block effect - menu");

    // preset are default
    int inputHeight{ 5 };
    int inputWidth{ 75 };
    auto inputSpeed{ 0.1 };

    cout << "height?\n";
    cin >> inputHeight;

    clear();

    cout << "width?\n";
    cin >> inputWidth;

    clear();

    cout << "speed?\n";
    cin >> inputSpeed;

    checkForInvalid(inputHeight, inputWidth, inputSpeed);
}

// ------- \\

int main()
{
    title("cool block effect - credits");

    cout << "written by chapel1337\n";
    cout << "made on 10/12/2022\n";

    sleep(2);
    menu();
}
