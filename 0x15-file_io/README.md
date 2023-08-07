# 0x15. C - File I/O

[File descriptors](https://en.wikipedia.org/wiki/File_descriptor)

[C Programming in Linux Tutorial #024 - open() read() write() Functions](https://www.youtube.com/watch?v=e-srF6c3TJ8)

## Function prototypes

+ ssize_t read_textfile(const char *filename, size_t letters): reads a text file and prints it to the POSIX standard output.
+ int create_file(const char *filename, char *text_content): creates a file.
+ int append_text_to_file(const char *filename, char *text_content): appends text at the end of a file.
