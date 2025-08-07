# File Copier Utility (C)

A simple command-line utility written in C that replicates the behavior of the Unix `cp` command. This tool copies the contents of a file into another file or into a destination directory, creating a new copy with the same filename.

---

## 🛠 Features

- Supports copying from source file to destination file.
- Detects if the destination is a directory and appends the filename.
- Handles basic file I/O and buffer-based copying.
- Includes error handling for file access and path issues.

---

### 🔧 Compilation

Use the provided `Makefile` (or compile manually):

```bash
make
```

Or manually:

```bash
gcc copier.c -o copier
```

### ▶️ Running

```bash
./copy <source_file> <destination_file_or_directory>
```

#### Examples

```bash
# Copy to another file
./copy test.c hello.c

# Copy to a directory (retains original filename)
./copy test.c src
```

---

## 📂 Project Structure

```
copier.c       # Main source file
copier.h       # Header declarations
README.md      # This file
Makefile       # For easy building
```

---

## 📌 Notes

- The buffer size is capped at 1000 characters per read operation.
- Destination path handling checks for a `.` in the name to determine if it's a file.
- Does not currently support recursive directory copying or metadata preservation.

---

## 📄 License

This project is open-source and free to use under the [MIT License](LICENSE).

---

## ✍️ Author

Created by Philip Gill – feel free to contribute or suggest improvements.
