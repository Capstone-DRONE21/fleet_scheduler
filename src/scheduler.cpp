#include "fleet_scheduler/scheduler.hpp"

namespace fleet_scheduler {

Scheduler::Scheduler(SchedulingAlgorithm initialAlgorithm) : activeAlgorithm_(initialAlgorithm) {
    
}

ScheduleResult Scheduler::processUpdate(const SchedulerUpdate& update) {
    if (update.algorithmSelection.has_value()) {
        activeAlgorithm_ = *update.algorithmSelection;
    }

    // Input validation, state updates, and scheduling are not implemented yet.
    return {
        ScheduleStatus::NotImplemented,
        {},
        "Scheduling logic is a placeholder."
    };
}

SchedulingAlgorithm Scheduler::activeAlgorithm() const {
    return activeAlgorithm_;
}

}  // namespace fleet_scheduler
