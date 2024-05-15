#include <iostream>
#include <queue>

using namespace std;

class ArboreAVL {
private:
    struct Nod {
        int valoare;
        Nod* stanga;
        Nod* dreapta;
        int inaltime;
        int ordine;
        int nivel;
        Nod(int val) : valoare(val), stanga(nullptr), dreapta(nullptr), inaltime(1),ordine(1),nivel(1) {}
    };

    Nod* radacina;

    int inaltime(Nod* nod) {
        if (nod == nullptr)
            return 0;
        return nod->inaltime;
    }

    int echilibru(Nod* nod) {
        if (nod == nullptr)
            return 0;
        return inaltime(nod->stanga) - inaltime(nod->dreapta);
    }

    Nod* rotireDreapta(Nod* y) {
        Nod* x = y->stanga;
        Nod* T2 = x->dreapta;

        x->dreapta = y;
        y->stanga = T2;

        y->inaltime = max(inaltime(y->stanga), inaltime(y->dreapta)) + 1;
        x->inaltime = max(inaltime(x->stanga), inaltime(x->dreapta)) + 1;

        return x;
    }

    Nod* rotireStanga(Nod* x) {
        Nod* y = x->dreapta;
        Nod* T2 = y->stanga;

        y->stanga = x;
        x->dreapta = T2;

        x->inaltime = max(inaltime(x->stanga), inaltime(x->dreapta)) + 1;
        y->inaltime = max(inaltime(y->stanga), inaltime(y->dreapta)) + 1;

        return y;
    }

    Nod* inserare(Nod* nod, int valoare) {
        if (nod == nullptr)
            return new Nod(valoare);

        if (valoare < nod->valoare)
            nod->stanga = inserare(nod->stanga, valoare);
        else if (valoare > nod->valoare)
            nod->dreapta = inserare(nod->dreapta, valoare);
        else
            return nod;

        nod->inaltime = 1 + max(inaltime(nod->stanga), inaltime(nod->dreapta));

        int factorEchilibru = echilibru(nod);

        if (factorEchilibru > 1 && valoare < nod->stanga->valoare)
            return rotireDreapta(nod);

        if (factorEchilibru < -1 && valoare > nod->dreapta->valoare)
            return rotireStanga(nod);

        if (factorEchilibru > 1 && valoare > nod->stanga->valoare) {
            nod->stanga = rotireStanga(nod->stanga);
            return rotireDreapta(nod);
        }

        if (factorEchilibru < -1 && valoare < nod->dreapta->valoare) {
            nod->dreapta = rotireDreapta(nod->dreapta);
            return rotireStanga(nod);
        }

        return nod;
    }

    Nod* gasesteMinim(Nod* nod) {
        if (nod == nullptr)
            return nullptr;
        while (nod->stanga != nullptr)
            nod = nod->stanga;
        return nod;
    }

    Nod* stergeNod(Nod* radacina, int valoare) {
        if (radacina == nullptr)
            return radacina;

        if (valoare < radacina->valoare)
            radacina->stanga = stergeNod(radacina->stanga, valoare);
        else if (valoare > radacina->valoare)
            radacina->dreapta = stergeNod(radacina->dreapta, valoare);
        else {
            if (radacina->stanga == nullptr || radacina->dreapta == nullptr) {
                Nod* temp = radacina->stanga ? radacina->stanga : radacina->dreapta;

                if (temp == nullptr) {
                    temp = radacina;
                    radacina = nullptr;
                }
                else
                    *radacina = *temp;

                delete temp;
            }
            else {
                Nod* temp = gasesteMinim(radacina->dreapta);
                radacina->valoare = temp->valoare;
                radacina->dreapta = stergeNod(radacina->dreapta, temp->valoare);
            }
        }

        if (radacina == nullptr)
            return radacina;

        radacina->inaltime = 1 + max(inaltime(radacina->stanga), inaltime(radacina->dreapta));

        int factorEchilibru = echilibru(radacina);

        if (factorEchilibru > 1 && echilibru(radacina->stanga) >= 0)
            return rotireDreapta(radacina);

        if (factorEchilibru > 1 && echilibru(radacina->stanga) < 0) {
            radacina->stanga = rotireStanga(radacina->stanga);
            return rotireDreapta(radacina);
        }

        if (factorEchilibru < -1 && echilibru(radacina->dreapta) <= 0)
            return rotireStanga(radacina);

        if (factorEchilibru < -1 && echilibru(radacina->dreapta) > 0) {
            radacina->dreapta = rotireDreapta(radacina->dreapta);
            return rotireStanga(radacina);
        }

        return radacina;
    }

    void inOrdine(Nod* radacina) {
        if (radacina != nullptr) {
            inOrdine(radacina->stanga);
            cout << radacina->valoare << " ";
            inOrdine(radacina->dreapta);
        }
    }

    void afisareCuFii(Nod* nod) {
        if (nod != nullptr) {
            cout << nod->valoare << " ";

            if (nod->stanga != nullptr || nod->dreapta != nullptr) {
                cout << " ";
                if (nod->stanga != nullptr)
                {
                    cout << nod->stanga->valoare << " ";
                    nod->stanga->nivel = nod->nivel + 1;
                    nod->stanga->ordine = nod->ordine * 2 - 1;

                    cout << " ( " << nod->stanga->nivel << " " << nod->stanga->ordine << " )";
                }
                else
                    cout << "- ";
                if (nod->dreapta != nullptr)
                {
                    cout << nod->dreapta->valoare << " ";
                    nod->dreapta->nivel = nod->nivel + 1;
                    nod->dreapta->ordine = nod->ordine * 2;
                    cout<<" ( " << nod->dreapta->nivel <<" "<< nod->dreapta->ordine <<" )";
                }
                else
                    cout << "-)";
            }

            cout << endl;

            afisareCuFii(nod->stanga);
            afisareCuFii(nod->dreapta);
        }
    }

public:
    ArboreAVL() : radacina(nullptr) {}

    void inserare(int valoare) {
        radacina = inserare(radacina, valoare);
    }

    void stergere(int valoare) {
        radacina = stergeNod(radacina, valoare);
    }

    void afisareInOrdine() {
        cout << "Traversarea în ordine a arborelui AVL: ";
        inOrdine(radacina);
        cout << endl;
    }

    void afisareCuFii() {
        cout << "Afisarea nodurilor cu fii:" << endl;
        afisareCuFii(radacina);
    }
};

int main() {
    ArboreAVL arbore;


    arbore.inserare(10);
    arbore.inserare(5);
    arbore.inserare(20);
    arbore.inserare(3);
    arbore.inserare(7);
    arbore.inserare(15);
    arbore.inserare(25);


    arbore.afisareInOrdine();


    arbore.afisareCuFii();

    return 0;
}
