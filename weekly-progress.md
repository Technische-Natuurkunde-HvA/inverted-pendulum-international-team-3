# About this document

This is a team document where you record your weekly progress. It is written in Markdown, which allows you to format content in a simple and readable way. The document is rendered directly in GitHub without the need for a compiler (unlike LaTeX). The syntax is relatively easy. An overview of commonly used Markdown syntax can be found here:  
https://www.markdownguide.org/basic-syntax/

Below you find an example of the sections that must be included in each weekly progress report.

Use the **same document for all weeks**. For each week, use the **same headers and subheaders**.

Use the GitHub repository to store important project files (code, visuals including videos and figures, data, etc.). If necessary refer to those files in this document using a hyperlink. 

---

# Week 1

## 1. Progress description
We made a plan to make a wheel and a measurement protocol. We decided that team Lisbon will design the wheel and team Amsterdam will make the measurement protocol.

## 2. Code
For code, we will use the pre-written C# code to measure the PWM values.



## 3. Results
We had workshops and made a plan for the next week.

## 4. Reflection 
We have learnt how to work as an international team and what impacts culture differences has on an international team and how to deal with (if any) problems caused by cultural differences.

---

# Week 2

## 1. Progress description
HVA team: This week we did the PWM measurements with incrementing steps of 50.
We made a graph of these measurements set out against The RPM value.

## 2. Code

## 3. Results
HVA team
<img width="571" height="453" alt="image" src="https://github.com/user-attachments/assets/afa86f9c-f8f4-4628-b2f9-04c6656095b4" />


## 4. Reflection 
HVA team: We are going to do the measurements again with incrementing steps of 5 like out interntational side of the team have done. 

## 5. Measurement protocol
**At which PWM values will you measure?:**

- *The PWM value goes from 0  to 255. We will measure it with increments of 5. Then we will plot the PWM values against the rpm values and put a fit-function in the graph to get an equation to go from PWM to rpm.*

**How many measurements will you perform at each PWM value? How long will each measurement last?:**

- *1 measurement per PWM value and measure it when the motor rotates at a constant speed.*

**The motor can rotate in two directions. How will you account for this in your measurements?:**

- *We will measure it only at one direction.*

**Which software will you use to collect and process your data?:**
    
- *We will use Arduino IDE to run the program and collect the data and python to process it.*

**An example of the graph you expect to produce:**

- <img width="400" height="300" alt="image" src="https://github.com/user-attachments/assets/a714d244-5c57-48db-ac11-4acac1266d3f" />

---

# Week 3

## 1. Progress description
HVA Team: This week we did the PWM-RPM measurement again but with incrementing steps of 5. 

## 2. Code 

## 3. Results
We combined the graphs of both our teams's output response curves.

## 4. Reflection

# Week 4

## 1. Progress description

The portugal team has had some setbacks with the sensor. The sensor made big jumps in the value it read out, even by just blowing on it.
We tried to change from Arduino UNO R4 WiFi to the Arduino Uno R3.
It was not successful.
We changed cables.
We changed the sensor.
Adjusted the mount.
Made multiple versions of the code that are now in comment on our sketch of the week 3 assignment.
And it set us back so as we did not start to do the week 4 assignment as we were not able to retrieve data to complete the week 3 assignment as we.
So they didnt manage to get the pendulumn to be stable yet.
They did manage to get the sensor working eventually but didn't have time to do the week 4 assignment so they will do that next week.
The assignment for week 3 could be completed.

The HvA team did manage to stabilize the pendulumn but couldn't manage to export the data with python because one of the arms snapped.
We did get another one printed out so we'll try again next week.

We are also going to print out a new wheel.


## 3. Results

So for the results the HvA team got the pendulumn stable but couldnt export the data.
The portugal team couldnt get the pendulumn stable yet because of problems with the sensor.

## 4. Reflection

As for the extra challenges, we'll try to use a bearing and maybe try removing some counterweight.