#include <stdio.h>

#define STUDENTS    3
#define EXAMS       4
#define END_PROGRAM 4

void printArray(int [][EXAMS], size_t, size_t);
void minimum(int [][EXAMS], size_t, size_t);
void maximum(int [][EXAMS], size_t, size_t);
void average(int [][EXAMS], size_t, size_t);

int studentGrades[STUDENTS][EXAMS] = {
  {77, 68, 86, 73},
  {96, 87, 89, 78},
  {70, 90, 86, 81}
};

int main() {
  void (*processGrades[4])(int [][EXAMS], size_t, size_t) =
    {printArray, minimum, maximum, average};

  int choice = -1;

  while (1) {
    printf( "Enter a choice:\n" \
      "  0  Print the array of grades\n" \
      "  1  Find the maximum grade\n" \
      "  2  Find the minimum grade\n" \
      "  3  Print the average on all tests for each student\n" \
      "  4  End program\n" \
      "? ");

    scanf("%d", &choice);
    printf("\n");

    if (choice < 0 || choice > 4) {
      printf("Invalid option: %d\n", choice);
      return 1;
    }

    if (choice == END_PROGRAM) {
      printf("Program Ended.\n");
      return 0;
    }

    //Call the function associated with this choice
    (*processGrades[choice]) (studentGrades, STUDENTS, EXAMS);
  }

  return 1; //user should return using option 4: end program
}

void printArray(int grades[][EXAMS], size_t num_students, size_t num_grades) {
  printf("                 ");

  //Print array indices above where grades will be printed
  for (int more_grades = num_grades; more_grades > 0; )
    printf("[%lu]     ", num_grades - more_grades--);
  printf("\n");

  for (size_t current_student = 0; current_student < num_students; current_student++) {
    printf("studentGrades[%lu] ", current_student);

    for (size_t current_grade = 0; current_grade < num_grades; current_grade++) {
      printf("%-8d", grades[current_student][current_grade]);
    }
    printf("\n");
  }
  printf("\n");
}

void minimum(int grades[][EXAMS], size_t num_students, size_t num_grades) {
  if (num_students < 1 || num_grades < 1) {
    printf("No grades inputted\n");
    return;
  }

  int minimum = grades[0][0];

  for (size_t current_student = 0; current_student < num_students; current_student++) {
    for (size_t current_grade = 0; current_grade < num_grades; current_grade++) {
      if (grades[current_student][current_grade] < minimum)
        minimum = grades[current_student][current_grade];
    }
  }

  printf("The lowest grade is %d\n\n", minimum);
}

void maximum(int grades[][EXAMS], size_t num_students, size_t num_grades) {
  if (num_students < 1 || num_grades < 1) {
    printf("No grades inputted\n");
    return;
  }

  int maximum = grades[0][0];

  for (size_t current_student = 0; current_student < num_students; current_student++) {
    for (size_t current_grade = 0; current_grade < num_grades; current_grade++) {
      if (grades[current_student][current_grade] > maximum)
        maximum = grades[current_student][current_grade];
    }
  }

  printf("The highest grade is %d\n\n", maximum);
}

void average(int grades[][EXAMS], size_t num_students, size_t num_grades) {
  for (size_t current_student = 0; current_student < num_students; current_student++) {
    int sum = 0;

    for (size_t current_grade = 0; current_grade < num_grades; current_grade++) {
      sum += grades[current_student][current_grade];
    }

    printf("The average for student %lu is %.1f\n", (current_student + 1), (sum / (double) num_grades));
  }
  printf("\n");
}
