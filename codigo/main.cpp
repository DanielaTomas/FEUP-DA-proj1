#include "Utils.h"
#include <algorithm>
#include <set>
using namespace std;


int firstScenery(std::vector<Deliver>& delivers, std::vector<DeliverMan>& deliverMen) {

    //Bin packing

    sort(delivers.begin(), delivers.end());
    reverse(delivers.begin(), delivers.end());

    std::set<DeliverMan> result;

    int totalDuration = 0;

    //First fit.
    for(auto deliver : delivers) {
        for(auto & deliverMan : deliverMen) {
            if(deliverMan.addDeliver(deliver)) {
                totalDuration += deliver.getDuration();
                result.insert(deliverMan);
                break;
            }
        }
    }

    return result.size();
}
bool compareRacio(const Deliver &d1, const Deliver &d2) {
    return (d1.getReward()/(float)d1.getWeight()) > (d2.getReward()/(float)d2.getWeight());
}
bool compareCost(const DeliverMan &dm1, const DeliverMan &dm2) {
    return dm1.getCost() < dm2.getCost();
}

void secondScenery(std::vector<Deliver>& delivers, std::vector<DeliverMan>& deliverMen) {

    sort(delivers.begin(), delivers.end(),compareRacio);
    sort(deliverMen.begin(), deliverMen.end(), compareCost);
    float cost = 0;
    float payment = 0;
    bool usedVan = false;
    for(auto deliverMan : deliverMen){
        for(auto deliver : delivers){
            if(deliverMan.addDeliver(deliver)) {
                payment += deliver.getReward();
                usedVan = true;
            }
        }
        if(usedVan) {
            cost += deliverMan.getCost();
            usedVan = false;
        }
    }

    cout << "Profit: "<< payment-cost << endl;
}


bool compareDuration(const Deliver &d1, const Deliver &d2) {
    if(d1.getDuration() == d2.getDuration()) return d1.getId() < d2.getId();
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
    printf("Average time: %.2f seconds\n", avgTime);

    return avgTime;
}

int main() {

    std::vector<Deliver> delivers;
    std::vector<DeliverMan> deliverMen;
    string filepath1 = "../../dataset/encomendas.txt", filepath2 = "../../dataset/carrinhas.txt";
    int num;

    std::cout << "Choose a Scenery: ";
    std::cin >> num;

    switch(num) {
        case 1:
            int numDeliverMen;
            readFiles(delivers, filepath1);
            readFiles(deliverMen, filepath2);
            numDeliverMen = firstScenery(delivers, deliverMen);
            cout << "Number of used deliver man: " << numDeliverMen << endl;
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
