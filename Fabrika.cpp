#include <iostream>
#include <cstring>

using namespace std;

class Rabotnik
{
private:
    char ime[30];
    char prezime[30];
    int plata;

public:
    Rabotnik() {}
    Rabotnik(char *ime, char *prezime, int plata)
        : plata(plata)
    {
        strncpy(this->ime, ime, 30);
        strncpy(this->prezime, prezime, 30);
    }
    ~Rabotnik() {}

    int getPlata() { return plata; }

    void pecati()
    {
        cout << ime << " " << prezime << " " << plata << endl;
    }
};

class Fabrika
{
private:
    Rabotnik rabotnik[100];
    int brojVraboteni;

public:
    Fabrika(Rabotnik *rab, int brojVraboteni) : brojVraboteni(brojVraboteni)
    {
        for (size_t i = 0; i < 100; i++)
        {
            rabotnik[i] = rab[i];
        }
    }
    ~Fabrika() {}
    void pecatiVraboteni()
    {
        for (size_t i = 0; i < brojVraboteni; i++)
        {
            rabotnik[i].pecati();
        }
    }
    void pecatiSoPlata(int plata)
    {
        for (size_t i = 0; i < brojVraboteni; i++)
        {
            if (rabotnik[i].getPlata() >= plata)
            {
                rabotnik[i].pecati();
            }
        }
    }
};

int main()
{
    int n, minimalna;
    cin >> n;

    Rabotnik *rabotnik = new Rabotnik[n];

    for (size_t i = 0; i < n; i++)
    {
        char ime[30], prezime[30];
        int plata;
        cin >> ime >> prezime >> plata;
        rabotnik[i] = Rabotnik(ime, prezime, plata);
    }

    Fabrika fab(rabotnik, n);

    cin >> minimalna;
    cout << "Site vraboteni:" << endl;
    fab.pecatiVraboteni();
    cout << "Vraboteni so plata povisoka od " << minimalna << " :" << endl;
    fab.pecatiSoPlata(minimalna);

    delete[] rabotnik;
}