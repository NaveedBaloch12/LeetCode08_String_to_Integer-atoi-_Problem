#include <iostream>

using namespace std;

int myAtoi(string s)
{
    int Number = 0;
    bool Negative = false;
    bool Updateed = false;

    for (int i = 0; i < s.length(); i++)
    {
        // Ignore leading whitespace
        if (!Updateed && s[i] == ' ')
        {
            continue;
        }
        else if(Updateed && s[i] == ' ')
        {
            break;
        }

        // Signedness check
        if (!Updateed && s[i] == '-')
        {
            Updateed = true;
            Negative = true;
            continue;
        }
        else if (!Updateed && s[i] == '+')
        {
            Updateed = true;
            continue;
        }
        else if (!Updateed && (s[i] == '-' || s[i] == '+'))
        {
            break;
        }

        // Check for Digit
        if (s[i] < '0' || s[i] > '9')
        {
            break;
        }

        // Rounding check if integer
        {
            if (Number > INT_MAX / 10 || (Number == INT_MAX / 10 && s[i] - '0' > 7))
            {
                if(Negative)
                {
                    return INT_MIN;
                }
                else
                {
                    return INT_MAX;
                }
            }

            Number = Number * 10 + (s[i] - '0');
            Updateed = true;
        }
    }
    if (Negative == true)
    {
        Number = -Number;
    }

    return Number;
}

int main()
{

    cout << myAtoi("  -012");

    return 0;
}