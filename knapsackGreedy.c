#include<stdio.h>

int main()
{
    int n;
    printf("Enter the number of elements: ");
    scanf("%d",&n);

    int capacity;
    printf("Enter the knapsack capacity: ");
    scanf("%d",&capacity);

    int profit[n], weight[n], i, j;
    float ratio[n], temp;

    printf("Enter the profit and weight of each item:\n");
    for(i=0; i<n; i++)
    {
        printf("Profit[%d]: ", i+1);
        scanf("%d", &profit[i]);
        printf("Weight[%d]: ", i+1);
        scanf("%d", &weight[i]);
        ratio[i] = (float)profit[i] / weight[i];
    }

    for(i=0; i<n-1; i++)
    {
        for(j=i+1; j<n; j++)
        {
            if(ratio[i] < ratio[j])
            {
                temp = ratio[i];
                ratio[i] = ratio[j];
                ratio[j] = temp;

                temp = profit[i];
                profit[i] = profit[j];
                profit[j] = temp;

                temp = weight[i];
                weight[i] = weight[j];  
                weight[j] = temp;
            }
        }
    }

    float totalProfit = 0, totalWeight = 0;
    for(i=0; i<n; i++)
    {
        if(totalWeight + weight[i] <= capacity) // Assuming the knapsack capacity is 50
        {
            totalWeight += weight[i];
            totalProfit += (float)profit[i];
        }
        else
        {
            float remainingWeight = capacity - totalWeight;
            totalProfit += (float)profit[i] * (remainingWeight / weight[i]);
            break;
        }
    }

    printf("Total profit: %0.1f\n", totalProfit);
    return 0;
}