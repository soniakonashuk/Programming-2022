#include <iostream>;
#include <random>;

using namespace std;

// enum of Colors
enum Color
{
    RED,
    BLACK,
    GREEN,
    BLUE,
    YELLOW,
    WHITE,
    ORANGE,
    PURPLE,
    PINK,
    BROWN,
    GREY,
    GOLD,
};

struct ColorBall {
    Color color;
    double radius;
};

// check if element is present in Array
bool isPresent(string arr[], int size, string element)
{
    for (int i = 0; i < size; i++)
    {
        if (arr[i] == element)
        {
            return true;
        }
    }
    return false;
}

// function to get value from enum
string getColorByIndex(Color colors)
{
    switch (colors)
    {
    case RED:
        return "Red";
    case BLACK:
        return "Black";
    case GREEN:
        return "Green";
    case BLUE:
        return "Blue";
    case YELLOW:
        return "Yellow";
    case WHITE:
        return "White";
    case ORANGE:
        return "Orange";
    case PURPLE:
        return "Purple";
    case PINK:
        return "Pink";
    case BROWN:
        return "Brown";
    case GREY:
        return "Grey";
    case GOLD:
        return "Gold";
    default:
        return "Unknown";
    }
}

// function get random value from enum

Color getRandomColor()
{
    // get random value from enum
    int randomValue = rand() % 12;
    return static_cast<Color>(randomValue);
}

// get ball with biggest radius
ColorBall getBiggestBall(ColorBall balls[], int size)
{
    ColorBall biggestBall = balls[0];
    for (int i = 1; i < size; i++)
    {
        if (balls[i].radius > biggestBall.radius)
        {
            biggestBall = balls[i];
        }
    }
    return biggestBall;
}

void main()
{

    string A[3] = {};

    // push colors to array
    for (int i = 0; i < 3; i++)
    {
        A[i] = getColorByIndex(getRandomColor());
    }

    // get enum value by index
    for (int i = 0; i < 3; i++)
    {
        cout << A[i] << endl;
    }

    int M = 4;
    string B[4] = {};
    string color;
    for (int j = 0; j < M; j++)
    {
        cout << "Enter color: " << endl;
        cin >> color;
        if (!isPresent(A, 3, color))
        {
            B[j] = color;
        }
    }
    // show B array

    cout << "B Array: " << endl;
    for (int i = 0; i < 4; i++)
    {
        cout << B[i] << endl;
    }

    // Fill Color Ball Array
    ColorBall colorBallArray[5] = {};
    for (int i = 0; i < 5; i++)
    {
        colorBallArray[i].color = getRandomColor();
        colorBallArray[i].radius = rand() % 10;
    }

   // print ball with biggest radius
    ColorBall biggestBall = getBiggestBall(colorBallArray, 5);
    cout << "Biggest ball: " << getColorByIndex(biggestBall.color) << " " << biggestBall.radius << endl;
