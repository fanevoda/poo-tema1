#include <iostream>

using namespace std;

class BonDeMasa
{
public:
    int id;
    string emitent;
    double valoare;

    BonDeMasa()
    {
        id = 0;
        emitent = "??";
        valoare = 0.0;

    }
    BonDeMasa(const int x, const string y, const double z)
    {
        id = x;
        emitent = y;
        valoare = z;
    }

    ~BonDeMasa()
    {}

    BonDeMasa& operator=(BonDeMasa& other)
    {
        id = other.id;
        emitent = other.emitent;
        valoare = other.valoare;
        return *this;
    }

    friend istream& operator>>(istream& is, BonDeMasa& bon);

};


class Angajat
{
public:
    int id;
    string nume;
    int nrBonuri;
    BonDeMasa bonuri[100];

    Angajat(Angajat& angajat)
    {
        id = angajat.id;
        nume = angajat.nume;
        nrBonuri = angajat.nrBonuri;
    }

    Angajat(int x, string y)
    {
        id = x;
        nume = y;
        nrBonuri = 0;
    }
    Angajat()
    {
        id = 0;
        nume = "??";
        nrBonuri = 0;
    }
    ~Angajat() {}

    void afiseaza()
    {
        cout << this->nume << " are id-ul " << this->id << " si " << this->nrBonuri << " bonuri." << endl;
    }

    Angajat& operator *=(BonDeMasa& other)
    {
        this->nrBonuri++;
        this->bonuri[this->nrBonuri] = other;
        return *this;
    }

    Angajat& operator =(Angajat& other)
    {
        this->id = other.id;
        this->nume = other.nume;
        this->nrBonuri = other.nrBonuri;
        for (int i = 0; i <= other.nrBonuri; i++)
            this->bonuri[i] = other.bonuri[i];
        return *this;
    }

    bool operator <(const Angajat& other)
    {
        return (id < other.id);
    }

    friend ostream& operator<<(ostream& os, const Angajat& angajat);
    friend istream& operator>>(istream& is, Angajat& angajat);
};

ostream& operator<<(ostream& os, const Angajat& angajat)
{
    os << angajat.nume << " are id-ul " << angajat.id << " si " << angajat.nrBonuri << " bonuri." << endl;
    return os;
}

istream& operator>>(istream& is, BonDeMasa& bon)
{
    cout << "id-ul bonului: ";
    int x;
    string y;
    double z;
    is >> x;
    cout << "emitentul bonului: ";
    is >> y;
    cout << "valoarea bonului: ";
    is >> z;

    bon.id = x;
    bon.emitent = y;
    bon.valoare = z;

    return is;

}

istream& operator>>(istream& is, Angajat& angajat)
{
    cout << "id-ul angajatului: ";
    int x;
    string y;
    double z;
    is >> x;
    cout << "numele angajatului: ";
    is >> y;

    angajat.id = x;
    angajat.nume = y;

    return is;

}



int main()
{
    BonDeMasa b1(1, "GustoPass", 9.35), b2, b3;
    b3 = b1;
    Angajat a1(22, "Ionescu"), a2;
    cout << a1;
    cin >> b2;
    cin >> a2;
    Angajat a3(a2), a4;
    a3 *= b1;
    a4 = a3;
    if (a1 < a2)
        cout << "Angajatul " << a1 << " are id-ul mai mic decat " << a2;
    a3.afiseaza();
}

