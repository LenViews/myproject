#include "Scheduler.h"
#include "Team.h"
#include <iostream>
#include <vector>

int main() {
    std::vector<Team> teams = {
        Team("Cklein Stars", "CKlein Arena", "Nairobi"),
        Team("Wolves FC", "Wolves Den", "Nairobi"),
        Team("Dolphins FC", "Dolphins Stadium", "Mombasa"),
        Team("Sea Horses", "Sea Horses Arena", "Mombasa"),
        Team("Sharks United", "Sharks Stadium", "Kisumu"),
        Team("Lake Basin FC", "Lake Basin Grounds", "Kisumu"),
        Team("Thika United", "Thika Field", "Thika"),
        Team("Mavuno Comrades FC", "Mavuno Grounds", "Thika"),
        Team("Nakuru FC", "Nakuru Field", "Nakuru"),
        Team("Ostrich Associates", "Ostrich Field", "Nakuru")
    };

    Scheduler scheduler(teams);
    scheduler.createFixtures();
    scheduler.displaySchedule();

    return 0;
}
