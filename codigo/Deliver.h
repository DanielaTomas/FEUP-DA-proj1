#ifndef CODIGO_DELIVER_H
#define CODIGO_DELIVER_H

#include <string>
#include <vector>

/// Goods deliveries
class Deliver {
private:
    //! Deliver id
    int id;
    //! Deliver current id
    static int current_id;
    //! Package volume to be transported
    int volume;
    //! Package weight to be transported
    int weight;
    //! Reward for performing the service
    float reward;
    //! Estimated delivery time
    int duration;
    //! Sum of weight and volume
    float sumWeiVol;
public:
    //! Constructor
    //!
    //! \param volume Package volume to be transported
    //! \param weight Package weight to be transported
    //! \param reward Reward for performing the service
    //! \param duration Estimated delivery time
    Deliver(int volume, int weight, float reward, int duration);
    //! Get Id
    //!
    //! \return id
    int getId() const;
    //! Get package volume to be transported
    //!
    //! \return volume
    int getVolume() const;
    //! Get package weight to be transported
    //!
    //! \return weight
    int getWeight() const;
    //! Get Reward for performing the service
    //!
    //! \return reward
    float getReward() const;
    //! Get Estimated delivery time
    //!
    //! \return duration
    int getDuration() const;
    //! Compare delivers (<)
    //!
    //! \param d1 deliver 1
    //! \param d2 deliver 2
    //! \return Corresponding bool
    friend bool operator<(const Deliver& d1, const Deliver& d2);
};


#endif //CODIGO_DELIVER_H
