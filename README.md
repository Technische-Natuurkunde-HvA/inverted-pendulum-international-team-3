# Project Summary

This GitHub Repository is for the stabilization of an inverted pendulum using a PID controller.
The PID controller is run on an Arduino UNO R4. Connected to the Arduino is a AS5600 Magnetic Angle Encoder and an electrial motor.
The pendulum itself is 3D printed. Only the files for the flywheel are given in this repository.

# Repository Folders

- /3d_models folder contains the solidworks file for the flywheel design.
- /code folder contains all code used for the project.
- /code/data folder contains the exported data from the Arduino during testing of the project.
- /docs folder contains the index.md for the GitHub webpage.
- /feedback folder contains the feedback for our weekly updates on the project.
- /visuals folder contains all videos and images of the project.

# How to run the scripts

- The /code/PID_control_simple.ino script should be uploaded to an Arduino UNO R4 using the Arduino IDE, after it is uploaded the script can be started by sending "START" in the serial monitor. This will start the PID controller.

- The /code/save_info_to_csv.py script can be run via any IDE or via a python terminal, be sure to have the 'serial' library installed.
When this script is run it will send the "START" command via the serial monitor to the Arduino so the script starts and it will gather the angle and PWM data from the Arduino for 20 seconds.


