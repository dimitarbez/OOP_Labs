#include <iostream>
#include <cstring>

using namespace std;

enum zanr
{
    akcija,
    komedija,
    drama
};

class Film
{
private:
    char* ime;
    int memorija;
    zanr genre;
public:
    Film(char* ime = "", int memorija = 0, zanr z = (zanr)0)
        :memorija(memorija), genre(z)
    {
        this->ime = new char[strlen(ime) + 1];
        strcpy(this->ime, ime);
    }

    Film(const Film& src)
        :memorija(src.memorija), genre(src.genre)
    {
        this->ime = new char[strlen(src.ime) + 1];
        strcpy(this->ime, src.ime);
    }

    ~Film() 
    {
        delete[] ime;
    }

    void pecati()
    {
        cout << memorija << "MB-\"" << ime << "\"" << endl;
    }
    zanr GetGenre()
    {
        return genre;
    }

    int GetMemory() const
    {
        return memorija;
    }

    Film& operator=(const Film& src)
    {
        if(this == &src)
            return *this;
        
        delete[] this->ime;

        this->genre = src.genre;
        this->memorija = src.memorija;

        ime = new char[strlen(src.ime) + 1];
        strcpy(this->ime, src.ime);
        
        return *this;
    }
};

class DVD
{
private:
    Film filmovi[5];
    int brojNaFilmovi;
    int memoryCapacity;
public:
    DVD(int memory = 0, Film* filmovi = NULL, int broj = 0) 
        :memoryCapacity(memory), brojNaFilmovi(broj)
    {
        for (size_t i = 0; i < broj; i++)
        {
            this->filmovi[i] = filmovi[i];
        }
        
    }

    ~DVD() 
    {
    }

    void dodadiFilm(const Film& f)
    {
        int total = 0;
        for (size_t i = 0; i < brojNaFilmovi; i++)
        {
            total += filmovi[i].GetMemory();
        }
        if(memoryCapacity - total >= f.GetMemory() && brojNaFilmovi < 5)
        {
            filmovi[brojNaFilmovi++] = f;
        }
    }

    void pecatiFilmoviDrugZanr(zanr z)
    {
        for (size_t i = 0; i < brojNaFilmovi; i++)
        {
            if(filmovi[i].GetGenre() != z)
            {
                filmovi[i].pecati();
            }
        }
        
    }

    float procentNaMemorijaOdZanr(zanr z)
    {
        int mbGenre = 0, mbAll = 0;

        for (size_t i = 0; i < brojNaFilmovi; i++)
        {
            if(filmovi[i].GetGenre() == z)
            {
                mbGenre += filmovi[i].GetMemory();
            }

            mbAll += filmovi[i].GetMemory();
            
        }

        return (float)mbGenre / mbAll * 100.0;        
    }

    Film& getFilm(int i)
    {
        return filmovi[i];
    }

    int getBroj()
    {
        return brojNaFilmovi;
    }
};

int main() {
    // se testira zadacata modularno
    int testCase;
    cin >> testCase;

    int n, memorija, kojzanr;
    char ime[50];

    if (testCase == 1) {
        cout << "===== Testiranje na klasata Film ======" << endl;
        cin >> ime;
        cin >> memorija;
        cin >> kojzanr; //se vnesuva 0 za AKCIJA,1 za KOMEDIJA i 2 za DRAMA
        Film f(ime, memorija, (zanr) kojzanr);
        f.pecati();
    } else if (testCase == 2) {
        cout << "===== Testiranje na klasata DVD ======" << endl;
        DVD omileno(50);
        cin >> n;
        for (int i = 0; i < n; i++) {
            cin >> ime;
            cin >> memorija;
            cin >> kojzanr; //se vnesuva 0 za AKCIJA,1 za KOMEDIJA i 2 za DRAMA
            Film f(ime, memorija, (zanr) kojzanr);
            omileno.dodadiFilm(f);
        }
        for (int i = 0; i < n; i++)
            (omileno.getFilm(i)).pecati();
    } else if (testCase == 3) {
        cout << "===== Testiranje na metodot dodadiFilm() od klasata DVD ======" << endl;
        DVD omileno(50);
        cin >> n;
        for (int i = 0; i < n; i++) {
            cin >> ime;
            cin >> memorija;
            cin >> kojzanr; //se vnesuva 0 za AKCIJA,1 za KOMEDIJA i 2 za DRAMA
            Film f(ime, memorija, (zanr) kojzanr);
            omileno.dodadiFilm(f);
        }
        for (int i = 0; i < omileno.getBroj(); i++)
            (omileno.getFilm(i)).pecati();
    } else if (testCase == 4) {
        cout << "===== Testiranje na metodot pecatiFilmoviDrugZanr() od klasata DVD ======" << endl;
        DVD omileno(50);
        cin >> n;
        for (int i = 0; i < n; i++) {
            cin >> ime;
            cin >> memorija;
            cin >> kojzanr; //se vnesuva 0 za AKCIJA,1 za KOMEDIJA i 2 za DRAMA
            Film f(ime, memorija, (zanr) kojzanr);
            omileno.dodadiFilm(f);
        }
        cin >> kojzanr;
        omileno.pecatiFilmoviDrugZanr((zanr) kojzanr);

    } else if (testCase == 5) {
        cout << "===== Testiranje na metodot pecatiFilmoviDrugZanr() od klasata DVD ======" << endl;
        DVD omileno(50);
        cin >> n;
        for (int i = 0; i < n; i++) {
            cin >> ime;
            cin >> memorija;
            cin >> kojzanr; //se vnesuva 0 za AKCIJA,1 za KOMEDIJA i 2 za DRAMA
            Film f(ime, memorija, (zanr) kojzanr);
            omileno.dodadiFilm(f);
        }
        cin >> kojzanr;
        omileno.pecatiFilmoviDrugZanr((zanr) kojzanr);

    } else if (testCase == 6){
		cout<<"===== Testiranje na metodot procentNaMemorijaOdZanr() od klasata DVD =====" <<endl;
		DVD omileno(40);
		cin >> n;
		for (int i = 0; i < n; i++) {
            cin >> ime;
            cin >> memorija;
            cin >> kojzanr; //se vnesuva 0 za AKCIJA,1 za KOMEDIJA i 2 za DRAMA
            Film f(ime, memorija, (zanr) kojzanr);
            omileno.dodadiFilm(f);
        }
        cin >> kojzanr;
        cout<<"Procent na filmovi od dadeniot zanr iznesuva: "<<omileno.procentNaMemorijaOdZanr((zanr) kojzanr)<<"%\n";
		
	}

    return 0;
}