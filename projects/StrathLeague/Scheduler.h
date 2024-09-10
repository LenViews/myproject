#ifndef SCHEDULER_H
#define SCHEDULER_H

#include <vector>
#include "Team.h"
#include "Fixture.h"

class Scheduler {
private:
    std::vector<Team> teams;
    std::vector<Fixture> fixtures;
public:
    Scheduler(std::vector<Team> teams);
    void createFixtures();
    void displaySchedule() const;
};

#endif
