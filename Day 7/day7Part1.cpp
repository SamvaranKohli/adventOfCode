#include<iostream>
#include<fstream>
#include<unordered_map>
#include<string>
#include<set>

using namespace std;

// store all kinds of cards
vector<pair<string, int>> fiveOfKind;
vector<pair<string, int>> fourOfKind;
vector<pair<string, int>> fullHouse;
vector<pair<string, int>> threeOfKind;
vector<pair<string, int>> twoPair;
vector<pair<string, int>> onePair;
vector<pair<string, int>> highCard;

// strength of each card
vector<char> strength = {'2', '3', '4', '5', '6', '7', '8', '9', 'T', 'J', 'Q', 'K', 'A'};


// calculate the type of hand
void typeOfHand(string hand, int bid)
{
    // store the occurance of each char in a map
    unordered_map<char, int> mp;

    for(int i = 0; i < hand.length(); i++)
    {
        if(mp.find(hand[i]) != mp.end())
        {
            mp[hand[i]]++;
        }
        else
            mp[hand[i]] = 1;
    }

    // loop through and count the size of the map
    // to know number of occurances of each group of char
    // then calculate its type
    if(mp.size() == 1)
        fiveOfKind.push_back({hand, bid});
    else if(mp.size() == 2)
    {
        for(auto it : mp)
        {
            if(it.second == 4 || it.second == 1)
            {
                fourOfKind.push_back({hand, bid});
                break;
            }
            else if(it.second == 3 || it.second == 2)
            {
                fullHouse.push_back({hand, bid});
                break;
            }   
                
        }
    }
    else if(mp.size() == 3)
    {
        bool three = false;

        for(auto it : mp)
        {
            if(it.second == 3 )
            {
                three = true;
                break;
            }
        }

        if(three)
            threeOfKind.push_back({hand, bid});
        else
            twoPair.push_back({hand, bid});
    }
    else if(mp.size() == 4)
        onePair.push_back({hand, bid});
    else if(mp.size() == 5)
        highCard.push_back({hand, bid});
}

// comparator to sort the cards of the same type
int currStrength(char a, char b)
{
    // get the index of both the char in the strength vector
    auto itA = find(strength.begin(), strength.end(), a);
    auto itB = find(strength.begin(), strength.end(), b);

    // the order is fine
    if(itA > itB)
        return 1;

    // swap
    if(itA < itB)
        return 0;

    // both chars are same
    return 2;
}

// sort the cards in each type
void sortCards(vector<pair<string, int>> &cards)
{
    // bubble sort to sort the vector
    int n = cards.size();

    for(int i = 0; i < n-1; i++)
    {
        for(int j = 0; j < n-1-i; j++)
        {
            // this loop this for each character
            for(int k = 0; k < 5; k++)
            {
                int value = currStrength(cards[j+1].first[k],cards[j].first[k]);

                // if value == 2
                // then they have the same char and move to the nex char to calculate the order

                if(value == 1)
                    break;
                
                if(value == 0)
                {
                    swap(cards[j], cards[j+1]);
                    break;
                }
            }
        }
    }  
}

int main()
{
    ifstream fin;
    string line;

    fin.open("day7Input.txt");

    // segregate into its types
    while (getline(fin, line))
    {
        string hand = "";
        string numS = "";

        int i = 0;
        int bid = 0;

        while(line[i] != ' ')
        {
            hand += line[i];
            i++;
        }

        i++;

        while(i < line.length())
        {
            numS += line[i];
            i++;
        }

        bid = stoi(numS);

        typeOfHand(hand, bid);

    }

    // sort each type
    sortCards(fiveOfKind);
    sortCards(fourOfKind);
    sortCards(fullHouse);
    sortCards(threeOfKind);
    sortCards(twoPair);
    sortCards(onePair);
    sortCards(highCard);

    // move them into one big vector
    vector<pair<string, int>> allCards = highCard;

    allCards.insert(allCards.end(), onePair.begin(), onePair.end());
    allCards.insert(allCards.end(), twoPair.begin(), twoPair.end());
    allCards.insert(allCards.end(), threeOfKind.begin(), threeOfKind.end());
    allCards.insert(allCards.end(), fullHouse.begin(), fullHouse.end());
    allCards.insert(allCards.end(), fourOfKind.begin(), fourOfKind.end());
    allCards.insert(allCards.end(), fiveOfKind.begin(), fiveOfKind.end());

    // calculate answer by * rank and its bid
    int ans = 0;

    for(int i = 0; i < allCards.size(); i++)
    {
        ans = ans + allCards[i].second*(i+1);
    }

    cout<<ans;

    return 0;
}