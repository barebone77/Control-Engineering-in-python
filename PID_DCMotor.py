import matplotlib.pyplot as plt
import numpy as np

# Parameters
set_point = 100  # Desired speed
Kp = 0.1         # Proportional gain
Ki = 0.01        # Integral gain
Kd = 0.05        # Derivative gain
dt = 0.1         # Time step
sim_time = 150   # Simulation time

# Initialization
integral = 0
previous_error = 0
motor_speed = 0
time_data = []
speed_data = []

# PID loop
for t in np.arange(0, sim_time, dt):
    error = set_point - motor_speed  # Calculate the error

    # PID terms
    P_out = Kp * error
    integral += error * dt
    I_out = Ki * integral
    derivative = (error - previous_error) / dt
    D_out = Kd * derivative

    # Control output
    control_output = P_out + I_out + D_out

    # Update motor speed
    motor_speed += control_output * dt

    # Save data for plotting
    time_data.append(t)
    speed_data.append(motor_speed)

    # Update the previous error
    previous_error = error

# Plot the results
plt.plot(time_data, speed_data)
plt.title('DC Motor with PID Control')
plt.xlabel('Time (s)')
plt.ylabel('Speed (RPM)')
plt.grid(True)
plt.show()
