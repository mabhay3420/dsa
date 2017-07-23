#include <bits/stdc++.h>

using namespace std;

int Merge(std::vector<int>& nums,
          int start, int mid, int end) {
  int i = start;
  int j = mid + 1;
  std::vector<int> merged;
  int result = 0;
  while (i <= mid || j <= end) {
    if (i > mid) {
      while (j <= end) merged.push_back(nums[j++]);
      break;
    }
    if (j > end) {
      while (i <= mid) merged.push_back(nums[i++]);
      break;
    }
    if (nums[i] <= nums[j]) {
      merged.push_back(nums[i++]);
    } else {
      merged.push_back(nums[j++]);
      result += (mid - i + 1);
    }
  }
  for (int i = start; i <= end; i++) {
    nums[i] = merged[i - start];
  }
  return result;
}

int MergeSort(std::vector<int>& nums, int start, int end) {
  if (start >= end) return 0;
  int mid = start + (end - start) / 2;
  return MergeSort(nums, start, mid) +
         MergeSort(nums, mid + 1, end) +
         Merge(nums, start, mid, end);
}

int CountInversions(std::vector<int>& nums) {
  return MergeSort(nums, 0, nums.size() - 1);
}

int main() {
  std::vector<int> nums{1, 2, 9, 3, 4, 7, 5, 6, 8};  // 8
  cout << CountInversions(nums) << endl;
  return 0;
}
