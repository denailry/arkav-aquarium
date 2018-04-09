#ifndef PIRANHA_HPP
#define PIRANHA_HPP

#include "../Fish/Fish.hpp"

class Piranha : public Fish
{
public:
    Piranha(int x, int y);
    int getLastFed() const;
    void setLastFed(int) const;
    void tick(LinkedList<Guppy> const& guppies);
private:
    /* Atribut untuk piranha (boleh ditambah kalau belum lengkap): */
    int lastFed;
    Guppy findNearestGuppy(LinkedList<Guppy> const& guppies);
    bool isAbleToConsume(Guppy const& guppy);
};

#endif
