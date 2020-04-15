#include <iostream>
#include <cstring>

using namespace std;

//Vasiot kod tuka

class Pica
{
private:
    char ime[15];
    int cena;
    char* sostojki;
    int namaluvanje;
public:
    Pica(char* ime = "", int cena = 0, char* sostojki = "", int namaluvanje = 0) 
        :cena(cena), namaluvanje(namaluvanje)
    {
        strncpy(this->ime, ime, 15);

        this->sostojki = new char[strlen(sostojki) + 1];
        strcpy(this->sostojki, sostojki);
    }

    Pica(const Pica& src)
        :cena(src.cena), namaluvanje(src.namaluvanje)
    {
        strncpy(ime, src.ime, 15);

        sostojki = new char[strlen(src.sostojki) + 1];
        strcpy(sostojki, src.sostojki);
    }

    ~Pica() 
    {
        delete[] sostojki;
    }

    Pica& operator=(const Pica& src)
    {
        if(this == &src)
            return *this;

        cena = src.cena;
        namaluvanje = src.namaluvanje;
        strncpy(this->ime, src.ime, 15);

        delete[] sostojki;
        sostojki = new char[strlen(src.sostojki) + 1];
        strcpy(sostojki, src.sostojki);

        return *this;
    }

    void pecati()
    {
        cout << ime << " " << sostojki << ", " << cena << endl;
    }

    char* getIme() 
    {
        return ime;
    }

    int getCena()
    {
        return cena;
    }

    bool istiSe(Pica p)
    {
        return strcmp(this->sostojki, p.sostojki) == 0;
    }

    int GetNamaluvanje()
    {
        return namaluvanje;
    }
};

class Picerija
{
private:
    char ime[15];
    Pica* pici;
    int brojNaPici;
public:
    Picerija(char* ime = "") 
    {
        strncpy(this->ime, ime, 15);
    }

    Picerija(const Picerija& src)
        :brojNaPici(src.brojNaPici)
    {
        strncpy(this->ime, src.ime, 15);

        pici = new Pica[brojNaPici];

        for (size_t i = 0; i < brojNaPici; i++)
        {
            pici[i] = src.pici[i];
        }
        
    }

    ~Picerija()
    {
        delete[] pici;
    }

    Picerija& dodadi(Pica p)
    {
        bool isti = false;
        for (size_t i = 0; i < brojNaPici; i++)
        {
            if(p.istiSe(pici[i]))
            {
                isti = true;
            }
        }

        if(!isti)
        {
            Pica* temp = new Pica[brojNaPici + 1];

            for (size_t i = 0; i < brojNaPici; i++)
            {
                temp[i] = pici[i];
            }

            delete[] pici;

            temp[brojNaPici++] = p;

            pici = temp;            
        }
        
        return *this;
    }

    void piciNaPromocija()
    {
        for (size_t i = 0; i < brojNaPici; i++)
        {
            if(pici[i].GetNamaluvanje())
            {
                pici[i].pecati();
                cout << pici[i].getCena() - pici[i].getCena() * pici[i].GetNamaluvanje() / 100;
            }
        }
        
    }

    void setIme(char* ime)
    {
        strncpy(this->ime, ime, 15);
    }

    char* getIme()
    {
        return ime;
    }
};


int main () {

    int n;
    char ime[15];
    cin >> ime;
    cin >> n;

    Picerija p1(ime);
    for(int i = 0; i < n; i++){
        char imp[100];
        cin.get();
        cin.getline(imp,100);
        int cena;
        cin >> cena;
        char sostojki[100];
        cin.get();
        cin.getline(sostojki,100);
        int popust;
        cin >> popust;
        Pica p(imp,cena,sostojki,popust);
        p1.dodadi(p);
    }

    Picerija p2 = p1;
    cin >> ime;
    p2.setIme(ime);
    char imp[100];
    cin.get();
    cin.getline(imp,100);
    int cena;
    cin >> cena;
    char sostojki[100];
    cin.get();
    cin.getline(sostojki,100);
    int popust;
    cin >> popust;
    Pica p(imp,cena,sostojki,popust);
    p2.dodadi(p);

    cout<<p1.getIme()<<endl;
    cout<<"Pici na promocija:"<<endl;
    p1.piciNaPromocija();

    cout<<p2.getIme()<<endl;
    cout<<"Pici na promocija:"<<endl;
    p2.piciNaPromocija();

	return 0;
}
