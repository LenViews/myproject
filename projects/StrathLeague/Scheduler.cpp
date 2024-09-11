#include "Scheduler.h"
#include <iostream>
#include <unordered_set>
#include <vector>

Scheduler::Scheduler(std::vector<Team> teams)
    : teams(teams) {}

void Scheduler::createFixtures() {
    std::vector<std::pair<Team, Team>> unplayedFixtures;

    // Initialize unplayed fixtures
    for (size_t i = 0; i < teams.size(); ++i) {
        for (size_t j = i + 1; j < teams.size(); ++j) {
            unplayedFixtures.emplace_back(teams[i], teams[j]);
        }
    }

    int weekend = 1;
    while (!unplayedFixtures.empty()) {
        std::vector<std::pair<Team, Team>> fixturesForWeekend;
        std::unordered_set<std::string> teamsScheduledThisWeekend;  // Correct include

        // Schedule matches for the weekend
        for (auto it = unplayedFixtures.begin(); it != unplayedFixtures.end();) {
            const std::pair<Team, Team>& fixture = *it;  // Replace structured bindings with C++11-compatible code
            const Team& team1 = fixture.first;
            const Team& team2 = fixture.second;

            if (teamsScheduledThisWeekend.find(team1.getName()) == teamsScheduledThisWeekend.end() &&
                teamsScheduledThisWeekend.find(team2.getName()) == teamsScheduledThisWeekend.end()) {

                fixturesForWeekend.emplace_back(team1, team2);
                teamsScheduledThisWeekend.insert(team1.getName());
                teamsScheduledThisWeekend.insert(team2.getName());
                it = unplayedFixtures.erase(it);  // Remove scheduled fixture
            } else {
                ++it;
            }

            // Stop if we have scheduled two matches
            if (fixturesForWeekend.size() == 2) break;
        }

       // Schedule fixtures
        for (const std::pair<Team, Team>& fixture : fixturesForWeekend) {
            const Team& team1 = fixture.first;
            const Team& team2 = fixture.second;

            fixtures.emplace_back(team1, team2, weekend);  // Home match
            fixtures.emplace_back(team2, team1, weekend + 1);  // Away match
        }

        // Move to the next weekend
        weekend += 2;
    }
}

void Scheduler::displaySchedule() const {
    for (const auto& fixture : fixtures) {
        fixture.displayFixture();
    }
}
