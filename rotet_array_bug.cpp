#include <iostream>
#include <vector>
using namespace std;
// TODO: Write this in c with memory allocation
/**
 * This algorithm for rotate array will foil for the following
 * [1,2,3,4,5,6,7,8,9,10,11,12,13,14,15,16,17,18,19,20,21,22,23,24,25,26,27]
 * k = 38
 */
class Solution
{
public:
    void rotate(vector<int> &nums, int k)
    {
        
        if(k > nums.size()){
            k %= nums.size();
        }
        int div_indx = nums.size() - k;

        if (div_indx < k)
        {
            rotate_right_heavy(nums, div_indx);
        }
        else
        {
            rotate_left_heavy(nums, div_indx);
        }
    }

private:
    void swap(int i, int j, vector<int> &nums)
    {
        nums[i] = nums[i] ^ nums[j];
        nums[j] = nums[i] ^ nums[j];
        nums[i] = nums[i] ^ nums[j];
    }

    void rotate_right_heavy(vector<int> &nums, int div_indx)
    { // decrease i and j; reset i
        int i = div_indx - 1;
        int j = nums.size() - 1;
        while (i < j && (i >= 0 && j <= nums.size() - 1))
        {
            swap(i, j, nums);
            i--;
            j--;

            if (i >= j)
            {
                i = j - 1;
            }
            if (i < 0)
            { // reset i
                i = div_indx - 1;
            }
        }
    }

    void rotate_left_heavy(vector<int> &nums, int div_indx)
    { // increase i and j; reset j
        int j = div_indx;
        int i = 0;
        while (i < j && (i >= 0 && j <= nums.size() - 1))
        {
            swap(i, j, nums);
            i++;
            j++;

            if (j <= i)
            {
                j = i + 1;
            }
            if (j > nums.size() - 1)
            { // reset j
                j = div_indx;
            }
        }
    }
};

int main()
{
    while (1)
    {
        int input_vector;
        int size_vector;
        vector<int> nums;
        std::cout << "Input vector size: ";
        std::cin >> size_vector;
        cout << "\n";
        std::cout << "Input vector value one by one of size " << size_vector;

        cout << "\n";
        for (int i = 0; i < size_vector; i++)
        {
            std::cin >> input_vector;
            nums.push_back(input_vector);
        }
        cout << "\n";
        for (int i = 0; i < nums.size(); i++)
        {
            cout << nums[i] << " ";
        }
        cout << "\n";
        int k;
        std::cout << "Put the value of k: ";
        std::cin >> k;
        std::cout << "\n";
        Solution s;
        s.rotate(nums, k);
        for (int i = 0; i < nums.size(); i++)
        {
            cout << nums[i] << " ";
        }
        cout << "\n";
    }
}
