import math
class car:
    def __init__(self, mass, dimensions, center_of_mass, friction_coeff, engine_power, maximum_speed):
        self.mass = mass
        self.dimensions = dimensions
        self.center_of_mass = center_of_mass
        self.friction_coeff = friction_coeff
        self.engine_power = engine_power
        self.maximum_speed = maximum_speed
        self.position = [0,0]
        self.velocity = [0,0]
        self.acceleration = [0,0]
    
    def update(self, time_step, steering, throttle, breaks):
         # Gravity
        gravity = [0, self.mass * -9.81]

         # Friction
        friction = [0, 0]
        if self.velocity[0] != 0:
            friction[0] = -1 * self.friction_coeff * gravity[1] * self.velocity[0] / abs(self.velocity[0])
        if self.velocity[1] != 0:
            friction[1] = -1 * self.friction_coeff * gravity[1] * self.velocity[1] / abs(self.velocity[1])

        # Air resistance
        air_resistance = [-0.5 * 1.2 * self.dimensions[0] * self.dimensions[1] * self.velocity[0] ** 2 * abs(self.velocity[0]), 
                          -0.5 * 1.2 * self.dimensions[1] * self.dimensions[2] * self.velocity[1] ** 2 * abs(self.velocity[1])]
        
        engine_force = [0,0]
        # Total force
        total_force = [gravity[0] + friction[0] + air_resistance[0] + engine_force[0],
                       gravity[1] + friction[1] + air_resistance[1] + engine_force[1]]
        
        # Calculate the acceleration based on the total force
        self.acceleration[0] = total_force[0] / self.mass
        self.acceleration[1] = total_force[1] / self.mass

        #Updating the velocity of the car and position of the car based on the acceleration and time step
        self.velocity[0] += self.acceleration[0] * time_step
        self.velocity[1] += self.acceleration[0] * time_step
        speed = math.sqrt(self.velocity[0]**2 + self.velocity[1]**2)
    
        if speed > self.maximum_speed:
            # if the current speed is greater than the maximum speed then bring it down to maximum limit
            self.velocity[0] *= self.max_speed / speed
            self.velocity[1] *= self.max_speed / speed
        self.position[0] += self.velocity[0] * time_step
        self.position[1] += self.velocity[1] * time_step

        

    def detect_collision(self, other_object):
        ...
    

    def render(self):
        ...

