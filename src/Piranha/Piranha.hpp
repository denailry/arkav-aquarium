#ifndef PIRANHA_HPP
#define PIRANHA_HPP

#include "../Fish/Fish.hpp"
#include "../Guppy/Guppy.hpp"

class Piranha : public Fish
{
public:
    Piranha(double x, double y, double width, double height);
    int getLastFed() const;
    void setLastFed(int);
    void tick(LinkedList<Guppy> const& guppies, int delay);
private:
    /* Atribut untuk piranha (boleh ditambah kalau belum lengkap): */
    int lastFed;
    Guppy findNearestGuppy(LinkedList<Guppy> const& guppies);
    bool isAbleToConsume(Guppy const& guppy);
};

#endif
