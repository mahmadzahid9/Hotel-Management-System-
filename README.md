Hotel Managment System
Description:
A console-based Hotel Management System in C++ for managing guest check-ins, check-outs, rooms, and feedback. The system stores data in text files, enabling persistent storage between sessions.

Features:

Employee:

Login using ID and password.

View all guests with details: name, room ID, room type, number of guests, balance, and stay duration.

View all rooms with details: room ID, type, cost per day, and status.

View guest feedback.

Guest:

Check-in: Enter personal info and desired room type; the system allocates an available room and verifies bank balance.

Check-out: Provide room ID, submit feedback, and automatically free the room.

System Details:

Guest Data: Stored in guests.txt.

Room Data: Stored in rooms.txt.

Feedback: Stored in feedback.txt.

Object-oriented design with Guest and Room classes.

Room availability automatically updates on check-in/check-out.

Usage:

Clone the repository.

Compile the C++ code (Dev-C++, Code::Blocks, or g++).

Run the program and follow prompts to log in as Employee or Guest.  
