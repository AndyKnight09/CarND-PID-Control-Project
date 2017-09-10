# Vehicle Detection Project

The goal of this project was to implement a PID controller to control the steer angle of a simulated car as it drives around a track.

## [Rubric](https://review.udacity.com/#!/rubrics/824/view) Points
### Here I will consider the rubric points individually and describe how I addressed each point in my implementation.  

---

### Compilation

#### Your code should compile.

The code compiles using cmake and make commands as described in project instructions.

### Implementation

#### The PID procedure follows what was taught in the lessons.

I have implemented the PID controller as described in the lessons. However, there are a couple of changes that I made:

1) The CTE has been scaled by speed of the vehicle before use by the PID. I found that this prevented the vehicle from oversteering at low speeds (e.g. when setting off).

2) The integral error term in the PID controller has been limited to prevent the integral term growing too large and dominating the control (integral wind up).

3) I used a simple proportional controller to control the throttle of the vehicle based on the current steer angle. This helps to slow the car down as it travels round sharper corners and then accelerate on the longer straights.

### Reflection

#### Describe the effect each of the P, I, D components had in your implementation.

The proportional term forces the vehicle to steer back towards the centre of the track but can lead to an oscillating trajectory if it is too dominant.

The derivative term helps to limit the rate at which the car steers back towards the centre of the track, effectively damping the effect of the proportional control.

The integral term helps to bring the car back onto the centre line of the track when errors are small but sustained. I found it also helped to make the car take some of the sharper corners more tightly.

#### Describe how the final hyperparameters were chosen.

The parameters were chosen by manually tuning performance of the car. First of all I chose a proportional gain that provided a nice oscillating trajectory (see [video 1](./videos/Proportional%20controller.mp4)). I then tuned the derivative gain to damp the oscillation (see [video 2](./videos/Proportional%20and%20Derivative%20controller.mp4)). I then increased the integral gain until performance started to osciallate again and then reduced it slightly (see [video 3](./videos/PID%20controller.mp4)). Finally I added a proportional gain control of the throttle to give the final result (see [video 4](./videos/PID%20controller%20with%20throttle%20control.mp4)).

Final parameters:

|| PID Parameter || Value ||
| --- | --- |
| Proportional Gain | 0.08 |
| Integral Gain | 0.002 |
| Derivative Gain | 5.0 |

### Simulation

#### The vehicle must successfully drive a lap around the track.

The final video shows the car driving successfully around the track (see [video 4](./videos/PID%20controller%20with%20throttle%20control.mp4)).
