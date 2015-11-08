/*
Smallest Rectangle Enclosing Black Pixels

An image is represented by a binary matrix with 0 as a white pixel and 1 as a black pixel. 
The black pixels are connected, i.e., there is only one black region. 
Pixels are connected horizontally and vertically. 
Given the location (x, y) of one of the black pixels, return the area of the smallest (axis-aligned) rectangle 
that encloses all black pixels.

For example, given the following image:

[
  "0010",
  "0110",
  "0100"
]
and x = 0, y = 2,
Return 6.

*/
class Solution {
public:
    int minArea(vector<vector<char>>& image, int x, int y) {
        if (image.empty() || image[0].empty()) return 0;
        int n = image.size();
        int m = image[0].size();
        return (findRow(image, x, n - 1, 1) - findRow(image, 0, x, 0) + 1) * (findCol(image, y, m - 1, 1) - findCol(image, 0, y, 0) + 1);
    }
private:
    int findRow(vector<vector<char>>& image, int left, int right, int opt) {
        while(left < right) {
            int mid = (opt == 0) ? left + (right - left) / 2 : left + (right - left + 1) / 2;
            bool hasOne = false;
            for (int i = 0; i < image[0].size(); i++) {
                if (image[mid][i] == '1') hasOne = true;
            }
            if (opt == 0) {
                if (hasOne) right = mid;
                else left = mid + 1;
            }
            else {
                if (hasOne) left = mid;
                else right = mid - 1;
            }
        }
        return left;
    }   
    int findCol(vector<vector<char>>& image, int left, int right, int opt) {
        while(left < right) {
            int mid = (opt == 0) ? left + (right - left) / 2 : left + (right - left + 1) / 2;
            bool hasOne = false;
            for (int i = 0; i < image.size(); i++) {
                if (image[i][mid] == '1') hasOne = true;
            }
            if (opt == 0) {
                if (hasOne) right = mid;
                else left = mid + 1;
            }
            else {
                if (hasOne) left = mid;
                else right = mid - 1;
            }
        }
        return left;
    }
};
