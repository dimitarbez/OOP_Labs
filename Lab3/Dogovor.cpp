#include <iostream>
#include <cstring>

using namespace std;

class Potpisuvac
{
public:
    Potpisuvac()
    {
    }
    Potpisuvac(char* ime, char* prezime, char* embg)
    {
        strcpy(this->ime, ime);
        strcpy(this->prezime, prezime);
        strcpy(this->embg, embg);
    }
    Potpisuvac(const Potpisuvac& src)
    {
        strcpy(this->ime, src.ime);
        strcpy(this->prezime, src.prezime);
        strcpy(this->embg, src.embg);
    }
    char* GetEmbg() { return embg; }
private:
    char ime[20];
    char prezime[20];
    char embg[14];
};


class Dogovor
{
public:
    Dogovor(int brojNaDogovor, char* kategorijaDogovor, Potpisuvac* potpisuvaci)
        :brojNaDogovor(brojNaDogovor)
    {
        strncpy(this->kategorijaDogovor, kategorijaDogovor, 50);
        for (size_t i = 0; i < 3; i++)
        {
            this->potpisuvaci[i] = potpisuvaci[i];
        }
    }
    bool proverka()
    {
        int counter = 0;
        for (size_t i = 0; i < 3; i++)
        {
            for (size_t j = 0; j < 3; j++)
            {
                if ((strcmp(potpisuvaci[i].GetEmbg(), potpisuvaci[j].GetEmbg()) == 0)&&(i != j))
                {
                    //cout << "|" << potpisuvaci[i].GetEmbg() << "|" << potpisuvaci[j].GetEmbg() << "|";
                    return true;
                }
            }
        }
        return false;
    }
private:
    int brojNaDogovor;
    char kategorijaDogovor[50];
    Potpisuvac potpisuvaci[3];
};


//ne smee da se menuva main funkcijata
int main()
{
    char embg[13], ime[20], prezime[20], kategorija[20];
    int broj, n;
    cin >> n;
    for(int i = 0; i < n; i++){
    	cin >> embg >> ime >> prezime;
    	Potpisuvac p1(ime, prezime, embg);
    	cin >> embg >> ime >> prezime;
    	Potpisuvac p2(ime, prezime, embg);
    	cin >> embg >> ime >> prezime;
    	Potpisuvac p3(ime, prezime, embg);
    	cin >> broj >> kategorija;
    	Potpisuvac p[3];
    	p[0] = p1; p[1] = p2; p[2] = p3;
    	Dogovor d(broj, kategorija, p);
        cout << "Dogovor " << broj << ":" << endl; 
    	if(d.proverka() == true)
    	    cout << "Postojat potpishuvaci so ist EMBG" << endl;
    	else
    	    cout << "Ne postojat potpishuvaci so ist EMBG" << endl;
    }
    return 0;
}