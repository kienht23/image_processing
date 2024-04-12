import cv2
import numpy as np
import matplotlib.pyplot as plt

# Load the image
image = cv2.imread('C:\\Users\\Admin\\OneDrive\\Desktop\\mountain.jpg')

# Convert the image to grayscale
gray = cv2.cvtColor(image, cv2.COLOR_BGR2GRAY)

# Apply Sobel filter
sobelx = cv2.Sobel(gray, cv2.CV_64F, 1, 0, ksize=5)  # x-direction
sobely = cv2.Sobel(gray, cv2.CV_64F, 0, 1, ksize=5)  # y-direction

# Compute the magnitude of the gradient
gradient_magnitude = cv2.sqrt(cv2.addWeighted(cv2.pow(sobelx, 2.0), 1.0, cv2.pow(sobely, 2.0), 1.0, 0.0))

# Convert back to uint8
gradient_magnitude = cv2.convertScaleAbs(gradient_magnitude)

# Create a subplot
fig, axs = plt.subplots(1, 2, figsize=(10, 5))

# Display the original image
axs[0].imshow(cv2.cvtColor(image, cv2.COLOR_BGR2RGB))
axs[0].set_title('Original Image')
axs[0].axis('off')

# Display the image after applying Sobel filter
axs[1].imshow(gradient_magnitude, cmap='gray')
axs[1].set_title('Sobel filter applied')
axs[1].axis('off')

plt.show()