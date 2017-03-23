# Embedded Test Run

This git repo contains an incomplete C program, whose goal is to checks that a website is alive. If it is, the C program will call a script.

## Setup

If you are doing this at the Wink office, your workstation is already set up. Please skip to the next section. If you're doing this on your own, you'll need to install libcurl on your machine:
- For Ubuntu: `sudo apt-get update && sudo apt-get install libcurl4-openssl-dev`.
- For OSX: you're already good to go with libcurl (albeit with an outdated version).







## Your task

This program is currently incomplete. There are several necessary steps, written out below, to make this program meet requirements. Complete as much as possible during the allotted time, with a preference for getting something compiling and working instead of making it perfect. You will probably not complete the entire task in the allocated time (and that's ok!). You may use any online resources you would like. Any changes or improvements to the program are welcomed, or you may simply add "TODO" comments if you spot something you would want to fix but do not have time to fix during this interview.

This program is stored in a git repository -- feel free to make use of any git features (e.g. stash, diff) if you would like to. At several points, you will be asked to make a commit. You may make additional commits at any time, if you desire. Generally, anything is allowed during this exercise, unless an instruction specifically disallows it.









### Step 1: make the main function take command line arguments

Take a look at the C files in the `src/` directory. The first step is to modify the `main()` function to take a command line argument and print it back to stdout. At this time, do not worry about implementing any other functionality.

#### Verification

At the end of this step, you should be able to generate the following output:

```
$ cd src/
$ make
$ ./websiteChecker "hello world"
hello world
```










### Step 2: complete C program's "checkWebsite" function

The `checkWebsite()` function in `src/websiteChecker.c` needs to be completed, to match the comment above it.

Additionally, the `main()` function in the program should be modified to accept the first parameter from the command line as the URL, and return the value of the call to `checkWebsite()`. At this time, do not worry about the other functions described in the comment above `main()`.

**Hints**:
- `libcurl` is installed on this system, if you wish to use it, though you may use any implentation you would like, including installing other libraries.
- You may need to modify the Makefile to get your program to compile, when using outside libraries.

#### Verification

At the end of this step, you should be able to generate the following output:

```
$ cd src/
$ make
$ ./websiteChecker "example.com"; echo $?
0
$ ./websiteChecker "thisIsNotARealWebsite.noTLD"; echo $?
1
```

#### Commit

Please make a commit at the end of this step, with the title "Completed checkWebsite() function"










### Step 3: call a system command passed in via command line argument

Complete the `main()` function as described in the comment above it, making use of the `execCommand()` function.

#### Verification

At the end of this step, you should be able to generate the following output:

```
$ cd src/
$ make
$ ./websiteChecker example.com "echo hello world"
hello world
$ echo $?
0
$ ./websiteChecker thisIsNotARealWebsite.noTLD "echo hello world"
$ echo $?
1
```

#### Commit

Please make a commit at the end of this step, with the title "Completed checkWebsite program"










### Step 4: daemonize

The program is running great right now, but you have a small problem: sometimes, the script that you want to call takes a long time to run. Or, sometimes, you don't want to wait while the request times out when the website is down.

```
$ time ./websiteChecker "example.com" "sleep 5"

real    0m5.144s
user    0m0.000s
sys     0m0.000s
```

Sure, the user could run your script in the background by appending `&` to the command in their shell. But instead, let's do it for them as part of this program.

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









### Step 5: an unexpected twist

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

