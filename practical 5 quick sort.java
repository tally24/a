import java.util.Random;

public class Main {

    public static void main(String[] args) {
        // Create an array of random numbers
        int[] numbers = new int[10000];
        Random rand = new Random();
        for (int i = 0; i < numbers.length; i++) {
            numbers[i] = rand.nextInt();
        }

        // Run the deterministic quick sort algorithm
        long deterministicTime = System.currentTimeMillis();
        deterministicQuickSort(numbers, 0, numbers.length - 1);
        long deterministicTimeEnd = System.currentTimeMillis();

        // Run the randomized quick sort algorithm
        long randomizedTime = System.currentTimeMillis();
        randomizedQuickSort(numbers, 0, numbers.length - 1, rand);
        long randomizedTimeEnd = System.currentTimeMillis();

        // Print the running times of the two algorithms
        System.out.println("Deterministic quick sort time: " + (deterministicTimeEnd - deterministicTime));
        System.out.println("Randomized quick sort time: " + (randomizedTimeEnd - randomizedTime));
    }

    public static void deterministicQuickSort(int[] numbers, int left, int right) {
        if (left >= right) {
            return;
        }

        int pivot = numbers[(left + right) / 2];
        int partition = partition(numbers, left, right, pivot);

        deterministicQuickSort(numbers, left, partition - 1);
        deterministicQuickSort(numbers, partition + 1, right);
    }

    public static void randomizedQuickSort(int[] numbers, int left, int right, Random rand) {
        if (left >= right) {
            return;
        }

        int pivotIndex = rand.nextInt(right - left + 1) + left;
        int pivot = numbers[pivotIndex];

        swap(numbers, pivotIndex, right);

        int partition = partition(numbers, left, right, pivot);

        randomizedQuickSort(numbers, left, partition - 1, rand);
        randomizedQuickSort(numbers, partition + 1, right, rand);
    }

    public static int partition(int[] numbers, int left, int right, int pivot) {
        int i = left;
        int j = right - 1;

        while (i <= j) {
            while (i <= j && numbers[j] > pivot) {
                j--;
            }

            while (i <= j && numbers[i] < pivot) {
                i++;
            }

            if (i <= j) {
                swap(numbers, i, j);
                i++;
                j--;
            }
        }

        return i;
    }

    public static void swap(int[] numbers, int i, int j) {
        int temp = numbers[i];
        numbers[i] = numbers[j];
        numbers[j] = temp;
    }
}
