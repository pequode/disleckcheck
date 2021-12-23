# disleckcheck: A simple spell checker built from scratch to help spell check comments in code.
##Contents
* **main**
  The central file that runs spell check on a given program.  
* **Algs**
  A cpp class with different classic Algorithms.
* **mobytxt.txt**
  A complete copy of Moby Dick, one of my favorite books, used for creating a word frequency list. This could be replaced by and general text to help sort suggestions based on word frequency.
* **dicList**
  A large file with a long list of words to try and match mis-spellings with.
* **cmtChckr**
  A draft of the class which specializes in checking comments
* **numm**
  A set class to attempt to add things to other classes through the test file.
* **test**
  The runner that is used for testing sections of code from numm.
* **helpers**
  The program that sets out a basic framework for the spellcheck library. It includes the Dictionary and FrequencyList Classes.
* **spck**
  used the primitives from helpers to perform spell checking.
## Purpose
I wanted to apply my C++ education in a meaningful project. I choose this one because I suffer with dyslexia and have always struggled with basic spelling.
I understand that there are already programs and library which are able to do a more robust job of spellcheck. However, I wanted to really begin to understand how the process worked because I use spellcheck so often. I also wanted to improve my command of C++ after taking a course in system level C programming. This was also the first time that I implemented a complex algorithm from a paper that I found online and proved to be a rewarding experience. Along the way I learned the importance of testing, and the pervasive issues of memory leaks that large projects like this often face.     
##Credits  
This project was inspired by the blog post by Peter Norvig in 2007
https://norvig.com/spell-correct.html
for word databases it uses:  
http://www.mieliestronk.com/wordlist.html for dictionary   
I did the converstion to c++
George Kent-Scheller
v20211223.1
