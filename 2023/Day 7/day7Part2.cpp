#include<iostream>
#include<fstream>
#include<unordered_map>
#include<string>
#include<set>

using namespace std;

// same logic as part 1
// just change the type of card depending on the number of j cards

vector<pair<string, int>> fiveOfKind;
vector<pair<string, int>> fourOfKind;
vector<pair<string, int>> fullHouse;
vector<pair<string, int>> threeOfKind;
vector<pair<string, int>> twoPair;
vector<pair<string, int>> onePair;
vector<pair<string, int>> highCard;

vector<char> strength = {'J', '2', '3', '4', '5', '6', '7', '8', '9', 'T', 'Q', 'K', 'A'};

void printArray(vector<pair<string, int>> cards)
{
    for(int i = 0; i < cards.size(); i++)
    {
        cout<<cards[i].first<<" "<<cards[i].second<<"\n";
    }

    cout<<"\n\n";
}

void typeOfHand(string hand, int bid)
{
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

    int jCards = 0;

    if(mp.find('J') != mp.end())
        jCards = mp['J'];

    if(mp.size() == 1)
        fiveOfKind.push_back({hand, bid});
    else if(mp.size() == 2)
    {
        if(jCards != 0)
        {
            fiveOfKind.push_back({hand, bid});
            return;
        }

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

        if(three && jCards != 0)
        {
            fourOfKind.push_back({hand, bid});
            return;
        }

        if(jCards == 1)
        {
            fullHouse.push_back({hand, bid});
            return;
        }
        else if(jCards == 2)
        {
            fourOfKind.push_back({hand, bid});
            return;
        }

        if(three)
            threeOfKind.push_back({hand, bid});
        else
            twoPair.push_back({hand, bid});
    }
    else if(mp.size() == 4)
    {
        if(jCards != 0)
        {
            threeOfKind.push_back({hand, bid});
            return;
        }

        onePair.push_back({hand, bid});
    }
    else if(mp.size() == 5)
    {
        if(jCards != 0)
        {
            onePair.push_back({hand, bid});
            return;
        }

        highCard.push_back({hand, bid});
    }
}

int currStrength(char a, char b)
{
    auto itA = find(strength.begin(), strength.end(), a);
    auto itB = find(strength.begin(), strength.end(), b);

    if(itA > itB)
        return 1;

    if(itA < itB)
        return 0;

    return 2;
}

void sortCards(vector<pair<string, int>> &cards)
{
    int n = cards.size();

    for(int i = 0; i < n-1; i++)
    {
        for(int j = 0; j < n-1-i; j++)
        {
            for(int k = 0; k < 5; k++)
            {
                int value = currStrength(cards[j+1].first[k],cards[j].first[k]);

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

    sortCards(fiveOfKind);
    sortCards(fourOfKind);
    sortCards(fullHouse);
    sortCards(threeOfKind);
    sortCards(twoPair);
    sortCards(onePair);
    sortCards(highCard);

    vector<pair<string, int>> allCards = highCard;

    allCards.insert(allCards.end(), onePair.begin(), onePair.end());
    allCards.insert(allCards.end(), twoPair.begin(), twoPair.end());
    allCards.insert(allCards.end(), threeOfKind.begin(), threeOfKind.end());
    allCards.insert(allCards.end(), fullHouse.begin(), fullHouse.end());
    allCards.insert(allCards.end(), fourOfKind.begin(), fourOfKind.end());
    allCards.insert(allCards.end(), fiveOfKind.begin(), fiveOfKind.end());

    int ans = 0;

    for(int i = 0; i < allCards.size(); i++)
    {
        ans = ans + allCards[i].second*(i+1);
    }

    cout<<ans;

    return 0;
}