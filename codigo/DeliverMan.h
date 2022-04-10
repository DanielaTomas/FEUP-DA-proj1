#ifndef CODIGO_DELIVERMAN_H
#define CODIGO_DELIVERMAN_H

#include "Deliver.h"

/// Deliverers subcontracted by the company
class DeliverMan {
private:
    //! Deliver Man id
    int id;
    //! Deliver Man current id
    static int current_id;
    //! Carrying capacity (maximum volume)
    int maxVol;
    //! Carrying capacity (maximum weight)
    int maxW;
    //! Remaining volume
    int remainingVol;
    //! Remaining weight
    int remainingW;
    //! Transport cost that will be paid by the company
    float cost;
    //! Car plate
    std::string carPlate;
    //! A vector of delivers
    std::vector<Deliver> delivers;
    //! Check if DeliverMan is full
    bool full;
public:
    //! Constructor
    //!
    //! \param maxVol Carrying capacity (maximum volume)
    //! \param maxW Carrying capacity (maximum weight)
    //! \param cost Transport cost that will be paid by the company
    DeliverMan(int maxVol, int maxW, float cost);
    //! Get Remaining Volume
    //!
    //! \return volume
    int getRemainingVol() const;
    //! Get Remaining Weight
    //!
    //! \return weight
    int getRemainingW() const;
    //! Add a deliver
    //!
    //! \param deliver
    //! \return bool
    bool addDeliver(Deliver& deliver);
};


#endif //CODIGO_DELIVERMAN_H
