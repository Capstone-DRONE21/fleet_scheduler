#include "fleet_scheduler/scheduler.hpp"

#include <iostream>

int main() {
    fleet_scheduler::Scheduler scheduler{
        fleet_scheduler::SchedulingAlgorithm::EDF
    };

    std::cout << "Fleet Scheduler not ready for demo!!! :)" << std::endl;

    (void)scheduler;
    return 0;
}
