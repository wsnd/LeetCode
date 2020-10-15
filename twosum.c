/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
#include <stdio.h>
#include <stdbool.h>
#include <malloc.h>
/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* twoSum(int* nums, int numsSize, int target, int* returnSize){
    typedef struct node_visit
    {
        bool visited;
        int index;
    }node_visit;
    int min = nums[0];
    int max = nums[0];
    *returnSize = 2;
    int *Result = (int *)malloc(sizeof(int) * 2);
    for (int i = 1; i < numsSize; ++i)
    {
        min = nums[i] < min ? nums[i] : min;
        max = nums[i] > max ? nums[i] : max;
    }
    node_visit *visited = (node_visit *)malloc(sizeof(node_visit) * (max - min + 1));
    for (int i = 0; i < max - min + 1; ++i)
    {
        visited[i].visited = false;
        visited[i].index = -1;
    }
    for (int i = 0; i < numsSize; ++i)
    {
        visited[nums[i] - min].visited = true;       
        if (target - nums[i] >= min 
            && target - nums[i] <= max
            && visited[target - nums[i] - min].visited == true
            && visited[target - nums[i] - min].index != i
            && visited[target - nums[i] - min].index != -1) {
            Result[0] = visited[target - nums[i] - min].index;
            Result[1] = i;
            free(visited);
            return Result;
        }
        visited[nums[i] - min].index = i;
    }
    free(visited);
    return NULL;
}
int main()
{
    int array[3] = {3, 2, 3};
    int *pSize = (int *)malloc(sizeof(int));
    int *pResult;
    pResult = twoSum(array, 3, 6, pSize);
    printf("%d %d\n", pResult[0], pResult[1]);
    free(pResult);
    free(pSize);
    return 0;
}