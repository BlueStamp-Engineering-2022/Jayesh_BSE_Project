# Nerf Target/Alarm Clock
This project is a small alarm clock that is deactivated by the impact of a nerf dart. It uses some LEDs connected to an Arduino board to operate. The clock is calibrated using an oscillometer by recognizing similar patterns in a change in voltage, and using these patterns we can write an algorithm to recognize when the nerf dart hits and disable the alarm. This alarm clock also displays time using the LED lights, and as well as a clock, it serves as a nerf target whenever I need it.

| **Engineer** | **School** | **Area of Interest** | **Grade** |
|:--:|:--:|:--:|:--:|
| Jayesh | St. Francis High School | Mechanical Engineering | Incoming Freshman

![Headstone Image](https://lh3.googleusercontent.com/pw/AM-JKLXxO2NAix_UHZqhKbR0_yUSqJ13SZYBCzEKlT49LGyTo6AnGnMQwYPeFEVjm0XkGqb4K8YLoDKk3O8TDLQkm6bSboWW7a4QQYuqYfjVXYR5P8v0ww8n9wkq0dWff-4rqtbZzTKWc5plo5MwvwkrZ0Q=s1578-no?authuser=0)

# Final Milestone
My final milestone is to increase the reliability and accuracy of my robot. I ameliorated the sagging and fixed the reliability of the finger. As discussed in my second milestone, the arm sags because of weight. I put in a block of wood at the base to hold up the upper arm; this has reverberating positive effects throughout the arm. I also realized that the forearm was getting disconnected from the elbow servo’s horn because of the weight stress on the joint. Now, I make sure to constantly tighten the screws at that joint. 

[![Final Milestone](https://res.cloudinary.com/marcomontalbano/image/upload/v1612573869/video_to_markdown/images/youtube--F7M7imOVGug-c05b58ac6eb4c4700831b2b3070cd403.jpg )](https://www.youtube.com/watch?v=F7M7imOVGug&feature=emb_logo "Final Milestone"){:target="_blank" rel="noopener"}

# Second Milestone
My final milestone is to increase the reliability and accuracy of my robot. I ameliorated the sagging and fixed the reliability of the finger. As discussed in my second milestone, the arm sags because of weight. I put in a block of wood at the base to hold up the upper arm; this has reverberating positive effects throughout the arm. I also realized that the forearm was getting disconnected from the elbow servo’s horn because of the weight stress on the joint. Now, I make sure to constantly tighten the screws at that joint.

[![Third Milestone](https://res.cloudinary.com/marcomontalbano/image/upload/v1612574014/video_to_markdown/images/youtube--y3VAmNlER5Y-c05b58ac6eb4c4700831b2b3070cd403.jpg)](https://www.youtube.com/watch?v=y3VAmNlER5Y&feature=emb_logo "Second Milestone"){:target="_blank" rel="noopener"}
# First Milestone

My first milestone was getting the LED lights to work as a reaction to the impact of a nerf dart. I first had to hook up the piezoelectric sensor and LED lights to their respective pins. I then wrote the algorithm to differ between a nerf dart and a finger tap. This was particularily challenging because I had to create a threshold value that only the frequencies transmitted by a nerf dart's impact would exceed. This threshold value would constantly vary depending on the location of the piezo sensor on the cardboard and the angle the piezo sensor is positioned at. Once I had fixed this value, I then worked on coding a pattern for the LED lights to display. I chose a circular motion around the ring and downloaded the Adafruit Neopixel library to control the LED's. I had to create two "for" loops, one to display the lights and one to remove the lights. Once this was done, I created a small loop to check the frequencies transmitted by the piezoelectric sensor and then display the LED's appropriately.

[![First Milestone](https://i3.ytimg.com/vi/7RK27fesDF0/maxresdefault.jpg)](https://www.youtube.com/watch?v=7RK27fesDF0&t=5s)

# Starter Project
My starter project this summer was the "Useless Machine." This machine simply uses an arm to reset the position of a swith that you toggle. It operates using a PCB that contains a switch and a pressure activated lever. The pressure activated lever is completely pressed when the arm is at rest. When the switch is toggled, the motor moves the arm towards the switch, and simultaneously relieves pressure on the lever. When the arm toggles off the switch, it sends another signal to the motor telling it to move the arm away from the switch, causing the arm to also push down on the lever until the lever is fully compressed. It repeats this process once the switch is manually toggled again. 

[![First Milestone](https://i3.ytimg.com/vi/L8_Psk7M8gM/maxresdefault.jpg)](https://www.youtube.com/watch?v=L8_Psk7M8gM&feature=emb_logo "Starter Project")
