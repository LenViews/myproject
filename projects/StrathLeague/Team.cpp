#include "Team.h"
Team::Team(std::string name, std::string stadium, std::string town)
	:name(name), stadium(stadium), town(town){}
std::string Team::getName() const{
return name;
}
std::string Team::getStadium() const{ 
return stadium;
}
std::string Team::getTown() const{ 
return town;
}
