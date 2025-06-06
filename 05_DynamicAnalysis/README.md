# 05 Dynamic Analysis

## Wonderland.exe 

### Level 4

In this level, we see the following:

![alt text](image.png)

A `scanf` call that if input anything of than an `unsigned int `(`%du`) will cause a crash (using stack overflow).

And if input a number if will treat it as an address and try to compare it with the `Str` variable (which is a string that is initialized at runtime to be "Good luck!!")

So the first Idea was to give as an input the address of the `Str` variable (The runtime address so we need to use ida to debug it the address we try was `0x0017FEF8` converted to decimal `1703672`)

And the program output was `"Cheater ..."` so we understood that there was a check to see if `Str == Str1` so we had to give the program an address of a string that was `"Good luck!!"` while at the same time not being the same address of `Str`, the trick was to do it dynamically so we found the a random address and put the the string `"Good luck!!"` and gave the address as input

![alt text](image-1.png)

![alt text](image-2.png)

So we gave as input the address at which we put (at runtime) the string (i.e. `0x0019FF08`) and got the following screen

![sucess](sucess.png)