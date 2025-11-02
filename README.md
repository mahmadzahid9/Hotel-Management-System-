Description:
This is a console-based Hotel Management System implemented in C++. It allows both employees and guests to manage hotel operations efficiently. The program handles guest check-ins, check-outs, room management, and feedback collection. It stores data in text files, enabling persistent storage between sessions.

Features:

For Employees:

Login with ID and password.

View all current guests along with details: name, room ID, number of persons, room type, balance, and stay duration.

View all rooms with details: room ID, type, cost per day, and status (Available/Occupied).

View guest feedback stored in the system.

For Guests:

Check-in:

Enter personal information and desired room type.

The system automatically allocates an available room and calculates the total cost.

Check if the bank balance is sufficient for the stay.

Check-out:

Provide room ID to check out.

Submit feedback about the stay.

Room status updates to "Available," and guest data is removed from the active list.

System Details:

Data Storage:

guests.txt stores guest information.

rooms.txt stores room information and status.

feedback.txt stores guest feedback.

Room Management:

Each room has an ID, type, cost per day, and occupancy status.

Room status automatically updates during check-in and check-out.

Guest Management:

Tracks name, room type, room ID, number of people, balance, and stay duration.

Guest information is added or removed from the system during check-in/check-out.

Technologies Used:

Language: C++

File Handling: Reading from and writing to .txt files for persistent storage.

Object-Oriented Programming: Classes for Guest and Room encapsulate related data and behaviors.

Usage Instructions:

Clone the repository.

Compile the C++ code using any C++ compiler (e.g., Dev-C++, Code::Blocks, or g++).

Run the executable and follow on-screen instructions to log in as an employee or guest.
