#include <iostream>
#include <cstring>
#include <string>
//for vector
#include <vector> //https://www.geeksforgeeks.org/vector-in-cpp-stl/

// for list
#include <list>     //https://www.geeksforgeeks.org/list-cpp-stl/
#include <iterator>
#include <map>
#include <set>
#include <fstream>
#include <typeinfo>
#include <dos.h>   //pentru parola
#include <conio.h>  //pentru parola

using namespace std;

class Angajat
{
    char* nume;
    string* prenume;
    int nrPrenume;
    char initialaTata;
    const int idAngajat;
    string functie; // asistent sau medic
    int* data_angajare;
    int nrData;   //trebuie sa stiu daca am data sau nu; nrData=0 sau 3
    bool experienta;    // are valoarea 0 daca e nu are si 1 daca are
    double salariu;
public:
    static int id;
    Angajat();   //constructor fara parametri
    Angajat(char* nume, string* prenume, int nrPrenume, char initialaTata, string functie, int* data_angajare, int nrData, bool experienta,double salariu);
                    //constructor cu toti parametri
    Angajat(char*nume); //constructor cu un parametru
    Angajat(const Angajat &S);    //copy constructor
    ~Angajat(); /*destructor*/
    void setNume(char* nume);       //setter
    char* getNume();                 //getter
    void setPrenume(string* prenume, int nrPrenume);   //setter
    string* getPrenume();                 //getter
    int getNrPrenume();    //getter
    void setFunctie(string functie);
    string getFunctie();
    void  setData_angajare(int* data_angajare, int nrData);
    int getNrData();
    int* getData_angajare();
    void setInitiala(char initialaTata);  //setter
    char getInitiala();                 //getter
    void setExperienta(bool experienta);
    bool getExperienta();
    const int getIdAngajat();
    void setSalariu(double salariu);
    double getSalariu();
    ///operatorul =
    Angajat& operator=(const Angajat &S);
    ///operatorul <<
    friend ostream &operator<<(ostream &f2, const Angajat &S);
    ///operatorul >>
    friend istream &operator>>(istream &f1, Angajat &S);
    //operatorul ==
    bool operator==(const Angajat &S);   //returneaza 0 sau 1
    //operatorul <=
    bool operator< (const Angajat &S);   //returneaza 0 sau 1
    ///functionalitate: daca angajatorul lucreaza de un an la cabinet inseamna ca a castigat
    ///experienta si ii cresc salariul cu 10%
    void modificare();
    const Angajat& operator++();  // pre-incremenatre
    const Angajat operator++(int); //post-incrementare
    ///operatorul +
    Angajat operator+(int x);
    friend Angajat operator+(int x, Angajat A);
    ///operatorul *
    Angajat operator*(int x);
    friend Angajat operator*(int x, Angajat A);
    ///operator de indexare (selectez ziua, luna sau anul in care s-a angajat)
    int operator[](int index);
    ///cast explicit pe salariu (il transform in int)
    explicit operator int();
};

//Pre-incremenatre
const Angajat& Angajat::operator++()
{
    this->salariu++;
    return *this;
}
//Post-incrementare
const Angajat Angajat::operator++(int)
{
    Angajat aux(*this);
    this->salariu++;

    return aux;

}

///functionalitate
///daca are mai mult de un an de experienta, se pune ca angajatul are experienta si ii cresc salariul cu 10%
void Angajat::modificare()
{
    if(this->experienta==0 && this->nrData!=0)
    {
        cout<<"Introduceti data curent (zi/luna/an):";
        int zi,luna,an;
        cin>>zi>>luna>>an;
        if(an-this->data_angajare[2]>1)
        {
            this->experienta=1;
            this->salariu=this->salariu+this->salariu/10;
        }
        else
                if(an-this->data_angajare[2]==1)
            {
                if(luna-this->data_angajare[1]>0)
                {
                    this->experienta=1;
                    this->salariu=this->salariu+this->salariu/10;
                }
                    else
                        if(luna-this->data_angajare[1]==0)
                            if(zi-this->data_angajare[0]>=0)
                        {
                            this->experienta=1;
                            this->salariu=this->salariu+this->salariu/10;
                            cout<<"\najunge\n";
                        }
            }
    }
}
int Angajat::id=100;

//SETTER SI GETTER PT NUME
void Angajat::setNume(char* nume)
{
    if(this->nume!=NULL)
            delete[] this->nume;
    this->nume=new char[strlen(nume)+1];
    strcpy(this->nume,nume);
}
char* Angajat::getNume()
{
    return this->nume;
}

//SETTER SI GETTER PT PRENUME, numarul de prenume
void Angajat::setPrenume(string* prenume, int nrPrenume)
{
    this->nrPrenume=nrPrenume;
    if(this->prenume!=NULL)
        delete[] this->prenume;
    this->prenume=new string[this->nrPrenume];
    for(int i=0;i<this->nrPrenume;i++)
        this->prenume[i]=prenume[i];
}
string* Angajat::getPrenume()
{
    return this->prenume;
}
int Angajat::getNrPrenume()
{
    return this->nrPrenume;
}

//SETTER SI GETTER PT FUNCTIE
void Angajat::setFunctie(string functie)
{
    this->functie=functie;
}
string Angajat::getFunctie()
{
    return this->functie;
}

//SETTER SI GETTER PT DATA DE ANGAJARE
void Angajat::setData_angajare(int* data_angajare, int nrData)
{
    this->nrData=nrData;
    if(this->data_angajare!=NULL)
        delete[] this->data_angajare;
    this->data_angajare=new int[nrData];
    for(int i=0;i<nrData;i++)
        this->data_angajare[i]=data_angajare[i];
}
int* Angajat::getData_angajare()
{
    return this->data_angajare;
}
int Angajat::getNrData()
{
    return this->nrData;
}

//SETTER SI GETTER PT exp in dom
void Angajat::setExperienta(bool experienta)
{
   this->experienta=experienta;
}
bool Angajat::getExperienta()
{
    return this->experienta;
}

//SETTER SI GETTER PT initiala tatalui
void Angajat::setInitiala(char initialaTata)
{
    this->initialaTata=initialaTata;

}
char Angajat::getInitiala()
{
    return this->initialaTata;
}

//GETTER PT CONST
const int Angajat::getIdAngajat()
{
    return this->idAngajat;
}

//SETTER SI GETTER PT SALARIU
void Angajat::setSalariu(double salariu)
{
    this->salariu=salariu;
}
double Angajat::getSalariu()
{
    return this->salariu;
}
//CONSTRUCTOR FARA PARAMETRI
Angajat::Angajat():idAngajat(id++)
{
    this->nume= new char[strlen("Anonim")+1];
    strcpy(this->nume,"Anonim");
    this->prenume=NULL;
    this->nrPrenume=0;
    this->initialaTata='n';
    this->functie="none";
    this->nrData=0;
    this->data_angajare=NULL;
    this->experienta=0;
    this->salariu=0;
}

 //constructor cu toti parametri
Angajat::Angajat(char* nume, string* prenume, int nrPrenume, char initialaTata, string functie, int* data_angajare, int nrData, bool experienta,double salariu):idAngajat(id++)
{
    this->nume=new char[strlen(nume)+1];
    strcpy(this->nume,nume);
    this->nrPrenume=nrPrenume;
    this->prenume=new string[nrPrenume];
    for(int i=0;i<this->nrPrenume;i++)
        this->prenume[i]=prenume[i];
    this->initialaTata=initialaTata;
    this->functie=functie;
    this->nrData=nrData;
    this->data_angajare=new int[this->nrData];
    for(int i=0;i<this->nrData;i++)
        this->data_angajare[i]=data_angajare[i];
    this->experienta=experienta;
    this->salariu=salariu;
}

//constructorul cu un parametru
Angajat::Angajat(char* nume):idAngajat(id++)
    {
    this->prenume=NULL;
    this->nrPrenume=0;
    this->initialaTata='a';
    this->functie="none";
    this->nrData=0;
    this->data_angajare=NULL;
    this->experienta=0;
    this->salariu=0;
    this->nume=new char[strlen(nume)+1];
    strcpy( this->nume, nume);
    }

//CC
Angajat::Angajat(const Angajat&S):idAngajat(S.idAngajat)
{
    this->nume=new char[strlen(S.nume)+1];
    strcpy(this->nume,S.nume);
    this->nrPrenume=S.nrPrenume;
    this->prenume=new string[S.nrPrenume];
    for(int i=0;i<this->nrPrenume;i++)
        this->prenume[i]=S.prenume[i];
    this->initialaTata=S.initialaTata;
    this->functie=S.functie;

    this->nrData=S.nrData;
    this->data_angajare=new int[this->nrData];
    for(int i=0;i<this->nrData;i++)
        this->data_angajare[i]=S.data_angajare[i];

    this->experienta=S.experienta;
    this->salariu=S.salariu;
}

//operator =
Angajat& Angajat::operator=(const Angajat&S)
{
    if(this!=&S)
    {
        if(this->nume!=NULL)
            delete[] this->nume;
        this->nume=new char[strlen(S.nume)+1];
        strcpy(this->nume,S.nume);

        this->nrPrenume=S.nrPrenume;

        if(this->prenume!=NULL)
            delete[] this->prenume;
        this->prenume=new string[S.nrPrenume];
        for(int i=0;i<this->nrPrenume;i++)
            this->prenume[i]=S.prenume[i];

        this->initialaTata=S.initialaTata;
        this->functie=S.functie;

        this->nrData=S.nrData;
        if(this->data_angajare!=NULL)
            delete[] this->data_angajare;
        this->data_angajare=new int[this->nrData];
        for(int i=0;i<this->nrData;i++)
            this->data_angajare[i]=S.data_angajare[i];

        this->experienta=S.experienta;
        this->salariu=S.salariu;
    }
    return *this;

}

//SUPRAINCARCAREA OPERATORULUI CIN SI COUT
//OPERATORUL >> / cin
istream &operator>>(istream &f1, Angajat &S)
{
    cout<<"Nume: ";
    char a[]={};
    f1>>a;
    S.setNume(a);
    cout<<"Numarul de prenume: ";
    f1>>S.nrPrenume;
    cout<<"Prenume: ";
    if(S.prenume!=NULL)
        delete[] S.prenume;
    S.prenume=new string[S.nrPrenume];
    for(int i=0;i<S.nrPrenume;i++)
        f1>>S.prenume[i];
    cout<<"Initiala tatalui: ";
    f1>>S.initialaTata;
    cout<<"Functie: ";
    f1>>S.functie;
    cout<<"Data angajarii: ";
    S.nrData=3;
    if(S.data_angajare!=NULL)
        delete[] S.data_angajare;
    S.data_angajare=new int[S.nrData];
    for(int i=0;i<S.nrData;i++)
        f1>>S.data_angajare[i];
    cout<<"Experienta in domeniu: ";
    f1>>S.experienta;
    cout<<"Salariu: ";
    f1>>S.salariu;
    return f1;
}

// OPERATORUL <<
ostream &operator<<(ostream &f2,const Angajat &S)
{
    f2<<"\nNume: "<<S.nume;
    f2<<"\nNumarul de prenume: "<<S.nrPrenume;
    f2<<"\nPrenume: ";
    for(int i=0;i<S.nrPrenume;i++)
        f2<<S.prenume[i]<<" ";
    f2<<"\nInitiala tatalui: "<<S.initialaTata;
    f2<<"\nCodul angajatului: "<<S.idAngajat;
    f2<<"\nFunctie: "<<S.functie;
    f2<<"\nData angajarii: ";
    for(int i=0;i<S.nrData;i++)
        f2<<S.data_angajare[i]<<" ";
    f2<<"\nExperienta in domeniu: "<<S.experienta;
    f2<<"\nSalariu: "<<S.salariu;
    return f2;

}

//OPERATORUL +  (obiect+int)
Angajat Angajat::operator+(int x)
{
    Angajat aux(*this);
    aux.salariu=aux.salariu+x;
    return aux;
}

//OPERATORUL + (int+obiect)
Angajat operator+(int x, Angajat A)
{
    A.salariu=A.salariu+x;
    return A;
}

//operatorul* (int*Angajat)
Angajat Angajat::operator*(int x)
{
    Angajat aux(*this);
    aux.salariu=aux.salariu*x;
    return aux;
}
Angajat operator*(int x, Angajat A)
{
    A.salariu=A.salariu*x;
    return A;
}
//OPERATORUL ==
bool Angajat::operator==(const Angajat &S)
{
    if(strcmp(this->nume,S.nume)!=0)
        return 0;

    if(this->nrPrenume!=S.nrPrenume)
        return 0;

    for(int i=0;i<nrPrenume;i++)
        if(this->prenume[i]!=S.prenume[i])
            return 0;
    return 1;
}
//OPERATORUL []
int Angajat::operator[](int index)
{
    if(index>=0 && index<this->nrData)
        return this->data_angajare[index];
    else
        cout<<"Index invalid!";
    return 0;
}

//OPERATORUL <
bool Angajat::operator< (const Angajat &S)
{
   // if(this->salariu>S.salariu)
    //    return 0;
    cout<<"\ninceput "<<this->nume <<" "<<S.nume;
    if(strcmp(this->nume, S.nume)<0)
        return 1;
    else
        {
            if(strcmp(this->nume, S.nume)>0)
                return 0;
            else
            {
                cout<<"\nacelasi nume";
                int a=0;

                while(a < this->nrPrenume && a < S.nrPrenume)
                {
                    cout<<"\n"<<this->prenume[a]<<" "<<S.prenume[a];
                    if(this->prenume[a]<=S.prenume[a])
                        a++;
                    else
                        return 0;
                    cout<<"\nacelasi prim prenume";
                }
                if(this->nrPrenume<=S.nrPrenume)
                        return 1;
                cout<<"\nare mai multe prenume primul";
                return 0;
            }
        }
    return 1;
}
//OPERATOR CAST EXPLICIT
Angajat::operator int()
{
    return (int)this->salariu;
}
//DESTRUCTOR
Angajat::~Angajat()
{
    if(this->nume!=NULL)
        delete[]this->nume;
    if(this->prenume!=NULL)
        delete[]this->prenume;
    if(this->data_angajare!=NULL)
        delete[]this->data_angajare;
}

///-------------------------------------------------------------------------------------------------------------------------


class AngajatSuperior:public Angajat{
    string sex;
    string* sporSarbatoare;
    float* spor;
    int numar;
public:
    AngajatSuperior();
    AngajatSuperior(char* nume, string* prenume, int nrPrenume, char initialaTata, string functie, int* data_angajare, int nrData, bool experienta,double salariu, string sex, string* sporSarbatoare, float* spor,int numar);
    AngajatSuperior(const AngajatSuperior &ext);
    AngajatSuperior& operator=(const AngajatSuperior& ang);
    ~AngajatSuperior();
    friend istream& operator>> (istream& in, AngajatSuperior &ang);
    friend ostream& operator<< (ostream& out, const AngajatSuperior& ang);
    void martie();
    void adaugaLaLista(string sarbatoare, float suma);
    void stergeLaLista(string sarbatoare);
    int getNumar();
    bool operator<(const AngajatSuperior&ang) const;
};
bool AngajatSuperior::operator<(const AngajatSuperior & ang) const
{
    return (Angajat&)(*this)<(Angajat&)(ang);
}
int AngajatSuperior::getNumar()
{
    return this->numar;
}

AngajatSuperior::AngajatSuperior():Angajat()
{
    sex="anonim";
    spor=NULL;
    numar=0;
    sporSarbatoare=NULL;
}
AngajatSuperior::AngajatSuperior(char* nume,string* prenume,int nrPrenume,char initialaTata,string functie,int* data_angajare,int nrData,bool experienta,double salariu,string sex,string* sporSarbatoare,float* spor,int numar):Angajat(nume,prenume,nrPrenume,initialaTata,functie,data_angajare,nrData,experienta,salariu)
{
    this->sex=sex;
    this->numar=numar;
    this->spor=new float[this->numar];
    this->sporSarbatoare=new string[this->numar];
    for(int i=0;i<this->numar;i++)
    {
        this->spor[i]=spor[i];
        this->sporSarbatoare[i]=sporSarbatoare[i];
    }
}
//CC
AngajatSuperior::AngajatSuperior(const AngajatSuperior &ext):Angajat(ext)
    {
        sex=ext.sex;
        this->sporSarbatoare=new string[ext.numar];
        this->spor=new float[ext.numar];
        this->numar=ext.numar;
        for(int i=0;i<ext.numar;i++)
        {
            this->spor[i]=ext.spor[i];
            this->sporSarbatoare[i]=ext.sporSarbatoare[i];
        }
    }
AngajatSuperior& AngajatSuperior::operator=(const AngajatSuperior& ang)
{
    if(this!=&ang)
    {
        Angajat::operator=(ang);
        sex=ang.sex;
        if(this->sporSarbatoare!=NULL)
            this->sporSarbatoare=new string[ang.numar];
        if(this->spor!=NULL)
            this->spor=new float[ang.numar];
        this->numar=ang.numar;
        for(int i=0;i<ang.numar;i++)
        {
            this->spor[i]=ang.spor[i];
            this->sporSarbatoare[i]=ang.sporSarbatoare[i];
        }
    }
    return *this;
}
AngajatSuperior::~AngajatSuperior()
{
    if(this->spor!=NULL)
        delete[] this->spor;
    if(this->sporSarbatoare!=NULL)
        delete[] this->sporSarbatoare;
}
void AngajatSuperior::martie()
{
    if(this->sex=="feminin")
    {
        int c=this->numar;
        string* lista=new string[c];
        float* bani= new float[c];
        for(int i=0;i<c;i++)
        {
            lista[i]=this->sporSarbatoare[i];
            bani[i]=this->spor[i];
        }
        this->numar+=2;
        this->sporSarbatoare=new string[this->numar];
        this->spor= new float[this->numar];
        for(int i=0;i<this->numar-2;i++)
        {
            this->sporSarbatoare[i]=lista[i];
            this->spor[i]=bani[i];
        }
        this->sporSarbatoare[this->numar-2]="1 martie";
        this->spor[this->numar-2]=35;
        this->sporSarbatoare[this->numar-1]="8 martie";
        this->spor[this->numar-1]=50;
    }
}
void AngajatSuperior::adaugaLaLista(string sarbatoare, float suma)
{
    int c=this->numar;
    string* lista=new string[c];
    float* bani= new float[c];
    for(int i=0;i<c;i++)
    {
        lista[i]=this->sporSarbatoare[i];
        bani[i]=this->spor[i];
    }
    this->numar+=1;
    this->sporSarbatoare=new string[this->numar];
    this->spor= new float[this->numar];
    for(int i=0;i<this->numar-1;i++)
    {
        this->sporSarbatoare[i]=lista[i];
        this->spor[i]=bani[i];
    }
    this->sporSarbatoare[this->numar-1]=sarbatoare;
    this->spor[this->numar-1]=suma;

}
void AngajatSuperior::stergeLaLista(string sarbatoare)
{
    int c=this->numar;
    string* lista=new string[c-1];
    float* bani= new float[c-1];
    int i;
    for(i=0;i<c && this->sporSarbatoare[i]!= sarbatoare;i++)
    {
        lista[i]=this->sporSarbatoare[i];
        bani[i]=this->spor[i];
    }
    for(int j=i+1;j<c;j++)
    {
        lista[i]=this->sporSarbatoare[j];
        bani[i]=this->spor[j];
        i++;
    }
    this->numar-=1;
    this->sporSarbatoare=new string[this->numar];
    this->spor= new float[this->numar];
    for(int i=0;i<this->numar;i++)
    {
        this->sporSarbatoare[i]=lista[i];
        this->spor[i]=bani[i];
    }
}

istream& operator>> (istream& in, AngajatSuperior &ang)
{
    in>>(Angajat&)ang;
    cout<<"Sex feminin/masculin: ";
    in>>ang.sex;

    return in;
}
ostream& operator<< (ostream& out, const AngajatSuperior &ang)
{
    out<<(Angajat&)ang;
    out<<"\nSex: "<<ang.sex;
    if(ang.numar==0)
        out<<"\nAngajatul nu primeste sporuri!";
    else
   {
        out<<"\nSarbatorile la care angajatul primeste bani cadou: ";
        for(int i=0;i<ang.numar;i++)
            out<<"\nDe "<<ang.sporSarbatoare[i]<<" primeste "<<ang.spor[i]<<" lei.";
   }
    return out;
}

////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////


//a 2 a clasa
class Animal
{
    const int idAnimal;
    string numeAnimal;
    char* tipAnimal;
    float varsta;  //ex: 1 an si 2 luni => 1.02  ; 2 ani si 11 luni =>2.11
    string* tratamente;
    int nrTratamente;   //nrTratamente=nrPreturi, asa ca am lasat doar nrTratamente
    float* preturi;
public:

    static int contorAnimal;
    Animal();
    Animal(string numeAnimal, char* tipAnimal, float varsta, int nrTratamente, string* tratamente, float* preturi);
    Animal(string numeAnimal, char*tipAnimal);
    Animal (const Animal& C); //copy constructor
    Animal& operator=(const Animal&C); //operator =
    friend istream& operator>>(istream& in,Animal&C); //operator >>
    friend ostream& operator<<(ostream& out,const Animal&C); //operator <<
    bool operator==(const Animal &C);  //operator ==
    ~Animal();
    const Animal& operator++();  // pre-incremenatre
    const Animal operator++(int); //post-incrementare

    void setTratamentePreturi(string* tratamente, float* preturi, int nrTratamente)
    {
        this->nrTratamente=nrTratamente;
        if(this->tratamente!=NULL)
            this->tratamente=new string[nrTratamente];
        if(this->preturi!=NULL)
            this->preturi=new float[nrTratamente];
        for(int i=0; i<nrTratamente;i++)
            {
                this->tratamente[i]=tratamente[i];
                this->preturi[i]=preturi[i];
            }
    }

    float* getPreturi();
    string* getTratamente();
    int getNrTratamente();
    char* getTipAnimal();
    string getNumeAnimal();
    bool operator>(const Animal&A); //operatorul >
    ///functionalitate
    float sumaPreturi();    //calculeaza suma dintre preturi fara a calcula bonusul
    ///operatorul -
    Animal operator-(int x);
    friend Animal operator-(int x, Animal A);
    ///operatorul /
    Animal operator/(int x);
    friend Animal operator/(int x, Animal A);
    ///operator de indexare (selectez pretul tratamentului de pe pozitia "index")
    float operator[](int index);
};
int Animal::contorAnimal=0;

float* Animal::getPreturi()
{
    return this->preturi;
}
//GETTER pt nume animal
string Animal::getNumeAnimal()
{
    return this->numeAnimal;
}
//GETTER pentru tip animal
char* Animal::getTipAnimal()
{
    return this->tipAnimal;
}
//GETTER pentru tratamente
string* Animal::getTratamente()
{
    return this->tratamente;
}
//GETTER pentru nr tratamente
int Animal::getNrTratamente()
{
    return this->nrTratamente;
}

//CONSTRUCTOR FARA PARAMETRII
Animal::Animal():idAnimal(contorAnimal++)
{
    this->numeAnimal="Animal Anonim";

    this->tipAnimal=new char[strlen("Specie anonima")+1];
    strcpy(this->tipAnimal, "Specie anonima");

    this->varsta=0;
    this->nrTratamente=0;
    this->tratamente=nullptr;
    this->preturi=NULL;

}

//CONSTRUCTOR CU TOTI PARAMETRII
Animal::Animal(string numeAnimal, char*tipAnimal, float varsta, int nrTratamente, string* tratamente, float*preturi):idAnimal(contorAnimal++)
{
    this->numeAnimal=numeAnimal;
    this->tipAnimal=new char[strlen(tipAnimal)+1];
    strcpy(this->tipAnimal, tipAnimal);

    this->varsta=varsta;
    this->nrTratamente=nrTratamente;

    this->tratamente=new string[this->nrTratamente];
    for(int i=0;i<this->nrTratamente;i++)
        this->tratamente[i]=tratamente[i];

    this->preturi=new float[this->nrTratamente];
    for(int i=0;i<this->nrTratamente;i++)
        this->preturi[i]=preturi[i];
}

//CONSTRUCTOR CU 2 PARAMETRII
Animal::Animal(string numeAnimal, char* tipAnimal):idAnimal(contorAnimal++)
{
    this->numeAnimal=numeAnimal;
    this->tipAnimal=new char[strlen(tipAnimal)+1];
    strcpy(this->tipAnimal, tipAnimal);


    this->nrTratamente=0;
    this->tratamente=nullptr;
    this->varsta=0;
    this->preturi=NULL;
}

//DESTRUCTOR
Animal::~Animal()
{
    if(this->tipAnimal!=NULL)
        delete[] this->tipAnimal;

    if(this->tratamente!=NULL)
        delete[] this->tratamente;

    if(this->preturi!=NULL)
        delete[] this->preturi;
}

//COPY CONSTRUCTOR
Animal::Animal(const Animal& C):idAnimal(C.idAnimal)
{
    this->numeAnimal=C.numeAnimal;
    this->tipAnimal=new char[strlen(C.tipAnimal)+1];
    strcpy(this->tipAnimal, C.tipAnimal);

    this->varsta=C.varsta;
    this->nrTratamente=C.nrTratamente;

    this->tratamente=new string[this->nrTratamente];
    for(int i=0;i<this->nrTratamente;i++)
        this->tratamente[i]=C.tratamente[i];

    this->preturi=new float[this->nrTratamente];
    for(int i=0;i<this->nrTratamente;i++)
        this->preturi[i]=C.preturi[i];
}

//OPERATORUL =
Animal& Animal ::operator= (const Animal&C)
{
    if(this!=&C)
    {
        this->numeAnimal=C.numeAnimal;

        if(this->tipAnimal!=NULL)
            delete[] this->tipAnimal;
        this->tipAnimal=new char[strlen(C.tipAnimal)+1];
        strcpy(this->tipAnimal, C.tipAnimal);

        this->varsta=C.varsta;
        this->nrTratamente=C.nrTratamente;

        if(this->tratamente!=NULL)
            delete[] this->tratamente;
        this->tratamente=new string[this->nrTratamente];
        for(int i=0;i<this->nrTratamente;i++)
            this->tratamente[i]=C.tratamente[i];

        if(this->preturi!=NULL)
            delete[] this->preturi;
        this->preturi=new float[this->nrTratamente];
        for(int i=0;i<this->nrTratamente;i++)
            this->preturi[i]=C.preturi[i];
    }
    return *this;
}
// OPERATORUL >>
istream& operator>>(istream& in, Animal&A)
{
    cout<<"\nIntroduceti numele animalului: ";
    in>>A.numeAnimal;
    cout<<"\nVa rog alegeti tipul animalului din urmatoarele variante: caine, pisica, iepure, hamster, papagal.  ";
    char sp[]={};
    in>>sp;
    if(A.tipAnimal!=NULL)
        delete[] A.tipAnimal;
    A.tipAnimal=new char[strlen(sp)+1];
    strcpy(A.tipAnimal,sp);

    cout<<"\nIntroduceti varsta acestuia (forma introdusa an,luni; de exemplu, 1 an si 2 luni => 1.02  ; 2 ani si 11 luni =>2.11): ";
    in>>A.varsta;
    cout<<"\nIntroduceti numarul de tratamente de care a beneficiat: ";
    in>>A.nrTratamente;
    if(A.tratamente!=NULL)
        delete[] A.tratamente;
    A.tratamente=new string[A.nrTratamente];
    cout<<"\nIntroduceti tratamentele de cate a beneficiat: ";
    in.ignore();
    for(int i=0;i<A.nrTratamente;i++)
        {
            getline(in, A.tratamente[i]);
        }
    A.preturi=new float[A.nrTratamente];
    cout<<"\nIntroduceti preturile corespunzatoare: ";
    for(int i=0;i<A.nrTratamente;i++)
        in>>A.preturi[i];
    return in;
}
//OPERATORUL <<
ostream& operator<<(ostream& out,const Animal&A)
{
    out<<"\nAnimalului este un: "<<A.tipAnimal;
    out<<"\nNumele animalului: "<<A.numeAnimal;
    out<<"\nVarsta acestuia (de exemplu,  1.02 => 1 an si 2 luni ; 2.11 => 2 ani si 11 luni ): "<<A.varsta;
    out<<"\nNumarul de tratamente de care a beneficiat: "<<A.nrTratamente;
    out<<"\nTratamentele si preturile corespunzatoare:\n";
    for(int i=0;i<A.nrTratamente;i++)
        out<<A.tratamente[i]<<" "<<A.preturi[i]<<" lei\n";

    return out;
}
//OPERATOR ==
bool Animal :: operator== (const Animal &A)
{
    if(strcmp(this->tipAnimal, A.tipAnimal)!=0)
        return 0;
    if(this->numeAnimal!=A.numeAnimal)
        return 0;

    return 1;
}
//OPERATORUL >
bool Animal::operator>(const Animal&A)
{
    if(this->varsta<=A.varsta)  //ex: 1 an si 2 luni => 1.02  ; 2 ani si 11 luni =>2.11
        return 0;
    return 1;
}

//Pre-incremenatre

const Animal& Animal::operator++()
{
    this->varsta++;
    return *this;
}
//Post-incrementare
const Animal Animal::operator++(int)
{
    Animal aux(*this);
    this->varsta++;
    return aux;
}

 //calculeaza suma dintre preturi fara a calcula bonusul
float Animal::sumaPreturi()
{
    float s=0;
    for(int i=0;i<this->nrTratamente;i++)
        s=s+this->preturi[i];
    return s;
}
//operatorul -
Animal Animal::operator-(int x)
{
    Animal aux(*this);
    for(int i=0;i<aux.nrTratamente;i++)
        aux.preturi[i]=aux.preturi[i]-x;
    return aux;
}
Animal operator-(int x, Animal A)
{
    for(int i=0;i<A.nrTratamente;i++)
        A.preturi[i]=x-A.preturi[i];
    return A;
}
///operatorul /
Animal Animal::operator/(int x)
{
    Animal aux(*this);
    for(int i=0;i<aux.nrTratamente;i++)
        aux.preturi[i]=aux.preturi[i]/x;
    return aux;
}
Animal operator/(int x, Animal A)
{
    for(int i=0;i<A.nrTratamente;i++)
        A.preturi[i]=x/A.preturi[i];
    return A;
}
///operator de indexare (selectez pretul tratamentului de pe pozitia "index")
float Animal::operator[](int index)
{
    if(index>=0 && index<this->nrTratamente)
        return this->preturi[index];
    else
        cout<<"index invalid";
    return 0;
}
///////////////////////////////////////////////////////////////////////////////////////////////////////////////////




//clasa a 3 a
class Client
{
    string nume;
    string prenume;
    string cnp;
    const int idClient;
    bool fidelitate;     ///daca clientul a mai venit inainte cu acelasi animal, primeste reducere de 10%
    int* data;             ///cand s-a venit la cabinet  //format zi|luna|an
    int nrData;          ///trebuie sa stiu daca am data sau nu pt a ma putea plimba prin vectorul data, nrData=0 sau 3
    Animal A;          ///agregare
public:

    virtual float pretFinal(){
        return A.sumaPreturi()- fidelitate*A.sumaPreturi()/10;
    }

    static int contorClient;
    void setNume(string nume);
    string getNume();
    void setPrenume(string prenume);
    string getPrenume();
    void setCnp(string cnp);
    string getCnp();
    int getIdClient();
    void setData(int* data,int nrData);
    int* getData();
    int getNrData();
    void setFidelitate(bool fidelitate);
    bool getFidelitate();
    void setA(const Animal&A);
    Animal& getA();
    Client();
    Client(string nume, string prenume, string cnp, bool fidelitate, int* data, int nrData, Animal A);
    Client(string nume, Animal A); //constructor cu 2 parametri
    Client(const Client &C);    //copy constructor
    virtual ~Client(); //destructor
    Client& operator= (const Client& C);  //operator=
    friend istream& operator>>(istream& in, Client&C);
    friend ostream& operator<<(ostream& out, const Client&C);
    virtual istream& citire(istream&in);
    virtual ostream& afisare(ostream&out) const;
    int operator==(const Client&C);
    int operator<=(const Client&C);
    ///functionalitate
    friend void reducere(Client&B, Client&C);
    const Client& operator++();  // pre-incremenatre
    const Client operator++(int); //post-incrementare
    int operator[](int index);
};

//Pre-incremenatre
const Client& Client::operator++()
{
    if(this->data[1]==1 || this->data[1]==3 || this->data[1]==5 || this->data[1]==7 || this->data[1]==8 || this->data[1]==10 || this->data[1]==12)
    {
        if(this->data[0]<=30)
            this->data[0]++;
        else
        {
            this->data[0]=1;
            if(this->data[1]!=12)
                this->data[1]++;
            else
            {
                this->data[1]=1;
                this->data[2]++;
            }
        }
    }
    else
        if(this->data[1]!=2)
        {
        if(this->data[0]<=29)
            this->data[0]++;
        else
        {
            this->data[0]=1;
            this->data[1]++;
        }
        }
    else
    {
        if(this->data[0]<=27)
            this->data[0]++;
        else
        if(this->data[2]%400==0 || (this->data[2]%4==0&&this->data[2]%100!=0))
       ///an bisect
      {
        if(this->data[0]==28)
            this->data[0]++;
        else
       {
           this->data[0]=1;
           this->data[1]++;
       }
      }
       else
       {
           this->data[0]=1;
           this->data[1]++;
       }
    }
    return *this;
}
//Post-incrementare
const Client Client::operator++(int)
{
    Client aux(*this);

        if(this->data[1]==1 || this->data[1]==3 || this->data[1]==5 || this->data[1]==7 || this->data[1]==8 || this->data[1]==10 || this->data[1]==12)
    {
        if(this->data[0]<=30)
            this->data[0]++;
        else
        {
            this->data[0]=1;
            if(this->data[1]!=12)
                this->data[1]++;
            else
            {
                this->data[1]=1;
                this->data[2]++;
            }
        }
    }
    else
    if(this->data[1]!=2)
        {
        if(this->data[0]<=29)
            this->data[0]++;
        else
        {
            this->data[0]=1;
            this->data[1]++;
        }
        }
    else
    {
        if(this->data[0]<=27)
            this->data[0]++;
        else
        if(this->data[2]%400==0 || (this->data[2]%4==0&&this->data[2]%100!=0))
       ///an bisect
    {
        if(this->data[0]==28)
        this->data[0]++;
             else
       {
           this->data[0]=1;
           this->data[1]++;
       }
    }
       else
       {
           this->data[0]=1;
           this->data[1]++;
       }
    }
    return aux;
}


void reducere(Client&B, Client&C)    ///formula generala pret_final-fidelitate*(1/10)*pret_final
{
    if(B.cnp==C.cnp && B.A.getNumeAnimal()==C.A.getNumeAnimal())
        C.fidelitate=1;
}

int Client::contorClient=1000;
void Client::setNume(string nume)
{
    this->nume=nume;
}

string Client::getNume()
{
    return this->nume;
}
void Client::setPrenume(string prenume)
{
    this->prenume=prenume;
}
string Client::getPrenume()
{
    return this->prenume;
}
void Client::setCnp(string cnp)
{
    this->cnp=cnp;
}
string Client::getCnp()
{
    return this->cnp;
}
int Client::getIdClient()
{
    return this->idClient;
}

void Client::setData(int* data,int nrData)
{
    this->nrData=nrData;
    if(this->data!=NULL)
        delete[] this->data;
    this->data=new int[nrData];
    for(int i=0;i<nrData;i++)
        this->data[i]=data[i];
}
int* Client::getData()
{
    return this->data;
}
int Client::getNrData()
{
    return this->nrData;
}
void Client::setFidelitate(bool fidelitate)
{
    this->fidelitate=fidelitate;
}
bool Client::getFidelitate()
{
    return this->fidelitate;
}

void Client::setA(const Animal& A)
{
    this->A=A;
}
Animal& Client::getA()
{
    return this->A;
}

//Constructor fara parametri
Client::Client():idClient(contorClient++)
{
    this->nume="Nume Anomin";
    this->prenume="Prenume Anomin";
    this->cnp="Nu se stie";
    this->fidelitate=0;
    this->data=NULL;
    this->nrData=0;
    this->A=A;
}

//CONSTRUCTORI CU TOTI PARAMETRI
Client::Client(string nume, string prenume, string cnp, bool fidelitate, int* data,int nrData, Animal A):idClient(contorClient++)
{
    this->nume=nume;
    this->prenume=prenume;
    this->cnp=cnp;
    this->fidelitate=fidelitate;
    this->nrData=nrData;
    this->data=new int[nrData];
    for(int i=0;i<nrData;i++)
        this->data[i]=data[i];
    this->A=A;
}

//Constructor cu 2 parametri
Client::Client(string nume, Animal A):idClient(contorClient++)
{
    this->nume=nume;
    this->A=A;
    this->prenume="Prenume Anomin";
    this->cnp="Nu se stie";
    this->fidelitate=0;
    this->nrData=0;
    this->data=NULL;
}
//CC
Client::Client(const Client &C):idClient(C.idClient)
{
    this->nume=C.nume;
    this->prenume=C.prenume;
    this->cnp=C.cnp;
    this->fidelitate=C.fidelitate;
    this->nrData=C.nrData;
    this->data=new int[this->nrData];
    for(int i=0;i<this->nrData;i++)
        this->data[i]=C.data[i];
    this->A=C.A;
}
//DESTRUCTOR
Client::~Client()
{
    if(this->data!=NULL)
        delete[] this->data;
}
//OPERATORUL=
Client& Client::operator= (const Client & C)
{
    if(this!=&C)
    {
        this->nume=C.nume;
        this->prenume=C.prenume;
        this->cnp=C.cnp;
        this->fidelitate=C.fidelitate;
        this->nrData=C.nrData;

        if(this->data!=NULL)
            delete[] this->data;
        this->data=new int[this->nrData];
        for(int i=0;i<this->nrData;i++)
            this->data[i]=C.data[i];

        this->A=C.A;
    }
    return *this;
}

//operator ==
int Client::operator==(const Client&C)
{
    if(this->cnp!=C.cnp)
        return 0;
    return 1;
}

//operator <
int Client::operator<=(const Client&C)
{
    cout<<"\nintra in op <=\n";
    if(this->nrData==3 && C.nrData==3)
     {
        if(this->data[2]<C.data[2])
            return 1;
        else
            if(this->data[2]==C.data[2])
             {
                if(this->data[1]<C.data[1])
                    return 1;
                else
                    if(this->data[1]==C.data[1])
                        if(this->data[0]<=C.data[0])
                            return 1;
            }
     }
    return 0;
}
istream& Client::citire(istream&in)
{
    cout<<"\nIntroduceti numele clientului: ";
    in>>this->nume;
    cout<<"\nIntroduceti prenumele clientului: ";
    in>>this->prenume;
    cout<<"\nIntroduceti CNP-ul clientului (fara spatii intre cifre): ";

    try
    {
        in>>this->cnp;

        if(this->cnp.size()!=13)
            throw 0;

    }
    catch(...)
    {
        cout<<"CNP ul trebuie sa aiba 13 cifre\nIntroduceti-l din nou\n";
        in>>this->cnp;

    }

    cout<<"\nIntroduceti data de azi (data la care a venit la cabinet): ";
    if(this->data!=NULL)
        delete[] this->data;
    this->nrData=3;
    this->data=new int[this->nrData];
    for(int i=0;i<this->nrData;i++)
        in>>this->data[i];
    cout<<"Date despre animalul clientului"<<endl;
    in>>this->A;
   // cout<<"\nA mai venit la cabinet cu animalul acela? ";
   // in>>this->fidelitate;
    this->fidelitate=0;

    return in;
}
//OP >>
istream& operator>>(istream& in, Client&C)
{
    return C.citire(in);
}

ostream& Client::afisare(ostream&out) const
{
    out<<"\nID ul clientului: "<<this->idClient;
    out<<"\nNumele clientului: "<<this->nume;
    out<<"\nPrenumele: "<<this->prenume;
    out<<"\nCNP: "<<this->cnp;
    out<<"\nData la care s-a preventat la cabinet: ";
    for(int i=0;i<this->nrData;i++)
        out<<this->data[i]<<" ";
    out<<"\nCard de fidelitate: ";
    if(this->fidelitate==1)
        out<<"da";
    else
        out<<"nu";
    out<<"\n\nDate despre animal!";
    out<<this->A;

    return out;
}
//OP <<
ostream& operator<<(ostream& out, const Client&C)
{
    return C.afisare(out);
}

int Client::operator[](int index)
{
    if(index>=0 &&index<this->nrData)
        return this->data[index];
    else
        cout<<"Index invalid!";
    return -1;
}

/*******************************************************************************************************************************/

class ClientInDomeniu: public Client
{
    string firma;
public:
    ClientInDomeniu();
    ClientInDomeniu(string nume, string prenume, string cnp, bool fidelitate, int* data, int nrData, Animal A, string firma);
    ~ClientInDomeniu();
    ClientInDomeniu(const ClientInDomeniu &client);
    ClientInDomeniu& operator=(const ClientInDomeniu& client);
    ///friend istream& operator>>(istream&in, ClientInDomeniu& client);
    ///friend ostream& operator<<(ostream&out, const ClientInDomeniu& client);
    virtual istream& citire(istream& in);
    virtual ostream& afisare(ostream&out) const;
    void detartaj();
    //este vorba de un client care este angajat in acest cabinet si/sau la alte caninete
    //el este tratat diferit, avand la dispozitie reduceri de 15% la orice tratament, reducere care nu anuleaza alte reduceri de care dispune
    float pretFinal();
};
ClientInDomeniu::ClientInDomeniu():Client()
{
    firma="Anonima";
}
ClientInDomeniu::ClientInDomeniu(string nume, string prenume, string cnp, bool fidelitate, int* data, int nrData, Animal A, string firma):Client(nume, prenume, cnp, fidelitate, data, nrData, A)
{
    this->firma=firma;
}
ClientInDomeniu :: ~ClientInDomeniu() {}
ClientInDomeniu::ClientInDomeniu(const ClientInDomeniu &client):Client(client)
{
    this->firma=client.firma;
}
ClientInDomeniu& ClientInDomeniu :: operator=(const ClientInDomeniu& client)
{
    if(&client != this)
    {
        Client::operator=(client);
        this->firma=client.firma;
    }
    return *this;
}
istream& ClientInDomeniu :: citire(istream&in)
{
    cout<<"\nLa ce firma(cabinet) lucrati? ";
    in.ignore();
    getline(in, this->firma);

    Client::citire(in);
    return in;
}
ostream& ClientInDomeniu :: afisare (ostream&out) const
{
    out<<"\nLucreaza la firma(cabinet) "<<this->firma;

    Client::afisare(out);
    return out;
}

void ClientInDomeniu :: detartaj()
{
    if(strcmp(getA().getTipAnimal(), "pisica")==0 || strcmp(getA().getTipAnimal(), "caine")==0)
    {
        cout<<endl<<getA().getNumeAnimal()<<" primeste detartaj gratis!";

        int nr = getA().getNrTratamente();
        string *listaTratamente1=new string[nr];
        float *listaPreturi1=new float[nr];
        for(int i=0;i<nr;i++)
        {
            listaTratamente1[i]=getA().getTratamente()[i];
            listaPreturi1[i]=getA().getPreturi()[i];
        }
        nr++;

        string *listaTratamente2=new string[nr];
        float *listaPreturi2=new float[nr];
        for(int i=0;i<nr-1;i++)
        {
            listaTratamente2[i]=listaTratamente1[i];
            listaPreturi2[i]=listaPreturi1[i];
        }
        listaTratamente2[nr-1]="detartaj";
        listaPreturi2[nr-1]=0;
        Client::getA().setTratamentePreturi(listaTratamente2,listaPreturi2,nr);
    }
}
///este vorba de un client care este angajat in acest cabinet si/sau la alte cabinete
///el este tratat diferit, avand la dispozitie reduceri de 15% la orice tratament, reducere care nu anuleaza alte reduceri de care dispune
float ClientInDomeniu :: pretFinal()
{
    float inainte=0;
    inainte = Client::pretFinal();
    return inainte-inainte*15/100;
}
////////////////////////////////////////////////////
//a 4 a clasa
class Cabinet
{
    string denumire;
    int an_infiintare;
    string* animale;
    int numar;
    float* program;  ///progrramul va fi dat printr-un vector, pe pozitiile pare sunt orele de inceput de program, pe pozitiile impare orele de final,
                    ///programul de pe o zi ocupa 2 spatii
    int zile;    ///intotdeauna va avea una din cele 2 valori:
                ///0 daca nu avem program si 7 daca avem program

public:
    Cabinet();
    Cabinet(float* program);
    Cabinet(string denumire, int an_infiintare, string*animale, int numar, float* program,int zile);
    ~Cabinet();
    Cabinet(const Cabinet &S);
    Cabinet& operator=(const Cabinet&S);
    friend istream& operator>>(istream& in, Cabinet&S);
    friend ostream& operator<<(ostream& out, const Cabinet&S);

    const Cabinet& operator--();  // pre-incremenatre
    const Cabinet operator--(int); //post-incrementare
    int operator-(int an);
    friend int operator-(int an,const Cabinet&cab);
    float operator[](int index);
    bool operator>=(const Cabinet&C);
    bool operator==(const Cabinet&C);

    void setProgramZi(float p1, float p2, int z);
    Cabinet operator+(string numeA);
    friend Cabinet operator+(string numeA, Cabinet cab);

///functionalitate: omul introduce de la tastatura o ora si o zi, si metoda ii afiseaza 10 daca este in timpul programului,
///deci poate veni, altfel afiseaza prima zi din saptamana in care este program la ora aceea si in caz in care nu exista o astfel
///de zi, returneaza -1
    int verificare(int zi, float ora);

};
void Cabinet::setProgramZi(float p1, float p2, int z)
{
    if(this->zile==0)
    {
        this->zile=7;
        this->program=new float[this->zile*2];

    }
    this->program[2*z]=p1;
    this->program[2*z+1]=p2;
}
//Contructor fara parametrii
Cabinet::Cabinet()
{
    this->denumire="Anonima";
    this->an_infiintare=0;
    this->numar=0;
    this->animale=NULL;
    this->zile=0;
    this->program=NULL;
}

//constructor cu 2 parametri
Cabinet::Cabinet(float* program)
{
    this->zile=7;
    this->program=new float[14];
    for(int i=0;i<14;i++)
        this->program[i]=program[i];
    this->denumire="Anonima";
    this->an_infiintare=0;
    this->numar=0;
    this->animale=NULL;

}

//constructor cu toti parametrii
Cabinet::Cabinet(string denumire, int an_infiintare, string*animale, int numar, float* program,int zile)
{
    this->denumire=denumire;
    this->an_infiintare=an_infiintare;
    this->numar=numar;
    this->animale=new string[this->numar];
    for(int i=0;i<this->numar;i++)
        this->animale[i]=animale[i];
    this->zile=zile;
    this->program=new float[zile*2];
    for(int i=0;i<zile*2;i++)
        this->program[i]=program[i];
}

//destructor
Cabinet::~Cabinet()
{
    if(this->program!=NULL)
    delete[] this->program;
    if(this->animale!=NULL)
        delete[] this->animale;

}

 //CC
Cabinet::Cabinet(const Cabinet &C)
{
    this->denumire=C.denumire;
    this->an_infiintare=C.an_infiintare;
    this->numar=C.numar;
    this->animale=new string[this->numar];
    for(int i=0;i<this->numar;i++)
        this->animale[i]=C.animale[i];
    this->zile=C.zile;
    this->program=new float[zile*2];
    for(int i=0;i<zile*2;i++)
        this->program[i]=C.program[i];
}

//OPERATORUL =
Cabinet& Cabinet::operator=(const Cabinet&C)
{
    if(this!=&C)
    {
        this->denumire=C.denumire;
        this->an_infiintare=C.an_infiintare;
        this->numar=C.numar;

        if(this->animale!=NULL)
            delete[] this->animale;
        this->animale=new string[this->numar];
        for(int i=0;i<this->numar;i++)
            this->animale[i]=C.animale[i];
        this->zile=C.zile;
        if(this->program!=NULL)
            delete[] this->program;
        this->program=new float[zile*2];
        for(int i=0;i<zile*2;i++)
            this->program[i]=C.program[i];
    }
    return *this;
}

//operatorul >>
istream& operator>>(istream& in, Cabinet&C)
{
    cout<<"\nDenumirea cabinetului veterinar: ";
    getline(in,C.denumire);
    cout<<"\nDin ce an functioneaza: ";
    in>>C.an_infiintare;
    cout<<"\nNumarul de animale ce pot fi tratate aici: ";
    in>>C.numar;
    cout<<"\nAnimale: ";
    if(C.animale!=NULL)
        delete[] C.animale;
    C.animale=new string[C.numar];
    for(int i=0;i<C.numar;i++)
        in>>C.animale[i];
    cout<<"\nProgram (introduceti numere de tip float Ora,Minute) daca intr-o zi nu se lucreaza se completeaza cu 2 de zero:un 0 pentru ora de inceput si celalalt pentru ora de terminare ";
    if(C.program!=NULL)
        delete[] C.program;
    C.zile=7;
    C.program=new float[C.zile*2];
    for(int i=0;i<C.zile*2;i++)
        in>>C.program[i];
    return in;
}
//operatorul <<
ostream& operator<<(ostream& out, const Cabinet&C)
{

    out<<"\nDenumirea cabinetului veterinar: "<<C.denumire;
    out<<"\nDin ce an functioneaza: "<<C.an_infiintare;
    out<<"\nNumarul de animale ce pot fi tratate aici: "<<C.numar;
    out<<"\nAnimale: ";
    for(int i=0;i<C.numar;i++)
        out<<C.animale[i]<<" ";
    out<<"\nProgram: ";
    for(int i=0;i<C.zile;i++)
        {
            out<<endl;
            if(i==0) out<<"Luni ";
            if(i==1) out<<"Marti ";
            if(i==2) out<<"Miercuri ";
            if(i==3) out<<"Joi ";
            if(i==4) out<<"Vineri ";
            if(i==5) out<<"Sambata ";
            if(i==6) out<<"Duminica ";
            if(C.program[2*i]==0 && C.program[2*i+1]==0)
                out<<"nu se lucreza";
            else
                out<<C.program[2*i]<<" - "<<C.program[2*i+1];
        }
    return out;
}

///Ora de inceput scade cu o ora
//Pre-incremenatre
const Cabinet& Cabinet::operator--()
{
    for(int i=0;i<this->zile;i++)
       {
           if(!(this->program[2*i]==0 && this->program[2*i+1]==0))
             {
                this->program[2*i]--;
                if(this->program[2*i]<0)
                    this->program[2*i]+=24;
             }
       }
    return *this;
}
//Post-incrementare
const Cabinet Cabinet::operator--(int)
{
    Cabinet aux(*this);
    for(int i=0;i<this->zile;i++)
       {
           if(!(this->program[2*i]==0 && this->program[2*i+1]==0))
        {
            this->program[2*i]--;
            if(this->program[2*i]<0)
                 this->program[2*i]+=24;
        }
       }
    return aux;
}
Cabinet Cabinet::operator+(string numeA)
{
    Cabinet aux(*this);
    string* lista=new string[this->numar];
    for(int i=0;i<this->numar;i++)
        lista[i]=this->animale[i];
    aux.numar++;
    delete[] aux.animale;
    aux.animale=new string[aux.numar];
    for(int i=0;i<aux.numar-1;i++)
        aux.animale[i]=lista[i];
    aux.animale[aux.numar-1]=numeA;
    return aux;
}
Cabinet operator+(string numeA, Cabinet cab)
{
    string* lista=new string[cab.numar];
    for(int i=0;i<cab.numar;i++)
        lista[i]=cab.animale[i];
    cab.numar++;
    delete[] cab.animale;
    cab.animale=new string[cab.numar];
    for(int i=0;i<cab.numar-1;i++)
        cab.animale[i]=lista[i];
    cab.animale[cab.numar-1]=numeA;
    return cab;
}
int Cabinet::operator-(int an)
{
    return this->an_infiintare-an;
}
int operator-(int an,const Cabinet&cab)
{
    return an-cab.an_infiintare;
}
float Cabinet::operator[](int index)
{
    if(index>=0 && index<14)
        return this->program[index];
    else
        cout<<"Index invalid!!";
    return -1;
}

bool Cabinet::operator>=(const Cabinet&C)
{
    if(this->numar>=C.numar)
        return 1;
    return 0;
}
bool Cabinet::operator==(const Cabinet&C)
{

    if(this->numar==C.numar)
        return 1;
    return 0;
}
///functionalitate: omul introduce de la tastatura o ora si o zi, si metoda ii afiseaza 10 daca este in timpul programului,
///deci poate veni, altfel afiseaza prima zi din saptamana in care este program la ora aceea si in caz in care nu exista o astfel
///de zi, returneaza -1, 100 daca a fost introdusa o zi invalida
int Cabinet::verificare(int zi, float ora)
{
    if(zi>=0 && zi<this->zile)
       {
        if(ora<=this->program[2*zi+1] && ora>=this->program[2*zi])
            return 10;
        else
        {
            for(int i=0;i<this->zile;i++)
                if(ora<=this->program[2*i+1] && ora>=this->program[2*i])
                    return i;
            return -1;
        }
       }
    else
        cout<<"Zi sau ora invalida\n";
    return 100;
}

///++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
///INTERFATA
class Interfata
{
public:
    virtual void categorie(){ cout<<"\nMagazin din incinta cabinetului veterinar!"; }
};
///CLASA ABSTRACTA
class Produs:public Interfata
{
    string denumire;
    float pret;
public:
    Produs();
    Produs(string denumire, float pret);
    virtual ~Produs();
    Produs(const Produs&prod);
    Produs& operator=(const Produs &prod);

    virtual ostream& afisare(ostream& out)const;
    virtual istream& citire(istream& in);
    friend istream& operator>>(istream &in, Produs &prod);
    friend ostream& operator<<(ostream&out, const Produs&prod);

    virtual float pretFinal()=0;      ///metoda virtuala pura

    void setDenumire(string denumire);
    string getDenumire();
    void setPret(float pret);
    float getPret();

};
Produs::Produs()
{
    this->denumire="Produs necunoscut";
    this->pret=0;
}
Produs::Produs(string denumire, float pret)
{
    this->denumire=denumire;
    this->pret=pret;
}

Produs::~Produs(){}

Produs::Produs(const Produs&prod)
{
    this->denumire=prod.denumire;
    this->pret=prod.pret;
}
Produs& Produs::operator=(const Produs &prod)
{
    if(this!=&prod)
    {
        this->denumire=prod.denumire;
        this->pret=prod.pret;
    }
    return *this;
}


istream& operator>>(istream &in, Produs &prod)
{
    return prod.citire(in);
}
ostream& operator<<(ostream&out, const Produs&prod)
{
    return prod.afisare(out);
}

ostream& Produs::afisare(ostream& out) const
{
        out<<"\nNume produs: "<<denumire;
        out<<"\nPret produs: "<<pret;
        return out;
}
istream& Produs::citire(istream& in)
{
        in.ignore();
        cout<<"\nNume produs: ";
        getline(in, denumire);
        cout<<"\nPret produs: ";
        in>>pret;
        return in;
}
void Produs::setDenumire(string denumire)
{
    this->denumire=denumire;
}
string Produs::getDenumire()
{
    return this->denumire;
}
void Produs::setPret(float pret)
{
    this->pret=pret;
}
float Produs::getPret()
{
    return this->pret;
}



///obiectele peste 200 de lei au garantie : garantia costa 5% din pret
class Obiect: public Produs
{
    string* culoare;
    int nrCulori;
    string tipAnimal;
    string taraProducere;
    float greutate;
    bool garantie;
public:
    Obiect();
    Obiect(string denumire, float pret, string* culoare, string tipAnimal, string taraProducere, float greutate, int nrCulori=1);
    ~Obiect();
    Obiect(const Obiect&obiect);
    Obiect& operator= (const Obiect&obiect);

    virtual istream& citire (istream& in);
    virtual ostream& afisare(ostream&out) const;

    void verifGarantie();     ///obiectele peste 200 de lei au garantie
    int getNrCulori();
    string getTipAnimal();
    string* getCuloare();
    float getGreutate();
    float getGarantie();
    string getTaraProducere();
    float pretGarantie();    /// garantia costa 5% din pret
    float pretFinal();
    void categorie();
};
Obiect::Obiect():Produs()
{
    culoare=nullptr;
    tipAnimal="none";
    taraProducere="none";
    greutate=0;
    garantie=0;
    nrCulori=0;
}
Obiect::Obiect(string denumire, float pret, string* culoare, string tipAnimal, string taraProducere, float greutate, int nrCulori):Produs(denumire, pret)
{
    this->nrCulori=nrCulori;
    this->culoare= new string[this->nrCulori];
    for(int i=0;i<this->nrCulori;i++)
        this->culoare[i]=culoare[i];
    this->tipAnimal=tipAnimal;
    this->taraProducere=taraProducere;
    this->greutate=greutate;
    this->garantie=0;
}

Obiect::~Obiect()
{
    if(this->culoare!=NULL)
        delete[] this->culoare;
}
Obiect::Obiect(const Obiect&obiect):Produs(obiect)
{
    this->culoare=new string[obiect.nrCulori];
    for(int i=0;i<obiect.nrCulori;i++)
        this->culoare[i]=obiect.culoare[i];
    this->nrCulori=obiect.nrCulori;
    this->tipAnimal=obiect.tipAnimal;
    this->taraProducere=obiect.taraProducere;
    this->greutate=obiect.greutate;
    this->garantie=obiect.garantie;
}
Obiect& Obiect:: operator= (const Obiect&obiect)
{
    if(this != &obiect)
    {
        Produs::operator=(obiect);
        if(this->culoare!=NULL)
            delete[] this->culoare;
        this->culoare=new string[obiect.nrCulori];
        for(int i=0;i<obiect.nrCulori;i++)
            this->culoare[i]=obiect.culoare[i];
        this->nrCulori=obiect.nrCulori;
        this->tipAnimal=obiect.tipAnimal;
        this->taraProducere=obiect.taraProducere;
        this->greutate=obiect.greutate;
        this->garantie=obiect.garantie;
    }
    return *this;
}

istream& Obiect::citire (istream& in)
{
    Produs::citire(in);
    cout<<"Pentru ce animal? ";
    in>>this->tipAnimal;
    cout<<"\nNumar culori :";
    in>>this->nrCulori;
    cout<<"\nCulori:\n";
    if(this->culoare!=NULL)
        delete[] this->culoare;
    this->culoare=new string[this->nrCulori];
    in.get();
    for(int i=0;i<this->nrCulori;i++)
        getline(in, this->culoare[i]);
    cout<<"\nFabricat in: ";
    in>>this->taraProducere;
    cout<<"\nGreutate (in grame): ";
    in>>this->greutate;

    ///nu pot sa pun aici daca are sau nu garantie, pentru ca pretul se poate modifica la un moment dat
    return in;
}
ostream& Obiect::afisare(ostream&out) const
{
    Produs::afisare(out);
    out<<"\nAnimal: "<<this->tipAnimal;

    out<<"\nCuloare/Culori:";
    for(int i=0;i<this->nrCulori;i++)
        out<<endl<<this->culoare[i];
    out<<"\nRealizat in: "<<this->taraProducere;
    out<<"\nGreutate produs: "<<this->greutate;
    if(this->garantie==1)
        out<<"\nProdusul are garantie";
    else
        out<<"\nProdusul nu are garantie";

    return out;
}
int Obiect::getNrCulori()
{
    return this->nrCulori;
}
string Obiect::getTipAnimal()
{
    return this->tipAnimal;
}
string* Obiect::getCuloare()
{
    return this->culoare;
}
float Obiect::getGreutate()
{
    return this->greutate;
}
float Obiect::getGarantie()
{
    return this->garantie;
}
string Obiect::getTaraProducere()
{
    return this->taraProducere;
}
void Obiect::verifGarantie()
{
    if(this->getPret()>=200)
        this->garantie=1;
}
float Obiect::pretGarantie()
{
    return this->garantie*getPret()/20;
}
float Obiect::pretFinal()
{
    return this->getPret()+ pretGarantie();
}
void Obiect::categorie()
{
    cout<<"\nCategoria obiect pentru animalul dvs.!";
}

///**********************************************************************************************

class Medicament: public Produs
{
    string folosinta;
    int bucati;             ///bucati per pret; un cumparator nu poate lua mai putine bucati decat cele meitionate per pret.
    int nrPacheteDorite;   ///aici se va pune numarul de bucati dorite de client
    int peZi;               ///de cate ori pe zi trebuie luat
    int zile;               /// pentru cate zile
        ///daca valoarile din atributele "peZile" si "zile" sunt zero inseamna ca nu le vrea pentru un tratament anume
public:
    Medicament();
    Medicament(string denumire, float pret, string folosinta, int bucati, int nrPacheteDorite,int peZi=0, int zile=0);
    Medicament(const Medicament & med);
    Medicament& operator=(const Medicament & med);
    ~Medicament();

    virtual istream& citire(istream&in);
    virtual ostream& afisare(ostream&out) const;

    void calculPachete();  ///pune in cos cate pachete de medicamentul acela este nevoie in functie de modul de utilizare dorit
    string getFolosinta();
    int getBucati();
    void setNrPacheteDorite(int x);
    int getNrPacheteDorite();
    void setPeZi(int x);
    void setZile(int x);
    void cresteNrPachete(int x);
    void scadeNrPachete(int x);
    float pretFinal();
    void categorie();
};
Medicament::Medicament():Produs()
{
    this->folosinta="none";
    this->bucati=0;
    this->nrPacheteDorite=0;
    this->peZi=0;
    this->zile=0;
}
Medicament::Medicament(string denumire, float pret, string folosinta, int bucati, int nrPacheteDorite,int peZi, int zile):Produs(denumire, pret)
{
    this->folosinta=folosinta;
    this->bucati=bucati;
    this->nrPacheteDorite=nrPacheteDorite;
    this->peZi=peZi;
    this->zile=zile;
}
Medicament::Medicament(const Medicament & med):Produs(med)
{
    this->folosinta=med.folosinta;
    this->bucati=med.bucati;
    this->nrPacheteDorite=med.nrPacheteDorite;
    this->peZi=med.peZi;
    this->zile=med.zile;
}
Medicament& Medicament::operator=(const Medicament & med)
{
    if(this != &med)
    {
        this->folosinta=med.folosinta;
        this->bucati=med.bucati;
        this->nrPacheteDorite=med.nrPacheteDorite;
        this->peZi=peZi;
        this->zile=zile;
    }
    return *this;
}

Medicament::~Medicament(){}

istream& Medicament::citire(istream&in)
{
    Produs::citire(in);
    in.get();
    cout<<"\nPentru ce este folositor acest medicament? ";
    getline(in, this->folosinta);
    cout<<"\nPentru cate bucati este pretul afisat? ";
    in>>this->bucati;
    cout<<"\nCate pachete doriti? ";
    in>>this->nrPacheteDorite;

    cout<<"\nMod de utilizare a medicamentului? ";
    cout<<"\nCate pastile(fiole) pe zi?: ";
    in>>this->peZi;
    cout<<"\nPentru cate zile? ";
    in>>this->zile;

    return in;
}
ostream& Medicament:: afisare(ostream&out) const
{
    Produs::afisare(out);
    out<<"\nPentru ce este folositor acest medicament? "<<this->folosinta;
    out<<"\nPentru cate bucati este pretul afisat? "<<this->bucati;
    if(this->nrPacheteDorite!=0)
        out<<"\nCate pachete doriti? "<<this->nrPacheteDorite;

    if(this->zile!=0 && this->peZi!=0)    ///afisez si modul de utilizare doar daca exista un mod.
    {
        out<<"\nMod de utilizare a medicamentului: ";
        out<<this->peZi<<" pe zi, timp de "<<this->zile<<" zile";
    }

    return out;
}
void Medicament::calculPachete()
{
    if(this->peZi != 0 && this->zile != 0)
    {
        if((this->peZi*this->zile)%this->bucati==0)
            this->nrPacheteDorite=(this->peZi*this->zile)/this->bucati;
        else
            this->nrPacheteDorite=((this->peZi*this->zile)/this->bucati)+1;
    }
}
string Medicament::getFolosinta()
{
    return this->folosinta;
}
int Medicament::getBucati()
{
    return this->bucati;
}
void Medicament::setPeZi(int x)
{
    this->peZi=x;
}
void Medicament::setZile(int x)
{
    this->zile=x;
}
void Medicament::setNrPacheteDorite(int x)
{
    this->nrPacheteDorite=x;
}
int Medicament::getNrPacheteDorite()
{
    return this->nrPacheteDorite;
}
void Medicament::cresteNrPachete(int x)
{
    this->nrPacheteDorite+=x;
}
void Medicament::scadeNrPachete(int x)
{
    if(x > 0)
        this->nrPacheteDorite-=x;
}
float Medicament:: pretFinal()
{
    return this->getPret()*this->nrPacheteDorite;
}
void Medicament::categorie()
{
    cout<<"\nCategoria medicament pentru animalul dvs.!";
}


///++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
void citireFisier(vector<Produs*>&stoc, set<AngajatSuperior>&ang, Cabinet* &cabinet)
{
    ifstream fin("date.in");
    string denumire;

    while(fin>>denumire)
    {

        if(denumire=="OBIECT")
        {
            string nume;
            float pret;
            fin.get();
            getline(fin, nume);
            fin>>pret;
            string animal;
            fin>>animal;
            int nrC;
            fin>>nrC;
            string* c=new string[nrC];
            fin.get();
            for(int i=0;i<nrC;i++)
                getline(fin,c[i]);
            string tara;
            fin>>tara;
            float greutate;
            fin>>greutate;

            stoc.push_back(new Obiect(nume,pret, c,animal,tara,greutate,nrC));
        }
        else if(denumire=="MEDICAMENT")
        {
            string nume;
            float pret;
            fin.get();
            getline(fin,nume);
            fin>>pret;
            string folosire;
            fin.get();
            getline(fin,folosire);
            int bucati_pachet;
            fin>>bucati_pachet;
            stoc.push_back(new Medicament(nume, pret, folosire,bucati_pachet,0,0,0));
        }
        else
            if(denumire=="ANGAJAT")
        {
            char nume[50];
            fin.get();
            fin>>nume;
            int numarPren;
            fin>>numarPren;
            string * prenume=new string[numarPren];
            for(int i=0;i<numarPren;i++)
                    fin>>prenume[i];
            char init;
            fin>>init;
            string funct;
            fin>>funct;
            int nrData;
            fin>>nrData;
            int* data= new int[nrData];
            for(int i=0;i<nrData;i++)
                fin>>data[i];
            bool exp;
            fin>>exp;
            double salariu;
            fin>>salariu;
            string sex;
            fin>>sex;
            AngajatSuperior a(nume, prenume, numarPren, init, funct, data, nrData, exp, salariu, sex, NULL, NULL,0);
            a.martie();

            ang.insert(a);
        }
        else
            if(denumire=="CABINET")
        {
            string nume;
            fin.get();
            getline(fin, nume);
            int an;
            fin>>an;
            int nr;
            fin>>nr;
            string* animale=new string[nr];
            fin.get();
            for(int i=0;i<nr; i++)
                getline(fin,animale[i]);
            int zile;
            fin>>zile;
            float* program= new float[zile*2];
            for(int i=0;i<zile*2; i++)
                fin>>program[i];

            cabinet = new Cabinet(nume, an, animale, nr, program, zile);
        }
    }
}
class MeniuInteractiv{
private:
    static MeniuInteractiv *obiect;

public:
    static MeniuInteractiv* getInstance(){
        if(!obiect)                     ///daca obiectul este null se creeaza, daca nu, il returneaza pe cel deja existent
            obiect=new MeniuInteractiv();

        return obiect;
    }

    void meniu();
};
MeniuInteractiv* MeniuInteractiv::obiect=0;

void MeniuInteractiv::meniu(){

    Cabinet* cabinet;  ///date despre cabinet, afacerea are la baza un singur cabinet   //daca cumva in fisier sunt mai multe cabinete, va fi luata doar ultima varianta(prin suprascriere)
    vector<Produs*> stoc;       ///in stoc se afla medicamente si obiecte ce pot fi cumparate
    set <AngajatSuperior> ang;   ///lista cu angajati sortati alfabetic
    ofstream fout("bon.out");     ///bonul dat omului dupa achizitionare

    citireFisier(stoc,ang,cabinet);

    map <int, list<Produs*>> bon;     ///bonurile sunt salvate in memorie, dovada cumpararii, vanzarilor realizate
    int contor=1;                ///numarul bonului, numararea se face de la 1
    list<Client*> clienti;      ///sunt numiti clienti doar cei care apeleaza la cabinetul veterinar prin aducerea unui animal,
                                        ///nu si cei care cumpara din magazin
    int intrare;
    int comanda;
    int k1=1, k2=1 ,k=1;

    while(k1==1)     ///intrarea in meniul principal
    {
    cout<<"\n\nApasati pe tasta corespunzatoare!";
    cout<<"\nInformatii despre cabinet: 000";
    cout<<"\nAdministrator: 111";
    cout<<"\nRelatii cu clientii: 222";
    cout<<"\nStop: 333\n";

    cin>>intrare;
    switch(intrare)
    {
    case 000:
        {
            cout<<"\nAfisare date: 1";
            cout<<"\nVerificare daca o anumita ora este in program: 2\n";
            cin>>comanda;
            switch(comanda)
            {
            case 1:
                {
                    cout<<*cabinet;
                    break;
                }
            case 2:
                {
                    int zi;
                    cout<<"\nIntroduceti ziua despre care vreti sa va interesati(0=luni, 1=marti, 2=miercuri, 3=joi, 4=vineri, 5=sambata, 6=duminica): ";
                    cin>>zi;
                    cout<<"\nIntroduceti ora despre care doriti sa stiti: ";
                    float o;
                    cin>>o;
                    int x=cabinet->verificare(zi,o);
                    if(x==10)
                        cout<<"\nPuteti veni!";
                    if(x==0)
                        cout<<"\nPuteti veni luni la ora aceea";
                    if(x==1)
                        cout<<"\nPuteti veni marti la ora aceea";
                    if(x==3)
                        cout<<"\nPuteti veni miercuri la ora aceea";
                    if(x==4)
                        cout<<"\nPuteti veni vineri la ora aceea";
                    if(x==5)
                        cout<<"\nPuteti veni sambata la ora aceea";
                    if(x==6)
                        cout<<"\nPuteti veni duminica la ora aceea";
                    if(x==-1)
                        cout<<"\nImi pare rau, este prea devreme pentru programul cabinetului";

                    break;
                }
            }
            break;
        }
    case 111:
        {
            cout<<"Introduceti parola: ";
            char parola[10];
            int i;
            for(i=0;i<9;i++)
            {
                parola[i]=getch();
                cout<<"*";
            }
            parola[i]='\0';
            cout<<endl;
            char stiuta[10]="123456789";
            if(strcmp(parola, stiuta)!=0)
                cout<<"\nParola invalida!";
            else
            {
                k=1;
                while(k==1)
                {
                cout<<"\n\nMedicament inserat: 1";
                cout<<"\nMedicament sters: 2";
                cout<<"\nObiect inserat: 3";
                cout<<"\nObiect sters: 4";
                cout<<"\nAngajat inserat: 5";
                cout<<"\nAngajat sters: 6";
                cout<<"\nAdaugare sarbatoare si spor pentru angajat: 7";
                cout<<"\nSterge sporul primit pentru o anumita sarbatoare: 8";
                cout<<"\nPentru Angajat - Update experienta si salariu in functie de experienta: 9";
                cout<<"\nAfisare lista medicamente: 10";
                cout<<"\nAfisare lista obiecte: 11";
                cout<<"\nAfisare lista angajati: 12";
                cout<<"\nAfisare lista bonuri fiscale: 13";
                cout<<"\nModificare interval de lucru intr-o zi: 14";
                cout<<"\nIesire: 15\n";
                cin>>comanda;
                switch(comanda)
                {
                case 1:
                    {
                        ///Medicament inserat
                        Medicament* m = new Medicament;
                        cout<<"CAMPURILE referitoare la numarul de pachete si zile se completeaza de la tastatura cu 0";
                        cin>>*m;
                        stoc.push_back(m);
                        break;
                    }
                case 2:
                    {
                        ///Medicament sters
                        int i=0;
                        for(auto it=stoc.begin();it!=stoc.end();it++)
                        {
                            if(typeid(*(*it))==typeid(Medicament))
                            {
                                cout<<"Medicament nr "<<i<<endl;
                                cout<<*(*it)<<endl<<endl;
                            }
                            i++;
                        }
                        cout<<"\nCe medicament doriti sa stergeti (introduceti numarul din lista specific lui) ";
                        int nr;
                        cin>>nr;
                        auto it=stoc.begin();
                        while(nr!=0)
                        {
                            nr--;
                            it++;
                        }
                        stoc.erase(it);
                        break;
                    }

                case 3:
                    {
                        ///Obiect inserat
                        Obiect* o= new Obiect;
                        cin>>*o;
                        stoc.push_back(o);
                        break;
                    }
                case 4:
                    {
                        ///Obiect sters
                        int i=0;
                        for(auto it=stoc.begin();it!=stoc.end();it++)
                        {
                            if(typeid(*(*it))==typeid(Obiect))
                            {
                                cout<<"Obiect nr "<<i<<endl;
                                cout<<*(*it)<<endl<<endl;
                            }
                            i++;
                        }
                        cout<<"\nCe obiect doriti sa stergeti (introduceti numarul din lista specific lui) ";
                        int nr;
                        cin>>nr;
                        auto it=stoc.begin();
                        while(nr!=0)
                        {
                            nr--;
                            it++;
                        }
                        stoc.erase(it);
                        break;
                    }
                case 5:
                    {
                        ///Angajat inserat
                        AngajatSuperior a;
                        cin>>a;
                        a.martie();        ///daca angajatul este o femeie, i se introduce direct sporurile din martie - de martisor si ziua femeii
                        ang.insert(a);
                        cout<<"\nsize "<<ang.size();
                        break;
                    }
                case 6:
                    {
                        ///Angajat sters
                        if(ang.size()==0)
                            cout<<"\nNu exista angajati in baza de date";
                        else
                        {
                            set<AngajatSuperior>::iterator it;

                            for(it=ang.begin();it!=ang.end();++it)
                                cout<<endl<<(*it);

                            cout<<"\nIntroduceti codul angajatului pe care vreti sa-l stergeti: ";
                            int cod;
                            cin>>cod;
                            for(it=ang.begin();it!=ang.end();++it)
                               {
                                   AngajatSuperior a=(*it);   ///nu este upcasting, este nevoie sa ma mut in alt obiect pentru ca setul nu accepta modificari, nici get (este const)

                                   if(cod==a.getIdAngajat())
                                        break;
                               }
                            ang.erase(it);
                        }
                        break;
                    }
                case 7:
                    {
                        ///Adaugare sarbatoare si spor pentru angajat
                            set<AngajatSuperior>::iterator it;

                            for(it=ang.begin();it!=ang.end();++it)
                                {
                                    AngajatSuperior a=(*it);      ///setul nu accepta modificari=> nu pot sa accesez date din obiect din set, trebuie luat separat
                                    cout<<endl<<"\nAngajatul "<<a.getNume()<<" cu codul "<<a.getIdAngajat();
                                }
                            cout<<"\nIntroduceti codul angajatului: ";
                            int cod;
                            cin>>cod;
                             for(it=ang.begin();it!=ang.end();++it)
                             {
                                AngajatSuperior a=(*it);
                                if(cod==a.getIdAngajat())
                                    break;
                               }

                            cout<<"\nDate despre angajatul ales";
                            cout<<(*it);
                            string sarbatoare;
                            float bani;
                            int i;
                            AngajatSuperior a=(*it);    ///sterg obiectul din set pentru al putea introduce din nou dupa update
                            ang.erase(it);
                            do
                                {
                                    cout<<"\nSarbatoare pentru care se primeste spor: ";
                                    cin.get();
                                    getline(cin,sarbatoare);
                                    cout<<"\nSpor: ";
                                    cin>>bani;
                                    a.adaugaLaLista(sarbatoare,bani);

                                    cout<<"\nAcum angajatul are urmatoarele date in baza de date: \n"<<a;

                                    cout<<"\nAdaugati si alt spor?(0/1) ";
                                    cin>>i;
                                }
                            while(i==1);
                            ang.insert(a);

                        break;
                    }
                case 8:
                {
                        ///Sterge sporul primit pentru o anumita sarbatoare
                        set<AngajatSuperior>::iterator it;

                        cout<<"\nLista angajati:";
                        for(it=ang.begin();it!=ang.end();++it)
                            {
                                AngajatSuperior a=(*it);
                                cout<<endl<<"Angajatul "<<a.getNume()<<" cu codul "<<a.getIdAngajat()<<endl;
                            }
                        cout<<"\nIntroduceti codul angajatului dorit: ";
                        int cod;
                        cin>>cod;
                         for(it=ang.begin();it!=ang.end();++it)
                         {
                            AngajatSuperior a=(*it);
                            if(cod==a.getIdAngajat())
                                break;
                           }

                        cout<<"\nDate despre angajatul ales";
                        cout<<(*it);
                        string sarbatoare;
                        int i;
                        AngajatSuperior a=(*it);
                        ang.erase(it);
                        do {
                                cout<<"\nSarbatoare pentru care doriti ca angajatul sa nu mai primeasca spor\n(Daca v-ati razgandit introduceti - ): ";
                                cin.get();

                                getline(cin,sarbatoare);

                                if(sarbatoare!="-")
                                    a.stergeLaLista(sarbatoare);

                                cout<<"\nAcum angajatul are urmatoarele date in baza de date: \n"<<a;

                                if(a.getNumar()!=0)
                                    {
                                        cout<<"\nAdaugati si alt spor sa fie scos din lista?(0/1) ";
                                        cin>>i;
                                    }
                                else
                                    i=0;
                            }while(i == 1);
                        ang.insert(a);
                        break;
                    }
                case 9:
                    {
                        ///verificare experienta si salariu
                        set<AngajatSuperior>::iterator it;
                        set<AngajatSuperior> aux;
                        for(it=ang.begin();it!=ang.end();++it)
                        {
                            AngajatSuperior a=(*it);
                            a.modificare();
                            aux.insert(a);
                        }
                        ang=aux;
                        break;
                    }
                case 10:
                    {///Afisare lista medicamente
                         for(auto it=stoc.begin();it!=stoc.end();it++)
                            if(typeid(*(*it))==typeid(Medicament))
                                cout<<*(*it)<<endl;
                        break;
                    }
                case 11:
                    {///Afisare lista obiecte
                        for(auto it=stoc.begin();it!=stoc.end();it++)
                            if(typeid(*(*it))==typeid(Obiect))
                                cout<<*(*it)<<endl;
                        break;
                    }
                case 12:
                    {///Afisare lista angajati
                        set<AngajatSuperior>::iterator it;

                        if(ang.size()==0)
                            cout<<"\nNu sunt angajati!";
                        else
                        {
                            int i=1;
                            for(it=ang.begin(); it!=ang.end(); ++it)
                                cout<<"\nAngajatul numarul "<<i++<<*it<<endl;
                        }
                        break;
                    }
                case 13:
                    {///Lista bonuri fiscale
                        map <int, list<Produs*>>::iterator it;
                        if((bon.size())==0)
                            cout<<"\nNu a fost realizata nicio vanzare!";
                        else
                           {
                               for(it=bon.begin();it!=bon.end();it++)
                                {
                                    cout<<"\n\nNumar bon: "<<it->first;
                                    cout<<"\nProduse: ";
                                    for(auto itr=it->second.begin(); itr!=it->second.end();itr++)
                                    {
                                        if((*(*itr)).getDenumire()!="Total")
                                            {
                                                (*itr)->categorie();
                                                cout<<"  ";
                                            }
                                        else
                                            cout<<"\n";
                                        cout<<(*(*itr)).getDenumire()<<" ";
                                        cout<<(*(*itr)).pretFinal();
                                    }
                                }
                           }
                         break;
                    }
                case 14:
                    {
                        ///Modificare interval de lucru intr-o zi
                        string zi;
                        cout<<"\nIntroduceti ziua in care vreti sa schimbati programul: ";
                        cin>>zi;
                        cout<<"\nIntroduceti ora de inceput si ora de terminare de program: ";
                        float o1,o2;
                        cin>>o1>>o2;
                        int i;
                        if(zi=="luni") i=0;
                        if(zi=="marti") i=1;
                        if(zi=="miercuri") i=2;
                        if(zi=="joi") i=3;
                        if(zi=="vineri") i=4;
                        if(zi=="sambata") i=5;
                        if(zi=="duminica") i=6;
                        cabinet->setProgramZi(o1, o2, i);

                        break;
                    }
                case 15:
                    {///Iesire
                        k=2;
                        break;
                    }
                default:
                    {///inserare cod gresit
                        cout<<"\nAti apasat pe o tasta gresita!\n ";
                        break;
                    }
                }
            }
        }
        break;
    }
    case 222:
        {
            k2=1;
            while(k2==1)
            {
            cout<<"\nClienti: 1";
            cout<<"\nMagazin: 2";
            cout<<"\nStop: 3\n";
            cin>>comanda;
            switch(comanda)
            {
            case 1:
                    { ///animal adus la cabinet
                    cout<<"\nIntroduceti date + calcul pret: 1";
                    cout<<"\nAfisare pe ecran a clientilor: 2\n";
                    cin>>comanda;
                    switch(comanda)
                    {
                        case 1:
                        { ///introducere client
                            cout<<"Clientul lucreaza in domeniul veterinar? ";
                            bool ok;
                            cin>>ok;
                            if(ok==1)
                            {
                                ClientInDomeniu* cd=new ClientInDomeniu;
                                cin>>*cd;
                                cd->detartaj();

                                for(auto it=clienti.begin();it!=clienti.end();++it)
                                    reducere((*(*it)),*cd);
                                cout<<"\nClientul trebuie sa dea "<<cd->pretFinal()<<"lei.";
                                clienti.push_back(cd);
                            }
                            else
                            {
                                Client *c= new Client;
                                cin>>*c;

                                for(auto it=clienti.begin();it!=clienti.end();++it)
                                    reducere((*(*it)),*c);
                                cout<<"\nClientul trebuie sa dea "<<c->pretFinal()<<" lei.";
                                clienti.push_back(c);
                            }

                            break;
                        }
                        case 2:
                        {///lista clienti
                            int i=0;
                            for(auto it=clienti.begin();it!=clienti.end();it++)
                                cout<<"\nClient nr "<<++i<<*(*it)<<"\nPret tratamente: "<<(*it)->pretFinal()<<" lei.\n";
                            break;
                        }
                    }
                    break;
                }
            case 2:
                { ///magazin
                    list<Produs*> cumparaturi;   ///lista de cumparaturi a unui om care vine la magazin: obiecte+medicamente
                    k=1;
                    while(k==1)
                {
                    cout<<"\nObiect: 1";
                    cout<<"\nMedicament: 2";
                    cout<<"\nAlocare garantii (pentru obiecte cu pret mai mare sau egal cu 200): 3";   ///daca pretul obiectului este >= 200, obiectul are garantie si se plateste o suma in plus
                    cout<<"\nEmitere bon fiscal: 4";
                    cout<<"\nStop: 5\n";

                    cin>>comanda;
                    switch(comanda)
                    {
                        int i,id;
                        case 1:
                        {
                            ///ALEG OBIECT
                            cout<<"\nPentru ce animal vreti sa cumparati? ";
                            string anm;
                            cin>>anm;

                            i=0;
                            cout<<"\nPentru animalul dvs avem urmatoarele produse: ";
                            for(auto it=stoc.begin();it!=stoc.end();it++)
                              {
                                Obiect* ob = dynamic_cast<Obiect*>(*it);    ///a trebuit sa fac dynamic_cast din cauza functiei getTipAnimal() care se gaseste in derivata, nu in clasa de baza
                                if(ob!=NULL)
                                    if(ob->getTipAnimal()==anm || ob->getTipAnimal()=="oricare")
                                        cout<<"\n"<<ob->getDenumire()<<" - costa "<<ob->getPret()<<"    nr: "<<i;
                                i++;
                              }
                            cout<<"\nAlegeti un produs: ";
                            cin>>id;
                            cout<<"\nAvem pe culorile: ";
                            Obiect* obAles=dynamic_cast<Obiect*>(stoc[id]);
                            for(i=0;i<obAles->getNrCulori();i++)
                                {
                                    cout<<obAles->getCuloare()[i]<<" nr "<<i<<"\n";
                                }
                            cout<<"\nAlegeti o culoare ";
                            int comCul;
                            cin>>comCul;
                            string* culoare=nullptr;
                            culoare=new string[1];
                            culoare[0]=obAles->getCuloare()[comCul];

                            cumparaturi.push_back(new Obiect(obAles->getDenumire(),obAles->getPret(), culoare, obAles->getTipAnimal(),obAles->getTaraProducere(), obAles->getGreutate()));

                            break;
                        }
                        case 2:
                            {
                                ///ALEG MEDICAMENT
                                i=0;
                                for(auto it=stoc.begin();it!=stoc.end();it++)
                                    {
                                        if(typeid(*(*it))==typeid(Medicament))
                                            cout<<"\n\nnr "<<i<<" "<<*(*it);
                                        i++;
                                    }
                                cout<<"\n\nAlegeti un medicament:";
                                cin>>id;

                                Medicament* medAles=  dynamic_cast <Medicament*> (stoc[id]);

                                int zile=0;
                                int peZi=0;
                                int ok;

                                if(medAles->getBucati()==1)
                                    medAles->setNrPacheteDorite(1);
                                else
                                {
                                    cout<<"\nVreti sa il folositi in mod regulat pentru o perioada? (0/1) (Se calculeaza numarul de pachete necesare pentru numarul de pastile necesare)";

                                    cin>>ok;
                                    if(ok == 1)
                                    {
                                        cout<<"\nPentru cate zile? ";
                                        cin>>zile;
                                        cout<<"\nCate pe zi? ";
                                        cin>>peZi;
                                        medAles->setZile(zile);
                                        medAles->setPeZi(peZi);

                                        medAles->calculPachete();
                                    }
                                    else
                                        medAles->setNrPacheteDorite(1);

                                }
                                cout<<"\nPana acum aveti in cos "<<medAles->getNrPacheteDorite()<<" pachet(e)";

                                cout<<"\nDoriti o alta cantitate? (0/1) ";
                                cin>>ok;
                                if(ok == 1)
                               {
                                    cout<<"Pentru mai multe pachete tastati '1' si pentru mai putine '2' ";
                                    cin>>ok;
                                    int x;
                                    if(ok==1){
                                        cout<<"\nCu cate pachete doriti mai multe? ";
                                        cin>>x;
                                        medAles->cresteNrPachete(x);
                                    }
                                    else{
                                        cout<<"\nCu cate pachete doriti mai putine? ";
                                        cin>>x;
                                        medAles->scadeNrPachete(x);
                                   }
                               }
                                cumparaturi.push_back(new Medicament(medAles->getDenumire(),medAles->getPret(),medAles->getFolosinta(),medAles->getBucati(),medAles->getNrPacheteDorite(),peZi, zile));

                                break;
                            }
                         case 3:
                            {
                                //Alocare garantii
                                list<Produs*>::iterator it;
                                Obiect* obiect;
                                for(it= cumparaturi.begin(); it!=cumparaturi.end();it++)
                                {
                                    obiect= dynamic_cast<Obiect*> ((*it));
                                    if(obiect!=NULL)
                                    {
                                        obiect->verifGarantie();
                                        if(obiect->pretFinal()!=obiect->getPret()){
                                            cout<<obiect->getDenumire()<<" - ";
                                            cout<<"pretul dupa taxa garantiei este de "<<obiect->pretFinal()<<" lei\n";
                                        }
                                    }
                                }
                                break;
                            }
                         case 4:
                            {
                                ///emitere bon fiscal
                                list<Produs*>::iterator it;
                                double s=0;

                                if(cumparaturi.begin()!=cumparaturi.end())  //pentru a nu se emite un bon fara cumparaturi
                                {
                                    fout<<"Numar bon: "<<contor<<"\n";

                                    int i=0;
                                    for(it=cumparaturi.begin();it!=cumparaturi.end();it++)
                                    {
                                        fout<<++i<<". "<<(*(*it)).getDenumire()<<" ";
                                        Obiect* ob=dynamic_cast<Obiect*>(*it);
                                        if(ob!=nullptr)
                                           {
                                            fout<<ob->pretFinal()<<" lei\n";
                                            s+=ob->pretFinal();
                                           }
                                        else
                                        {
                                            Medicament* m=dynamic_cast<Medicament*>(*it);
                                            if(m!=nullptr)
                                                {
                                                     fout<<m->getPret()<<" lei * "<<m->getNrPacheteDorite()<<"   "<<m->pretFinal()<<" lei\n";
                                                     s+=m->pretFinal();
                                                }
                                        }
                                    }
                                    fout<<"Total "<<s<<" lei\n\n";
                                    Obiect *ob = new Obiect();
                                    ob->setDenumire("Total");
                                    ob->setPret(s);
                                    cumparaturi.push_back(ob);

                                    bon.insert(make_pair(contor++, cumparaturi));

                                    cumparaturi.clear();
                                }
                                break;
                            }
                         case 5:
                            {///stop
                                k=2;
                                break;
                            }
                         default:
                            {
                                cout<<"\nAti apasat pe o tasta gresita.\nIncercati din nou!.";
                                break;
                            }
                }
                }
                    break;
                }
            case 3:
                {///stop
                    k2=2;
                    break;
                }
            default:
                {
                    cout<<"\nAti apasat o tasta gresita, incercati din nou!";
                    break;
                }
            }
        }
        break;
        }
    case 333:
    {///stop
        k1=2;
        break;
    }
    default:
        {
            cout<<"\nAti introdus un cod gresit\n";
            break;
        }
    }
    }

}

////////////////////////////////////////////////////////////////////////////
int main()
{

    MeniuInteractiv *meniulMeu=meniulMeu->getInstance();
    meniulMeu->meniu();
    return 0;
}

