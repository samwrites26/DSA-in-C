#include <stdio.h>

int main()
{
    int arr[100], n, i;
    int choice, pos, value, key;
    int low, high, mid, found;

    // Array creation
    printf("Enter number of elements: ");
    scanf("%d", &n);

    printf("Enter %d elements:\n", n);
    for(i = 0; i < n; i++)
    {
        scanf("%d", &arr[i]);
    }

    do
    {
        printf("\n----- ARRAY OPERATIONS -----\n");
        printf("1. Display\n");
        printf("2. Insertion\n");
        printf("3. Deletion\n");
        printf("4. Updation\n");
        printf("5. Linear Search\n");
        printf("6. Binary Search\n");
        printf("7. Exit\n");

        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch(choice)
        {
            // Display
            case 1:
                printf("Array elements are:\n");
                for(i = 0; i < n; i++)
                {
                    printf("%d ", arr[i]);
                }
                printf("\n");
                break;

            // Insertion
            case 2:
                printf("Enter position (1 to %d): ", n + 1);
                scanf("%d", &pos);

                printf("Enter value: ");
                scanf("%d", &value);

                if(pos < 1 || pos > n + 1)
                {
                    printf("Invalid position!\n");
                }
                else
                {
                    for(i = n; i >= pos; i--)
                    {
                        arr[i] = arr[i - 1];
                    }

                    arr[pos - 1] = value;
                    n++;

                    printf("Element inserted successfully.\n");
                }
                break;

            // Deletion
            case 3:
                printf("Enter position to delete (1 to %d): ", n);
                scanf("%d", &pos);

                if(pos < 1 || pos > n)
                {
                    printf("Invalid position!\n");
                }
                else
                {
                    for(i = pos - 1; i < n - 1; i++)
                    {
                        arr[i] = arr[i + 1];
                    }

                    n--;

                    printf("Element deleted successfully.\n");
                }
                break;

            // Updation
            case 4:
                printf("Enter position to update (1 to %d): ", n);
                scanf("%d", &pos);

                if(pos < 1 || pos > n)
                {
                    printf("Invalid position!\n");
                }
                else
                {
                    printf("Enter new value: ");
                    scanf("%d", &value);

                    arr[pos - 1] = value;

                    printf("Element updated successfully.\n");
                }
                break;

            // Linear Search
            case 5:
                printf("Enter element to search: ");
                scanf("%d", &key);

                found = 0;

                for(i = 0; i < n; i++)
                {
                    if(arr[i] == key)
                    {
                        printf("Element found at position %d.\n", i + 1);
                        found = 1;
                        break;
                    }
                }

                if(found == 0)
                {
                    printf("Element not found.\n");
                }
                break;

            // Binary Search
            case 6:
                // Sorting array
                for(i = 0; i < n - 1; i++)
                {
                    int j;
                    for(j = 0; j < n - i - 1; j++)
                    {
                        if(arr[j] > arr[j + 1])
                        {
                            int temp = arr[j];
                            arr[j] = arr[j + 1];
                            arr[j + 1] = temp;
                        }
                    }
                }

                printf("Sorted array: ");
                for(i = 0; i < n; i++)
                {
                    printf("%d ", arr[i]);
                }

                printf("\nEnter element to search: ");
                scanf("%d", &key);

                low = 0;
                high = n - 1;
                found = 0;

                while(low <= high)
                {
                    mid = (low + high) / 2;

                    if(arr[mid] == key)
                    {
                        printf("Element found at position %d in sorted array.\n",mid + 1);
                        found = 1;
                        break;
                    }
                    else if(arr[mid] < key)
                    {
                        low = mid + 1;
                    }
                    else
                    {
                        high = mid - 1;
                    }
                }

                if(found == 0)
                {
                    printf("Element not found.\n");
                }
                break;

            case 7:
                printf("Program ended.\n");
                break;

            default:
                printf("Invalid choice!\n");
        }

    } while(choice != 7);

    return 0;
}