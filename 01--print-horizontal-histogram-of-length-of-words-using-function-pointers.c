#include <stdio.h>

#define SIZE 10

int a[SIZE] = {2, 6, 4, 8, 10, 12, 89, 68, 45, 37};

void bubble_sort(int (*comparison_function) (int, int), int numbers[], int size);
int ascending(int first, int second);
int descending(int first, int second);

/** @brief Main asks if the user wants to sort the array in ascending or descending order,
 *         then prints the original array and the sorted one based on the user input.
 */
int main() {
  int choice = -1;
  int (*comparison_function) (int, int);
  char *comparison_string = "invalid";

  printf( "Enter 1 to sort in ascending order\n" \
          "Enter 2 to sort in descending order\n" \
          "Your choice: ");

  scanf("%d", &choice);
  printf("\n");

  switch (choice) {
    case 1:
      comparison_function = ascending;
      comparison_string = "ascending";
      break;
    case 2:
      comparison_function = descending;
      comparison_string = "descending";
      break;
    default:
      printf("Invalid option.");
      return 1; //return error status code
  }

  printf("Data items in original order\n");

  for (int i = 0; i < SIZE; i++)
    printf("%5d", a[i]);
  printf("\n");

  bubble_sort(comparison_function, a, SIZE);

  printf("Data items in %s order\n", comparison_string);

  for (int i = 0; i < SIZE; i++)
    printf("%5d", a[i]);
  printf("\n\n");

  return 0;
}

/** @brief Bubble sort algorithm sorts the array numbers either ascending
 *         or descending depending on what function is passed for comparison_function.
 *
 *         Implemented based on the unoptimized pseudocode implementation in wikipedia's bubble sort article.
 *
 *  @param comparison_function  The function that compares to determine if a swap must be done.
 *  @param numbers  The array to sort.
 *  @param numbers_size The size of the array numbers.
 */
void bubble_sort(int (*comparison_function) (int, int), int numbers[], int numbers_size) {
  int swapped = 0;

  do {
    swapped = 0;

    //Loop through all elements, comparing and swapping if necessary
    for (int i = 0; i < numbers_size - 1; i++) {
      //if the comparison determines we need to swap
      if ((*comparison_function) (numbers[i], numbers[i + 1])) {
        //swap
        int temp = numbers[i];
        numbers[i] = numbers[i + 1];
        numbers[i + 1] = temp;

        //swap occurred this pass through: ie. array may not be sorted
        swapped = 1;
      }
    }
  } while (swapped); //Takes one extra pass to know the array is sorted (no swap occurred)

  return;
}

/** @brief ascending returns 1 if a swap must be done to sort in ascending order.
 *  @param first  The element that comes first in the array.
 *  @param second The element that comes second in the array.
 *  @return 0 if second is larger than first, that is, it is ascending already, and 1 if it is not ascending and a swap must be done.
 */
int ascending(int first, int second) {
  return first > second;
}

/** @brief descending returns 1 if a swap must be done to sort in descending order.
 *  @param first  The element that comes first in the array.
 *  @param second The element that comes second in the array.
 *  @return 0 if second is smaller than first, that is, it is descending already, and 1 if it is not descending and a swap must be done.
 */
 int descending(int first, int second) {
  return second > first;
}
