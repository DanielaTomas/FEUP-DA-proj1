#include <iostream>
#include <algorithm>
#include <set>
#include "DeliverMan.h"
#include "Utils.h"
using namespace std;

int firstScenery(std::vector<Deliver>& delivers, std::vector<DeliverMan>& deliverMen) {

    //Bin packing

    //Ordenar encomendas por peso e largura

    sort(delivers.begin(), delivers.end());
    reverse(delivers.begin(), delivers.end());

    //First fit: Vai pondo cada encomenda logo no primeiro estafeta que der.
    for(auto deliver: delivers) {
        for(auto & i : deliverMen) {
            if(i.addDeliver(deliver)) {
                break;
            }
        }
    }

    //Best fit: Vai pondo cada encomenda no melhor estafeta(no que sobrar menos espaço).


    return false;
}


bool secondScenery(std::vector<Deliver> delivers, std::vector<DeliverMan> deliverMen) {
    //knapsack(mochila)
    //ordenar materiais por ordem decrescente de racio valor/peso

    //se couber tudo, incluir tudo e continuar para o proximo
    //se n couber na totalidade, incluir o maximo possivel e terminar..

    //(Relatório)--Complexidade..Ordenar(nlogn)..Processar(n)..Total(nlogn)

    return false;
}

bool thirdScenery(std::vector<Deliver> delivers, std::vector<DeliverMan> deliverMen) {

    //Job scheduling

    return false;
}


int main() {

    std::vector<Deliver> delivers;
    std::vector<DeliverMan> deliverMen;
    int num;

    readFiles(delivers, deliverMen);

    std::cout << "Choose a Scenery: " << std::endl;
    std::cin >> num;

    switch(num) {
        case 1:
            firstScenery(delivers, deliverMen);
            break;
        case 2:
            secondScenery(delivers, deliverMen);
            break;
        case 3:
            thirdScenery(delivers, deliverMen);
            break;
        default:
            break;
    }

    return 0;
}
