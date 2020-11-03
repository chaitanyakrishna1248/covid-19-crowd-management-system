# covid-19-crowd-management-system
This project is inspired from the problems local shop keepers have been facing because of overcrowding of people 
in the shops as well as not following sanitising procedures by the public. The project has two systems, a simple 
counter system made of two IR sensors and a sanitising system consisting of a piezoelectric sensor. Whenever a 
person enters the shop he has to sanitise his hands using the mechanical sanitising system where in we use legs
to press the button to get our hands sanitised. The system has piezoelectric sensor so if a person presses the 
system the sensor records in the data. Then he moves to the counter system where his count is recorded. If both
conditions satisfy the person is allowed to enter else an alarm will be triggered. The data is sent to thinger.io
to monitor.
Components used: NodeMCU, IR sensors, piezoelectric sensors, Jumper wires
