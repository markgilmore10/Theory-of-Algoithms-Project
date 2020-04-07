# Theory-of-Algoithms-Project
## MD5 Secure Hash Algorithm

|     |     |
| --- | --- |
| **Author** | [Mark Gilmore](https://github.com/markgilmore10) |
| **Student Number** | G00214777 |
| **Lecturer** | Dr Ian McLoughlin |
| **Course** | BSc (Hons) in Software Development
| **Module** |  Theory of Algorithms |

This Repository contains the submission for my 4th year Theory of Algorithms project as part of my BSc (Hons) in Software Development course.

<hr>

## Introduction

This repository contains the working code for an MD5 Hashing Algorithm written in C along with 2 hello world programs written in Python and C and a working SHA256 hashing algorithm also written in C.  
A look at previous commits will show how these projects were pieced together for the duration of the semester using online tutorials provided by my lecturer, Dr Ian McLoughlin, as well as self study and investigation via online documentation and tutorials. Throughout the semester a series of video lectures helped us understand key hashing concepts like C bit operations, unions and padding in C.  
The hello world programs were used to refresh students memory regarding the Python and C languages and how they are run.    
The SHA256 program is the project which our lecturer used as an example to help us on our way to building the MD5.  
Throughout this module we used the VIM text editor on a Debian Virtual Machine hosted on Google Cloud to develop our code. This gave us a great understanding of using such a text editor to create, develop and run programs on a VM.

<hr>

## Problem Statement
You must write a program in the C programming language that calculates the MD5 hash digest of an input.  
The algorithm is specified in the Request For Comments 1321 document supplied by the Internet Engineering Task Force.  
The only pre-requisite is that your program performs the algorithm — you are free to decide what input the algorithm should be performed on.

<hr>

## The MD5 Algorithm

[The MD5 message-digest algorithm is a widely used hash function producing a 128-bit hash value.  
Although MD5 was initially designed to be used as a cryptographic hash function, it has been found to suffer from extensive vulnerabilities.  It can still be used as a checksum to verify data integrity, but only against unintentional corruption.  
It remains suitable for other non-cryptographic purposes, for example for determining the partition for a particular key in a partitioned database.  
MD5 was designed by Ronald Rivest in 1991 to replace an earlier hash function MD4 and was specified in 1992 as RFC 1321.](https://en.wikipedia.org/wiki/MD5)

<hr>

## Steps
The following are the steps involved in the hashing process:

### 1. Append Padding Bits
The first step towards building the MD5 is padding. Padding is the process in which a message, of arbitrary length, is padded so that the length of the message in bits is equal to 448 modulo 512.  
Padding is done only when the message is less than 64 bytes in size otherwise it is left as is. 

### 2. Append Length
A 64-bit representation of the length of the given message before the padding was added is appended to the result of the padding resulting in a message which has a length multiple of 512 bits.

### 3. Initialize Message Digest buffer


### 4. Process Message in 16-Word Blocks


### 5. Output Results


## Code

## Run the Program Locally

### 1. Cloning the Repository

### 2. Compiling the Program

### 3. Running the Program

## Testing

## Research

## References
