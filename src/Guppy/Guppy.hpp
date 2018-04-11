#ifndef GUPPY_HPP
#define GUPPY_HPP

#include "../Fish/Fish.hpp"
#include "../LinkedList/LinkedList.hpp"
#include "../Food/Food.hpp"
#include "../Coin/Coin.hpp"

class Guppy : public Fish
{
public:
    //ctor random + opr=
    Guppy(double x, double y, double width, double height);
    //Get & set
    int getC() const;
    int getG() const;
    int getLastFed() const;
    int getLastCoin() const;
    void setC(int);
    void setG(int);
    void setLastFed(int);
    void setLastCoin(int);
    //Service
    void tick(LinkedList<Food> &foods, LinkedList<Coin> &newCoins, double delay);
private:
    /* Atribut untuk guppy (boleh ditambah kalau belum lengkap): */
    int C; // Waktu periode ikan mengeluarkan koin
    int G;
		int growthCounter; //baru nih, masukin ke perubahan
    int lastFed;
    int lastCoin;
		int lastDrift; //baru nih
		int driftLength; //baru nih 
    Food* findNearestFood(LinkedList<Food> &foods);
    bool isAbleToConsume(Food const& food);

};

#endif
