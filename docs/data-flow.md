# Fleet Scheduler Program Workflow

```mermaid
flowchart TD
    CONFIG[Select initial algorithm in run configuration: EDF, LLF, or LLLP]
    START([Start scheduler])
    INIT[Load configuration and initialize drone data, pad status, and schedule]
    DATA["Receive drone telemetry (e.g. altitude and battery data), drone status (e.g. flying, landed, returning, or charging), pad status, or operator update"]
    VALID{Is the received input valid and usable?}
    INVALID[Report invalid or unusable input]
    CHANGE{Does the input include an algorithm selection?}
    SET_ALGO[Validate and set active algorithm]
    UPDATE[Update drone telemetry, drone status, and pad status]
    MEASURES[Recalculate derived values, return urgency, and feasibility]
    CANDIDATES[Identify safely schedulable drones]
    ANY{Are any drones safely schedulable?}
    INFEASIBLE[Produce an infeasibility status]
    RANK[Rank eligible drones using the active algorithm]
    PAD{Is the charging pad available?}
    QUEUE[Account for the pad's next available time]
    SCHEDULE[Produce or update charging schedule]
    RESULT[Return schedule or status as the program result]
    NEXT{Does the scheduler continue running?}
    STOP([End run])

    CONFIG --> START --> INIT --> DATA --> VALID
    VALID -- No --> INVALID --> RESULT
    VALID -- Yes --> CHANGE
    CHANGE -- Yes --> SET_ALGO --> UPDATE
    CHANGE -- No --> UPDATE
    UPDATE --> MEASURES --> CANDIDATES --> ANY
    ANY -- No --> INFEASIBLE --> RESULT
    ANY -- Yes --> RANK --> PAD
    PAD -- No --> QUEUE --> SCHEDULE
    PAD -- Yes --> SCHEDULE
    SCHEDULE --> RESULT
    RESULT --> NEXT
    NEXT -- Yes --> DATA
    NEXT -- No --> STOP
```

## Remaining design decisions

- What input-update format and timing the Control Station provides.
- How charging duration and the pad's next available time are estimated.
- How telemetry validity and staleness are determined.
- Which operator data or overrides are part of the scheduler's input, and how they interact with safety and feasibility checks.
- Whether a new schedule replaces only waiting/future assignments or can alter an assignment already underway. A conservative initial policy is to leave charging already in progress unchanged and apply recalculation to future assignments.
- What criteria define the best-performing algorithm for the demo.
