# Architecture Diagram

```
@startuml Architecture

digraph {
    graph [rankdir=TB, splines=ortho]
    node [shape=ellipse, style=rounded]
    
    MachineState [label="Machine State"]
    
    Log1 [label="Log"]
    Configuration [label="Configuration"]
    Datatypes [label="Datatypes"]
    Interfaces [label="Interfaces"]
    Enums [label="enums"]
    ItemModels [label="Item Models"]
    Representation [label="Representation"]
    Scripting [label="Scripting"]
    Dashboard [label="Dashboard"]
    AllenManager [label="Allen Manager"]
    
    Log2 [label="Log"]
    Datatypes2 [label="Datatypes"]
    Enums2 [label="enums"]
    Representation2 [label="Representation"]
    AccessManager [label="Access Manager"]
    TaskManager [label="Task Manager"]
    ItemModels2 [label="Item Models"]
    MachineState2 [label="Machine State"]
    DataGenerator [label="Data Generator"]
    InitialSetup [label="Initial Setup"]
    Scripting2 [label="Scripting"]
    
    Log3 [label="Log"]
    Enums3 [label="enums"]
    Configuration2 [label="Configuration"]
    Datatypes3 [label="Datatypes"]
    SettingManager [label="Setting Manager"]
    
    WmcComponents [label="wmc components", shape=box, style="rounded,filled", fillcolor="#f0f0f0"]
    
    LogWmc [label="Log"]
    EnumRepresentation [label="enum representation"]
    UnitRepresentation [label="unitrepresentation"]
    
    MachineState -> Log1
    MachineState -> Configuration
    MachineState -> Datatypes
    MachineState -> Interfaces
    MachineState -> Enums
    MachineState -> ItemModels
    MachineState -> Representation
    MachineState -> Scripting
    MachineState -> Dashboard
    MachineState -> AllenManager
    
    Configuration -> AccessManager
    Configuration -> TaskManager
    Configuration -> ItemModels2
    Configuration -> MachineState2
    Configuration -> DataGenerator
    Configuration -> InitialSetup
    Configuration -> Scripting2
    
    Log1 -> Log2
    Datatypes -> Datatypes2
    Enums -> Enums2
    Representation -> Representation2
    
    Dashboard -> Log3
    Dashboard -> Enums3
    Dashboard -> Configuration2
    Dashboard -> Datatypes3
    Dashboard -> SettingManager
    
    Scripting -> WmcComponents
    
    WmcComponents -> LogWmc
    WmcComponents -> EnumRepresentation
    WmcComponents -> UnitRepresentation
    
    EnumRepresentation -> UnitRepresentation [label="connects to", style=dashed, color=red]
}

@enduml
```

## Diagram Structure

**Level 1 (Root):** Machine State

**Level 2 (Primary Components):**
- Log
- Configuration
- Datatypes
- Interfaces
- enums
- Item Models
- Representation
- Scripting
- Dashboard
- Allen Manager

**Level 3 (Sub-components):**
- Configuration expands to: Access Manager, Task Manager, Item Models, Machine State, Data Generator, Initial Setup, Scripting
- Multiple components connect to their respective secondary instances

**Level 4 (WMC Components):**
- Scripting connects to `wmc components` container
- `wmc components` contains:
  - Log
  - enum representation
  - unitrepresentation

**Connection:** `enum representation` → `unitrepresentation` (shown as dashed red line)
