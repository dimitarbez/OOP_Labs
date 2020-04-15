#include<iostream>
#include <cstring>

using namespace std;

// вашиот код

class Avtomobil
{
private:
    char boja[20];
    char brend[20];
    char model[20];

public:
    Avtomobil(char* boja, char* brend, char* model) 
    {
        strncpy(this->boja, boja, 20);
        strncpy(this->brend, brend, 20);
        strncpy(this->model, model, 20);

    }

    Avtomobil()
    {

    }

    Avtomobil& operator=(const Avtomobil& src)
    {
        strcpy(this->boja, src.boja);
        strcpy(this->brend, src.brend);
        strcpy(this->model, src.model);

        return *this;
    }

    ~Avtomobil() {}
};

class ParkingPlac
{
private:
    char adresa[20];
    char* id;
    int cenaZaChas;
    int zarabotka;
    int parkiraniVozila;
    Avtomobil* avtomobili;
public:
    ParkingPlac(char* adresa, char* id, int cenaZaChas)
        :cenaZaChas(cenaZaChas) 
    {
        strncpy(this->adresa,adresa,20);
        this->id = new char[strlen(id) + 1];
        strcpy(this->id, id);
    }

    ParkingPlac()
    {

    }

    ~ParkingPlac() 
    {
        delete[] id;
        delete[] avtomobili;
    }

    void platiCasovi(int casovi)
    {
        zarabotka += casovi * cenaZaChas;
    }

    bool daliIstaAdresa(const ParkingPlac& p)
    {
        return (strcmp(this->adresa, p.adresa) == 0);
    }

    void pecati()
    {
        cout << id << " - " << zarabotka << " denari";
    }

    ParkingPlac& parkirajVozilo(Avtomobil novoVozilo)
    {

        Avtomobil* temp = new Avtomobil[parkiraniVozila + 1];
        for (size_t i = 0; i < parkiraniVozila; i++)
        {   
            temp[i] = avtomobili[i];
        }
        temp[parkiraniVozila++] = novoVozilo;
        delete[] avtomobili;
        avtomobili = temp;
        
        return *this;
    }

    void pecatiParkiraniVozila()
    {
        cout << parkiraniVozila;        
    }

    char* getId()
    {
        char* temp = id;
        return temp;
    }
};



int main(){

	ParkingPlac p[100];
	int n,m;
	char adresa[50],id[50];
	int brojcasovi,cenacas;
	cin>>n;
	if(n > 0){


		for (int i=0;i<n;i++){
	        cin.get();
			cin.getline(adresa,50);
			cin>>id>>cenacas;
			
			ParkingPlac edna(adresa,id,cenacas);
	        
	        p[i]=edna;
		}
	    
		//plakjanje
		cin>>m;
		for (int i=0;i<m;i++){

			cin>>id>>brojcasovi;
	        
	        int findId=false;
	        for (int j=0;j<m;j++){
	            if (strcmp(p[j].getId(),id)==0){
	                p[j].platiCasovi(brojcasovi);
	                findId=true;
	            }
	        }
			if (!findId)
	        cout<<"Ne e platen parking. Greshen ID."<<endl;
		}

	    cout<<"========="<<endl;
	    ParkingPlac pCentar("Cvetan Dimov","C10",80);
		for (int i=0;i<n;i++)
	        if (p[i].daliIstaAdresa(pCentar))
	            p[i].pecati();
	} else {

		ParkingPlac najdobarPlac("Mars", "1337", 1);
	    int brVozila;
	    cin >> brVozila;
	    for(int i = 0; i < brVozila; ++i){

	    	char boja[20];
	    	char brend[20];
	    	char model[20];

	    	cin >> boja >> brend >> model;
	    	Avtomobil novAvtomobil(boja, brend, model);
	    	najdobarPlac.parkirajVozilo(novAvtomobil);
	    }
	    if(brVozila != 0)
	    najdobarPlac.pecatiParkiraniVozila();

	}  
}