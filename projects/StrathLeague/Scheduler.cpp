#include "Scheduler.h"
#include <iostream>
#include <unordered_set>
#include <vector>

Scheduler::Scheduler(std::vector<Team> teams)
    : teams(teams) {}

void Scheduler::createFixtures() {
    int n = teams.size();
    int rounds = n - 1;  // Number of rounds needed (each team plays others once)

    // Vector to store all teams, use modulo operation for round-robin logic
    std::vector<Team> tempTeams = teams;

    // To store the fixtures
    std::vector<std::pair<Team, Team>> allFixtures;

    // Round-robin schedule for n teams over n-1 rounds
    for (int round = 0; round < rounds; ++round) {
        for (int i = 0; i < n / 2; ++i) {
            Team homeTeam = tempTeams[i];
            Team awayTeam = tempTeams[n - 1 - i];

            // Create fixtures for this round
            allFixtures.emplace_back(homeTeam, awayTeam);
        }

        // Rotate the array of teams, leaving the first one fixed
        Team lastTeam = tempTeams[n - 1];
        for (int i = n - 1; i > 1; --i) {
            tempTeams[i] = tempTeams[i - 1];
        }
        tempTeams[1] = lastTeam;
    }

    // Assign matches to weekends
    int weekend = 1;
    for (size_t i = 0; i < allFixtures.size(); ++i) {
        const std::pair<Team, Team>& fixture = allFixtures[i];
        fixtures.emplace_back(fixture.first, fixture.second, weekend);

        // After every two matches (one weekend), increment the weekend count
        if ((i + 1) % 2 == 0) {
            weekend += 1;
        }
    }
}

void Scheduler::displaySchedule() const {
    for (const auto& fixture : fixtures) {
        fixture.displayFixture();
    }
}
