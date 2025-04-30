#include <iostream>
#include <vector>
#include <queue>
#include <thread>
using namespace std;

vector<vector<short>> pierwszy(5);
vector<vector<short>> drugi(5);

void uzupelnianie_pierwszego()
{
    pierwszy[0].push_back(1);
    pierwszy[0].push_back(2);
    pierwszy[1].push_back(0);
    pierwszy[1].push_back(3);
    pierwszy[1].push_back(4);
    pierwszy[2].push_back(0);
    pierwszy[3].push_back(1);
    pierwszy[4].push_back(1);
}

void uzupelnianie_drugiego()
{
    drugi[0].push_back(1);
    drugi[0].push_back(2);
    drugi[1].push_back(0);
    drugi[2].push_back(3);
    drugi[2].push_back(0);
    drugi[3].push_back(2);
    drugi[3].push_back(4);
    drugi[4].push_back(3);
}

void przeszukiwanie(vector<vector<short>> graf, short poczatek)
{
    vector<bool> bylo;
    for(short i=0;i<graf.size();i++)
    {
        bylo.push_back(0);
    }
    queue<short> kol;
    kol.push(poczatek);
    bylo[poczatek]=1;
    cout << "Przeszukiwanie grafu od: " << poczatek << " przeszukiwane po kolei wierzcholki: ";
    while(!kol.empty())
    {
        cout << kol.front() << " ";
        vector<short> zawartosc = graf[kol.front()];
        kol.pop();
        for(short i=0;i<zawartosc.size();i++)
            if(bylo[zawartosc[i]]==0)
            {
                bylo[zawartosc[i]]=1;
                kol.push(zawartosc[i]);
            }
    }
    cout << "\n";
}
int main()
{
    uzupelnianie_pierwszego();
    uzupelnianie_drugiego();
    thread wczytywanie_pierwszego(przeszukiwanie, ref(pierwszy),0);
    thread wczytywanie_drugiego(przeszukiwanie, ref(drugi),0);
    wczytywanie_pierwszego.join();
    wczytywanie_drugiego.join();
}
