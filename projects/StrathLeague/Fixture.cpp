#include "Fixture.h"
#include <iostream>

Fixture::Fixture(Team t1, Team t2, int w)
    : team1(t1), team2(t2), weekend(w) {}

void Fixture::displayFixture() const {
    std::cout << "Week " << weekend << ": " 
              << team1.getName() << " vs " << team2.getName() 
              << " at " << team1.getStadium() 
              << " (" << team1.getTown() << ")" 
              << std::endl;
}
