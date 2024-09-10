#include "Scheduler.h"
#include <iostream>

Scheduler::Scheduler(std::vector<Team> teams)
    : teams(teams) {}

void Scheduler::createFixtures() {
    int weekend = 1;
    for (size_t i = 0; i < teams.size(); ++i) {
        for (size_t j = i + 1; j < teams.size(); ++j) {

            fixtures.push_back(Fixture(teams[i], teams[j], weekend));
            fixtures.push_back(Fixture(teams[j], teams[i], weekend));
            // Schedule only 2 matches
            if (fixtures.size() % 2 == 0) {
                weekend++;
            }
        }
    }
}

void Scheduler::displaySchedule() const {
    for (const auto& fixture : fixtures) {
        fixture.displayFixture();
    }
}
