# Gym Tracker - OOP Final Project
**Autor:** Arturo Sebastian García Soto

## Problem Statement & Solution
Tracking different types of workouts (like strength training and cardio) often requires distinct data points (e.g., weights and reps vs. distance and pace). This project solves that problem by providing a console-based object-oriented C++ application. It allows the user to log distinct types of exercises, store them in daily sessions, and calculate the total accumulated workout time using an intuitive menu.

## Build and Run Instructions
To compile and run this project, open your terminal, ensure you are in the root directory of the repository, and execute the following commands:

**1. Compile the code (Strictly C++14 with all warnings):**
```bash
g++ -std=c++14 -Wall Gym_Tracker/*.cpp -o gym_tracker
```
**2. Run the application:**
```bash
./gym_tracker
```

## Expected / Sample Output

Upon running the program, the user is greeted with a continuous menu:

```text
=================================
       GYM TRACKER SYSTEM        
=================================
A - Log new session
B - View full history
C - Calculate total time of ALL sessions (Test + operator)
X - Exit
Choose an option:
```

When logging an exercise and displaying the history, the polymorphic display will show formatted data specific to the exercise type:

--- Strength Exercise ---
ID: 1 | Name: Weights
Focus: U | Sets: 4 | Reps: 10 | Weight: 60 kg
Duration: 45 min | Effort: 8/10
