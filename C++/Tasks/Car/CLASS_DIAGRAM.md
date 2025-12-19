# Car Project Architecture - Class Diagram

```
@startuml Car_Architecture

!define CLASSWIDTH 140

' Base Classes
class Car {
    - brand: string
    - model: string
    - fuelType: string
    - price: double
    - milage: float
    - myDoor[4]: Door
    - mySeat[4]: Seat
    - myWheel[4]: AlloyWheel
    - myEngine: Engine
    - myStaring: Staring
    - myHeadLight: HeadLight
    - myTailLight: TailLight
    - myWindShield: WindShield
    - myGear: ManualTransmission
    - myDashboard: DashBoard
    + start()
    + drive()
    + stop()
}

class Engine {
    - engineType: string
    - engineHP: int
    + engineStart()
    + engineStop()
}

class Wheel {
    - wheelRadius: float
    - myTyer: TubeTyer
    + move()
    + turn()
    + insertTyer()
    + removeTyer()
}

class AlloyWheel {
    - price: float
    - myBreak: DiscBreak
}

class SteelWheel {
    - price: float
}

class Tyer {
    - tyerBrand: string
    - tyerRadius: float
    + fillAir()
}

class TubeTyer

class TubeLessTyer

class Break {
    + slowDown()
    + releaseBreak()
}

class DiscBreak {
    - price: float
    + utilizeFriction()
}

class DrumBreak {
    - price: float
    + mechanicalBrakeing()
}

class Gear {
    + transmitMotion()
}

class ManualTransmission {
    + controlSpeed()
}

class AutoTransmission {
    + controlMode()
}

class Light {
    - lightType: string
    + lightON()
    + lightOFF()
}

class HeadLight

class TailLight

class Door {
    - doorMaterial: string
    - doorColor: string
    - myWindow: Window
    + openDoor()
    + closeDoor()
}

class Window {
    - windowType: string
    + openWindow()
    + closeWindow()
}

class WindShield {
    + clearView()
    + disturbedView()
}

class Seat {
    - seatType: string
    - seatLength: int
    + seatIncline()
    + seatDecline()
}

class Staring {
    - handleType: string
    + turnRight()
    + turnLeft()
    + horn()
}

class DashBoard {
    - myAC: AirConditioner
    - myMusicPlayer: MusicPlayer
    - myUSB: UsbPort
    + operate()
}

class AirConditioner {
    + cool()
    + warm()
}

class MusicPlayer {
    + playMusic()
    + pauseMusic()
}

class UsbPort {
    + connectDevice()
}

' Inheritance Relationships
AlloyWheel --|> Wheel : inherits
SteelWheel --|> Wheel : inherits

TubeTyer --|> Tyer : inherits
TubeLessTyer --|> Tyer : inherits

DiscBreak --|> Break : inherits
DrumBreak --|> Break : inherits

ManualTransmission --|> Gear : inherits
AutoTransmission --|> Gear : inherits

HeadLight --|> Light : inherits
TailLight --|> Light : inherits

' Composition Relationships
Car *-- "4" Door : contains
Car *-- "4" Seat : contains
Car *-- "4" AlloyWheel : contains
Car *-- Engine : contains
Car *-- Staring : contains
Car *-- HeadLight : contains
Car *-- TailLight : contains
Car *-- WindShield : contains
Car *-- ManualTransmission : contains
Car *-- DashBoard : contains

Wheel *-- TubeTyer : contains
AlloyWheel *-- DiscBreak : contains
Door *-- Window : contains

DashBoard *-- AirConditioner : contains
DashBoard *-- MusicPlayer : contains
DashBoard *-- UsbPort : contains

@enduml
```

## Architecture Overview

### Main Class: Car
The **Car** class is the central composition that aggregates all major car components:
- **Propulsion**: Engine, ManualTransmission
- **Steering**: Staring (steering wheel)
- **Wheels**: 4x AlloyWheel instances
- **Doors & Windows**: 4x Door (each with a Window)
- **Seats**: 4x Seat
- **Lighting**: HeadLight, TailLight
- **Interior**: DashBoard, WindShield

### Inheritance Hierarchies

#### Wheel Variants
- **Wheel** (base class)
  - **AlloyWheel** (with DiscBreak)
  - **SteelWheel**

#### Tire Variants
- **Tyer** (base class)
  - **TubeTyer**
  - **TubeLessTyer**

#### Brake Variants
- **Break** (base class)
  - **DiscBreak** (modern braking system)
  - **DrumBreak** (mechanical braking system)

#### Transmission Variants
- **Gear** (base class)
  - **ManualTransmission**
  - **AutoTransmission**

#### Light Variants
- **Light** (base class)
  - **HeadLight**
  - **TailLight**

### Dashboard Subsystem
The **DashBoard** class composes three entertainment/connectivity components:
- **AirConditioner**: Climate control
- **MusicPlayer**: Audio entertainment
- **UsbPort**: Device connectivity

### Component Relationships
- Each **Door** contains a **Window**
- Each **Wheel** contains a **Tyer**
- Each **AlloyWheel** contains a **DiscBreak**
- **Staring** handles steering and horn control
- **WindShield** manages front windshield operations
- **Seat** provides seating configuration
