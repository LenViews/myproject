#ifndef FIXTURE_H
#define FIXTURE_H

#include "Team.h"
#include <string>

class Fixture {
private:
    Team team1;
    Team team2;
    int weekend;
public:
    Fixture(Team t1, Team t2, int w);
    void displayFixture() const;
};

#endif
