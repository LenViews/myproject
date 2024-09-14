#include <algorithm>
#include <random>
#include "Scheduler.h"
#include <iostream>
#include <unordered_set>
#include <vector>
#include <iomanip>   // For time formatting
#include <sstream>   // For std::stringstream

// Utility function to generate random match times
std::string generateMatchTime() {
    // Random number generator setup
    std::random_device rd;
    std::mt19937 gen(rd());

    // Define time ranges: 14:00-18:00 for afternoon, 19:00-22:00 for evening
    std::uniform_int_distribution<> afternoonOrEvening(0, 1); // 0 for afternoon, 1 for evening
    std::uniform_int_distribution<> hourAfternoon(14, 18);    // Hours between 14:00 and 18:00
    std::uniform_int_distribution<> hourEvening(19, 22);      // Hours between 19:00 and 22:00
    std::uniform_int_distribution<> minuteDist(0, 59);        // Minutes for any hour

    // Select either afternoon or evening
    int hour = (afternoonOrEvening(gen) == 0) ? hourAfternoon(gen) : hourEvening(gen);
    int minute = minuteDist(gen);

    // Format time in HH:MM format
    std::stringstream ss;  // Include <sstream> for this
    ss << std::setfill('0') << std::setw(2) << hour << ":"
       << std::setfill('0') << std::setw(2) << minute;
    return ss.str();
}
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

        // Print out fixtures for the weekend with random times
        std::cout << "Weekend " << weekend << " Fixtures:\n";
        for (const auto& fixture : weekendFixtures) {
            std::string matchTime = generateMatchTime();  // Generate match time
            std::cout << fixture.first.getName() << " vs " << fixture.second.getName()
                      << " at " << fixture.first.getStadium()
                      << " - Time: " << matchTime << "\n";  // Include time in the output
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
