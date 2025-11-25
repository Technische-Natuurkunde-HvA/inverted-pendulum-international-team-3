# About this document

This is a team document where you record your weekly progress. It is written in Markdown, which allows you to format content in a simple and readable way. The document is rendered directly in GitHub without the need for a compiler (unlike LaTeX). The syntax is relatively easy. An overview of commonly used Markdown syntax can be found here:  
https://www.markdownguide.org/basic-syntax/

Below you find an example of the sections that must be included in each weekly progress report.

Use the **same document for all weeks**. For each week, use the **same headers and subheaders**.

Use the GitHub repository to store important project files (code, visuals including videos and figures, data, etc.). If necessary refer to those files in this document using a hyperlink. 

---

# Week 1

## 1. Progress description
Describe the progress of your work for this week. Keep it clear and concise.

## 2. Code

You can display code using three backticks (```) followed by an optional language extension.  
For example:  
- For C/C++ code, use `c` or `cpp`.  
- For Python, use `python`.



#### Example:

```c
// Header file for input/output functions
#include <stdio.h>

// Main function: entry point for execution
int main() {

    // Print a message to the console
    printf("Hello World");

    return 0;
}
``` 
## 3. Results
Present your results here. This may include tables, figures, or charts.
Add charts and other visuals to the `visuals` folder in the GitHub repository and reference them in this document if needed.


## 4. Reflection 
What did you learn this week?
What should you focus on or improve in the coming weeks of the project?

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

- The PWM value goes from 0  to 255. We will measure it with increments of 5. Then we will plot the PWM values against the rpm values and put a fit-function in the graph to get an equation to go from PWM to rpm.

**How many measurements will you perform at each PWM value? How long will each measurement last?:**

- 1 measurement per PWM value and measure it when the motor rotates at a constant speed.</p>

**The motor can rotate in two directions. How will you account for this in your measurements?:**

- We will measure it only at one direction.

**Which software will you use to collect and process your data?:**
    
- We will use Arduino IDE to run the program and collect the data and python to process it.

**An example of the graph you expect to produce:**

- <img width="400" height="300" alt="image" src="https://github.com/user-attachments/assets/a714d244-5c57-48db-ac11-4acac1266d3f" />
