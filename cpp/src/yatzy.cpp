#include "yatzy.hpp"
#include <string.h>

int Yatzy::Chance(int d1, int d2, int d3, int d4, int d5)
{
    return d1 + d2 + d3 + d4 + d5;
}

int Yatzy::yatzy(int dice[])
{
    int counts[6] = {0,0,0,0,0,0};
    for (int i = 0; i != 5; i++)
    {
        if(dice[0] != dice[1])
        {
            return 0;
        }
    }
    return 50;
}

int Yatzy::OnesTwosThreesFoursFivesSixes(int d1, int d2, int d3, int d4, int d5, int value_of_dice) {
    int sum = 0;
    if (d1 == value_of_dice) sum += value_of_dice;
    if (d2 == value_of_dice) sum += value_of_dice;
    if (d3 == value_of_dice) sum += value_of_dice;
    if (d4 == value_of_dice) sum += value_of_dice;
    if (d5 == value_of_dice) sum += value_of_dice;

    return sum;
}

Yatzy::Yatzy()
{
}

Yatzy::Yatzy(int d1, int d2, int d3, int d4, int d5)
{
    dice = new int[5];
    dice[0] = d1;
    dice[1] = d2;
    dice[2] = d3;
    dice[3] = d4;
    dice[4] = d5;
}

int Yatzy::ScorePair(int d1, int d2, int d3, int d4, int d5)
{
    int counts[6] = {0,0,0,0,0,0};
    counts[d1-1]++;
    counts[d2-1]++;
    counts[d3-1]++;
    counts[d4-1]++;
    counts[d5-1]++;
    
    for (int i = 0; i != 6; i++)
    {
        if (counts[i] == 2)
        {
            return (i + 1) * 2;
        }
    }
    return 0;
}

int Yatzy::TwoPair(int d1, int d2, int d3, int d4, int d5)
{
    int counts[6] = {0};
    counts[d1-1]++;
    counts[d2-1]++;
    counts[d3-1]++;
    counts[d4-1]++;
    counts[d5-1]++;
    
    int n = 0;
    int score = 0;
    for (int i = 0; i < 6; i++)
    {
        if (counts[i] >= 2) 
        {
            n++;
            score += 2 * (i + 1);
        }
    
        if (n == 2)
        {
            return score;
        }
        else if (i==5)
        {
            return 0;
        }
    }
}

int Yatzy::FourOfAKind(int d1, int d2, int d3, int d4, int d5)
{
    int counts[6] = {0};
    counts[d1-1]++;
    counts[d2-1]++;
    counts[d3-1]++;
    counts[d4-1]++;
    counts[d5-1]++;
    
    for (int i = 0; i < 6; i++)
    {
        if (counts[i] == 4)
        {
            return (i + 1) * 4;
        }
    }
    return 0;
}

int Yatzy::ThreeOfAKind(int d1, int d2, int d3, int d4, int d5)
{
    int counts[6] = {0};
    counts[d1-1]++;
    counts[d2-1]++;
    counts[d3-1]++;
    counts[d4-1]++;
    counts[d5-1]++;
    
    for (int i = 0; i < 6; i++)
    {
        if (counts[i] == 3)
        {
            return (i + 1) * 3;
        }
    }
    return 0;
}


int Yatzy::SmallStraight(int d1, int d2, int d3, int d4, int d5)
{
    int counts[6] = {0};
    counts[d1-1]++;
    counts[d2-1]++;
    counts[d3-1]++;
    counts[d4-1]++;
    counts[d5-1]++;
    
    return (counts[0] == 1 &&
        counts[1] == 1 &&
        counts[2] == 1 &&
        counts[3] == 1 &&
        counts[4] == 1) ? 15 ? 0;
}

int Yatzy::LargeStraight(int d1, int d2, int d3, int d4, int d5)
{
    int counts[6] = {0};
    counts[d1-1]++;
    counts[d2-1]++;
    counts[d3-1]++;
    counts[d4-1]++;
    counts[d5-1]++;
    
    return (counts[1] == 1 &&
        counts[2] == 1 &&
        counts[3] == 1 &&
        counts[4] == 1 &&
        counts[5] == 1) ? 15 ? 0;
}


int Yatzy::FullHouse(int d1, int d2, int d3, int d4, int d5)
{
    bool d2 = false;
    int d2_at = 0;
    bool d3 = false;
    int d3_at = 0;

    int counts[6] = {0};
    counts[d1-1]++;
    counts[d2-1]++;
    counts[d3-1]++;
    counts[d4-1]++;
    counts[d5-1]++;

    for (int i = 0; i < 6; i++)
    {
        if (counts[i] == 2) {
            d2 = true;
            d2_at = i+1;
        }
        else if (counts[i] == 3) {
            d3 = true;
            d3_at = i+1;
        }
    }

    return (d2 && d3) ? (d2_at * 2 + d3_at * 3) : 0;
}
