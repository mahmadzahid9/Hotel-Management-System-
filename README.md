# 🏨 Hotel Management System

A console-based **Hotel Management System** developed in C++ to automate basic hotel operations such as guest check-in, check-out, room allocation, employee management, and guest feedback.

The system uses **object-oriented programming** and **text-file-based data storage**, allowing important hotel information to persist between program sessions.

---

## 📌 Overview

The Hotel Management System provides separate functionality for **Employees** and **Guests**.

Employees can manage and monitor hotel information, while guests can check into available rooms, check out, and provide feedback about their stay.

The system automatically manages room availability during the check-in and check-out processes.

---

## ✨ Features

### 👨‍💼 Employee Features

Employees can log into the system using their credentials and access hotel management information.

#### Employee Login
- Login using employee ID and password.
- Provides access to hotel and guest information.

#### Guest Management
Employees can view information about registered guests, including:

- Guest name
- Room ID
- Room type
- Number of guests
- Account balance
- Duration of stay

#### Room Management

Employees can view all hotel rooms and their current status.

Room information includes:

- Room ID
- Room type
- Cost per day
- Availability status

#### Feedback Management

Employees can view feedback submitted by guests after their stay.

---

### 🧑‍💼 Guest Features

Guests can manage their stay through the guest section of the system.

#### 🛎️ Check-In

During check-in, guests:

1. Enter their personal information.
2. Select their desired room type.
3. The system searches for an available room.
4. The selected room is automatically allocated.
5. The system verifies the guest's available bank balance.
6. The guest's information is stored.
7. The room status is updated to **occupied**.

#### 🚪 Check-Out

During check-out, guests:

1. Provide their room ID.
2. Complete the checkout process.
3. Submit feedback about their stay.
4. The room is automatically marked as **available**.
5. Guest information and feedback are stored for future reference.

---

## 🗂️ Data Storage

The system uses text files to maintain data between program sessions.

| File | Description |
|---|---|
| `guests.txt` | Stores guest information |
| `rooms.txt` | Stores room information and availability |
| `feedback.txt` | Stores guest feedback |

This allows the system to retain information even after the program is closed.

---

## 🧱 Object-Oriented Design

The system follows an **Object-Oriented Programming (OOP)** approach.

### Guest Class

The `Guest` class represents hotel guests and manages information related to their stay, including:

- Personal information
- Room assignment
- Number of guests
- Stay duration
- Account/balance information

### Room Class

The `Room` class represents hotel rooms and manages:

- Room ID
- Room type
- Room cost
- Room availability

The use of classes helps organize the system into logical and reusable components.

---

## 🔄 Room Allocation

Room availability is automatically updated throughout the guest lifecycle.

```text
Guest Requests Room
        │
        ▼
Check Requested Room Type
        │
        ▼
Search Available Room
        │
        ▼
Check Guest Balance
        │
   ┌────┴────┐
   │         │
Valid       Invalid
   │         │
   ▼         ▼
Allocate    Reject
Room        Booking
   │
   ▼
Room → Occupied
```

When a guest checks out:

```text
Guest Check-Out
       │
       ▼
Submit Feedback
       │
       ▼
Complete Check-Out
       │
       ▼
Room → Available
```

---

## 🛠️ Technologies Used

- **C++**
- Object-Oriented Programming
- File Handling
- Classes and Objects
- Console-based User Interface
- Text File Storage

### Standard C++ Concepts

The project demonstrates concepts such as:

- Classes and objects
- Encapsulation
- Constructors
- Member functions
- Conditional statements
- Loops
- File input/output
- Data validation
- Object-based system design

---

## 💻 Requirements

To run the project, you need:

- A C++ compiler
- Dev-C++
- Code::Blocks
- Visual Studio
- MinGW / `g++`
- Windows, Linux, or macOS

---

## 🚀 Installation & Setup

### 1. Clone the Repository

```bash
git clone <repository-url>
```

Navigate into the project directory:

```bash
cd Hotel-Management-System
```

### 2. Compile the Program

Using `g++`:

```bash
g++ main.cpp -o hotel_management
```

### 3. Run the Program

On Windows:

```bash
hotel_management.exe
```

On Linux/macOS:

```bash
./hotel_management
```

Alternatively, open the project using **Dev-C++** or **Code::Blocks**, compile the source code, and run the executable.

---

## 📖 Usage

After launching the application, follow the instructions displayed in the console.

Users can access the appropriate functionality by logging in as either:

```text
Employee
```

or

```text
Guest
```

### Employee

Employees can:

- Log in
- View guests
- View rooms
- Check room availability
- View guest feedback

### Guest

Guests can:

- Check into the hotel
- Select a desired room type
- Check room availability
- Check out
- Submit feedback

---

## 📁 Project Structure

```text
Hotel-Management-System/
│
├── main.cpp
├── guests.txt
├── rooms.txt
├── feedback.txt
└── README.md
```

> The `.txt` files are used for persistent storage and may be created or updated automatically by the application.

---

## 🔐 Data Persistence

One of the key features of the system is its use of **file handling**.

Instead of keeping all information only in memory, the system stores hotel data in text files. This means information can be loaded again when the application is restarted.

The system maintains separate files for:

- Guest records
- Room information
- Guest feedback

---

## 🎯 Project Objectives

The main objectives of this project are to:

- Develop a practical C++ application using OOP.
- Implement hotel room allocation.
- Manage guest check-in and check-out.
- Maintain room availability automatically.
- Implement file-based persistent storage.
- Provide separate employee and guest functionality.
- Practice real-world software design using C++.

---

## 🔮 Future Improvements

Possible future enhancements include:

- 🗄️ Database integration
- 🌐 Online hotel booking
- 🖥️ Graphical user interface
- 💳 Online payment processing
- 🧾 Automated bill generation
- 📅 Reservation scheduling
- ❌ Booking cancellation
- 🔍 Room search and filtering
- 👥 Multiple employee roles
- 📊 Hotel management dashboard
- 📧 Booking confirmation notifications
- 🏷️ Discount and promotional systems

---

## 👨‍💻 Author

**Muhammad Ahmed**

Developed as a C++ project to demonstrate **Object-Oriented Programming, file handling, data management, and system design**.

---

## 📄 License

This project was developed for **educational purposes**.
