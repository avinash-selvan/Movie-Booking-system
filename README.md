
# 🎬 Movie Ticket Booking System (C Project)

## 📌 Overview

The **Movie Ticket Booking System** is a C language console application that simulates the process of booking and cancelling movie tickets in a theater. The program allows users to:
- View available movies and showtimes
- Select and book seats
- Cancel bookings
- See real-time seat availability (updated through a matrix)
- Calculate the total cost of tickets

All interactions happen via a clean and simple terminal menu interface.

---

## 🛠️ Features

- 🎥 Multiple movies and showtimes
- 🎟️ Seat booking with live availability using adjacency matrix
- ❌ Ticket cancellation with seat matrix updates
- 💰 Dynamic price calculation based on row selection
- 🖥️ Console-based user-friendly interface with looped menu
- ✅ Data is updated live in-memory (no file storage)

---

## 🧠 Technical Details

- **Language**: C
- **Data Structure**: Structs and 3D Adjacency Matrix
- **Matrix Logic**: 
  - Rows and columns simulate seat positions.
  - Each movie has multiple showtimes, and each showtime has its own seating chart.
- **Seat Pricing**:
  - Rows 1-2: ₹450 per seat  
  - Rows 3-5: ₹375 per seat  
  - Row 6: ₹300 per seat

---

## 📂 Project Structure

```
📁 MovieTicketBooking/
├── main.c           # Main source code
└── README.md        # Project documentation
```

---

## 📷 Sample Flow

```
🎬 Welcome to the Movie Ticket Booking System 🎬

1️⃣ View Movies and Showtimes
2️⃣ Book Tickets
3️⃣ Cancel Tickets
4️⃣ Exit

Enter your choice: 2

You selected: Avengers: Endgame
Available Showtimes:
1. 10:00 AM
2. 1:30 PM
3. 7:00 PM

Enter showtime: 2
🎟️ Seat Matrix:
 0 0 1 0 0
 1 1 1 0 0
 0 0 0 0 0

Enter row, column, number of seats: 3 2 2
✅ Seats selected successfully!
💵 Total price: ₹750
```

---

## 🚀 How to Run

1. **Clone the repository** or copy the source code into a `main.c` file.
2. Compile the code using a C compiler:
   ```bash
   gcc main.c -o movie_booking
   ```
3. Run the executable:
   ```bash
   ./movie_booking
   ```

---

## 📌 Future Enhancements

- 💾 Add file storage to persist bookings
- 🌐 Build a GUI using GTK or move to a web-based interface
- 👥 Add user login functionality
- 📱 Integrate SMS or email confirmation for bookings

---

## 👨‍💻 Author

**Avinash**  
B.Tech CSE | 3rd Year  
Passionate about software engineering and systems development.

---

## 📃 License

This project is open-source and free to use for educational purposes.
