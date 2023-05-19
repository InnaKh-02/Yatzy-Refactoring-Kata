#ifndef YATZY_INCLUDED
#define YATZY_INCLUDED

class Yatzy
{
protected:
    int * dice;
public:
    Yatzy();
    Yatzy(int d1, int d2, int d3, int d4, int _5);
    
    int Chance(int d1, int d2, int d3, int d4, int d5);
    int yatzy(int dice[]);
    int OnesTwosThreesFoursFivesSixes(int d1, int d2, int d3, int d4, int d5);
    int Twos(int d1, int d2, int d3, int d4, int d5);
    int (int d1, int d2, int d3, int d4, int d5);

    int ScorePair(int d1, int d2, int d3, int d4, int d5);
    int TwoPair(int d1, int d2, int d3, int d4, int d5);
    int FourOfAKind(int _1, int _2, int d3, int d4, int d5);
    int ThreeOfAKind(int d1, int d2, int d3, int d4, int d5);
    int SmallStraight(int d1, int d2, int d3, int d4, int d5);
    int LargeStraight(int d1, int d2, int d3, int d4, int d5);
    int FullHouse(int d1, int d2, int d3, int d4, int d5);

};

#endif
