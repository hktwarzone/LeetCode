/*
158. Read N Characters Given Read4 II - Call multiple times

The API: int read4(char *buf) reads 4 characters at a time from a file.

The return value is the actual number of characters read. For example, 
it returns 3 if there is only 3 characters left in the file.

By using the read4 API, implement the function int read(char *buf, int n) 
that reads n characters from the file.

The read function may be called multiple times.

Example 1

Input:
"filetestbuffer"
read(6)
read(5)
read(4)
read(3)
read(2)
read(1)
read(10)

Output:
6, buf = "filete"
5, buf = "stbuf"
3, buf = "fer"
0, buf = ""
0, buf = ""
0, buf = ""
0, buf = ""


Example 2

Input:
"abcdef"
read(1)
read(5)

Output:
1, buf = "a"
5, buf = "bcdef"
*/

// Forward declaration of the read4 API.
int read4(char *buf);

class Solution {
public:
    Solution() : bufread(0), bufvalidsize(0) {}
    /**
     * @param buf destination buffer
     * @param n maximum number of characters to read
     * @return the number of characters read
     */
    int read(char *buf, int n) {
        int count = 0;
        if (bufread > 0) {
            while(count < n && bufread < bufvalidsize) {
                buf[count++] = buffer[bufread++];
            }
            bufread %= 4;
        }
        while(count < n) {
            bufread = 0;
            bufvalidsize = read4(buffer);
            if (bufvalidsize == 0) break;
            while(count < n && bufread < bufvalidsize) {
                buf[count++] = buffer[bufread++];
            }
        }
        return count;
    }
private:
    char buffer[4];
    int bufread;
    int bufvalidsize;
};
