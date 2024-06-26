import matplotlib.pyplot as plt
import numpy as np

# Create an image of 20x20 pixels
food_image = np.zeros((20, 20, 3), dtype=np.uint8)

# Draw some food-like shapes (a simple example, e.g., a piece of fruit)
# Let's create a red apple-like shape in the center
for i in range(20):
    for j in range(20):
        if (i-10)**2 + (j-10)**2 < 30:  # A circle equation
            food_image[i, j] = [0, 255, 0]  # green for foodGate and grey for blockage
        elif (i-10)**2 + (j-10)**2 < 35:  # A slightly larger circle for the border
            food_image[i, j] = [139, 69, 19]  # Brown color for the border

# Save the image as a PNG file
plt.imsave('food_sprite.png', food_image)

'/mnt/data/food_sprite.png'
