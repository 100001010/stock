#include <iostream>
#include <string>
#include <cmath>
using namespace std;
void turn_to_number(int n, double stock_k[][4], int *number_k);
int amplitude(double stock_k[4]);
int head_foot(double stock_k[4]);
int main()
{
    int n = 2;
    double stock_k[n][4]; //[][開,收,高,低]
    int number_k[n];
    cout << "請由第一根開始輸入，並由開,收,高,低依序輸入";

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < 4; j++)
        {
            cin >> stock_k[i][j];
        }
    }
    turn_to_number(n, stock_k, number_k);
    for (int i = 0; i < n; i++)
        cout << number_k[i] << endl;
    return 0;
}
void turn_to_number(int n, double stock_k[][4], int *number_k)
{
    for (int i = 0; i < n; i++)
    {
        if (stock_k[i][0] - stock_k[i][1] < 0)
            number_k[i] = 0;
        else
            number_k[i] = 24;
        number_k[i] += amplitude(stock_k[i]);
        number_k[i] += head_foot(stock_k[i]);
    }
}

int amplitude(double stock_k[4])
{
    double amp = (stock_k[2] - stock_k[3]) / stock_k[0];
    if (amp <= 0.01)
        return 18;
    else if (0.1 < amp <= 0.03)
        return 0;
    else if (0.3 < amp <= 0.07)
        return 6;
    else if (0.07 < amp)
        return 12;
    return 0;
}

int head_foot(double stock_k[4])
{
    double head = stock_k[2] - stock_k[0];
    double foot = stock_k[1] - stock_k[3];

    if (head == 0 && foot == 0)
        return 1;
    else if (head == 0 && foot >= 0)
        return 2;
    else if (head >= 0 && foot == 0)
        return 3;
    else
    {
        double h_f_cut = head - foot;
        double h_f_percentage = (head > foot ? head / foot : foot / head);
        if (h_f_percentage <= 1.25)
            return 4;
        else if (h_f_cut < 0)
            return 5;
        else if (h_f_cut > 0)
            return 6;
        return 0;
    }
}

/*
   |
   |
   |
   |
   |
   |
   |
   |
   |
   |
______
|    |
|    |
|    |
------
   |
   |
   |
   |
   |
   |
   |
   |

2/1=2

6/5=1.2
5/4=1.25

*/
