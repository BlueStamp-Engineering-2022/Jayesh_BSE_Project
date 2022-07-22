# Nerf Target/Alarm Clock
This project is a small alarm clock that is deactivated by the impact of a nerf dart. It uses some LEDs connected to an Arduino board to operate. The clock is calibrated using an oscillometer by recognizing similar patterns in a change in voltage, and using these patterns we can write an algorithm to recognize when the nerf dart hits and disable the alarm. This alarm clock also displays time using the LED lights, and as well as a clock, it serves as a nerf target whenever I need it.

| **Engineer** | **School** | **Area of Interest** | **Grade** |
|:--:|:--:|:--:|:--:|
| Jayesh | St. Francis High School | Mechanical Engineering | Incoming Freshman

![Headstone Image](https://lh3.googleusercontent.com/pw/AM-JKLXxO2NAix_UHZqhKbR0_yUSqJ13SZYBCzEKlT49LGyTo6AnGnMQwYPeFEVjm0XkGqb4K8YLoDKk3O8TDLQkm6bSboWW7a4QQYuqYfjVXYR5P8v0ww8n9wkq0dWff-4rqtbZzTKWc5plo5MwvwkrZ0Q=s1578-no?authuser=0)

# Final Milestone
My final milestone is the final assembly of the nerf alarm clock as well as having all the code working. I accomplished the time feature through an RTC module, which was very helpful because it kept an accurate track of time in the background without having to place any extra code in my loop. To display the time on the LED ring, I simply wrote a small equation to get the amount of minutes that has passed since the last 12:00 (either midnight or noon depending on which one is most recent, and then I divided 720 (amount of minutes in 12 hours) by that to get the percentage of the ring that should be filled up. To turn off and on the buzzer, I change the pin number when the piezoelectric sensor detects that a nerf dart has hit to an inactive pin, causing no sound to be played. I then reset it at midnight. The piezoelectric sensor works in the same way as in my first milestone.

[![Final Milestone](https://res.cloudinary.com/marcomontalbano/image/upload/v1612573869/video_to_markdown/images/youtube--F7M7imOVGug-c05b58ac6eb4c4700831b2b3070cd403.jpg )](https://www.youtube.com/watch?v=F7M7imOVGug&feature=emb_logo "Final Milestone"){:target="_blank" rel="noopener"}

# First Milestone

My first milestone was getting the LED lights to work as a reaction to the impact of a nerf dart. I first had to hook up the piezoelectric sensor and LED lights to their respective pins. I then wrote the algorithm to differ between a nerf dart and a finger tap. This was particularily challenging because I had to create a threshold value that only the frequencies transmitted by a nerf dart's impact would exceed. This threshold value would constantly vary depending on the location of the piezo sensor on the cardboard and the angle the piezo sensor is positioned at. Once I had fixed this value, I then worked on coding a pattern for the LED lights to display. I chose a circular motion around the ring and downloaded the Adafruit Neopixel library to control the LED's. I had to create two "for" loops, one to display the lights and one to remove the lights. Once this was done, I created a small loop to check the frequencies transmitted by the piezoelectric sensor and then display the LED's appropriately.

[![First Milestone](https://i3.ytimg.com/vi/7RK27fesDF0/maxresdefault.jpg)](https://www.youtube.com/watch?v=7RK27fesDF0&t=5s)

# Starter Project
My starter project this summer was the "Useless Machine." This machine simply uses an arm to reset the position of a swith that you toggle. It operates using a PCB that contains a switch and a pressure activated lever. The pressure activated lever is completely pressed when the arm is at rest. When the switch is toggled, the motor moves the arm towards the switch, and simultaneously relieves pressure on the lever. When the arm toggles off the switch, it sends another signal to the motor telling it to move the arm away from the switch, causing the arm to also push down on the lever until the lever is fully compressed. It repeats this process once the switch is manually toggled again. 

[![First Milestone](https://i3.ytimg.com/vi/L8_Psk7M8gM/maxresdefault.jpg)](https://www.youtube.com/watch?v=L8_Psk7M8gM&feature=emb_logo "Starter Project")
