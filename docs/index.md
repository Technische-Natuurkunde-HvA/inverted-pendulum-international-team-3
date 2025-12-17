index.md

# Reaction Wheel Inverted Pendulum - Team 3

This project was carried out by an international team of students at the
Technische Natuurkunde program (HvA). The objective is to stabilize an
inverted pendulum using a reaction wheel driven by an electric motor.

## 1. Project Motivation

The inverted pendulum is an interesting project for the experimentation with control of a system. The materials needed for this project are not too expensive and most parts can be 3D printed. 

## 2. System Overview

## 3. Control Principle

## 4. Implementation

### 4.1 Arduino Control Software

### 4.2 Python Tools

For the gathing of data from the Arduino we used the /inverted-pendulum-international-team-3/code/save_info_to_csv.py script. 

For the visualisation of the data we used the /inverted-pendulum-international-team-3/code/plot_data.ipynb script.

## 5. Experiments and Data
We had to kalibrate the motor to give the correct RPM for the given PWM values. 

Data HVA team 

[PWM over time](../visuals/PID_data_bearing_time_vs_pwm.png)

[PWM over time, less weight](../visuals/PID_data_bearing_less_weight_time_vs_pwm.png)

[anglke over time](../visuals/PID_data_bearing_time_vs_angle.png)

[angle over time, less weight](../visuals/PID_data_bearing_less_weight_time_vs_angle.png)

Data ISEL team 

[angle over time](../visuals/image_2025-11-21_154353655.png)


## 6. Results
Results HVA team 

[slow swing](../visuals/Pendulum%20slow%20swing.mp4)

[stabilised pendulum](../visuals/stabilised%20pendulum%20HVA.mp4)


Results ISEL team 

[stabilised pendulum](../visuals/pendulumn_lisbon.mp4)


## 7. Project Timeline
Week 1

Both sides of the team met each other online. We decided that team in Lisbon will design the wheel and team Amsterdam will make the measurement protocol.


Week 2

HVA team: This week we did the PWM measurements with incrementing steps of 50. We made a graph of these measurements set out against The RPM value.

Next week we are going to do the measurements again with incrementing steps of 5 like out interntational side of the team have done.


Week 3

HVA Team: This week we did the PWM-RPM measurement again but with incrementing steps of 5.

We combined the graphs of both our teams's output response curves.


Week 4

The portugal team has had some setbacks with the sensor. The sensor made big jumps in the value it read out, even by just blowing on it. We tried to change from Arduino UNO R4 WiFi to the Arduino Uno R3. It was not successful. We changed cables. We changed the sensor. Adjusted the mount. Made multiple versions of the code that are now in comment on our sketch of the week 3 assignment. And it set us back so as we did not start to do the week 4 assignment as we were not able to retrieve data to complete the week 3 assignment as we. So they didnt manage to get the pendulumn to be stable yet. They did manage to get the sensor working eventually but didn't have time to do the week 4 assignment so they will do that next week. The assignment for week 3 could be completed.

The HvA team did manage to stabilize the pendulumn but couldn't manage to export the data with python because one of the arms snapped. We did get another one printed out so we'll try again next week.

We are also going to print out a new wheel.

As for the extra challenges, we'll try to use a bearing and maybe try removing some counterweight.

Week 5

The HVA team got the pendulum fixed up which broke last week. We managed to complete the challenge of adding the metal bearings and using less weight.

The additional challenges went well. We didn't have enough time to do morwe challenging assignments sadly.

## 8. Team and Credits

Hoge school Van Amsterdam

Students:
Finn Van Woensel
Fatih Burcu  
Eric Nusser 

Supervisors:
Mark Bosman
Youssef el Bouhassani
Saskia Van Asselt


instituto superior de engenharia de lisboa

Students:
Rafael Gonçalves
Emanuel Timoteo
Rafael Luís

Supervisors: 
Mário Mendes 
Manfred Niehus
Pedro Patricio

## 9. Repository
