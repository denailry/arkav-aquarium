#ifndef GUPPY_HPP
#define GUPPY_HPP

#include "../Fish/Fish.hpp"
#include "../LinkedList/LinkedList.hpp"
#include "../Food/Food.hpp"

enum growth : int {small=1,medium=2,large=3};

class Guppy : public Fish
{
public:
    //ctor random + opr=
    Guppy(double x, double y, double width, double height);
    //Get & set
    int getC() const;
    growth getG() const;
    int getLastFed() const;
    int getLastCoin() const;
    void setC(int);
    void setG(growth);
    void setLastFed(int);
    void setLastCoin(int);
    //Service
    void tick(LinkedList<Food> const& foods, double delay);
private:
    /* Atribut untuk guppy (boleh ditambah kalau belum lengkap): */
    int C; // Waktu periode ikan mengeluarkan koin
    growth G;
    int lastFed;
    int lastCoin;
    Food findNearestFood(LinkedList<Food> &foods);
    bool isAbleToConsume(Food const& food);

};

#endif
