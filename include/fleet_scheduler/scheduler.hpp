#pragma once

#include <optional>
#include <string>
#include <vector>

namespace fleet_scheduler {

enum class SchedulingAlgorithm {
    EDF,
    LLF,
    LLLP
};

struct DroneState {
    std::string id;
    std::optional<double> stateOfChargePercent{};
    std::optional<double> stateOfHealthPercent;
    std::optional<double> energyConsumptionRate;
    std::optional<double> timeToReturnSeconds;
    std::optional<double> latestSafeReturnStartSeconds;
    std::string status;
};

struct SchedulerInput {
    std::vector<DroneState> drones;
    bool chargingPadAvailable = false;
};

struct SchedulerUpdate {
    SchedulerInput input;
    std::optional<SchedulingAlgorithm> algorithmSelection;
};

struct ChargingAssignment {
    std::string droneId;
    double startTimeSeconds = 0.0;
    double durationSeconds = 0.0;
};

enum class ScheduleStatus {
    ScheduleProduced,
    InvalidInput,
    NoFeasibleSchedule,
    NotImplemented
};

struct ScheduleResult {
    ScheduleStatus status;
    std::vector<ChargingAssignment> assignments;
    std::string message;
};

class Scheduler {
public:
    explicit Scheduler(SchedulingAlgorithm initialAlgorithm);

    ScheduleResult processUpdate(const SchedulerUpdate& update);
    SchedulingAlgorithm activeAlgorithm() const;

private:
    SchedulingAlgorithm activeAlgorithm_;
};

}  // namespace fleet_scheduler
