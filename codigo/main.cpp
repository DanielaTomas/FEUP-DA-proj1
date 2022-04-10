#include <iostream>
#include <algorithm>
#include "DeliverMan.h"
#include "Utils.h"
using namespace std;

bool firstScenery(std::vector<Deliver>& delivers, std::vector<DeliverMan>& deliverMen) {

    //Bin packing

    //Ordenar encomendas por peso e largura

    sort(delivers.begin(), delivers.end());

    //First fit: Vai pondo cada encomenda logo no primeiro estafeta que der.
    for(auto deliver : delivers) {
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

bool compareDuration(const Deliver &d1, const Deliver &d2) {
    return d1.getDuration() < d2.getDuration();
}
float thirdScenery(std::vector<Deliver> delivers) {
    //Job scheduling

    //sort by duration (shorter deliveries first)
    sort(delivers.begin(), delivers.end(),compareDuration);

    int maxDelivers= 0, sum = 0;
    for(int i = 0; i < delivers.size(); i++) {
        if(sum+delivers[i].getDuration() <= 28800) {   //9h00-17h00 -> 8 hours = 28800 seconds
            sum += delivers[i].getDuration();
            maxDelivers++;
        }
        else {
            delivers.erase(delivers.begin()+i,delivers.end());
            break;
        }
    }

    float avgTime = (float)sum/(float)maxDelivers;
    printf("Average time: %.2f seconds\n",avgTime);

    return avgTime;
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
            thirdScenery(delivers);
            break;
        default:
            break;
    }

    return 0;
}
