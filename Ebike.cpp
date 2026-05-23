#include <iostream>
#include <string>
#include <cmath>
#include <algorithm>
#include <cstdlib>
#include <ctime>
#include <iomanip>
using namespace std;
struct EBike {
    int id;
    double x;
    double y;
    double distanza;
    double autonomia;
    bool disponibile;
};
double calcolaDistanza(const EBike& bici, double Ux, double Uy) {
    return sqrt(pow(bici.x - Ux, 2) + pow(bici.y - Uy, 2));
}
bool confrontoDistanza(const EBike& A, const EBike& B) {
    return A.distanza < B.distanza;
}
int inizializzaFlotta(EBike flotta[]) { 
    flotta[0] = {1, 2.0, 3.0, 0.0, 16.0, true};
    flotta[1] = {2, 3.0, 5.0, 0.0, 12.0, false};
    flotta[2] = {3, 1.0, 4.0, 0.0, 62.0, false};
    flotta[3] = {4, 4.0, 2.0, 0.0, 42.0, true};
    flotta[4] = {5, 5.0, 1.0, 0.0, 80.0, true};
    return 5;
}
int main() {
    srand((unsigned int)time(0));
    const int N = 5;
    EBike flotta[N];
    int nBici = inizializzaFlotta(flotta);  
    double Ux, Uy;
    cout << "Inserisci la tua posizione\n";
    cout << "X: "; cin >> Ux;
    cout << "Y: "; cin >> Uy;
    int scelta = -1;
    while (scelta != 0) {
        cout << "\n+=========================+\n|      E-BIKE RENTAL      |\n+=========================+\n";
        cout << "|  1. Bici disponibili    |\n|  2. Noleggia una bici   |\n|  0. Esci                |\n+=========================+\nScelta: ";
        cin >> scelta;
        if (scelta == 1 || scelta == 2) {  
            for (int i = 0; i < nBici; i++) flotta[i].distanza = calcolaDistanza(flotta[i], Ux, Uy);
            EBike disponibili[N];
            int nDisponibili = 0;
            for (int i = 0; i < nBici; i++) {
                if (flotta[i].disponibile) {  
                    disponibili[nDisponibili] = flotta[i];
                    nDisponibili++;
                }
            }
            sort(disponibili, disponibili + nDisponibili, confrontoDistanza); 
            for (int i = 0; i < nDisponibili; i++) {
                cout << "Bici " << disponibili[i].id << " | Pos: (" << disponibili[i].x << "," << disponibili[i].y << ") | Autonomia: " << disponibili[i].autonomia << " km | Distanza: " << disponibili[i].distanza << " km\n";
            }
        }
        if (scelta == 2) {
            int idScelto;
            cout << "ID bici da noleggiare (0 per annullare): ";
            cin >> idScelto;
            if (idScelto == 0) continue;
            int indice = -1;
            for (int i = 0; i < nBici; i++) {
                if (flotta[i].id == idScelto) {
                    indice = i;
                    break;
                }
            }
            if (indice == -1 || !flotta[indice].disponibile) {
                cout << "Bici non trovata o non disponibile.\n";
                continue;
            }
            double km;
            cout << "Autonomia residua: " << flotta[indice].autonomia << " km\nQuanti km vuoi percorrere? ";
            cin >> km;
            if (km > flotta[indice].autonomia) {
                cout << "[NOLEGGIO NEGATO] Autonomia insufficiente.\n";
                continue;
            }
            int ritardo = rand() % 15 + 1;
            double tempoTotale = (km / 20.0) * 60.0 + ritardo;
            double costo = tempoTotale * 0.20;
            flotta[indice].autonomia -= km;
            cout << "RIEPILOGO NOLEGGIO\nKm percorsi: " << km << " km\nTempo totale: " << tempoTotale << " min\nCosto: " << costo << " EUR\nAutonomia rest.: " << flotta[indice].autonomia << " km\n";
        }
        if (scelta == 0) cout << "Arrivederci!\n";
    }
    return 0;
}