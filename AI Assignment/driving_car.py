import math
import pygame
pygame.init()
import random

class Car:
    def __init__(self, mass, dimensions, center_of_mass, friction_coeff, engine_power, maximum_speed):
        self.mass = mass
        self.dimensions = dimensions
        self.center_of_mass = center_of_mass
        self.friction_coeff = friction_coeff
        self.engine_power = engine_power
        self.maximum_speed = maximum_speed
        self.position = [0, 0]
        self.velocity = [0, 0]
        self.acceleration = [0, 0]

    def update(self, time_step, steering, throttle, brakes):
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

        # Updating the velocity of the car and position of the car based on the acceleration and time step
        self.velocity[0] += self.acceleration[0] * time_step
        self.velocity[1] += self.acceleration[1] * time_step
        speed = math.sqrt(self.velocity[0]**2 + self.velocity[1]**2)

        if speed > self.maximum_speed:
            self.velocity[0] *= self.maximum_speed / speed
            self.velocity[1] *= self.maximum_speed / speed
        self.position[0] += self.velocity[0] * time_step
        self.position[1] += self.velocity[1] * time_step


    def detect_collision(self, other_object):
        # Assuming other_object has properties: position, dimensions
        min_x = self.position[0] - self.dimensions[0] / 2
        max_x = self.position[0] + self.dimensions[0] / 2
        min_y = self.position[1] - self.dimensions[1] / 2
        max_y = self.position[1] + self.dimensions[1] / 2

        other_min_x = other_object.position[0] - other_object.dimensions[0] / 2
        other_max_x = other_object.position[0] + other_object.dimensions[0] / 2
        other_min_y = other_object.position[1] - other_object.dimensions[1] / 2
        other_max_y = other_object.position[1] + other_object.dimensions[1] / 2

        if (min_x <= other_max_x and max_x >= other_min_x) and (min_y <= other_max_y and max_y >= other_min_y):
            return True
        else:
            return False

    def render(self, window):
        car_width = self.dimensions[0]
        car_height = self.dimensions[1]
        if self is my_car:
            car_color = (0, 255, 0)  # Green
        else:
            car_color = (255, 0, 0)  # Red
        car_rect = pygame.Rect(self.position[0] - car_width / 2, self.position[1] - car_height / 2, car_width, car_height)
        pygame.draw.rect(window, car_color, car_rect)

# Initialize Pygame
pygame.init()

window_width = 800
window_height = 600
window = pygame.display.set_mode((window_width, window_height))
pygame.display.set_caption("Self-Driving Car")
clock = pygame.time.Clock()

# Testing the car class
my_car = Car(1000, [80, 40, 20], [0, 0], 0.8, 200, 20)
my_car.position = [window_width / 2, window_height / 2]  # Set the initial position to the center of the window

other_car1 = Car(1200, [80, 40, 20], [0, 0], 0.8, 200, 30)
other_car1.position = [random.uniform(0, window_width), random.uniform(0, window_height)] # Set the initial position of the other car1

other_car2 = Car(1200, [80, 40, 20], [0, 0], 0.8, 200, 40)
other_car2.position = [random.uniform(0, window_width), random.uniform(0, window_height)] # Set the initial position of the other car2

other_car3 = Car(1200, [80, 40, 20], [0, 0], 0.8, 200, 60)
other_car3.position = [random.uniform(0, window_width), random.uniform(0, window_height)] # Set the initial position of the other car2

running = True
while running:
    for event in pygame.event.get():
        if event.type == pygame.QUIT:
            running = False

    # Update the car's state
    my_car.update(0.1, 0, 1, 0)  # Example values for time_step, steering, throttle, brakes
    other_car1.update(0.1, 0, 1, 0)  # Update the position of the other car
    other_car2.update(0.1, 0, 1, 0)
    other_car3.update(0.1, 0, 1, 0)
    

   # Check for collision
   # Check for collision with other_car1
    if my_car.detect_collision(other_car1):
        print("Collision with other_car1 Detected!")
        my_car.velocity = [0, 0]  # Stop my_car when collision occurs with other_car1
        other_car1.velocity = [0, 0]

    # Check for collision with other_car2
    if my_car.detect_collision(other_car2):
        print("Collision with other_car2 Detected!")
        my_car.velocity = [0, 0]  # Stop my_car when collision occurs with other_car2
        other_car2.velocity = [0, 0]
    
     # Check for collision with other_car2
    if my_car.detect_collision(other_car3):
        print("Collision with other_car3 Detected!")
        my_car.velocity = [0, 0]  # Stop my_car when collision occurs with other_car2
        other_car3.velocity = [0, 0]


    # Clear the screen
    window.fill((255, 255, 255))

    # Render the cars
    my_car.render(window)
    other_car1.render(window)
    other_car2.render(window)
    other_car3.render(window)
    

    # Update the display
    pygame.display.flip()
    clock.tick(60)  # Limit the frame rate to 60 FPS

# Quit Pygame
pygame.quit()
