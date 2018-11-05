# SYST44288–Operating Systems & Systems ProgrammingAssignment 3 –Threads and Errors
# By Simran Kaur and Syed Turab 

# Github 
The github contribution screenshot is included in the zip file. (github.png). 

# SVN logs 
The directory called SVN logs will have screenshots of all the SVN commits in our github repository. 

# Question 1 - Please refer to the directory called Question 1
Write a multithreaded program that calculates various statistical values for a list of numbers. This program will be passed a series of numbers onthe command line and will then create three separate worker threads.One thread will determine the average of the numbers, the second will determine the maximum value, and the third will determine theminimum value. For example, suppose your program is passed theintegers90 81 78 95 79 72 85The program will report:The average value is 82The minimum value is 72The maximum value is 95The variables representing the average, minimum, and maximum values will be stored globally. The worker threads will set these values, and theparent thread will output the values once the workers have exited. (We could obviously expand this program by creating additional threadsthat determine other statistical values, such as median and standard deviation.)


# Question 2 - Please refer to the directory called Question 2 
Question 2 , Assignment 2, Question 1,involved designing an echo server using the Java threading API. This server is single-threaded, meaning that theserver cannot respond to concurrent echo clients until the current clientexits. Modify yoursolution to Assignment 2, Question 1,so that the echo server serviceseach client in a separate request.Apply appropriate error handling,see theGeneral Notes Section below.Input sanitizing -While it is always recommended to sanitize input, the fact that this program will compile and execute any code it is sent over the Internet basically makes itimpossible to secure properly. Just do basic sanitizing and don’t worry too much.
