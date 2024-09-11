
#include <algorithm>
#include <random>
#include "Scheduler.h"
#include <iostream>
#include <unordered_set>
#include <vector>

Scheduler::Scheduler(std::vector<Team> teams)
    : teams(teams) {}

void Scheduler::createFixtures() {
    std::vector<std::pair<Team, Team>> homeAndAwayFixtures;

    // Generate home and away matches for all teams
    for (size_t i = 0; i < teams.size(); ++i) {
        for (size_t j = i + 1; j < teams.size(); ++j) {
            // Home and away for each pair of teams
            homeAndAwayFixtures.emplace_back(teams[i], teams[j]);  // Team i home, Team j away
            homeAndAwayFixtures.emplace_back(teams[j], teams[i]);  // Team j home, Team i away
        }
    }

    // Shuffle the fixtures to ensure variety
    std::random_shuffle(homeAndAwayFixtures.begin(), homeAndAwayFixtures.end());

    int weekend = 1;
    std::vector<std::pair<Team, Team>> weekendFixtures;

    while (!homeAndAwayFixtures.empty()) {
        std::unordered_set<std::string> teamsPlayingThisWeekend;

        // Schedule two matches per weekend
        for (auto it = homeAndAwayFixtures.begin(); it != homeAndAwayFixtures.end(); ) {
            const Team& homeTeam = it->first;
            const Team& awayTeam = it->second;

            // Ensure the same team doesn't play twice in a weekend
            if (teamsPlayingThisWeekend.find(homeTeam.getName()) == teamsPlayingThisWeekend.end() &&
                teamsPlayingThisWeekend.find(awayTeam.getName()) == teamsPlayingThisWeekend.end()) {

                weekendFixtures.push_back(*it);
                teamsPlayingThisWeekend.insert(homeTeam.getName());
                teamsPlayingThisWeekend.insert(awayTeam.getName());

                // Erase the scheduled match from the list
                it = homeAndAwayFixtures.erase(it);

                // Stop if we have 2 matches for this weekend
                if (weekendFixtures.size() == 2) break;
            } else {
                ++it;
            }
        }

        // Print out fixtures for the weekend
        std::cout << "Weekend " << weekend << " Fixtures:\n";
        for (const auto& fixture : weekendFixtures) {
            std::cout << fixture.first.getName() << " vs " << fixture.second.getName()
                      << " at " << fixture.first.getStadium() << "\n";
        }

        weekendFixtures.clear();  // Reset for the next weekend
        weekend++;  // Move to the next weekend
    }
}




void Scheduler::displaySchedule() const {
    for (const auto& fixture : fixtures) {
        fixture.displayFixture();
    }
}
