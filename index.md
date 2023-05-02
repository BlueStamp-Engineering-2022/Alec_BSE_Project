# Smart Lamp with IoT Technology
My Smart Lamp detects movement in the area, temperature and humidity. The Lamp also has an additional features for safety, the security mdoe. When activated if movement is detected in the area, an alarm will go off, alerting the owner to the burgalrs presence. If the security mode isn't activated and movement is detected in the room, the lamp will turn on.

| **Engineer** | **School** | **Area of Interest** | **Grade** |
|:--:|:--:|:--:|:--:|
| Alec | The Harker School | Electrical Engineering | Incoming Sophmore

<img width="767" alt="Screen Shot 2022-06-17 at 9 20 20 AM" src="https://user-images.githubusercontent.com/107577299/174337803-5cfe6110-a3b2-4814-a6ca-9fb8a80d731d.png">

# First Milestone
I completed all of the electronics including triggers, notifications, sensors and a LED light. The PIR sensor detects infrared, which detects movement around the area. The IDR sensor detects the light level around the room and if it is below a certain level, it will turn on the Neopixel LED ring. The neopixel LED ring can change colors using sliders on the cayenne dashboard. The DHT11 sensor senses the temperature and humidity around the room. If the temperature and humidity are too high or low, a notification will be sent to the owner. There are also 2 other buttons on the cayenne dashboard, the burglar mode, which, if pressed, will detect movement in the room and send a notification to the owner. But when the button is not activated and movement is detected in the room, the lamp will turn on. The False Safe button in case there is a false alert when the burglar mode is turned on. 

[![First Milestone](https://i3.ytimg.com/vi/BQ9KYhZLy0E/maxresdefault.jpg)](https://www.youtube.com/watch?v=BQ9KYhZLy0E)

# Second Milestone
My second milestone was simply making sure all of the code and the electronics were able to work. My biggest struggle during this milestone was the timer. I tried to find multiple libraries that had a timer function, but I ended up just using arduino’s slight delay between each command to sum up a delay for when movement is detected. The rest of my code is pretty straightfoward, either scanning in the different values, or adjusting the lights based on the values of the sensors.

[![Second Milestone](https://i3.ytimg.com/vi/SQUfqLcNOkU/maxresdefault.jpg)](https://www.youtube.com/watch?v=SQUfqLcNOkU&feature=emb_logo "Second Milestone")
  
# Final Milestone
My final milestone is adding an additional feature to my lamp. My additional feature for this project was the increased radius to the LED ring. Instead of just 12 led lights, I made a 35 led neopixel ring. With this modification came many struggles. I had to redesgin all of my schematics for my enclosure and dome and also use a makeshift cardboard for a divet. 

[![Final Milestone](https://i3.ytimg.com/vi/9kh0GzjxDNE/maxresdefault.jpg )](https://www.youtube.com/watch?v=9kh0GzjxDNE&feature=emb_logo "Final Milestone")

![image](https://content.instructables.com/ORIG/F8H/HNQL/J8QGDILR/F8HHNQLJ8QGDILR.png)

![IMG_2339](https://user-images.githubusercontent.com/107577299/176978044-8d126bcf-b2a6-4d83-aa3f-1ca3e405f010.jpg)

<img width="200" alt="Screen Shot 2022-06-29 at 11 31 12 AM" src="https://user-images.githubusercontent.com/107577299/176510277-5e7cd8a5-0ec1-4028-83e8-6846b6b1fcbf.png"> <img width="200" alt="Screen Shot 2022-06-29 at 11 31 42 AM" src="https://user-images.githubusercontent.com/107577299/176510386-6b11b940-5989-477b-8f94-80a275dbcaa9.png"> <img width="200" alt="Screen Shot 2022-06-29 at 11 31 29 AM" src="https://user-images.githubusercontent.com/107577299/176510306-7e34bb26-bb0c-4d9c-a5f6-63bc266f9a04.png"> <img width="200" alt="Screen Shot 2022-06-29 at 11 31 36 AM" src="https://user-images.githubusercontent.com/107577299/176510363-f7cb9746-fa02-4be5-8ba6-a84004807601.png"> 


# Useless Machine

The useless machine is well, useless. It uses a switch that triggers a LED light (green) and the movement of the arm. When the arm hits the switch, flipping it, the LED turns red, and the arm reverses directions. Eventually, the base of the arm hits a snap switch, which turns off the whole circuit. The switch connects to the motor and battery through 2 sets of green pins.

[![Starter Project](https://i3.ytimg.com/vi/BQ9KYhZLy0E/maxresdefault.jpg)](https://www.youtube.com/watch?v=BQ9KYhZLy0E)

