# Embedded Test Run

This git repo contains a simple C program which checks that a website is alive. If it is, the C program will call a script.



## Your task

This program is currently incomplete. There are several necessary steps to make this program meet requirements. Liberal use of online resources is encouraged. Improvements to the program are welcomed, or simply "TODO" comments if you spot something you would want to fix but do not want to fix during this interview.

This program is stored in a git repository -- feel free to make use of any git features (e.g. stash, diff) if you would like to. At several points, you will be asked to make a commit, but you may make additional ones if you desire. Generally, anything is allowed, unless specifically disallowed.









### Step 1: make the main function take command line arguments

Take a look at the C files in the `src/` directory. The main function should be modified to take a command line argument and print it back to stdout. At this time, do not worry about implementing any other functionality.

#### Verification

At the end of this step, you should be able to generate the following output:

```
$ cd src/
$ make
$  ./websiteChecker "hello world"
hello world
```










### Step 2: complete C program's "checkWebsite" function

The `checkWebsite()` function in `src/websiteChecker.c` needs to be completed, to match the comment above it.

Additionally, the `main()` function in the program should be modified to accept the first parameter from the command line as the URL, and return the value of the call to `checkWebsite()`. At this time, do not worry about the other functions described in the comment above `main()`.

#### Verification

At the end of this step, you should be able to generate the following output:

```
$ cd src/
$ make
$  ./websiteChecker "example.com"; echo $?
0
$  ./websiteChecker "thisIsNotARealWebsite.noTLD"; echo $?
1
```

#### Commit

Please make a commit at the end of this step, with the title "Completed checkWebsite() function"










### Step 3: call a system command passed in via command line argument

Complete the `main()` function as described in the comment above it, making use of the `callScript()` function.

#### Verification

At the end of this step, you should be able to generate the following output:

```
$ cd src/
$ make
$  ./websiteChecker example.com "echo hello world"
hello world
$  ./websiteChecker thisIsNotARealWebsite.noTLD "echo hello world"

```

#### Commit

Please make a commit at the end of this step, with the title "Completed checkWebsite program"










# Step 4: daemonize

The program is running great right now, but you have a small problem: sometimes, the script that you want to call takes a long time to run. Or, sometimes, you don't want to wait while the request times out when the website is down.

```
$ time ./websiteChecker "example.com" "sleep 5"

real    0m5.144s
user    0m0.000s
sys     0m0.000s
```

Sure, the user could run your script in the background by appending `&` to the command in their shell. But instead, you should do it for them as part of this program.

#### Verification

At the end of this step, you should be able to generate the following output:

```
$ rm ./testFile
$ time ./websiteChecker "example.com" "sleep 5; touch $PWD/testFile"

real    0m0.004s
user    0m0.000s
sys     0m0.000s
$ sleep 5
$ ls ./testFile
./testFile
$ rm ./testFile
```









# Step 5: an unexpected twist

Take a look at the script within the `scripts/` directory. When run, they create a file in the user's home directory:

```
$ ./scripts/do_important_stuff.sh
$ ls ~/test_important_stuff
/Users/you/test_important_stuff
$ rm ~/test_important_stuff
```

Now, try calling this script as part of the program from the previous step:

```
$ rm ~/test_important_stuff
$ cd src/
$  ./websiteChecker "example.com" "$PWD/../scripts/do_important_stuff.sh"
$ ls ~/test_important_stuff
No such file or directory
```

Clearly, something has gone wrong! Please either explain why out loud to your interviewer or write an explanation in the file `./explanation.txt`.

Also, please fix it :)

#### Verification

At the end of this step, you should be able to generate the following output:

```
$ rm ~/test_important_stuff
$ cd src/
$  ./websiteChecker "example.com" "$PWD/../scripts/do_important_stuff.sh"
$ ls ~/test_important_stuff
/Users/you/test_important_stuff
```

#### Commit

Please make a commit at the end of this step, with the title "Completed the interview"

