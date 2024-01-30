# CGPA Calculator

A simple console-based GPA and CGPA calculator written in C++. The program takes course names, grades, and credits obtained in each course during each semester as input to calculate GPA and CGPA.

## How to Use

1. **Run the program in your preferred IDE.**
2. **Enter the number of completed semesters.**
3. For each semester:
   - **Enter the number of courses.**
   - For each course:
     - **Enter the course name.**
     - **Enter the achieved grade(e.g., A+, A, A-, ...,F).**
     - **Enter the credit hours of the course.**
  
The program will then display the GPA and credit hours for the current semester, as well as the CGPA and total credit hours up to that point.

## Menu Options

After completing the calculation, the program presents the user with the following options:
   - `0` to Exit the program.
   - `1` to Calculate CGPA again.

## Notes

   - This program will clear the console before each new set of calculations using (`system("cls")`). Might not work on all platforms.
   - This program assumes that the user enters all valid inputs for grades and credit hours.
   - This program uses a default grade point scale. To customize it, modify the HashMap in the code. Be aware that any changes may affect the GPA and CGPA accuracy.

 **Feel free to use, modify, and distribute the code with proper attribution.**
