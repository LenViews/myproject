#ifndef TEAM_H
#define TEAM_H

#include <string>
class Team{
private:
std::string name;
std::string stadium;
std::string town;
public:
Team(std::string name, std::string stadium, std::string town);
std::string getName() const;
std::string getStadium() const;
std::string getTown() const;
};
#endif
