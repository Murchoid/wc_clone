# wc-clone  

A minimal clone of the classic **Linux `wc` (word count) command**, written in **C**.  
This project was inspired by coding challenges I came across (special thanks to **John Cricket from Code Challenges** and the community post that sparked the idea).  

The goal was to build a working version of `wc` in **under 2 hours**, so the current implementation is intentionally minimal but fully functional — supporting **reading from both files and stdin**.  

---

## Features (Current)  
- Count **lines, words, and bytes**.  
- Works with **stdin** and **file input**.  
- Flag support:  
  - `-l` → line count  
  - `-w` → word count  
  - `-c` → byte count  
- Clean separation into multiple source files with **CMake build support**.  

---

## Future Plans  
This project is just the foundation — I plan to expand it further:  

- [ ] Add support for additional flags (`-m`, `-L`, etc.).  
- [ ] Support multiple files (with totals, like GNU `wc`).  
- [ ] Handle larger files efficiently (buffered reading).  
- [ ] Error handling and better flag parsing.  
- [ ] Colored output / formatting options.  
- [ ] Unit tests to validate correctness.  

---

## Why This Project?  
I wanted to **challenge myself to replicate a real Linux tool** in pure C. The time-boxed goal (2 hours) forced me to focus on the essentials while leaving space for future improvements.  

---

## Build & Run  

### Build with CMake
```bash
mkdir build && cd build
cmake ..
make
