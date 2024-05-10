#include <stdio.h>
#include <stdlib.h>

int main()
{
    int sumResult = sum(5, 7);

    int numbers[] = {2, 4, 1, 7, 5, 10, 4, 11};
    int size = sizeof(numbers) / sizeof(numbers[0]);

    cutOff(numbers, size, 5);
    printf("Size: %d\n", size);

    int peak3Result = peak3(numbers, 0, size - 1);
    int findPeakElementResult = findPeakElement(numbers);

    printf("peak3 result: %d \n", peak3Result);
    printf("findPeakElementResult result: %d \n", findPeakElementResult);

    for (int i = 0; i < size; i++) {
        printf("%d\n", numbers[i]);
    }

    return 0;
}

int sum(int number, int number2) {
    return number + number2;
}

int sub(int number1, int number2) {
    return number1 - number2;
}

void cutOff(int numbers[], int size, int k){
    for (int i = 0; i < size; i++){
        if (numbers[i] > k) {
            numbers[i] = k;
        }
    }
    return numbers;
}

// • Theoretical analysis.
//     • Algorithm 1 and 2 finds a peak in Θ(n) time.
//     • Algorithm 3 finds a peak in Θ(log n) time.

// Peak algorithms
int getIndexOfFirstPeak(int numbers[], int arrayLength) {
    if (numbers[0] >= numbers[1]) return 0;

    for (int i = 1; i <= arrayLength - 2; i++) {
        if (numbers[i - 1] <= numbers[i] && numbers[i] >= numbers[i + 1]){
            return i;
        }
    }

    if (numbers[arrayLength - 2] <= numbers[arrayLength - 1]){
            return arrayLength - 1;
    }
}

int findMax(int numbers[], int arrayLength) {
    int max = 0;

    for (int i = 0; i <= arrayLength - 1; i++) {
        if (numbers[i] > numbers[max]) {
            max = i;
        }
    }

    return max;
}

int peak3(int numbers[], int startingIndex, int endingIndex) {
    int middleIndex = (startingIndex + endingIndex) / 2;

    if (numbers[middleIndex] >= numbers[middleIndex - 1] &&
    numbers[middleIndex] >= numbers[middleIndex + 1]) {
        return middleIndex; // numbers[middleIndex] is a peak
    } else if (numbers[middleIndex - 1] > numbers[middleIndex]) {
        // Search in the left half
        return peak3(numbers, startingIndex, middleIndex - 1);
    } else {
        // Search in the right half
        return peak3(numbers, middleIndex + 1, endingIndex);
    }
}

int findPeakElement(int numbers[]) {
    int start = 0;
    int size = sizeof(numbers) / sizeof(numbers[0]);
    int end =  size - 1;

    if (size == 1) return 0;
    if (numbers[0] > numbers[1]) return 0;
    if (numbers[size - 1] > numbers[size - 2]) return size - 1;

    while(start <= end) {
        int mid = start + (end - start)/2;
        if(numbers[mid] > numbers[mid-1] && numbers[mid] > numbers[mid+1]) return mid;   // if mid == peak ( case 2 )
        else if(numbers[mid] < numbers[mid-1]) end = mid - 1; // downward slope and search space left side ( case 1)
        else if(numbers[mid] < numbers[mid+1]) start = mid + 1; // upward slope and search space right side ( case 3 )
    }

}