import cv2
import matplotlib.pyplot as plt

# Load the image
image = cv2.imread('C:\\Users\\Admin\\OneDrive\\Desktop\\picture.jpg')

# Apply Gaussian filter
gaussian_blur = cv2.GaussianBlur(image, (5, 5), 0)

# Create a subplot
fig, axs = plt.subplots(1, 2, figsize=(10, 5))

# Display the original image
axs[0].imshow(cv2.cvtColor(image, cv2.COLOR_BGR2RGB))
axs[0].set_title('Original Image')
axs[0].axis('off')

# Display the image after applying Gaussian filter
axs[1].imshow(cv2.cvtColor(gaussian_blur, cv2.COLOR_BGR2RGB))
axs[1].set_title('Gaussian filter applied')
axs[1].axis('off')

plt.show()