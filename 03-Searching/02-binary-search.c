#include <stdio.h>

int main()
{
    int numbers[10] = {5, 9, 11, 16, 17, 28, 34, 43, 49, 57};
    int foundIndex = -1;
    int target;

    printf("Enter an integer to search for: ");
    scanf("%d", &target);

    int left = 0;
    int right = 9;

    while (left <= right)
    {
        int mid = (left + right) / 2;

        if (numbers[mid] == target)
        {
            foundIndex = mid;
            break;
        }
        else if (numbers[mid] < target)
        {
            left = mid + 1;
        }
        else if (numbers[mid] > target)
        {
            right = mid - 1;
        }
    }

    if (foundIndex != -1)
    {
        printf("Element found at position %d\\n", foundIndex + 1);
    }
    else
    {
        printf("Element not found.\\n");
    }

    return 0;
}
