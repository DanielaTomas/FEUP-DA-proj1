#include "Utils.h"
#include <algorithm>
#include <set>
using namespace std;

/*
int checkBestFit(set<DeliverMan*>& usedDeliverMen, Deliver& deliver) {

    int volume = 999999;
    int weight = 999999;
    int id = -1;

    for(auto & usedDeliverMan : usedDeliverMen) {
        if(deliver.getWeight() <= usedDeliverMan->getRemainingW()
        && deliver.getVolume() <= usedDeliverMan->getRemainingVol()) {
            if(usedDeliverMan->getRemainingVol() < volume
            && usedDeliverMan->getRemainingW() < weight) {
                volume = usedDeliverMan->getRemainingVol();
                weight = usedDeliverMan->getRemainingW();
                id = usedDeliverMan->getId();
            }
        }
    }

    return id;
}


DeliverMan* searchForDeliverMan(int id, vector<DeliverMan>& deliverMen) {

    DeliverMan* deliverMan1;

    for(auto & deliverMan : deliverMen) {
        if(deliverMan.getId() == id) {
            deliverMan1 = new DeliverMan(deliverMan);
            break;
        }
    }

    return deliverMan1;
}
*/

int firstScenery(std::vector<Deliver>& delivers, std::vector<DeliverMan>& deliverMen) {

    //Bin packing

    sort(delivers.begin(), delivers.end());
    reverse(delivers.begin(), delivers.end());

    std::set<DeliverMan> result;

    int totalDuration = 0;

    //First fit: Vai pondo cada encomenda logo no primeiro estafeta que der.
    for(auto deliver : delivers) {
        if(totalDuration >= 28800) { //8 horas de trabalho
            break;
        }
        for(auto & deliverMan : deliverMen) {
            if(deliverMan.addDeliver(deliver)) {
                totalDuration += deliver.getDuration();
                result.insert(deliverMan);
                break;
            }
        }
    }

    /*
    vector<DeliverMan> deliverMenBF = deliverMen;
    set<DeliverMan> resultBF;
    */

    //Best fit: Vai pondo cada encomenda no melhor estafeta(no que sobrar menos espaço).
    /*
    std::set<DeliverMan*> usedDeliverMen;
    for(auto deliver : delivers) {
        int deliverManId = checkBestFit(usedDeliverMen, deliver);
        if(deliverManId != -1) {
            DeliverMan& deliverMan = searchForDeliverMan(deliverManId, deliverMenBF);
            if(deliverMan.getId() != -1) {
                deliverMan.addDeliver(deliver);
                continue;
            }
        }
        for(auto & deliverMan : deliverMenBF) {
            if(deliverMan.addDeliver(deliver)) {
                usedDeliverMen.insert(&deliverMan);
                resultBF.insert(deliverMan);
                break;
            }
        }
    }

    cout << "First Fit: " << resultFF.size() << endl;
    cout << "Best Fit: " << resultBF.size() << endl;

    if(resultFF.size() < resultBF.size()) {
        deliverMen = deliverMenFF;
        return resultFF.size();
    }else {
        deliverMen = deliverMenBF;
        return resultBF.size();
    }
    */
    return result.size();

}
bool compareRacio(const Deliver &d1, const Deliver &d2) {
    return (d1.getReward()/d1.getWeight()) > (d2.getReward()/d2.getWeight());
}
bool compareCost(const DeliverMan &dm1, const DeliverMan &dm2) {
    return dm1.getCost() < dm2.getCost();
}

void secondScenery(std::vector<Deliver>& delivers, std::vector<DeliverMan>& deliverMen) {

    sort(delivers.begin(), delivers.end(),compareRacio);
    sort(deliverMen.begin(), deliverMen.end(), compareCost);
    int custo=0;
    int pagamento=0;
    bool carrinhausada=false;
    for(auto deliverMan : deliverMen){
        for(auto deliver : delivers){
            if((deliverMan.getRemainingW() >= deliver.getWeight()) && (deliverMan.getRemainingVol()>= deliver.getVolume())) {
                deliverMan.addDeliver(deliver);
                pagamento+=deliver.getReward();
                carrinhausada= true;
            }
        }
        if(carrinhausada) {
            custo += deliverMan.getCost();
            carrinhausada = false;
        }
    }
    cout<<"Lucro: "<<pagamento-custo<<endl;
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
    float avgTimeHours = avgTime/120;
    printf("Average time: %.2f seconds\n", avgTime);
    cout << "Average time: " << avgTimeHours << " hours." << endl;

    return avgTime;
}

int main() {

    std::vector<Deliver> delivers;
    std::vector<DeliverMan> deliverMen;
    string filepath1 = "../../dataset/encomendas_test.txt", filepath2 = "../../dataset/carrinhas_test.txt";
    int num;

    std::cout << "Choose a Scenery: ";
    std::cin >> num;

    switch(num) {
        case 1:
            int numDeliverMen;
            readFiles(delivers, filepath1);
            readFiles(deliverMen, filepath2);
            cout << "efwfew" << endl;
            numDeliverMen = firstScenery(delivers, deliverMen);
            cout << "Numero de estafetas usados for the best option: " << numDeliverMen << endl;
            break;
        case 2:
            readFiles(delivers, filepath1);
            readFiles(deliverMen, filepath2);
            secondScenery(delivers, deliverMen);
            break;
        case 3:
            readFiles(delivers, filepath1);
            thirdScenery(delivers);
            break;
        default:
            break;
    }

    return 0;
}
