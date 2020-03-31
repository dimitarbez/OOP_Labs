//vasiot kod ovde
#include <iostream>
#include <cstring>

using namespace std;

class Masa
{
private:
    int length;
    int width;

public:
    Masa()
        : length(0), width(0)
    {
    }
    Masa(int width, int length)
        : length(length), width(width)
    {
    }
    ~Masa()
    {
    }
    void pecati()
    {
        cout << "Masa: " << width << " " << length << endl;
    }
};

class Soba
{
private:
    Masa masa;
    int width;
    int length;

public:
    Soba(int width, int length, Masa m)
        : width(width), length(length), masa(m)
    {
    }
    Soba()
    {
    }
    ~Soba()
    {
    }
    void pecati()
    {
        cout << "Soba: " << width << " " << length << " ";
        masa.pecati();
    }
};

class Kukja
{
private:
    char adresa[50];
    Soba soba;

public:
    Kukja(Soba soba, char *adresa)
        : soba(soba)
    {
        strncpy(this->adresa, adresa, 50);
    }
    Kukja()
    {
    }
    ~Kukja()
    {
    }

    void pecati()
    {
        cout << "Adresa: " << adresa << " ";
        soba.pecati();
    }
};

//ne smee da se menuva main funkcijata!
int main()
{
    int n;
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        int masaSirina, masaDolzina;
        cin >> masaSirina;
        cin >> masaDolzina;
        Masa m(masaSirina, masaDolzina);
        int sobaSirina, sobaDolzina;
        cin >> sobaSirina;
        cin >> sobaDolzina;
        Soba s(sobaSirina, sobaDolzina, m);
        char adresa[30];
        cin >> adresa;
        Kukja k(s, adresa);
        k.pecati();
    }

    return 0;
}