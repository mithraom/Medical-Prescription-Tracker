# 💊 Medical Prescription Tracker
 
A console-based **Medical Prescription Tracker** built in **C**, using **Linked Lists** to dynamically store and manage patient medication data. Developed as a 2nd Semester CAT Project for the Data Structures and Algorithms Laboratory (22MDC26) at **Coimbatore Institute of Technology**.
 
---
 
## 📌 About the Project
 
Managing multiple prescriptions and medication schedules can be challenging — especially for patients on long-term treatment or multiple medications. This project provides a simple, structured, terminal-based system to organize and monitor a patient's medication records efficiently.
 
Each medicine is stored as a node in a singly linked list, containing:
- Medicine Name
- Dosage
- Start Date & End Date
- Time of Intake (Morning / Afternoon / Night)
---
 
## ✨ Features
 
| Feature | Description |
|---|---|
| ➕ Add Prescription | Insert a new medicine record into the linked list |
| 📋 View Prescriptions | Display all current medication records |
| 🔍 Linear Search | Search for a medicine by name (O(n)) |
| ⚡ Binary Search | Fast search on sorted array conversion (O(log n)) |
| 🔃 Bubble Sort | Sort medicines by name using Bubble Sort |
| 🔃 Selection Sort | Sort medicines by name using Selection Sort |
| ✏️ Update Prescription | Modify dosage, dates, or intake time of an existing record |
| 🗑️ Delete Prescription | Remove a medicine from the list |
| ⏱️ Performance Timer | Measures and displays execution time for each algorithm |
 
---
 
## 🛠️ Tech Stack
 
- **Language:** C
- **Data Structure:** Singly Linked List
- **Algorithms:** Linear Search, Binary Search, Bubble Sort, Selection Sort
- **Standard Libraries:** `stdio.h`, `stdlib.h`, `string.h`, `time.h`
---
 
## 📊 Algorithm Complexity
 
### Searching
| Algorithm | Best Case | Worst Case | Time Complexity |
|---|---|---|---|
| Linear Search | O(1) | O(n) | O(n) |
| Binary Search | O(1) | O(log n) | O(log n) |
 
### Sorting
| Algorithm | Best Case | Worst Case | Space Complexity |
|---|---|---|---|
| Bubble Sort | O(1) | O(n²) | O(1) |
| Selection Sort | O(n²) | O(n²) | O(1) |
 
---
 
## 🚀 How to Run
 
### Prerequisites
- A C compiler (GCC recommended)
- Terminal / Command Prompt
### Steps
 
```bash
# 1. Clone the repository
git clone https://github.com/your-username/medical-prescription-tracker.git
 
# 2. Navigate to the project folder
cd medical-prescription-tracker
 
# 3. Compile the source code
gcc prescription_tracker.c -o prescription_tracker
 
# 4. Run the program
./prescription_tracker
```
 
> On Windows, use `prescription_tracker.exe` instead.
 
---
 
## 🖥️ Sample Usage
 
```
===== Medical Prescription Tracker =====
1. Add Prescription
2. Display Prescriptions
3. Linear Search (Medicine Name)
4. Binary Search (Medicine Name)
5. Bubble Sort (by Medicine Name)
6. Selection Sort (by Medicine Name)
7. Update Prescription
8. Delete Prescription
0. Exit
Enter your choice: 1
 
Enter medicine name: Paracetamol
Enter dosage: 500 mg
Enter start date (dd-mm-yyyy): 10-4-2025
Enter end date (dd-mm-yyyy): 14-4-2025
Enter time of intake (Morning/Night/etc): Morning
Prescription added successfully!
```
 
---
 
## 🔮 Future Enhancements
 
- 🔐 User Authentication (Login / Signup)
- 🔔 Medication Reminder Notifications
- 📅 Date-Based Filtering (current / expired prescriptions)
- 📄 Export to PDF / CSV
- 🏥 Doctor and Pharmacy Mapping
- ☁️ Mobile App with Cloud Sync
- 🌳 Advanced Data Structures (Trees, Hash Maps) for better performance
---
 
## 📁 Project Structure
 
```
medical-prescription-tracker/
│
├── prescription_tracker.c   # Main source code
└── README.md                # Project documentation
```
 
---
 
