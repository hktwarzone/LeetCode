/*
158. Read N Characters Given Read4 II - Call multiple times

The API: int read4(char *buf) reads 4 characters at a time from a file.

The return value is the actual number of characters read. For example, 
it returns 3 if there is only 3 characters left in the file.

By using the read4 API, implement the function int read(char *buf, int n) 
that reads n characters from the file.

The read function may be called multiple times.
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
