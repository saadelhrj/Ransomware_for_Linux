# Ransomware
!!!!!!!!!! The Simplest Ransomware code ever seen by mankind !!!!!!!!!

<h1> Purpose </h1>

This repository contains the source code of a simple implementation of ransomware. It encrypts all the files in the current directory using AES-256 encryption and a hard-coded key, and then deletes the original files.

<h2> Disclaimer </h2>

The use of ransomware is illegal and unethical, and its victims can suffer significant financial and emotional harm. This repository is not intended to promote or encourage the use of ransomware, and the source code contained herein should not be used for any malicious activities.

<h2> Usage </h2>

The source code implements the openssl library.
To link all necessary libraries while compiling use the command below :

```
gcc ransomware.c -o ransomware.out -lssl -lcrypto
```
The file does not have an exclusion on itself, this means that all the files in the current dir are encrypted including the sourcecode and the executable !!!!
This is the first version, more features will be added soon.
